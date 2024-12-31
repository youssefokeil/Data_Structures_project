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

/*
 * filename => path to the file
 * xmlAsString => xmlstring
 * isStringXml => true if stringxml
 * err=> error will be passes to this varible
 *
 */
bool  is_xml_valid(string filname,string xmlAsString , bool isStringXml ,string & err ){
    string xmlString;
if(isStringXml){
    xmlString=xmlAsString;
}else{
    xmlString=readXML(filname);
}

//    cout<<xmlString<<endl;
    vector <string> tags;
    // extract tages
    for(int i=0 ;i<xmlString.size()  ;){
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
        else if(xmlString[i]=='>'){
            tags.push_back(string(1,xmlString[i]));
            i++;
        }
        else{
            i++;
        }
    }
//    for(auto x : tags){
//        cout<<x<<endl;
//    }
    stack<string> tagsStack;
    // check validaty
    string errors="";
    bool isValid= true;

    for(int i =0 ;i<tags.size() ;i++){
        cout<<tags[i]<<endl;
        if(tags[i][1]=='/'){
            if(tagsStack.empty()) return false;
             string current = tags[i].substr(2,tags[i].size()-3);
             string topOfStack=tagsStack.top().substr(1,tagsStack.top().size()-2);
//             cout<<current<<" "<<topOfStack<<endl;
             if(current==topOfStack) {
                 tagsStack.pop();
             }else{
                 isValid= false;
                 stack<string> step ;
                 bool isFound=false;
                 while (!tagsStack.empty()){
                     string current = tags[i].substr(2,tags[i].size()-3);
                     string topOfStack=tagsStack.top().substr(1,tagsStack.top().size()-2);
                     if(topOfStack==current){
                         tagsStack.pop();
                         isFound= true;
                     }else{
                         step.push(tagsStack.top());
                         tagsStack.pop();
                     }


                 }
                 while (!step.empty()){
                     tagsStack.push(step.top());
                     step.pop();
                 }
                 if(!isFound){
                     errors+=("error : tag "+tags[i]+" has no opening tag \n");
                 }


             }

        }
        else tagsStack.push(tags[i]);

    }

    if(!tagsStack.empty()){
        isValid= false;
        while (!tagsStack.empty()){
            errors+=("error : tag "+ tagsStack.top()+" has no closing tag \n");
            tagsStack.pop();
        }
    };


//    cerr<<errors;
    err=errors;
    return isValid;


}

