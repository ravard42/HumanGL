﻿#include "Mat4.hpp"

Mat4::Mat4( void ) {
	std::cout << "Mat4 constructor called" << std::endl;
	this->_identity();
}

Mat4::Mat4( Vec4 const & a, Vec4 const & b, Vec4 const & c, Vec4 const & d) {
	int	i = -1;

	while (++i < 4) {
		this->m[0][i] = a.v[i];
		this->m[1][i] = b.v[i];
		this->m[2][i] = c.v[i];
		this->m[3][i] = d.v[i];
	}
}

Mat4::Mat4( std::string str, float fov, float ar, float znear, float zfar) {
	std::cout << "Mat4 Perspective Projection constructor called" << std::endl;
	if (!str.compare("Perspective Projection"))
		this->_perspProj(fov, ar, znear, zfar);
}

Mat4::Mat4(Mat4 const  & src) {
	std::cout << "Mat4 copy constructor called" << std::endl;
	*this = src;
}


Mat4::~Mat4( void ) {
	std::cout << "Mat4 destructor called" << std::endl;
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


Mat4 &    	Mat4::operator+( Mat4 const & src) {
	int	j = -1;
	int	i;

	while (++j < 4) {
		i = -1;
		while (++i < 4)
			this->m[j][i] += src.m[j][i];
	}
	return (*this);
}

Mat4 &    	Mat4::operator*( float k ) {
	int	j = -1;
	int	i;

	while (++j < 4) {
		i = -1;
		while (++i < 4)
			this->m[j][i] *= k;
	}
	return (*this);
}

float *		Mat4::operator[]( int j )
{
	if ( j < 0 || j > 3 )
		std::cout << "Index out of bounds" << std::endl;
	return (this->m[j]);
}

void		Mat4::_identity( void ) {
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

void		Mat4::_perspProj(float fov, float ar, float znear, float zfar) {
	this->_identity();
	this->m[0][0] = 1 / (ar * tan(fov / 2));
	this->m[1][1] = 1 / tan(fov / 2);
	this->m[2][2] = (znear + zfar) / (znear - zfar);
	this->m[2][3] = -1;
	this->m[3][2] = -2 * znear * zfar / (znear - zfar);
	this->m[3][3] = 0;
}

//void		Mat4::_rotation(float radian, Vec3 const & n) {
//	Mat4	id;
//	Mat4	p;
//	Mat4	q;
//}

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
