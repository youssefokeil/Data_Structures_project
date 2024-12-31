#pragma once
#include <string>
#include <vector>
//#include <msclr/marshal_cppstd.h>  // For marshaling

using namespace System::Collections::Generic;

using namespace System;

public ref class BeautifyXMLCLI
{
public:
    // Method to beautify the XML file
    static void Beautify(String^ inputFilePath, String^ outputFilePath);

private:
    // Helper methods
    static String^ Trim(String^ str);
    static void SplitXML(String^ xml, List<String^>^% tokens);
    // Declare RepeatIndent method
    String^ RepeatIndent(int indentLevel);
};
