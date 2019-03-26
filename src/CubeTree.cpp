#include "CubeTree.hpp"

CubeTree::CubeTree( void ) : _nbChild(0), father(NULL), childTree(NULL) {
}

CubeTree::CubeTree( Cube * f, Cube ** ch ) : father(f), childTree(NULL) {
	childAlloc(ch);
}
	
CubeTree::~CubeTree( void ) {
	if (childTree)
		delete [] childTree;
}

void				CubeTree::childAlloc(Cube ** ch) {
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

void				CubeTree::draw( Mat4 stack ) {
	stack = father->draw(stack);
	int i = -1;
	while (++i < _nbChild)
		childTree[i].draw(stack);
}
	
int				CubeTree::getNbChild( void ) const {
	return _nbChild;
}

std::string		CubeTree::getFatherName( void ) const {
	return father->getName();
}

std::string		CubeTree::getChildNames( void ) const {
	std::string		ret;
	int				i = -1;

	while (++i < _nbChild)
		ret += childTree[i].father->getName() + " ";
	return ret;
}

std::ostream &	operator<<( std::ostream & o, CubeTree const & rhs ) {
	int		i = -1;

	o << "<---CUBETREE PRINTER---->" << std::endl;
	o << "father : " << rhs.getFatherName() << std::endl;
	o << "childs : " << rhs.getChildNames() << std::endl;
	o << "<----------------------->" << std::endl;
	while (++i < rhs.getNbChild())
		o << rhs.childTree[i];
	return o;
}
