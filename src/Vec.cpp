#include "Vec.hpp"

Vec::Vec( float x, float y ) : dim(2) {
	std::cout << "Vec 2Param constructor called" << std::endl;
	this->coord = (float *)malloc(sizeof(float) * this->dim);
	this->coord[0] = x;
	this->coord[1] = y;
}

Vec::Vec( float x, float y, float z ) : dim(3) {
	std::cout << "Vec 3Param constructor called" << std::endl;
	this->coord = (float *)malloc(sizeof(float) * this->dim);
	this->coord[0] = x;
	this->coord[1] = y;
	this->coord[2] = z;
}

Vec::Vec( float x, float y, float z, float w ) : dim(4) {
	std::cout << "Vec 4Param constructor called" << std::endl;
	this->coord = (float *)malloc(sizeof(float) * this->dim);
	this->coord[0] = x;
	this->coord[1] = y;
	this->coord[2] = z;
	this->coord[3] = w;
}

Vec::Vec(Vec const  & src) : coord(NULL) {
	std::cout << "Vec copy constructor called" << std::endl;
	*this = src;
}


Vec::~Vec( void ) {
	std::cout << "Vec destructor called" << std::endl;
	free(this->coord);
}


Vec &    	Vec::operator=( Vec const & src) {
	this->dim = src.dim;
	if (this->coord)
		free(this->coord);
	this->coord = (float *)malloc(sizeof(float) * this->dim);
	int	i = -1;

	while (++i < this->dim)
		this->coord[i] = src.coord[i];
	return (*this);
}


std::ostream &		operator<<( std::ostream & o, Vec const & rhs ) {
	int	i = -1;

	o << "Vec" << (int)rhs.dim << std::endl;
	while (++i < rhs.dim)
		o << "|" << rhs.coord[i] << std::endl;
    return o;
}
