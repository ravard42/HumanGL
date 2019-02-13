#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>
# include <math.h>
# include "Vec3.hpp"

# include "HumanState.hpp"
# include "Cube.hpp"
# include "CubeTree.hpp"

# define 	RIGHT 				68
# define 	LEFT 					65
# define 	BACK 					83
# define 	FORWARD 			87
# define 	TURBO 				340
# define	HUMAN_CAM			72
# define	WALK_EVENT		77

# define HUMAN_NB_KEY 7

typedef float (*fptr)(short frame);

class Human {

private:
	static fptr const		_radFunc[2][2];
	static Vec3 const		_rotFunc[2][2];
	static short const	_keyEntry[];
	char								_keyEvent;

	std::string		_name;
	Vec3					_pos;
	float					_rad;
	HumanState		_state;
	
	Cube					_chest;
	Cube					_bandeSup;
	Cube					_bandeInf;
	Cube					_bag;
	Cube					_head;
	Cube					_capInf;
	Cube					_capSup;
	Cube					_upLArm;
	Cube					_upRArm;
	Cube					_lowLArm;
	Cube					_lowRArm;
	Cube					_upLLeg;
	Cube					_upRLeg;
	Cube					_lowLLeg;
	Cube					_lowRLeg;

	CubeTree	 *	_tree;
	Cube			*		_tab[10];	

	void					_resetTab( void );	
	void					_initCubeTree( void );
	void					_newRot( void );
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
	void				move_and_draw( void );

	void				printTree( void );
};

//std::ostream &		operator<<( std::ostream & o, Human const & rhs );

#endif
