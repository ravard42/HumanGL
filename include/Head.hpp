#ifndef HEAD_HPP
# define HEAD_HPP

# include "Cube.hpp"
class Cube;


class Head : public Cube {

public:

	Head( void );
	Head( std::string name, Vec3 Col, float initRad, Vec3 initRot,  Vec3 sc, float rad, Vec3 rot, Vec3 tr);
//Head(Head const & src);
	~Head( void );
//Head &		operator=( Head const & src);

//void			draw( GLuint vao, Shader & shad ) const;
};

#endif
