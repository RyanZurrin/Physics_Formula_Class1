#pragma once
//author:	Ryan Zurrin
//file:		Vector2D2d.h
// Specification file for a  Vector2D class
#ifndef Vector2D_H
#define Vector2D_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cassert>

typedef long double _ld_;
using namespace std;


constexpr auto _PI_ = 3.14159265359;
constexpr auto DEGREE = 180/_PI_;
constexpr auto RADIAN = _PI_/180;
constexpr auto _Ga_ = 9.81;
static int object_counter = 0;

class Vector2D
{

   friend class Vector3D;
   //friend class Physics;

public:
	char mode;  //sets mode to Polar w/ 'p' or Rectangular w/ 'r'

	Vector2D(string id = ""); //default constructor
	Vector2D(char, string id = "");//mode select, defaults to 0, in rectangular, constructor
	Vector2D(_ld_, _ld_, char _mode = 'r', string id = ""); //constructor takes both coordinates and mode
	Vector2D(const Vector2D &, string id = "");	//copy constructor
	void displayAllData(std::string label = "")const; //virtual so any derived classes must redefine
	void display()const;
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
	_ld_ projection(Vector2D&)const;
	_ld_ angle_between_vectors(Vector2D&)const;
	_ld_ square()const;              //gives square o_ld_ the Vector2D
	_ld_ find_magnitude()const;             //magnitude o_ld_ the Vector2D
	_ld_ dot_product(const Vector2D&)const; //scalar dot_product
	_ld_ distance(const Vector2D&)const;    //gives distance between two Vector2Ds
	_ld_ cross_product(const Vector2D&)const;    //cross_product
	Vector2D normalize_Vector2D();   //normalized Vector2D
	 //virtual void setParametricPoints();

	bool operator>(const Vector2D &)const;
	bool operator>=(const Vector2D&)const;
	bool operator<(const Vector2D &)const;
	bool operator<=(const Vector2D&)const;
	bool operator==(const Vector2D &)const;
	bool operator!=(const Vector2D&)const;
	bool operator>(const _ld_& n)const { return magnitude > n; }
	bool operator>=(const _ld_& n)const { return magnitude >= n; }
	bool operator<(const _ld_& n)const { return magnitude < n; }
	bool operator<=(const _ld_& n)const { return magnitude <= n; }
	bool operator==(const _ld_& n)const { return magnitude == n; }
	bool operator!=(const _ld_& n)const { return !(magnitude == n); }

	Vector2D operator+(const Vector2D &)const;
	Vector2D operator+(_ld_ number)const;
	Vector2D &operator+=(const Vector2D &);
	Vector2D operator+()const;
	Vector2D operator++();
	Vector2D operator++(int);
	Vector2D operator-(const Vector2D&) const;
	Vector2D operator-(const _ld_ number)const;
	Vector2D operator-()const;
	Vector2D operator--();
	Vector2D operator--(int);
	Vector2D& operator=(const Vector2D &);
	Vector2D &operator=(const Vector2D *);
	Vector2D &operator=(Vector2D&& right)noexcept;
	Vector2D(Vector2D&& temp)noexcept;

	Vector2D operator*(_ld_)const;

	friend Vector2D operator*(_ld_ s, Vector2D& v);
	friend Vector2D operator*(Vector2D& v, Vector2D& s);
	friend Vector2D operator-(_ld_ s, Vector2D& v);
	friend Vector2D operator+(_ld_ s, Vector2D& v);
	friend ostream& operator<<(ostream&, const Vector2D&);
	friend istream& operator>>(istream&, Vector2D&);

	virtual ~Vector2D();

private:
	string ID;
	Vector2D* _vPtr2d;
	_ld_ x;
	_ld_ y;
	_ld_ magnitude;
	_ld_ angle;
	_ld_ arcLength;
	_ld_ revolutionAngle_inDegrees;
	static void countShow() { std::cout << "Vector2D count: " << object_counter << std::endl; }
	//void    calculate_parametric_equation();
	void 	 validate_setMode();
	void    normalize_magnitude();
	void    calculate_magnitude();
	void    calculate_angle();
	void    adjust_angle();
	void    calculate_rectangular();
	void    calculate_polar();
	void    calculate_arcLength();
	static void countIncrease() { object_counter += 1; }
	static void countDecrease() { object_counter -= 1; }
};
#endif
//=============================================================================
//in-line class Implementation

