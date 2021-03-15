#pragma once
/**
 * @class PhysicsWorld
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   10/15/2020
 */
#ifndef PHYSICSWORLD_H
#define PHYSICSWORLD_H

#include <cmath>
#include <iostream>
#include "Circuits.h"
#include "Drag.h"
#include "DynamicsAndForces.h"
#include "Elasticity.h"
#include "ElectricCharge.h"
#include "ElectricCurrent.h"
#include "ElectricPotential.h"
#include "Energy.h"
#include "FluidDynamics.h"
#include "FluidStatics.h"
#include "Friction.h"
#include "Hearing.h"
#include "Heat.h"
#include "Kinematics.h"
#include "Magnetism.h"
#include "Momentum.h"
#include "PeriodicElements.h"
#include "RotationalMotion.h"
#include "Statics.h"
#include "Temperature.h"
#include "Thermodynamics.h"
#include "Torque.h"
#include "UniformCircularMotion.h"
#include "Vector3D.h"
#include "Waves.h"


class PhysicsWorld;
//_____________________________________________________________________________
//global constants, methods and structures
//
//

typedef long double ld;
typedef PhysicsWorld PW;

static ld _val_;// = 0.0;
static void show_val() { cout << "_val_: " << _val_ << endl; }
static void show_val(const ld val) { cout << "val: " << val << endl; }
static void show_val(const string label, const string units = "")
{ cout << "\n"+label+": " << _val_ << " "+units <<endl; }
static int setVal(const ld v)
{
	_val_ = v;
	return v;
}
/// <summary>
/// Returns the value.
/// </summary>
/// <returns></returns>
static ld return_val() { return _val_; }

/// <summary>
/// Prints the vector values of passed in vector.
/// </summary>
/// <param name="v">The v.</param>
static void printVectorValues(vector<ld>& v)
{
	const auto size = v.size();
	cout << "vector: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << v[i] << ", ";
	}
	std::cout << std::endl;
}
static void printVectorValues(vector<ld> v)
{
	const auto size = v.size();
	cout << "vector: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << v[i] << ", ";
	}
	std::cout << std::endl;
}

template <typename T, size_t size>
void static printArray(const T(&array)[size])
{
	for (size_t i = 0; i < size; i++)
		cout << array[i] << " ";

	cout << endl;
}
/// <summary>
/// Prints the arr.
/// </summary>
/// <param name="arr">The array.</param>
/// <param name="n">= sizeof( arr ) / sizeof( *arr )</param>
void static printArr(const ld arr[], const int n)
{
	cout << "array values: ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
}

//Gravitational Constant 6.67408(31) * 10^(-11) * N
const ld _GC_ = 6.674 * pow(10.0, -11.0);

// speed of light in a vacuum is 299792458 m/s
const ld _c_ = 2.99792458 * pow(10.0, 8.0);

/**
 * @brief area of sphere with radius r
 */
static ld sphereArea(const ld r)
{
	return 4.0 * _PI_ * (r * r);
}

/**
 * @brief volume of sphere with radius r
 */
static ld sphereVolume(const ld r)
{
	return (4.0 / 3.0) * (_PI_ * (r * r * r));
}

/**
 * @circumference of a circle with radius r or diameter d
 */
static ld circleCircumference(const ld rd, const char mode = 'r')
{
	if(mode == 'r')
	{
		return 2.0 * _PI_ * rd;
	}
	return _PI_ * rd;
}
/**
 * @brief global method for finding the area of a circle
 * @param rd is the radius or diameter of the circle
 * @param mode in radius default, for diameter add 'd' as a second argument
 * @returns the total area of a circle
 */
static ld circleArea(const ld rd, const char mode = 'r')
{
	if (mode == 'r')
	{
		return _PI_ * (rd * rd);
	}
	return (_PI_ * (rd * rd)) / 4.0;
}
/**
 * @brief global method for finding the change in two values
 * @param xi is the starting value
 * @param xf is the ending value
 * @return the difference between xf and xi
 */
static ld delta(const ld xi, const ld xf)
{
	return xf - xi;
}




/**
 * @brief structure for conversion methods
 */
