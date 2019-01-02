#ifndef LEG_HPP
# define LEG_HPP

# include "Cube.hpp"
class Cube;


class Leg : public Cube {

public:

	Leg( void );
	Leg( std::string name, Vec3 Col, float initRad, Vec3 initRot,  Vec3 sc, float rad, Vec3 rot, Vec3 tr);
//Leg(Leg const & src);
	~Leg( void );
//Leg &		operator=( Leg const & src);

//void			draw( GLuint vao, Shader & shad ) const;
};

//std::ostream &		operator<<( std::ostream & o, Leg const & rhs );

#endif
