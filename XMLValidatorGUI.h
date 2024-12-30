#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <string>

using namespace System;

namespace XMLValidator {

    public ref class XMLValidator
    {
    public:
        // Function to read the content of an XML file
        static String^ ReadXML(String^ filename);

        // Function to validate if the XML is well-formed
        static bool IsXMLValid(String^ filename);
    };
}

