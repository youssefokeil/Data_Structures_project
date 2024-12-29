#pragma managed
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]


int main(array<String^>^args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	GUIproject::MyForm form;
	Application::Run(% form);
	return 0;
}

#pragma unmanaged
#include <iostream>
#include "C:\\Users\\YAHIA\\Desktop\\beautify.h"