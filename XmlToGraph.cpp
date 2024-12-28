#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <stdio.h>
#include <vector>



using namespace std;
using namespace std::filesystem;

// CONSTANTS

// relative path to XML file
const string XML_FILE = "Resources/sample.xml";
const string DOT_FILE = "Resources/graph.dot";

// class for each user
class User {
public:
	string user_name;
	int user_id;
	vector<int> follower_ids;
	vector<int> following_ids;
	vector<string> user_posts;
	~User() {}
	void display() {
		cout << "User Name: " << user_name << endl
			<< "Id:" << user_id << endl;
		cout << "followers_ids:";
		for (int i = 0;i < follower_ids.size();i++)
			cout << follower_ids[i] << ",";
		cout << "\nfollowing_ids:";
		for (int i = 0;i < following_ids.size();i++)
			cout << following_ids[i] << ",";
		cout << "\n"<<"-----------------------------------"<<endl;
	}
	void add_follower(int follower_id) { follower_ids.push_back(follower_id); }

};

// Header of functions
void parseXML(string xml_path, vector<User>& users, string dot_path );




int main() {

	vector<User> users;

	parseXML(XML_FILE, users, DOT_FILE);
	//for (int i = 0; i < users.size(); i++)
		//users[i].display();

	return 0;
}


void parseXML(string xml_path, vector<User>& users, string dot_path) {
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
					users.push_back(new_user);

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

	////////////////// writing in dot file //////////////////
	ofstream myDOT(DOT_FILE);
	myDOT << "digraph {" << endl;
	// printing users & adding to dot file
	for (int i = 0;i < users.size();i++) {
		User my_user = users[i];
		my_user.display();
		for (int j = 0; j < my_user.follower_ids.size();j++) {
			int follower_id = my_user.follower_ids[j];
			myDOT << my_user.user_id << "->" << follower_id << ";" << endl;
		}
	}
	myDOT << "}";
	myDOT.close(); // close file
}