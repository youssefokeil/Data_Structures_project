#ifndef TOPIC_H
#define TOPIC_H

#include "post.h"
#include <vector>

class topic {
private:
    string Topic;
    vector<post> posts;

public:
    topic(string Topic) : Topic(Topic) {}
    void add_post(string post_data);
    vector<string> get_posts_of_topic();
    vector<string> searchword(string word);
    friend class user;
};

#endif
