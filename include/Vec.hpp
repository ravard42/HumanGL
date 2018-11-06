#ifndef VEC_HPP
# define VEC_HPP

# include <iostream>

class Vec {

public:

	Vec( float x, float y );
	Vec( float x, float y, float z );
	Vec( float x, float y, float z, float w );
	Vec(Vec const & src);
	
	~Vec( void );
	Vec &		operator=( Vec const & src);


	char		dim;
	float		*coord;
};

std::ostream &		operator<<( std::ostream & o, Vec const & rhs );

#endif
