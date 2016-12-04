#pragma once
#include <GL/glew.h>
class SceneBuffer {
public:
	GLuint texColorBuffer, quadVAO, quadVBO, rbo, depthTex;
	GLuint frameBuffer;
	SceneBuffer();
	int use();
	int displayColor();
	int displayDepth();
	int clear();
};