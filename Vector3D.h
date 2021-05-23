﻿// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors
// author:   Ryan Zurrin
#ifndef VECTOR3D_H
#define VECTOR3D_H
#include "Vector2D.h"

using namespace std;

class Vector3D : public Vector2D
{
public:
	Vector3D* _ptr3d;
	Vector3D(string id = ""); //constructor
	Vector3D(ld, ld, ld, string id = "");  //initializing object with values.
	Vector3D(const Vector3D &vec, string id = "");    //copy constructor
	void setX(ld);
	void setY(ld);
	void setZ(ld);
	void set_xAngle(ld);
	void set_yAngle(ld);
	void set_zAngle(ld);
	void set_coordinates(ld, ld, ld);
	void displayAllData(std::string label = "");
	void showRectCord(std::string label = "")const;
	void showSphericalCoordinates(std::string label = "")const;
	void showAllAngles(std::string label = "")const;
	void display()const;    //display value of vector
	ld returnX()const; //return x
	ld returnY()const; //return y
	ld returnZ()const; //return z
	ld return_xAngle()const; //return x angle
	ld return_yAngle()const; //return y angle
	ld return_zAngle()const; //return z angle
	ld projection(Vector3D& v)const;
	ld angle_between_vectors(Vector3D& v)const;
	ld square(); //gives square of the vector
	ld dot_product(const Vector3D &vec) const; //scalar dot_product
	ld distance(const Vector3D &vec);    //gives distance between two vectors
	ld find_magnitude();  //magnitude of the vector
	Vector3D cross_product(const Vector3D &vec);    //cross_product
	Vector3D normalize_vector();   //normalized vector
	bool operator==(const Vector3D& v)const;
	bool operator!=(const Vector3D& v)const;
	bool operator>(const Vector3D& v)const;
	bool operator>=(const Vector3D& v)const;
	bool operator<(const Vector3D& v)const;
	bool operator<=(const Vector3D& v)const;
	Vector3D operator+(const Vector3D &vec)const;    //addition
	Vector3D operator+(Vector3D &vec)const;
	Vector3D &operator+=(const Vector3D &vec);  ////assigning new result to the vector
	Vector3D operator-(const Vector3D &vec);    //substraction
	Vector3D operator-(const ld number)const;
	Vector3D operator-()const;
	Vector3D operator--();
	Vector3D operator--(int);
	Vector3D &operator-=(const Vector3D &vec);  //assigning new result to the vector
	Vector3D operator*(ld value);    //multiplication
	Vector3D &operator*=(ld value);  //assigning new result to the vector.
	Vector3D &operator=(const Vector3D &vec);
	friend ostream& operator<<(ostream&, const Vector3D&);
	~Vector3D();
private:
	ld z, xAngle, yAngle, zAngle,radius, inclination, azimuth;
	void setRadius();
	void setInclination();
	void setAzimuth();
	void calculate_spherical();
	void set_allAngles();
	void set_magnitude();
};
#endif


