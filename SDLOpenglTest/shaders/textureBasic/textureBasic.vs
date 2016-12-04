#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texCoord;
uniform float factor;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
out vec3 ourColor;
out vec2 TexCoord;
out vec4 pos;
void main()
{
    pos=gl_Position =projection * view * model * vec4(position.x-factor,position.yz, 1.0f) ;
    ourColor = color;
    TexCoord = vec2(texCoord.x, 1.0f - texCoord.y);
}