static struct Conversions
{
	struct SpecificHeatConverter
	{
		static ld joulesKgC_to_kcalKgC(const ld j = _val_)
		{
			return j * .000238845896627;
		}
		static ld _kcalKgC_to_joulesKgC_IT(const ld kcal = _val_)
		{
			return kcal * 4186.8;
		}
	}heat;


	static ld atomicWeight_to_kilograms(const ld u = _val_)
	{
		return u * 1.6605402 * pow(10, -27);
	}

	static ld kiloJoules_to_calories(const ld kJ)
	{
		return (kJ * 1000.0) / 4186.0;
	}

	static ld revolutionsFromRadians(const ld radTotal)
	{
		//cout << "revolutions: " << radTotal / (2.0 * _PI_) << endl;
		return radTotal / (2.0 * _PI_);
	}

	/**
	 * @brief Returns the revolutions in radians per second which is the
	 * angular velocity as well
	 * @param revMin revolutions per minute
	 * @returns revolutions in radians per second
	 */
	static ld revolutions_min_to_radians_second(const ld revMin)
	{
		return (revMin * 2.0 * _PI_) / 60;
	}

	/**
	 * @brief Returns the conversion from revolutions per radian second to
	 * revolutions per minute
	 * @param radSec is the rotation speed in radians per second
	 * @returns the revolutions per minute
	 */
	static ld radians_second_to_revolutions_minute(const ld radSec)
	{
		return (radSec * 60.0) / (2.0 * _PI_);
	}

	/**
	 *  @brief Returns the ratio of the value to gravity
	 *  @param unit can be whatever you are dividing by gravity acceleration
	 *  @returns the gravity ratio
	 */
	static ld gravity_ratio(const ld unit)
	{
		return unit / _G_;
	}


	/**
	 * @brief Returns the conversion from meters per second to kilometers
	 * per hour
	 * @param mps is meters per second
	 * @returns kilometers per hour
	 */
	static ld mps_to_kmh(const ld mps = _val_)
	{
		return mps * 3.6;
	}
	/**
	 * @brief Returns the conversion from kilometers per hour to meters per
	 * second
	 * @param kmh is kilometers per hour
	 * @returns meters per second
	 */
	static ld kmh_to_mps(const ld kmh = _val_)
	{
		return kmh / 3.6;
	}

