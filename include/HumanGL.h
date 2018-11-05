#ifndef HUMANGL_HPP
# define HUMANGL_HPP

# include <iostream>

# include "glad/glad.h"
# include "glfw3.h"
//# include "stb_image.h"
//# include "glm.hpp"
//# include "gtc/matrix_transform.hpp"
//# include "gtc/type_ptr.hpp"
//#include "Importer.hpp"
//#include "scene.h"
//#include "postprocess.h"

# define WINX 800
# define WINY 640


# include "Shader.hpp"
//# include "Camera.hpp"

typedef struct		s_env {

	GLFWwindow		*w;
//	Camera			cam;

}					t_env;


int			init_glfw(t_env *e);
int			init_glad(void);
void		set_callback(t_env *e);

#endif
