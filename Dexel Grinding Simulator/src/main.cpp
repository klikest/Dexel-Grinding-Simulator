#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include "App\App.h"



int main()
{
	App* ptrApp = new App;

	ptrApp->InitApp();
	ptrApp->Run();
	ptrApp->Close();

	system("pause");

	return 0;
}