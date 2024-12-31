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
using namespace std::filesystem;

// CONSTANTS

// relative path to XML file
const string XML_FILE = "Resources/sample.xml";
const string DOT_FILE = "Resources/graph.dot";
const string GRAPH_PATH = "Resources/graph.jpg";


// class for each user
class User {
public:
	string user_name;
	int user_id = 0;
	int num_followers = 0, num_following = 0;

	// if id "1" is following "3" id_to_following[1]=3;
	static multimap<int, int> id_to_following;

	static multimap<int, int> following_count_to_id;
	static multimap<int, int> follower_count_to_id;
	static multimap<int, int> connection_count_to_id;

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
		cout << "\nFollowers count:" << num_followers << endl;
		cout << "Following count:" << num_following << endl;
		cout << "-----------------------------------" << endl;
	}
	void add_follower(int follower_id) {
		follower_ids.push_back(follower_id);
		num_followers += 1;
		User::id_to_following.insert(pair<int, int>(follower_id, user_id));
	}
	static void add_following(map<int, User>& id_to_user) {
		for (auto elem : id_to_following) {
			int user_id = elem.first;
			int following_id = elem.second;
			User user = id_to_user[user_id];
			user.following_ids.push_back(following_id);
			user.num_following += 1;

			id_to_user[user_id] = user; //change user

		}
	}
	// to be called after parsing everything 
	static void finish_maps(map<int, User> id_to_user) {
		for (auto elem : id_to_user) {
			User user = elem.second;
			User::follower_count_to_id.insert(pair<int, int>(user.num_followers, elem.first));
			User::following_count_to_id.insert(pair<int, int>(user.num_following, elem.first));

			int num_connections = user.num_followers + user.num_following;
			User::connection_count_to_id.insert(pair<int, int>(num_connections, elem.first));
		}

	}
	static int most_followers(map<int, User> id_to_user) {
		int most_followed_id = 0;
		if (User::follower_count_to_id.empty())
			cout << "Nothing in here yet";
		else {
			auto max_pair = prev(User::follower_count_to_id.end());

			most_followed_id = max_pair->second;

		}
		return most_followed_id;
	}
	static void most_active(map<int, User> id_to_user) {
		if (User::connection_count_to_id.empty())
			cout << "Nothing in here yet";
		else {
			auto max_pair = prev(User::connection_count_to_id.end());

			int most_active_id = max_pair->second;
			cout << "\nMost active id:" << most_active_id << endl
				<< "Most active name:" << id_to_user[most_active_id].user_name << endl
				<< "Has connections count:" << max_pair->first << endl;
		}
	}
	static map<int, string> suggest(map<int, User> id_to_user, int id) {
		vector<int> f_of_followers;
		vector<int> user_followers_ids = id_to_user[id].follower_ids;
		for (int follower_id : user_followers_ids) {
			// this step is important to ensure that we have f_of_followers>=user_followers_ids
			f_of_followers.push_back(follower_id);
			vector<int> f_of_followers_ids = id_to_user[follower_id].follower_ids;
			for (int f_o_f_id : f_of_followers_ids) {
				// follower of follower is not himself
				if (f_o_f_id != id)
					f_of_followers.push_back(f_o_f_id);
			}
		}


		// sort both arrays
		sort(f_of_followers.begin(), f_of_followers.end());
		sort(user_followers_ids.begin(), user_followers_ids.end());

		cout << "follower of followers size:" << f_of_followers.size() << endl;
		cout << "followers size:" << user_followers_ids.size() << endl;

		// have to check that they aren't already followers
		// we use the code we used in missing numbers in hacker rank
		vector<int> suggest_ids;
		map<int, string> suggestions_map;

		int j = 0;
		for (int i = 0;i<int(f_of_followers.size());i++) {
			// if both elements are equal then we skip ahead
			if ((j<int(user_followers_ids.size())) && f_of_followers[i] == user_followers_ids[j])
				j++;

			// checks if last element in vector is equal to element about to be pushed
			// important so that we don't have repeated missing numbers
			else if (suggest_ids.end() == suggest_ids.begin() || (*(--suggest_ids.end())) != f_of_followers[i]) {
				int suggestion_id = f_of_followers[i];
				suggest_ids.push_back(suggestion_id);
				suggestions_map[suggestion_id] = id_to_user[suggestion_id].user_name;
			}
		}

		return suggestions_map;
	}
	static map<int, string> mutual(map<int, User> id_to_user, vector<int> ids) {
		map<int, string> mutual_map;
		map<int, int> follower_to_count_map;
		for (int id : ids) {
			vector<int> followers_ids = id_to_user[id].follower_ids;
			for (int follower_id : followers_ids) {
				if (follower_to_count_map.find(follower_id) == follower_to_count_map.end())
					// first instantiation
					follower_to_count_map[follower_id] = 1;
				else {
					// already exists
					int count = follower_to_count_map[follower_id];
					count++;
					// existed number of id times
					if (count == ids.size())
						mutual_map[follower_id] = id_to_user[follower_id].user_name;
					else
						follower_to_count_map[follower_id] = count;
				}
			}
		}
		return mutual_map;



	}
};


// Header of functions
void parseXML(string xml_path, map<int, User>& id_to_users);
void draw(map<int, User>& id_to_users, string graph_path);

multimap<int, int> User::id_to_following;

multimap<int, int> User::following_count_to_id;
multimap<int, int> User::follower_count_to_id;
multimap<int, int> User::connection_count_to_id;

int main() {

	map<int,User> id_to_users;

	// draw
	parseXML(XML_FILE, id_to_users);
	draw(id_to_users, GRAPH_PATH);

	// max followers
	int most_followed_id=User::most_followers(id_to_users);
	cout << "\nMost followed id:" << most_followed_id << endl
		<< "Most followed name:" << id_to_users[most_followed_id].user_name << endl
		<< "Has follower count:" << id_to_users[most_followed_id].num_followers << endl;

	// most active
	User::most_active(id_to_users);

	// suggest
	map<int,string> suggestions_map=User::suggest(id_to_users, 2);

	cout << "\nSuggestions for user: " << id_to_users[2].user_name << " with id:" << 2 << endl;
	for (auto suggestion : suggestions_map)
		cout << suggestion.second << " ";
	cout << endl;

	// mutual
	vector<int> ids = { 2,3 };
	map<int, string> mutuals_map = User::mutual(id_to_users, { 2,3 });
	for (auto mutual : mutuals_map)
		cout << "Mutual id:" << mutual.first <<" With name:"<<mutual.second << endl;


	return 0;
}

void parseXML(string xml_path, map<int,User>& id_to_users) {


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
					id_to_users[new_user.user_id]=new_user;

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


void draw(map<int, User>& id_to_users,string graph_path) {
	////////////////// writing in dot file //////////////////
	ofstream myDOT(DOT_FILE);
	myDOT << "digraph {" << endl;
	// printing users & adding to dot file
	for (auto map_element: id_to_users) {
		User my_user = map_element.second;
		my_user.display();
		for (int j = 0; j < my_user.follower_ids.size();j++) {
			int follower_id = my_user.follower_ids[j];
			myDOT << map_element.first<< "->" << follower_id << ";" << endl;
		}
	}
	myDOT << "}";
	myDOT.close(); // close file


	///////////////////// drawing graph //////////////////////////////
	string command_str = "dot -Tjpg " + DOT_FILE + " -o " + graph_path;
	const char* command = command_str.c_str();
	system(command);

}
