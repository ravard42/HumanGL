#version 410 core

layout (location = 0) in vec3	position;
uniform 	mat4 	proj;
uniform 	mat4 	view;
uniform 	mat4 	model;

//uniform	mat3	normalMatrix;
//out		vec3	Normal;
//out		vec3	FragPos;

void	main()
{
	gl_Position = proj * view * model * vec4(position, 1.0);
//	gl_Position = proj * model * vec4(position, 1.0);
//	gl_Position = vec4(position, 1.0);

//	Normal = normalMatrix * normal;
//	FragPos = vec3(model * vec4(position, 1.0)); 
}

