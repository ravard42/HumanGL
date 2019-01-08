#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>
# include <math.h>
# include "Vec3.hpp"

# include "Cube.hpp"
# include "HumanState.hpp"

# define 	RIGHT 		262
# define 	LEFT 			263
# define 	BACK 			264
# define 	FORWARD 	265
# define	HUMAN_CAM	72

# define HUMAN_NB_KEY 4


class Human {

private:
	static short const	_keyEntry[];
	char								_keyEvent;

	std::string		_name;
	Cube					_chest;
	Cube					_head; 
	Cube					_rArm; 
	Cube					_lArm; 
	Cube					_rLeg; 
	Cube					_lLeg; 
	Vec3					_pos;

	HumanState		_state;
	
	void					_setLimbs( void );
	void					_newPos( void );

public:

	Human( void );
	Human( std::string name );
//	Human(Human const & src);
	~Human( void );
//	Human &		operator=( Human const & src);

	char				getKeyEvent( void ) const;
	void				setKeyEvent( int key );
	void				unsetKeyEvent( int key );
	Mat4				setView( void );
	void				draw( GLuint vao, Shader & shad );
};

//std::ostream &		operator<<( std::ostream & o, Human const & rhs );

#endif
