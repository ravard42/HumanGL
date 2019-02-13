#include "Human.hpp"

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
	_tab[6] = &_bandeSup;
	_tab[7] = &_bandeInf;	
	_tree = new CubeTree(&_chest, _tab);

	_resetTab();
	_tab[0] = &_capInf;
	_tree->childTree[0].childAlloc(_tab);
	_tab[0] = &_lowLArm;
	_tree->childTree[2].childAlloc(_tab);
	_tab[0] = &_lowRArm;
	_tree->childTree[3].childAlloc(_tab);
	_tab[0] = &_lowLLeg;
	_tree->childTree[4].childAlloc(_tab);
	_tab[0] = &_lowRLeg;
	_tree->childTree[5].childAlloc(_tab);
	
	_tab[0] = &_capSup;
	_tree->childTree[0].childTree[0].childAlloc(_tab);
}

	


Human::Human( void ) : _keyEvent(0), _name("default"), _pos(0, 0, 2), _rad(0)
	{
	std::cout << "Human default constructor called" << std::endl;
}

Human::Human( std::string name ) : _keyEvent(0), _name(name), _pos(0, 0, 2), _rad(0),
		_chest("chest", Vec3("yellow"), Vec3(0.0), 0.0, Vec3(0), Vec3(0), Vec3(0.2, 0.4, 0.1), 0.0, Vec3(0)),
		_bandeSup("bandeSup", Vec3(0.5), Vec3(0.0, 0.02, 0), 0.0, Vec3(0), Vec3(0), Vec3(0.21, 0.04, 0.11), 0.0, Vec3(0)),
		_bandeInf("bandeInf", Vec3(0.5), Vec3(0.0, -0.13, 0), 0.0, Vec3(0), Vec3(0), Vec3(0.21, 0.04, 0.11), 0.0, Vec3(0)),
		_bag("bag", Vec3("brown"), Vec3(0, 0, 0.07), 0.0, Vec3(0), Vec3(0), Vec3(0.18, 0.4, 0.04), 0.0, Vec3(0)),
		_head("head", Vec3("skin"), Vec3(0.0, 0.25, 0.0) , 0.0, Vec3(0), Vec3(0), Vec3(0.145, 0.12, 0.085), 0.0, Vec3(0)),
		_capInf("capInf", Vec3("darkRed"), Vec3(0.0, 0.069, -0.029) , 0.0, Vec3(0), Vec3(0), Vec3(0.145, 0.018, 0.144), 0.0, Vec3(0)),
		_capSup("capSup", Vec3("darkRed"), Vec3(0.0, 0.027, 0.0288) , 0.0, Vec3(0), Vec3(0), Vec3(0.14, 0.036, 0.0864), 0.0, Vec3(0)),
		_upLArm("upLArm", Vec3("darkPurple"), Vec3(-0.138, 0.18, 0.0) , 0.0, Vec3(0), Vec3(0, -0.1, 0), Vec3(0.072, 0.22, 0.072), 0.0, Vec3(0)),
		_upRArm("upRArm", Vec3("darkPurple"), Vec3(0.138, 0.18, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.1, 0.0), Vec3(0.072, 0.22, 0.072), 0.0, Vec3(0)),
		_lowLArm("lowLArm", Vec3("skin"), Vec3(0, -0.12, 0.0) , 0.0, Vec3(0), Vec3(0, -0.1, 0), Vec3(0.072, 0.22, 0.072), 0.0, Vec3(0)),
		_lowRArm("lowRArm", Vec3("skin"), Vec3(0, -0.12, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.1, 0.0), Vec3(0.072, 0.22, 0.072), 0.0, Vec3(0)),
		_upLLeg("upLLeg", Vec3("blue jeanz"), Vec3(-0.05, -0.21, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.1, 0.0), Vec3(0.09, 0.22, 0.09), 0.0, Vec3(0)),
		_upRLeg("upRLeg", Vec3("blue jeanz"), Vec3(0.05, -0.21, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.1, 0.0), Vec3(0.09, 0.22, 0.09), 0.0, Vec3(0)),
		_lowLLeg("lowLLeg", Vec3("blue jeanz"), Vec3(0, -0.15, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.105, 0.0), Vec3(0.09, 0.29, 0.09), 0.0, Vec3(0)),
		_lowRLeg("lowRLeg", Vec3("blue jeanz"), Vec3(0, -0.15, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.105, 0.0), Vec3(0.09, 0.29, 0.09), 0.0, Vec3(0)) {
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
	int		i = 0;

	if (key == Human::_keyEntry[0])
			_keyEvent = (_keyEvent & (char)pow(2, 0)) ? _keyEvent & ~(char)pow(2, 0) : _keyEvent | (char)pow(2, 0);
	while (++i < HUMAN_NB_KEY) 
		if (key == Human::_keyEntry[i])
			_keyEvent |= (char)pow(2, i);
}

