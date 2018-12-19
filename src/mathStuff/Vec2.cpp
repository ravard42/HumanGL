#include "Vec2.hpp"

Vec2::Vec2( void ) {
//	std::cout << "Vec2 constructor called" << std::endl;
	v[0] = 0;
	v[1] = 0;
}

Vec2::Vec2( float x, float y ) {
//	std::cout << "Vec2 parametric constructor called" << std::endl;
	v[0] = x;
	v[1] = y;
}

Vec2::Vec2(Vec2 const  & src) {
//	std::cout << "Vec2 copy constructor called" << std::endl;
	*this = src;
}


Vec2::~Vec2( void ) {
//	std::cout << "Vec2 destructor called" << std::endl;
}

float &		Vec2::operator[]( int i)
{
	if (i < 0 || i > 1)
		std::cout << "Index out of bounds" << std::endl;
	return (this->v[i]);
}

Vec2 &    	Vec2::operator=( Vec2 const & src) {
	this->v[0] = src.v[0];
	this->v[1] = src.v[1];
	return (*this);
}


std::ostream &		operator<<( std::ostream & o, Vec2 const & rhs ) {

	o << "<---VEC2 PRINTER---->" << std::endl;
	o << "		|" << rhs.v[0] << std::endl;
	o << "		|" << rhs.v[1] << std::endl;
	return o;
}
