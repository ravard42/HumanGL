#include "Cube.hpp"

float const Cube::data[] = {-0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f,  0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f};

GLuint			Cube::vao_id = 0;
Shader	*		Cube::shad = NULL;

Cube::Cube( void ) : _name("default"), _col(Vec3(1)) {
//	std::cout << "Cube default constructor called" << std::endl;
}

Cube::Cube( std::string name, Vec3 col, Vec3 tr, float rad, Vec3 rot, Vec3 initTr, Vec3 sc, float initRad, Vec3 initRot ) :
		_name(name), _col(col), _tr(tr), _rad(rad), _rot(rot), _initTr(initTr), _sc(sc), _initRad(initRad), _initRot(initRot) {
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
	_tr = src.getTr();
	_rad = src.getRad();
	_rot = src.getRot();
	_initTr = src.getInitTr();
	_sc = src.getSc();
	_initRad = src.getInitRad();
	_initRot = src.getInitRot();
	return (*this);
}

std::string		Cube::getName( void ) const {
	return _name;
}

Vec3				Cube::getCol( void ) const {
	return _col;
}

Vec3				Cube::getTr( void ) const {
	return 	_tr;
}

float				Cube::getRad( void ) const {
	return this->_rad;
}

Vec3				Cube::getRot( void ) const {
	return this->_rot;
}

Vec3				Cube::getInitTr( void ) const {
	return this->_initTr;
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

void				Cube::setAttr( std::string name, Vec3 col, Vec3 tr, float rad, Vec3 rot, Vec3 initTr, Vec3 sc, float initRad, Vec3 initRot) {
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

void				Cube::move( float rad, Vec3 rot ) {
			_rad = rad;
			_rot = rot;
}

Mat4				Cube::draw( Mat4 stack ) const {
		Mat4		tmp;
		Vec3		col = _col;
		
		Cube::shad->setVec3("col", col);
/*		stack	*= Mat4("Translation", _tr)
//					* Mat4("Rotation", _rad, _rot)\
//					* Mat4("Translation", _initTr)\
//					* Mat4("Scale", _sc)
//					* Mat4("Rotation", _initRad, _initRot);
		Cube::shad->setMat4("model", stack);*/
		stack	*= Mat4("Translation", _tr)
					* Mat4("Rotation", _rad, _rot)\
					* Mat4("Translation", _initTr);
		tmp = stack * Mat4("Scale", _sc)\
						* Mat4("Rotation", _initRad, _initRot);
		Cube::shad->setMat4("model", tmp);
	
		glBindVertexArray(Cube::vao_id);
		glDrawArrays(GL_TRIANGLES, 0, 3 * 12);
		glBindVertexArray(0);

		return stack;
}

std::ostream &		operator<<( std::ostream & o, Cube const & rhs ) {

	o << "<---Cube PRINTER--->" << std::endl;
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
