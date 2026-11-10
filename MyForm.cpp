#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

// Точка входу програми
[STAThread]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	coursework::MyForm form;
	Application::Run(% form);
	return 0;
}