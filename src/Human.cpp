#include "Human.hpp"

//
//		_tree[0] = &_head;
//		_tree[1] = &_lArm;
//		_tree[2] = &_rArm;
//		_tree[3] = &_lLeg;
//		_tree[4] = &_rLeg;

void			Human::_resetTab( void ) {
	int			i =	 -1;

	while (++i < 9)
		_tab[i] = NULL;
}

void			Human::_initCubeTree( void ) {
	_resetTab();
	_tab[0] = &_head;
	_tab[1] = &_bag;
	_tab[2] = &_upLArm;
	_tab[3] = &_upRArm;
	_tab[4] = &_upLLeg;
	_tab[5] = &_upRLeg;	
	_tree = new CubeTree(&_chest, _tab);

	_resetTab();
	_tab[0] = &_hair;
	_tree->childTree[0].childAlloc(_tab);
	_tab[0] = &_lowLArm;;
	_tree->childTree[1].childAlloc(_tab);
	_tab[0] = &_lowRArm;;
	_tree->childTree[2].childAlloc(_tab);
	_tab[0] = &_lowLLeg;;
	_tree->childTree[3].childAlloc(_tab);
	_tab[0] = &_lowRLeg;;
	_tree->childTree[4].childAlloc(_tab);
	
	
}

	


Human::Human( void ) : _keyEvent(0), _name("default"), _pos(0, 0, 2), _rad(0)
	{
	std::cout << "Human default constructor called" << std::endl;
}

Human::Human( std::string name ) : _keyEvent(0), _name(name), _pos(0, 0, 2), _rad(0),
		_chest("chest", Vec3("yellow"), Vec3(0.0), 0.0, Vec3(0), Vec3(0), Vec3(0.3, 0.5, 0.15), 0.0, Vec3(0)),
		_bag("bag", Vec3("brown"), Vec3(0, 0, 0.12), 0.0, Vec3(0), Vec3(0), Vec3(0.3, 0.5, 0.07), 0.0, Vec3(0)),
		_head("head", Vec3("skin"), Vec3(0.0, 0.34, 0.0) , 0.0, Vec3(0), Vec3(0), Vec3(0.17, 0.17, 0.17), 0.0, Vec3(0)),
		_hair("hair", Vec3("darkRed"), Vec3(0.0, 0.5, 0.0) , 0.0, Vec3(0), Vec3(0), Vec3(0.03, 0.20, 0.15), 0.0, Vec3(0)),
		_upLArm("upLArm", Vec3("blue"), Vec3(-0.2, 0.24, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.1, 0.0), Vec3(0.1, 0.22, 0.1), 0.0, Vec3(0)),
		_upRArm("upRArm", Vec3("blue"), Vec3(0.2, 0.24, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.1, 0.0), Vec3(0.1, 0.22, 0.1), 0.0, Vec3(0)),
		_lowLArm("lowLArm", Vec3("darkPurple"), Vec3(-0.2, 0.005, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.125, 0.0), Vec3(0.1, 0.29, 0.1), 0.0, Vec3(0)),
		_lowRArm("lowRArm", Vec3("darkPurple"), Vec3(0.2, 0.005, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.125, 0.0), Vec3(0.1, 0.29, 0.1), 0.0, Vec3(0)),
		_upLLeg("upLLeg", Vec3(0.3), Vec3(-0.1, -0.27, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.1, 0.0), Vec3(0.1, 0.22, 0.1), 0.0, Vec3(0)),
		_upRLeg("upRLeg", Vec3(0.3), Vec3(0.1, -0.27, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.1, 0.0), Vec3(0.1, 0.22, 0.1), 0.0, Vec3(0)),
		_lowLLeg("lowLLeg", Vec3("orange"), Vec3(-0.1, -0.51, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.125, 0.0), Vec3(0.1, 0.29, 0.1), 0.0, Vec3(0)),
		_lowRLeg("lowRLeg", Vec3("orange"), Vec3(0.1, -0.51, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.125, 0.0), Vec3(0.1, 0.29, 0.1), 0.0, Vec3(0)) {
		_initCubeTree();
		std::cout << "Human " << _name << " join the party!" << std::endl;
}
	
//Human::Human(Human const & src) {
//	std::cout << "Human copy constructor called" << std::endl;
//	*this = src;
//}

Human::~Human( void ) {
	if (_tree)
		delete _tree;
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
	if (key == Human::_keyEntry[HUMAN_NB_KEY])
			_keyEvent = (_keyEvent & (char)pow(2, 5)) ? _keyEvent & ~(char)pow(2, 5) : _keyEvent | (char)pow(2, 5);
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

void			Human::_newRot( void ) {
	float		drad = ((bool)(this->_keyEvent & 1) - (bool)(this->_keyEvent & 2));

	_rad -= drad * 0.05;
}

void			Human::_newPos( void ) {
	float		dmouv = ((bool)(this->_keyEvent & 4) - (bool)(this->_keyEvent & 8));
	float		speed = 0.05;

	speed = (this->_keyEvent & 16) ? 3 * speed : speed;
	_pos[0] += dmouv * speed * sin(_rad);
	_pos[2] += dmouv * speed * cos(_rad);
}

void					Human::moveNdraw( void ) {
	Mat4		stack;

		if (_keyEvent & (char)pow(2, 5)) {
			_newRot();
			_newPos();
		}

		_state.newState(_keyEvent);

//	std::cout << _state << std::endl;

//		_upLArm.move(&_state);
//		_upRArm.move(&_state);
//		_lowRArm.move(&_state);
//		_chest.move(&_state);
	
		stack = Mat4("Translation", _pos) * Mat4("Rotation", _rad, Vec3("y"));
	//	stack = Mat4("Translation", _pos);
	//	stack = Mat4("Rotation", _rad, Vec3("y"));

		_tree->draw(stack);
}
	
void					Human::printTree( void ) {

		std::cout << *_tree << std::endl;	

}

short const		Human::_keyEntry[] = {RIGHT, LEFT, BACK, FORWARD, TURBO, HUMAN_CAM};

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
