#pragma once
/**
 * @class PhysicsWorld
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   10/15/2020
 */
#ifndef PHYSICSWORLD_H
#define PHYSICSWORLD_H

#include <iostream>
#include <cmath>
#include <vector>
#include "Friction.h"
#include "Drag.h"
#include "Elasticity.h"
#include "UniformCircularMotion.h"
#include "Vector3D.h"
#include "Energy.h"
#include "Momentum.h"
#include "Statics.h"
#include "RotationalMotion.h"
#include "Torque.h"
#include "Temperature.h"
#include "Heat.h"
#include "Thermodynamics.h"
#include "DynamicsAndForces.h"
#include "FluidStatics.h"
#include "PeriodicElements.h"

//#include "reactphysics3d.h"
//using namespace rp3d;


class PhysicsWorld;
//____________________________________________________________________________
//global constants, methods and structures
//
//
//using namespace rp3d;
typedef long double ld;
typedef PhysicsWorld PW;
//using namespace std;

//Gravitational Constant 6.67408(31) * 10^(-11) * N
const ld _GC_ = 6.674 * pow(10.0, -11.0);

// speed of light in a vacuum is 299792458 m/s
const ld _c_ = 2.99792458 * pow(10.0, 8.0);

/**
 * @brief area of sphere with radius r
 */
inline ld sphereArea(const ld r)
{
	return 4.0 * _PI_ * (r * r);
}

/**
 * @brief volume of sphere with radius r
 */
inline ld sphereVolume(const ld r)
{
	return (4.0 / 3.0) * (_PI_ * (r * r * r));
}

/**
 * @circumference of a circle with radius r or diameter d
 */
inline ld circleCircumference(const ld rd, const char mode = 'r')
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
inline ld circleArea(const ld rd, const char mode = 'r')
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
inline ld delta(const ld xi, const ld xf)
{
	return xf - xi;
}
static ld _val_;// = 0.0;
static void show_val() { cout << "_val_: " << _val_ << endl; }
static void show_val(const ld val) { cout << "val: " << val << endl; }
static void show_val(const string label) { cout << label+": " << _val_ << endl; }

/**
 * @brief structure for conversion methods
 */
static struct Conversions
{
	struct SpecificHeatConverter
	{
		ld static joulesKgC_to_kcalKgC(const ld j = _val_)
		{
			return j * .000238845896627;
		}
		ld static _kcalKgC_to_joulesKgC_IT(const ld kcal = _val_)
		{
			return kcal * 4186.8;
		}
	}heat;


	ld static atomicWeight_to_kilograms(const ld u = _val_)
	{
		return u * 1.6605402 * pow(10, -27);
	}

	ld static kiloJoules_to_calories(const ld kJ)
	{
		return (kJ * 1000.0) / 4186.0;
	}

	ld static revolutionsFromRadians(const ld radTotal)
	{
		//cout << "revolutions: " << radTotal / (2.0 * _PI_) << endl;
		return radTotal / (2.0 * _PI_);
	}

	/**
	 * @brief Returns the revolutions in radians per second which is the angular velocity as well
	 * @param revMin revolutions per minute
	 * @returns revolutions in radians per second
	 */
	ld static revolutions_min_to_radians_second(const ld revMin)
	{
		return (revMin * 2.0 * _PI_) / 60;
	}

	/**
	 * @brief Returns the conversion from revolutions per radian second to revolutions per minute
	 * @param radSec is the rotation speed in radians per second
	 * @returns the revolutions per minute
	 */
	ld static radians_second_to_revolutions_minute(const ld radSec)
	{
		return (radSec * 60.0) / (2.0 * _PI_);
	}

	/**
	 *  @brief Returns the ratio of the value to gravity
	 *  @param unit can be whatever you are dividing by gravity acceleration
	 *  @returns the gravity ratio
	 */
	ld static gravity_ratio(const ld unit)
	{
		return unit / _G_;
	}


