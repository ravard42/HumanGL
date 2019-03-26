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

	


Human::Human( void ) : _p_keyEvent(0), _pr_keyEvent(0), _name("default"), _pos(0, 0, 2), _rad(0), _state{}, _fbf(0), _tree(NULL), _tab{}
	{
}

Human::Human( std::string name ) : _p_keyEvent(0), _pr_keyEvent(0), _name(name), _pos(0, 0, 0), _rad(0), _state{}, _fbf(0), _tree(NULL), _tab{},_chest("chest", Vec3("yellow"), Vec3(0.0), 0.0, Vec3(0), Vec3(0), Vec3(0.2, 0.4, 0.1), 0.0, Vec3(0)),
	_bandeSup("bandeSup", Vec3(0.5), Vec3(0.0, 0.02, 0), 0.0, Vec3(0), Vec3(0), Vec3(0.21, 0.04, 0.11), 0.0, Vec3(0)),
	_bandeInf("bandeInf", Vec3(0.5), Vec3(0.0, -0.13, 0), 0.0, Vec3(0), Vec3(0), Vec3(0.21, 0.04, 0.11), 0.0, Vec3(0)),
	_bag("bag", Vec3("brown"), Vec3(0, 0, 0.07), 0.0, Vec3(0), Vec3(0), Vec3(0.18, 0.4, 0.04), 0.0, Vec3(0)),
	_head("head", Vec3("skin"), Vec3(0.0, 0.25, 0.0) , 0.0, Vec3(0), Vec3(0), Vec3(0.145, 0.12, 0.085), 0.0, Vec3(0)),
	_capInf("capInf", Vec3("darkRed"), Vec3(0.0, 0.069, -0.029) , 0.0, Vec3(0), Vec3(0), Vec3(0.145, 0.018, 0.144), 0.0, Vec3(0)),
	_capSup("capSup", Vec3("darkRed"), Vec3(0.0, 0.027, 0.0288) , 0.0, Vec3(0), Vec3(0), Vec3(0.14, 0.036, 0.0864), 0.0, Vec3(0)),
	_upLArm("upLArm", Vec3("darkPurple"), Vec3(-0.138, 0.18, 0.0) , 0.0, Vec3(0), Vec3(0, -0.1, 0), Vec3(0.072, 0.22, 0.072), 0.0, Vec3(0)),
	_upRArm("upRArm", Vec3("darkPurple"), Vec3(0.138, 0.18, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.1, 0.0), Vec3(0.072, 0.22, 0.072), 0.0, Vec3(0)),
	_lowLArm("lowLArm", Vec3("skin"), Vec3(0, -0.12, 0.0) , 0.0, Vec3(0), Vec3(0, -0.1, 0), Vec3(0.071, 0.22, 0.071), 0.0, Vec3(0)),
	_lowRArm("lowRArm", Vec3("skin"), Vec3(0, -0.12, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.1, 0.0), Vec3(0.071, 0.22, 0.071), 0.0, Vec3(0)),
	_upLLeg("upLLeg", Vec3("blue jeanz"), Vec3(-0.05, -0.21, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.1, 0.0), Vec3(0.09, 0.22, 0.09), 0.0, Vec3(0)),
	_upRLeg("upRLeg", Vec3("blue jeanz"), Vec3(0.05, -0.21, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.1, 0.0), Vec3(0.09, 0.22, 0.09), 0.0, Vec3(0)),
	_lowLLeg("lowLLeg", Vec3("blue jeanz"), Vec3(0, -0.15, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.105, 0.0), Vec3(0.09, 0.29, 0.09), 0.0, Vec3(0)),
	_lowRLeg("lowRLeg", Vec3("blue jeanz"), Vec3(0, -0.15, 0.0) , 0.0, Vec3(0), Vec3(0.0, -0.105, 0.0), Vec3(0.09, 0.29, 0.09), 0.0, Vec3(0)) {
	_initCubeTree();
	std::cout << "Human " << _name << " join the party!" << std::endl;
}
	
Human::~Human( void ) {
	if (_tree)
		delete _tree;
	std::cout << _name << " decided to leave the dance floor for now..." << std::endl;
}

