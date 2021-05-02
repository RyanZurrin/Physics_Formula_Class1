#pragma once
//author:	Ryan Zurrin
//file:		Vector2d.h
// Specification file for a  vector class
#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cassert>
using namespace std;
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
	bool operator<(const _ld_& n)const { return magnitude < n; }
	bool operator<=(const _ld_& n)const { return magnitude <= n; }
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

	Vector operator*(_ld_)const;

	friend Vector operator*(_ld_ s, Vector& v);
	friend Vector operator*(Vector& v, Vector& s);
	friend Vector operator-(_ld_ s, Vector& v);
	friend Vector operator+(_ld_ s, Vector& v);
	friend ostream& operator<<(ostream&, const Vector&);
	friend istream& operator>>(istream&, Vector&);

	virtual ~Vector();
};
#endif
//=============================================================================
//in-line class Implementation

inline Vector::Vector()
{
  _vptr2d =  nullptr;
  x = 0;
  y = 0;
  magnitude = 0.0;
  angle = 0.0;
  calculate_arcLength();
  arcLength = 0.0;
  revolutionAngle_inDegrees = 0.0;
  mode = 'r';
  validate_setMode();

  countIncrease();
  //countShow();
}

inline Vector::Vector(char _mode)
{
	_vptr2d =  nullptr;
  x = 0;
  y = 0;
  magnitude = 0;
  angle = 0;
  calculate_arcLength();
  arcLength = return_angle();
  revolutionAngle_inDegrees = 0;
  mode = _mode;
  validate_setMode();
  countIncrease();
  //countShow();
}
/*______________________________________________________________________________
  the third argument is the mode setting.
  Use 'r'/'R' for rectangular components, 'p'/'P' for polar components
*/
inline Vector::Vector(_ld_ xMag, _ld_ yAng, char _mode)
{
	revolutionAngle_inDegrees = 0;
	magnitude = 0;
	angle = 0;
	mode = _mode;
	validate_setMode();
	x = xMag;
	y = yAng;
	set_coordinates(x, y, _mode);
	calculate_arcLength();
	arcLength = return_angle();
	_vptr2d =  nullptr;
	countIncrease();

}
inline Vector::Vector(const Vector &v)
{


	revolutionAngle_inDegrees = v.revolutionAngle_inDegrees;
	magnitude = v.magnitude;
	angle = v.angle;
	mode = v.mode;
	validate_setMode();
	x = v.x;
	y = v.y;
	set_coordinates(x, y, mode);
	calculate_arcLength();
	arcLength = return_angle();
	_vptr2d =  nullptr;
	countIncrease();
}
inline void Vector::showAllData()const
{

  showRectCord();
  showPolarCord();
  showRevolutionAngle();
 // show_mode();
  show_arcLength();
}
inline void Vector::showVector()const
{
  if (mode == 'r' || mode == 'R') {
   showRectCord();
   show_arcLength();
  }
  else {
   showPolarCord();
   show_arcLength();
  }
}

