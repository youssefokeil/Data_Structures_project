#include "minify.h"
#include <fstream>
#include <vector>
#include <msclr\auto_gcroot.h>

using namespace System;
using namespace System::IO;

namespace MinifyLib {
    void Minifier::Minify(StreamReader^ inputStream, String^ outputFileName) {
        // Convert managed System::String^ to native std::wstring
        pin_ptr<const wchar_t> wchOutputFileName = PtrToStringChars(outputFileName);
        std::wofstream ofile(wchOutputFileName);

        if (!ofile.is_open()) {
            Console::Error->WriteLine("Failed to open the output file: {0}", outputFileName);
            return;
        }

        std::vector<std::wstring> lines;

        while (!inputStream->EndOfStream) {
            String^ managedLine = inputStream->ReadLine();
            pin_ptr<const wchar_t> wchManagedLine = PtrToStringChars(managedLine);
            std::wstring line(wchManagedLine);

            // Minify the line (remove spaces and handle '<')
            for (size_t i = 0; i < line.size(); ++i) {
                if (line[i] == L' ') {
                    line.erase(line.begin() + i);
                    --i;
                }
                else if (line[i] == L'<') {
                    break;
                }
            }
            lines.push_back(line);
        }

        // Write the result to the output file
        for (const auto& line : lines) {
            ofile << line;
        }

        ofile.close();
    }
}
