#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "beautify.h"
#include "compression.h"
using namespace std;


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


void compress(const string& input_name,const string& output_name){
    ifstream in(input_name);
    ofstream out(output_name);
    string s = get_file_content_minified(in);
    int symbol_no = 0;
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
            string generated_symbol = to_string(symbol_no++);
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

    for (pair<string,string> i:symbols)
    {
        s+=i.first+" "+i.second+" ";
    }
    
    s+="End_Symbols_mapping ";


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
    cout<<"File Compressed Succesfully"<<endl;
}


void decompress(const string& input_name,const string& output_name){
    ifstream in(input_name);
    ofstream out(output_name);
    string s = get_file_content_minified(in);
    unordered_map<string,string> symbols;
    vector<string> tokens;
    split_XML(s,tokens);
    int tokens_len=tokens.size();

    int file_start;

    for (int i = 0; i < tokens_len; i+=2)
    {
        if(tokens[i] == "End_Symbols_mapping"){
            file_start=i+1;
            break;
        }
        else{
            symbols["$"+tokens[i+1]]=tokens[i];
        }
    }

    for (int i = file_start; i < tokens_len; i++)
    {
        if(symbols.count(tokens[i])){
            tokens[i]= (symbols[tokens[i]]);
        }
    }

    s="";
    for (int i = file_start; i < tokens_len; i++)
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
    beautifyXML(output_name,output_name);
    cout<<"File Compressed Succesfully"<<endl;
    

}

