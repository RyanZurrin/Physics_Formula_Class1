// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors
// prgrammer:   Ryan Zurrin
#ifndef VECTOR3D_H
#define VECTOR3D_H
#include "Vector2d.h"
typedef long double _ld;

using namespace std;

class Vector3D : public Vector
{
//friend class Vector;
private:

public:
    _ld z, xAngle, yAngle, zAngle;
    void set_allAngles();
    void set_magnitude();
    Vector3D check_division(_ld);
    Vector3D* _ptr3d;
    Vector3D(); //constructor
    Vector3D(_ld, _ld, _ld);  //initializing object with values.
    Vector3D(const Vector3D &vec);    //copy constructor
    void setX(_ld);
    void setY(_ld);
    void setZ(_ld);
    void set_xAngle(_ld);
    void set_yAngle(_ld);
    void set_zAngle(_ld);
    void set_coordinates(_ld, _ld, _ld);
    void showAllData();
    void showPolarCord()const;
    void display();    //display value of vectors
    _ld returnX()const; //return x
    _ld returnY()const; //return y
    _ld returnZ()const; //return z
    _ld return_xAngle()const; //return x angle
    _ld return_yAngle()const; //return y angle
    _ld return_zAngle()const; //return z angle
    _ld square(); //gives square of the vector
    _ld dot_product(const Vector3D &vec) const; //scalar dot_product
    _ld distance(const Vector3D &vec);    //gives distance between two vectors
    _ld find_magnitude();  //magnitude of the vector
    Vector3D cross_product(const Vector3D &vec);    //cross_product
    Vector3D normalization();   //normalized vector
    Vector3D operator+(const Vector3D &vec)const;    //addition
    Vector3D operator+(Vector &vec)const;
    Vector3D &operator+=(const Vector3D &vec);  ////assigning new result to the vector
    Vector3D operator-(const Vector3D &vec);    //substraction
    Vector3D operator-(const _ld number)const;
    Vector3D operator-()const;
    Vector3D operator--();
    Vector3D operator--(int);
    Vector3D &operator-=(const Vector3D &vec);  //assigning new result to the vector
    Vector3D operator*(_ld value);    //multiplication
    Vector3D &operator*=(_ld value);  //assigning new result to the vector.
    Vector3D operator/(_ld);    //division
virtual Vector3D operator/(int);
    Vector3D &operator/=(_ld value);  //assigning new result to the vector
    Vector3D &operator=(const Vector3D &vec);
	friend ostream& operator<<(ostream&, const Vector3D&);
    ~Vector3D();
};
#endif



