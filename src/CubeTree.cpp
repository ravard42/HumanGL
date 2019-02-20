#include "CubeTree.hpp"

CubeTree::CubeTree( void ) : _nbChild(0), father(NULL), childTree(NULL) {
//	std::cout << "CubeTree default constructor called" << std::endl;
}

CubeTree::CubeTree( Cube * f, Cube ** ch ) : _nbChild(0), father(f), childTree(NULL) {
//	std::cout << "CubeTree parametric constructor called" << std::endl;
	childAlloc(ch);
}
	
//CubeTree::CubeTree(CubeTree const & src) {
//	std::cout << "CubeTree copy constructor called" << std::endl;
//	*this = src;
//}

CubeTree::~CubeTree( void ) {
	if (childTree)
		delete [] childTree;
//	std::cout << "CubeTree destructor called" << std::endl;
}

//CubeTree &    	CubeTree::operator=( CubeTree const & src) {

//	return (*this);
//}
//

//Cube  &    	CubeTree::operator[]( int i ) {
//	if (i >= 0 && i < childNumber)
//		return (child[i]);
//	else
//		throw	-42;
//}

void						CubeTree::childAlloc(Cube ** ch) {
	int		i = -1;

	if (ch && !childTree) {
		while (ch[++i])
			;
		_nbChild = i;
		childTree = (_nbChild) ? new CubeTree[_nbChild] : NULL;
		i = -1;
		while (++i < _nbChild)
			childTree[i].father = ch[i];
	}
}


void						CubeTree::draw( Mat4 stack ) {
	stack = father->draw(stack);
	int i = -1;
	while (++i < _nbChild)
		childTree[i].draw(stack);

}
	
int								CubeTree::getNbChild( void ) const {
	return _nbChild;
}

std::string				CubeTree::getFatherName( void ) const {
	return father->getName();
}

std::string				CubeTree::getChildNames( void ) const {
	std::string		ret;
	int						i = -1;

	while (++i < _nbChild)
		ret += childTree[i].father->getName() + " ";
	return ret;
}

std::ostream &		operator<<( std::ostream & o, CubeTree const & rhs ) {
	int		i = -1;

	o << "<---CUBETREE PRINTER---->" << std::endl;
	o << "father : " << rhs.getFatherName() << std::endl;
	o << "childs : " << rhs.getChildNames() << std::endl;
	while (++i < rhs.getNbChild())
		o << rhs.childTree[i];
	return o;
}
