#ifndef MAT4_HPP
# define MAT4_HPP

# include <iostream>
# include <iomanip>
# include <math.h>

class Mat4 {

private:
	void		_identity( void );
	void		_perspProj(float fov, float ar, float znear, float zfar);

public:

	Mat4( void );
	Mat4( std::string str, float fov, float ar, float znear, float zfar );
	Mat4(Mat4 const & src );
	~Mat4( void );
	Mat4 &		operator= ( Mat4 const & src );

	float		m[4][4];
};

std::ostream &		operator<<( std::ostream & o, Mat4 const & rhs );

#endif
