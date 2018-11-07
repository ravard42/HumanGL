#ifndef VEC3_HPP
# define VEC3_HPP

# include <iostream>

class Vec3 {

public:

	Vec3( void );
	Vec3( float x, float y, float z );
	Vec3(Vec3 const & src);
	~Vec3( void );
	Vec3 &		operator=( Vec3 const & src);

	float		v[3];
};

std::ostream &		operator<<( std::ostream & o, Vec3 const & rhs );

#endif
