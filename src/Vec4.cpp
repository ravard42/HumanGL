#include "Vec4.hpp"

Vec4::Vec4( void ) {
//	std::cout << "Vec4 constructor called" << std::endl;
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	v[3] = 0;
}

Vec4::Vec4( float x, float y, float z, float w ) {
//	std::cout << "Vec4 parametric constructor called" << std::endl;
	v[0] = x;
	v[1] = y;
	v[2] = z;
	v[3] = w;
}

Vec4::Vec4(Vec4 const  & src) {
//	std::cout << "Vec4 copy constructor called" << std::endl;
	*this = src;
}


Vec4::~Vec4( void ) {
//	std::cout << "Vec4 destructor called" << std::endl;
}

float &		Vec4::operator[]( int i)
{
	if (i < 0 || i > 3)
		std::cout << "Index out of bounds" << std::endl;
	return (this->v[i]);
}

Vec4 &    	Vec4::operator=( Vec4 const & src) {
	this->v[0] = src.v[0];
	this->v[1] = src.v[1];
	this->v[2] = src.v[2];
	this->v[3] = src.v[3];
	return (*this);
}


std::ostream &		operator<<( std::ostream & o, Vec4 const & rhs ) {
	o << "<---VEC4 PRINTER---->" << std::endl;
	o << "    |" << rhs.v[0] << std::endl;
	o << "    |" << rhs.v[1] << std::endl;
	o << "    |" << rhs.v[2] << std::endl;
	o << "    |" << rhs.v[3] << std::endl;
	return o;
}
