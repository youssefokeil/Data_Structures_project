#include "hashing_instant.h"
#define char_test(x) (((x) >= 48 && (x) <= 57) || ((x) >= 65 && (x) <= 90) || ((x) >= 97 && (x) <= 122))
hashing_instant::hashing_instant(string working_on) {
    strList = breakString(working_on);
    my_string = working_on;
    djb2(strList.getRoot());
    createHashTable(strList.getRoot());
}

void hashing_instant::djb2(node* root) {
    while (root) {
        unsigned long long hash = 5381;
        for (char c : root->strVal) {
            hash = ((hash << 5) + hash) + c;
        }
        root->intVal = hash;
        root = root->next;
    }
}

void hashing_instant::createHashTable(node* root) {
    while (root) {
        if (myMap.find(root->intVal) == myMap.end()) {
            my_linked_list newList;
            newList.push(root->strVal);
            myMap[root->intVal] = newList;
        }
        else {
            myMap[root->intVal].push(root->strVal);
        }
        root = root->next;
    }
}

my_linked_list hashing_instant::breakString(string hugeString) {
    my_linked_list result;
    string word;
    for (char c : hugeString) {
        if (char_test(c)) {
            word += c;
        }
        else if (!word.empty()) {
            result.push(word);
            word.clear();
        }
    }
    if (!word.empty()) result.push(word);
    return result;
}

string hashing_instant::search(string searchWord) {
    unsigned long long hash = 5381;
    for (char c : searchWord) {
        hash = ((hash << 5) + hash) + c;
    }

    if (myMap.find(hash) != myMap.end()) {
        node* current = myMap[hash].getRoot();
        while (current) {
            if (current->strVal == searchWord) {
                return my_string;
            }
            current = current->next;
        }
    }
    return "not found";
}
