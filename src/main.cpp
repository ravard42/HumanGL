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


//	float			t = glfwGetTime();
	Mat4			proj = Mat4("Perspective Projection", M_PI / 4 , (float)WINX / (float)WINY, -0.1f, -100.0f);
	Mat4			view;
	Mat4			model;
	Vec3			col;
	Vec3			red(1.0f, 0.0f, 0.0f); 
	Vec3			green(0.0f, 1.0f, 0.0f); 
	Vec3			blue(0.0f, 0.0f, 1.0f); 
	Vec3			purple(1.0f, 0.0f, 1.0f); 

	Human	ravard("ravard");
	Limb	head("head", Vec3(0.17, 0.17, 0.17), Vec3(), 0.0f, Vec3(0, 0.32, 0.0), purple);
	Limb	lArm("left arm", Vec3(0.07, 0.5, 0.07), Vec3("z"),  -M_PI / 14, Vec3(-0.18f, 0.0f, 0.0f), blue);
	Limb	rArm("right arm", Vec3(0.07, 0.5, 0.07), Vec3("z"), M_PI / 14, Vec3(0.18f, 0.0f, 0.0f), blue);
	Limb	chest("chest", Vec3(0.23, 0.5, 0.21), Vec3(), 0.0f, Vec3("0"), green);
	Limb	lLeg("left leg", Vec3(0.09, 0.5, 0.09), Vec3(), 0.0f, Vec3(-0.07f, -0.5f, 0.0f), red);
	Limb	rLeg("right leg", Vec3(0.09, 0.5, 0.09), Vec3(), 0.0f, Vec3(0.07f, -0.5f, 0.0f), red);

	std::cout << ravard << std::endl;


	objShad.use();
	while(!glfwWindowShouldClose(e.w)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//	t = glfwGetTime();	

		
		proj = Mat4("Perspective Projection", e.cam.getFov() * 2 * M_PI / 360 , (float)WINX / (float)WINY, -0.1f, -100.0f);
		objShad.setMat4("proj", proj);
		view = e.cam.setView();
		objShad.setMat4("view", view);
		
		//HEAD
		model = Mat4("Translation", head.getTr()) * Mat4("Rotation", head.getRad(), head.getRot()) * Mat4("Scale", head.getSc());
		objShad.setMat4("model", model);
		col = head.getCol();
		objShad.setVec3("col", col);
	
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
		glBindVertexArray(0);
		
		//LEFT ARM
		model = Mat4("Translation", lArm.getTr()) * Mat4("Rotation", lArm.getRad(), lArm.getRot()) * Mat4("Scale", lArm.getSc());
		objShad.setMat4("model", model);
		col = lArm.getCol();
		objShad.setVec3("col", col);
	
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
		glBindVertexArray(0);
		

		//RIGHT ARM
		model = Mat4("Translation", rArm.getTr()) * Mat4("Rotation", rArm.getRad(), rArm.getRot()) * Mat4("Scale", rArm.getSc());
		objShad.setMat4("model", model);
		col = rArm.getCol();
		objShad.setVec3("col", col);
	
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
		glBindVertexArray(0);

		//CHEST
		model = Mat4("Translation", chest.getTr()) * Mat4("Rotation", chest.getRad(), chest.getRot()) * Mat4("Scale", chest.getSc());
		objShad.setMat4("model", model);
		col = chest.getCol();
		objShad.setVec3("col", col);
	
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
		glBindVertexArray(0);
		
		//LEFT LEG
		model = Mat4("Translation", lLeg.getTr()) * Mat4("Rotation", lLeg.getRad(), lLeg.getRot()) * Mat4("Scale", lLeg.getSc());
		objShad.setMat4("model", model);
		col = lLeg.getCol();
		objShad.setVec3("col", col);
	
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
		glBindVertexArray(0);
		
		//RIGHT LEG
		model = Mat4("Translation", rLeg.getTr()) * Mat4("Rotation", rLeg.getRad(), rLeg.getRot()) * Mat4("Scale", rLeg.getSc());
		objShad.setMat4("model", model);
		col = rLeg.getCol();
		objShad.setVec3("col", col);
	
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
		glBindVertexArray(0);



		
		glfwSwapBuffers(e.w);
		glfwPollEvents();

	}

	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
	glfwTerminate();
	return 0;
}
