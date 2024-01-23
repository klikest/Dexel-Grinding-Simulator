#include "RenderScene.h"

RenderScene::RenderScene()
{
}

void RenderScene::Init(GLFWwindow* simWindow)
{
	window = simWindow;


	GLfloat vertices_[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
	};
	vertices = new GLfloat[9];
	vertices = vertices_;



	//shaderProgram = Shader();
	shaderProgram.createShaderProgram(
		(char*)"src/App/Cutting Simulation/Render scene/Shaders/default.vert",
		(char*)"src/App/Cutting Simulation/Render scene/Shaders/default.frag");

	VAO1 = VAO();
	VAO1.Bind();

	VBO1 = VBO();
	VBO1.Init(vertices, sizeof(GLfloat)*9);


	VAO1.LinkVBO(VBO1, 0);
	VAO1.Unbind();
	VBO1.Unbind();



}

void RenderScene::Render()
{
	shaderProgram.Activate();
	VAO1.Bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);

}

void RenderScene::Close()
{
	VAO1.Delete();
	VBO1.Delete();
	shaderProgram.Delete();
}