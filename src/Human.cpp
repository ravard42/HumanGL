#include "Human.hpp"

//
//		_tree[0] = &_head;
//		_tree[1] = &_lArm;
//		_tree[2] = &_rArm;
//		_tree[3] = &_lLeg;
//		_tree[4] = &_rLeg;
	
void			Human::_newPos( void ) {
	Vec3		mouv((float)((bool)(this->_keyEvent & 1) - (bool)(this->_keyEvent & 2))
					, 0
					, (float)((bool)(this->_keyEvent & 4) - (bool)(this->_keyEvent & 8)));
	
	_pos[0] = _pos[0] + mouv[0] * 0.05;
	_pos[2] = _pos[2] + mouv[2] * 0.05;
//	this->_speed = (this->_keyEvent & 64) ? RUSH * SPEED : SPEED;
}


Human::Human( void ) : _keyEvent(0), _name("default"), _pos(0, 0, 2)
	{
	std::cout << "Human default constructor called" << std::endl;
}

Human::Human( std::string name ) : _keyEvent(0), _name(name), _pos(0, 0, 2),
		_chest("chest", Vec3("yellow"), Vec3(0.0), 0.0, Vec3(0), Vec3(0), Vec3(0.3, 0.5, 0.15), 0.0, Vec3(0)),
		_bag("bag", Vec3("brown"), Vec3(0, 0, 0.12), 0.0, Vec3(0), Vec3(0), Vec3(0.3, 0.5, 0.07), 0.0, Vec3(0)),
		_head("head", Vec3("skin"), Vec3(0.0, 0.34, 0.0) , 0.0, Vec3(0), Vec3(0), Vec3(0.17, 0.17, 0.17), 0.0, Vec3(0)),
		_cap("cap", Vec3("darkRed"), Vec3(0.0, 0.5, 0.0) , 0.0, Vec3(0), Vec3(0), Vec3(0.03, 0.20, 0.15), 0.0, Vec3(0)),
		_upLArm("upLArm", Vec3("blue"), Vec3(-0.2, 0.24, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.1, 0.0), Vec3(0.1, 0.22, 0.1), 0.0, Vec3(0)),
		_upRArm("upRArm", Vec3("blue"), Vec3(0.2, 0.24, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.1, 0.0), Vec3(0.1, 0.22, 0.1), 0.0, Vec3(0)),
		_lowLArm("lowLArm", Vec3("darkPurple"), Vec3(-0.2, 0.005, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.125, 0.0), Vec3(0.1, 0.29, 0.1), 0.0, Vec3(0)),
		_lowRArm("lowRArm", Vec3("darkPurple"), Vec3(0.2, 0.005, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.125, 0.0), Vec3(0.1, 0.29, 0.1), 0.0, Vec3(0)),
		_upLLeg("upLLeg", Vec3(0.3), Vec3(-0.1, -0.27, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.1, 0.0), Vec3(0.1, 0.22, 0.1), 0.0, Vec3(0)),
		_upRLeg("upRLeg", Vec3(0.3), Vec3(0.1, -0.27, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.1, 0.0), Vec3(0.1, 0.22, 0.1), 0.0, Vec3(0)),
		_lowLLeg("lowLLeg", Vec3("orange"), Vec3(-0.1, -0.51, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.125, 0.0), Vec3(0.1, 0.29, 0.1), 0.0, Vec3(0)),
		_lowRLeg("lowRLeg", Vec3("orange"), Vec3(0.1, -0.51, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.125, 0.0), Vec3(0.1, 0.29, 0.1), 0.0, Vec3(0)) 
	{
	std::cout << "Human " << _name << " join the party!" << std::endl;
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

//		_upLArm.move(&_state);
//		_upRArm.move(&_state);
//		_lowRArm.move(&_state);
//		_chest.move(&_state);
	
		stack = Mat4("Translation", _pos);
//
		_chest.draw(vao, shad, stack);
		_bag.draw(vao, shad, stack);
		_head.draw(vao, shad, stack);
		_cap.draw(vao, shad, stack);
		_upLArm.draw(vao, shad, stack);
		_upRArm.draw(vao, shad, stack);
		_upLLeg.draw(vao, shad, stack);
		_upRLeg.draw(vao, shad, stack);
		_lowLArm.draw(vao, shad, stack);
		_lowRArm.draw(vao, shad, stack);
		_lowLLeg.draw(vao, shad, stack);
		_lowRLeg.draw(vao, shad, stack);
}
	
//void					Human::printTree( void ) {
//	int		i = -1;
//
//	while ( (*_tree)[++i])
//		std::cout << (*_tree)[i]->getName() << std::endl;
//
//}

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