	/**
	 * @brief Returns the conversion from meters per second to kilometers per hour
	 * @param mps is meters per second
	 * @returns kilometers per hour
	 */
	ld static mps_to_kmh(const ld mps = _val_)
	{
		return mps * 3.6;
	}
	/**
	 * @brief Returns the conversion from kilometers per hour to meters per second
	 * @param kmh is kilometers per hour
	 * @returns meters per second
	 */
	ld static kmh_to_mps(const ld kmh = _val_)
	{
		return kmh / 3.6;
	}
	/**
	 * @brief Returns the conversion from miles per hour to meters per second
	 * @param mph is miles per hour
	 * @returns meters per second
	 */
	ld static mph_to_mps(const ld mph = _val_)
	{
		return mph / 2.237;
	}
	/**
	 * @brief Returns the conversion from meters per second to miles per hour
	 * @param mps is meters per second
	 * @returns miles per hour
	 */
	ld static mps_to_mph(const ld mps = _val_)
	{
		return mps * 2.237;
	}
	/**
	 * @brief Returns the conversion from milliseconds to seconds
	 * @param ms to be converted to seconds
	 * @returns seconds from milliseconds
	 */
	ld static millisecond_to_seconds(const ld ms = _val_)
	{
		return ms / 1000;
	}
	ld static minutes_to_seconds(const ld min = _val_)
	{
		return min * 60;
	}
	ld static hours_to_seconds(const ld hours = _val_)
	{
		return hours * 3600;
	}
	/**
	 * @brief Returns the conversion from days to seconds for use in calculation
	 * @param days can be expressed as a decimal, four and a half days would be 4.5
	 * @returns total seconds converted from days
	 */
	ld static days_to_seconds(const ld days = _val_)
	{
		return days * 86400;
	}
	/**
	 * @brief Returns the conversion from seconds to days
	 * @param seconds to be converted
	 * @returns days
	 */
	ld static seconds_to_days(const ld seconds = _val_)
	{
		return seconds / 86400;
	}
	/**
	 * @brief Returns the conversion from miles to meters
	 * @param miles to be converted
	 * @returns meters from miles
	 */
	ld static miles_to_meters(const ld miles = _val_)
	{
		return miles * 1609;
	}
	/**
	 * @brief Returns the conversion from feet to meters
	 * @param feet to be converted
	 * @returns meters
	 */
	ld static feet_to_meters(const ld feet = _val_)
	{
		return feet / 3.281;
	}
	/**
	 * @brief Returns the conversion from inches to meters
	 * @param inches to be converted
	 * @returns meters
	 */
	ld static inches_to_meters(const ld inches = _val_)
	{
		return inches / 39.37;
	}
	/**
	 * @brief Returns the conversion from meters to inches
	 * @param meters is the total meters
	 * @returns inches
	 */
	ld static meters_to_inches(const ld meters = _val_)
	{
		return meters * 39.37;
	}
	/**
	 * @brief Returns the conversion from centimeters to meters
	 * @param cm centimeters
	 * @returns meters
	 */
	ld static centimeters_to_meters(const ld cm = _val_)
	{
		return cm / 100;
	}
	ld static meters_to_centimeters(const ld m = _val_)
	{
		return m * 100;
	}
	ld static kilometers_to_meters(const ld km = _val_)
	{
		return km * 1000;
	}
	ld static millimeters_to_meters(const ld mm = _val_)
	{
		return mm / 1000;
	}
	ld static micrometers_to_meters(const ld Mm = _val_)
	{
		return Mm / pow(1, -6);
	}
	ld static nanometers_to_meters(const ld nm = _val_)
	{
		return nm / pow(1, -9);
	}
	ld static pound_to_kilogram(const ld lbs = _val_)
	{
		return lbs / 2.205;
	}
	ld static milligram_to_kilogram(const ld mg = _val_)
	{
		return mg / pow(1, -6);
	}
	ld static gram_to_kilogram(const ld g = _val_)
	{
		return g / 1000;
	}
	ld static ounce_to_kilogram(const ld ounce = _val_)
	{
		return ounce / 35.274;
	}
	ld static watts_to_kilowatts(const ld watt = _val_)
	{
		return watt / 1000;
	}
	ld static kWh_to_joules(const ld kWh = _val_)
	{
		return kWh * (3.6*pow(10, 6));
	}
	ld static joules_to_kWh(const ld j = _val_)
	{
		return j / (3.6 * pow(10, 6));
	}
	ld static newtonMeters_to_ftPounds(const ld Nm = _val_)
	{
		return Nm / .73756;
	}
	ld static radians_to_revolutions(const ld rad = _val_)
	{
		return rad / (2 * _PI_);
	}
	ld static revolutions_to_radians(const ld rev = _val_)
	{
		return rev * 2 * _PI_;
	}
	ld static atm_to_pascals(const ld atm = _val_)
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
	const ld water_L = 1.0; // 2700 kg/m^3
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

static void setVal(const ld v)
{
	_val_ = v;
}
class PhysicsWorld
{

private:

