#version 330 core
out vec4 color;
in vec3 ourColor;
in vec4 pos;
vec3 tempCol;

void main()
{
	tempCol.x = ourColor.x + pos.x;
	tempCol.yz = ourColor.yz;
    color = vec4(tempCol, 1.0f);
};