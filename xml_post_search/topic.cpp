#include "topic.h"
//#include "./post.h"
void topic::add_post(string post_data) {
    posts.emplace_back(post_data);
}

vector<string> topic::get_posts_of_topic() {
    vector<string> result;
    for (auto p : posts) {
        result.emplace_back(p.get_post());
    }
    return result;
}

vector<string> topic::searchword(string word) {
    vector<string> result;
    for (auto p : posts) {
        if (p.searchword(word) != "not found") {
            result.emplace_back(p.get_post());
        }
    }
    return result;
}
