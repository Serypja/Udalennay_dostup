#include "MyForm.h"
#include<iostream>
#include<windows.h>
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void main(array<String^>^ args) { // ^ - �������������� �������� ������
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Less::MyForm form;
	Application::Run(% form);
}