#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include "User.h"
#include "Constants.h"



using namespace std;
using namespace std::filesystem;




void parseXML(string xml_path, map<int, User>& id_to_users) {


	// will loop line by line
	string xml_line;
	// to avoid errors
	User new_user;
	string tag = "", prev_tag = "";

	///////// parse file //////////////


	ifstream myXML(xml_path);
	while (getline(myXML, xml_line)) {
		size_t pos = 0;
		int not_first_user = 0;

		while (pos < xml_line.length()) {

			if (xml_line[pos] == '<') {
				// update previous tag
				prev_tag = tag;
				// Find the end of the tag
				int end = xml_line.find('>', pos);
				if (end == string::npos) break;
				tag = xml_line.substr(pos, end - pos + 1);
				pos = end + 1;

				// end of user 
				if (tag == "</user>")
					id_to_users[new_user.user_id] = new_user;

			}
			else {

				// Extract text between tags
				int end = xml_line.find('<', pos);
				if (end == string::npos) end = xml_line.length();
				string text = xml_line.substr(pos, end - pos);
				pos = end;

				///////////////////////////////////////
				/////////// add data to user /////////
				// new_user points to new user  actually
				if (tag == "<user>") {
					new_user.~User();
					new (&new_user) User();
				}
				else if (tag == "<id>" && prev_tag != "<follower>")
					new_user.user_id = stoi(text);
				else if (tag == "<name>")
					new_user.user_name = text;
				else if (tag == "<id>" && prev_tag == "<follower>")
					new_user.add_follower(stoi(text));
			}

		}
	}
	myXML.close(); // remember to close file
	// add following
	User::add_following(id_to_users);
	User::finish_maps(id_to_users);
}


void draw(map<int, User>& id_to_users, string graph_path) {
	////////////////// writing in dot file //////////////////
	ofstream myDOT(DOT_FILE);
	myDOT << "digraph {" << endl;
	// printing users & adding to dot file
	for (auto map_element : id_to_users) {
		User my_user = map_element.second;
		my_user.display();
		for (int j = 0; j < my_user.follower_ids.size();j++) {
			int follower_id = my_user.follower_ids[j];
			myDOT << map_element.first << "->" << follower_id << ";" << endl;
		}
	}
	myDOT << "}";
	myDOT.close(); // close file


	///////////////////// drawing graph //////////////////////////////
	string command_str = "dot -Tjpg " + DOT_FILE + " -o " + graph_path;
	const char* command = command_str.c_str();
	system(command);

}

string trim(const string& str) {
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == string::npos) return "";
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, (last - first + 1));
}

vector<vector<string>> parseXMLToVector(const string& filename) {
	vector<string> user;
	vector<string> posts;
	vector<vector<string>> all_users;

	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Failed to open XML file!" << endl;
		return all_users;
	}

	string line, current_tag;

	while (getline(file, line)) {
		line = trim(line); // Trim only leading and trailing spaces

		if (line.empty()) continue; // Skip empty lines

		if (line[0] == '<' && line[1] != '/') {
			size_t tag_end = line.find('>');
			current_tag = line.substr(1, tag_end - 1);

			if (current_tag == "user") {
				user.clear();
				posts.clear();
			}
		}
		else if (line[0] == '<' && line[1] == '/') {
			size_t tag_end = line.find('>');
			string closing_tag = line.substr(2, tag_end - 2);

			if (closing_tag == "user") {
				// Ensure the user vector is added to all_users
				if (!user.empty()) {
					all_users.push_back(user);
				}
				user.clear();
				posts.clear();
			}
			else if (closing_tag == "topics") {
				// Clear posts only when a topic ends
				posts.clear();
			}
		}
		else {
			if (current_tag == "id") {
				// Always push user ID as the first element
				user.push_back(line);
				if (user.empty()) {
					user.push_back(line);
				}
				else if (user[0] != line) {
					user.insert(user.begin(), line);
				}
			}
			else if (current_tag == "body") {
				posts.push_back(line); // Add post body without modifying spaces
			}
			else if (current_tag == "topic") {
				if (!line.empty()) {
					user.push_back(line); // Add topic
					user.push_back(to_string(posts.size())); // Add number of posts
					user.insert(user.end(), posts.begin(), posts.end()); // Add all posts
				}
			}
		}
	}

	file.close();
	return all_users;
}