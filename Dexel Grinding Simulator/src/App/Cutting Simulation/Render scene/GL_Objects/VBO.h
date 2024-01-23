#pragma once
#include <vector>
#include<glad/glad.h>
#include <glm\glm.hpp>

class VBO
{
public:
	VBO();
	void Init(GLfloat* vertices, GLsizeiptr size);
	void Init(std::vector<glm::vec3> vertices);
	void Init(std::vector<GLfloat> vertices, GLsizeiptr size);
	void UpdateData(std::vector<GLfloat> vertices, GLsizeiptr size);
	void Bind();
	void Unbind();
	void Delete();
	GLuint ID;
};

