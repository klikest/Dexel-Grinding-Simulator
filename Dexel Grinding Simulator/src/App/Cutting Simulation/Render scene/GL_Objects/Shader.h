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
	void Init(char* vertexFile,char* fragmentFile);
	void Activate();
	void Delete();

	GLuint ID;
};

