#include "CuttingSimulation.h"


void CuttingSimulation::CreateSimWindow(int width_, int height_, std::string title_)
{
	width = width_;
	height = height_;
	title = title_;

	SimulationWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	if (SimulationWindow == NULL)
	{
		std::cout << "GLFW window create - failed" << std::endl;
		glfwTerminate();
	}
	else
	{
		std::cout << "GLFW window create - done" << std::endl;
	}
}



void CuttingSimulation::Run()
{

	glfwMakeContextCurrent(SimulationWindow);
	gladLoadGL();

	glViewport(0, 0, 800, 800);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(SimulationWindow);

	while (!glfwWindowShouldClose(SimulationWindow))
	{
		glfwPollEvents();
	}
}

void CuttingSimulation::Close()
{
	glfwDestroyWindow(SimulationWindow);
	glfwTerminate();
}