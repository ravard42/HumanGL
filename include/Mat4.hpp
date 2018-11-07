#ifndef MAT4_HPP
# define MAT4_HPP

# include <iostream>
# include <iomanip>
# include <math.h>
# include "Vec3.hpp"
# include "Vec4.hpp"

class Mat4 {

private:
	void		_identity( void );
	void		_perspProj(float fov, float ar, float znear, float zfar);
	void		_rotation(float radian, Vec3 const & n);

public:

	Mat4( void );
	Mat4( Vec4 const & a, Vec4 const & b, Vec4 const & c, Vec4 const & d);
	Mat4( std::string str, float fov, float ar, float znear, float zfar );
	Mat4(Mat4 const & src );
	~Mat4( void );
	Mat4	&		operator=( Mat4 const & src );
	Mat4	&		operator+( Mat4 const & src );
	Mat4	&		operator*( float k );
	float *		operator[]( int j );

	float		m[4][4];
};

std::ostream &		operator<<( std::ostream & o, Mat4 const & rhs );

#endif
