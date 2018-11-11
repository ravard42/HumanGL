#include "Vec3.hpp"

Vec3::Vec3( void ) {
//	std::cout << "Vec3 constructor called" << std::endl;
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
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

	o << "<---VEC3 PRINTER---->" << std::endl;
	o << "		|" << rhs.v[0] << std::endl;
	o << "		|" << rhs.v[1] << std::endl;
	o << "		|" << rhs.v[2] << std::endl;
	return o;
}
