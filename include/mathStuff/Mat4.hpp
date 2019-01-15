#ifndef MAT4_HPP
# define MAT4_HPP

# include <iostream>
# include <iomanip>
# include <math.h>
# include "Vec3.hpp"
# include "Vec4.hpp"

class Mat4 {

public:

	Mat4( void );
	Mat4( Vec4 const & a, Vec4 const & b, Vec4 const & c, Vec4 const & d);
	Mat4( std::string );
	Mat4( std::string str, float fov, float ar, float znear, float zfar );
	Mat4( std::string str, float radian, Vec3 const & n);
	Mat4( std::string str, Vec3 const & vec);
	Mat4(Mat4 const & src );
	~Mat4( void );
	Mat4	&		operator=( Mat4 const & src );
	Vec4	&		operator[]( int j );
	Mat4			operator+( Mat4 const & src ) const;
	Mat4			operator*( Mat4 const & src ) const;
	Mat4	&		operator*=( Mat4 const & src );
	Mat4			operator*( float k ) const;

	Vec4		m[4];
	Mat4	&	zero( void );
	Mat4	&	identity( void );
	Mat4	&	perspProj(float fov, float ar, float znear, float zfar);
	Mat4	&	scale(Vec3 const & sc);
	Mat4	&	rotation(float radian, Vec3 const & n);
	Mat4	&	normalize( void );
	Mat4	&	translation(Vec3 const & tr);
	Mat4		transpose( void );
};

std::ostream &		operator<<( std::ostream & o, Mat4 const & rhs );

#endif
