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

	glfwMakeContextCurrent(SimulationWindow);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD initialize - failed" << std::endl;
	}
	else
	{
		std::cout << "GLAD initialize - done" << std::endl;
	}

	gui = new GUI;

	gui->SetCurretWindow(SimulationWindow);
	gui->Init();


}


void CuttingSimulation::Run()
{


	glViewport(0, 0, width, height);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	glfwSwapBuffers(SimulationWindow);




	while (!glfwWindowShouldClose(SimulationWindow))
	{
		glfwPollEvents();

		gui->Render();

		glfwSwapBuffers(SimulationWindow);
		

	}
}

void CuttingSimulation::Close()
{
	gui->Close();

	glfwDestroyWindow(SimulationWindow);
	glfwTerminate();
}