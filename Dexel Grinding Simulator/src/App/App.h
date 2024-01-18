#pragma once
#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<imgui/imgui.h>
#include<imgui/imgui_impl_glfw.h>
#include<imgui/imgui_impl_opengl3.h>
#include "Cutting Simulation/CuttingSimulation.h"

class App
{
public:

	CuttingSimulation* ptrCuttingSimulationApp;

	void InitApp();
	void Run();
	void Close();
};

