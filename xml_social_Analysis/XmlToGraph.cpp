#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <stdio.h>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include "User.h"



using namespace std;
// using namespace std::filesystem;

// CONSTANTS

// relative path to XML file
const string XML_FILE = "Resources/sample.xml";
const string DOT_FILE = "Resources/graph.dot";
const string GRAPH_PATH = "Resources/graph.jpg";





// Header of functions
void parseXML(string xml_path, map<int, User>& id_to_users);
void draw(map<int, User>& id_to_users, string graph_path);

// multimap<int, int> User::id_to_following;

// multimap<int, int> User::following_count_to_id;
// multimap<int, int> User::follower_count_to_id;
// multimap<int, int> User::connection_count_to_id;

// int main() {

// 	map<int,User> id_to_users;

// 	// draw
// 	parseXML(XML_FILE, id_to_users);
// 	draw(id_to_users, GRAPH_PATH);

// 	// max followers
// 	int most_followed_id=User::most_followers(id_to_users);
// 	cout << "\nMost followed id:" << most_followed_id << endl
// 		<< "Most followed name:" << id_to_users[most_followed_id].user_name << endl
// 		<< "Has follower count:" << id_to_users[most_followed_id].num_followers << endl;

// 	// most active
// 	User::most_active(id_to_users);

// 	// suggest
// 	map<int,string> suggestions_map=User::suggest(id_to_users, 2);

// 	cout << "\nSuggestions for user: " << id_to_users[2].user_name << " with id:" << 2 << endl;
// 	for (auto suggestion : suggestions_map)
// 		cout << suggestion.second << " ";
// 	cout << endl;

// 	// mutual
// 	vector<int> ids = { 2,3 };
// 	map<int, string> mutuals_map = User::mutual(id_to_users, { 2,3 });
// 	for (auto mutual : mutuals_map)
// 		cout << "Mutual id:" << mutual.first <<" With name:"<<mutual.second << endl;


// 	return 0;
// }

// void parseXML(string xml_path, map<int,User>& id_to_users) {


// 	// will loop line by line
// 	string xml_line;
// 	// to avoid errors
// 	User new_user;
// 	string tag = "", prev_tag = "";

// 	///////// parse file //////////////


// 	ifstream myXML(xml_path);
// 	while (getline(myXML, xml_line)) {
// 		size_t pos = 0;
// 		int not_first_user = 0;

// 		while (pos < xml_line.length()) {

// 			if (xml_line[pos] == '<') {
// 				// update previous tag
// 				prev_tag = tag;
// 				// Find the end of the tag
// 				int end = xml_line.find('>', pos);
// 				if (end == string::npos) break;
// 				tag = xml_line.substr(pos, end - pos + 1);
// 				pos = end + 1;

// 				// end of user 
// 				if (tag == "</user>")
// 					id_to_users[new_user.user_id]=new_user;

// 			}
// 			else {

// 				// Extract text between tags
// 				int end = xml_line.find('<', pos);
// 				if (end == string::npos) end = xml_line.length();
// 				string text = xml_line.substr(pos, end - pos);
// 				pos = end;

// 				///////////////////////////////////////
// 				/////////// add data to user /////////
// 				// new_user points to new user  actually
// 				if (tag == "<user>") {
// 					new_user.~User();
// 					new (&new_user) User();
// 				}
// 				else if (tag == "<id>" && prev_tag != "<follower>")
// 					new_user.user_id = stoi(text);
// 				else if (tag == "<name>")
// 					new_user.user_name = text;
// 				else if (tag == "<id>" && prev_tag == "<follower>")
// 					new_user.add_follower(stoi(text));
// 			}

// 		}
// 	}
// 	myXML.close(); // remember to close file
// 	// add following
// 	User::add_following(id_to_users);
// 	User::finish_maps(id_to_users);
// }


// void draw(map<int, User>& id_to_users,string graph_path) {
// 	////////////////// writing in dot file //////////////////
// 	ofstream myDOT(DOT_FILE);
// 	myDOT << "digraph {" << endl;
// 	// printing users & adding to dot file
// 	for (auto map_element: id_to_users) {
// 		User my_user = map_element.second;
// 		my_user.display();
// 		for (int j = 0; j < my_user.follower_ids.size();j++) {
// 			int follower_id = my_user.follower_ids[j];
// 			myDOT << map_element.first<< "->" << follower_id << ";" << endl;
// 		}
// 	}
// 	myDOT << "}";
// 	myDOT.close(); // close file


// 	///////////////////// drawing graph //////////////////////////////
// 	string command_str = "dot -Tjpg " + DOT_FILE + " -o " + graph_path;
// 	const char* command = command_str.c_str();
// 	system(command);

// }