inline void Vector::showRectCord()const
{
	 cout << setprecision(5) << fixed;

	 cout << "\n(x,y) = ";
	 if(x < 0 && x > -1 ){
		 cout << setiosflags(ios::fixed);
	 cout << fixed << "(" << x << ","
		 << resetiosflags(ios::fixed);
   }
	 else{
	 cout << "(" << x << ",";
   }
   if(y<0 && y>-1){
	   cout << setiosflags(ios::fixed);
	   cout << y << ")" <<endl;
		 cout << resetiosflags(ios::fixed);
	 }
	 else{
		cout << y << ")";
	 }
}
inline void Vector::showPolarCord()const
{
	cout << setprecision(5) << fixed;
	 if(magnitude >= 0 && angle >= 0){
		 cout << "\n<r,\xE9> = <" << magnitude << "," << angle * RADIAN << ">";
	 }
	 else{
		 cout << setiosflags(ios::fixed);
		 cout << "\n<r,\xE9> = <" << magnitude << "," << angle * RADIAN << ">";
		 cout << resetiosflags(ios::fixed) << endl;
	 }
}
inline void Vector::showRevolutionAngle()const
{
  cout << "Angle in degrees:  " << revolutionAngle_inDegrees;
}
inline void Vector::show_x() const
{
	cout << "\nx: " << x << endl;
}
inline void Vector::show_y() const
{
	cout << "\ny: " << y << endl;
}
inline void Vector::show_mag() const
{
	cout << "\nr: " << magnitude << endl;
}
inline void Vector::show_angle() const
{
	cout << "\n\xE9: " << angle << "\xF8" << endl;
}
inline void Vector::show_mode()const
{
	if (mode == 'p' || mode == 'P') {
		cout << "\nmode: Polar" << endl;
	}
	else
		cout << "\nmode: Rectangular" << endl;
}
inline void Vector::show_arcLength() const
{
   cout << setprecision(7)<< fixed;
	cout << "\narc length: " << arcLength << endl;
}
inline _ld_ Vector::return_x() const
{
	return x;
}
inline _ld_ Vector::return_y()const
{
	return y;
}
inline _ld_ Vector::return_mag()const
{
	return magnitude;
}
inline _ld_ Vector::return_angle()const
{
	return angle;
}
inline _ld_ Vector::return_arcLength() const
{
	return arcLength;
}
inline char Vector::return_mode()const
{
  return mode;
}
/**
 *method: set_coordinates(_ld_ xMag, _ld_ yAng, char _mode)
* arguments: x, y mode = 'r' or 'p' .by default is 'r'ectangular, 'p'= polar.
* Use 'r'/'R' for rectangular components, 'p'/'P' for polar components
*/
inline void Vector::set_coordinates(_ld_ xMag, _ld_ yAng, char _mode)
{
  validate_setMode();

  if (tolower(_mode) ==  'r') {
	set_rectCord(xMag, yAng);
	adjust_angle();
  }
  else{
	  set_polarCord(xMag, yAng);
	  adjust_angle();
  }
  calculate_arcLength();
}
inline void Vector::set_rectCord(_ld_ _x, _ld_ _y)
{
  x = _x;
  y = _y;
  calculate_polar();
  revolutionAngle_inDegrees = angle;
}
inline void Vector::set_polarCord(_ld_ mag, _ld_ ang)
{
  magnitude = mag;
  normalize_magnitude();
  angle =ang;
  revolutionAngle_inDegrees = ang;
  adjust_angle();
  calculate_rectangular();
}
inline void Vector::set_x(_ld_ _x)
{
  x = _x;
  calculate_polar();
}
inline void Vector::set_y(_ld_ _y)
{
  y = _y;
  calculate_polar();
}
inline void Vector::set_mag(_ld_ mag)
{
  magnitude = mag;
  normalize_magnitude();
  calculate_rectangular();
  calculate_arcLength();
}
inline void Vector::set_angle(_ld_ ang)
{
  angle = ang;
  adjust_angle();
  calculate_arcLength();
  calculate_rectangular();
}
inline void Vector::set_mode(char _mode)
{
  mode = _mode;
  validate_setMode();
}
inline _ld_ Vector::square()const
{
	return  x * x + y * y;
}
inline _ld_ Vector::dot_product(const Vector& vec)const
{
	return  x * vec.x + vec.y * y;
}
inline _ld_ Vector::distance(const Vector& vec)const
{
	_ld_ x1, x2, y1, y2, t1, t2;
	x1 = this->x;
	x2 = vec.x;
	y1 = this->y;
	y2 = vec.y;
	t1 = x2 - x1;
	t2 = y2 - y1;
	return sqrt(pow(t1, 2) + pow(t2, 2));
}
inline _ld_ Vector::cross_product2D(const Vector& v)const
{
	return (x * v.y) - (y * v.x);
}
inline Vector Vector::normalization()
{
	assert(find_magnitude() != 0);  // NOLINT(clang-diagnostic-float-equal)
	*this /= find_magnitude();
	return *this;
}
inline _ld_ Vector::find_magnitude()const
{
	return sqrt(square());
}
/*
void Vector::setPolarCurve()
{
	cout << "\nEnter the Polar Curve to convert to cartiesian equation\n>";
	cin >> Curve.r;
  Curve.x = sqrt(pow(Curve.r, 2) + pow(Curve.y, 2));
  Curve.theta = atan(y / x);
}
*/
inline void Vector::validate_setMode()
{
	do{
		  if (tolower(mode) == 'r' || tolower(mode) == 'p') {
	   break;
		  }
			else {
		cout << "\nEnter a valid mode, r/R for rectangular\n"
			 << "or p/P or polar components\n>";
		cin >> mode;
		cin.clear();
		cin.ignore(100, '\n');
			 }
  }while(!cin || tolower(mode) != 'r' || tolower(mode) != 'p');
}
inline void Vector::normalize_magnitude()
{
  if (magnitude < 0)
	magnitude = abs(magnitude);
}
inline void Vector::calculate_magnitude()
{
   magnitude = sqrt(x * x + y * y);
}
inline void Vector::calculate_angle()
{
	angle = atan2(y, x) * DEGREE;
}
inline void Vector::adjust_angle()
{
  if(angle == -360 || angle == -720 || angle == -1080 || angle == -1440){  // NOLINT(clang-diagnostic-float-equal)
	angle = 0;
  }
	if (angle >= 360){
		const int rev_degrees = static_cast<int>(angle) / 360;
		const int to_subtract = rev_degrees *360;
		const _ld_ new_angle = angle - to_subtract;
		angle = new_angle;
	}else if (angle < 0 && angle > -360){
		angle += 360;
		cout <<"test:" << angle << endl;
	}else if(angle < -360){
		const int rev_degrees = static_cast<int>(angle) /360;
		const int to_subtract = rev_degrees *360;
		const _ld_ newAngle = angle - to_subtract + 360;
		angle = newAngle;
	}
}
inline void Vector::calculate_rectangular()
{
  x = magnitude* cos(angle*RADIAN);
  y = magnitude* sin(angle*RADIAN);
}
inline void Vector::calculate_polar()
{
	 magnitude = sqrt(x * x + y * y);
	if (x == 0.0 && y == 0.0)
		angle = 0.0;
	else
		angle = atan2(y, x)*DEGREE;

	adjust_angle();
	calculate_arcLength();
	revolutionAngle_inDegrees = angle;
}
inline void Vector::calculate_arcLength()
{
  adjust_angle();
  arcLength = (_PI_ * (magnitude*2)) *
		(angle / 360.0);
}
inline Vector Vector::check_division(_ld_ d)
{
	return *this;
}
inline Vector Vector::check_division(Vector d)
{
	Vector temp;
	return temp;
}
inline bool Vector::operator<(const Vector &v) const
{
  if (magnitude < v.magnitude)
	return true;
  return false;
}
inline bool Vector::operator<=(const Vector& v) const
{
	if (magnitude <= v.magnitude)
		return true;
	return false;
}
inline bool Vector::operator>(const Vector & v)const
{
  if (magnitude > v.magnitude)
	return true;
  return false;
}
inline bool Vector::operator>=(const Vector& v) const
{
	if (magnitude >= v.magnitude)
		return true;

	return false;  // NOLINT(clang-diagnostic-misleading-indentation)
}
inline bool Vector::operator==(const Vector & v)const
{
  if (magnitude == v.magnitude && angle == v.angle)  // NOLINT(clang-diagnostic-float-equal)
	return true;
  return false;
}
inline bool Vector::operator!=(const Vector& v) const
{
	if (!(magnitude == v.magnitude && angle == v.angle))  // NOLINT(clang-diagnostic-float-equal)
		return true;
	else
		return false;
}
inline Vector Vector::operator+(const _ld_ n)const
{
	cout << "in  Vector::operator+(const _ld_ n)const"<<endl;
	Vector total(x + n, y + n);
	total.mode = mode;
	return total;
}
inline Vector& Vector::operator+=(const Vector& v)
{
	cout << "in Vector& Vector::operator+=(const Vector& v)" << endl;
	Vector sum;
	sum.x += v.x;
	sum.y += v.y;
	sum.mode = v.mode;
	return *this;
}
inline Vector Vector::operator+(const Vector& v)const
{
	cout << "in  Vector::operator+(const Vector& v)const"<<endl;
  Vector sum(x + v.x, y + v.y);
  sum.mode = mode;
  return sum;
}
inline Vector Vector::operator+()const
{
	cout << "in  Vector::operator+()const"<<endl;
	Vector total(x+x, y+y);
	total.mode = mode;
  return total;
}
inline Vector Vector::operator++()
{
	Vector sum(++x, ++y);
	sum.mode = mode;
  return sum;
}
inline Vector Vector::operator++(int)
{
  Vector sum(x++, y++, mode);
  return sum;
}
inline Vector Vector::operator-(const Vector& v) const
{
  Vector sum(x-v.x, y-v.y, mode);
  return sum;
}
inline Vector Vector::operator-(const _ld_ number)const
{
	Vector total(x - number, y - number);
	total.mode = mode;
	return total;
}
inline Vector Vector::operator-()const
{
	Vector total(-x, -y);
	total.mode = mode;
  return total;
}
inline Vector Vector::operator--()
{
  Vector difference(--x, --y);
  difference.mode = mode;
  return difference;
}
inline Vector Vector::operator--(int)
{
  Vector difference(x--, y--);
  difference.mode = mode;
  return difference;
}
inline Vector operator-(_ld_ s, Vector& v)
{
 Vector total(s-v.return_x(),s-v.return_y(),v.return_mode());
 return total;
}
inline Vector operator+(_ld_ s, Vector& v)
{
 Vector total(s+v.return_x(),s+v.return_y(),v.return_mode());
 return total;
}
inline Vector& Vector::operator=(const Vector &right)
{
  if (this != &right) {

		x = right.x;
		y = right.y;
		calculate_polar();
		calculate_arcLength();
	}
  return *this;
}
inline Vector& Vector::operator=(const Vector *vec)
{
  x = vec->x;
  y = vec->y;
  calculate_polar();
  calculate_arcLength();
  return *this;
}
inline Vector& Vector::operator=(Vector&& right)noexcept
{
	 if (this != &right)
	 {
		 swap(x, right.x);
		 swap(y, right.y);
		 this->calculate_polar();
	 }
	 return *this;
}
inline Vector::Vector(Vector&& temp) noexcept
{
	_vptr2d = nullptr;
	x = temp.x;
	y = temp.y;
	mode = temp.mode;
	calculate_polar();
	calculate_arcLength();
	revolutionAngle_inDegrees = return_angle();
	angle = return_angle();
	magnitude = return_mag();
	arcLength = return_arcLength();
	calculate_arcLength();
}
inline Vector Vector::operator/(_ld_ d)
{
	return check_division(d);
}
inline Vector Vector::operator/(int d)
{
	return check_division(d);
}
inline Vector Vector::operator/(Vector v)
{
	return check_division(v);
}
inline Vector &Vector::operator/=(_ld_ value)
{
	x /= value;
	y /= value;
	calculate_polar();
	calculate_angle();
	return *this;

}
inline Vector Vector::operator*(const _ld_ scalar)const
{
	Vector results(x*scalar, y*scalar);
	results.mode = mode;
	return results;
}
inline Vector operator*(_ld_ s, Vector& v)
{
  return v * s;
}
inline Vector operator*(Vector& v, Vector& s)
{
   Vector results(v.x*s.x, v.y*s.y, v.mode);
   return results;
}
inline ostream& operator<<(ostream& os, const Vector& v)
{
  if(v.mode == 'R' || v.mode == 'r'){
	v.showRectCord();
  }
  else{
	v.showPolarCord();
  }
  return os;
}
inline istream& operator>>(istream& is, Vector& v)
{
  if(v.mode == 'R' || v.mode == 'r'){
	is>> v.x >> v.y;
	v.calculate_polar();
  }
  else{
	is>> v.magnitude >> v.angle;
	v.calculate_rectangular();
  }
  return is;
}
inline Vector::~Vector()
{
	delete _vptr2d;
	countDecrease();
	//countShow();
}


