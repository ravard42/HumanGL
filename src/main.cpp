#include "HumanGL.h"

static void		init_vao_vbo(GLuint *vao, GLuint *vbo) {
//2 pairs de vao/vbo pour le carre et le cube respectivement
	glGenVertexArrays(2, vao);
	glGenBuffers(2, vbo);
	
//a) Square 
	glBindVertexArray(vao[0]);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, SQUARE_DATA_NB * sizeof(float), Square::data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

// b) Cube
	glBindVertexArray(vao[1]);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, CUBE_DATA_NB * sizeof(float), Cube::data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

	Square::vao_id = vao[0];
	Cube::vao_id = vao[1];
}


static void		set_env_square(t_env *e) {
	e->s = new Square[ENV_SQUARE_NB];

	e->s[0].setAttr("ground", Vec3("darkgreen"), Vec3(0.0), 0.0, Vec3(0), Vec3(0), Vec3(50), 0.0, Vec3(0));

	std::cout << e->s[0] << std::endl;
}

static void		set_env_cube(t_env *e) {
	e->c = new Cube[ENV_CUBE_NB];

	
	e->c[0].setAttr("Cube1", Vec3(1.0), Vec3(0.0, 7.0, -40.0), 0.0, Vec3(0), Vec3(0), Vec3(0.4, 1.0, 0.1), M_PI / 4, Vec3("z"));
	e->c[1].setAttr("Cube2", Vec3(1.0),	Vec3(0.0, 7.0, -40.0), M_PI / 2, Vec3("z"), Vec3(0), Vec3(0.4, 1.0, 0.1), M_PI / 4, Vec3("z"));
	e->c[2].setAttr("Cube3", Vec3(1.0), Vec3(0.0, 7.0, -40.0), M_PI / 4, Vec3("z"), Vec3(0), Vec3(0.4, 1.0, 0.099), M_PI / 4, Vec3("z"));
	e->c[3].setAttr("Cube4", Vec3(1.0), Vec3(0.0, 7.0, -40.0), -M_PI / 4, Vec3("z"), Vec3(0), Vec3(0.4, 1.0, 0.099), M_PI / 4, Vec3("z"));
	//e->c[4].setAttr("ref", Vec3(0.3), Vec3(0.0, -0.21, -1), 0.0, Vec3("z"), Vec3(0), Vec3(1, 1, 1), 0, Vec3("z"));
	e->c[4].setAttr("ref", Vec3(0.3), Vec3(0.0, 0.5, -1), 0.0, Vec3("z"), Vec3(0), Vec3(1), 0, Vec3("z"));
	e->c[5].setAttr("ref2", Vec3(0.3), Vec3(0.0, 0.5, -1), 0.0, Vec3("z"), Vec3(0), Vec3(1), 0, Vec3("z"));

}

void			draw_all(t_env *e) {
		Mat4	proj = Mat4("Perspective Projection", e->cam.getFov() * 2 * M_PI / 360 , (float)WINX / (float)WINY, -0.1f, -100.0f);
		Mat4	view = (e->h.get_p_keyEvent() & 1) ? e->h.setView() : e->cam.setView();
		
		e->shad.setMat4("proj", proj);
		e->shad.setMat4("view", view);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
		for (int i=0; i < ENV_SQUARE_NB; ++i)
			e->s[i].draw(Mat4());
		for (int i=0; i < ENV_CUBE_NB; ++i)
			e->c[i].draw(Mat4());
		e->h.draw();

		glfwSwapBuffers(e->w);
}

int	main()
{
	GLFWwindow	*w;
	if (!(w = init_OpenGL()))
		return (-1);
	t_env		e = {w, Camera(), Shader("./shader/v.glsl", "./shader/f.glsl"), Human("ravard"), NULL, NULL};
	glfwSetWindowUserPointer(e.w, &e);
	set_callback(&e);

	Square::shad = &e.shad;
	Cube::shad = &e.shad;
	e.shad.use();
	
	GLuint	vao[2], vbo[2];
	init_vao_vbo(vao, vbo);
	
	set_env_square(&e);
	set_env_cube(&e);

	e.h.printTree();

	float		t[2] = {0.0};
	while(!glfwWindowShouldClose(e.w)) {
		if ((t[1] = glfwGetTime() - t[0]) > 1 / 60.0) {
		draw_all(&e);
		glfwPollEvents();
		t[0] = glfwGetTime();
		}
	}
	delete [] e.s;
	delete [] e.c;
	glDeleteBuffers(2, vbo);
	glDeleteVertexArrays(2, vao);
	glfwTerminate();
	return 0;
}
