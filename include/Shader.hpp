#ifndef SHADER_HPP
# define	SHADER_HPP


# include <glad/glad.h>

# include <fstream>
# include <sstream>
# include <iostream>
# include <math.h>

# include "Vec3.hpp"
# include "Mat4.hpp"


class Shader {

private:

	GLuint	_progID;

	GLuint	_compileShader(std::string sourcePath, GLenum shaderType) const;
	void	_linkProgram( GLuint vertID, GLuint fragID );
	void	_debug( GLint status, char c, GLuint ID) const;

public:

	Shader( std::string vertPath, std::string fragPath );
	~Shader( void );

	void	use( void ) const;
	void	setVec3( const std::string &name, Vec3 & v ) const;
	void 	setMat4(const std::string &name, Mat4 & mat) const;
};

#endif
