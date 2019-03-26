#ifndef CUBETREE_HPP
# define CUBETREE_HPP

# include <iostream>
# include <math.h>

# include "Cube.hpp"
# include "Mat4.hpp"

class CubeTree {
private:
	int					_nbChild;

public:
	Cube					*	father;
	CubeTree				* childTree;

	CubeTree( void );
	CubeTree(Cube * father, Cube ** childs );
	~CubeTree( void );

	void				childAlloc( Cube ** ch );
	void				draw(Mat4 stack);

	int				getNbChild( void ) const;
	std::string		getFatherName( void ) const;
	std::string		getChildNames( void ) const;

};

std::ostream &		operator<<( std::ostream & o, CubeTree const & rhs );

#endif
