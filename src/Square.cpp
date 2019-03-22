#include "Square.hpp"

float const Square::data[] = {-0.5f, 0.0f, -0.5f, 0.5f, 0.0f, -0.5f, 0.5f, 0.0f, 0.5f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f};

GLuint			Square::vao_id = 0;
Shader	*		Square::shad = NULL;

Square::Square( void ) : _name("default"), _col(Vec3(1)) {
//	std::cout << "Square default constructor called" << std::endl;
}

Square::Square( std::string name, Vec3 col, Vec3 tr, float rad, Vec3 rot, Vec3 initTr, Vec3 sc, float initRad, Vec3 initRot ) :
		_name(name), _col(col), _tr(tr), _rad(rad), _rot(rot), _initTr(initTr), _sc(sc), _initRad(initRad), _initRot(initRot) {

//	std::cout << "Square parametric constructor called" << std::endl;
}
	
Square::Square(Square const & src) {
//	std::cout << "Square copy constructor called" << std::endl;
	*this = src;
}

Square::~Square( void ) {
//	std::cout << "Square destructor called" << std::endl;
}

Square &    	Square::operator=( Square const & src) {
	_name = src.getName();
	_col = src.getCol();
	_tr = src.getTr();
	_rad = src.getRad();
	_rot = src.getRot();
	_initTr = src.getInitTr();
	_sc = src.getSc();
	_initRad = src.getInitRad();
	_initRot = src.getInitRot();
	return (*this);
}

std::string		Square::getName( void ) const {
	return _name;
}

Vec3				Square::getCol( void ) const {
	return _col;
}

Vec3				Square::getTr( void ) const {
	return 	_tr;
}

float				Square::getRad( void ) const {
	return this->_rad;
}

Vec3				Square::getRot( void ) const {
	return this->_rot;
}

Vec3				Square::getInitTr( void ) const {
	return this->_initTr;
}

Vec3				Square::getSc( void ) const {
	return this->_sc;
}

float				Square::getInitRad( void ) const {
	return this->_initRad;
}

Vec3				Square::getInitRot( void ) const {
	return this->_initRot;
}
	
void				Square::setAttr( std::string name, Vec3 col, Vec3 tr, float rad, Vec3 rot, Vec3 initTr, Vec3 sc, float initRad, Vec3 initRot) {
	_name = name;
	_col = col;
	_tr = tr;
	_rad = rad;
	_rot = rot;
	_initTr = initTr;
	_sc = sc;
	_initRad = initRad;
	_initRot = initRot;
}

void				Square::move( float rad, Vec3 rot ) {
			_rad = rad;
			_rot = rot;
}

Mat4				Square::draw( Mat4 stack ) const {
		Mat4		tmp;
		Vec3		col = _col;

		Square::shad->setVec3("col", col);
		stack	*= Mat4("Translation", _tr)
					* Mat4("Rotation", _rad, _rot)\
					* Mat4("Translation", _initTr);
		tmp = stack * Mat4("Scale", _sc)\
						* Mat4("Rotation", _initRad, _initRot);
		Square::shad->setMat4("model", tmp);

		glBindVertexArray(Square::vao_id);
		glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
		glBindVertexArray(0);

		return stack;
}

std::ostream &		operator<<( std::ostream & o, Square const & rhs ) {

	o << "<---Square PRINTER--->" << std::endl;
	o << "name: " << rhs.getName() << std::endl;
	o << "color: " << rhs.getCol() << std::endl;
	o << "translate: " << rhs.getTr() << std::endl;
	o << "rotate: " << rhs.getRad() << " radians on " << rhs.getRot() << " axis" << std::endl;
	o << "initial translation: " << rhs.getInitTr() << std::endl;
	o << "scaling: " << rhs.getSc() << std::endl;
	o << "initial rotation: " << rhs.getInitRad() << " radians on " << rhs.getInitRot() << " axis" << std::endl;
	o << "<-------------------->"; 
	return o;
}
