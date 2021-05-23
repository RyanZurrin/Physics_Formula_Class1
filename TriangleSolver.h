#pragma once
// Part of a final project in c++ II, this program as a whole
// will calculate the properties of 2D and 3D objects and vectors

// prgrammer:   Ryan Zurrin

#ifndef  TRIANGLE_SOLVER_H
#define  TRIANGLE_SOLVER_H
#include <cmath>
#include <string>
#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
#include "Vector2D.h"

static int counter = 0;
//using namespace std;

// use the char name as a mode selector in the constructor followed by the
// three values being entered all seperated by commas of course.
//  example->  Triangle exampleConstruct(ssa, 12.5, 9, 75);   <-sample

// sss uses the the sides_a than side_b than side_c for input order
const char sss = 's'; // sidea sideb sidec input

// sas uses the side a, angle C, than side b for input order
const char sas = 'a'; // side angle side between

// ssa uses side a, side b, angle A as input order
const char ssa = 'b'; // side side angle not between

// all angles cant be solved further will ask for one side length
const char aaa = 'l'; // all angles *cant go further need to have a side too

// asa uses angle
const char asa = 'i'; // angleA side_c angleB side between

// asa uses angle A then angle C then side c, as the unput sides at the moment
const char aas = 'n';  // angle angle side not between


class TriangleSolver
{
	//friend class ExceptionHandler;

public:
	TriangleSolver* _triPtr;
	double max_side;
	double height_a, altHeight_a;
	double height_b, altHeight_b;
	double height_c, altHeight_c;
	double max_height;
	double side_a;
	double side_b;
	double side_c, altSide;
	double angle_A, altAngle_A;
	double angle_B, altAngle_B;
	double angle_C, altAngle_C;
	double area, altArea;
	double perimeter, altPerimeter;
	double sVal, altSval; // Semiperimeter
	double rVal, altRval; // Circumradius
	double iVal, altIval; // inradius
	// these bools are for determining cungruency and type
	double median_a, altMedian_a;
	double median_b, altMedian_b;
	double median_c, altMedian_c;
	bool   sssFlag,
		   aaaFlag,
		   sasFlag,
		   ssaFlag,
		   asaFlag,
		   aasFlag,
		   missingSideFlag,
		   altTriFlag;
	// these are char flag variables to add to constructor to define what data you are entering


	string sideType;
	string angleType;


	double pythagoreanTheorem(double, double)const;
	void update_triangle();
	//ExceptionHandler catcher;
	struct TriangleAsCartesianPoints
	{
		pair<double, double> pt1;
		pair<double, double> pt2;
		pair<double, double> pt3;
	}cTri;

	void makeTriangleAsPoints();

	TriangleSolver();

	/// <summary>
	/// Initializes a new instance of the <see cref="TriangleSolver"/> class.\n
	/// mode types: sss='s', sas='a', ssa ='b', aaa='l', asa='i', aas='n'\n
	/// side, side, side(sss)\n
	/// side angle side(sas)\n
	/// side, side, angle(ssa)\n
	/// angleA, angleB, angleC(aaa)\n
	/// angleA ,side_c, angleB (asa)\n
	///	angleA angleC side_c (aas)\n
	/// </summary>
	/// <param name="m">The mode.</param>
	/// <param name="s1">The s1.</param>
	/// <param name="a">a.</param>
	/// <param name="s2">The s2.</param>
	TriangleSolver(double, double, double,char = 's');

	TriangleSolver(const TriangleSolver&); // copy constructor
	TriangleSolver make2rights(); // makes two 90 degree triangles by modifiying itself and returning the other part to new object.
	TriangleSolver& operator=(const TriangleSolver& right)noexcept; //self assignment

	void check_SSS(TriangleSolver&);// by Arnab Kundu
	void check_SAS(TriangleSolver&);
	void check_AAA(TriangleSolver&);

	[[nodiscard]] bool checkSides()const;
	[[nodiscard]] bool checkTriangle()const;
	[[nodiscard]] bool checkAngles()const;
	void triangleTypeBySide();
	void triangleTypeByAngle();
	bool checkCongruent(TriangleSolver& T);
	void congruentBy(TriangleSolver&);

	void displayTriangleData()const;
	void showTriangleSides()const;
	void showTriangleAngles()const;
	void showAngleType()const;
	void showTriangleAreaPerimeter()const;
	void showSide_a()const { cout << "side a: " << side_a<< endl; }
	void showSide_b()const { cout << "side b: " << side_b << endl; }
	void showSide_c()const { cout << "side c: " << side_c << endl; }
	void showAngle_A()const { cout << "angle A: " << angle_A<< endl; }
	void showAngle_B()const { cout << "angle B: " << angle_B<< endl; }
	void showAngle_C()const { cout << "angle C: " << angle_C<< endl; }
	void showArea()const { cout << "area: " << area << endl; }
	void showParameter()const { cout << "parameter: "<< perimeter<< endl; }
	void showMaxHeight()const { cout << "Max Height: " << max_height << endl; }
	void showHeight_a()const { cout << "height_a: " << height_a << endl; }
	void showHeight_b()const { cout << "height_b: " << height_b << endl; }
	void showHeight_c()const { cout << "height_c: " << height_c << endl; }
	void showMedian_a()const { cout << "median_a: " << median_a << endl; }
	void showMedian_b()const { cout << "median_b: " << median_b << endl; }
	void showMedian_c()const { cout << "median_c: " << median_c << endl; }
	static void showVertex();
	void showAllHeights()const {
		cout << "height_a: " << height_a << endl
			 << "height_b: " << height_b << endl
			 << "height_c: " << height_c << endl;
	}
	void showAllMedians()const {
		cout << "median_a: " << median_a << endl
			 << "median_b: " << median_b << endl
			 << "median_c: " << median_c << endl;
	}
	void showLargestSide()const { cout << "base: " << max_side << endl; }
	void showCircumradius()const { cout << "circum-radius: " << rVal << endl; }
	void showInRadius()const { cout << "in-radius: " << iVal << endl; }
	void showSemiParameter()const { cout << "semi-parameter: " << sVal << endl; }
	void showCongruencyFlags()const;
	static void showTriangleAsCartesianPoints();


