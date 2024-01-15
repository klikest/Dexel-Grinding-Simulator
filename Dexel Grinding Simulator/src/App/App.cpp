#include "App.h"
#include "Cutting Simulation/CuttingSimulation.h"


static void glfw_error_callback(int error, const char* description)
{
	fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}


void App::InitApp()
{
	glfwSetErrorCallback(glfw_error_callback);

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


}

void App::Run()
{
	CuttingSimulation* ptrCuttingSimulationApp = new CuttingSimulation;


	ptrCuttingSimulationApp->CreateSimWindow(400, 400, "Dexel Grinding Simulation");
	ptrCuttingSimulationApp->Run();
}
