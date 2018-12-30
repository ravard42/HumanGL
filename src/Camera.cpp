#include "Camera.hpp"

Camera::Camera( void ) : _keyEvent(0), _speed(SPEED), _firstMouse(true), _fov(45.0f) {
	std::cout << "Camera default constructor called" << std::endl;
	this->_pos = Vec3(0.0f, 0.0f, 5.0f);	
}

Camera::~Camera( void ) {
	std::cout << "Camera destructor called" << std::endl;
}

void			Camera::_newPos( void ) {
	Vec3		mouv((float)((bool)(this->_keyEvent & 1) - (bool)(this->_keyEvent & 2))
					, (float)((bool)(this->_keyEvent & 4) - (bool)(this->_keyEvent & 8))
					, (float)((bool)(this->_keyEvent & 16) - (bool)(this->_keyEvent & 32)));
	
	this->_speed = (this->_keyEvent & 64) ? RUSH * SPEED : SPEED;
	this->_pos = this->_pos
					+ this->_base3[0] * mouv[0] * this->_speed
					+ this->_base3[1] * mouv[1] * this->_speed
					+ this->_base3[2] * mouv[2] * this->_speed;
}

void			Camera::_newBase( void ) {
	Vec3  n;
	
	if (this->_mouseVector[0]) {
		n = (this->_base3[1][1] >= 0) ?
			Vec3(0.0f, 1.0f, 0.0f) : Vec3(0.0f, -1.0f, 0.0f);
		this->_base4 = Mat4("Rotation", ROTSPEED * -this->_mouseVector[0], n)
			* this->_base4;
		this->_base4.normalize();
		this->_base3 = Mat3(this->_base4);
	}
	if (this->_mouseVector[1]) {
		n = this->_base3[0];
		this->_base4 = Mat4("Rotation", ROTSPEED * this->_mouseVector[1], n)
			* this->_base4;
		this->_base4.normalize();
		this->_base3 = Mat3(this->_base4);
	}
	this->_mouseVector[0] = 0.0f;
	this->_mouseVector[1] = 0.0f;

}

void			Camera::setKeyEvent( int key ) {
	int		i = -1;

	while (++i < CAM_NB_KEY) 
		if (key == Camera::_keyEntry[i])
			this->_keyEvent |= (char)pow(2, i);
}

void			Camera::unsetKeyEvent( int key ) {
	int		i = -1;

	while (++i < CAM_NB_KEY)
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

	this->_newPos();
	this->_newBase();
	view = this->_base4.transpose() * Mat4("Translation", this->_pos * -1);
	return ( view );
}
	
//glm::vec3		Camera::sendViewPos( void ) const {
//	
//	return (glm::vec3(-this->_trans[3]));
//}

short const		Camera::_keyEntry[] = {X_POS, X_NEG, Y_POS, Y_NEG, Z_POS, Z_NEG, TURBO};
