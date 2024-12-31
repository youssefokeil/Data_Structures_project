#pragma once
#include <string>
#include <vector>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Collections::Generic;

public ref class XMLWrapper
{
public:
    // Function to trim a System::String
    static System::String^ Trim(System::String^ str);

    // Function to split an XML string into tokens
    static void SplitXML(System::String^ xml, List<System::String^>^ tokens);

    // Function to beautify XML content
    static void BeautifyXML(System::String^ inputFile, System::String^ outputFile);


};