	[[nodiscard]] double returnSide_a()const { return side_a; }
	[[nodiscard]] double returnSide_b()const { return side_b; }
	[[nodiscard]] double returnSide_c()const { return side_c; }
	[[nodiscard]] double returnAngle_A()const { return angle_A; }
	[[nodiscard]] double returnAngle_B()const { return angle_B; }
	[[nodiscard]] double returnAngle_C()const { return angle_C; }
	[[nodiscard]] double returnArea()const { return area; };
	[[nodiscard]] double returnPerimeter()const { return perimeter; }
	[[nodiscard]] double returnBase()const { return max_side; }
	[[nodiscard]] double returnMaxHeight()const { return max_height; }
	[[nodiscard]] double returnHeight_a()const { return height_a; }
	[[nodiscard]] double returnHeight_b()const { return height_a; }
	[[nodiscard]] double returnHeight_c()const { return height_c; }
	[[nodiscard]] double returnMedian_a()const { return median_a; }
	[[nodiscard]] double returnMedian_b()const { return median_b; }
	[[nodiscard]] double returnMedian_c()const { return median_c; }
	[[nodiscard]] double returnCircumradius()const { return rVal; }
	[[nodiscard]] double returnSemiPerimeter()const { return sVal; }
	[[nodiscard]] bool returnSAS()const { return sasFlag; }
	[[nodiscard]] bool returnSSS() const { return sssFlag; }
	[[nodiscard]] bool returnAAA() const { return aaaFlag; }
	[[nodiscard]] bool returnSSA()const { return ssaFlag; }
	[[nodiscard]] bool returnASA() const { return asaFlag; }
	[[nodiscard]] bool returnAAS() const { return aasFlag; }

	void setSide_a(double _a);
	void setSide_b(double _b);
	void setSide_c(double _c);
	void setSides(double, double, double);
	void setAngles(double, double, double);
	static int getCount() { return counter; }
	//double setAngle_A(double _A) { angle_A = _A; update_triangle(); }
	//double setAngle_B(double _B) { angle_B = _B; update_triangle(); }
	//double setAngle_C(double _C) { angle_C = _C; update_triangle(); }
	//double setTriangleArea(double tA) { area = tA; update_triangle(); }


	//overloaded relational operators
	bool operator>(const TriangleSolver& s)const { return area > s.area; }
	bool operator>=(const TriangleSolver& s)const { return area >= s.area; }
	bool operator<(const TriangleSolver& s)const { return area < s.area; }
	bool operator<=(const TriangleSolver& s)const { return area <= s.area; }
	bool operator==(const TriangleSolver& s)const { return area == s.area; }
	bool operator!=(const TriangleSolver& s)const { return !(area == s.area); }
	bool operator>(const double& n)const { return area > n; }
	bool operator>=(const double& n)const { return area >= n; }
	bool operator<(const double& n)const { return n < area; }
	bool operator<=(const double& n)const { return n <= area; }
	bool operator==(const double& n)const { return area == n; }
	bool operator!=(const double& n)const { return !(area == n); }

	//overloaded additon operators

	TriangleSolver operator+()const;
	TriangleSolver operator++()const;
	TriangleSolver operator++(int)const;
	TriangleSolver operator+(const TriangleSolver&)const;
	TriangleSolver operator+(double);
	TriangleSolver& operator+=(const TriangleSolver&);
	friend TriangleSolver operator+(double num, TriangleSolver&);
	//friend Triangle operator+(Triangle lhs, const Triangle&);

	// overloaded subtraction operators
	TriangleSolver operator-()const;
	TriangleSolver operator--()const;
	TriangleSolver operator--(int)const;
	TriangleSolver operator-(const TriangleSolver&)const;
	TriangleSolver operator-(double)const;
	TriangleSolver& operator-=(const TriangleSolver&);
	friend TriangleSolver operator-(double num, TriangleSolver&);
	//friend Triangle operator-(Triangle lhs, const Triangle&);

	TriangleSolver operator*(double value)const;   // multiply

	friend TriangleSolver operator*(double s, TriangleSolver& v);
	friend TriangleSolver operator*(TriangleSolver& v, TriangleSolver& s);
	TriangleSolver operator/(double)const;    //division
	TriangleSolver operator/(const TriangleSolver&)const;