	/// <summary>
	/// KMSs to KMH.
	/// </summary>
	/// <param name="kms">kilometers per second.</param>
	/// <returns>kilometers per hour</returns>
	static ld kms_to_kmh(const ld kms = _val_)
	{
		return kms * 3600.0;
	}
	/// <summary>
	/// KMHs to KMS.
	/// </summary>
	/// <param name="kmh">kilometers per hour.</param>
	/// <returns>kilometers per second</returns>
	static ld kmh_to_kms(const ld kmh = _val_)
	{
		return kmh / 3600.0;
	}
	/**
	 * @brief Returns the conversion from miles per hour to meters per second
	 * @param mph is miles per hour
	 * @returns meters per second
	 */
	static ld mph_to_mps(const ld mph = _val_)
	{
		return mph / 2.237;
	}
	/**
	 * @brief Returns the conversion from meters per second to miles per hour
	 * @param mps is meters per second
	 * @returns miles per hour
	 */
	static ld mps_to_mph(const ld mps = _val_)
	{
		return mps * 2.237;
	}
	/**
	 * @brief Returns the conversion from milliseconds to seconds
	 * @param ms to be converted to seconds
	 * @returns seconds from milliseconds
	 */
	static ld millisecond_to_seconds(const ld ms = _val_)
	{
		return ms / 1000;
	}
	static ld minutes_to_seconds(const ld min = _val_)
	{
		return min * 60;
	}
	static ld hours_to_seconds(const ld hours = _val_)
	{
		return hours * 3600;
	}
	/**
	 * @brief Returns the conversion from days to seconds for use in calculation
	 * @param days can be expressed as a decimal, four and a half days would
	 * be 4.5
	 * @returns total seconds converted from days
	 */
	static ld days_to_seconds(const ld days = _val_)
	{
		return days * 86400;
	}
	/**
	 * @brief Returns the conversion from seconds to days
	 * @param seconds to be converted
	 * @returns days
	 */
	static ld seconds_to_days(const ld seconds = _val_)
	{
		return seconds / 86400;
	}
	/**
	 * @brief Returns the conversion from miles to meters
	 * @param miles to be converted
	 * @returns meters from miles
	 */
	static ld miles_to_meters(const ld miles = _val_)
	{
		return miles * 1609;
	}
	/**
	 * @brief Returns the conversion from feet to meters
	 * @param feet to be converted
	 * @returns meters
	 */
	static ld feet_to_meters(const ld feet = _val_)
	{
		return feet / 3.281;
	}
	/**
	 * @brief Returns the conversion from inches to meters
	 * @param inches to be converted
	 * @returns meters
	 */
	static ld inches_to_meters(const ld inches = _val_)
	{
		return inches / 39.37;
	}
	/**
	 * @brief Returns the conversion from meters to inches
	 * @param meters is the total meters
	 * @returns inches
	 */
	static ld meters_to_inches(const ld meters = _val_)
	{
		return meters * 39.37;
	}
	/**
	 * @brief Returns the conversion from centimeters to meters
	 * @param cm centimeters
	 * @returns meters
	 */
	static ld centimeters_to_meters(const ld cm = _val_)
	{
		return cm / 100;
	}
	static ld meters_to_centimeters(const ld m = _val_)
	{
		return m * 100;
	}
	static ld kilometers_to_meters(const ld km = _val_)
	{
		return km * 1000;
	}
	static ld millimeters_to_meters(const ld mm = _val_)
	{
		return mm / 1000;
	}
	static ld micrometers_to_meters(const ld Mm = _val_)
	{
		return Mm / pow(1, -6);
	}
	static ld nanometers_to_meters(const ld nm = _val_)
	{
		return nm / pow(1, -9);
	}
	static ld pound_to_kilogram(const ld lbs = _val_)
	{
		return lbs / 2.205;
	}
	static ld milligram_to_kilogram(const ld mg = _val_)
	{
		return mg / pow(1, -6);
	}
	static ld gram_to_kilogram(const ld g = _val_)
	{
		return g / 1000;
	}
	static ld ounce_to_kilogram(const ld ounce = _val_)
	{
		return ounce / 35.274;
	}
	static ld watts_to_kilowatts(const ld watt = _val_)
	{
		return watt / 1000;
	}
	static ld kWh_to_joules(const ld kWh = _val_)
	{
		return kWh * (3.6*pow(10, 6));
	}
	static ld joules_to_kWh(const ld j = _val_)
	{
		return j / (3.6 * pow(10, 6));
	}
	static ld newtonMeters_to_ftPounds(const ld Nm = _val_)
	{
		return Nm / .73756;
	}
	static ld radians_to_revolutions(const ld rad = _val_)
	{
		return rad / (2 * _PI_);
	}
	static ld revolutions_to_radians(const ld rev = _val_)
	{
		return rev * 2 * _PI_;
	}
	static ld atm_to_pascals(const ld atm = _val_)
	{
		return atm * 101325.0;
	}

}converter;

