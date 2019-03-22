#include "HumanGL.h"

GLFWwindow	*init_glfw( void ) {
	GLFWwindow	*w;

	if (!glfwInit()) {
		std::cout << "an error occured in glfwInit() ..." << std::endl;
		return (NULL);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	if (!(w = glfwCreateWindow(WINX, WINY, "HumanGL", NULL, NULL))) {
		std::cout << "an error occured in glfwCreateWindow() ..." << std::endl;
		glfwTerminate();
		return (NULL);
	}
	glfwMakeContextCurrent(w);
	glfwSetInputMode(w, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	return (w);
}

static int	init_glad( void ) {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "an error occured in gladLoadGLLoader() ..." << std::endl;
		glfwTerminate();
		return (0);
	}
	return (1);
}

GLFWwindow	*init_OpenGL( void ) {
	GLFWwindow	*w;
	
	w = init_glfw();
	if (w && init_glad())
		return w;
	return NULL;
}