inline Vector3D::Vector3D(string id) //constructor
{
  ID = id;
  x=0;
  y=0;
  z=0;
  xAngle = 0.0;
  yAngle = 0.0;
  zAngle = 0.0;
  magnitude = 0.0;
  _ptr3d =  nullptr;
  calculate_spherical();
  set_allAngles();
  object_counter++;
  //cout<< object_counter << ": " <<"in the 3dVector default constructor"<<endl;
}
inline Vector3D::Vector3D(ld x1,ld y1,ld z1,string id) //initializing object with values.
{
  ID = id;
  x=x1;
  y=y1;
  z=z1;
  xAngle = 0.0;
  yAngle = 0.0;
  zAngle = 0.0;
  _ptr3d =  nullptr;
  calculate_spherical();
  set_magnitude();
  set_allAngles();
  object_counter++;
	//cout<< object_counter << ": " <<"in the x,y,z constructor" << endl;;
}
inline Vector3D::Vector3D(const Vector3D &vec, string id)
	: Vector2D(vec)
{
  ID = id;
  x=vec.x;
  y=vec.y;
  z=vec.z;
  xAngle = 0.0;
  yAngle = 0.0;
  zAngle = 0.0;
  _ptr3d = nullptr;
  calculate_spherical();
  set_magnitude();
  set_allAngles();
  object_counter++;

}
inline void Vector3D::setX(ld _x)
{
	x = _x;
	set_allAngles();
	set_magnitude();
	calculate_spherical();
}
inline void Vector3D::setY(ld _y)
{
	y = _y;
	set_allAngles();
	set_magnitude();
	calculate_spherical();
}
inline void Vector3D::setZ(ld _z)
{
	z = _z;
	set_allAngles();
	set_magnitude();
	calculate_spherical();
}
inline void Vector3D::set_xAngle(ld _xa)
{
	xAngle = _xa;
	set_allAngles();
	set_magnitude();
}
inline void Vector3D::set_yAngle(ld _ya)
{
	yAngle = _ya;
	set_allAngles();
	set_magnitude();
}
inline void Vector3D::set_zAngle(ld _za)
{
	zAngle = _za;
	set_allAngles();
	set_magnitude();
}
inline void Vector3D::set_coordinates(ld x1, ld y1, ld z1)
{
	x = x1;
	y = y1;
	z = z1;
	xAngle = 0.0;
	yAngle = 0.0;
	zAngle = 0.0;
	_ptr3d = nullptr;

	set_magnitude();
	set_allAngles();
	object_counter++;
}
inline void Vector3D::displayAllData(std::string label)
{
	std::cout << ((label == "") ? ID : label);
	magnitude = find_magnitude();
	showRectCord();
	showSphericalCoordinates();
	showAllAngles();
	cout<< "mag: " << magnitude << endl;

}
inline void Vector3D::showRectCord(std::string label) const
{
	cout << setprecision(9) << fixed;

	cout<< "\n" <<((label == "") ? ID : label) << "(x,y,z) = ";
	if (x < 0 && x > -1) {
		cout << setiosflags(ios::fixed);
		cout << fixed << "(" << x << ","
			<< resetiosflags(ios::fixed);
	}
	else {
		cout << "(" << x << ",";
	}
	if (y<0 && y>-1) {
		cout << setiosflags(ios::fixed);
		cout << y << ",";
		cout << resetiosflags(ios::fixed);
	}
	else {
		cout << y << ",";
	}
	if (z<0 && z>-1) {
		cout << setiosflags(ios::fixed);
		cout << z << ")" << endl;
		cout << resetiosflags(ios::fixed);
	}
	else {
		cout << z << ")";
	}
	std::cout << std::endl;
}
inline void Vector3D::showSphericalCoordinates(std::string label)const
{
	cout<<((label == "") ? ID : label) << setprecision(9) << fixed
		<< "<r,\xE9,\xE8> = <" << radius
		<< ", " << inclination << ", " << azimuth << ">"<<std::endl;
}
inline void Vector3D::showAllAngles(std::string label) const
{
	cout <<((label == "") ? ID : label) << " Direction Angles \xE9x: "
		 << xAngle << ", \xE9y: " << yAngle
		 << ", \xE9z: " << zAngle << endl;
}
inline void Vector3D::setRadius()
{
	radius = sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}
inline void Vector3D::setInclination()
{
	inclination = acos(z / radius)*DEGREE;
}
inline void Vector3D::setAzimuth()
{
	azimuth = atan(y / x)*DEGREE;
}
inline void Vector3D::calculate_spherical()
{
	setRadius();
	setInclination();
	setAzimuth();
}
inline void Vector3D::set_allAngles()
{
	xAngle = return_xAngle();
	yAngle = return_yAngle();
	zAngle = return_zAngle();
	//angle =
}

inline void Vector3D::set_magnitude()
{
	magnitude = find_magnitude();
}



//addition
inline Vector3D Vector3D::operator+(const Vector3D &vec)const
{
	cout << "in Vector3D::operator+(const Vector3D &vec)"<<endl;
	return Vector3D(x+vec.x,y+vec.y,z+vec.z);
}
inline Vector3D Vector3D::operator+(Vector3D &vec)const
{
	cout << "in Vector3D::operator+(Vector &vec)const "<<endl;
	return Vector3D(x+vec.x,y+vec.y,z);
}

inline Vector3D &Vector3D::operator+=(const Vector3D &vec)
{
	cout << "in &Vector3D::operator+=(const Vector3D &vec)"<<endl;
	x+=vec.x;
	y+=vec.y;
	z+=vec.z;
	calculate_spherical();
	set_allAngles();
	return *this;
}

//substraction//
inline Vector3D Vector3D::operator-(const Vector3D &vec)
{
	return Vector3D(x-vec.x,y-vec.y,z-vec.z);
}
inline Vector3D Vector3D::operator-(const ld n) const
{
	return Vector3D(x-n, y-n, z-n);
}
inline Vector3D Vector3D::operator-() const
{
	return Vector3D(-x, -y, -z);
}
inline Vector3D Vector3D::operator--()
{
	return Vector3D(--x, --y, --z);
}
inline Vector3D Vector3D::operator--(int)
{
	return Vector3D(x--, y--, z--);
}
inline Vector3D &Vector3D::operator-=(const Vector3D &vec)
{
	x-=vec.x;
	y-=vec.y;
	z-=vec.z;
	set_allAngles();
	return *this;
}

