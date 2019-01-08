#ifndef HUMANSTATE_HPP
# define HUMANSTATE_HPP

# include <iostream>
# include <math.h>
//# include "Vec3.hpp"

//# include "Cube.hpp"

//# define FPS										30
# define CYCLE_FRAME_NB					60

# define UNMOVING 0
#	define WALK			1

class HumanState {

private:
	char		_frame;
	char		_prevState;
	char		_state;

public:

	HumanState( void );
//	HumanState( std::string name );
//	HumanState(HumanState const & src);
	~HumanState( void );
//	HumanState &		operator=( HumanState const & src);


	char	getFrame( void ) const;	

	void	newState( char keyEvent );
};

std::ostream &		operator<<( std::ostream & o, HumanState const & rhs );

#endif
