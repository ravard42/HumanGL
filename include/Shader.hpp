﻿#ifndef SHADER_HPP
#define	SHADER_HPP


#include <glad/glad.h>

#include <fstream>
#include <sstream>
#include <iostream>

#include "Vec.hpp"

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
	void	setUVec3( const std::string &name, Vec & v ) const;
//	void	setUMat3( const std::string &name, glm::mat3 m ) const;
//	void	setUMat4( const std::string &name, glm::mat4 m ) const;
	
};

#endif
