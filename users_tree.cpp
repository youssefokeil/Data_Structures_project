#include "./users_tree.h"

void users_tree::set_all_users(vector<vector<string>> all_users) {
    for (auto user : all_users) {
        set_users(user);
    }
}
void users_tree::set_users(vector<string> input_data) {
    user new_user;
    new_user.set_topics(input_data);
    users.push_back(new_user);
}

vector<string> users_tree::search_topic(string topic_name) {
    vector<string> result;
    for (auto u : users) {
        auto res = u.get_posts_of_topic(topic_name);
        result.insert(result.end(), res.begin(), res.end());
    }
    return result;
}

vector<string> users_tree::searchword(string word) {
    vector<string> result;
    for (auto u : users) {
        auto res = u.searchword(word);
        result.insert(result.end(), res.begin(), res.end());
    }
    return result;
}
