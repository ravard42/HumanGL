#include "Cube.hpp"

Cube::Cube( void ) : _name("default"){
//	std::cout << "Cube default constructor called" << std::endl;
}

Cube::Cube( std::string name, Vec3 col, float initRad, Vec3 initRot, Vec3 sc, float rad, Vec3 rot, Vec3 tr) :
	_name(name), _col(col), _initRad(initRad), _initRot(initRot), _sc(sc), _rad(rad), _rot(rot), _tr(tr) {
//	std::cout << "Cube parametric constructor called" << std::endl;
}
	
//Cube::Cube(Cube const & src) {
////	std::cout << "Cube copy constructor called" << std::endl;
//	*this = src;
//}

Cube::~Cube( void ) {
//	std::cout << "Cube destructor called" << std::endl;
}

//Cube &    	Cube::operator=( Cube const & src) {
//	this->_name = src.getName();
//	this->_sc = src.getSc();
//	this->_rot = src.getRot();
//	this->_rad = src.getRad();
//	this->_tr = src.getTr();
//	this->_col = src.getCol();
//	return (*this);
//}
//
//std::string		Cube::getName( void ) const {
//	return this->_name;
//}
//
//Vec3				Cube::getSc( void ) const {
//	return this->_sc;
//}
//
//Vec3				Cube::getRot( void ) const {
//	return this->_rot;
//}
//
//float				Cube::getRad( void ) const {
//	return this->_rad;
//}
//
//Vec3				Cube::getTr( void ) const {
//	return this->_tr;
//}
//
//Vec3				Cube::getCol( void ) const {
//	return this->_col;
//}
//
//void				Cube::setSc( Vec3 sc ) {
//	_sc = sc;
//}
//
//void				Cube::setRot( Vec3 rot ) {
//	_rot = rot;
//}
//
//void				Cube::setRad( float rad ) {
//	_rad = rad;
//}
//
//void				Cube::setTr( Vec3 tr ) {
//	_tr = tr;
//}

void				Cube::draw( GLuint vao, Shader & shad ) const {
		
		Mat4	model = Mat4("Translation", _tr)\
								* Mat4("Rotation", _rad, _rot)\
								* Mat4("Scale", _sc)\
								* Mat4("Rotation", _initRad, _initRot);
		shad.setMat4("model", model);
		
		Vec3	col = _col;
		shad.setVec3("col", col);


		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
		glBindVertexArray(0);
	
}

float const Cube::mala[] = {-0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f,  0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f};


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
