#pragma once
#include "BeautifyXML.h"
#include <string>
#include <unordered_map>
#include <vector>

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

public ref class XMLCompressor {
public:
    // Compress an XML file
    static void Compress(String^ inputFileName, String^ outputFileName);

    // Decompress an XML file
    static void Decompress(String^ inputFileName, String^ outputFileName);

private:
    // Split XML content into tokens
    static void SplitXML(String^ xml, List<String^>^ tokens);

    // Minify the content of a file
    static String^ GetFileContentMinified(StreamReader^ reader);


};

