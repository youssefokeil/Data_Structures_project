#include "XMLValidator.h"
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
String^ XMLValidator::ReadXML(String^ filename) {
    try {
        StreamReader^ reader = gcnew StreamReader(filename);
        String^ content = reader->ReadToEnd();
        reader->Close();
        return content;
    }
    catch (Exception^ ex) {
        Console::Error->WriteLine("Error: Could not open file " + filename + ". Exception: " + ex->Message);
        return nullptr;
    }
}

bool XMLValidator::IsXMLValid(String^ filename, String^ xmlAsString, bool isStringXml, String^% err) {
    String^ xmlContent;
    if (isStringXml) {
        xmlContent = xmlAsString;
    }
    else {
        xmlContent = ReadXML(filename);
        if (xmlContent == nullptr) {
            err = "Error reading XML file.";
            return false;
        }
    }

    List<String^>^ tags = gcnew List<String^>();
    for (int i = 0; i < xmlContent->Length;) {
        if (xmlContent[i] == '<') {
            String^ tag = "";
            for (int j = i; j < xmlContent->Length; j++) {
                tag += xmlContent[j];
                if (xmlContent[j] == '>') {
                    tags->Add(tag);
                    i = j + 1;
                    break;
                }
            }
        }
        else if (xmlContent[i] == '>') {
            tags->Add(gcnew String(">"));
            i++;
        }
        else {
            i++;
        }
    }

    Stack<String^>^ tagStack = gcnew Stack<String^>();
    String^ errors = "";
    bool isValid = true;

    for each (String ^ tag in tags) {
        if (tag->StartsWith("</")) {
            if (tagStack->Count == 0) {
                errors += "Error: Closing tag " + tag + " has no opening tag.\n";
                isValid = false;
                continue;
            }

            String^ currentTag = tag->Substring(2, tag->Length - 3);
            String^ stackTopTag = tagStack->Peek()->Substring(1, tagStack->Peek()->Length - 2);

            if (currentTag == stackTopTag) {
                tagStack->Pop();
            }
            else {
                isValid = false;
                Stack<String^>^ tempStack = gcnew Stack<String^>();
                bool isFound = false;

                while (tagStack->Count > 0) {
                    stackTopTag = tagStack->Peek()->Substring(1, tagStack->Peek()->Length - 2);
                    if (stackTopTag == currentTag) {
                        tagStack->Pop();
                        isFound = true;
                        break;
                    }
                    else {
                        tempStack->Push(tagStack->Pop());
                    }
                }

                while (tempStack->Count > 0) {
                    tagStack->Push(tempStack->Pop());
                }

                if (!isFound) {
                    errors += "Error: Closing tag " + tag + " has no matching opening tag.\n";
                }
            }
        }
        else {
            tagStack->Push(tag);
        }
    }

    while (tagStack->Count > 0) {
        errors += "Error: Opening tag " + tagStack->Pop() + " has no closing tag.\n";
        isValid = false;
    }

    err = errors;
    return isValid;
}
