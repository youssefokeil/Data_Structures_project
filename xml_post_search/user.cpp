#include "user.h"

void user::set_topics(vector<string> todecompose) {
    int i = 0;
    while (i < todecompose.size()) {
        string topic_name = todecompose[i++];
        int num_posts = stoi(todecompose[i++]);
        topic new_topic(topic_name);

        for (int j = 0; j < num_posts; j++) {
            new_topic.add_post(todecompose[i++]);
        }

        topics.emplace_back(new_topic);
    }
}

vector<string> user::get_posts_of_topic(string topic_name) {
    for (auto t : topics) {
        if (t.Topic == topic_name) {
            return t.get_posts_of_topic();
        }
    }
    return {};
}

vector<string> user::searchword(string word) {
    vector<string> result;
    for (auto t : topics) {
        auto res = t.searchword(word);
        result.insert(result.end(), res.begin(), res.end());
    }
    return result;
}
