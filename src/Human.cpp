#include "Human.hpp"

void					Human::_setLimbs( void ) {
//	_head = Cube("head", Vec3("green"), 0.0, Vec3("x"), Vec3(0.17, 0.17, 0.17), 0.0, Vec3("x"), Vec3(0, 0.32, 5.0));
//	
//
		_chest = Cube("chest", Vec3("yellow"), Vec3(0), 0.0, Vec3(0), Vec3(0), Vec3(0.3, 0.5, 0.3), 0.0, Vec3(0));
	
		_head = Cube("head", Vec3("skin"), Vec3(0.0, 0.3, 0.0) , 0.0, Vec3(0), Vec3(0), Vec3(0.2, 0.2, 0.2), 0.0, Vec3(0));
	
		//_lArm = Cube("lArm", Vec3("blue"), Vec3(-0.2, 0.26, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.3, 0.0), Vec3(0.1, 0.6, 0.1), 0.0, Vec3(0));
		_lArm = Cube("lArm", Vec3("blue"), Vec3(-0.2, 0.21, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.25, 0.0), Vec3(0.1, 0.6, 0.1), 0.0, Vec3(0));
		_rArm = Cube("rArm", Vec3("blue"), Vec3(0.2, 0.21, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.25, 0.0), Vec3(0.1, 0.6, 0.1), 0.0, Vec3(0));
		
		_lLeg = Cube("lLeg", Vec3("red"), Vec3(-0.1, -0.26, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.3, 0.0), Vec3(0.1, 0.6, 0.1), 0.0, Vec3(0));
		_rLeg = Cube("rLeg", Vec3("red"), Vec3(0.1, -0.26, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.3, 0.0), Vec3(0.1, 0.6, 0.1), 0.0, Vec3(0));

	
//	_lLeg = Cube("lLeg", Vec3("red"), 0.0, Vec3("x"), Vec3(0.09, 0.5, 0.09), 0.0, Vec3("x"), Vec3(-0.07, -0.5, 5.0));
//	_rLeg = Cube("rLeg", Vec3("red"), 0.0, Vec3("x"), Vec3(0.09, 0.5, 0.09), 0.0, Vec3("x"), Vec3(0.07, -0.5, 5.0));
}

void			Human::_newPos( void ) {
	Vec3		mouv((float)((bool)(this->_keyEvent & 1) - (bool)(this->_keyEvent & 2))
					, 0
					, (float)((bool)(this->_keyEvent & 4) - (bool)(this->_keyEvent & 8)));
	
	_pos[0] = _pos[0] + mouv[0] * 0.05;
	_pos[2] = _pos[2] + mouv[2] * 0.05;
//	this->_speed = (this->_keyEvent & 64) ? RUSH * SPEED : SPEED;
}


Human::Human( void ) : _keyEvent(0), _name("default"), _pos(0, 0, 2) {
	std::cout << "Human default constructor called" << std::endl;
	_setLimbs();
}

Human::Human( std::string name ) : _keyEvent(0), _name(name), _pos(0, 0, 2) {
	std::cout << "Human " << _name << " join the party!" << std::endl;
	_setLimbs();
}
	
//Human::Human(Human const & src) {
//	std::cout << "Human copy constructor called" << std::endl;
//	*this = src;
//}

Human::~Human( void ) {
	std::cout << _name << " decided to leave the dance floor for now..." << std::endl;
}

//Human &    	Human::operator=( Human const & src) {

//	return (*this);
//}
//


char						Human::getKeyEvent( void ) const {
	return _keyEvent;
}

void					Human::setKeyEvent( int key ) {
	int		i = -1;

	while (++i < HUMAN_NB_KEY) 
		if (key == Human::_keyEntry[i])
			_keyEvent |= (char)pow(2, i);
	if (key == Human::_keyEntry[4])
			_keyEvent = (_keyEvent & (char)pow(2, 4)) ? _keyEvent & ~(char)pow(2, 4) : _keyEvent | (char)pow(2, 4);
}

void			Human::unsetKeyEvent( int key ) {
	int		i = -1;

	while (++i < HUMAN_NB_KEY)
		if (key == Human::_keyEntry[i])
			this->_keyEvent &= ~(char)pow(2, i);
}


Mat4			Human::setView( void ) {
	Vec3	camPos = _pos + Vec3(0, 1.2, 5);
	Mat4	view;
	
	view = Mat4("Rotation", -M_PI/12, Vec3("x")).transpose() * Mat4("Translation", camPos * -1);
	return view;
}

void					Human::draw( GLuint vao, Shader & shad ) {
	Mat4		stack;

	_newPos();
	_state.newState(_keyEvent);
//	std::cout << _state << std::endl;

	_lArm.move(&_state);
	_rArm.move(&_state);
	_chest.move(&_state);

	stack = Mat4("Translation", _pos);

	this->_head.draw(vao, shad, stack);
	this->_chest.draw(vao, shad, stack);
	this->_lArm.draw(vao, shad, stack);
	this->_rArm.draw(vao, shad, stack);
	this->_lLeg.draw(vao, shad, stack);
	this->_rLeg.draw(vao, shad, stack);
}

short const		Human::_keyEntry[] = {RIGHT, LEFT, BACK, FORWARD, HUMAN_CAM};

//std::ostream &		operator<<( std::ostream & o, Human const & rhs ) {
//
//	o << "<---HUMAN PRINTER---->" << std::endl;
//	o << "name: " << rhs.getName() << std::endl;
//	o << "head: "	<< rhs.getHead() << std::endl;
//	o << "lArm: "	<< rhs.getLArm() << std::endl;
//	o << "rArm: "	<< rhs.getRArm() << std::endl;
//	o << "chest: "	<< rhs.getChest() << std::endl;
//	o << "lLeg: "	<< rhs.getLLeg() << std::endl;
//	o << "rLeg: "	<< rhs.getRLeg() << std::endl;
//	return o;
//}
