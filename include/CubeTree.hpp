#ifndef CUBETREE_HPP
# define CUBETREE_HPP

# include <iostream>
# include <math.h>

# include "Cube.hpp"


class CubeTree {

public:
	Cube			*	father;
	int					childNumber;
	Cube			*	child;
	CubeTree	* childTree;

	CubeTree( void );
	CubeTree(Cube * father, int childNumber );
//	CubeTree(CubeTree const & src);
	~CubeTree( void );
//	CubeTree &		operator=( CubeTree const & src);
	Cube  &		operator[]( int i );


};

//std::ostream &		operator<<( std::ostream & o, CubeTree const & rhs );

#endif
