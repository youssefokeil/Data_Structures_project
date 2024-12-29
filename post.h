#ifndef POST_H
#define POST_H

#include "hashing_instant.h"

class post {
private:
    string data;
    hashing_instant myhash;

public:
    post(string data) : data(data), myhash(data) {}
    string searchword(string word) { return myhash.search(word); }
    string get_post() { return data; }
};

#endif
