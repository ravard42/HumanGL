#include "Head.hpp"

Head::Head( void ) : Cube() {
//	std::cout << "Head default constructor called" << std::endl;
}

Head::Head( std::string name, Vec3 col, float initRad, Vec3 initRot, Vec3 sc, float rad, Vec3 rot, Vec3 tr) : Cube(name, col, initRad, initRot, sc, rad, rot, tr) {
//	std::cout << "Head parametric constructor called" << std::endl;
}
	
//Head::Head(Head const & src) {
////	std::cout << "Head copy constructor called" << std::endl;
//	*this = src;
//}

Head::~Head( void ) {
//	std::cout << "Head destructor called" << std::endl;
}

//Head &    	Head::operator=( Head const & src) {
//	this->_name = src.getName();
//	this->_sc = src.getSc();
//	this->_rot = src.getRot();
//	this->_rad = src.getRad();
//	this->_tr = src.getTr();
//	this->_col = src.getCol();
//	return (*this);
//}

//void				Head::draw( GLuint vao, Shader & shad ) const {
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

//std::ostream &		operator<<( std::ostream & o, Head const & rhs ) {
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
