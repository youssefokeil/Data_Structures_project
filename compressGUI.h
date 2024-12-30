#pragma once

using namespace System;
using namespace System::Collections::Generic;


namespace CompressionCLI {
    public ref class CompressionManager {
    public:
        // Compress the input XML file and save it to the output file.
        static void Compress(String^ inputFilePath, String^ outputFilePath);

        // Decompress the compressed XML file and save it to the output file.
        static void Decompress(String^ inputFilePath, String^ outputFilePath);

    private:
        // Helper functions.
        static String^ GetFileContentMinified(String^ inputFilePath);
        static void SplitXML(String^ xml, List<String^>^% tokens);
        static String^ GenerateSymbol(int index);
    };
}
