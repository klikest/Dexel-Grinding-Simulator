#pragma once
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <glm\glm.hpp>
#include <glm\gtc/type_ptr.hpp>
#include <glm\gtc/matrix_transform.hpp>


class Camera
{
public:
    glm::vec3 cameraPos;
    glm::vec3 cameraFront;
    glm::vec3 cameraUp;
    float cam_speed = 20;

    GLfloat yaw = -90.0f;	
    GLfloat pitch = 0.0f;
    GLfloat lastX;
    GLfloat lastY;
    int width, height;
    GLfloat fov = 45.0f;
    bool firstMouse = true;

    glm::mat4 pMat;
    glm::mat4 vMat;

    GLuint vLoc = 0, projLoc = 0;

    Camera();

    void Init(GLFWwindow* window, glm::vec3 campos_, float yaw_, float pitch);
    void MoveCamera(GLFWwindow* window, GLfloat deltaTime);
    void UpdateMatrix(GLuint shader);

};

