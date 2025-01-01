#include <algorithm>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iterator>
#include "User.h"

using namespace std;
using namespace std::filesystem;


// Static member definitions
std::multimap<int, int> User::id_to_following;
std::multimap<int, int> User::following_count_to_id;
std::multimap<int, int> User::follower_count_to_id;
std::multimap<int, int> User::connection_count_to_id;


// Implementation of User methods
void User::display() {
    std::cout << "User Name: " << user_name << std::endl
        << "Id:" << user_id << std::endl;
    std::cout << "followers_ids:";
    for (int id : follower_ids)
        std::cout << id << ",";
    std::cout << "\nfollowing_ids:";
    for (int id : following_ids)
        std::cout << id << ",";
    std::cout << "\nFollowers count:" << num_followers << std::endl;
    std::cout << "Following count:" << num_following << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

void User::add_follower(int follower_id) {
    follower_ids.push_back(follower_id);
    num_followers += 1;
    User::id_to_following.insert({ follower_id, user_id });
}

// Other methods follow the same pattern...
void User::add_following(map<int, User>& id_to_user) {
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
void User::finish_maps(map<int, User> id_to_user) {
    for (auto elem : id_to_user) {
        User user = elem.second;
        User::follower_count_to_id.insert(pair<int, int>(user.num_followers, elem.first));
        User::following_count_to_id.insert(pair<int, int>(user.num_following, elem.first));

        int num_connections = user.num_followers + user.num_following;
        User::connection_count_to_id.insert(pair<int, int>(num_connections, elem.first));
    }

}


int User::most_followers(map<int, User> id_to_user) {
	int most_followed_id = 0;
	if (User::follower_count_to_id.empty())
		cout << "Nothing in here yet";
	else {
		auto max_pair = prev(User::follower_count_to_id.end());

		most_followed_id = max_pair->second;

	}
	return most_followed_id;
}
void User::most_active(map<int, User> id_to_user) {
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
map<int, string> User::suggest(map<int, User> id_to_user, int id) {
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
map<int, string> User::mutual(map<int, User> id_to_user, vector<int> ids) {
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
