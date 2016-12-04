#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
uniform float factor;
out vec3 ourColor; // Output a color to the fragment shader
out vec4 pos; 
float rand(vec2 co){
  return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}
void main()
{
	pos = gl_Position = vec4(position.x -factor, position.y, position.z, 1.0);
	ourColor = color;
};