	static int physics_objectCount;
	static void countIncrease() { physics_objectCount += 1; }
	static void countDecrease() { physics_objectCount -= 1; }

public:

	static std::vector<ld> vector_values;
	static void setVector(vector<ld> v)
	{
		vector_values = v;
	}


	 /**
	 * @brief static member function to print values of passed in vector
	 *
	 */
	template <typename T, size_t size>
	static void show_vector_values(T (&size_t) [size])
	{
		for (auto it : size_t)
		{
			std::cout << it << ", ";
		}
		std::cout << std::endl;
	}
	static void show_vector_values();

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
	PeriodicElements* periodic_elements;


	//PhysicsCommon * physics_common;
	//PhysicsWorld * world;
	PhysicsWorld * _ptr_;

	PhysicsWorld();
	PhysicsWorld(ld t1, ld t2, ld t3);
	PhysicsWorld(ld t1, ld t2);
	PhysicsWorld(const PhysicsWorld&); //copy constructor
	PhysicsWorld& operator=(const PhysicsWorld&); //copy assignment operator
	PhysicsWorld(PhysicsWorld&& o) noexcept :
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
		periodic_elements(o.periodic_elements),
		_ptr_(o._ptr_){} // move constructor


	static ld return_val() { return _val_; }
	static vector<ld> return_vector(PhysicsWorld &v) { return v.vector_values; }

	//============================================================================
	//chapter 2 formulas

	/**
	 * @brief Returns the displacement between two positions
	 * @param startPos starting position
	 * @param endPos ending position
	 * @returns displacement.
	 */
	ld static displacement(const ld startPos,const ld endPos)
	{ return endPos - startPos; }

	/**
	 * @brief Returns the displacement from knowing the velocity and time.
	 * @param velocity in m/s
	 * @param time in seconds
	 * @returns displacement.
	 */
	ld static displacement_VxT(const ld velocity, const ld time)
	{ return velocity * time; }

	/**
	 * method: displacement_accelerating_object(ld acceleration, ld time)
	 * arguments: acceleration m/s , time in s
	 * purpose: find the displacement of an accelerating object
	 * returns:	ld, displacement
	 */
	ld static displacement_accelerating_object(const ld acceleration, const ld time)
	{ return ((acceleration) * (time * time)) / 2; }

	/**
	 * method: displacement_accelerating_object_PV(ld acceleration, ld time)
	 * arguments: velocity, acceleration m/s , position = 0m default, time in s
	 * purpose: find the displacement of an accelerating object with a starting
	 * 			position and an initial velocity along with acceleration and a time
	 * returns:	ld, displacement
	 */
	ld static displacement_accelerating_object_PV(const ld velocity,
												  const ld acceleration,
												  const ld time,
												  const ld pos = 0)
	{ return pos + (velocity * time) + (acceleration * (time * time)) / 2; }

	/**
	 * @brief calculates the displacement using the kinematic formula
	 * X = Vi*t+ 1/2*a*t^2
	 * @param velocity in m/s
	 * @param acceleration in m/s^2
	 * @param time in s
	 */
	ld static displacement_using_kinematic(const ld velocity,
										   const ld acceleration,
										   const ld time)
	{
		return (velocity * time) + (acceleration * (time * time)) / 2;
	}

	/**
	 * method: displacement_halting_VdA(ld velocity, ld acceleration)
	 * arguments: x0 = starting position(0), Sv = starting velocity, fV = ending velocity(0) a = acceleration
	 * purpose: calculate displacement for the distance to stop from moving object
	 * returns: ld, final displacement
	 */
	ld static distance_VdA(const ld pos, const ld velocityStart, const ld velocityFinal, const ld acceleration)
	{ return abs(((velocityFinal * velocityFinal) - (velocityStart * velocityStart)) / (2 * acceleration)) + pos; }

