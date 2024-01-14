#pragma once
#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

class CuttingSimulation
{
	GLFWwindow* SimulationWindow;
	int width;
	int height;
	std::string title;

public:
	void CreateSimWindow(int width_, int height_, std::string title_);
	void Run();
	void Close();
};

