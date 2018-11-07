#include "Vec3.hpp"

Vec3::Vec3( void ) {
	std::cout << "Vec3 constructor called" << std::endl;
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
}

Vec3::Vec3( float x, float y, float z ) {
	std::cout << "Vec3 parametric constructor called" << std::endl;
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

Vec3::Vec3(Vec3 const  & src) {
	std::cout << "Vec3 copy constructor called" << std::endl;
	*this = src;
}


Vec3::~Vec3( void ) {
	std::cout << "Vec3 destructor called" << std::endl;
}

float &		Vec3::operator[]( int i)
{
	if (i < 0 || i > 2)
		std::cout << "Index out of bounds" << std::endl;
	return (this->v[i]);
}

Vec3 &    	Vec3::operator=( Vec3 const & src) {
	this->v[0] = src.v[0];
	this->v[1] = src.v[1];
	this->v[2] = src.v[2];
	return (*this);
}


std::ostream &		operator<<( std::ostream & o, Vec3 const & rhs ) {

	o << "<---VEC3 PRINTER---->" << std::endl;
	o << "		|" << rhs.v[0] << std::endl;
	o << "		|" << rhs.v[1] << std::endl;
	o << "		|" << rhs.v[2] << std::endl;
	return o;
}
