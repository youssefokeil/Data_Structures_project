#include <iostream>
#include <string>

using namespace std;

class Node {
    private : 
    string data;
    int children; // Number of children of this node
    Node * child[10]; // Array of 10 pointers to Node
    Node * parent; // Pointer to parent node of this node
    public :
    Node (){ data = ""; children = 0;} // Constructor
    Node(string s) : data(s), children(0) { }
    friend class Tree ;
    // Other member functions and constructors can be added here
};

class Tree {
    private : 
    Node * root;
    Node * current;

    string Depth_first_traversal (Node * root) {
        string s = "";
        s = s + root -> data;
        for (int i = 0; i < root -> children; i++) {
            s=s +Depth_first_traversal(root -> child[i]);
            // s = s + current -> child[i] -> Depth_first_traversal();
        }
        return s;
    }

    public : 

    Tree() { root = nullptr; current =nullptr ; } // Constructor
    Tree (string s) { root = new Node(s);  current = root ; } // Constructor
    void addNode(string s) {
        Node * newNode = new Node(s);
        current -> child[current -> children] = newNode;
        current -> children++;
        newNode -> parent = current;
    }
    bool move2child (int i) { // returns true if move is successful
        if (current -> children > i) {
            current = current -> child[i];
        }
    }
    void move2parent() {
        if (current != root )
        current = current -> parent;
    }
    string getData() {
        return current -> data;
    }
    
    string DFT () {
        return Depth_first_traversal(root);
    }
    
    
    // Other member functions and constructors can be added here
};

int main() {
    return 0;
}