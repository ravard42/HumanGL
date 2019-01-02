#ifndef CHEST_HPP
# define CHEST_HPP

# include "Cube.hpp"
class Cube;


class Chest : public Cube {

public:

	Chest( void );
	Chest( std::string name, Vec3 Col, float initRad, Vec3 initRot,  Vec3 sc, float rad, Vec3 rot, Vec3 tr);
//Chest(Chest const & src);
	~Chest( void );
//Chest &		operator=( Chest const & src);

//void			draw( GLuint vao, Shader & shad ) const;
};

//std::ostream &		operator<<( std::ostream & o, Chest const & rhs );

#endif
