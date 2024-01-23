#pragma once
#include <glm\glm.hpp>
#include <glm\gtc/type_ptr.hpp>
#include <glm\gtc/matrix_transform.hpp>

#include "App/Cutting Simulation/Render scene/GL_Objects/Shader2.h"
#include "App/Cutting Simulation/Render scene/GL_Objects/VAO.h"
#include "App/Cutting Simulation/Render scene/GL_Objects/VBO.h"

using namespace glm;

class Line
{
public:
	
	Line(vec3 p1, vec3 p2, vec4 color);

	Line();

	void Draw();
	void UpdatePosition(vec3 p1, vec3 p2);
	void UpdateColor(vec4 color_);
	void Delete();

	vec3 p1;
	vec3 p2;
	vec4 color;
	GLuint color_loc;
	Shader* shaderProgram;
	VAO VAO1;
	VBO VBO1;

	GLuint color_loc2;
	Shader* shaderProgram2;
	VAO VAO2;
	VBO VBO2;
};

