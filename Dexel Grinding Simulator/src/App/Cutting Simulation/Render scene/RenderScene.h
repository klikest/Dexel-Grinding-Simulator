#pragma once

#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include "GL_Objects/VAO.h"
#include "GL_Objects/VBO.h"
#include "GL_Objects/EBO.h"
#include "GL_Objects/Shader.h"
#include "Camera/Camera.h"

class RenderScene
{
public:
	RenderScene();
	void Init(GLFWwindow* simWindow);
	void Render();
	void Close();

	GLFWwindow* window;

	GLfloat* vertices;
	//GLuint* indices;
	Shader shaderProgram;
	VAO VAO1;
	VBO VBO1;
	VBO VBO2;
	//EBO EBO1;
};

