#include "HumanGL.h"

int	main()
{
	t_env		e;

	if (init_glfw(&e) == -1 || init_glad() == -1)
		return (-1);

	std::cout << glGetString(GL_VERSION) << std::endl;

	glEnable(GL_DEPTH_TEST);
//	Shader		liShad("./shader/light/v.glsl", "./shader/light/f.glsl");
	Shader		objShad("./shader/object/v.glsl", "./shader/object/f.glsl");
	//static float		vertices[] = {-0.5f, -0.5f, -5.0f,
	//											-0.5f, 0.5f, -5.0f,
	//											0.5f, 0.5f, -5.0f,
	//											0.5f, 0.5f, -5.0f,
	//											0.5f, -0.5f, -5.0f,
	//											-0.5f, -0.5f, -5.0f 
	//						};
	float vertices[] = {
		    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  0.0f, -1.0f,
		     0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f,  0.0f, -1.0f, 
		     0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  0.0f, -1.0f, 
		     0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 0.0f,  0.0f, -1.0f, 
		    -0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,  0.0f, -1.0f, 
		    -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  0.0f, -1.0f, 
		
		    -0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f,  0.0f, 1.0f,
		     0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 0.0f,  0.0f, 1.0f,
		     0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		     0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		    -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		    -0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f,  0.0f, 1.0f,
		
		    -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
		    -0.5f,  0.5f, -0.5f, 0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
		    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
		    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
		    -0.5f, -0.5f,  0.5f, 0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
		    -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, -1.0f,  0.0f,  0.0f,
		
		     0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
		     0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
		     0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
		     0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
		     0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
		     0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f,  0.0f,  0.0f,
		
		    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
		     0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
		     0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
		     0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
		    -0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
		    -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, -1.0f,  0.0f,
		
		    -0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
		     0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
		     0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
		     0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
		    -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f,  1.0f,  0.0f,
		    -0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 0.0f,  1.0f,  0.0f
		};


	GLuint	vao, vbo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
	
	glBindVertexArray(0);


//	GLuint	liVao;
//	glGenVertexArrays(1, &liVao);
//	glBindVertexArray(liVao);
//	
//	glBindBuffer(GL_ARRAY_BUFFER, vbo);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *)0);
//	glEnableVertexAttribArray(0);
//	
//	glBindVertexArray(0);




//	glm::vec3	liCol;
//	glm::vec3	liPos;
//	glm::mat4	liModel;
//
//	
//	glm::vec3	objPos(0.0f, 0.0f, 0.0f);
//	glm::mat4	objModel;
//	glm::mat3	objNormalMatrix = glm::transpose(glm::inverse(glm::mat3(objModel)));
//	objShad.use();
//	objShad.setUMat4("model", objModel);
//	objShad.setUMat3("normalMatrix", objNormalMatrix);

	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	float			t = glfwGetTime();
	Vec3			col; 
	Mat4			proj = Mat4("Perspective Projection", M_PI / 4 , (float)WINX / (float)WINY, -0.1f, -100.0f);
	Mat4			view;
	Mat4			model;
	Mat4			sc = Mat4("Scale", Vec3(1.0f, 2.0f, 1.0f));
	Mat4			rot;
	Mat4			trans = Mat4("Translation", Vec3(0.5f, 0.0f, 0.0f));
	Vec3			n = Vec3(0.0f,1.0f,0.0f);

	objShad.use();
	while(!glfwWindowShouldClose(e.w)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		t = glfwGetTime();	
		col[0] = abs(cos(t));
		col[2] =  abs(sin(t));
		objShad.setVec3("col", col);
		proj = Mat4("Perspective Projection", e.cam.getFov() * 2 * M_PI / 360 , (float)WINX / (float)WINY, -0.1f, -100.0f);
		objShad.setMat4("proj", proj);
		view = e.cam.setView();
		objShad.setMat4("view", view);



		rot.rotation(float(t), n);
		model = trans * rot * sc;
		objShad.setMat4("model", model);

	
	//	liCol = glm::vec3(abs(vt.x), vt.x + vt.y, abs(vt.y));
	//	liPos = glm::vec3(vt.y * 3.0f, 1.0f, vt.x * 3.0f);
	//	liModel = glm::mat4();
	//	liModel = glm::translate(liModel, liPos);
	//	liModel = glm::rotate(liModel, glm::radians(t * 42), glm::vec3(0.0f, 0.0f, 1.0f));
	//	liModel = glm::scale(liModel, glm::vec3(0.2f));
	//	liShad.use();
	//	liShad.setUVec3("Col", liCol);
	//	liShad.setUMat4("projViewModel", e.cam.setProjViewModel(liModel));
	//	glBindVertexArray(liVao);
	//	glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
	//	glBindVertexArray(0);
	//	
	//	objShad.use();
	//	objShad.setUVec3("lightCol", liCol);
	//	objShad.setUVec3("lightPos", liPos);
	//	objShad.setUVec3("viewPos", e.cam.sendViewPos());
	//	objShad.setUMat4("projViewModel", e.cam.setProjViewModel(objModel));
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
		glBindVertexArray(0);
		
		glfwSwapBuffers(e.w);
		glfwPollEvents();

	}


	//glDeleteVertexArrays(1, &liVao);
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	//glDeleteTextures(1, &tex);
	glfwTerminate();
	return 0;
}