inline Vector2D::Vector2D(string id)
{
  _vPtr2d =  nullptr;
  ID = id;
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

inline Vector2D::Vector2D(char _mode, string id)
{
  _vPtr2d =  nullptr;
  ID = id;
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
inline Vector2D::Vector2D(_ld_ xMag, _ld_ yAng, char _mode, string id)
{
	revolutionAngle_inDegrees = 0;
	ID = id;
	magnitude = 0;
	angle = 0;
	mode = _mode;
	validate_setMode();
	x = xMag;
	y = yAng;
	set_coordinates(x, y, _mode);
	calculate_arcLength();
	arcLength = return_angle();
	_vPtr2d =  nullptr;
	countIncrease();

}
inline Vector2D::Vector2D(const Vector2D &v, string id)
{

	ID = id;
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
	_vPtr2d =  nullptr;
	countIncrease();
}
inline void Vector2D::displayAllData(std::string label)const
{
  std::cout << ((label == "") ? ID : label) << std::endl;
  showRectCord();
  showPolarCord();
  showRevolutionAngle();
  show_arcLength();
}
inline void Vector2D::display()const
{
  if (mode == 'r' || mode == 'R') {
   showRectCord();
  }
  else {
   showPolarCord();
  }
}

inline void Vector2D::showRectCord()const
{
	 cout << setprecision(9) << fixed;

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
inline void Vector2D::showPolarCord()const
{
	cout << setprecision(9) << fixed;
	 if(magnitude >= 0 && angle >= 0){
		 cout << "\n<r,\xE9> = <" << magnitude << "," << angle * RADIAN << ">";
	 }
	 else{
		 cout << setiosflags(ios::fixed);
		 cout << "\n<r,\xE9> = <" << magnitude << "," << angle * RADIAN << ">";
		 cout << resetiosflags(ios::fixed) << endl;
	 }
}
inline void Vector2D::showRevolutionAngle()const
{
  cout << "Angle in degrees:  " << revolutionAngle_inDegrees;
}
inline void Vector2D::show_x() const
{
	cout << "\nx: " << x << endl;
}
inline void Vector2D::show_y() const
{
	cout << "\ny: " << y << endl;
}
inline void Vector2D::show_mag() const
{
	cout << "\nr: " << magnitude << endl;
}
inline void Vector2D::show_angle() const
{
	cout << "\n\xE9: " << angle << "\xF8" << endl;
}
inline void Vector2D::show_mode()const
{
	if (mode == 'p' || mode == 'P') {
		cout << "\nmode: Polar" << endl;
	}
	else
		cout << "\nmode: Rectangular" << endl;
}
inline void Vector2D::show_arcLength() const
{
   cout << setprecision(7)<< fixed;
	cout << "\narc length: " << arcLength << endl;
}
inline _ld_ Vector2D::return_x() const
{
	return x;
}
inline _ld_ Vector2D::return_y()const
{
	return y;
}
inline _ld_ Vector2D::return_mag()const
{
	return magnitude;
}
inline _ld_ Vector2D::return_angle()const
{
	return angle;
}
inline _ld_ Vector2D::return_arcLength() const
{
	return arcLength;
}
inline char Vector2D::return_mode()const
{
  return mode;
}
/**
 *method: set_coordinates(_ld_ xMag, _ld_ yAng, char _mode)
* arguments: x, y mode = 'r' or 'p' .by default is 'r'ectangular, 'p'= polar.
* Use 'r'/'R' for rectangular components, 'p'/'P' for polar components
*/
inline void Vector2D::set_coordinates(_ld_ xMag, _ld_ yAng, char _mode)
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
inline void Vector2D::set_rectCord(_ld_ _x, _ld_ _y)
{
  x = _x;
  y = _y;
  calculate_polar();
  revolutionAngle_inDegrees = angle;
}
inline void Vector2D::set_polarCord(_ld_ mag, _ld_ ang)
{
  magnitude = mag;
  normalize_magnitude();
  angle =ang;
  revolutionAngle_inDegrees = ang;
  adjust_angle();
  calculate_rectangular();
}
inline void Vector2D::set_x(_ld_ _x)
{
  x = _x;
  calculate_polar();
}
inline void Vector2D::set_y(_ld_ _y)
{
  y = _y;
  calculate_polar();
}
inline void Vector2D::set_mag(_ld_ mag)
{
  magnitude = mag;
  normalize_magnitude();
  calculate_rectangular();
  calculate_arcLength();
}
inline void Vector2D::set_angle(_ld_ ang)
{
  angle = ang;
  adjust_angle();
  calculate_arcLength();
  calculate_rectangular();
}
inline void Vector2D::set_mode(char _mode)
{
  mode = _mode;
  validate_setMode();
}
inline _ld_ Vector2D::projection(Vector2D& v) const
{
	const auto Θ = this->angle_between_vectors(v);

	return this->magnitude * cos(Θ * RADIAN);
}
inline _ld_ Vector2D::angle_between_vectors(Vector2D& v) const
{
	return acos(this->dot_product(v) / (this->magnitude * v.magnitude)) * DEGREE;
}
inline _ld_ Vector2D::square()const
{
	return  x * x + y * y;
}
inline _ld_ Vector2D::dot_product(const Vector2D& vec)const
{
	return  x * vec.x + vec.y * y;
}
inline _ld_ Vector2D::distance(const Vector2D& vec)const
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
inline _ld_ Vector2D::cross_product(const Vector2D& v)const
{
	return (x * v.y) - (y * v.x);
}
inline Vector2D Vector2D::normalize_Vector2D()
{
	assert(find_magnitude() != 0);  // NOLINT(clang-diagnostic-float-equal)
	const auto length = sqrt((this->x * this->x) + (this->y * this->y));
	this->x /= length;
	this->y /= length;
	calculate_polar();
	calculate_angle();
	adjust_angle();
	calculate_arcLength();
	return *this;
}
inline _ld_ Vector2D::find_magnitude()const
{
	return sqrt(square());
}
/*
void Vector2D::setPolarCurve()
{
	cout << "\nEnter the Polar Curve to convert to cartiesian equation\n>";
	cin >> Curve.r;
  Curve.x = sqrt(pow(Curve.r, 2) + pow(Curve.y, 2));
  Curve.theta = atan(y / x);
}
*/
inline void Vector2D::validate_setMode()
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
inline void Vector2D::normalize_magnitude()
{
  if (magnitude < 0)
	magnitude = abs(magnitude);
}
inline void Vector2D::calculate_magnitude()
{
   magnitude = sqrt(x * x + y * y);
}
inline void Vector2D::calculate_angle()
{
	angle = atan2(y, x) * DEGREE;
}
inline void Vector2D::adjust_angle()
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
	}else if(angle < -360){
		const int rev_degrees = static_cast<int>(angle) /360;
		const int to_subtract = rev_degrees *360;
		const _ld_ newAngle = angle - to_subtract + 360;
		angle = newAngle;
	}
}
inline void Vector2D::calculate_rectangular()
{
  x = magnitude* cos(angle*RADIAN);
  y = magnitude* sin(angle*RADIAN);
}
inline void Vector2D::calculate_polar()
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
inline void Vector2D::calculate_arcLength()
{
  adjust_angle();
  arcLength = (_PI_ * (magnitude*2)) *
		(angle / 360.0);
}

inline bool Vector2D::operator<(const Vector2D &v) const
{
  return magnitude < v.magnitude;
}
inline bool Vector2D::operator<=(const Vector2D& v) const
{
	return magnitude <= v.magnitude;
}
inline bool Vector2D::operator>(const Vector2D & v)const
{
  return magnitude > v.magnitude;
}
inline bool Vector2D::operator>=(const Vector2D& v) const
{
	return magnitude >= v.magnitude;
}
inline bool Vector2D::operator==(const Vector2D & v)const
{
	return magnitude == v.magnitude && angle == v.angle;
}
inline bool Vector2D::operator!=(const Vector2D& v) const
{
	return !(magnitude == v.magnitude && angle == v.angle);
}
inline Vector2D Vector2D::operator+(const _ld_ n)const
{
	//cout << "in  Vector2D::operator+(const _ld_ n)const"<<endl;
	Vector2D total(x + n, y + n);
	total.mode = mode;
	return total;
}
inline Vector2D& Vector2D::operator+=(const Vector2D& v)
{
	//cout << "in Vector2D& Vector2D::operator+=(const Vector2D& v)" << endl;
	Vector2D sum;
	sum.x += v.x;
	sum.y += v.y;
	sum.mode = v.mode;
	return *this;
}
inline Vector2D Vector2D::operator+(const Vector2D& v)const
{
  //cout << "in  Vector2D::operator+(const Vector2D& v)const"<<endl;
  Vector2D resultant(x + v.x, y + v.y, this->mode);
  return resultant;
}
inline Vector2D Vector2D::operator+()const
{
	//cout << "in  Vector2D::operator+()const"<<endl;
	Vector2D resultant(x+x, y+y, this->mode);
  return resultant;
}
inline Vector2D Vector2D::operator++()
{
	Vector2D resultant(++x, ++y, this->mode);
  return resultant;
}
inline Vector2D Vector2D::operator++(int)
{
  Vector2D resultant(x++, y++, mode);
  return resultant;
}
inline Vector2D Vector2D::operator-(const Vector2D& v) const
{
  Vector2D resultant(x-v.x, y-v.y, mode);
  return resultant;
}
inline Vector2D Vector2D::operator-(const _ld_ n)const
{
	Vector2D resultant(x - n, y - n, this->mode);
	return resultant;
}
inline Vector2D Vector2D::operator-()const
{
	Vector2D resultant(-x, -y, this->mode);
  return resultant;
}
inline Vector2D Vector2D::operator--()
{
  Vector2D resultant(--x, --y, this->mode);
  return resultant;
}
inline Vector2D Vector2D::operator--(int)
{
  Vector2D resultant(x--, y--, this->mode);
  return resultant;
}
inline Vector2D operator-(_ld_ s, Vector2D& v)
{
 Vector2D resultant(s-v.return_x(),s-v.return_y(),v.return_mode());
 return resultant;
}
inline Vector2D operator+(_ld_ s, Vector2D& v)
{
 Vector2D resultant(s+v.return_x(),s+v.return_y(),v.return_mode());
 return resultant;
}
inline Vector2D& Vector2D::operator=(const Vector2D &right)
{
  if (this != &right) {

		x = right.x;
		y = right.y;
		calculate_polar();
		calculate_arcLength();
	}
  return *this;
}
inline Vector2D& Vector2D::operator=(const Vector2D *vec)
{
  x = vec->x;
  y = vec->y;
  calculate_polar();
  calculate_arcLength();
  return *this;
}
inline Vector2D& Vector2D::operator=(Vector2D&& right)noexcept
{
	 if (this != &right)
	 {
		 swap(x, right.x);
		 swap(y, right.y);
		 this->calculate_polar();
	 }
	 return *this;
}
inline Vector2D::Vector2D(Vector2D&& temp) noexcept
{
	_vPtr2d = nullptr;
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

inline Vector2D Vector2D::operator*(const _ld_ scalar)const
{
	Vector2D results(x*scalar, y*scalar);
	results.mode = mode;
	return results;
}
inline Vector2D operator*(_ld_ s, Vector2D& v)
{
  return v * s;
}
inline Vector2D operator*(Vector2D& v, Vector2D& s)
{
   Vector2D results(v.x*s.x, v.y*s.y, v.mode);
   return results;
}
inline ostream& operator<<(ostream& os, const Vector2D& v)
{
  if(v.mode == 'R' || v.mode == 'r'){
	v.showRectCord();
  }
  else{
	v.showPolarCord();
  }
  return os;
}
inline istream& operator>>(istream& is, Vector2D& v)
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
inline Vector2D::~Vector2D()
{
	delete _vPtr2d;
	countDecrease();
	//countShow();
}


