#version 330 core
struct Material {
    sampler2D texture_diffuse1;
	sampler2D texture_diffuse2;
	sampler2D texture_diffuse3;
    sampler2D texture_specular1;
	sampler2D texture_specular2;
	sampler2D texture_specular3;
	int specCount;
	int diffCount;
	sampler2D refract;
	float reflection;
    float shininess;
}; 
struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
	float constant;
    float linear;
    float quadratic;
};



out vec4 color;
in vec2 TexCoords;
in vec3 Normal;  
in vec3 FragPos;  
in vec3 textureDir;
uniform vec3 cameraPos;
uniform vec3 viewPos;
uniform Light light;
uniform vec3 lightColor;
uniform Material material;

uniform samplerCube skybox;
void main()
{	float diff;
	vec3 lightDir;
	 vec3 norm;
	vec3 diffuse;
	// sample texture
	
   // use default color
	//Attenution
	float distance    = length(light.position - FragPos);
	float attenuation = 1.0f / (light.constant + light.linear * distance + light.quadratic * (distance * distance));    
	// Ambient
    vec3 ambient = light.ambient * vec3(texture(material.texture_diffuse1, TexCoords));
  	
    // Diffuse 
    norm = normalize(Normal);
    lightDir = normalize(light.position - FragPos);
    diff = max(dot(norm, lightDir), 0.0);
    diffuse = light.diffuse * diff * vec3(texture(material.texture_diffuse1, TexCoords)); 
    if(material.diffCount+1>1)
	diffuse+=light.diffuse * diff * vec3(texture(material.texture_diffuse2, TexCoords));
	if(material.diffCount+1>2)
	diffuse+=light.diffuse * diff * vec3(texture(material.texture_diffuse3, TexCoords));
    // Specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * vec3(texture(material.texture_specular1, TexCoords))); 
	if(material.specCount>1)
		specular+= light.specular * (spec * vec3(texture(material.texture_specular2, TexCoords)));
	if(material.specCount>2)
		specular+= light.specular * (spec * vec3(texture(material.texture_specular3, TexCoords)));
		//reflection
	vec3 I = normalize(FragPos - cameraPos);
    vec3 R = reflect(I, normalize(Normal));
	
    vec3 Rf = refract(I, normalize(Normal), 1.00 / 1.52);
	vec4 refraction = texture(skybox, Rf)*vec4(texture(material.texture_specular1, TexCoords)) * attenuation;
	int i=0;
	vec4 reflection = texture(skybox, R)*vec4(texture(material.texture_specular1, TexCoords));
	if(material.specCount>1)
		reflection +=vec4(texture(material.texture_specular2, TexCoords));
	if(material.specCount>2)
		reflection += vec4(texture(material.texture_specular3, TexCoords));
		
	
	vec3 result = ambient*attenuation + diffuse*attenuation + specular*attenuation;
	color = vec4(result,1.0)*reflection;
	
	
}