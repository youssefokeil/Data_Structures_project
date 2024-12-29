#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class node {
public:
    long long intVal;
    string strVal;
    node* next;

    node() : intVal(0), strVal(""), next(nullptr) {}
    node(string strValue) : intVal(0), strVal(strValue), next(nullptr) {}
    node(string strValue, int intValue) : intVal(intValue), strVal(strValue), next(nullptr) {}
};

#endif
