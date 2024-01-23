#pragma once
#include <glm\glm.hpp>
#include <glm\gtc/type_ptr.hpp>
#include <glm\gtc/matrix_transform.hpp>
#include <vector>

#include "App/Cutting Simulation/Render scene/GL_Objects/Shader.h"
#include "App/Cutting Simulation/Render scene/GL_Objects/VAO.h"
#include "App/Cutting Simulation/Render scene/GL_Objects/VBO.h"


class Lines
{
public:

	Lines(std::vector<glm::vec3> points, glm::vec4 color);

	void Draw();
	void UpdatePosition(std::vector<glm::vec3> points);
	void UpdateColor(glm::vec4 color_);
	void Delete();

	float weight;
	int size;

	std::vector<glm::vec3> points;
	glm::vec4 color;
	GLuint color_loc;
	Shader shaderProgram;
	VAO VAO1;
	VBO VBO1;
};
