#include "Human.hpp"

Human::Human( void ) : _name("default"){
	std::cout << "Human default constructor called" << std::endl;
	_head = Limb("head", Vec3(0.17, 0.17, 0.17), Vec3(), 0.0f, Vec3(0, 0.32, 0.0), Limb::color[3]);
	_lArm = Limb("left arm", Vec3(0.07, 0.5, 0.07), Vec3("z"),  -M_PI / 14, Vec3(-0.18f, 0.0f, 0.0f), Limb::color[2]);
	_rArm = Limb("right arm", Vec3(0.07, 0.5, 0.07), Vec3("z"), M_PI / 14, Vec3(0.18f, 0.0f, 0.0f), Limb::color[2]);
	_chest = Limb("chest", Vec3(0.23, 0.5, 0.21), Vec3(), 0.0f, Vec3("0"), Limb::color[1]);
	_lLeg = Limb("left leg", Vec3(0.09, 0.5, 0.09), Vec3(), 0.0f, Vec3(-0.07f, -0.5f, 0.0f), Limb::color[0]);
	_rLeg = Limb("right leg", Vec3(0.09, 0.5, 0.09), Vec3(), 0.0f, Vec3(0.07f, -0.5f, 0.0f), Limb::color[0]);

}

Human::Human( std::string name ) : _name(name) {
	std::cout << "Human " << _name << " join the party!" << std::endl;
	_head = Limb("head", Vec3(0.17, 0.17, 0.17), Vec3(), 0.0f, Vec3(0, 0.32, 0.0), Limb::color[3]);
	_lArm = Limb("left arm", Vec3(0.07, 0.5, 0.07), Vec3("z"),  -M_PI / 14, Vec3(-0.18f, 0.0f, 0.0f), Limb::color[2]);
	_rArm = Limb("right arm", Vec3(0.07, 0.5, 0.07), Vec3("z"), M_PI / 14, Vec3(0.18f, 0.0f, 0.0f), Limb::color[2]);
	_chest = Limb("chest", Vec3(0.23, 0.5, 0.21), Vec3(), 0.0f, Vec3("0"), Limb::color[1]);
	_lLeg = Limb("left leg", Vec3(0.09, 0.5, 0.09), Vec3(), 0.0f, Vec3(-0.07f, -0.5f, 0.0f), Limb::color[0]);
	_rLeg = Limb("right leg", Vec3(0.09, 0.5, 0.09), Vec3(), 0.0f, Vec3(0.07f, -0.5f, 0.0f), Limb::color[0]);
}
	
//Human::Human(Human const & src) {
////	std::cout << "Human copy constructor called" << std::endl;
//	*this = src;
//}

Human::~Human( void ) {
	std::cout << _name << " decided to leave the dance floor for now..." << std::endl;
}

//Human &    	Human::operator=( Human const & src) {
//	this->_name = src.getName();
//	return (*this);
//}

std::string		Human::getName( void ) const {
	return this->_name;
}

Limb					Human::getHead( void ) const {
	return this->_head;
}

Limb					Human::getLArm( void ) const {
	return this->_lArm;
}

Limb					Human::getRArm( void ) const {
	return this->_rArm;
}

Limb					Human::getChest( void ) const {
	return this->_chest;
}

Limb					Human::getLLeg( void ) const {
	return this->_lLeg;}

Limb					Human::getRLeg( void ) const {
	return this->_rLeg;
}


void					Human::draw( GLuint vao, Shader & shad ) const {
	this->_head.draw(vao, shad);
	this->_lArm.draw(vao, shad);
	this->_rArm.draw(vao, shad);
	this->_chest.draw(vao, shad);
	this->_lLeg.draw(vao, shad);
	this->_rLeg.draw(vao, shad);
}

std::ostream &		operator<<( std::ostream & o, Human const & rhs ) {

	o << "<---HUMAN PRINTER---->" << std::endl;
	o << "name: " << rhs.getName() << std::endl;
	o << "head: "	<< rhs.getHead() << std::endl;
	o << "lArm: "	<< rhs.getLArm() << std::endl;
	o << "rArm: "	<< rhs.getRArm() << std::endl;
	o << "chest: "	<< rhs.getChest() << std::endl;
	o << "lLeg: "	<< rhs.getLLeg() << std::endl;
	o << "rLeg: "	<< rhs.getRLeg() << std::endl;
	return o;
}
