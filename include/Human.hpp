#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <iostream>
# include <math.h>
# include "Vec3.hpp"

# include "Limb.hpp"

# define RIGHT 262
# define LEFT 263
# define BACK 264
# define FORWARD 265

# define HUMAN_NB_KEY 4


class Human {

private:
	static short const	_keyEntry[];
	char								_keyEvent;

	std::string		_name;
	Limb					_head; 
	Limb					_lArm;
	Limb					_rArm;
	Limb					_chest;
	Limb					_lLeg;
	Limb					_rLeg;
	
	void					_setLimbs( void );

public:

	Human( void );
	Human( std::string name );
//	Human(Human const & src);
	~Human( void );
//	Human &		operator=( Human const & src);

	std::string	getName( void ) const;
	Limb				getHead( void ) const;
	Limb				getLArm( void ) const;
	Limb				getRArm( void ) const;
	Limb				getChest( void ) const;
	Limb				getLLeg( void ) const;
	Limb				getRLeg( void ) const;

	void				draw( GLuint vao, Shader & shad ) const;
	void				setKeyEvent( int key );
	void				unsetKeyEvent( int key );
	void				newPos();
};

std::ostream &		operator<<( std::ostream & o, Human const & rhs );

#endif
