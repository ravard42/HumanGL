#ifndef CAMERA_HPP
# define CAMERA_HPP

# include <iostream>

# include "Vec2.hpp"
# include "Vec3.hpp"
# include "Vec4.hpp"
# include "Mat3.hpp"
# include "Mat4.hpp"

# define X_POS 	68
# define X_NEG 	65
# define Y_POS 	86
# define Y_NEG 	67
# define Z_POS 	83
# define Z_NEG 	87
# define TURBO 	340

# define CAM_NB_KEY 7


# define SPEED	0.03
# define RUSH	5
# define ROTSPEED 0.003

class Camera {

private:
	static short const	_keyEntry[];
	char						_keyEvent;

	float					_speed;
	Vec3					_pos;
	Mat3					_base3;
	Mat4					_base4;
	bool					_firstMouse;	
	Vec2					_lastMousePos;
	Vec2					_mouseVector;
	float					_fov;

	void				_newPos( void );
	void				_newBase( void );

public:

	Camera( void );
	~Camera( void );

	void				setKeyEvent( int key );
	void				unsetKeyEvent( int key );
	void				mouseEvent( Vec2 pos );
	void				scrollEvent( double offset );
	float				getFov( void ) const;
	Mat4				setView( void );
//	glm::vec3		sendViewPos( void ) const;
};

#endif
