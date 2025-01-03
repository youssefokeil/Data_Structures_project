#include <iostream>
#include <map>
#include <vector>
#include <sstream>

#include "xml_compression_decompression/compression.h"
#include "xml_validaty/checkXMLConsistency.h"
#include "xml_beautify/beautify.h"
#include "xml_minify/minify.h"
#include "xml_to_JSON/ToJSON.h"

// social analysis includes
#include "xml_social_Analysis/Utils.h"
#include "xml_social_Analysis/User.h"

//post and topic searh includes

#include "xml_post_search/users_list.h"
#include "xml_post_search/user.h"
#include "xml_post_search/post.h"
#include "xml_post_search/node.h"
#include "xml_post_search/my_linked_list.h"
#include "xml_post_search/hashing_instant.h"
#include "xml_post_search/topic.h"
using namespace std;




int main(int argc, char* argv[]){

    string input_name;
    string output_name;
    string command = argv[1];
    string flag1 = argv[2];
    string flag2="-p";
    
    if(argc>4)
        flag2 = argv[4];
	
    // for social network analysis
    map<int, User> id_to_users;
    int id;
    vector<int> ids;

    //for word and topic search
    vector<vector<string>> all_users;
    vector<string> related_topic_posts;

    if(flag1 == "-i" && flag2=="-o"){
        input_name = argv[3];
        output_name = argv[5];
    }
    else if(flag1 == "-o" && flag2=="-i"){
        input_name = argv[5];
        output_name = argv[3]; 
    }
    else if(flag1== "-i" && flag2=="-ids"){
        string ids_str=argv[5];
        stringstream ss(ids_str);
        string token;

        input_name= argv[3];
        ids_str= argv[5];

        // Split the string by ','
        while (std::getline(ss, token, ',')) 
            // Convert to integer and add to the result
            ids.push_back(std::stoi(token));
    }
    else if(flag1=="-i" && flag2=="-id"){
        
        input_name=argv[3];
        id=stoi(argv[5]);
    }else if(flag1=="-i" && flag2=="-p"){
        input_name=argv[3];
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
    else if(command == "json"){
        ifstream input(input_name);
        ToJSON(input,output_name);
    }

    // graph drawing
    else if(command=="draw"){
        parseXML(input_name, id_to_users);
	    draw(id_to_users, output_name);

        cout<< "Graph drawn at "<<output_name;
    }

    // max followers
    else if(command=="most_influencer"){

        parseXML(input_name, id_to_users);
    	int most_followed_id = User::most_followers(id_to_users);
        cout << "\nMost followed id:" << most_followed_id << endl
            << "Most followed name:" << id_to_users[most_followed_id].user_name << endl
            << "Has follower count:" << id_to_users[most_followed_id].num_followers << endl;
    }

    else if(command=="most_active"){
        parseXML(input_name, id_to_users);        
        User::most_active(id_to_users);

    }

    else if(command=="suggest"){
        parseXML(input_name, id_to_users); 
        map<int, string> suggestions_map = User::suggest(id_to_users, 2);

        cout << "\nSuggestions for user: " << id_to_users[2].user_name << " with id:" << 2 << endl;
        for (auto suggestion : suggestions_map)
            cout << suggestion.second << " ";
        cout << endl;
    }

    else if(command=="mutual"){


        parseXML(input_name, id_to_users); 
        cout<<"\n";
        map<int, string> mutuals_map = User::mutual(id_to_users, ids);
        for (auto mutual : mutuals_map)
            cout << "Mutual id:" << mutual.first << " With name:" << mutual.second << endl;
    }

    else if(command=="suggest"){
        parseXML(input_name, id_to_users); 

        map<int, string> suggestions_map = User::suggest(id_to_users, id);

        cout << "\nSuggestions for user: " << id_to_users[2].user_name << " with id:" << 2 << endl;
        for (auto suggestion : suggestions_map)
            cout << suggestion.second << " ";
        cout << endl;
    }
    else if(command=="search"){ 
     string filename=argv[5];
     all_users=parseXMLToVector(filename); 
     users_list my_users;
     my_users.set_all_users(all_users);
     string mycommand=argv[2];
     string intended=argv[3];
    if(mycommand=="-w"){
	   related_topic_posts= my_users.searchword(intended);
	    int n=0;
	    for(auto i : related_topic_posts){
		    n++;
		    cout<<endl<<n<<": "<<i<<endl;
	    }
    } 
     else if(mycommand=="-t"){
	     related_topic_posts=my_users.search_topic(intended);
	     int n=0;
	     for(auto i : related_topic_posts){
		    n++;
		    cout<<endl<<n<<": "<<i<<endl;
	    }
}
	    
	    
}
}