	/**
	 * method: velocity_vStart_plus_vEndD2(const ld velocityStart, const ld velocityEnd)
	 * arguments: vStart = starting velocity m/s, vEnd = ending velocity m/s
	 * purpose:	find the displacement when start and end velocity is know
	 * returns: ld, displacement
	 */
	ld static velocity_vStart_plus_vEndD2(const ld velocityStart, const ld velocityEnd)
	{ return (velocityStart + velocityEnd) / 2;	}

	/**
	 *@brief calculates the final velocity using the kinematic equation Vf = Vi + a*t
	 *@param initialVelocity is the initial velocity, many times this is zero
	 *@param acceleration is the acceleration of object
	 *@param time is amount of time taken
	 *@returns the final velocity
	 */
	ld static velocity_final_from_kinematic_time(const ld initialVelocity, const ld acceleration, const ld time)
	{	return initialVelocity + acceleration * time; }

	/**
	 *@brief calculates the final velocity using the kinematic formula vf^2 = vi^2 + 2*a*d
	 *@param initialVelocity m/s
	 *@param acceleration m/s^2
	 *@param displacement m
	 *@returns the final velocity
	 */
	ld static velocity_final_kinematic_no_time(const ld initialVelocity, const ld acceleration , const ld displacement)
	{ return sqrt(initialVelocity * initialVelocity + (2 * (acceleration * displacement))); }

	/**
	 * method: velocity_avg_DdT(ld displacement, ld time)   ss2.3 pg37
	 * arguments: displacement = avg displacement in m, time = total time  in s
	 * purpose: to calculate the average velocity using displacement divided by time
	 * returns: ld, average velocity
	 */
	ld static velocity_avg_DdT(const ld displacement, const ld time)
	{ return  displacement / time; }

	/**
	 * method: PhysicsWorld::velocity_falling_object_down(ld y, ld yf, ld v, ld a)
	 * arguments: y0 = start position,  yf = final position v = velocity, a = acceleration
	 * purpose: find the velocity of a falling object thrown downwards
	 * returns: ld, velocity
	 */
	ld static velocity_kinematic_constant_a(const ld xY0, const ld xYf, const ld velocity, const ld acceleration)
	{ return sqrt((velocity * velocity) + (2 * (acceleration * (xYf - xY0)))); }

	/**
	 * @brief calculates the final velocity using the kinematic formula Vf = Vi*t
	 * @param vi initial velocity
	 * @param t time
	 * @returns the final velocity
	 */
	ld static velocityFinal_kinematic(const ld vi, const ld t)
	{
		return vi * t;
	}

	/**
	 * method: acceleration_avg(ld vChange, ld tChange)   ss2.4  pg40
	 * arguments: vChange = average change in velocity in m/s, tChange = change in time in seconds
	 * purpose:	to find the average acceleration by dividing the avg velocity by the time
	 * returns: ld, average acceleration
	 */
	ld static acceleration_avg(const ld vChange, const ld tChange)
	{ return vChange / tChange; }

	/**
	 * method: acceleration_dispDtimeSqrd(ld displacement, ld time)
	 * arguments: 1)displacement 2)time
	 * purpose: this method can be used to calculate the acceleration of falling objects
	 * returns: ld, acceleration of object
	 */
	ld static acceleration_dispDtimeSqrd(const ld displacement, const ld time)
	{ return (2 * (displacement)) / (time * time); }

	/**
	 * method: acceleration_vStart_vEndDdisplacement(ld velocityStart, ld velocityEnd, ld displacement)const
	 * arguments: velocity start, velocity end, total displacement
	 * purpose: finds the acceleration using the starting and ending velocity and total displacement as known values
	 * returns: ld, acceleration of object
	 */
	ld static acceleration_vStart_vEndDdisplacement(const ld velocityStart, const ld velocityEnd, const ld displacement)
	{ return (velocityEnd * velocityEnd - velocityStart * velocityStart) / (2 * displacement); }

	/**
	 * method: speed_avg_DdT(ld total_distance, ld time)   ss2.3 pg37
	 * arguments: displacement = avg displacement in m, time = total time  in s
	 * purpose: to calculate the average velocity using displacement divided by time
	 * returns: ld, average velocity
	 */
	ld static speed_avg_DdT(const ld total_distance, const ld time)
	{ return abs(total_distance / time); }

