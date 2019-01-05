#ifndef CUBE_HPP
# define CUBE_HPP

# include <iostream>
# include <math.h>
# include "Vec3.hpp"
# include "Shader.hpp"
# include "HumanState.hpp"

class Cube {

private:

	std::string				_name;
	Vec3							_col;
	
	Vec3							_parentTr;
	float							_parentRad;
	Vec3							_parentRot;
	Vec3							_parentSc;

	float							_rad;
	Vec3							_rot;
	Vec3							_tr;
	Vec3							_sc;
	float							_initRad;
	Vec3							_initRot;

public:

	static float const mala[];	

	Cube( void );
	Cube( std::string name, Vec3 col, Vec3 parentTr, float parentRad, Vec3 parentRot, Vec3 parentSc, float rad, Vec3 rot, Vec3 tr, Vec3 sc, float initRad, Vec3 initRot);
	Cube(Cube const & src);
	~Cube( void );
	Cube &		operator=( Cube const & src);

	std::string			getName( void ) const;
	Vec3						getCol( void ) const;

	//parent getter here if necessary

	Vec3						getParentTr( void ) const;
	float						getParentRad( void ) const;
	Vec3						getParentRot( void ) const;
	Vec3						getParentSc( void ) const;
	
	float						getRad( void ) const;
	Vec3						getRot( void ) const;
	Vec3						getTr( void ) const;
	Vec3						getSc( void ) const;
	float						getInitRad( void ) const;
	Vec3						getInitRot( void ) const;
	
	//parent setter to write if necessary

	void						setRad( float rad );
	void						setRot( Vec3 rot );
	void						setTr( Vec3 tr );
	void						setSc( Vec3 sc );

	void			draw( GLuint vao, Shader & shad, Mat4 stackTransfo, HumanState * state ) const;
};

//std::ostream &		operator<<( std::ostream & o, Cube const & rhs );

#endif
