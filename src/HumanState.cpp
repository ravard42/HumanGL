﻿#include "HumanState.hpp"


HumanState::HumanState( void ) : _frame(0), _prevState(0), _state(0) {
	std::cout << "HumanState default constructor called" << std::endl;
}

//HumanState::HumanState( std::string name ) :  {
//	std::cout << "HumanState " << _name << " join the party!" << std::endl;
//	_setLimbs();
//}
	
//HumanState::HumanState(HumanState const & src) {
//	std::cout << "HumanState copy constructor called" << std::endl;
//	*this = src;
//}

HumanState::~HumanState( void ) {
	std::cout << "HumanState destructor called" << std::endl;
}


//HumanState &    HumanState::operator=( HumanState const & src) {

//	return (*this);
//}
//


short							HumanState::getFrame( void ) const {
	return _frame;
}

void							HumanState::newState( char keyEvent ) {

	if (keyEvent & (char)pow(2, 6))
	{
		_state = WALK;
		_frame = (_prevState == UNMOVING) ? 0 : (_frame + 1) % CYCLE_FRAME_NB;
		_prevState = WALK;
	}
	else {
		_state = UNMOVING;
		_frame = 0;
		_prevState = UNMOVING;
	}

}


std::ostream &		operator<<( std::ostream & o, HumanState const & rhs ) {

	o << "<---STATE PRINTER---->" << std::endl;
	o << "frame number : " << (int)rhs.getFrame() << std::endl;

	return o;
}
