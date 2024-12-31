#include "compress.h"

void XMLCompressor::SplitXML(String^ xml, List<String^>^ tokens) {
    int pos = 0;
    while (pos < xml->Length) {
        if (xml[pos] == '<') {
            int end = xml->IndexOf('>', pos);
            if (end == -1) break;
            tokens->Add(xml->Substring(pos, end - pos + 1));
            pos = end + 1;
        }
        else {
            if (Char::IsWhiteSpace(xml[pos])) {
                pos++;
                continue;
            }
            int end = Math::Min(xml->IndexOf('<', pos), xml->IndexOf(' ', pos));
            if (end == -1) end = xml->Length;
            String^ text = xml->Substring(pos, end - pos);
            if (!String::IsNullOrWhiteSpace(text)) tokens->Add(text);
            pos = end;
        }
    }
}

String^ XMLCompressor::GetFileContentMinified(StreamReader^ reader) {
    String^ minifiedContent = "";
    while (!reader->EndOfStream) {
        String^ line = reader->ReadLine()->Trim();
        if (!String::IsNullOrWhiteSpace(line)) {
            minifiedContent += line;
        }
    }
    return minifiedContent;
}

void XMLCompressor::Compress(String^ inputFileName, String^ outputFileName) {
    StreamReader^ reader = gcnew StreamReader(inputFileName);
    StreamWriter^ writer = gcnew StreamWriter(outputFileName);

    String^ content = GetFileContentMinified(reader);
    Dictionary<String^, String^>^ symbolMap = gcnew Dictionary<String^, String^>();
    Dictionary<String^, int>^ frequencyMap = gcnew Dictionary<String^, int>();
    List<String^>^ tokens = gcnew List<String^>();

    SplitXML(content, tokens);

    int symbolCounter = 0;
    for each (String ^ token in tokens) {
        if (!frequencyMap->ContainsKey(token)) frequencyMap[token] = 0;
        frequencyMap[token]++;
    }

    for each (KeyValuePair<String^, int> kvp in frequencyMap) {
        if (kvp.Value > 5 && kvp.Key->Length > 3) {
            symbolMap[kvp.Key] = "$" + symbolCounter++;
        }
    }

    String^ compressedContent = "";
    for each (KeyValuePair<String^, String^> kvp in symbolMap) {
        compressedContent += kvp.Key + " " + kvp.Value + " ";
    }
    compressedContent += "End_Symbols_mapping ";

    for each (String ^ token in tokens) {
        if (symbolMap->ContainsKey(token)) {
            compressedContent += symbolMap[token];
        }
        else {
            compressedContent += token;
        }
        compressedContent += " ";
    }

    writer->Write(compressedContent);
    writer->Close();
    reader->Close();
    Console::WriteLine("File compressed successfully.");
}

void XMLCompressor::Decompress(String^ inputFileName, String^ outputFileName) {
    StreamReader^ reader = gcnew StreamReader(inputFileName);
    StreamWriter^ writer = gcnew StreamWriter(outputFileName);

    String^ content = GetFileContentMinified(reader);
    Dictionary<String^, String^>^ symbolMap = gcnew Dictionary<String^, String^>();
    List<String^>^ tokens = gcnew List<String^>();

    SplitXML(content, tokens);

    int fileStartIndex = 0;
    for (int i = 0; i < tokens->Count; i += 2) {
        if (tokens[i] == "End_Symbols_mapping") {
            fileStartIndex = i + 1;
            break;
        }
        symbolMap[tokens[i + 1]] = tokens[i];
    }

    String^ decompressedContent = "";
    for (int i = fileStartIndex; i < tokens->Count; i++) {
        if (symbolMap->ContainsKey(tokens[i])) {
            decompressedContent += symbolMap[tokens[i]];
        }
        else {
            decompressedContent += tokens[i];
        }
        decompressedContent += " ";
    }

    writer->Write(decompressedContent);
    writer->Close();
    reader->Close();
    BeautifyXMLCLI::Beautify(outputFileName, outputFileName);
    Console::WriteLine("File decompressed successfully.");
}


