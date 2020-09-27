#pragma once
//author:			Ryan Zurrin
//file:           vect.h (XL)
// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// Specification file for a  vect class 
#ifndef VECTOR2D_H
#define VECTOR2D_H
//#include "Numbers.h"
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <complex>
#include <assert.h>


using namespace std;


const double PI		= 3.1415926535898;
const double DEGREE = 180/PI;
const double RADIAN = PI/180; 



class Vector
{
   static int object_counter;	 	 
   friend class Vector3D; 			  
   public:
      Vector* vptr2d;
      double x, y, magnitude, angle,
         arcLength, revolutionAngle_inDegrees;
      char mode;  //sets mode to Polar w/ 'p' or Rectangular w/ 'r'           
      
      //void    calculate_parametric_equation();
      void 	  validate_setMode();
      void    normalize_magnitude();
      void    calculate_magnitude();
      void    calculate_angle();
      void    adjust_angle();
      void    calculate_rectangular();
      void    calculate_polar();
      void    calculate_arcLength();
      Vector  check_division(double);
      Vector  check_division(Vector);
      
      //void    calculate_derivative();

  // private:
  //    Vector calculate_parallel_vector2d( Vector&, Vector&);

 			
     
	  Vector(); //default constructor      
      Vector(char);//mode select, defaults to 0, in rectangular, constructor
      Vector(double, double, char _mode = 'r'); //constructor takes both coordinates and mode
      Vector(const Vector &);	//copy constructor		   
      virtual void showAllData()const; //virtual so any derived classes must redefine
      virtual void showVector()const;    
      virtual void showRectCord()const;
      virtual void showPolarCord()const;
      virtual void showRevolutionAngle()const;
      
      //virtual void showPolarCurve()const;
      //virtual void showParametricEquation()const;
      void show_x()const;
      void show_y()const;
      void show_mag()const;
      void show_angle()const;
      void show_mode()const;
      void show_arcLength()const;
	
      double return_x()const;
      double return_y()const;
      double return_mag()const;
      double return_angle()const;
      double return_arcLength()const;
      char return_mode()const;
      static int return_objectCount(){return object_counter;}
			
     
      
      void set_coordinates(double, double, char _mode = 'r');
      void set_rectCord(double, double);
      void set_polarCord(double, double);     
      void set_x(double);
      void set_y(double);
      void set_mag(double);
      void set_angle(double);
      void set_mode(char); 
      //void setPolarCurve();

      virtual double square();              //gives square old the vector
      virtual double find_magnitude();             //magnitude old the vector
      virtual double dot_product(const Vector&); //scalar dot_product
      virtual double distance(const Vector&);    //gives distance between two vectors
      virtual double cross_product2D(const Vector&);    //cross_product
      Vector normalization();   //normalized vector    
      //virtual void setParametricPoints();      
      
      bool operator>(const Vector &)const;
      bool operator>=(const Vector&)const;
      bool operator<(const Vector &)const;
      bool operator<=(const Vector&)const;
      bool operator==(const Vector &)const;
      bool operator!=(const Vector&)const;
      bool operator>(const double& n)const { return magnitude > n; }
      bool operator>=(const double& n)const { return magnitude >= n; }
      bool operator<(const double& n)const { return n < magnitude; }
      bool operator<=(const double& n)const { return n <= magnitude; }
      bool operator==(const double& n)const { return magnitude == n; }
      bool operator!=(const double& n)const { return !(magnitude == n); }
   
      
      Vector operator+(const Vector &)const;     
      Vector operator+(double number)const;      
      Vector &operator+=(const Vector &);

      Vector operator+()const;        
      Vector operator++();
      Vector operator++(int);

      Vector operator-(const Vector &);     
      Vector operator-(const double number)const;
      Vector operator-()const;      
      Vector operator--();
      Vector operator--(int);      
      
      Vector operator/(double);     
      Vector operator/(int);
      Vector operator/(Vector);
     
      Vector &operator/=(double);
      const Vector operator=(const Vector &);
      Vector &operator=(const Vector *);
      Vector &operator=(Vector&& right)noexcept;
      Vector(Vector&& temp)noexcept;
     
      
      virtual Vector operator*(double)const;
      
      friend Vector operator*(double s, Vector& v);
      friend Vector operator*(Vector& v, Vector& s);
      friend Vector operator-(double s, Vector& v);
      friend Vector operator+(double s, Vector& v);      
      friend ostream& operator<<(ostream&, const Vector&);     
      friend istream& operator>>(istream&, Vector&);  
      
      virtual ~Vector();    
};
#endif



