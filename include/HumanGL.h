#ifndef HUMANGL_HPP
# define HUMANGL_HPP

# include <iostream>
# include <math.h>

# include "glad/glad.h"
# include "glfw3.h"

# include "unistd.h"

# define WINX 500
# define WINY 500

# define MALA 108

# include "Vec3.hpp"
# include "Vec4.hpp"
# include "Mat4.hpp"
# include "Shader.hpp"
# include "Camera.hpp"
# include "Cube.hpp"
# include "CubeTree.hpp"
# include "Human.hpp"
# include "HumanState.hpp"

typedef struct		s_env {

	GLFWwindow		*w;
	Camera			cam;
	Human				*h;

}					t_env;


int			init_glfw(t_env *e);
int			init_glad(void);
void		set_callback(t_env *e);

#endif