	/**
	 * method: time_by_avgVdA(ld acceleration, ld velocityStart, ld velocityEnd)
	 * arguments: a = acceleration, sV = start velocity(default 0), fV = final velocity
	 * purpose: calculate time with know acceleration and final velocity end point
	 * returns: ld, time
	 */
	ld static time_by_avgVdA(const ld acceleration, const ld velocityStart, const ld velocityEnd)
	{ return (velocityEnd - velocityStart) / acceleration; }

	/**
	 * method: time_by_DisTdV(ld distance, ld velocity)
	 * arguments: distance , average velocity
	 * purpose: find the velocity of a falling object thrown downwards
	 * returns: ld, velocity
	 */
	ld static time_by_DisTdV(const ld distance, const ld velocity)
	{ return distance / velocity; }

	/**
	 * method: time_finalPos_acceleration(ld displacement, ld acceleration)
	 * arguments: displacement of object, acceleration of object
	 * purpose: find how long it takes an object with a known acceleration to travel a know distance
	 * returns: ld, time to accelerate a distance
	 */
	ld static time_by_finalPos_acceleration(const ld displacement, const ld acceleration)
	{ return sqrt((2 * displacement) / acceleration); }

	/**
	 * method: time(ld startTime, ld endTime)
	 * arguments: y = startTime = beginning time in seconds, endTime = endTime in seconds
	 * purpose: find the amount of time between two periods
	 * returns: ld, difference in two times
	 */
	ld static time_difference(const ld startTime, const ld endTime)
	{ return endTime - startTime; }

	/**
	 * method: time_kinematic_rearranged(ld velocity, ld y0, ld acceleration) const
	 * arguments: velocity, y0 = position from 0, acceleration
	 * purpose: find the amount of time between two periods
	 * returns: ld, difference in two times
	 */
	ld static time_kinematic_rearranged(const ld velocity, const ld displacement, const ld acceleration)
	{ return (-(velocity)-sqrt((velocity * velocity) - 2 * (acceleration) * (displacement))) / (acceleration); }

	/**
	 * method: slope_formula(ld y1, ld y0, ld x1, ld x0)
	 * arguments: y1 , y0, x1, x0
	 * purpose:	the general slope equation of (y1 - y0)/(x1 - x0)
	 *  to find the slope of a line between two points
	 * returns: ld, slope of line between two points
	 */
	ld static slope_formula(const ld y1, const ld y0, const ld x1, const ld x0)
	{ return (y1 - y0) / (x1 - x0);	}

	/**
	 * method: rotation_speed_2PIxRdT(ld radius, ld rotations, ld time)
	 * arguments: radius = length in m from center of rotation
	 *	rotations = how many rotations in a time period
	 *	time = time units
	 * purpose: find the speed of a spinning object, such as fan blade
	 * returns: average speed of spinning object
	 */
	ld static rotation_speed_2PIxRdT(const ld radius, const ld rotations, const ld time)
	{ return (2.0 * _PI_ * radius) / (time / rotations); }

	/**
	 * method: rotation_avgVelocity_2PIxRdT_in_1_rotation(ld radius, ld time)
	 * arguments: radius , time = time for one rotation
	 * purpose: find average velocity of a spinning object
	 * returns: ld, average velocity
	 */
	ld static rotation_avgVelocity_2PIxRdT_in_1_rotation(const ld radius, const ld time)
	{ return (2.0 * _PI_ * radius) / time; }

	/**
	 * @brief Returns the conversion of given value divided by the acceleration of gravity on earth, 9.80 m/s^2
	 * @param value the value to find the multiples of gravity of
	 * returns: g's
	 */
	ld static conversion_multiple_of_gravity(const ld value)
	{ return value / GA; }

	/**
	 * method: time_using_quadratic(ld a, ld b, ld c)
	 * arguments: a1 = default to 1, b_velocity = constant velocity, c_displacement = total distance to travel
	 * purpose: calculate the time of a merging object when velocity and displacement is know
	 * returns: ld, total time
	 */
	std::vector<ld> time_using_quadratic(ld a1, ld b_velocity, ld c_displacement)
	{
		vector_values[0] = (-b_velocity + sqrt((b_velocity * b_velocity) - 4 * a1 * c_displacement)) / (2 * a1);
		vector_values[1] = (-b_velocity - sqrt((b_velocity * b_velocity) - 4 * a1 * c_displacement)) / (2 * a1);

		return this->vector_values;
	}