char						Human::get_p_keyEvent( void ) const {
	return _p_keyEvent;
}

char						Human::get_pr_keyEvent( void ) const {
	return _pr_keyEvent;
}

void					Human::setKeyEvent( int key ) {
	if (key == Human::_p_keyEntry[0])
			_p_keyEvent = (_p_keyEvent & (char)pow(2, 0)) ? _p_keyEvent & ~(char)pow(2, 0) : _p_keyEvent | (char)pow(2, 0);
	if (_p_keyEvent & 1 && key == Human::_p_keyEntry[1])
			_p_keyEvent = (_p_keyEvent & (char)pow(2, 1)) ? _p_keyEvent : _p_keyEvent | (char)pow(2, 1);
	for (int i = 0; i < PR_KEY_NB; i++)
		if (key == Human::_pr_keyEntry[i])
			_pr_keyEvent |= (char)pow(2, i);
}

void			Human::unsetKeyEvent( int key ) {
	for (int i = 0; i < PR_KEY_NB; i++)
		if (key == Human::_pr_keyEntry[i])
			_pr_keyEvent &= ~(char)pow(2, i);
}

Mat4			Human::setView( void ) {
	Vec3	camPos = _pos + Vec3(0, 1.2, 5);
	Mat4	view;
	
	view = Mat4("Rotation", -M_PI/14, Vec3("x")).transpose() * Mat4("Translation", camPos * -1);
	return view;
}

void			Human::_newRot( void ) {
	float		drad = ((bool)(_pr_keyEvent & 1) - (bool)(_pr_keyEvent & 2));

	_rad += drad * ROT_SPEED;
}

void			Human::_newPos(float save_dmouv, float save_rad) {
	float		dmouv = ((bool)(this->_pr_keyEvent & 4) - (bool)(this->_pr_keyEvent & 8));
	float		rad = _rad;

	dmouv = (_pr_keyEvent & 16) ? 3 * WALK_SPEED * dmouv : WALK_SPEED * dmouv;

	if (save_dmouv != -1) {
		dmouv = save_dmouv;
		rad = save_rad;
	}
	_pos[0] -= dmouv * sin(rad);
	_pos[2] -= dmouv * cos(rad);
	_pos[0] = (fabs(_pos[0]) > 25.0) ? 25.0 * _pos[0] / fabs(_pos[0]) : _pos[0];
	_pos[2] = (fabs(_pos[2]) > 25.0) ? 25.0 * _pos[2] / fabs(_pos[2]) : _pos[2];
}


void					Human::_state_update( float * save_dmouv, float * save_rad ) {
	if (_state[0] != JUMP && _p_keyEvent & 2) {
		_state[1] = JUMP;
		_fbf = 0;
		*save_dmouv = ((bool)(this->_pr_keyEvent & 4) - (bool)(this->_pr_keyEvent & 8));
		*save_dmouv = (_pr_keyEvent & 16) ? 3 * WALK_SPEED * *save_dmouv : WALK_SPEED * *save_dmouv;
		*save_rad = _rad;
	}
	else if (_state[0] == JUMP) {
		_fbf += 2;
		if (_fbf >= NFAS) {
			_p_keyEvent &= ~2;
			_state[1] = _state[0] = _fbf = UNMOVING;
			*save_dmouv = -1;
			*save_rad = -1;
		}
	}
	else if ((_pr_keyEvent & (char)pow(2, 2) || _pr_keyEvent & (char)pow(2,3))) {
		_state[1] = (_pr_keyEvent & (char)pow(2, 4)) ? RUN : WALK;
		_fbf = (_fbf + _state[1]) % NFAS;
	}
	else
		_state[1] = UNMOVING;
	_state[0] = _state[1];
}

