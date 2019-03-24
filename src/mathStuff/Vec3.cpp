#include "Vec3.hpp"

Vec3::Vec3( void ) {
//	std::cout << "Vec3 default constructor called" << std::endl;
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
}

Vec3::Vec3( float k ) {
	v[0] = k;
	v[1] = k;
	v[2] = k;
}
	
Vec3::Vec3( std::string str ) {
	if (!str.compare("x") || !str.compare("red")) {
//		std::cout << "Vec3 X constructor called" << std::endl;
		v[0] = 1;
		v[1] = 0;
		v[2] = 0;
	}
	else if (!str.compare("y") || !str.compare("green")) {
//		std::cout << "Vec3 Y constructor called" << std::endl;
		v[0] = 0;
		v[1] = 1;
		v[2] = 0;
	}
	else if (!str.compare("z") || !str.compare("blue")) {
//		std::cout << "Vec3 Z constructor called" << std::endl;
		v[0] = 0;
		v[1] = 0;
		v[2] = 1;
	}
	else if (!str.compare("blue jeanz")) {
		v[0] = 0.20;
		v[1] = 0.25;
		v[2] = 0.42;
	}
	else if (!str.compare("magenta")) {
//		std::cout << "Vec3 Z constructor called" << std::endl;
		v[0] = 1;
		v[1] = 0;
		v[2] = 1;
	}
	else if (!str.compare("cyan")) {
//		std::cout << "Vec3 Z constructor called" << std::endl;
		v[0] = 0;
		v[1] = 1;
		v[2] = 1;
	}
	else if (!str.compare("yellow")) {
//		std::cout << "Vec3 Z constructor called" << std::endl;
		v[0] = 1;
		v[1] = 1;
		v[2] = 0;
	}
	else if (!str.compare("brown")) {
//		std::cout << "Vec3 Z constructor called" << std::endl;
		v[0] = 0.5;
		v[1] = 0.258;
		v[2] = 0;
	}
	else if (!str.compare("darkgreen")) {
//		std::cout << "Vec3 Z constructor called" << std::endl;
		v[0] = 0.0;
		v[1] = 0.15;
		v[2] = 0;
	}
	else if (!str.compare("skin")) {
//		std::cout << "Vec3 Z constructor called" << std::endl;
		v[0] = 1.0;
		v[1] = 0.8;
		v[2] = 0.6;
	}
	else if (!str.compare("purple")) {
//		std::cout << "Vec3 Z constructor called" << std::endl;
		v[0] = 0.8;
		v[1] = 0.0;
		v[2] = 0.8;
	}
	else if (!str.compare("darkRed")) {
//		std::cout << "Vec3 Z constructor called" << std::endl;
		v[0] = 0.42;
		v[1] = 0.0;
		v[2] = 0.0;
	}
	else if (!str.compare("darkPurple")) {
//		std::cout << "Vec3 Z constructor called" << std::endl;
		v[0] = 0.5;
		v[1] = 0.0;
		v[2] = 0.5;
	}
	else if (!str.compare("orange")) {
//		std::cout << "Vec3 Z constructor called" << std::endl;
		v[0] = 1;
		v[1] = 0.3;
		v[2] = 0;
	}
}

Vec3::Vec3( float x, float y, float z ) {
//	std::cout << "Vec3 parametric constructor called" << std::endl;
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

Vec3::Vec3(Vec3 const  & src) {
//	std::cout << "Vec3 copy constructor called" << std::endl;
	*this = src;
}


Vec3::~Vec3( void ) {
//	std::cout << "Vec3 destructor called" << std::endl;
}

Vec3 &    	Vec3::operator=( Vec3 const & src) {
	this->v[0] = src.v[0];
	this->v[1] = src.v[1];
	this->v[2] = src.v[2];
	return (*this);
}

float &		Vec3::operator[]( int i)
{
	if (i < 0 || i > 2)
		std::cout << "Index out of bounds" << std::endl;
	return (this->v[i]);
}

Vec3     	Vec3::operator+( Vec3 const & src) const {
	Vec3	ret(0.0f, 0.0f, 0.0f);
	int	i = -1;

	while (++i < 3)
			ret[i] = this->v[i] + src.v[i];
	return (ret);
}
	
Vec3     	Vec3::operator*( float k ) const {
	Vec3	ret(0.0f, 0.0f, 0.0f);
	int	i = -1;

	while (++i < 3) {
			ret[i] = k * this->v[i];
	}
	return (ret);
}

float			Vec3::getNorm( void ) const {
	return sqrt(pow(this->v[0], 2) + pow(this->v[1], 2) + pow(this->v[2], 2));
}
	
Vec3	&		Vec3::normalize( void ) {
	float norm = this->getNorm();

	*this = (norm != 0.0f) ? *this * (1 / norm) : *this;
	return *this;
}

std::ostream &		operator<<( std::ostream & o, Vec3 const & rhs ) {

	o << "VEC3(" << rhs.v[0] <<
		"," << rhs.v[1] <<
		"," << rhs.v[2] << ")";
	return o;
}
