#pragma once
// class for doing physics problems
// author: Ryan Zurrin
// last Modified: 10/11/2020
#ifndef ELASTICITY_H
#define ELASTICITY_H
#include <iostream>
#include <vector>
#include "Vector2d.h"

typedef long double ld;
static int elasticity_objectCount = 0;

class Elasticity
{
private:
	
	static void countIncrease() { elasticity_objectCount += 1; }
	static void countDecrease() { elasticity_objectCount -= 1; }
	
public:
	static void countShow() { std::cout << "elasticity count: " << elasticity_objectCount << std::endl; }
	
	ld _stress_;
	void show_stress()const { cout << "stress: " << _stress_ << endl; }
	
	ld _strain_;
	void show_strain()const { cout << "strain: " << _strain_ << endl; }
	
	ld _force_;
	void show_force()const { cout << "force: " << _force_ << endl; }
	
	ld _area_;
	void show_area()const { cout << "area: " << _area_ << endl; }

	Elasticity* _ptrElastic;

	/**
	 * structure: Elastic_Moduli vector
	 * components: <young's modulus, Shear modulus, Bulk modulus> Y, S, B
	 * purpose:	store data on elastic moduli for using in physics calculations
	 * returns: specified component value
	 */
	struct Elastic_Moduli  // all units are multiplied by(10^9 N/m^2)
	{
		vector<ld> aluminum = { 70 * pow(10, 9),	25 * pow(10, 9),	75 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> bone_tension = { 16 * pow(10, 9),	80 * pow(10, 9),	8 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> bone_compression = { 9 * pow(10, 9),	0 * pow(10, 9),	0 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> brass = { 90 * pow(10, 9),	35 * pow(10, 9),	75 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> brick = { 15 * pow(10, 9),	0 * pow(10, 9),	0 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> concrete = { 20 * pow(10, 9),	0 * pow(10, 9),	0 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> glass = { 70 * pow(10, 9),	20 * pow(10, 9),	30 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> granite = { 45 * pow(10, 9),	20 * pow(10, 9),	45 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> hair_human = { 10 * pow(10, 9),	0 * pow(10, 9),	0 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> hardwood = { 25 * pow(10, 9),	10 * pow(10, 9),	0 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> cast_iron = { 100 * pow(10, 9),	40 * pow(10, 9),	90 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> lead = { 16 * pow(10, 9),	5 * pow(10, 9),	50 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> marble = { 60 * pow(10, 9),	20 * pow(10, 9),	70 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> nylon = { 5 * pow(10, 9),	0 * pow(10, 9),	0 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> polystyrene = { 3 * pow(10, 9),	0 * pow(10, 9),	0 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> silk = { 6 * pow(10, 9),	0 * pow(10, 9),	0 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> spider_thread = { 3 * pow(10, 9),	0 * pow(10, 9),	0 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> steel = { 210 * pow(10, 9),	80 * pow(10, 9),	130 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> tendon = { 1 * pow(10, 9),	0 * pow(10, 9),	0 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> acetone = { 0 * pow(10, 9),	0 * pow(10, 9),	0.7 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> ethanol = { 0 * pow(10, 9),	0 * pow(10, 9),	0.9 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> glycerin = { 0 * pow(10, 9),	0 * pow(10, 9),	4.5 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> mercury = { 0 * pow(10, 9),	0 * pow(10, 9),	25 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		vector<ld> water = { 0 * pow(10, 9),	0 * pow(10, 9),	2.2 * pow(10, 9) };
		///<young's modulus, Shear modulus, Bulk modulus>
		
	}moduli;
	
	// default constructor
	Elasticity()
	{
		_ptrElastic = nullptr;
		_stress_ = 0.0;
		_strain_ = 0.0;
		_force_ = 0.0;
		_area_ = 0.0;
		countIncrease();
		countShow();
	}

	// copy constructor
	Elasticity(const Elasticity& e)
	{
		_ptrElastic = e._ptrElastic;
		_stress_ = e._stress_;
		_strain_ = e._strain_;
		_force_ = e._force_;
		_area_ = e._area_;
		countIncrease();
		countShow();
	}

	// copy assignment operator 
	Elasticity& operator=(const Elasticity& r)
	{
		if(this != &r)
		{
			_ptrElastic = r._ptrElastic;
			_area_ = r._area_;
			_force_ = r._force_;
			_strain_ = r._strain_;
			_stress_ = r._stress_;
			countIncrease();
			countShow();
		}
		return  *this;	
	}

	/**
	 * method: cross_sectional(const ld radius)
	 * arguments: radius
	 * purpose:	calculates the cross sectional, which is used in many elasticity problems
	 * returns: ld, cross sectional 
	 */
	ld static cross_sectional_area(const ld radius)
	{ return PI * (radius * radius); }

	 /**
	 * method: change_L(const ld appliedForce, const ld mod_Y, const ld crossSection, const ld originalLength)
	 * arguments: 1)appliedForce 2)YoungsModulus 3)crossSection 4) originalLength
	 * purpose:	calculates the deformation, or change in length
	 * returns: ld, deformation
	 */
	ld static deformations(const ld appliedForce, const ld modulus, const ld crossSectionalArea, const ld original)
	{ return (1 / modulus) * (appliedForce / crossSectionalArea) * original; }

	/**
	* method: stress_usingY(const ld YoungsModulus, const ld strain)
	* arguments: 1)YoungsModulus 2)strain 
	* purpose:	calculates the stress which is defined as the ratio of force to area
	* returns: ld, stress
	*/
	ld static stress_usingY(const ld YoungsModulus, const ld strain)
	{ return YoungsModulus * strain; }

	/**
	* method:  stress_usingF(const ld force, const ld area)
	* arguments: 1)force 2)area = PI*r^2
	* purpose:	calculates the stress which is defined as the ratio of force to area
	* returns: ld, stress
	*/
	ld static stress_usingF(const ld force, const ld area)
	{ return force / area;	}

	/**
	* method: strain(const ld change_in_length, const ld total_length)
	* arguments: 1)change_in_length 2)total_length 
	* purpose:	calculates the strain which is defined as the ratio of the change in length to length
	* returns: ld, strain
	*/
	ld static strain(const ld change_in_length, const ld total_length)
	{ return change_in_length / total_length; }

	/**
	* method: hookes_law(const ld k, const ld deformation)
	* arguments: 1)k = proportionailty constant 2)deformation = change in length 
	* purpose:	calculates the Tensile strength using hooks law
	* returns: ld, force that is safe before breaking
	*/
	ld static hookes_law(const ld k, const ld deformation)
	{ return k * deformation; }

	/**
	* method: deforming_force(const ld modulus, const ld crossSectionalArea, const ld originalLength, const ld amountDeformed)
	* arguments: 1)modulus 2)crossSectionalArea 3)originalLength 4)amountDeformed
	* purpose:	calculates the force required to bend or deform a something depending on the material
	* returns: ld, deforming force
	*/
	ld static deforming_force(const ld modulus, const ld crossSectionalArea, const ld originalLength, const ld amountDeformed)
	{ return ((modulus) * (crossSectionalArea) / (originalLength)) * amountDeformed; }
	
	~Elasticity()
	{
		delete _ptrElastic;
		countDecrease();
		countShow();
	}
};
#endif