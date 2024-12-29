#ifndef USERS_TREE_H
#define USERS_TREE_H

#include "user.h"

class users_tree {
private:
    vector<user> users;

public:
    users_tree() {}
    void set_all_users(vector<vector<string>> all_users);
    void set_users(vector<string> input_data);
    vector<string> search_topic(string topic_name);
    vector<string> searchword(string word);
};

#endif
