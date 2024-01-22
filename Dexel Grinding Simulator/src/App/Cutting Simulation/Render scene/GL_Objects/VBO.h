#pragma once
#include <vector>
#include<glad/glad.h>

class VBO
{
public:
	VBO();
	void Init(GLfloat* vertices, GLsizeiptr size);
	void Init(std::vector<GLfloat> vertices, GLsizeiptr size);
	void UpdateData(std::vector<GLfloat> vertices, GLsizeiptr size);
	void Bind();
	void Unbind();
	void Delete();
	GLuint ID;
};

