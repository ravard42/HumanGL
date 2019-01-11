#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>
# include <math.h>
# include "Vec3.hpp"

# include "HumanState.hpp"
# include "Cube.hpp"
# include "CubeTree.hpp"

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
	Vec3					_pos;
	HumanState		_state;
	
	Cube					_chest;
	Cube					_bag;
	Cube					_head;
	Cube					_cap;
	Cube					_upLArm;
	Cube					_upRArm;
	Cube					_lowLArm;
	Cube					_lowRArm;
	Cube					_upLLeg;
	Cube					_upRLeg;
	Cube					_lowLLeg;
	Cube					_lowRLeg;

//	CubeTree		*	_tree;	
	
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

//	void				printTree( void );
};

//std::ostream &		operator<<( std::ostream & o, Human const & rhs );

#endif
