// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors
// prgrammer:   Ryan Zurrin
#ifndef VECTOR3D_H
#define VECTOR3D_H
#include "Vector2d.h"


using namespace std;

class Vector3D : public Vector
{
//friend class Vector;
private:
   

public:    
    double z, xAngle, yAngle, zAngle;
    void set_allAngles();
    void set_magnitude();
    Vector3D check_division(double);
    Vector3D* _ptr3d;
   
    Vector3D(); //constructor    
    Vector3D(double, double, double);  //initializing object with values.    
    Vector3D(const Vector3D &vec);    //copy constructor    

    
    void setX(double);
    void setY(double);
    void setZ(double);
    void set_xAngle(double);
    void set_yAngle(double);
    void set_zAngle(double);
    
    void showAllData();
    void showPolarCord()const;
    void display();    //display value of vectors
    double returnX()const; //return x
    double returnY()const; //return y
    double returnZ()const; //return z
    double return_xAngle()const; //return x angle
    double return_yAngle()const; //return y angle
    double return_zAngle()const; //return z angle
    
    double square(); //gives square of the vector
    
    double dot_product(const Vector3D &vec); //scalar dot_product
    double distance(const Vector3D &vec);    //gives distance between two vectors
    double find_magnitude();  //magnitude of the vector
    Vector3D cross_product(const Vector3D &vec);    //cross_product
    Vector3D normalization();   //normalized vector    
    
    Vector3D operator+(const Vector3D &vec)const;    //addition
    Vector3D operator+(Vector &vec)const;
    Vector3D &operator+=(const Vector3D &vec);  ////assigning new result to the vector
    Vector3D operator-(const Vector3D &vec);    //substraction
    Vector3D operator-(const double number)const;
    Vector3D operator-()const;
    Vector3D operator--();
    Vector3D operator--(int);
    Vector3D &operator-=(const Vector3D &vec);  //assigning new result to the vector
    Vector3D operator*(double value);    //multiplication
    Vector3D &operator*=(double value);  //assigning new result to the vector.  
    Vector3D operator/(double);    //division
virtual Vector3D operator/(int);
    Vector3D &operator/=(double value);  //assigning new result to the vector
    Vector3D &operator=(const Vector3D &vec);      
    friend ostream& operator<<(ostream&, const Vector3D&);
    ~Vector3D(); 
};
#endif



