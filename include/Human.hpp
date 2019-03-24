#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>
# include <math.h>
# include "Vec3.hpp"

//# include "HumanState.hpp"
# include "Cube.hpp"
# include "CubeTree.hpp"

# define WALK_SPEED 				0.03f
# define ROT_SPEED 				0.12f
# define JUMP_LVL					0.0006


// KEY PRESS
# define		HUMAN_CAM			72
# define 	JUMP_KEY 			32

// KEY PRESS-RELEASE
# define 	PR_KEY_NB 			5
# define 	LEFT 					65
# define 	RIGHT 				68
# define 	FORWARD 				87
# define 	BACKWARD 			83
# define 	TURBO 				340

# define		NFAS					100 //Number of Frame in an Animation Sequence
# define 	UNMOVING 			0
# define 	WALK					1
# define 	RUN					2
# define		JUMP					3



typedef float (*fptr)(unsigned char frame, float lim, char param);

class Human {

private:
	static fptr const		_anim_func[2];
	static short const	_p_keyEntry[]; // press
	char						_p_keyEvent;
	static short const	_pr_keyEntry[]; //press-release
	char						_pr_keyEvent;

	std::string		_name;
	Vec3				_pos;
	float				_rad;
	int				_state[2];
	unsigned char	_fbf; //frame-by-frame (animation)
	
	Cube				_chest;
	Cube				_bandeSup;
	Cube				_bandeInf;
	Cube				_bag;
	Cube				_head;
	Cube				_capInf;
	Cube				_capSup;
	Cube				_upLArm;
	Cube				_upRArm;
	Cube				_lowLArm;
	Cube				_lowRArm;
	Cube				_upLLeg;
	Cube				_upRLeg;
	Cube				_lowLLeg;
	Cube				_lowRLeg;

	CubeTree	 	*	_tree;
	Cube			*	_tab[10];	

	void				_resetTab( void );	
	void				_initCubeTree( void );
	void				_newRot( void );
	void				_newPos( float save_dmouv = -1, float save_rad = 0.0);

public:

	Human( void );
	Human( std::string name );
//	Human(Human const & src);
	~Human( void );
//	Human &		operator=( Human const & src);

	char				get_p_keyEvent( void ) const;
	char				get_pr_keyEvent( void ) const;
	void				setKeyEvent( int key );
	void				unsetKeyEvent( int key );
	Mat4				setView( void );
	void				move_and_draw( void );

	void				printKeyEvents( void );
	void				printTree( void );
};

//std::ostream &		operator<<( std::ostream & o, Human const & rhs );

#endif
