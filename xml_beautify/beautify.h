#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Function to trim leading and trailing spaces from a string
string trim(const string& str) {
    int firstIndex = str.find_first_not_of(" \t\n");
    if (firstIndex == -1) return "";
    int lastIndex = str.find_last_not_of(" \t\n");
    return str.substr(firstIndex, lastIndex-firstIndex+1);
}

// Function to split a single-line XML into tags and text content
void splitXML(const string& xml, vector<string>& tokens) {
    size_t pos = 0;
    while (pos < xml.length()) {
        if (xml[pos] == '<') {
            // Find the end of the tag
            int end = xml.find('>', pos);
            if (end == -1) break;
            tokens.push_back(xml.substr(pos, end - pos + 1));
            pos = end + 1;
        } else {
            // Extract text between tags
            int end = xml.find('<', pos);
            if (end == string::npos) end = xml.length();
            string text = trim(xml.substr(pos, end - pos));
            if (!text.empty()) tokens.push_back(text);
            pos = end;
        }
    }
}

// Function to beautify XML from a single line
void beautifyXML(const string& inputFile, const string& outputFile) {
    ifstream input(inputFile);


    if (!input.is_open() ) {
        cerr << "Error opening files." << endl;
        return;
    }

    string xmlContent;
    getline(input, xmlContent, '\0'); // Read the entire file into a single string
    ofstream output(outputFile);
    if (!output.is_open()) {
        cerr << "Error opening files." << endl;
        return;
    }

    vector<string> tokens;
    splitXML(xmlContent, tokens); // Split the XML into tags and text content

    int indentLevel = 0;
    const string indent = "  "; // Indent with 2 spaces

    for (string token : tokens) {
        // to remove empty tokens(handel some case did not removed by trim func)
        if(token[0]-'0'==-38)continue;
        if (token[0] == '<') {
            if (token[1] == '/') {
                // Closing tag, reduce indent
                indentLevel--;
            }
            // Write the tag with the current indentation
            output << string(indentLevel * indent.size(), ' ') << token << endl;

            if (token[1] != '/' && token.back() != '/') {
                // Opening tag, increase indent
                indentLevel++;
            }
        } else {
            // Write text content with the current indentation
            output << string(indentLevel * indent.size(), ' ') << token << endl;
        }
    }

    input.close();
    output.close();
    cout << "Beautified XML saved to " << outputFile << endl;
}

