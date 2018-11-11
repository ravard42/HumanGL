#ifndef VEC3_HPP
# define VEC3_HPP

# include <iostream>
# include <math.h>

class Vec3 {

public:

	Vec3( void );
	Vec3( float x, float y, float z );
	Vec3(Vec3 const & src);
	~Vec3( void );
	Vec3 &		operator=( Vec3 const & src);
	float &		operator[]( int i );
	Vec3			operator+( Vec3 const & src ) const;
	Vec3			operator*( float k ) const;

	float		v[3];
	Vec3	&	normalize( void );
};

std::ostream &		operator<<( std::ostream & o, Vec3 const & rhs );

#endif
