#ifndef VEC2_HPP
# define VEC2_HPP

# include <iostream>

class Vec2 {

public:

	Vec2( void );
	Vec2( float x, float y );
	Vec2(Vec2 const & src);
	~Vec2( void );
	Vec2 &		operator=( Vec2 const & src);
	float &		operator[]( int i );

	float		v[2];
};

std::ostream &		operator<<( std::ostream & o, Vec2 const & rhs );

#endif
