#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
    private : 
    string name;
    string data ;
    int children; // Number of children of this node
    int depth  ; 
    vector<Node *> child ;
    // Node * child[20]; // Array of 10 pointers to Node
    Node * parent; // Pointer to parent node of this node
    public :
    Node (){ name = "" ; data = "" ; children = 0;} // Constructor
    Node(string s) { name = s; children = 0 ;data = "" ;  } // Constructor
    friend class Tree ;
    // Other member functions and constructors can be added here
};

class Tree {
    private : 
    Node * root;
    Node * current;
    int height ; 
    string hkt(Node* root)
    { 
        unifyborthers(root) ;
        string s ="" ; 
        s+= root -> name ;
        s+=" || " ;
        for(int i = 0; i < root ->children; i++) {
            s = s + hkt(root -> child[i]);
        }
        s+= "\n" ;
        return s ;
    }
    string Depth_first_traversal (Node * root) {
        string s ="" ;
        for (int i =0 ; i<root->depth ; i++)
        {
            s+= "\t" ;
        }
        if (root -> children == 1)
        {
            s+= root -> name ;
            s+= " : " ;
            s+="{" ;
            s+= "\n" ;
            s+= Depth_first_traversal(root -> child[0]) ;
            s+="} ," ;
            return s ;
        }
        else if (root -> children > 1)
        {   
            if (brothersexist(root))
            {
                s+= root -> name ;
                s+= " : " ;
                s+="\t {" ; 
                s+= "\n\t" ;
                s+= root->child[0] -> name ;
                s+= " : [\n\t { " ;
                for (int i = 0 ; i < root -> children ; i++)
                {
                    s+= "\n" ;
                    // s+= Depth_first_traversal(root -> child[i]) ;
                    for(int k=0; k<root->child[i]->children;k++)
                    {
                        s+= Depth_first_traversal(root -> child[i]->child[k]) ;
                            if (k != root -> child[i]->children -1)
                            {
                                s+= "," ;
                            }
                        s+="\n\t"; 
                    }
                    s+="}";
                    if (i != root -> children -1)
                    {
                        s+= "," ;
                      s+= "\n\t" ;
                       s+= "{" ;
                    }
                    
                }
                s+= " ] " ;
                s+="\t }" ; 

            }
            else 
            {
                s+= root -> name ;
                s+= " : " ;
                s+= " [ " ;
                s+= "\n\t" ;
                s+="{" ;
                for (int i = 0 ; i < root -> children ; i++)
                {
                    s+= "\n" ;
                    s+= Depth_first_traversal(root -> child[i]) ;
                    if (i != root -> children -1)
                    {
                        s+= "," ;
                    }
                }
                s+="} " ;
                s+="]" ;
            }
        }
        else
        if (root ->children == 0)
        {
            s+= root -> name ;
            s+= " :" ;
            s+="\"" ; 
            s+= root -> data ;
            s+="\"" ; 
            return s ;
        }       

        return s ; 
    }
    public : 

    Tree() { root = nullptr; current =nullptr ; height=-1; } // Constructor
    Tree (string s) { root = new Node(s); root->depth=0 ; current = root ;  height=0; } // Constructor
    void addNode(string s) {
        if (root == nullptr )
        {
            root  = new Node(s);
            root->depth=0;
            current = root ; 
            height = 0 ;
            return ;
        }
        else {
        Node * newNode = new Node(s);
        // current -> child[current -> children] = newNode; // when was static array 
        current -> child.push_back( newNode );
        current -> children++;
        newNode -> parent = current;
        newNode -> depth = current -> depth +1 ;
        height = max(height,current -> depth +1) ;
        }
    }
    int getheight ()
    {
        return height ;
    }
    bool move2child (int i) { // returns true if move is successful
        if (current -> children > i) {
            current = current -> child[i];
            return true ; 
        }
        return false ;
    }
    
    void move2parent() {
        if (current != root )
        current = current -> parent;
    }
    string getname() {
        return current -> name;
    }
    bool similar (string s)
    {
        if (current -> children <1 )
        {
            return false  ;
        }
        else 
        {
            for (int i = 0 ; i < current -> children ; i++)
            {
                if (current -> child[i] -> name == s)
                {
                    return true ;
                }
            }
        }
        return false ; 
    }
    string hkt2()
    {
        return hkt(root) ;
    }
    
    string DFT () {
        return Depth_first_traversal(root);
    }
    int getchildren ()
    {
        return current -> children ;
    }
    bool inchildren (string s )
    { 
        for (int i = 0 ; i < current -> children ; i++)
        {
            if (current -> child[i] -> name == s)
            {
                return true ; 
            }
        }
        return false ;
    }
    int searchinchildren (string s )
    { 
        for (int i = 0 ; i < current -> children ; i++)
        {
            if (current -> child[i] -> name == s)
            {
                return i ; 
            }
        }
        return -1 ;
    } 
    bool brothersexist (Node * node)
    {
        for (int i =0 ; i<node->children; i++)
        {
            for (int j = i+1 ; j<node->children; j++)
            {
                if (node->child[i]->name == node->child[j]->name)
                {
                    return true ;
                }
            }
        }
        return false ;
    }
    void unifyborthers(Node * parent )
    {
        int m= parent -> children ;
        for (int i = 0 ; i < m  ; i++)
        {
            for (int j = i+1 ; j < parent -> children ; j++)
            {
                if (parent -> child[i] -> name == parent -> child[j] -> name)
                {
                    Node* temp = parent -> child[j] ;
                    for( int m=0; m < temp -> children ; m++)
                    {
                        parent -> child[i] -> child.push_back(temp -> child[m]) ;
                        parent -> child[i] -> children ++ ;
                    }
                    parent->children -- ;
                    parent->child.erase(parent->child.begin()+j) ;
                    delete temp ;
                }
            }
        }
    }
    void addData (string s)
    {
        current -> data= s ;
    }
    string getdata ()
    {
        return current -> data ;
    }

    bool  removeleaf ()
    {
        if( current -> children == 0)
        {
            Node * Temp = current ; 
            current = current -> parent ;
            for (int i = 0 ; i < current -> children ; i++)
            {
                if (current -> child[i] == Temp)
                {
                    for (int j = i ; j < current -> children -1 ; j++)
                    {
                        current -> child[j] = current -> child[j+1] ;
                    }
                    current -> children -- ;
                    delete Temp ;
                    return true ;
                }
            }

            return true ;
        }
        return false ;
    }
    bool hasbrothers (Node * node)
    {
        Node * temp =node ;
        if (temp -> parent -> children <1)
        {
            return false  ;
        }
        temp = temp->parent ; 
        int num=0 ; 
        for(int i=0 ; i < temp -> parent -> children ; i++)
        {
            if (temp -> parent -> child[i] == node )
            {
                num++; 
            }
        }
        if (num >1)
        {
            return true ;
        }
        else 
        {
            return false ;
        }
    }
    
    // Other member functions and constructors can be added here
};