	friend ostream& operator<<(ostream&, const TriangleSolver&);
	friend istream& operator>>(istream&, TriangleSolver&);
	/*
	operator float();
	operator double();
	operator int();
	operator string();
	*/

	~TriangleSolver()
	{
		counter--;
	}


private:
	void badTriangle();
	template<typename T>
	T negativeNumCheck(T& num);
	template<typename T>
	T negativeNumFix(T& num);
	//double sVal;
	//double rVal;
	void initiate_triangle();
	void calculate_angleA();
	void calculate_angleB();
	void calculate_angleC();
	void calculate_All_angles();
	void calculate_AllHeight();
	void calculate_heightBase_a(),
			 calculate_heightBase_b(),
			 calculate_heightBase_c();
	void calculate_medians_abc();
	void findMissingSide();
	void find_base();
	void calculate_area();
	void calculate_perimeter();
	void calculate_rVal();
	void calculate_sVal();
	void calculate_iVal();
	TriangleSolver *solve_by_AAA(double&, double&, double&); // three sides known
	TriangleSolver *solve_by_AAS(double&, double&, double&); // two angles and a side not between
	TriangleSolver *solve_by_ASA(double&, double&, double&); // two angles and a side bewteen them
	TriangleSolver *solve_by_SAS(double&, double&, double&); // two sides and the included angle.
	TriangleSolver *solve_by_SSA(double&, double&, double&); //  two sides and one angle that is not the included angle
	TriangleSolver *solve_by_SSS(double&, double&, double&); //  all three sides of a triangle, but no angles

};

#endif // ! TRIANGLE_H

inline void TriangleSolver::makeTriangleAsPoints()
{
}

/*______________________________________________________________________________
*/
inline TriangleSolver::TriangleSolver()
{
	initiate_triangle();
	counter++;
}


inline TriangleSolver::TriangleSolver(double s1, double a, double s2,char m)
{	//sss='s', sas='a', ssa ='b', aaa='l', asa='i', aas='n'
	initiate_triangle();
	counter++;
	if (m == 's') // side, side, side(sss)
	{
		solve_by_SSS(s1, a, s2);
	}
	else if (m == 'a') // side angle side(sas)
	{
		solve_by_SAS(s1, a, s2);
	}
	else if (m == 'b') // side, side, angle(ssa)
	{
		solve_by_SSA(s1, a, s2);
	}
	else if (m == 'l') // angleA, angleB, angleC(aaa)
	{
		solve_by_AAA(s1, a, s2);
	}

	else if (m == 'i') // angleA ,side_c, angleB (asa)
	{
		solve_by_ASA(s1, a , s2);
	}
	else if (m == 'n') // angleA angleC side_c (aas)
	{
		solve_by_AAS(s1, a, s2);
	}
}

inline TriangleSolver::TriangleSolver(const TriangleSolver& t)
{
	counter++;
	_triPtr = t._triPtr;
	side_a = t.side_a;
	side_b = t.side_b;
	side_c = t.side_c;
	altSide = t.altSide;
	angle_A = t.angle_A;
	angle_B = t.angle_B;
	angle_C = t.angle_C;
	altAngle_A = t.altAngle_A;
	altAngle_B = t.altAngle_B;
	altAngle_C = t.altAngle_C;
	perimeter = t.perimeter;
	altPerimeter = t.altPerimeter;
	max_height = t.max_height;
	max_side = t.max_side;
	sVal = t.sVal;
	rVal = t.rVal;
	iVal = t.iVal;
	altRval = t.altRval;
	altSval = t.altSval;
	altIval = t.altIval;
	area = t.area;
	altArea = t.altArea;
	sideType = t.sideType;
	sssFlag = t.sssFlag;
	aaaFlag = t.aaaFlag;
	sasFlag = t.sasFlag;
	ssaFlag = t.ssaFlag;
	asaFlag = t.asaFlag;
	aasFlag = t.aasFlag;
	altTriFlag = t.altTriFlag;
	height_a = t.height_a;
	height_b = t.height_b;
	height_c = t.height_c;
	altHeight_a = t.altHeight_a;
	altHeight_b = t.altHeight_b;
	altHeight_c = t.altHeight_c;
	median_a = t.median_a;
	median_b = t.median_b;
	median_c = t.median_c;
	altMedian_a = t.altMedian_a;
	altMedian_b = t.altMedian_b;
	altMedian_c = t.altMedian_c;
	missingSideFlag = t.missingSideFlag;

	//return *this;
}


inline TriangleSolver& TriangleSolver::operator=(const TriangleSolver& right)noexcept
{
	//cout << "in the overloaded Triangle =operator";
	if (this != &right) {
		side_a = right.side_a;
		side_b = right.side_b;
		side_c = right.side_c;
		update_triangle();
	}
	return *this;
}

inline TriangleSolver TriangleSolver::make2rights()
{
	return TriangleSolver();
}
/*______________________________________________________________________________
*/

