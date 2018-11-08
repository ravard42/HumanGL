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
	float *		operator[]( int j );
	Mat4			operator+( Mat4 const & src ) const;
	Mat4			operator*( Mat4 const & src ) const;
	Mat4			operator*( float k ) const;

	float		m[4][4];
	void		zero( void );
	void		identity( void );
	void		perspProj(float fov, float ar, float znear, float zfar);
	void		scale(Vec3 const & sc);
	void		rotation(float radian, Vec3 const & n);
	void		translation(Vec3 const & tr);
};

std::ostream &		operator<<( std::ostream & o, Mat4 const & rhs );

#endif
