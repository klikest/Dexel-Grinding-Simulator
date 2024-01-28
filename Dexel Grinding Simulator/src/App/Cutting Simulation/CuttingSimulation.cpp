#include "CuttingSimulation.h"


using namespace glm;

CuttingSimulation::CuttingSimulation()
{
}


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


	camera = new Camera();
	camera->Init(SimulationWindow, glm::vec3(0, 0, 0), 0, 0);


	gui = new GUI;

	gui->SetCurretWindow(SimulationWindow);
	gui->Init();

	scene = new RenderScene;
	scene->Init(SimulationWindow);



	line = new Line(glm::vec3(-0.5, 0.5, 0), glm::vec3(0.5, -0.5, 0), glm::vec4(1, 1, 0, 1));
	line2 = new Line(glm::vec3(-0.5, -0.5, 0), glm::vec3(0.5, 0.5, 0), glm::vec4(1, 0, 1, 1));
}


void CuttingSimulation::Run()
{


	while (glfwGetKey(SimulationWindow, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(SimulationWindow) == 0)
	{
		glfwPollEvents();

		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		camera->MoveCamera(SimulationWindow, 0.1);
		camera->UpdateMatrix(line->shaderProgram->ID);


		line->Draw();
		line2->Draw();


		//scene->Render();
		//gui->Render();



		glfwSwapBuffers(SimulationWindow);
		

	}
}

void CuttingSimulation::Close()
{
	gui->Close();
	scene->Close();

	glfwDestroyWindow(SimulationWindow);
	glfwTerminate();
}