void			Human::unsetKeyEvent( int key ) {
	int		i = 0;

	while (++i < HUMAN_NB_KEY)
		if (key == Human::_keyEntry[i])
			this->_keyEvent &= ~(char)pow(2, i);
}


Mat4			Human::setView( void ) {
	Vec3	camPos = _pos + Vec3(0, 1.2, 5);
	Mat4	view;
	
	view = Mat4("Rotation", -M_PI/14, Vec3("x")).transpose() * Mat4("Translation", camPos * -1);
	return view;
}

void			Human::_newRot( void ) {
	float		drad = ((bool)(this->_keyEvent & 2) - (bool)(this->_keyEvent & 4));

	_rad -= drad * 0.05;
}

void			Human::_newPos( void ) {
	float		dmouv = ((bool)(this->_keyEvent & 8) - (bool)(this->_keyEvent & 16));
	float		speed = 0.05;

	speed = (this->_keyEvent & 32) ? 3 * speed : speed;
	_pos[0] += dmouv * speed * sin(_rad);
	_pos[2] += dmouv * speed * cos(_rad);
}

void					Human::move_and_draw( void ) {
	Mat4		stack;

		if (_keyEvent & (char)pow(2, 0)) {
			_newRot();
			_newPos();
		}

		_state.newState(_keyEvent);
//	std::cout << _state << std::endl;

		_radFunc[0][0](0);
		_radFunc[0][1](0);
		_radFunc[1][0](0);
		_radFunc[1][1](0);
	
		short		f = _state.getFrame();
		char		s = _state.getState();

		if (s != -1) {
			_upLArm.move(_radFunc[(int)s][0](f), _rotFunc[(int)s][0]);
			_upRArm.move(_radFunc[(int)s][1](f), _rotFunc[(int)s][0]);
			_upLLeg.move(_radFunc[(int)s][1](f), _rotFunc[(int)s][0]);
			_upRLeg.move(_radFunc[(int)s][0](f), _rotFunc[(int)s][0]);

		}

//	_upRArm.move(&_state);
//	_lowRArm.move(&_state);
//	_chest.move(&_state);
	
		stack = Mat4("Translation", _pos) * Mat4("Rotation", _rad, Vec3("y"));
	//	stack = Mat4("Translation", _pos);
	//	stack = Mat4("Rotation", _rad, Vec3("y"));

		_tree->draw(stack);
}
	
void					Human::printTree( void ) {

		std::cout << *_tree << std::endl;	

}

short const		Human::_keyEntry[] = {HUMAN_CAM, RIGHT, LEFT, BACK, FORWARD, TURBO, WALK_EVENT};


float					inter(short inf, short sup, short frame) {
		if (frame >= inf && frame <= sup)
			return 1;
		return 0;
}

float					walk_0( short f ) {
	float		ret = inter(0, 30, f) * (float)f / 30 * M_PI / 6\
 								+ inter(31, 90, f) * (M_PI / 6 - ((float)f - 30) / 60 * M_PI / 3)\
 								+ inter(91, 120, f) * (-M_PI / 6 + ((float)f - 90) / 30 * M_PI / 6);
	
	return (ret);
}

float					walk_1( short f ) {
	float		ret = inter(0, 30, f) * (float)f / 30 * M_PI / 6\
 								+ inter(31, 90, f) * (M_PI / 6 - ((float)f - 30) / 60 * M_PI / 3)\
 								+ inter(91, 120, f) * (-M_PI / 6 + ((float)f - 90) / 30 * M_PI / 6);
	return (-ret);
}

float					run_0( short f ) {
	(void)f;
	std::cout << "run_0" << std::endl;
	return 0.0;
}

float					run_1( short f ) {
	(void)f;
	std::cout << "run_1" << std::endl;
	return 1.0;
}

fptr const		Human::_radFunc[2][2] = {{walk_0, walk_1},{run_0, run_1}};
Vec3 const		Human::_rotFunc[2][2] = {{Vec3("x")}};

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
