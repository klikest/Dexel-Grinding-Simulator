#pragma once

#include<glad/glad.h>

class EBO
{
public:

	EBO();
	void Init(GLuint* indices, GLsizeiptr size);
	void Bind();
	void Unbind();
	void Delete();

	GLuint ID;
};

