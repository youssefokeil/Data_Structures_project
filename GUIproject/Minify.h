#pragma once

#include <string>
#include <iostream>

namespace MinifyLib {
    public ref class Minifier {
    public:
       static void Minify(System::IO::StreamReader^ inputStream, System::String^ outputFileName);
    };
}
