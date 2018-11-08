#include "Mat4.hpp"

Mat4::Mat4( void ) {
//	std::cout << "Mat4 constructor called" << std::endl;
	this->identity();
}

Mat4::Mat4( Vec4 const & a, Vec4 const & b, Vec4 const & c, Vec4 const & d) {
	int	i = -1;

//	std::cout << "Mat4 parametric constructor called" << std::endl;
	while (++i < 4) {
		(*this)[0][i] = a.v[i];
		(*this)[1][i] = b.v[i];
		(*this)[2][i] = c.v[i];
		(*this)[3][i] = d.v[i];
	}
}
	
Mat4::Mat4( std::string str ) {
	if (!str.compare("Zero"))
		this->zero();
}

Mat4::Mat4( std::string str, float fov, float ar, float znear, float zfar) {
//	std::cout << "Mat4 Perspective Projection constructor called" << std::endl;
	if (!str.compare("Perspective Projection"))
		this->perspProj(fov, ar, znear, zfar);
}

Mat4::Mat4( std::string str, float radian, Vec3 const & n) {
//	std::cout << "Mat4 Rotation constructor called" << std::endl;
	if (!str.compare("Rotation"))
		this->rotation(radian, n);
}

Mat4::Mat4( std::string str, Vec3 const & vec) {
	if (!str.compare("Scale")) {
//		std::cout << "Mat4 Scale constructor called" << std::endl;
		this->scale(vec);
	}
	else if (!str.compare("Translation")) {
//	std::cout << "Mat4 Translation constructor called" << std::endl;
		this->translation(vec);
	}
}

Mat4::Mat4(Mat4 const  & src) {
//	std::cout << "Mat4 copy constructor called" << std::endl;
	*this = src;
}


Mat4::~Mat4( void ) {
//	std::cout << "Mat4 destructor called" << std::endl;
}


Mat4 &    	Mat4::operator=( Mat4 const & src) {
	int	j = -1;
	int	i;

	while (++j < 4) {
		i = -1;
		while (++i < 4)
			this->m[j][i] = src.m[j][i];
	}
	return (*this);
}

float *		Mat4::operator[]( int j )
{
	if ( j < 0 || j > 3 )
		std::cout << "Index out of bounds" << std::endl;
	return (this->m[j]);
}


Mat4     	Mat4::operator+( Mat4 const & src) const {
	Mat4	ret("Zero");
	int	j = -1;
	int	i;

	while (++j < 4) {
		i = -1;
		while (++i < 4)
			ret[j][i] = this->m[j][i] + src.m[j][i];
	}
	return (ret);
}
	
Mat4			Mat4::operator*( Mat4 const & src ) const {
	Mat4 	ret("Zero");	
	int	i = -1;
	int	j, k;

	while (++i < 4) {
		j = -1;
		while (++j < 4) {
			k = -1;
			while (++k < 4) 
				ret[j][i] += this->m[k][i] * src.m[j][k];
		}
	}
	return ret;
}

Mat4     	Mat4::operator*( float k ) const {
	Mat4	ret("Zero");
	int	j = -1;
	int	i;

	while (++j < 4) {
		i = -1;
		while (++i < 4)
			ret[j][i] = k * this->m[j][i];
	}
	return (ret);
}


void		Mat4::zero( void ) {
	int	j = -1;
	int	i;

	while (++j < 4) {
		i = -1;
		while (++i < 4)
			this->m[j][i] = 0;
	}
}

void		Mat4::identity( void ) {
	int	j = -1;
	int	i;

	while (++j < 4) {
		i = -1;
		while (++i < 4)
			this->m[j][i] = 0;
	}
	j = -1;
	while (++j < 4)
		this->m[j][j] = 1;
}

void		Mat4::perspProj(float fov, float ar, float znear, float zfar) {
	this->identity();
	this->m[0][0] = 1 / (ar * tan(fov / 2));
	this->m[1][1] = 1 / tan(fov / 2);
	this->m[2][2] = (znear + zfar) / (znear - zfar);
	this->m[2][3] = -1;
	this->m[3][2] = -2 * znear * zfar / (znear - zfar);
	this->m[3][3] = 0;
}

void		Mat4::scale(Vec3 const & scVec) {
	float	const *sc = scVec.v;
	this->identity();
	(*this)[0][0] *= sc[0];
	(*this)[1][1] *= sc[1];
	(*this)[2][2] *= sc[2];
}

void		Mat4::rotation(float radian, Vec3 const & rotVec) {
	float	const *n = rotVec.v;
	Mat4	id;
	Mat4	p = Mat4(Vec4(n[0] * n[0], n[0] * n[1], n[0] * n[2], 0),
				Vec4(n[1] * n[0], n[1] * n[1], n[1] * n[2], 0),
				Vec4(n[2] * n[0], n[2] * n[1], n[2] * n[2], 0),
				Vec4(0, 0, 0, 0));
	Mat4	q = Mat4(Vec4(0, n[2], -n[1], 0),
				Vec4(-n[2], 0, n[0], 0),
				Vec4(n[1], -n[0], 0, 0),
				Vec4(0, 0, 0, 0));
	*this = id * cos(radian) + p * (1 - cos(radian)) + q * sin(radian);
	(*this)[3][3] = 1;
}

void		Mat4::translation(Vec3 const & trVec) {
	float	const *tr = trVec.v;
	this->identity();
	(*this)[3][0] += tr[0];
	(*this)[3][1] += tr[1];
	(*this)[3][2] += tr[2];
}

std::ostream &		operator<<( std::ostream & o, Mat4 const & rhs ) {
	int	i = -1;
	int	j;

	o << "<---MAT4 PRINTER---->" << std::endl;
	while (++i < 4) {
		o << "|";
		j = -1;
		while (++j < 4) {
			std::cout << std::setw(10);
			o << rhs.m[j][i] << "|";
		}
		o << std::endl;
	}
	return o;
}
