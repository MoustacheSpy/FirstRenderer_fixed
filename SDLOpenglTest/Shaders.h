#ifndef SHADERS_H_INCLUDED
#define SHADERS_H_INCLUDED
#include "stdafx.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>// Include glew to get all the required OpenGL headers

class Shader
{
private:
	char Vertexpath[100];
	char Fragpath[100];
public:
    // The program ID
    GLuint Program;

    // Constructor reads and builds the shader
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    // Use the program
    void Use();
	void recompile();
};

#endif // SHADERS_H_INCLUDED
