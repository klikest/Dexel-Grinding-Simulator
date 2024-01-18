#pragma once
#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include "GUI/GUI.h"

#include<glm\gtc\type_ptr.hpp>


class CuttingSimulation
{
public:
	GLFWwindow* SimulationWindow;

	int width;
	int height;
	std::string title;

	GUI* gui;


	void CreateSimWindow(int width_, int height_, std::string title_);
	void Run();
	void Close();
};

