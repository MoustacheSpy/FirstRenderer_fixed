#include "stdafx.h"
#include "GLTextures.h"

GLTexture::GLTexture(const char* filePath,GLenum target,GLenum param,GLenum filtering,GLenum SOILLoadtype,GLenum GLloadType)
{
	printf("Loading texture");
    if(SOILLoadtype == SOIL_LOAD_RGBA||GLloadType==GL_RGBA)
    {
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    }
    glGenTextures(1, &id);
    glBindTexture(target, id); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object
	printf(".");
    // Set the texture wrapping parameters
    if(target==GL_TEXTURE_2D)
    {
        glTexParameteri(target, GL_TEXTURE_WRAP_S, param);
        glTexParameteri(target, GL_TEXTURE_WRAP_T, param);
    }
    // Set texture filtering parameters
    glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // Load image, create texture and generate mipmaps
	printf(".");
    unsigned char* image = SOIL_load_image(filePath, &width, &height, 0, SOILLoadtype);
    glTexImage2D(target, 0, GLloadType, width, height, 0, GLloadType, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(target);
    SOIL_free_image_data(image);
    glBindTexture(target, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
    if(SOILLoadtype == SOIL_LOAD_RGBA||GLloadType==GL_RGBA)
    {
        glDisable(GL_BLEND);
    }
	printf("done\n");
}

int GLTexture::use(GLenum Channel){
    glActiveTexture(Channel);	// Activate the texture unit first before binding texture
    glBindTexture(GL_TEXTURE_2D, id);
	return 1;
}
