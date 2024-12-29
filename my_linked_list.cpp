#include "./my_linked_list.h"

void my_linked_list::push(string str, int value) {
    node* newNode = new node(str, value);
    newNode->next = root;
    root = newNode;
    size++;
}

void my_linked_list::displayContent() {
    node* current = root;
    int index = size;
    while (current) {
        cout << "Node " << index-- << ": [" << current->strVal << ", " << current->intVal << "]\n";
        current = current->next;
    }
}
