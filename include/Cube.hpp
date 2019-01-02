#ifndef CUBE_HPP
# define CUBE_HPP

# include <iostream>
# include <math.h>
# include "Vec3.hpp"
# include "Shader.hpp"

class Cube {

private:

	std::string				_name;
	Vec3							_col;
	float							_initRad;
	Vec3							_initRot;
	Vec3							_sc;
	float							_rad;
	Vec3							_rot;
	Vec3							_tr;

public:

	static float const mala[];	

	Cube( void );
	Cube( std::string name, Vec3 Col, float initRad, Vec3 initRot,  Vec3 sc, float rad, Vec3 rot, Vec3 tr);
//	Cube(Cube const & src);
	~Cube( void );
	//Cube &		operator=( Cube const & src);

//	std::string	getName( void ) const;
//	Vec3			getSc( void ) const;
//	Vec3			getRot( void ) const;
//	float			getRad( void ) const;
//	Vec3			getTr( void ) const;
//	Vec3			getCol( void ) const;
//	void			setSc( Vec3 sc );
//	void			setRot( Vec3 rot );
//	void			setRad( float rad );
//	void			setTr( Vec3 tr );

	void			draw( GLuint vao, Shader & shad ) const;
};

//std::ostream &		operator<<( std::ostream & o, Cube const & rhs );

#endif
