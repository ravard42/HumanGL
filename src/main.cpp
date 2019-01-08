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
	
	Cube	 x("x", Vec3("red"), Vec3(0), 0.0, Vec3(0), Vec3(0), Vec3(50, 0.007, 0.007), 0.0, Vec3(0));
	Cube	 y("y", Vec3("green"), Vec3(0), 0.0, Vec3(0), Vec3(0), Vec3(0.007, 50, 0.007), 0.0, Vec3(0));
	Cube	 z("z", Vec3("blue"), Vec3(0), 0.0, Vec3(0), Vec3(0), Vec3(0.007, 0.007, 50), 0.0, Vec3(0));

	Cube	c1("Cube1", Vec3("cyan"), Vec3(0.0, 0.0, -2.0), 0.0, Vec3(0), Vec3(0), Vec3(0.4, 1.0, 0.1), M_PI / 4, Vec3("z"));
	Cube	c2("Cube2", Vec3("cyan"),	Vec3(0.0, 0.0, -2.0), M_PI / 2, Vec3("z"), Vec3(0), Vec3(0.4, 1.0, 0.1), M_PI / 4, Vec3("z"));
	Cube	c3("Cube3", Vec3("magenta"), Vec3(0.0, 0.0, -2.0), M_PI / 4, Vec3("z"), Vec3(0), Vec3(0.4, 1.0, 0.099), M_PI / 4, Vec3("z"));
	Cube	c4("Cube4", Vec3("magenta"), Vec3(0.0, 0.0, -2.0), -M_PI / 4, Vec3("z"), Vec3(0), Vec3(0.4, 1.0, 0.099), M_PI / 4, Vec3("z"));

	

	Human	ravard("ravard");
	e.h = &ravard;


	objShad.use();




	while(!glfwWindowShouldClose(e.w)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		
		//<--PROJ-->
		proj = Mat4("Perspective Projection", e.cam.getFov() * 2 * M_PI / 360 , (float)WINX / (float)WINY, -0.1f, -100.0f);
		objShad.setMat4("proj", proj);
		
		//<--VIEW-->
		view = (e.h->getKeyEvent() & (char)pow(2, 4)) ? e.h->setView() : e.cam.setView();
		objShad.setMat4("view", view);
		
		//<--MODEL-->
		x.draw(vao, objShad, Mat4());
		y.draw(vao, objShad, Mat4());
		z.draw(vao, objShad, Mat4());
		c1.draw(vao, objShad, Mat4());
		c2.draw(vao, objShad, Mat4());
		c3.draw(vao, objShad, Mat4());
		c4.draw(vao, objShad, Mat4());
		e.h->draw(vao, objShad);


		glfwSwapBuffers(e.w);
		glfwPollEvents();
		
		//usleep((float)1/3 * pow(10, 5));
	}



	glDeleteBuffers(1, &vbo);
	glDeleteVertexArrays(1, &vao);
	glfwTerminate();
	return 0;
}
