#include "Camera.hpp"

Camera::Camera( void ) : _keyEvent(0), _speed(SPEED), _firstMouse(true), _sensitivity(0.2f), _fov(45.0f) {
	std::cout << "Camera default constructor called" << std::endl;
	this->_trans = Mat4("Translation", Vec3(0.0f, 0.0f, -5.0f));	
}

Camera::~Camera( void ) {
	std::cout << "Camera destructor called" << std::endl;
}

void			Camera::_newTrans( void ) {
	Vec3		xyz((float)((bool)(this->_keyEvent & 1) - (bool)(this->_keyEvent & 2))
					, (float)((bool)(this->_keyEvent & 4) - (bool)(this->_keyEvent & 8))
					, (float)((bool)(this->_keyEvent & 16) - (bool)(this->_keyEvent & 32)));
	Vec4		transVec = (this->_base[0] * xyz[0] + this->_base[1] * xyz[1] + this->_base[2] * xyz[2]);
	transVec.normalize();
	this->_speed = (this->_keyEvent & 64) ? 3 * SPEED : SPEED;
	transVec = transVec * this->_speed;
	this->_trans[3][0] -= transVec[0];
	this->_trans[3][1] -= transVec[1];
	this->_trans[3][2] -= transVec[2];
}
//
//void			Camera::_newBase( void ) {
//	glm::vec3	rot;
//
//	
//	rot = -this->_mouseVector.x * glm::vec3(0.0f, 1.0f, 0.0f);
//	if (!glm::isNull(rot, 0.5f))
//		this->_base = glm::rotate(glm::mat4(), glm::radians(this->_sensitivity) * glm::length(rot), glm::normalize(rot)) * this->_base;
//	rot = this->_mouseVector.y * this->_base[0].xyz();
//	if (!glm::isNull(rot, 0.5f))
//		this->_base = glm::rotate(glm::mat4(), glm::radians(this->_sensitivity) * glm::length(rot), glm::normalize(rot)) * this->_base;
//	this->_mouseVector = glm::vec2(0.0f, 0.0f);
//}

void			Camera::setKeyEvent( int key ) {
	int		i = -1;

	while (++i < NB_KEY) 
		if (key == Camera::_keyEntry[i])
			this->_keyEvent |= (char)pow(2, i);
}

void			Camera::unsetKeyEvent( int key ) {
	int		i = -1;

	while (++i < NB_KEY)
		if (key == Camera::_keyEntry[i])
			this->_keyEvent &= ~(char)pow(2, i);
}

void			Camera::mouseEvent( Vec2 pos) {
	if (this->_firstMouse && !(this->_firstMouse = false)) {
		this->_lastMousePos = pos;
		this->_mouseVector[0] = 0;
		this->_mouseVector[1] = 0;
	}
	else {
		this->_mouseVector[0] = pos[0] - this->_lastMousePos[0];
		this->_mouseVector[1] = -(pos[1] - this->_lastMousePos[1]);
		this->_lastMousePos = pos;
	}
}

void			Camera::scrollEvent( double offset) {
	if(this->_fov >= 1.0f && this->_fov <= 45.0f)
		this->_fov += offset;
	if(this->_fov <= 1.0f)
		this->_fov = 1.0f;
	if(this->_fov >= 45.0f)
		this->_fov = 45.0f;
}
	
float			Camera::getFov( void ) const {
	return (this->_fov);
}

Mat4			Camera::setView( void ) {
	Mat4	view;

	this->_newTrans();
	view = this->_trans;
	//this->_newBase();
	//view = glm::transpose(this->_base) * this->_trans;
	return ( view );
}
	
//glm::vec3		Camera::sendViewPos( void ) const {
//	
//	return (glm::vec3(-this->_trans[3]));
//}

short const		Camera::_keyEntry[] = {X_POS, X_NEG, Y_POS, Y_NEG, Z_POS, Z_NEG, TURBO};
