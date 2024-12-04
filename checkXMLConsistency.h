#include "bits/stdc++.h"
using namespace std;
string readXML( string filename) {
    ifstream file(filename);
    stringstream buffer;
    if (file.is_open()) {
        buffer << file.rdbuf();
        file.close();
    } else {
        cerr << "Error: Could not open file " << filename << std::endl;
    }
    return buffer.str();
}

bool  is_xml_valid(string filname){
    string xmlString = readXML(filname);


    vector <string> tags;
    // extract tages
    for(int i=0 ;i<xmlString.size()  ;i++){
        if(xmlString[i]=='<'){
             string tag;
            for(int j=i ; i<xmlString.size() ;j++){
                tag.push_back(xmlString[j]);
                if(xmlString[j]=='>'){
                    tags.push_back(tag);
                    i=j+1;
                    break;
                }
            }
        }
    }
    stack<string> tagsStack;
    // check validaty
    for(int i =0 ;i<tags.size() ;i++){

        if(tags[i][1]=='/'){
            if(tagsStack.empty()) return false;

             string current = tags[i].substr(2,tags[i].size()-3);
             string topOfStack=tagsStack.top().substr(1,tagsStack.top().size()-2);
//             cout<<current<<" "<<topOfStack<<endl;
             if(current==topOfStack) {
                 tagsStack.pop();
             }else return false;

        }
        else tagsStack.push(tags[i]);

    }

    if(!tagsStack.empty()) return false;

    return true;


}
