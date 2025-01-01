#ifndef HASHING_INSTANT_H
#define HASHING_INSTANT_H

#include "my_linked_list.h"
#include <unordered_map>
#include <cctype>

class hashing_instant {
private:
    string my_string;
    my_linked_list strList;
    unordered_map<long long, my_linked_list> myMap;

    void djb2(node* root);
    void createHashTable(node* root);
    my_linked_list breakString(string hugeString);

public:
    hashing_instant(string working_on);
    string search(string searchWord);
};

#endif
