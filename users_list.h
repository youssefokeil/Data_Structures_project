#ifndef USERS_LIST_H
#define USERS_LIST_H

#include "user.h"

class users_list {
private:
    vector<user> users;

public:
    users_list() {}
    void set_all_users(vector<vector<string>> all_users);
    void set_users(vector<string> input_data);
    vector<string> search_topic(string topic_name);
    vector<string> searchword(string word);
};

#endif
