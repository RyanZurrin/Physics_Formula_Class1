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
//static object counter for Elasticity class
static int elasticity_objectCount = 0;

class Elasticity
{
public:
	static void countShow() { std::cout << "elasticity count: " << elasticity_objectCount << std::endl; }

	void setElasticityVal(ld val) { _elasticityVal = val; }

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
		_ptrElastic =  nullptr;
		_elasticityVal = 0.0;
		countIncrease();
		//countShow();
	}
	Elasticity(ld val)
	{
		_ptrElastic =  nullptr;
		_elasticityVal = 0.0;
		countIncrease();

	}

	// copy constructor
	Elasticity(const Elasticity& e)
	{
		_ptrElastic = e._ptrElastic;
		_elasticityVal = e._elasticityVal;
		countIncrease();
		//countShow();
	}

	// copy assignment operator
	Elasticity& operator=(const Elasticity& r)
	{
		if (this != &r)
		{
			_ptrElastic = r._ptrElastic;
			_elasticityVal = r._elasticityVal;
			countIncrease();
			//countShow();
		}
		return  *this;
	}


	/**
	 * method: cross_sectional(const ld radius)
	 * arguments: radius
	 * purpose:	calculates the cross sectional, which is used in many elasticity problems
	 * returns: ld, cross sectional
	 */
	static ld cross_sectional_area(const ld radius)
	{ return _PI_ * (radius * radius); }

	 /**
	 * Returns the calculated deformation of an object which is used in hooks law equation
	 * @param appliedForce the force in newtons
	 * @param modulus <young's modulus, Shear modulus, Bulk modulus> values can be accessed by .moduli.
	 * @param crossSectionalArea
	 * @param original	 *
	 * @returns the deformation
	 */
	static ld deformations(const ld appliedForce, const ld modulus, const ld diameter, const ld original)
	{ return (1 / modulus) * (appliedForce / (_PI_ * (diameter * diameter)) * original); }

	/**
	* method: stress_usingY(const ld YoungsModulus, const ld strain)
	* arguments: 1)YoungsModulus 2)strain
	* purpose:	calculates the stress which is defined as the ratio of force to area
	* returns: ld, stress
	*/
	static ld stress_usingY(const ld youngsModulus, const ld strain)
	{ return youngsModulus * strain; }

	/**
	* method:  stress_usingF(const ld force, const ld area)
	* arguments: 1)force 2)area = PI*r^2
	* purpose:	calculates the stress which is defined as the ratio of force to area
	* returns: ld, stress
	*/
	static ld stress_usingF(const ld force, const ld area)
	{ return force / area;	}

	/**
	* method: strain(const ld change_in_length, const ld total_length)
	* arguments: 1)change_in_length 2)total_length
	* purpose:	calculates the strain which is defined as the ratio of the change in length to length
	* returns: ld, strain
	*/
	static ld strain(const ld change_in_length, const ld total_length)
	{ return change_in_length / total_length; }


	/// <summary>
	///  Uses Hookes law to find the force applied
	/// </summary>
	/// <param name="k">The force constant.</param>
	/// <param name="x">The deformation from starting point.</param>
	/// <returns>force applied</returns>
	static ld hookes_law(const ld k, const ld x)
	{ return k * x; }


	/**
	* method: deforming_force(const ld modulus, const ld crossSectionalArea, const ld originalLength, const ld amountDeformed)
	* arguments: 1)modulus 2)crossSectionalArea 3)originalLength 4)amountDeformed
	* purpose:	calculates the force required to bend or deform a something depending on the material
	* returns: ld, deforming force
	*/
	static ld deforming_force(const ld modulus, const ld crossSectionalArea, const ld originalLength, const ld amountDeformed)
	{ return ((modulus) * (crossSectionalArea) / (originalLength)) * amountDeformed; }

	/**
	 * Returns the total displacement to the side of an object due to a sheering force.
	 * @param length total length of the object
	 * @param diameter
	 * @param forceN in newtons
	 * @param sheerModuli for the material being measured
	 * @returns displacement of a material to side due to sheering force
	 */
	static ld displacement_side_sheer_force(const ld length, const ld diameter, const ld forceN, const ld sheerModuli)
	{
		return (1 / sheerModuli) * (4 / (_PI_ * (diameter * diameter))) * forceN * length;
	}

	/**
	 * @brief Returns the amount of compression an object undergoes, such as weight on a steel beam
	 * @param length is the length of the object
	 * @param crossSectionalArea is the area as if it was sliced in half
	 * @param youngsModulus is the modulus used in this equation
	 * @param force is the amount of force being applied
	 * @returns the compression amount in meters
	 */
	static ld compression(const ld length, const ld crossSectionalArea, const ld youngsModulus, const ld force)
	{
		return (force * length) / (youngsModulus * crossSectionalArea);
	}

	/**
	 * @brief Returns the maximum force something will take before it fails
	 * @param compressiveStrength is dependant on the material used
	 * @param crosssSectionalArea is the area of a cross section of the object
	 * @returns the max force before failure will occur
	 */
	static ld max_support_force(const ld compressiveStrength, const ld crossSectionalArea)
	{
		return compressiveStrength * crossSectionalArea;
	}

	~Elasticity()
	{
		delete _ptrElastic;
		countDecrease();
		//countShow();
	}

private:

	static void countIncrease() { elasticity_objectCount += 1; }
	static void countDecrease() { elasticity_objectCount -= 1; }
	ld _elasticityVal;
};
#endif