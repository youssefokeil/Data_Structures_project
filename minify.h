#include <fstream>
#include <iostream> 
#include <vector> 
#include <stack>

using namespace std;

void  minify(istream& ifile, const string& outputFileName) {

    ofstream ofile(outputFileName);
    if (!ofile.is_open()) {
        cerr << "Failed to open the output file: " << outputFileName << endl;
        return;
    }
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

    while (! lines.empty())
    {
        ofile << lines.front()   ; 
        lines.erase(lines.begin()) ;
    }

}