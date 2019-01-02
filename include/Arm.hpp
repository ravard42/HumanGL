#ifndef ARM_HPP
# define ARM_HPP

# include "Cube.hpp"
class Cube;


class Arm : public Cube {

public:

	Arm( void );
	Arm( std::string name, Vec3 Col, float initRad, Vec3 initRot,  Vec3 sc, float rad, Vec3 rot, Vec3 tr);
//Arm(Arm const & src);
	~Arm( void );
//Arm &		operator=( Arm const & src);

//void			draw( GLuint vao, Shader & shad ) const;
};

//std::ostream &		operator<<( std::ostream & o, Arm const & rhs );

#endif
