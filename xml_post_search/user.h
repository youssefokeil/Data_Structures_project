#ifndef USER_H
#define USER_H

#include "topic.h"

class user {
private:
    int id;
    vector<topic> topics;

public:
    user() : id(0) {}
    void set_topics(vector<string> todecompose);
    vector<string> get_posts_of_topic(string topic_name);
    vector<string> searchword(string word);
};

#endif
