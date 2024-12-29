#include "BeautifyXML.h"
#include <msclr/marshal_cppstd.h> // For marshaling between System::String^ and std::string

using namespace System;
using namespace System::IO;

// Method to beautify the XML from input to output
void BeautifyXMLCLI::Beautify(String^ inputFilePath, String^ outputFilePath)
{
    try
    {
        // Create an instance of BeautifyXMLCLI to access instance methods
        BeautifyXMLCLI^ beautifier = gcnew BeautifyXMLCLI();

        // Read the input file content into a single string
        StreamReader^ reader = gcnew StreamReader(inputFilePath);
        String^ xmlContent = reader->ReadToEnd();
        reader->Close();

        List<String^>^ tokens = gcnew List<String^>();
        SplitXML(xmlContent, tokens); // Split XML into tags and content

        int indentLevel = 0;
        String^ indent = "  "; // 2 spaces for indentation

        // Create the output file to write the beautified XML
        StreamWriter^ writer = gcnew StreamWriter(outputFilePath);

        for each (String ^ token in tokens)
        {
            // Skip empty tokens
            if (token->Length == 0) continue;

            if (token[0] == L'<') // Use L to specify wide character literals
            {
                // Check for closing tags to reduce indent
                if (token[1] == L'/')
                {
                    indentLevel--;
                }

                // Write the tag with proper indentation
                writer->WriteLine(beautifier->RepeatIndent(indentLevel) + token); // Use the object to call RepeatIndent

                // If it's an opening tag (not self-closing), increase the indent
                if (token[1] != L'/' && !token->EndsWith(L"/>"))
                {
                    indentLevel++;
                }
            }
            else
            {
                // Write the text content with the current indentation
                writer->WriteLine(beautifier->RepeatIndent(indentLevel) + token); // Use the object to call RepeatIndent
            }
        }

        writer->Close();
        Console::WriteLine("Beautified XML saved to " + outputFilePath);
    }
    catch (Exception^ ex)
    {
        Console::WriteLine("Error: " + ex->Message);
    }
}

// Non-static helper function to repeat the indent string
String^ BeautifyXMLCLI::RepeatIndent(int indentLevel)
{
    String^ result = "";
    for (int i = 0; i < indentLevel; i++)
    {
        result += "  "; // Add two spaces for each indent level
    }
    return result;
}

// Method to trim leading and trailing spaces from a string
String^ BeautifyXMLCLI::Trim(String^ str)
{
    return str->Trim(); // Uses built-in .NET method to trim whitespace
}

// Method to split XML into tags and text content
void BeautifyXMLCLI::SplitXML(String^ xml, List<String^>^% tokens)
{
    int pos = 0;
    while (pos < xml->Length)
    {
        if (xml[pos] == L'<') // Use L prefix for wide character literals
        {
            // Find the end of the tag
            int end = xml->IndexOf(L'>', pos); // Use L'>' for wide character
            if (end == -1) break;
            tokens->Add(xml->Substring(pos, end - pos + 1));
            pos = end + 1;
        }
        else
        {
            // Extract text between tags
            int end = xml->IndexOf(L'<', pos); // Use L'<' for wide character
            if (end == -1) end = xml->Length;
            String^ text = Trim(xml->Substring(pos, end - pos));
            if (!String::IsNullOrEmpty(text)) tokens->Add(text);
            pos = end;
        }
    }
}
