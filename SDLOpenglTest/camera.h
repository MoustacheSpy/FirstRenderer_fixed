#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED
#include "stdafx.h"
#include <GL/glew.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "SDL.h"
//#include "globalDefinitions.h"
#include <stdio.h>
#include <iostream>
#define CAM_PERSP 0x000A
#define CAM_ORTHO 0x000B
#define HEIGHT 600
#define WIDTH 600
class Camera
{
private:
    bool firstmouse=true;
public:
    glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f);
    float cameraSpeed=2;
    double frameTime=0;
    float pitch=0,yaw=266,roll=0;
    GLfloat sensitivity = 0.15f;
    GLfloat fov=45;
    int processKeyboard();
    int processMouse_FPS();
	glm::mat4 getViewMat();
	glm::mat4 getProjMat(int cammode);
};
#endif // CAMERA_H_INCLUDED
