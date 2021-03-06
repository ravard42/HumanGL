#ifndef PLANE_HPP
# define PLANE_HPP

# include <iostream>
# include <math.h>
# include "Vec3.hpp"
# include "Shader.hpp"

class Square {

private:

	std::string					_name;
	Vec3							_col;
	
	Vec3							_tr;
	float							_rad;
	Vec3							_rot;
	Vec3							_initTr;
	Vec3							_sc;
	float							_initRad;
	Vec3							_initRot;

public:

	static float const 	data[];	
	static GLuint 			vao_id;
	static Shader 	*		shad;

	Square( void );
	Square( std::string name, Vec3 col, Vec3 tr, float rad, Vec3 rot, Vec3 initTr, Vec3 sc, float initRad, Vec3 initRot);
	Square(Square const & src);
	~Square( void );
	Square &		operator=( Square const & src);

	std::string				getName( void ) const;
	Vec3						getCol( void ) const;

	Vec3						getTr( void ) const;
	float						getRad( void ) const;
	Vec3						getRot( void ) const;
	Vec3						getInitTr( void ) const;
	Vec3						getSc( void ) const;
	float						getInitRad( void ) const;
	Vec3						getInitRot( void ) const;

	void						setAttr( std::string name, Vec3 col, Vec3 tr, float rad, Vec3 rot, Vec3 initTr, Vec3 sc, float initRad, Vec3 initRot);

	void						move( float rad, Vec3 rot );
	Mat4						draw( Mat4 stack ) const;
};

std::ostream &		operator<<( std::ostream & o, Square const & rhs );

#endif