	/**
	 * method: pos_vel_falling_object_upDown(double p, double v, double a, double t)
	 * arguments: p = position (0),  v = velocity, a = acceleration, t = time is s
	 * purpose: this method will fill a vector with four pieces of data in order from the right to left it
	 *			is: time, position, velocity, acceleration. use the print_vector_values() to see contents.
	 * returns: ld, vector of the time, position, velocity, acceleration.
	 */
	std::vector<ld> pos_vel_falling_object_upDown(ld v, ld a, ld t, ld p = 0.0)
	{
		this->vector_values[0] = t;
		//solution for Position:
		PhysicsWorld obj;

		this->vector_values[1] = obj.displacement_accelerating_object_PV(v, a, t, p);
		//Solution for Velocity:

		_val_ = obj.velocity_final_from_kinematic_time(v, a, t);
		this->vector_values[2] = _val_;

		this->vector_values[3] = a;
		//this->show_vector_values();

		return obj.vector_values;
	}

	//=================================================================================
	// chapter 3 formulas

	/**
	* method: projectile_range_level_ground(ld velocity, ld theta)
	* arguments: velocity, theta (initial angle relative to the horizontal
	* purpose:	calculates projectile range
	* returns: ld, range of a projectile
	*/
	ld static range_projectile_level_ground(const ld velocity, const ld angleTheta)
	{ return  ((velocity * velocity) * sin(2 * angleTheta * RADIAN) / (GA));	}

	/**
	 * @brief calculates the angle theta of a projectile
	 */
	ld static projectile_theta(const ld distance, const ld velocity)
	{
		return (asinh(distance * _Ga_) / (velocity * velocity)) / 2;
	}



	/**
	 * @brief calculates the time a projectile with an initial velocity and angle
	 *  take to reach the same level from which it was launched, forms a parabolic curve
	 * (2* launchVelocity*sin(angleTheta))/(-GA);
	 * @param launchVelocity is the initial velocity in m/s
	 * @param angleTheta the angle of te launch
	 * @returns ld, time units
	 */
	ld static time_for_projectile_to_reach_level(ld launchVelocity, ld angleTheta)
	{
		return (2 * launchVelocity * sin(angleTheta)) / (GA);
	}

	// sqrt((-2*(displacement))/-GA)
	ld air_time_initial_velocity0_y0(ld displacement)const;

	//  sqrt((-GA/(-2 * y0)))* displacement
	ld velocity_initial_horizontal_component(ld y0, ld displacement)const;

	//velocity_final_vertical_component(ld y0) const
	ld velocity_vertical_component(ld y0, ld yf = 0)const;

	// sqrt(velocityY * velocityY + velocityX * velocityX);
	// atan(velocityY / velocityX) * DEGREE;
	std::vector<ld> final_projectile_velocity_vector(ld velocityY, ld velocityX);

	// sqrt(pow(horizontal_velocity_using_distance_angle_height(toGoal,height_at_goal, angle), 2) +
	// pow(vertical_velocity_by_Xvelocity_with_angle(horizontal_velocity_using_distance_angle_height(toGoal, height_at_goal, angle), angle), 2))
	ld velocity_soccer_kick(ld toGoal, ld height_at_goal, ld angle)const;

	// targetDistance * sqrt((abs(acceleration)/((2 * (targetDistance * (tan(angle)*DEGREE) - targetHeight)))))
	ld horizontal_velocity_using_distance_angle_height(ld targetDistance, ld targetHeight, ld angle, ld acceleration = GA)const;

	// xVelocity * tan(angle*RADIAN)
	ld vertical_velocity_by_Xvelocity_with_angle(ld xVelocity, ld angle)const;

	//  atan(-((b)+sqrt((b * b) - 4 * a * c)) / (2 * a))*DEGREE;
	//  atan(-((b)-sqrt((b * b) - 4 * a * c)) / (2 * a)) * DEGREE;
	std::vector<ld> basketball_angles(ld launchVelocity, ld releaseHeight, ld hoopDistance);





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

