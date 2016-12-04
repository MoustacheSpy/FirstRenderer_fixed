#pragma once
#include "stdafx.h"

#include "glm/glm.hpp"
#include <vector>
#include "Shaders.h"
#include "assimp/types.h"
using namespace std;

struct Texture {
	GLuint id;
	string type;
	aiString path;  // We store the path of the texture to compare with other textures
};
struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

class Mesh {
public:
	/*  Mesh Data  */
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Texture> textures;
	/*  Functions  */
	Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures);
	void Draw(Shader shader);
private:
	/*  Render data  */
	GLuint VAO, VBO, EBO;
	/*  Functions    */
	void setupMesh();
};