#pragma once
// class for doing physics problems
// author: Ryan Zurrin
// last Modified: 10/11/2020
#ifndef ELASTICITY_H
#define ELASTICITY_H
#include "Drag.h"

class Elasticity
{
private:
	
	
public:
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
	

	Elasticity()
	{
		_ptrElastic = nullptr;
		_stress_ = 0.0;
		_strain_ = 0.0;
		_force_ = 0.0;
		_area_ = 0.0;
	}

	Elasticity(const Elasticity& e)
	{
		_ptrElastic = e._ptrElastic;
		_stress_ = e._stress_;
		_strain_ = e._strain_;
		_force_ = e._force_;
		_area_ = e._area_;
	}

	Elasticity& operator=(const Elasticity& r)
	{
		if(this != &r)
		{
			_ptrElastic = r._ptrElastic;
			_area_ = r._area_;
			_force_ = r._force_;
			_strain_ = r._strain_;
			_stress_ = r._stress_;
		}
		return  *this;
	}

	/**
	 * method: cross_sectional(const ld radius)
	 * arguments: radius
	 * purpose:	calculates the cross sectional, which is used in many elasticity problems
	 * returns: ld, cross sectional 
	 */
	ld static cross_sectional(const ld radius)
	{ return PI * (radius * radius); }

	 /**
	 * method: change_L(const ld appliedForce, const ld mod_Y, const ld crossSection, const ld originalLength)
	 * arguments: 1)appliedForce 2)YoungsModulus 3)crossSection 4) originalLength
	 * purpose:	calculates the stretch in a material
	 * returns: ld, change in length
	 */
	ld static change_L(const ld appliedForce, const ld YoungsModulus, const ld crossSection, const ld originalLength)
	{
		return (1 / YoungsModulus) * (appliedForce / crossSection) * originalLength;
	}
	
	~Elasticity() = default;
};
#endif