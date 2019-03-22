#include "Mat3.hpp"

Mat3::Mat3( void ) {
//	std::cout << "Mat3 constructor called" << std::endl;
	this->identity();
}

Mat3::Mat3( Vec3 const & a, Vec3 const & b, Vec3 const & c) {
	int	i = -1;

//	std::cout << "Mat3 parametric constructor called" << std::endl;
	while (++i < 3) {
		(*this)[0][i] = a.v[i];
		(*this)[1][i] = b.v[i];
		(*this)[2][i] = c.v[i];
	}
}
	
Mat3::Mat3( std::string str ) {
//	std::cout << "Mat3 Zero constructor called" << std::endl;
	if (!str.compare("Zero"))
		this->zero();
}

Mat3::Mat3( std::string str, float radian, Vec3 const & n) {
//	std::cout << "Mat3 Rotation constructor called" << std::endl;
	if (!str.compare("Rotation"))
		this->rotation(radian, n);
}

Mat3::Mat3( std::string str, Vec3 const & vec) {
//		std::cout << "Mat3 Scale constructor called" << std::endl;
	if (!str.compare("Scale"))
		this->scale(vec);
}

Mat3::Mat3(Mat3 const  & src) {
//	std::cout << "Mat3 copy constructor called" << std::endl;
	*this = src;
}

Mat3::Mat3( Mat4 const & src ) {
	int	i = -1;
	int	j;

// std::cout << "Mat3 'Mat4 convertor' constructor called" << std::endl;
	while (++i < 3) {
		j = -1;
		while (++j < 3)
			this->m[j].v[i] = src.m[j].v[i];
	}
}

Mat3::~Mat3( void ) {
//	std::cout << "Mat3 destructor called" << std::endl;
}


Mat3 &    	Mat3::operator=( Mat3 const &  src) {
	int	j = -1;
	int	i;

	while (++j < 3) {
		i = -1;
		while (++i < 3)
			this->m[j][i] = src.m[j].v[i];
	}
	return (*this);
}

Vec3	&		Mat3::operator[]( int j )
{
	if ( j < 0 || j > 2 ) {
		std::cout << "Index out of bounds, first data sendt" << std::endl;
		return this->m[0];
	}
	else
		return this->m[j];
}


Mat3     	Mat3::operator+( Mat3 const & src) const {
	Mat3	ret("Zero");
	int	j = -1;
	int	i;

	while (++j < 3) {
		i = -1;
		while (++i < 3)
			ret[j][i] = this->m[j].v[i] + src.m[j].v[i];
	}
	return (ret);
}
	
Mat3			Mat3::operator*( Mat3 const & src ) const {
	Mat3 	ret("Zero");	
	int	i = -1;
	int	j, k;

	while (++i < 3) {
		j = -1;
		while (++j < 3) {
			k = -1;
			while (++k < 3) 
				ret[j][i] += this->m[k].v[i] * src.m[j].v[k];
		}
	}
	return ret;
}

Mat3     	Mat3::operator*( float k ) const {
	Mat3	ret("Zero");
	int	j = -1;
	int	i;

	while (++j < 3) {
		i = -1;
		while (++i < 3)
			ret[j].v[i] = k * this->m[j].v[i];
	}
	return (ret);
}


Mat3 &		Mat3::zero( void ) {
	int	j = -1;
	int	i;

	while (++j < 3) {
		i = -1;
		while (++i < 3)
			this->m[j][i] = 0;
	}
	return *this;
}

Mat3 &		Mat3::identity( void ) {
	int j = -1;
	
	this->zero();
	while (++j < 3)
		this->m[j][j] = 1;
	return *this;
}

Mat3 &		Mat3::scale(Vec3 const & scVec) {
	float	const *sc = scVec.v;
	this->identity();
	(*this)[0][0] *= sc[0];
	(*this)[1][1] *= sc[1];
	(*this)[2][2] *= sc[2];
	return *this;
}

Mat3 &		Mat3::rotation(float radian, Vec3 const & rotVec) {
	float	const *n = rotVec.v;
	Mat3	id;
	Mat3	p = Mat3(Vec3(n[0] * n[0], n[0] * n[1], n[0] * n[2]),
				Vec3(n[1] * n[0], n[1] * n[1], n[1] * n[2]),
				Vec3(n[2] * n[0], n[2] * n[1], n[2] * n[2]));
	Mat3	q = Mat3(Vec3(0, n[2], -n[1]),
				Vec3(-n[2], 0, n[0]),
				Vec3(n[1], -n[0], 0));
	*this = id * cos(radian) + p * (1 - cos(radian)) + q * sin(radian);
	return *this;
}
	
Mat3 &		Mat3::normalize( void ) {
	(*this)[0].normalize();
	(*this)[1].normalize();
	(*this)[2].normalize();
	return *this;
}

Mat3 			Mat3::transpose( void ) {
	int	i = 0;
	int	j;
	Mat3	ret;

	while (++i < 3) {
		j = -1;
		while (++j < 3)
			ret[i][j] = m[j][i];
	}
	return ret;
}

std::ostream &		operator<<( std::ostream & o, Mat3 const & rhs ) {
	int	i = -1;
	int	j;

	o << "<---MAT3 PRINTER---->" << std::endl;
	while (++i < 3) {
		o << "|";
		j = -1;
		while (++j < 3) {
			std::cout << std::setw(6);
			o << rhs.m[j].v[i] << "|";
		}
		o << std::endl;
	}
	o << "<------------------->";
	return o;
}
