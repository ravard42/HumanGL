#include "Leg.hpp"

Leg::Leg( void ) : Cube() {
//	std::cout << "Leg default constructor called" << std::endl;
}

Leg::Leg( std::string name, Vec3 col, float initRad, Vec3 initRot, Vec3 sc, float rad, Vec3 rot, Vec3 tr) : Cube(name, col, initRad, initRot, sc, rad, rot, tr) {
//	std::cout << "Leg parametric constructor called" << std::endl;
}
	
//Leg::Leg(Leg const & src) {
////	std::cout << "Leg copy constructor called" << std::endl;
//	*this = src;
//}

Leg::~Leg( void ) {
//	std::cout << "Leg destructor called" << std::endl;
}

//Leg &    	Leg::operator=( Leg const & src) {
//	this->_name = src.getName();
//	this->_sc = src.getSc();
//	this->_rot = src.getRot();
//	this->_rad = src.getRad();
//	this->_tr = src.getTr();
//	this->_col = src.getCol();
//	return (*this);
//}

//void				Leg::draw( GLuint vao, Shader & shad ) const {
//		
//		Mat4	model = Mat4("Translation", _tr)\
//								* Mat4("Rotation", _rad, _rot)\
//								* Mat4("Scale", _sc)\
//								* Mat4("Rotation", _initRad, _initRot);
//		shad.setMat4("model", model);
//		
//		Vec3	col = _col;
//		shad.setVec3("col", col);
//
//
//		glBindVertexArray(vao);
//		glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
//		glBindVertexArray(0);
//	
//}

//std::ostream &		operator<<( std::ostream & o, Leg const & rhs ) {
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