//scalar multiplication
inline Vector3D Vector3D::operator*(ld value)
{
	return Vector3D(x*value,y*value,z*value);
}
inline Vector3D &Vector3D::operator*=(ld value)
{
	x*=value;
	y*=value;
	z*=value;
	set_allAngles();
	return *this;
}


inline Vector3D& Vector3D::operator=(const Vector3D& vec)
{
	this->_ptr3d = vec._ptr3d;
	x = vec.x;
	y = vec.y;
	z = vec.z;
	set_allAngles();

	return *this;
}

inline ostream& operator<<(ostream& os, const Vector3D & v)
{
  if(v.mode == 'R' || v.mode == 'r'){
	v.showRectCord();
  }
  else{
	v.showPolarCord();
  }
  return os;
}


//Dot product
inline ld Vector3D::dot_product(const Vector3D &vec) const
{
	return x * vec.x + vec.y * y + vec.z * z;
}
//cross product
inline Vector3D Vector3D::cross_product(const Vector3D &vec)
{
	ld ni=y*vec.z-z*vec.y;
	ld nj=z*vec.x-x*vec.z;
	ld nk=x*vec.y-y*vec.x;
	return Vector3D(ni,nj,nk);
}
inline ld Vector3D::find_magnitude()
{
	return sqrt(square());
}
inline ld Vector3D::square()
{
	return x*x+y*y+z*z;
}

inline Vector3D Vector3D::normalize_vector()
{
	assert(find_magnitude()!=0);
	const auto length = sqrt((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
	this->x /= length;
	this->y /= length;
	this->z /= length;
	calculate_spherical();
	set_allAngles();
	return *this;
}

inline bool Vector3D::operator==(const Vector3D& v) const
{
	return std::make_tuple(this->x, this->y, this->z) ==
		std::make_tuple(v.x, v.y, v.z);
}

inline bool Vector3D::operator!=(const Vector3D& v) const
{
	return std::make_tuple(this->x, this->y, this->z) !=
		std::make_tuple(v.x, v.y, v.z);
}

inline bool Vector3D::operator>(const Vector3D& v) const
{
	return std::make_tuple(this->x, this->y, this->z) >
		std::make_tuple(v.x, v.y, v.z);
}

inline bool Vector3D::operator>=(const Vector3D& v) const
{
	return std::make_tuple(this->x, this->y, this->z) >=
		std::make_tuple(v.x, v.y, v.z);
}

inline bool Vector3D::operator<(const Vector3D& v) const
{
	return std::make_tuple(this->x, this->y, this->z) <
		std::make_tuple(v.x, v.y, v.z);
}

inline bool Vector3D::operator<=(const Vector3D& v) const
{
	return std::make_tuple(this->x, this->y, this->z) <=
		std::make_tuple(v.x, v.y, v.z);
}


inline ld Vector3D::distance(const Vector3D &vec)
{
	ld x1, x2, y1, y2, z1, z2;
	x1 = this->x;
	x2 = vec.x;
	y1 = this->y;
	y2 = vec.y;
	z1 = this->z;
	z2 = vec.z;
	return sqrt((pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2)));
}

inline ld Vector3D::returnX()const
{
	return x;
}
inline ld Vector3D::returnY()const
{
	return y;
}
inline ld Vector3D::returnZ()const
{
	return z;
}
inline ld Vector3D::return_xAngle()const
{
	return atan2(sqrt(y * y + z * z), x) * DEGREE;
}
inline ld Vector3D::return_yAngle()const
{
	return atan2(sqrt(x * x + z * z), y) * DEGREE;
}
inline ld Vector3D::return_zAngle()const
{
	return atan2(sqrt(x * x  + y * y), z) * DEGREE;
}
inline ld Vector3D::projection(Vector3D& v) const
{
	const auto Θ = this->angle_between_vectors(v);
	return this->magnitude * cos(Θ * RADIAN);
}
inline ld Vector3D::angle_between_vectors(Vector3D& v)const
{
	return acos(this->dot_product(v) / (this->magnitude * v.magnitude)) * DEGREE;
}
inline void Vector3D::display()const
{
	cout<<"<"<<x<<", "<<y<<", "<<z<<">"<<endl;
}

inline Vector3D::~Vector3D()
{
	--object_counter;
	delete _ptr3d;
	//delete this;
	//cout << "In Vector3D destructor: "<< object_counter << " objects remain\n"
	//		 << endl;
}