static struct Densities
{
	const ld aluminum_S = 2.7; // 2700 kg/m^3
	const ld brass_S = 8.44; // 8440 kg/m^3
	const ld copperAverage_S = 8.8; // 8800 kg/m^3
	const ld gold_S = 19.32; // 19320 kg/m^3
	const ld ironOrSteele_S = 7.8; // 7800 kg/m^3
	const ld lead_S = 11.3; // 11300 kg/m^3
	const ld polystyrene_S = .10; // 100 kg/m^3
	const ld tungsten = 19.30; // 19300 kg/m^3
	const ld uranium = 18.7; // 18700 kg/m^3
	const ld concrete_light_S = 2.30; // 2300 kg/m^3
	const ld concrete_med_S = 2.7; // 2700 kg/m^3
	const ld concrete_heavyDuty_S = 3.0; // 3000 kg/m^3
	const ld cork_S = .24; // 240 kg/m^3
	const ld glassAverage_S = 2.6; // 2600 kg/m^3
	const ld granite = 2.7; // 2700 kg/m^3
	const ld earthsCrust_S = 3.3; // 3300 kg/m^3
	const ld woodSoft_S = .3; // 300 kg/m^3
	const ld woodMed_S = .6 ; // 600 kg/m^3
	const ld woodHard_S = .9; // 900 kg/m^3
	const ld ice_0deg_S = .917; // 917 kg/m^3
	const ld boneSoft_S = 1.7; // 1700 kg/m^3
	const ld boneHard_S = 2.0; // 2000 kg/m^3
	const ld water_L = 1.0; // 1000 kg/m^3
	const ld blood_L = 1.05; // 1050 kg/m^3
	const ld seaWater_L = 1.025; // 1025 kg/m^3
	const ld mercury_L = 13.6; // 13600 kg/m^3
	const ld ethylAlcohol_L = .79; // 790 kg/m^3
	const ld petrol_L = .68; // 680 kg/m^3
	const ld glycerin_L = 1.26; // 1260 kg/m^3
	const ld oliveOil_L = .92; // 920 kg/m^3
	const ld air_G = 1.29 * pow(10, -3); // 1.29 kg/m^3
	const ld carbon_dioxide_G = 1.98 * pow(10, -3); // 1.98 kg/m^3
	const ld carbon_monoxide_G = 1.25 * pow(10, -3); // 1.25 kg/m^3
	const ld hydrogen_G = 0.090 * pow(10, -3); // 0.090 kg/m^3
	const ld helium_G = 0.18 * pow(10, -3); // 0.18 kg/m^3
	const ld methane_G = 0.72 * pow(10, -3); // 0.72 kg/m^3
	const ld nitrogen_G = 1.25 * pow(10, -3); // 1.25 kg/m^3
	const ld nitrous_oxide_G = 1.98 * pow(10, -3); // 1.98 kg/m^3
	const ld oxygen_G = 1.43 * pow(10, -3); // 1.43 kg/m^3
	const ld steam_G = 0.60 * pow(10, -3); // 0.60 kg/m^3
}p;



class PhysicsWorld
{

private:

	static int physics_objectCount;
	static void countIncrease() { physics_objectCount += 1; }
	static void countDecrease() { physics_objectCount -= 1; }

public:

	/**
	 * @brief Template method to print out an array that is passed to it
	 * @param array of values
	 */
	template <typename T, size_t size>
	void static print_array(const T(&array)[size])
	{
		for (size_t i = 0; i < size; i++)
			cout << array[i] << " ";

		cout << endl;
	}

	//PhysicsCommon  physics_common;
	//PhysicsWorld* world;
	Kinematics* kinematics;
	Friction* friction;
	Drag* drag;
	Elasticity* elasticity;
	UniformCircularMotion* uniformCircularMotion;
	Vector* vector2d;
	Vector3D* vector3d;
	Energy* energy;
	Momentum* momentum;
	Torque* torque;
	Statics* statics;
	RotationalMotion* rotationalMotion;
	Temperature* temperature;
	Heat* heat;
	Thermodynamics* thermodynamic;
	DynamicsAndForces* dynamics_and_forces;
	FluidStatics* fluid_statics;
	FluidDynamics* fluid_dynamics;
	Waves* waves;
	Hearing* hearing;
	ElectricCharge* electric_charge;
	ElectricPotential* electric_potential;
	ElectricCurrent* electric_current;
	PeriodicElements* periodic_elements;
	Circuits* circuits;
	Magnetism* magnetism;


	//PhysicsCommon * physics_common;
	//PhysicsWorld * world;
	PhysicsWorld * _ptr_;

