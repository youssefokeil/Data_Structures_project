#include <iostream>
#include "xml_compression_decompression/compression.h"
#include "xml_validaty/checkXMLConsistency.h"
#include "xml_beautify/beautify.h"
#include "xml_minify/minify.h"
#include "xml_to_JSON/ToJSON.h"

using namespace std;




int main(int argc, char* argv[]){

    string input_name;
    string output_name;
    string command = argv[1];
    string flag1 = argv[2];
    string flag2 = argv[4];


    

    if(flag1 == "-i" && flag2=="-o"){
        input_name = argv[3];
        output_name = argv[5];
    }
    else if(flag1 == "-o" && flag2=="-i"){
        input_name = argv[5];
        output_name = argv[3]; 
    }

    // xml_editor compress -i test2.xml -o test2_cmd.xml
    // xml_editor compress -i test2.xml -o test2_cmd.xml



    if(command == "compress"){
        compress(input_name,output_name);
    }
    else if(command == "decompress"){
        decompress(input_name,output_name);
    }
    else if(command == "verify"){
        string errors="";
        bool valid = is_xml_valid(input_name,"",false,errors);
        if(valid){
            cout<<"This File is valid"<<endl;
        }
        else{
            cout<<"This File is NOT valid"<<endl;
            cout<<errors<<endl;
        }
    }
    else if(command == "format"){
        beautifyXML(input_name,output_name);
    }
    else if(command == "minify"){
        ifstream input(input_name);
        minify(input,output_name);
    }
    else if(command == "convert"){
        ifstream input(input_name);
        ToJSON(input,output_name);
    }

}