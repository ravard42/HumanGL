#include "HumanGL.h"


int	main()
{
	t_env		e;

	if (init_glfw(&e) == -1 || init_glad() == -1)
		return (-1);

	std::cout << glGetString(GL_VERSION) << std::endl;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);

	Shader		objShad("./shader/object/v.glsl", "./shader/object/f.glsl");

	GLuint	vao, vbo;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, MALA * sizeof(float), Cube::mala, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
	
	glBindVertexArray(0);

//	float			t = glfwGetTime();
	Mat4		proj, view;

	Cube	c1("Cube1", Vec3("cyan"), M_PI / 4, Vec3("z"), Vec3(0.4, 1.0, 0.1), 0.0, Vec3("z"), Vec3(0.0, 0.0, 0.0));
	Cube	c2("Cube2", Vec3("cyan"), M_PI / 4, Vec3("z"), Vec3(0.4, 1.0, 0.1), M_PI / 2, Vec3("z"), Vec3(0.0, 0.0, 0.0));
	Cube	c3("Cube3", Vec3("magenta"), M_PI / 4, Vec3("z"), Vec3(0.4, 1.0, 0.09), M_PI / 4, Vec3("z"), Vec3(0.0, 0.0, 0.0));
	Cube	c4("Cube4", Vec3("magenta"), M_PI / 4, Vec3("z"), Vec3(0.4, 1.0, 0.09), -M_PI / 4, Vec3("z"), Vec3(0.0, 0.0, 0.0));
	

	Human	ravard("ravard");
	e.h = &ravard;


	objShad.use();




	while(!glfwWindowShouldClose(e.w)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//	t = glfwGetTime();	
//		e.h->newPos();

		//<--PROJ-->
		proj = Mat4("Perspective Projection", e.cam.getFov() * 2 * M_PI / 360 , (float)WINX / (float)WINY, -0.1f, -100.0f);
		objShad.setMat4("proj", proj);
		
		//<--VIEW-->
		view = e.cam.setView();
		objShad.setMat4("view", view);
		
		//<--MODEL-->
		c1.draw(vao, objShad);
		c2.draw(vao, objShad);
		c3.draw(vao, objShad);
		c4.draw(vao, objShad);
		e.h->draw(vao, objShad);


		glfwSwapBuffers(e.w);
		glfwPollEvents();
	}



	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
	glfwTerminate();
	return 0;
}