	PhysicsWorld();
	PhysicsWorld(ld t1, ld t2, ld t3);
	PhysicsWorld(ld t1, ld t2);
	PhysicsWorld(const PhysicsWorld&); //copy constructor
	PhysicsWorld& operator=(const PhysicsWorld&); //copy assignment operator
	PhysicsWorld(PhysicsWorld&& o) noexcept :
		kinematics(o.kinematics),
		friction(o.friction),
		drag(o.drag),
		elasticity(o.elasticity),
		uniformCircularMotion(o.uniformCircularMotion),
		vector2d(o.vector2d),
		vector3d(o.vector3d),
		energy(o.energy),
		momentum(o.momentum),
		torque(o.torque),
		statics(o.statics),
		rotationalMotion(o.rotationalMotion),
		temperature(o.temperature),
		heat(o.heat),
		thermodynamic(o.thermodynamic),
		dynamics_and_forces(o.dynamics_and_forces),
		fluid_statics(o.fluid_statics),
		fluid_dynamics(o.fluid_dynamics),
		waves(o.waves),
		hearing(o.hearing),
		electric_charge(o.electric_charge),
		electric_potential(o.electric_potential),
		electric_current(o.electric_current),
		periodic_elements(o.periodic_elements),
		circuits(o.circuits),
		magnetism(o.magnetism),
		_ptr_(o._ptr_){} // move constructor

	/**========================================================================
	 * overloaded operators
	 */
	PhysicsWorld operator+(const PhysicsWorld& r)const
	{
		double x, y, z;
		x = static_cast<ld>(vector3d->returnX() + r.vector3d->returnX());
		y = static_cast<ld>(vector3d->returnY() + r.vector3d->returnY());
		z = static_cast<ld>(vector3d->returnZ() + r.vector3d->returnZ());
		PhysicsWorld sum;
		sum.vector3d->set_coordinates(x, y, z);
		x = static_cast<ld>(vector2d->return_x() + r.vector2d->return_x());
		y = static_cast<ld>(vector2d->return_y() + r.vector2d->return_y());
		sum.vector2d->set_coordinates(x, y);
		sum.vector3d->mode = r.vector3d->mode;
		sum.vector2d->mode = this->vector2d->mode;
		return sum;
	}
	PhysicsWorld operator+(_ld_ n)const
	{
		double x, y, z;
		x = static_cast<ld>(vector3d->returnX() + n);
		y = static_cast<ld>(vector3d->returnY() + n);
		z = static_cast<ld>(vector3d->returnZ() + n);
		PhysicsWorld sum;
		sum.vector3d->set_coordinates(x, y, z);
		x = static_cast<ld>(vector2d->return_x() + n);
		y = static_cast<ld>(vector2d->return_y() + n);
		sum.vector2d->set_coordinates(x, y);
		sum.vector3d->mode = this->vector3d->mode;
		sum.vector2d->mode = this->vector2d->mode;
		_val_ = +n;
		return sum;
	}

	PhysicsWorld& operator+=(const PhysicsWorld& r)
	{
		double x, y, z;
		x = static_cast<ld>(vector3d->returnX() + r.vector3d->returnX());
		y = static_cast<ld>(vector3d->returnY() + r.vector3d->returnY());
		z = static_cast<ld>(vector3d->returnZ() + r.vector3d->returnZ());
		PhysicsWorld sum;
		sum.vector3d->set_coordinates(x, y, z);
		x = static_cast<ld>(vector2d->return_x() + r.vector2d->return_x());
		y = static_cast<ld>(vector2d->return_y() + r.vector2d->return_y());
		sum.vector2d->set_coordinates(x, y);
		sum.vector3d->mode = r.vector3d->mode;
		sum.vector2d->mode = this->vector2d->mode;
		return sum;

	}
	PhysicsWorld operator+()const
	{
		double x, y, z;
		x = static_cast<ld>(vector3d->returnX() + 1.0);
		y = static_cast<ld>(vector3d->returnY() + 1.0);
		z = static_cast<ld>(vector3d->returnZ() + 1.0);
		PhysicsWorld sum;
		sum.vector3d->set_coordinates(x, y, z);
		x = static_cast<ld>(vector2d->return_x() + 1.0);
		y = static_cast<ld>( vector2d->return_y() + 1.0);
		vector2d->set_coordinates(x, y);
		vector3d->mode = this->vector3d->mode;
		vector2d->mode = this->vector2d->mode;
		_val_ += 1;

		return sum;
	}

	// destructor
	~PhysicsWorld();
};
#endif // !PHYSICSWORLD_H