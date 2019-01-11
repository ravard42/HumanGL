#include "CubeTree.hpp"

CubeTree::CubeTree( void ) : father(NULL), child(NULL), childTree(NULL) {
	std::cout << "CubeTree default constructor called" << std::endl;
}

CubeTree::CubeTree( Cube * f, int childNumb ) : father(f)  {
	std::cout << "CubeTree parametric constructor called" << std::endl;
	child = (childNumb) ? new Cube[childNumb] : NULL;
	childTree = (childNumb) ? new CubeTree[childNumb] : NULL;
}
	
//CubeTree::CubeTree(CubeTree const & src) {
//	std::cout << "CubeTree copy constructor called" << std::endl;
//	*this = src;
//}

CubeTree::~CubeTree( void ) {
	if (child) {
		delete [] child;
		delete [] childTree;
	}
	std::cout << "CubeTree destructor called" << std::endl;
}

//CubeTree &    	CubeTree::operator=( CubeTree const & src) {

//	return (*this);
//}
//

Cube  &    	CubeTree::operator[]( int i ) {
	if (i >= 0 && i < childNumber)
		return (child[i]);
	else
		throw	-42;
}




//std::ostream &		operator<<( std::ostream & o, CubeTree const & rhs ) {
//
//	o << "<---CUBE TREE PRINTER---->" << std::endl;
//	return o;
//}
