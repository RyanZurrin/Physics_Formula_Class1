#pragma once
//author:			Ryan Zurrin
//file:           vect.h (XL)
// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// Specification file for a  vect class
#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
typedef  long double _ld_;
using namespace std;


const _ld_ _PI_ = acos(-1);
const _ld_ DEGREE = 180/_PI_;
const _ld_ RADIAN = _PI_/180;
const _ld_ _Ga_ = 9.8;
static int object_counter = 0;



class Vector
{

   friend class Vector3D;
   //friend class Physics;
private:
    static void countIncrease() { object_counter += 1; }
    static void countDecrease() { object_counter -= 1; }
public:
	Vector* _vptr2d;
	_ld_ x;
    _ld_ y;
    _ld_ magnitude;
    _ld_ angle;
    _ld_ arcLength;
	_ld_ revolutionAngle_inDegrees;
    char mode;  //sets mode to Polar w/ 'p' or Rectangular w/ 'r'
    static void countShow() { std::cout << "vector2d count: " << object_counter << std::endl; }
    //void    calculate_parametric_equation();
    void 	  validate_setMode();
    void    normalize_magnitude();
    void    calculate_magnitude();
    void    calculate_angle();
    void    adjust_angle();
    void    calculate_rectangular();
    void    calculate_polar();
    void    calculate_arcLength();
    Vector  check_division(_ld_);
   static Vector  check_division(Vector);

	Vector(); //default constructor
    Vector(char);//mode select, defaults to 0, in rectangular, constructor
    Vector(_ld_, _ld_, char _mode = 'r'); //constructor takes both coordinates and mode
    Vector(const Vector &);	//copy constructor
    void showAllData()const; //virtual so any derived classes must redefine
    void showVector()const;
    void showRectCord()const;
    void showPolarCord()const;
    void showRevolutionAngle()const;

    //virtual void showPolarCurve()const;
    //virtual void showParametricEquation()const;
    void show_x()const;
    void show_y()const;
    void show_mag()const;
    void show_angle()const;
    void show_mode()const;
    void show_arcLength()const;
	_ld_ return_x()const;
    _ld_ return_y()const;
    _ld_ return_mag()const;
    _ld_ return_angle()const;
    _ld_ return_arcLength()const;
    char return_mode()const;
    static int return_objectCount(){return object_counter;}

    void set_coordinates(_ld_, _ld_, char _mode = 'r');
    void set_rectCord(_ld_, _ld_);
    void set_polarCord(_ld_, _ld_);
    void set_x(_ld_);
    void set_y(_ld_);
    void set_mag(_ld_);
    void set_angle(_ld_);
    void set_mode(char);
    //void setPolarCurve();
    _ld_ square()const;              //gives square o_ld_ the vector
    _ld_ find_magnitude()const;             //magnitude o_ld_ the vector
    _ld_ dot_product(const Vector&)const; //scalar dot_product
    _ld_ distance(const Vector&)const;    //gives distance between two vectors
    _ld_ cross_product2D(const Vector&)const;    //cross_product
    Vector normalization();   //normalized vector
     //virtual void setParametricPoints();

    bool operator>(const Vector &)const;
    bool operator>=(const Vector&)const;
    bool operator<(const Vector &)const;
    bool operator<=(const Vector&)const;
    bool operator==(const Vector &)const;
    bool operator!=(const Vector&)const;
    bool operator>(const _ld_& n)const { return magnitude > n; }
    bool operator>=(const _ld_& n)const { return magnitude >= n; }
    bool operator<(const _ld_& n)const { return n < magnitude; }
    bool operator<=(const _ld_& n)const { return n <= magnitude; }
    bool operator==(const _ld_& n)const { return magnitude == n; }
    bool operator!=(const _ld_& n)const { return !(magnitude == n); }

    Vector operator+(const Vector &)const;
    Vector operator+(_ld_ number)const;
    Vector &operator+=(const Vector &);
    Vector operator+()const;
    Vector operator++();
    Vector operator++(int);
    Vector operator-(const Vector&) const;
    Vector operator-(const _ld_ number)const;
    Vector operator-()const;
    Vector operator--();
    Vector operator--(int);
    Vector operator/(_ld_);
	Vector operator/(int);
    Vector operator/(Vector);
    Vector &operator/=(_ld_);
    Vector& operator=(const Vector &);
    Vector &operator=(const Vector *);
    Vector &operator=(Vector&& right)noexcept;
    Vector(Vector&& temp)noexcept;

    virtual Vector operator*(_ld_)const;

    friend Vector operator*(_ld_ s, Vector& v);
    friend Vector operator*(Vector& v, Vector& s);
    friend Vector operator-(_ld_ s, Vector& v);
    friend Vector operator+(_ld_ s, Vector& v);
    friend ostream& operator<<(ostream&, const Vector&);
    friend istream& operator>>(istream&, Vector&);

    virtual ~Vector();
};
#endif



