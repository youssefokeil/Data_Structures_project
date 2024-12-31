#include "beautify.h"
#include <iostream>
#include <fstream>

using namespace std;

// Trim function to remove leading/trailing whitespace from std::string
std::string XMLWrapper::trim(const std::string& str)
{
    int firstIndex = str.find_first_not_of(" \t\n");
    if (firstIndex == -1) return "";
    int lastIndex = str.find_last_not_of(" \t\n");
    return str.substr(firstIndex, lastIndex - firstIndex + 1);
}

// Function to split a single-line XML into tags and text content (native version)
void XMLWrapper::splitXML(const std::string& xml, std::vector<std::string>& tokens)
{
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

// Function to beautify XML from a single line (native version)
void XMLWrapper::beautifyXML(const std::string& inputFile, const std::string& outputFile)
{
    ifstream input(inputFile);
    ofstream output(outputFile);

    if (!input.is_open() || !output.is_open()) {
        cerr << "Error opening files." << endl;
        return;
    }

    string xmlContent;
    getline(input, xmlContent, '\0'); // Read the entire file into a single string

    vector<string> tokens;
    splitXML(xmlContent, tokens); // Split the XML into tags and text content

    int indentLevel = 0;
    const string indent = "  "; // Indent with 2 spaces

    for (string token : tokens) {
        // to remove empty tokens (handle some cases that were not removed by the trim function)
        if (token[0] - '0' == -38) continue;
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

// Managed wrapper methods to handle System::String^

System::String^ XMLWrapper::Trim(System::String^ str)
{
    std::string nativeStr = msclr::interop::marshal_as<std::string>(str);
    std::string result = trim(nativeStr);
    return gcnew System::String(result.c_str());
}

void XMLWrapper::SplitXML(System::String^ xml, List<System::String^>^ tokens)
{
    std::string nativeXml = msclr::interop::marshal_as<std::string>(xml);
    std::vector<std::string> nativeTokens;
    splitXML(nativeXml, nativeTokens);

    for (const auto& token : nativeTokens) {
        tokens->Add(gcnew System::String(token.c_str()));
    }
}

void XMLWrapper::BeautifyXML(System::String^ inputFile, System::String^ outputFile)
{
    std::string nativeInput = msclr::interop::marshal_as<std::string>(inputFile);
    std::string nativeOutput = msclr::interop::marshal_as<std::string>(outputFile);
    beautifyXML(nativeInput, nativeOutput);
}
