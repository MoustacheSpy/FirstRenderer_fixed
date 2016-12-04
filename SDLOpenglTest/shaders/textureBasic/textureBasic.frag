
#version 330 core
in vec3 ourColor;
in vec2 TexCoord;
in vec4 pos;
out vec4 color;

uniform sampler2D ourTexture;
uniform sampler2D mixTexture;
void main()
{
	vec3 tempCol;
	
	tempCol.xyz = ourColor.xyz +pos.xyz;
	//*vec4(tempCol,1.0);
	color = (mix( texture(ourTexture, TexCoord).rgba, texture(mixTexture, TexCoord).rgba, vec4(texture(mixTexture, TexCoord)).a * 0.2));

}