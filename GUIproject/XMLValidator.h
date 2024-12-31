#pragma once

#include <string>
using namespace System;
using namespace System::Collections::Generic;

public ref class XMLValidator {
public:
    // Reads an XML file and returns its contents as a string
    static String^ ReadXML(String^ filename);

    static bool IsXMLValid(String^ filename, String^ xmlAsString, bool isStringXml, String^% err);
};


