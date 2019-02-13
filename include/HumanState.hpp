#ifndef HUMANSTATE_HPP
# define HUMANSTATE_HPP

# include <iostream>
# include <math.h>
//# include "Vec3.hpp"

//# include "Cube.hpp"

//# define FPS										30
# define CYCLE_FRAME_NB						120


# define UNMOVING -1
#	define WALK			0
#	define RUN			1

class HumanState {

private:
	short		_frame;
	char		_prevState;
	char		_state;

public:

	HumanState( void );
//	HumanState( std::string name );
//	HumanState(HumanState const & src);
	~HumanState( void );
//	HumanState &		operator=( HumanState const & src);


	short	getFrame( void ) const;	
	char	getState( void ) const;	

	void	newState( char keyEvent );
};

std::ostream &		operator<<( std::ostream & o, HumanState const & rhs );

#endif
