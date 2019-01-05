﻿#include "Cube.hpp"

float const Cube::mala[] = {-0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f,  0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f};

Cube::Cube( void ) : _name("default"), _col(Vec3(1)) {
//	std::cout << "Cube default constructor called" << std::endl;
}

Cube::Cube( std::string name, Vec3 col, Vec3 parentTr, float parentRad, Vec3 parentRot, Vec3 parentSc, float rad, Vec3 rot, Vec3 tr, Vec3 sc, float initRad, Vec3 initRot ) :
							_name(name), _col(col), _parentTr(parentTr), _parentRad(parentRad), _parentRot(parentRot), _parentSc(parentSc),
							_rad(rad), _rot(rot), _tr(tr), _sc(sc), _initRad(initRad), _initRot(initRot) {

//	std::cout << "Cube parametric constructor called" << std::endl;
}
	
Cube::Cube(Cube const & src) {
//	std::cout << "Cube copy constructor called" << std::endl;
	*this = src;
}

Cube::~Cube( void ) {
//	std::cout << "Cube destructor called" << std::endl;
}

Cube &    	Cube::operator=( Cube const & src) {
	_name = src.getName();
	_col = src.getCol();

	//parent
	_parentTr = src.getParentTr();
	_parentRad = src.getParentRad();
	_parentRot = src.getParentRot();
	_parentSc = src.getParentSc();
	//

	//Child here
	_rad = src.getRad();
	_rot = src.getRot();
	_tr = src.getTr();
	_sc = src.getSc();
	_initRad = src.getInitRad();
	_initRot = src.getInitRot();
	//

	return (*this);
}

std::string		Cube::getName( void ) const {
	return _name;
}

Vec3				Cube::getCol( void ) const {
	return _col;
}

//Parent getter

Vec3				Cube::getParentTr( void ) const {
	return 	_parentTr;
}

float				Cube::getParentRad( void ) const {
	return	_parentRad;
}
	
Vec3				Cube::getParentRot( void ) const {
	return 	_parentRot;
}

Vec3				Cube::getParentSc( void ) const {
	return 	_parentSc;
}
//

//Child getter

float				Cube::getRad( void ) const {
	return this->_rad;
}

Vec3				Cube::getRot( void ) const {
	return this->_rot;
}

Vec3				Cube::getTr( void ) const {
	return this->_tr;
}

Vec3				Cube::getSc( void ) const {
	return this->_sc;
}

float				Cube::getInitRad( void ) const {
	return this->_initRad;
}

Vec3				Cube::getInitRot( void ) const {
	return this->_initRot;
}
//

//parent setter to write if necessary

//

//Child setter
void				Cube::setRad( float rad ) {
	_rad = rad;
}

void				Cube::setRot( Vec3 rot ) {
	_rot = rot;
}

void				Cube::setTr( Vec3 tr ) {
	_tr = tr;
}

void				Cube::setSc( Vec3 sc ) {
	_sc = sc;
}
//


void				Cube::draw( GLuint vao, Shader & shad, Mat4 parentStack, HumanState * state ) const {

	
		Mat4	test = state && (!_name.compare("lArm") || !_name.compare("rArm")) ? Mat4("Translation", _parentTr) * Mat4("Rotation", state->getFrame() / (float)60 * M_PI * 2, Vec3("x")) : Mat4();


		Mat4	model = parentStack\
								* test\
								* Mat4("Rotation", _rad, _rot)\
								* Mat4("Translation", _tr)\
								* Mat4("Scale", _sc)\
								* Mat4("Rotation", _initRad, _initRot);


		shad.setMat4("model", model);
		
		Vec3	col = _col;
		shad.setVec3("col", col);


		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
		glBindVertexArray(0);
	
}



//std::ostream &		operator<<( std::ostream & o, Cube const & rhs ) {
//
//	o << "<---LIMB PRINTER---->" << std::endl;
//	o << "name: " << rhs.getName() << std::endl;
//	o << "scale: |" << rhs.getSc() << std::endl;
//	o << "rotate: " << rhs.getRad() << "radians on =>" << std::endl;
//	o << rhs.getRot() << std::endl;
//	o << "translate: " << rhs.getTr() << std::endl;
//	o << "color: " << rhs.getCol() << std::endl;
//	
//	return o;
//}
