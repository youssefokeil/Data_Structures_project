#include "compress.h"


using namespace System;
using namespace System::IO;
using namespace CompressionCLI;

// Helper method to generate a unique symbol based on an index.
String^ CompressionManager::GenerateSymbol(int index) {
    array<wchar_t>^ symbols = gcnew array<wchar_t>{
        L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8', L'9',
            L'A', L'B', L'C', L'D', L'E', L'F', L'G', L'H', L'I', L'J', L'K', L'L', L'M', L'N', L'O', L'P', L'Q', L'R', L'S', L'T', L'U', L'V', L'W', L'X', L'Y', L'Z',
            L'a', L'b', L'c', L'd', L'e', L'f', L'g', L'h', L'i', L'j', L'k', L'l', L'm', L'n', L'o', L'p', L'q', L'r', L's', L't', L'u', L'v', L'w', L'x', L'y', L'z'
    };

    String^ result = "";
    do {
        result = symbols[index % symbols->Length] + result;
        index /= symbols->Length;
    } while (index > 0);

    return "$" + result;
}

// Helper method to get minified XML content from a file.
String^ CompressionManager::GetFileContentMinified(String^ inputFilePath) {
    String^ content = File::ReadAllText(inputFilePath);
    return content->Replace("\r", "")->Replace("\n", "")->Trim();
}

// Helper method to split XML into tags and content.
void CompressionManager::SplitXML(String^ xml, List<String^>^% tokens) {
    int pos = 0;
    while (pos < xml->Length) {
        if (xml[pos] == '<') {
            int end = xml->IndexOf(L'>', pos);
            if (end == -1) break;
            tokens->Add(xml->Substring(pos, end - pos + 1));
            pos = end + 1;
        }
        else {
            int end = xml->IndexOf(L'<', pos);
            if (end == -1) end = xml->Length;
            String^ text = xml->Substring(pos, end - pos)->Trim();
            if (!String::IsNullOrEmpty(text)) tokens->Add(text);
            pos = end;
        }
    }
}

// Method to compress an XML file.
void CompressionManager::Compress(String^ inputFilePath, String^ outputFilePath) {
    String^ xmlContent = GetFileContentMinified(inputFilePath);
    List<String^>^ tokens = gcnew List<String^>();
    SplitXML(xmlContent, tokens);

    Dictionary<String^, int>^ frequency = gcnew Dictionary<String^, int>();
    Dictionary<String^, String^>^ symbolMap = gcnew Dictionary<String^, String^>();

    // Calculate token frequencies.
    for each (String ^ token in tokens) {
        if (frequency->ContainsKey(token)) {
            frequency[token]++;
        }
        else {
            frequency[token] = 1;
        }
    }

    // Generate symbols for frequently occurring tokens.
    int index = 0;
    for each (KeyValuePair<String^, int> pair in frequency) {
        if (pair.Value > 5 && pair.Key->Length > 3) {
            symbolMap[pair.Key] = GenerateSymbol(index++);
        }
    }

    // Build the compressed file content.
    String^ compressedContent = "";
    for each (KeyValuePair<String^, String^> pair in symbolMap) {
        compressedContent += pair.Key + " " + pair.Value + " ";
    }
    compressedContent += "End_Symbols_mapping ";

    for each (String ^ token in tokens) {
        compressedContent += symbolMap->ContainsKey(token) ? symbolMap[token] : token;
    }

    File::WriteAllText(outputFilePath, compressedContent);
}

// Method to decompress a compressed XML file.
void CompressionManager::Decompress(String^ inputFilePath, String^ outputFilePath) {
    String^ compressedContent = GetFileContentMinified(inputFilePath);
    List<String^>^ tokens = gcnew List<String^>();
    SplitXML(compressedContent, tokens);

    Dictionary<String^, String^>^ symbolMap = gcnew Dictionary<String^, String^>();
    int fileStartIndex = -1;

    // Parse the symbol mappings.
    for (int i = 0; i < tokens->Count; i += 2) {
        if (i >= tokens->Count || String::IsNullOrEmpty(tokens[i])) {
            throw gcnew ArgumentException("Malformed input: unexpected or missing token.");
        }

        // Check for "End_Symbols_mapping"
        if (tokens[i] == "End_Symbols_mapping") {
            fileStartIndex = i + 1;
            break;
        }

        // Ensure a valid pair exists.
        if (i + 1 >= tokens->Count || String::IsNullOrEmpty(tokens[i + 1])) {
            throw gcnew ArgumentOutOfRangeException("Index out of range while parsing symbol mappings. Missing value for key: " + tokens[i]);
        }

        // Add to the symbol map
        symbolMap[tokens[i + 1]] = tokens[i];
    }

    if (fileStartIndex == -1) {
        throw gcnew ArgumentException("Malformed input: 'End_Symbols_mapping' not found.");
    }

    // Build the decompressed content.
    String^ decompressedContent = "";
    for (int i = fileStartIndex; i < tokens->Count; i++) {
        decompressedContent += symbolMap->ContainsKey(tokens[i]) ? symbolMap[tokens[i]] : tokens[i];
    }

    File::WriteAllText(outputFilePath, decompressedContent);
}