void					Human::_animate( void ) {
	if (_state[1] == JUMP) {
		_chest.move( _fbf / 98.0 * (4 * M_PI), Vec3(1.0, 0.0, 0.0).normalize());
		_pos[1] = 99 * JUMP_LVL * _fbf - JUMP_LVL * pow(_fbf, 2);
	}
	else {
		float radChest = (_state[1] == 2) ? -M_PI / 10 : 0;
		_chest.move( radChest, Vec3("x"));
		_upLArm.move(_anim_func[0](_fbf, M_PI / 6 * _state[1], 0), Vec3("x"));
		_upRArm.move(-1 * _anim_func[0](_fbf, M_PI / 6 * _state[1], 0), Vec3("x"));
		_upLLeg.move(-1 * _anim_func[0](_fbf, M_PI / 6 * _state[1], 0), Vec3("x"));
		_upRLeg.move(_anim_func[0](_fbf, M_PI / 6 * _state[1], 0), Vec3("x"));
		_lowLArm.move(_anim_func[1](_fbf, M_PI / 6 * _state[1], 0), Vec3("x"));
		_lowRArm.move(_anim_func[1](_fbf, M_PI / 6 * _state[1], 1), Vec3("x"));
		_lowLLeg.move(_anim_func[1](_fbf, -M_PI / 6 * _state[1], 2), Vec3("x"));
		_lowRLeg.move(_anim_func[1](_fbf, -M_PI / 6 * _state[1], 3), Vec3("x"));
	}
}

void					Human::draw( void ) {
		static float save_dmouv = -1;
		static float save_rad = -1;

		//printKeyEvents();

		if (_p_keyEvent & 1) {
			_state_update(&save_dmouv, &save_rad);
			_animate();
			_newRot();
			_newPos(save_dmouv, save_rad);
		}

		Mat4		stack = Mat4("Translation", _pos) * Mat4("Rotation", _rad, Vec3("y"));
		_tree->draw(stack);
}
		
void					Human::printKeyEvents( void ) {
		std::cout << "PRESS KEY EVENTS" << std::endl;
		for(int i = 0; i < 8; i++)
			std::cout << (bool)(_p_keyEvent & (char)pow(2, i));
		std::cout << std::endl;
		std::cout << "PRESS & RELEASE KEY EVENTS" << std::endl;
		for(int i = 0; i < 8; i++)
			std::cout << (bool)(_pr_keyEvent & (char)pow(2, i));
		std::cout << std::endl << std::endl;
}
	
void					Human::printTree( void ) {
		std::cout << *_tree << std::endl;	
}



float				inter(unsigned char inf, unsigned char sup, unsigned char frame) {
		if (frame >= inf && frame < sup)
			return 1;
		return 0;
}

// anim_0 <=> avant arriere arriere avant (0->lim, lim->0, 0->-lim, -lim->0)
float				anim_0( unsigned char f, float lim, char param ) {
	unsigned char	seq = NFAS / 4;
	unsigned char 	seq_f = f % seq;
	float ratio = (float)seq_f / seq;
	float		ret = inter(0, seq, f) * ratio * lim\
 						+ inter(seq, 2*seq, f) * lim * (1 - ratio)\
 						+ inter(2*seq, 3*seq, f) * (-lim) * ratio
 						+ inter(3*seq, 4*seq, f) * lim * (ratio - 1);
	(void)param;
	return (ret);
}


// anim_1 <=> avant arriere
float				anim_1( unsigned char f, float lim, char param) {

	unsigned char	seq = NFAS / 4;
	unsigned char 	seq_f = f % seq;
	float ratio = (float)seq_f / seq;
	float		ret;

	if (param == 0)
		ret = inter(0, seq, f) * lim * ratio\
 				+ inter(seq, 2*seq, f) * lim * (1 - ratio);
	else if (param == 1)
				ret =  inter(2*seq, 3*seq, f) * lim * ratio\
 				+ inter(3*seq, 4*seq, f) * lim * (1 - ratio);
	else if (param == 2)
		ret = inter(seq, 2*seq, f) * lim * ratio\
 				+ inter(2*seq, 3*seq, f) * lim * (1 - ratio);
	else if(param == 3)
		ret = inter(0, seq, f) * lim * (1 - ratio)\
 				+ inter(3*seq, 4*seq, f) * lim * ratio;
	return (ret);
}

fptr const		Human::_anim_func[2] = {anim_0, anim_1};
short const		Human::_p_keyEntry[] = {HUMAN_CAM, JUMP_KEY};
short const		Human::_pr_keyEntry[] = {LEFT, RIGHT, FORWARD, BACKWARD, TURBO};

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
