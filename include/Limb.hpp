#ifndef LIMB_HPP
# define LIMB_HPP

# include <iostream>
# include <math.h>
# include "Vec3.hpp"

class Limb {

private:

	std::string				_name;
	Vec3							_sc;
	Vec3							_rot;
	float							_rad;
	Vec3							_tr;
	Vec3							_col;

public:
	
	static Vec3	const	color[];

	Limb( void );
	Limb( std::string name, Vec3 sc, Vec3 rot, float rad, Vec3 tr, Vec3 col);
	Limb(Limb const & src);
	~Limb( void );
	Limb &		operator=( Limb const & src);

	std::string	getName( void ) const;
	Vec3			getSc( void ) const;
	Vec3			getRot( void ) const;
	float			getRad( void ) const;
	Vec3			getTr( void ) const;
	Vec3			getCol( void ) const;
};

std::ostream &		operator<<( std::ostream & o, Limb const & rhs );

#endif
