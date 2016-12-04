#ifndef GLTEXTURES_H_INCLUDED
#define GLTEXTURES_H_INCLUDED
#include <string>
#include <GL/glew.h>
#include <SOIL.h>
#include <assimp/Importer.hpp>
class GLTexture
{
public:
    GLuint id;
	std::string type;
    aiString path;  // We store the path of the texture to compare with other textures
	int width, height;
	GLTexture(const char* filePath,GLenum target,GLenum param,GLenum filtering,GLenum SOILLoadtype,GLenum GLloadType);
    int use(GLenum channel);
};

#endif // GLTEXTURES_H_INCLUDED
