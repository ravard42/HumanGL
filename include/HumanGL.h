#ifndef HUMANGL_HPP
# define HUMANGL_HPP

# include <iostream>
# include <math.h>

# include "glad/glad.h"
# include "glfw3.h"

# define WINX 500
# define WINY 500


# include "Vec3.hpp"
# include "Vec4.hpp"
# include "Mat4.hpp"
# include "Shader.hpp"
# include "Camera.hpp"
# include "Limb.hpp"

typedef struct		s_env {

	GLFWwindow		*w;
	Camera			cam;

}					t_env;


int			init_glfw(t_env *e);
int			init_glad(void);
void		set_callback(t_env *e);

#endif
