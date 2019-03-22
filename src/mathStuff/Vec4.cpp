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

Vec4 &    	Vec4::operator=( Vec4 const & src) {
	this->v[0] = src.v[0];
	this->v[1] = src.v[1];
	this->v[2] = src.v[2];
	this->v[3] = src.v[3];
	return (*this);
}

float &		Vec4::operator[]( int i)
{
	if (i < 0 || i > 3) {
		std::cout << "Index out of bounds, first data sendt" << std::endl;
		return this->v[0];
	}
	return (this->v[i]);
}

Vec4     	Vec4::operator+( Vec4 const & src) const {
	Vec4	ret(0.0f, 0.0f, 0.0f, 0.0f);
	int	i = -1;

	while (++i < 4)
			ret[i] = this->v[i] + src.v[i];
	return (ret);
}
	
Vec4     	Vec4::operator*( float k ) const {
	Vec4	ret(0.0f, 0.0f, 0.0f, 0.0f);
	int	i = -1;

	while (++i < 4) {
			ret[i] = k * this->v[i];
	}
	return (ret);
}

float			Vec4::getNorm( void ) const {
	return sqrt(pow(this->v[0], 2)
			+ pow(this->v[1], 2)
			+ pow(this->v[2], 2)
			+ pow(this->v[3], 2));
}
	
Vec4	&		Vec4::normalize( void ) {
	float norm = this->getNorm();

	*this = (norm != 0.0f) ? *this * (1 / norm) : *this;
	return *this;
};

std::ostream &		operator<<( std::ostream & o, Vec4 const & rhs ) {
	o << "VEC4(" << rhs.v[0] <<
		"," << rhs.v[1] <<
		"," << rhs.v[2] <<
		"," << rhs.v[3] << ")";
	return o;
}
