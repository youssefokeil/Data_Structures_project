#include "tree.h" 
#include <fstream> 
#include <vector>

using namespace std ;

vector <string>  parse  (istream& ifile);
vector <string>  parse2  (istream& ifile) ;
bool isclosingtag (string s) ;
bool istag (string s) ;


void ToJSON ( istream & ifile  ,string  name ){
    ofstream ofile ("result.json") ;
    ofile << "{" << endl ;
    vector <string> parsed = parse(ifile) ;
    
    parsed.front()[0] = '"' ;
    parsed.front()[parsed.front().size()-1] = '"' ;
    
    Tree*  tree = new Tree (parsed.front()) ;
    parsed.erase(parsed.begin()) ;
    
    while (! parsed.empty())
    {
        if (istag(parsed.front()))
        {
            parsed.front()[0] = '"' ;
            parsed.front()[parsed.front().size()-1] = '"' ;
            // parsed.front().replace("<","\"") ;

            if (isclosingtag(parsed.front()))
            {
                tree -> move2parent() ;
            }
            else // opening tag
            {
                    tree -> addNode(parsed.front()) ;
                    tree -> move2child(tree->getchildren()-1) ;
            }
        }
        else 
        {
            tree->addData(parsed.front()) ;
        }
        // ofile <<  parsed.front() << endl ;
        parsed.erase(parsed.begin()) ;
    }  // kda el 7aga ba2et stored gowa tree 

    ofile << tree->DFT() ;
    // ofile << tree->hkt2() << endl ;    
    ofile << "\n}" << endl ;
    // cout << tree->getheight() << endl ;    
     
}

bool isclosingtag (string s)
{
    if (s[1] == '/')
    {
        return true ;
    }
    return false ;
}

bool istag (string s)
{
    if (s[0] == '<' && s[s.size()-1] == '>')
    {
        return true ;
    }
    else return false ;
}

vector <string>  parse  (istream& ifile) {    
    vector <string> lines ;
    string s ; 
    while ( getline(ifile,s) )
    {
        bool tag = false ;
        bool between = false ;
        int stin = 0 ;
        // int textend =-1 ;
        for (int i=0 ; i<s.size(); i++)
        {
            if (s[i] == ' ' & !tag & !between)
            {
                s.erase(s.begin()+i) ; 
                i-- ; 
            }
            else if (s[i] == '<')
            {   
                if(between)
                {
                string m = s.substr(stin,i) ;
                // m[i] = '"' ;
                // m[m.size()-1] = '"' ;
                lines.push_back(m) ;
                s= s.erase(stin,i) ;
                i -=stin-1 ; 
                }
                tag = true ; 
                stin = 0 ;
            }
            else if (s[i] == '>')
            {   
                if(tag)
                {
                    string k = s.substr(stin,i+1) ;
                    // k[i] = '"' ;
                    // k[k.size()-1] = '"' ;
                    lines.push_back(k) ;
                    s= s.erase(stin,i+1) ;
                    i=0;
                }
                tag = false ; 
                between = true ;
                stin = 0 ;
            }
        }
        if(s.size() > 0)
        {
            lines.push_back(s) ;
        }
    }
    return lines ;
}

vector <string>  parse2  (istream& ifile) 
{
    vector <string> lines ;
    string s ; 
    while ( getline(ifile,s) )
    {
        for (int i=0 ; i<s.size(); i++)
        {
            if (s[i] == ' ')
            {
                s.erase(s.begin()+i) ; 
                i-- ; 
            }
            else if (s[i] == '<')
            {
                break; 
            }
        }
        lines.push_back(s) ; 
    }
    return lines ;
}