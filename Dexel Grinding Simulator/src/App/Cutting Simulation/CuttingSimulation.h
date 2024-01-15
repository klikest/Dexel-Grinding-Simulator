#pragma once
#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include<glm\gtc\type_ptr.hpp>
#include<imgui/imgui.h>
#include<imgui/imgui_impl_glfw.h>
#include<imgui/imgui_impl_opengl3.h>

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