inline void TriangleSolver::update_triangle()
{

	if (angle_C > 0 && missingSideFlag == 1) {
		calculate_perimeter();
		calculate_sVal();
		calculate_area();
		calculate_rVal();
		calculate_iVal();
		calculate_angleA();
		calculate_angleB();
		find_base();
		calculate_AllHeight();
		calculate_medians_abc();
		triangleTypeByAngle();
		triangleTypeBySide();
	}
	else if (max_side > 0 && max_height > 0) {
		calculate_area();
		calculate_All_angles();
		calculate_rVal();
		calculate_sVal();
		calculate_perimeter();
		calculate_iVal();
		calculate_AllHeight();
		calculate_medians_abc();
		triangleTypeByAngle();
		triangleTypeBySide();
	}
	else if (side_a > 0 && side_b > 0 && side_c > 0 &&
		angle_A > 0 && angle_B > 0 && angle_C > 0)
	{
		calculate_perimeter();
		calculate_sVal();
		calculate_area();
		calculate_rVal();
		calculate_iVal();
		find_base();
		calculate_AllHeight();
		calculate_medians_abc();
		triangleTypeByAngle();
		triangleTypeBySide();
	}
	else {
		calculate_perimeter();
		calculate_sVal();
		calculate_area();
		calculate_rVal();
		calculate_iVal();
		calculate_angleA();
		calculate_angleB();
		calculate_angleC();
		find_base();
		calculate_AllHeight();
		calculate_medians_abc();
		triangleTypeByAngle();
		triangleTypeBySide();
	}
	triangleTypeByAngle();
	triangleTypeBySide();
}

inline void TriangleSolver::badTriangle()
{

	double _a, _b, _c;
	do
	{
		cout << "Your triangle is no good" << endl
		<< "Lets fix it" << endl;
		cout << "**please enter side a: ";
		cin >> _a;
		if (_a <= 0) {
			negativeNumFix(_a);
		}
		else
			side_a = _a;

		cout << "**please enter side b: ";
		cin >> _b;
		if (_b <= 0) {
			negativeNumFix(_b);
		}
		else
			side_b = _b;

		cout << "**please enter side c: ";
		cin >> _c;
		if (_c <= 0) {
			negativeNumFix(_c);
		}
		else
			side_c = _c;

		if (checkTriangle() == true) {
			update_triangle();
		}
		cin.clear();
		cin.ignore(100, '\n');
	}
	while (!checkSides() || !cin);

}

inline void TriangleSolver::initiate_triangle()
{
	_triPtr = this;
	max_side = 0.0;
	max_height = 0.0;
	height_a = 0.0;
	height_b = 0.0;
	height_c = 0.0;
	altHeight_a = 0.0;
	altHeight_b = 0.0;
	altHeight_c = 0.0;
	side_a = 0.0;
	side_b = 0.0;
	side_c = 0.0;
	altSide = 0.0;
	angle_A = 0.0;
	angle_B = 0.0;
	angle_C = 0.0;
	altAngle_A = 0.0;
	altAngle_B = 0.0;
	altAngle_C = 0.0;
	area = 0.0;
	altArea = 0.0;
	perimeter = 0.0;
	altPerimeter = 0.0;
	median_a = 0.0; altMedian_a = 0.0;
	median_b = 0.0; altMedian_b = 0.0;
	median_c = 0.0; altMedian_c = 0.0;
	sssFlag = 0.0;
	aaaFlag = 0.0;
	sasFlag = 0.0;
	ssaFlag = 0.0;
	asaFlag = 0.0;
	aasFlag = 0.0;
	missingSideFlag = 0.0;
	altTriFlag = 0.0;
	rVal = 0.0;
	sVal = 0.0;
	iVal = 0.0;
	altRval = 0.0;
	altSval = 0.0;
	altIval = 0.0;


}

inline void TriangleSolver::calculate_angleA()
{
	if (angle_B > 0 && angle_C > 0) {
		angle_A = 180 - (angle_B + angle_C);
	}
	else {
		angle_A = (180 / _PI_) * asin(side_a / (2 * rVal));
	}
}

inline void TriangleSolver::calculate_angleB()
{
	if (angle_A > 0 && angle_C > 0) {
		angle_B = 180 - (angle_A + angle_C);
	}
	else {
		angle_B = (180 / _PI_) * asin(side_b / (2 * rVal));
	}
}

inline void TriangleSolver::calculate_angleC()
{
	if (angle_B > 0 && angle_A > 0) {
		angle_C = 180 - (angle_A + angle_B);
	}
	else {
		angle_C = (180 / _PI_) * asin(side_c / (2 * rVal));
	}

}

inline void TriangleSolver::calculate_All_angles()
{
	calculate_angleA();
	calculate_angleB();
	calculate_angleC();
}


inline void TriangleSolver::calculate_AllHeight()
{
	max_height = 2 * area / (max_side);
	calculate_heightBase_a();
	calculate_heightBase_b();
	calculate_heightBase_c();

}

inline void TriangleSolver::calculate_heightBase_a()
{
	height_a = (2 * area) / side_a;
}

inline void TriangleSolver::calculate_heightBase_b()
{
	height_b = (2 * area) / side_b;
}

inline void TriangleSolver::calculate_medians_abc()
{
	double a = 0.0, b = 0.0, c = 0.0;
	a = side_a * side_a;
	b = side_b * side_b;
	c = side_c * side_c;
	median_a = sqrt(((2 * b) + (2 * c) - a) / 4);
	median_b = sqrt(((2 * a) + (2 * c) - b) / 4);
	median_c = sqrt(((2 * a) + (2 * b) - c) / 4);
}

