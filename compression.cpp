#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <unordered_map>
using namespace std;


string symbol_gen(){

    char symbols[62] = {'0','1','2','3','4','5','6','7','8','9',
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
    ,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    static int c1=-1;
    static int c2=0; 

    c1++;
    if(c1>61){
        c1=0;
        c2++;
    }
    string temp="";
    temp+=symbols[c1];
    temp+=symbols[c2];
    return temp;
}


void split_XML(const string& xml, vector<string>& tokens) {
    size_t pos = 0;
    while (pos < xml.length()) {
        if (xml[pos] == '<') {
            // Find the end of the tag
            int end = xml.find('>', pos);
            if (end == string::npos) break;
            tokens.push_back(xml.substr(pos, end - pos + 1));
            pos = end + 1;
        } else {
            // Extract text between tags
            if (xml[pos] == ' '){
                pos++;
                continue;
            }
            int end = min(xml.find('<', pos),xml.find(' ', pos));
            if (end == string::npos) end = xml.length();
            string text = xml.substr(pos, end - pos);
            if (!text.empty()) tokens.push_back(text);
            pos = end;
        }
    }
}


string get_file_content_minified(ifstream& in){
    string file = "";
    string temp;
    int start,end;
    while(getline(in,temp)){
        start = temp.find_first_not_of(" \t\n");
        if (start == string::npos) continue;;
        end = temp.find_last_not_of(" \t\n");
        file += temp.substr(start,end-start+1);
    }
    return file;
}


void compress(ifstream& in,ofstream& out){
    string s = get_file_content_minified(in);
    // cout<<s<<endl;
    unordered_map<string,string> symbols;
    unordered_map<string,int> repeat;
    vector<string> tokens;
    split_XML(s,tokens);
    int tokens_len=tokens.size();
    for (int i = 0; i < tokens_len; i++)
    {
       repeat[tokens[i]]++;
    }
    for (auto token:repeat)
    {
        if((token.second>5 && token.first.length()>3)){
            string generated_symbol = symbol_gen();
            symbols[token.first]=generated_symbol;
        }
    }
    for (int i = 0; i < tokens_len; i++)
    {
        if(symbols.count(tokens[i])){
            tokens[i]= ("$"+symbols[tokens[i]]);
        }
    }
    s="";
    for (int i = 0; i < tokens_len; i++)
    {
        if(i+1>= tokens_len || (tokens[i][0] == '<' && tokens[i+1][0] == '<'))
        {
            s+=tokens[i];
        }
        else{
            s+=tokens[i]+" ";
        }
    }

    out<<s;
}

int main() {
    ifstream input("test_large.xml");
    ofstream output("compressed_large.xml");
    compress(input,output);

    
    

}