#include "Limb.hpp"

Limb::Limb( void ) : _name("default"){
//	std::cout << "Limb default constructor called" << std::endl;
}

Limb::Limb( std::string name, Vec3 sc, Vec3 rot, float rad, Vec3 tr, Vec3 col) :
	_name(name), _sc(sc), _rot(rot), _rad(rad), _tr(tr), _col(col) {
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
	this->_col = src.getCol();
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

Vec3				Limb::getCol( void ) const {
	return this->_col;
}

void				Limb::setSc( Vec3 sc ) {
	_sc = sc;
}

void				Limb::setRot( Vec3 rot ) {
	_rot = rot;
}

void				Limb::setRad( float rad ) {
	_rad = rad;
}

void				Limb::setTr( Vec3 tr ) {
	_tr = tr;
}

void				Limb::draw( GLuint vao, Shader & shad ) const {
		
		Mat4	model = Mat4("Translation", this->getTr())\
								* Mat4("Rotation", this->getRad(), this->getRot())\
								* Mat4("Scale", this->getSc());
		shad.setMat4("model", model);
		
		Vec3	col = this->getCol();
		shad.setVec3("col", col);


		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
		glBindVertexArray(0);
	
}

Vec3 const	Limb::color[] = {Vec3(1.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0), Vec3(0.0, 0.0, 1.0), Vec3(1.0, 0.0, 1.0)};
float Limb::cube[] = {-0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f,  0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f};


std::ostream &		operator<<( std::ostream & o, Limb const & rhs ) {

	o << "<---LIMB PRINTER---->" << std::endl;
	o << "name: " << rhs.getName() << std::endl;
	o << "scale: |" << rhs.getSc() << std::endl;
	o << "rotate: " << rhs.getRad() << "radians on =>" << std::endl;
	o << rhs.getRot() << std::endl;
	o << "translate: " << rhs.getTr() << std::endl;
	o << "color: " << rhs.getCol() << std::endl;
	
	return o;
}