inline void TriangleSolver::calculate_heightBase_c()
{
	height_c = (2 * area) / side_c;
}

inline void TriangleSolver::findMissingSide()
{
	missingSideFlag = true;
	double a, b, angle=0;
	a = side_a;
	b = side_b;
	angle = angle_C;
	if (angle == 90) {
		side_c = pythagoreanTheorem(a, b);
	}
	else {
		side_c = sqrt((a * a) + (b * b) - 2 * a * (b * cos(angle*RADIAN)));
	}
	update_triangle();

}

inline bool TriangleSolver::checkAngles()const
{
	double temp = angle_A + angle_B + angle_C;
	if (temp > 180)
		return false;
	return true;
}

inline double TriangleSolver::pythagoreanTheorem(double a, double b)const
{
	return sqrt(a * a + b * b);
}


inline void TriangleSolver::find_base()
{
	const int size = 3;
	double a, b, c;
	a = side_a;
	b = side_b;
	c = side_c;
	vector<double> biggestSide = { a, b,  c };
	auto min_pos =
		min_element(biggestSide.cbegin(), biggestSide.cend());
	auto max_pos =
		max_element(biggestSide.cbegin(), biggestSide.cend());
	ranges::sort(biggestSide);
	max_side = biggestSide[2];
}
inline void TriangleSolver::calculate_area()
{
	if (max_side > 0 && max_height > 0) {
		area = (max_height * max_side) / 2;
	}else
	   area = sqrt(sVal * (sVal - side_a) * (sVal - side_b) * (sVal - side_c));

}
inline void TriangleSolver::calculate_perimeter()
{
	perimeter = side_a + side_b + side_c;
}
inline void TriangleSolver::calculate_rVal()
{
	rVal = (side_a * side_b * side_c) / (4 * area);
}
inline void TriangleSolver::calculate_sVal()
{
	sVal = perimeter / 2;
}
inline void TriangleSolver::calculate_iVal()
{
	iVal = area / sVal;
}
inline TriangleSolver *TriangleSolver::solve_by_AAA(double& a1, double& a2, double& a3)
{
	angle_A = a1; angle_B = a2; angle_C = a3;

	double temp_a=0.0, temp_b=0.0, temp_c=0.0;

	cout << "You need at least one side to solve a triangle\n";
	do {
		cout << "Enter a side length now for the sides you know\n"
			<< "if you do not know a side just enter a 0\n"
			<< "seperate with spaces input order is sides> a, b, c\n>";
		cin >> temp_a >> temp_b >> temp_c;
		if (!cin) {
			cout << "**ERROR**";
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (!cin);
	if (temp_a < 0) {
		side_a = abs(temp_a);
	}
	else
		side_a = temp_a;

	if (temp_b < 0) {
		side_b = abs(temp_b);
	}
	else
		side_b = temp_b;

	if (temp_c < 0) {
		side_c = abs(temp_c);
	}
	else
		side_c= temp_c;

	if (side_a > 0) {
		side_b = sin(angle_B * RADIAN) * side_a / sin(angle_A * RADIAN);
		side_c = sin(angle_C * RADIAN) * side_a / sin(angle_A * RADIAN);
	}
	else if (side_b > 0) {
		side_a = sin(angle_A * RADIAN) * side_b / sin(angle_B * RADIAN);
		side_c = sin(angle_C * RADIAN) * side_b / sin(angle_B * RADIAN);
	}
	else if (side_c > 0) {
		side_a = sin(angle_A * RADIAN) * side_c / sin(angle_C * RADIAN);
		side_b = sin(angle_B * RADIAN) * side_c / sin(angle_C * RADIAN);
	}
	else
		cout << "You didn't enter a valid side lenght, no further computations made on triangle";

	if (temp_a > 0.0) {
		side_a = temp_a;
	}
	if (temp_b > 0.0) {
		side_b = temp_b;
	}
	if (temp_c > 0.0) {
		side_c = temp_c;
	}

	if (checkTriangle() == true) {
		update_triangle();
	}
	else
		cout << "\nthe data entered does not make a valid Triangle. Please try again.";

	return this;
}
inline TriangleSolver *TriangleSolver::solve_by_AAS(double& a1, double& a2, double& s)
{
	//double tmp1, tmp2, tmp3, tmp4;
	angle_A = a1;
	angle_C = a2;
	side_c = s;
	calculate_angleB();
	side_a = sin(a1 * RADIAN) * s / sin(a2 * RADIAN);
	side_b = sin(angle_B*RADIAN) * s / sin(a2 * RADIAN);


	if (checkTriangle() == true) {
		update_triangle();
	}
	return this;
}
inline TriangleSolver *TriangleSolver::solve_by_ASA(double& a1, double& s, double& a2)
{
	angle_A = a1;
	side_c = s;
	angle_B = a2;

	calculate_angleC();

	side_b = sin(angle_B*RADIAN) * s/sin(angle_C*RADIAN);
	side_a = sin(angle_A*RADIAN) * s/sin(angle_C*RADIAN);

	if (checkTriangle() == true) {
		update_triangle();
	}
	return this;
}
inline TriangleSolver* TriangleSolver::solve_by_SAS(double &s1, double &a, double &s2)
{
	side_a = s1;
	angle_C = a;
	side_b = s2;
	findMissingSide();
	return this;
}
inline TriangleSolver* TriangleSolver::solve_by_SSA(double& s1, double& s2, double& _a)
{
	double t1 = 0.0, t2 = 0.0, t3 = 0.0, t4 = 0.0;

	side_a = s1;
	side_b = s2;
	angle_A = _a;
	t1 = s2 / s1;
	t2 = sin(_a * RADIAN);
	t3 = (t1 * t2);
	angle_B = asin(t3) * DEGREE;
	calculate_angleC();
	t4 = side_a * sin(angle_C*RADIAN);
	side_c = t4 / sin(angle_A*RADIAN);
	//side_c = sqrt((s1 * s1) + (s2 * s2) - 2 * s1 * s2 * cos(angle_C));
	if (checkTriangle() == true) {
		update_triangle();
	}
	else
		cout << "this is a bad tringle" << endl;
	double check = sin(angle_B * RADIAN);
	if (side_b > side_a && check >=0 && check <=1) // checking if an alternate triangle can be made
	{											   // and if so then calculates the alternate data.
		altTriFlag = true;
		altAngle_B = 180 - angle_B;
		altAngle_C = 180 - (angle_A + altAngle_B);
		altSide = side_a * sin(altAngle_C * RADIAN) / sin(angle_A * RADIAN);
		altArea = ( side_a * side_b ) * sin(altAngle_C*RADIAN) / 2;
		altPerimeter = side_a + side_b + altSide;
		altHeight_a = 2 * altArea / side_a;
		altHeight_b = 2 * altArea / side_b;
		altHeight_c = 2 * altArea / altSide;
	}

	return this;

}
inline TriangleSolver *TriangleSolver::solve_by_SSS(double& s1, double& s2, double& s3) //law of cosines to solve angle C
{
	side_a = s1;
	side_b = s2;
	side_c = s3;
	if (checkSides() == true) {
		update_triangle();
	}
	else {
		badTriangle();
	}
	return this;
}


inline void TriangleSolver::check_SSS(TriangleSolver& t)
{

	double s1[] = { side_a, side_b, side_c };
	double s2[] = { t.side_a, t.side_b, t.side_c };

	double a1[] = { angle_A, angle_B, angle_C };
	double a2[] = { t.angle_A, t.angle_B, t.angle_C };
	// Function for SSS similarity
	//double simi_sss(double s1[], double s2[]);

	sort(s1, s1 + 3);
	sort(s2, s2 + 3);

	// Check for SSS
	if (s1[0] / s2[0] == s1[1] / s2[1] &&
		s1[1] / s2[1] == s1[2] / s2[2] &&
		s1[2] / s2[2] == s1[0] / s2[0])
		sssFlag = 1;

	sssFlag = 0;

}
inline void TriangleSolver::check_SAS(TriangleSolver& t)
{// Function for SAS similarity

	double s1[] = { side_a, side_b, side_c };
	double s2[] = { t.side_a, t.side_b, t.side_c };

	double a1[] = { angle_A, angle_B, angle_C };
	double a2[] = { t.angle_A, t.angle_B, t.angle_C };

	sort(a1, a1 + 3);
	sort(a2, a2 + 3);
	sort(s1, s1 + 3);
	sort(s2, s2 + 3);

	// Check for SAS

	// angle b / w two smallest
	// sides is largest.
	if (s1[0] / s2[0] == s1[1] / s2[1])
	{
		if (a1[2] == a2[2])
			sasFlag = 1;
	}
	if (s1[1] / s2[1] == s1[2] / s2[2])
	{
		if (a1[0] == a2[0])
			sasFlag = 1;
	}
	if (s1[2] / s2[2] == s1[0] / s2[0])
	{
		if (a1[1] == a2[1])
			sasFlag = 1;
	}
	sasFlag = 0;
}

inline void TriangleSolver::check_AAA(TriangleSolver& t)
{

	double s1[] = { side_a, side_b, side_c };
	double s2[] = { t.side_a, t.side_b, t.side_c };

	double a1[] = { angle_A, angle_B, angle_C };
	double a2[] = { t.angle_A, t.angle_B, t.angle_C };


	sort(a1, a1 + 3);
	sort(a2, a2 + 3);

	// Check for AAA
	if (a1[0] == a2[0] &&
		a1[1] == a2[1] &&
		a1[2] == a2[2])
		aaaFlag = true;
	else
		aaaFlag = false;
}
/*______________________________________________________________________________
*/



inline bool TriangleSolver::checkSides()const
{
	if (
		side_a + side_b > side_c &&
		side_c + side_b > side_a &&
		side_a + side_c > side_b
		)
		return true;
	else
		return false;
}

inline bool TriangleSolver::checkTriangle()const
{
	if(checkSides()==true&&checkAngles()==true)
		return true;
	return false;
}

inline bool TriangleSolver::checkCongruent(TriangleSolver &T)
{
	check_AAA(T);
	check_SAS(T);
	check_SSS(T);
	if (sssFlag == true ||
		sasFlag == true ||
		sssFlag == true
		)
		return true;

	return false;

}
inline void TriangleSolver::congruentBy(TriangleSolver &T)
{
		if(checkCongruent(T)==true){
				cout << "Triangles are "
					<< "similar by ";
				if (aaaFlag == 1) cout << "AAA ";
				if (sssFlag == 1) cout << "SSS ";
				if (sasFlag == 1) cout << "SAS.";
		}
		else
		 		cout<< "Triangles are not congruent" << endl;

}

inline void TriangleSolver::triangleTypeBySide()
{
	if (!checkSides()) {
		//cout << "Not a valid triangle" << endl;
		sideType = "invalid";
	}
	else {
		if (side_a == side_b && side_b == side_c) {
			//cout << "Equilateral" << endl;
			sideType = "Equilateral";
		}
		else if (side_a == side_b || side_b == side_c || side_c == side_a) {
			//cout << "Isosceles" << endl;
			sideType = "Isosceles";
		}
		else {
			//cout << "scalene" << endl;
			sideType = "Scalene";
		}

	}
}

inline void TriangleSolver::triangleTypeByAngle()
{
	double a, b, c;
	a = angle_A;
	b = angle_B;
	c = angle_C;

	if (!checkAngles()) {
		//cout << "Not a valid triangle" << endl;
		//throw ExceptionHandler.
		angleType = "invalid";
	}
	else {
		double longest = c;

		if (longest < a) {
			c = longest;
			longest = b;
			a = c;
		}

		if (longest < b) {
			c = longest;
			longest = b;
			b = c;

		}
		if (a * a + b * b == longest * longest || a == 90 || b == 90 || c==90) {
			//cout << "This is a right-angled triangle.\n";
			angleType = "Right";
		}
		else if (a * a + b * b > longest * longest) {
			//cout << "This is an acute-angled triangle.\n";
			angleType = "Acute";
		}
		else
			//cout << "This is an obtuse-angled triangle.\n";
			angleType = "Obtuse";
	}
}


inline void TriangleSolver::displayTriangleData() const
{
	showAngleType();
	showTriangleSides();
	showTriangleAngles();
	showArea();
	showParameter();
	showSemiParameter();
	showLargestSide();
	showAllHeights();
	showAllMedians();
	showCircumradius();
	showInRadius();
	if (altTriFlag == true) {

		cout << "\nthis Triangle has an alternative" << endl;
		cout << "alt angle B: " << altAngle_B << endl;
		cout << "alt angle C: " << altAngle_C << endl;
		cout << "alt side c: " << altSide << endl;
		cout << "alt area: " << altArea << endl;
		cout << "alt perimeter: " << altPerimeter << endl;
		cout << "alt height_a: " << altHeight_a << endl;
		cout << "alt height_b: " << altHeight_b << endl;
		cout << "alt height_c: " << altHeight_c << endl;
	}
	cout << endl;
}

inline void TriangleSolver::showTriangleSides() const
{
	showSide_a();
	showSide_b();
	showSide_c();
}

inline void TriangleSolver::showTriangleAngles() const
{
	showAngle_A();
	showAngle_B();
	showAngle_C();

}
inline void TriangleSolver::showVertex()
{
}
inline void TriangleSolver::showCongruencyFlags() const
{
	cout << "sssFlag: " << sssFlag << endl;
	cout << "sasFlag: " << sasFlag << endl;
	cout << "aaaFlag: " << aaaFlag << endl;
}

inline void TriangleSolver::showTriangleAsCartesianPoints()
{
}

inline void TriangleSolver::showAngleType() const
{
	cout << "\ntype: " << angleType << "  " << sideType << endl;
}
inline void TriangleSolver::showTriangleAreaPerimeter() const
{
	showArea();
	showParameter();

}

inline void TriangleSolver::setSide_a(double _a)
{
	side_a = _a;
	do
	{
		if (checkSides())
		{
			update_triangle();
		}
		else
		{
			std::cout << "sides do don't make a proper triangle enter another"
				<< " value for side a now\n>>";
			std::cin >> side_a;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (!checkSides() || !cin);

}

inline void TriangleSolver::setSide_b(double _b)
{
	side_b = _b;
	do
	{
		if (checkSides())
		{
			update_triangle();
		}
		else
		{
			std::cout << "sides do don't make a proper triangle enter another"
				<< " value for side b now\n>>";
			std::cin >> side_b;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (!checkSides() || !cin);
}

inline void TriangleSolver::setSide_c(double _c)
{
	side_c = _c;
	do
	{
		if (checkSides())
		{
			update_triangle();
		}
		else
		{
			std::cout << "sides do don't make a proper triangle enter another"
				<< " value for side c now\n>>";
			std::cin >> side_c;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	while (!checkSides() || !cin);
}

inline void TriangleSolver::setSides(double _a, double _b, double _c)
{
		side_a = _a;
		side_b = _b;
		side_c = _c;
		if (checkSides() == true) {
			update_triangle();
		}
		else {
			badTriangle();
		}

}
inline void TriangleSolver::setAngles(double aA, double aB, double aC)
{
	// this will essentially build a new triangle from the one you have
		angle_A = aA;
		angle_B = aB;
		angle_C = aC;
	if (double check = aA + aB + aC; check != 180) {
		do {
			cout << "the angles need to add up to 180 degrees to be a real triangle\n"
				<< "please reenter the sides and make sure the total is 180 degrees.\n"
				<< "use spaces to seperate each angle esample: 40.5 65 79.5\n>";
			cin >> aA >> aB >> aC;
			check = aA + aB + aC;
			cin.clear();
			cin.ignore(100, '\n');
		} while (check != 180 || !cin);
	}
	if (checkAngles() == true) {
			solve_by_AAA(aA, aB, aC);
	}
	//update_triangle();
}
/*______________________________________________________________________________
											   overloaded addition opperators*/
inline TriangleSolver TriangleSolver::operator+() const
{
	return TriangleSolver();
}

inline TriangleSolver TriangleSolver::operator++()const
{
	return TriangleSolver();
}

inline TriangleSolver TriangleSolver::operator++(int)const
{
	return TriangleSolver();
}

inline TriangleSolver TriangleSolver::operator+(const TriangleSolver& tri)const
{
	double a,b,c;
	a = this->side_a + tri.side_a;
	b = this->side_b + tri.side_b;
	c = this->side_c + tri.side_c;
	return TriangleSolver(a, b, c);
}

inline TriangleSolver TriangleSolver::operator+(double n)
{
	side_a = side_a + n;
	side_b = side_b + n;
	side_c = side_c + n;
	if (checkSides() == true) {
		update_triangle();
	}
	return TriangleSolver();
}

inline TriangleSolver& TriangleSolver::operator+=(const TriangleSolver& rhs)
{
	side_a += rhs.side_a;
	side_b += rhs.side_b;
	side_c += rhs.side_c;
	calculate_All_angles();
	return *this;
}
inline TriangleSolver operator+(double num, TriangleSolver&)
{
	return TriangleSolver();
}
/*
Triangle operator+(Triangle lhs, const Triangle& rhs)
{
	Triangle temp(
			lhs.side_a+rhs.side_a,
			lhs.side_b+rhs.side_b,
			lhs.side_c+rhs.side_c
			);

	temp.update_triangle();
	return temp;
}

*/

/*______________________________________________________________________________
											overloaded subtraction opperators*/

inline TriangleSolver TriangleSolver::operator-() const
{
	return TriangleSolver();
}

inline TriangleSolver TriangleSolver::operator--()const
{
	return TriangleSolver();
}

inline TriangleSolver TriangleSolver::operator--(int)const
{
	return TriangleSolver();
}

inline TriangleSolver TriangleSolver::operator-(const TriangleSolver& tri) const
{
	double a,b,c;
	a = this->side_a - tri.side_a;
	b = this->side_b - tri.side_b;
	c = this->side_c - tri.side_c;
	return TriangleSolver(a, b, c);
}

inline TriangleSolver TriangleSolver::operator-(double) const
{
	return TriangleSolver();
}

inline TriangleSolver& TriangleSolver::operator-=(const TriangleSolver& rhs)
{
	side_a -= rhs.side_a;
	side_b -= rhs.side_b;
	side_c -= rhs.side_c;
	calculate_All_angles();
	return *this;
}

inline TriangleSolver operator-(double num, TriangleSolver&)
{
	return TriangleSolver();
}
/*
Triangle operator-(Triangle lhs, const Triangle&)
{
	return Triangle();
}
*/
/*______________________________________________________________________________
												overloaded division opperators*/

inline TriangleSolver TriangleSolver::operator/(double d)const
{
	return TriangleSolver(side_a/d, side_b/d, side_c/d);
}

inline TriangleSolver TriangleSolver::operator/(const TriangleSolver& t)const
{
	return TriangleSolver(side_a / t.side_a, side_b / t.side_b, side_c / t.side_c);
}

/*______________________________________________________________________________
										 overloaded multiplication opperators*/

inline TriangleSolver TriangleSolver::operator*(double t) const
{
	return TriangleSolver(side_a * t, side_b * t, side_c * t);
}

inline TriangleSolver operator*(double s, TriangleSolver& t)
{
	return TriangleSolver(t.side_a * s, t.side_b * s, t.side_c * s);
}

inline TriangleSolver operator*(TriangleSolver& v, TriangleSolver& s)
{
	TriangleSolver results(v.side_a * s.side_a, v.side_b * s.side_b, v.side_c * s.side_c);

	return results;

}
inline ostream& operator<<(ostream& os, const TriangleSolver& t)
{
	t.displayTriangleData();
	return os;
}

inline istream& operator>>(istream& is, TriangleSolver& t)
{
	is >> t.side_a >> t.side_b >> t.side_c;
	if (t.checkSides())
	{
		t.update_triangle();
		return is;
	}
	else
	{
		t.badTriangle();
	}
	return is;
}

template<typename T>
inline T TriangleSolver::negativeNumCheck(T& num)
{
	if (num > 0)
		return 0;
	else {
		num = negativeNumFix(num);
	}
	return 0;
}

template<typename T>
inline T TriangleSolver::negativeNumFix(T& num)
{
	//double temp;
	if (num < 0) {
		do {
			cout << "You cannot enter a negitive value\n:";
			cout << "making it an absolute value instead";
			num = abs(num);
			//return num;
			cin.ignore(100, '\n');
			cin.clear();
		} while (!cin || num < 0);
		return num;
	}
	return num;
}
