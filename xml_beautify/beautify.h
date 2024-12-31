#include <string>
#include <vector>
using namespace std;

#ifndef BEAUTIFY_H
#define BEAUTIFY_H

string trim(const string& str);
void splitXML(const string& xml, vector<string>& tokens);
void beautifyXML(const string& inputFile, const string& outputFile);


#endif