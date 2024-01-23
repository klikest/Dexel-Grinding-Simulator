#pragma once
#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>


class Shader
{
public:
	void createShaderProgram(char* vert, char* frag);
	Shader();
	void Activate();
	void Delete();

	GLuint ID;
};

