#ifndef HUMANSTATE_HPP
# define HUMANSTATE_HPP

# include <iostream>
# include <math.h>
//# include "Vec3.hpp"

//# include "Cube.hpp"

//# define FPS										30
# define CYCLE_FRAME_NB						300

# define UNMOVING 0
#	define WALK			1

class HumanState {

private:
	short		_frame;
	short		_prevState;
	short		_state;

public:

	HumanState( void );
//	HumanState( std::string name );
//	HumanState(HumanState const & src);
	~HumanState( void );
//	HumanState &		operator=( HumanState const & src);


	short	getFrame( void ) const;	

	void	newState( char keyEvent );
};

std::ostream &		operator<<( std::ostream & o, HumanState const & rhs );

#endif
