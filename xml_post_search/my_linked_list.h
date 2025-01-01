#ifndef MY_LINKED_LIST_H
#define MY_LINKED_LIST_H

#include "node.h"
#include <iostream>
using namespace std;

class my_linked_list {
private:
    node* root;
    uint32_t size;

public:
    my_linked_list() : root(nullptr), size(0) {}

    void push(string str = "", int value = 0);
    void displayContent();
    node* getRoot() { return root; }
};

#endif
