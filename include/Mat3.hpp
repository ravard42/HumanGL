#ifndef MAT3_HPP
# define MAT3_HPP

# include <iostream>
# include <iomanip>
# include <math.h>
# include "Vec3.hpp"
# include "Vec3.hpp"
# include "Mat4.hpp"

class Mat3 {

public:

	Mat3( void );
	Mat3( Vec3 const & a, Vec3 const & b, Vec3 const & c);
	Mat3( std::string );
	Mat3( std::string str, float radian, Vec3 const & n);
	Mat3( std::string str, Vec3 const & vec);
	Mat3( Mat4 const & src );
	Mat3(Mat3 const & src );
	~Mat3( void );
	Mat3	&		operator=( Mat3 const & src );
	Vec3	&		operator[]( int j );
	Mat3			operator+( Mat3 const & src ) const;
	Mat3			operator*( Mat3 const & src ) const;
	Mat3			operator*( float k ) const;

	Vec3		m[3];
	Mat3	&	zero( void );
	Mat3	&	identity( void );
	Mat3	&	scale(Vec3 const & sc);
	Mat3	&	rotation(float radian, Vec3 const & n);
	Mat3		transpose( void );
};

std::ostream &		operator<<( std::ostream & o, Mat3 const & rhs );

#endif
