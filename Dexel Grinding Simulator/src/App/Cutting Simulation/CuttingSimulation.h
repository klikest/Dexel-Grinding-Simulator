#pragma once
#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include "GUI/GUI.h"
#include "Render scene/RenderScene.h"
#include "Render scene/Primitives/Line.h"

#include<glm\gtc\type_ptr.hpp>


class CuttingSimulation
{
public:
	GLFWwindow* SimulationWindow;

	int width;
	int height;
	std::string title;

	GUI* gui;
	RenderScene* scene;

	Line* line;
	Line* line2;

	CuttingSimulation();

	void CreateSimWindow(int width_, int height_, std::string title_);
	void Run();
	void Close();
};

