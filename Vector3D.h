// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors
// author:   Ryan Zurrin
#ifndef VECTOR3D_H
#define VECTOR3D_H
#include "Vector2d.h"

using namespace std;

class Vector3D : public Vector
{
public:
	ld z, xAngle, yAngle, zAngle;
	void set_allAngles();
	void set_magnitude();
	Vector3D check_division(ld);
	Vector3D* _ptr3d;
	Vector3D(); //constructor
	Vector3D(ld, ld, ld);  //initializing object with values.
	Vector3D(const Vector3D &vec);    //copy constructor
	void setX(ld);
	void setY(ld);
	void setZ(ld);
	void set_xAngle(ld);
	void set_yAngle(ld);
	void set_zAngle(ld);
	void set_coordinates(ld, ld, ld);
	void showAllData();
	void showPolarCord()const;
	void display();    //display value of vectors
	ld returnX()const; //return x
	ld returnY()const; //return y
	ld returnZ()const; //return z
	ld return_xAngle()const; //return x angle
	ld return_yAngle()const; //return y angle
	ld return_zAngle()const; //return z angle
	ld square(); //gives square of the vector
	ld dot_product(const Vector3D &vec) const; //scalar dot_product
	ld distance(const Vector3D &vec);    //gives distance between two vectors
	ld find_magnitude();  //magnitude of the vector
	Vector3D cross_product(const Vector3D &vec);    //cross_product
	Vector3D normalization();   //normalized vector
	Vector3D operator+(const Vector3D &vec)const;    //addition
	Vector3D operator+(Vector &vec)const;
	Vector3D &operator+=(const Vector3D &vec);  ////assigning new result to the vector
	Vector3D operator-(const Vector3D &vec);    //substraction
	Vector3D operator-(const ld number)const;
	Vector3D operator-()const;
	Vector3D operator--();
	Vector3D operator--(int);
	Vector3D &operator-=(const Vector3D &vec);  //assigning new result to the vector
	Vector3D operator*(ld value);    //multiplication
	Vector3D &operator*=(ld value);  //assigning new result to the vector.
	Vector3D operator/(ld);    //division
virtual Vector3D operator/(int);
	Vector3D &operator/=(ld value);  //assigning new result to the vector
	Vector3D &operator=(const Vector3D &vec);
	friend ostream& operator<<(ostream&, const Vector3D&);
	~Vector3D();
};
#endif


inline Vector3D::Vector3D() //constructor
{
  x=0;
  y=0;
  z=0;
  xAngle = 0.0;
  yAngle = 0.0;
  zAngle = 0.0;
  _ptr3d =  nullptr;
 // _ptr2d = nullptr;
  set_allAngles();
  object_counter++;
  //cout<< object_counter << ": " <<"in the 3dVector default constructor"<<endl;
}
inline Vector3D::Vector3D(ld x1,ld y1,ld z1) //initializing object with values.
{
  x=x1;
  y=y1;
  z=z1;
  xAngle = 0.0;
  yAngle = 0.0;
  zAngle = 0.0;
  _ptr3d =  nullptr;
 // _ptr2d = nullptr;
  set_magnitude();
  set_allAngles();
  object_counter++;
	//cout<< object_counter << ": " <<"in the x,y,z constructor" << endl;;
}
inline Vector3D::Vector3D(const Vector3D &vec)
	: Vector(vec)
{
  x=vec.x;
  y=vec.y;
  z=vec.z;
  xAngle = 0.0;
  yAngle = 0.0;
  zAngle = 0.0;
  _ptr3d = nullptr;
  set_magnitude();
  set_allAngles();
  object_counter++;

}
inline void Vector3D::setX(ld _x)
{
	x = _x;
	set_allAngles();
	set_magnitude();
}
inline void Vector3D::setY(ld _y)
{
	y = _y;
	set_allAngles();
	set_magnitude();
}
inline void Vector3D::setZ(ld _z)
{
	z = _z;
	set_allAngles();
	set_magnitude();
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
	// _ptr2d = nullptr;
	set_magnitude();
	set_allAngles();
	object_counter++;
}
inline void Vector3D::showAllData()
{
	magnitude = find_magnitude();
	cout<< setprecision(9) << fixed;
	cout<< "x: " << x << " ";
	cout<< "y: " << y << " ";
	cout<< "z: " << z << endl;
	cout<< "mag: " << magnitude << endl;
	cout << "angles aX: "<< xAngle << ", aY: "<<yAngle<<", aZ: "<<zAngle
		 << endl;
	show_mode();
}
inline void Vector3D::showPolarCord()const
{
	cout << setprecision(9) << fixed << "polar<" << x << ", " << y << ", " << z << ">";
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

inline Vector3D Vector3D::check_division(ld d)
{
	return *this;
}

//addition
inline Vector3D Vector3D::operator+(const Vector3D &vec)const
{
	cout << "in Vector3D::operator+(const Vector3D &vec)"<<endl;
	return Vector3D(x+vec.x,y+vec.y,z+vec.z);
}
inline Vector3D Vector3D::operator+(Vector &vec)const
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

//scalar division

inline Vector3D Vector3D::operator/(ld d)
{
	return check_division(d);

}
inline Vector3D Vector3D::operator/(int d)
{
	return check_division(d);

}

inline Vector3D &Vector3D::operator/=(ld value)
{

	x/=value;
	y/=value;
	z/=value;
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

inline Vector3D Vector3D::normalization()
{
	assert(find_magnitude()!=0);
	*this/=find_magnitude();
	return *this;
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
inline void Vector3D::display()
{
	cout<<x<<" "<<y<<" "<<z<<endl;
}

inline Vector3D::~Vector3D()
{
	--object_counter;
	delete _ptr3d;
	//delete this;
	//cout << "In Vector3D destructor: "<< object_counter << " objects remain\n"
	//		 << endl;
}
