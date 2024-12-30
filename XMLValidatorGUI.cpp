#include "XMLValidator.h"
#include <clocale> // For setlocale and locale information
#include <string.h>

using namespace System;
using namespace System::IO;

namespace XMLValidator {

    // Function to convert System::String^ to std::string (manual conversion)
    std::string ToStdString(String^ str) {
        IntPtr ptr = System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(str);
        char* charPtr = static_cast<char*>(ptr.ToPointer());
        std::string result(charPtr);
        System::Runtime::InteropServices::Marshal::FreeHGlobal(ptr);
        return result;
    }

    // Function to convert std::string to System::String^ (manual conversion)
    String^ ToSystemString(const std::string& str) {
        return gcnew String(str.c_str());
    }

    // Function to read the content of an XML file
    String^ XMLValidator::ReadXML(String^ filename) {
        // Convert managed String^ to std::string
        std::string stdFilename = ToStdString(filename);
        std::ifstream file(stdFilename);

        std::stringstream buffer;
        if (file.is_open()) {
            buffer << file.rdbuf();
            file.close();
        }
        else {
            Console::WriteLine("Error: Could not open file " + filename);
        }

        // Convert std::string to managed String^
        return ToSystemString(buffer.str());
    }

    // Function to validate if the XML is well-formed
    bool XMLValidator::IsXMLValid(String^ filename) {
        String^ xmlString = ReadXML(filename);

        std::vector<std::string> tags;
        std::string xmlStr = ToStdString(xmlString);

        // Extract tags from the XML string
        for (size_t i = 0; i < xmlStr.size(); i++) {
            if (xmlStr[i] == '<') {
                std::string tag;
                for (size_t j = i; j < xmlStr.size(); j++) {
                    tag.push_back(xmlStr[j]);
                    if (xmlStr[j] == '>') {
                        tags.push_back(tag);
                        i = j + 1;
                        break;
                    }
                }
            }
        }

        std::stack<std::string> tagsStack;

        // Check XML validity by validating the tags
        for (size_t i = 0; i < tags.size(); i++) {
            if (tags[i][1] == '/') {
                if (tagsStack.empty()) {
                    return false;
                }

                std::string current = tags[i].substr(2, tags[i].size() - 3);
                std::string topOfStack = tagsStack.top().substr(1, tagsStack.top().size() - 2);

                if (current == topOfStack) {
                    tagsStack.pop();
                }
                else {
                    return false;
                }
            }
            else {
                tagsStack.push(tags[i]);
            }
        }

        // If there are unclosed tags left in the stack, the XML is invalid
        if (!tagsStack.empty()) {
            return false;
        }

        return true;
    }
}
