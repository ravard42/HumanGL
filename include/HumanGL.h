#ifndef HUMANGL_HPP
# define HUMANGL_HPP

# include <iostream>
# include <math.h>

# include "glad/glad.h"
# include "glfw3.h"

# include "unistd.h"

# define WINX 500
# define WINY 500

# define SQUARE_DATA_NB 18
# define	ENV_SQUARE_NB 1
# define CUBE_DATA_NB 108
# define	ENV_CUBE_NB 6

# include "Vec3.hpp"
# include "Vec4.hpp"
# include "Mat4.hpp"
# include "Shader.hpp"
# include "Camera.hpp"
# include "Square.hpp"
# include "Cube.hpp"
# include "CubeTree.hpp"
# include "Human.hpp"

typedef struct		s_env {

	GLFWwindow		*w;
	Camera			cam;
	Shader			shad;
	Human				h;
	Square			*s;
	Cube				*c;

}					t_env;


GLFWwindow  *init_OpenGL( void );
void			set_callback(t_env *e);
void			draw_all(t_env *e);

#endif
