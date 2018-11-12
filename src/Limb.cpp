#include "Limb.hpp"

Limb::Limb( void ) : _name("default"){
//	std::cout << "Limb default constructor called" << std::endl;
}

Limb::Limb( std::string name, Vec3 sc, Vec3 rot, float rad, Vec3 tr) :
	_name(name), _sc(sc), _rot(rot), _rad(rad), _tr(tr) {
//	std::cout << "Limb parametric constructor called" << std::endl;
}
	
Limb::Limb(Limb const & src) {
//	std::cout << "Limb copy constructor called" << std::endl;
	*this = src;
}

Limb::~Limb( void ) {
//	std::cout << "Limb destructor called" << std::endl;
}

Limb &    	Limb::operator=( Limb const & src) {
	this->_name = src.getName();
	this->_sc = src.getSc();
	this->_rot = src.getRot();
	this->_rad = src.getRad();
	this->_tr = src.getTr();
	return (*this);
}

std::string		Limb::getName( void ) const {
	return this->_name;
}

Vec3				Limb::getSc( void ) const {
	return this->_sc;
}

Vec3				Limb::getRot( void ) const {
	return this->_rot;
}

float				Limb::getRad( void ) const {
	return this->_rad;
}

Vec3				Limb::getTr( void ) const {
	return this->_tr;
}


std::ostream &		operator<<( std::ostream & o, Limb const & rhs ) {

	o << "<---LIMB PRINTER---->" << std::endl;
	o << "name: " << rhs.getName() << std::endl;
	o << "scale: |" << rhs.getSc() << std::endl;
	o << "rotate: " << rhs.getRad() << "radians on =>" << std::endl;
	o << rhs.getRot() << std::endl;
	o << "translate: " << rhs.getTr() << std::endl;
	
	return o;
}
