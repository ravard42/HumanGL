#ifndef VEC4_HPP
# define VEC4_HPP

# include <iostream>
# include <math.h>

class Vec4 {

public:

	Vec4( void );
	Vec4( float x, float y, float z, float w);
	Vec4(Vec4 const & src);
	~Vec4( void );
	Vec4	&		operator=( Vec4 const & src);
	float &		operator[]( int i );
	Vec4			operator+( Vec4 const & src ) const;
	Vec4			operator*( float k ) const;

	float		v[4];
	float		getNorm( void ) const;
	Vec4	&	normalize( void );
};

std::ostream &		operator<<( std::ostream & o, Vec4 const & rhs );

#endif
