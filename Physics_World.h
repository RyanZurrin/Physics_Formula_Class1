#pragma once
/**
 * @class PhysicsWorld
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   10/15/2020
 */
#ifndef PHYSICS_WORLD_H
#define PHYSICS_WORLD_H
#include <gsl/gsl_integration.h>
#include <gsl/gsl_linalg.h>
#include <Eigen/Eigen>
#include "Circuits.h"
#include "Drag.h"
#include "DynamicsAndForces.h"
#include "Elasticity.h"
#include "ElectricCharge.h"
#include "ElectricCurrent.h"
#include "ElectricPotential.h"
#include "ElectroMagneticInduction.h"
#include "ElectromagneticWaves.h"
#include "Energy.h"
#include "FluidDynamics.h"
#include "FluidStatics.h"
#include "Friction.h"
#include "GeometricOptics.h"
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
#include "TriangleSolver.h"
#include "UniformCircularMotion.h"
#include "Vector3D.h"
#include "VectorND.h"
#include "VisionOpticalInstruments.h"
#include "WaveOptics.h"
#include "Waves.h"
#include "SpecialRelativity.h"
#include "QuantumPhysics.h"
typedef TriangleSolver TS;
typedef QuantumPhysics QP;
typedef SpecialRelativity SR;
typedef WaveOptics WO;
typedef VisionOpticalInstruments VOI;
typedef UniformCircularMotion UCM;
typedef Thermodynamics TD;
typedef Temperature TEMP;
typedef RotationalMotion RM;
typedef PeriodicElements PE;
typedef GeometricOptics GO;
typedef FluidStatics FS;
typedef FluidDynamics FD;
typedef ElectromagneticWaves EMW;
typedef ElectroMagneticInduction EMI;
typedef ElectricPotential EP;
typedef ElectricCurrent EC;
typedef ElectricCharge ELCHRG;
typedef DynamicsAndForces DAF;



using namespace Eigen;
//class Physics_World;
typedef long double ld;

static auto physics_objectCount = 0;

//_____________________________________________________________________________
//global constants, methods and structures
//
//


static ld _val_;// = 0.0;



/// <summary>
/// Sets the value of the static member _val_
/// </summary>
/// <param name="v">The value to set val too.</param>
/// <returns>returns the value of v</returns>
static auto setVal = []<class T>(const T & v) {
	_val_ = v;
	return _val_;
};

/// <summary>
/// Gets the value.
/// </summary>
/// <returns></returns>
static auto getVal = []<class T>() {
	return  _val_;
};

/// <summary>
/// Shows the value with a label in front and units in back
/// </summary>
/// <param name="label">The label.</param>
/// <param name="units">The units.</param>
static auto show_val = []<class T>(const T label = "", const T units = "") {
	cout << "\n"<<label<<": " << _val_ << " "<<units <<endl;
};

/// <summary>
/// Prints the vector values of passed in vector.
/// </summary>
/// <param name="v">The v.</param>
/*
static void printVectorValues(vector<ld>& v)
{
	cout << "vector: ";
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << ", ";
	}
	std::cout << std::endl;
}//end printVectorValues
*/
/// <summary>
/// Prints the vector values of a vector
/// </summary>
/// <param name="v">The vector to print.</param>
template<typename T>
static auto printVectorValues(vector<T>& v)
{
	cout << "vector: ";
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << ", ";
	}
	std::cout << std::endl;
}//end printVectorValues

/// <summary>
/// Prints the vector of any type
/// </summary>
/// <param name="t">The vector to print.</param>
template<typename T>
void printVector(const T& t) {
	std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
}//end printVector

/// <summary>
/// Prints out a multidimensional vector values of any type.
/// </summary>
/// <param name="t">The vector to print.</param>
template<typename T>
void printVectorInVector(const T& t) {
	std::for_each(t.cbegin(), t.cend(), printVector<typename T::value_type>);
}//end printVectorInVector

/// <summary>
/// Prints an array of any type
/// </summary>
/// <param name="array">The array.</param>
template <typename T, size_t size>
void static printArray(const T(&array)[size])
{
	for (size_t i = 0; i < size; i++)
		cout << array[i] << " ";

	cout << endl;
}//end printArray

/// <summary>
/// Prints a map of any types out in its entirety.
/// </summary>
/// <param name="m">The map to print.</param>
template<typename K, typename V>
void printMap(std::map<K,V> const &m)
{
	for (auto const& pair: m) {
		std::cout << "{" << pair.first << ": " << pair.second << "}\n";
	}
}//end print_map

/// <summary>
/// Searches any type map by found value. only use if you need the values saved.\n
/// WARNING*** printMapValues allows you to pass only a map and a search value in
/// and it instantiates a vector within its scope and then fills it as well as
/// prints out the values to screen.*****\n
/// Use this method when you need to find the
/// values that match and then use them in other calculations within client code.
/// </summary>
/// <param name="vec">The vector to store the results in.</param>
/// <param name="mapOfElemen">The map of elements to search by values.</param>
/// <param name="value">The value to look for.</param>
/// <returns>true if a match was found: else false</returns>
template<typename K, typename V>
bool searchMapByValue(std::vector<K> & vec, std::map<K, V> mapOfElemen, V value)
{
	bool bResult = false;
	auto it = mapOfElemen.begin();
	while(it != mapOfElemen.end())
	{
		if(it->second == value)
		{
			bResult = true;
			vec.push_back(it->first);
		}
		it++;
	}
	return bResult;
}//end searchMapByValue
template<typename K, typename V>
bool searchMapByValue(std::vector<K> & vec, std::multimap<K, V> mapOfElemen, V value)
{
	bool bResult = false;
	auto it = mapOfElemen.begin();
	while(it != mapOfElemen.end())
	{
		if(it->second == value)
		{
			bResult = true;
			vec.push_back(it->first);
		}
		it++;
	}
	return bResult;
}//end searchMapByValue

/// <summary>
/// Prints the map keys found by search value.
/// </summary>
/// <param name="m">The map to search.</param>
/// <param name="val">The value to search for.</param>
template<typename K, typename V>
void printMapByValue(std::map<K,V> m, const V val)
{
	std::cout << "looking for value: "<< val<<endl;
	std::vector<std::string> results;
	bool tests = searchMapByValue(results, m, val);
	if(tests)
	{
		std::cout<<"Keys with value "<< val<< " are:"<<std::endl;
		printVector(results);

	}
	else
	{
		std::cout<<"No Key is found with the given value"<<std::endl;
	}

}//end printMapByValue

/// <summary>
/// Prints the map keys found by search value.
/// </summary>
/// <param name="m">The map to search.</param>
/// <param name="val">The value to search for.</param>
template<typename K, typename V>
void printMapByValue(std::multimap<K,V> m, const V val)
{
	std::cout << "looking for value: "<< val<<endl;
	std::vector<std::string> results;
	bool tests = searchMapByValue(results, m, val);
	if(tests)
	{
		std::cout<<"Keys with value "<< val<< " are:"<<std::endl;
		printVector(results);

	}
	else
	{
		std::cout<<"No Key is found with the given value"<<std::endl;
	}

}//end printMapByValue

/// <summary>
/// Prints an array of long doubles with a size of n
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
}//end printArr




/// <summary>
/// Calculates the area of a sphere.
/// </summary>
/// <param name="r">The radius.</param>
/// <returns>the area of sphere (m^2)</returns>
static auto sphereArea = []<class T>(const T r)
{
	return 4.0 * _PI_ * (r * r);
};


/// <summary>
/// Calculates the volume of a sphere.
/// </summary>
/// <param name="r">The radius.</param>
/// <returns>the volume of sphere(m^3)</returns>
static auto sphereVolume = []<class T>(const ld r)
{
	return (4.0 / 3.0) * (_PI_ * (r * r * r));
};


/// <summary>
/// Calculates the circumference of a circle.
/// </summary>
/// <param name="rd">The radius or diameter, use mode to specify.</param>
/// <param name="mode">use 'd' to specify if you use diameter and not
/// radius. Do not add anything here if it is the radius you are using
/// as it is defaulted to radius</param>
/// <returns>circumference of circle (m)</returns>
static auto circleCircumference = []<class T>(const T rd, const char mode = 'r')
{
	if (mode == 'r')
	{
		return 2.0 * _PI_ * rd;
	}
	return _PI_ * rd;
};

/// <summary>
/// Calculates the area of a circle.
/// </summary>
/// <param name="rd">The radius or diameter, use mode to specify.</param>
/// <param name="mode">use 'd' to specify if you use diameter and not
/// radius. Do not add anything here if it is the radius you are using
/// as it is defaulted to radius</param>
/// <returns>area of a circle (m^2)</returns>
static auto circleArea = []<class T>(const T rd, const char mode = 'r')
{
	if (mode == 'r')
	{
		return _PI_ * (rd * rd);
	}
	return (_PI_ * (rd * rd)) / 4.0;
};

/// <summary>
/// Calculates the change in any two values xi and xf.
/// </summary>
/// <param name="xi">The  initial starting value.</param>
/// <param name="xf">The final value.</param>
/// <returns>the change in a value</returns>
static auto delta = []<class T>(const T xi, const T xf)
{
	return xf - xi;
};


/// <summary>
/// structure filled with conversion methods
/// </summary>
static struct Conversions
{
	struct SpecificHeatConverter
	{
		template<typename T>
		static auto joulesKgC_to_kCalKgC(const T j = _val_)
		{
			return j * .000238845896627;
		}
		template<typename T>
		static auto kCalKgC_to_joulesKgC_IT(const T kCal = _val_)
		{
			return kCal * 4186.8;
		}
	}heat;

	template<typename T>
	static auto atomicWeight_to_kilograms(const T u = _val_)
	{
		return u * 1.6605402 * pow(10, -27);
	}

	template<typename T>
	static auto kiloJoules_to_calories(const T kJ)
	{
		return (kJ * 1000.0) / 4186.0;
	}
	template<typename T>
	static auto revolutionsFromRadians(const T radTotal)
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
	template<typename T>
	static auto revolutions_min_to_radians_second(const T revMin)
	{
		return (revMin * 2.0 * _PI_) / 60;
	}

	/**
	 * @brief Returns the conversion from revolutions per radian second to
	 * revolutions per minute
	 * @param radSec is the rotation speed in radians per second
	 * @returns the revolutions per minute
	 */
	template<typename T>
	static auto radians_second_to_revolutions_minute(const T radSec)
	{
		return (radSec * 60.0) / (2.0 * _PI_);
	}

	/**
	 *  @brief Returns the ratio of the value to gravity
	 *  @param unit can be whatever you are dividing by gravity acceleration
	 *  @returns the gravity ratio
	 */
	template<typename T>
	static auto gravity_ratio(const T unit)
	{
		return unit / _G_;
	}


	/**
	 * @brief Returns the conversion from meters per second to kilometers
	 * per hour
	 * @param mps is meters per second
	 * @returns kilometers per hour
	 */
	template<typename T>
	static auto mps_to_kmh(const T mps = _val_)
	{
		return mps * 3.6;
	}
	/**
	 * @brief Returns the conversion from kilometers per hour to meters per
	 * second
	 * @param kmh is kilometers per hour
	 * @returns meters per second
	 */
	template<typename T>
	static auto kmh_to_mps(const T kmh = _val_)
	{
		return kmh / 3.6;
	}

	/// <summary>
	/// KMSs to KMH.
	/// </summary>
	/// <param name="kms">kilometers per second.</param>
	/// <returns>kilometers per hour</returns>
	template<typename T>
	static auto kms_to_kmh(const T kms = _val_)
	{
		return kms * 3600.0;
	}
	/// <summary>
	/// KMHs to KMS.
	/// </summary>
	/// <param name="kmh">kilometers per hour.</param>
	/// <returns>kilometers per second</returns>
	template<typename T>
	static auto kmh_to_kms(const T kmh = _val_)
	{
		return kmh / 3600.0;
	}
	/**
	 * @brief Returns the conversion from miles per hour to meters per second
	 * @param mph is miles per hour
	 * @returns meters per second
	 */
	template<typename T>
	static auto mph_to_mps(const T mph = _val_)
	{
		return mph / 2.237;
	}
	/**
	 * @brief Returns the conversion from meters per second to miles per hour
	 * @param mps is meters per second
	 * @returns miles per hour
	 */
	template<typename T>
	static auto mps_to_mph(const T mps = _val_)
	{
		return mps * 2.237;
	}
	/**
	 * @brief Returns the conversion from milliseconds to seconds
	 * @param ms to be converted to seconds
	 * @returns seconds from milliseconds
	 */
	template<typename T>
	static auto millisecond_to_seconds(const T ms = _val_)
	{
		return ms / 1000;
	}
	template<typename T>
	static auto minutes_to_seconds(const T min = _val_)
	{
		return min * 60;
	}
	template<typename T>
	static auto hours_to_seconds(const T hours = _val_)
	{
		return hours * 3600;
	}
	/**
	 * @brief Returns the conversion from days to seconds for use in calculation
	 * @param days can be expressed as a decimal, four and a half days would
	 * be 4.5
	 * @returns total seconds converted from days
	 */
	template<typename T>
	static auto days_to_seconds(const T days = _val_)
	{
		return days * 86400.0;
	}
	/**
	 * @brief Returns the conversion from seconds to days
	 * @param seconds to be converted
	 * @returns days
	 */
	template<typename T>
	static auto seconds_to_days(const T seconds = _val_)
	{
		return seconds / 86400.0;
	}
	/**
	 * @brief Returns the conversion from miles to meters
	 * @param miles to be converted
	 * @returns meters from miles
	 */
	template<typename T>
	static auto miles_to_meters(const T miles = _val_)
	{
		return miles * 1609.0;
	}
	/**
	 * @brief Returns the conversion from feet to meters
	 * @param feet to be converted
	 * @returns meters
	 */
	template<typename T>
	static auto feet_to_meters(const T feet = _val_)
	{
		return feet / 3.281;
	}
	/**
	 * @brief Returns the conversion from inches to meters
	 * @param inches to be converted
	 * @returns meters
	 */
	template<typename T>
	static auto inches_to_meters(const T inches = _val_)
	{
		return inches / 39.37;
	}
	/**
	 * @brief Returns the conversion from meters to inches
	 * @param meters is the total meters
	 * @returns inches
	 */
	template<typename T>
	static auto meters_to_inches(const T meters = _val_)
	{
		return meters * 39.37;
	}
	/**
	 * @brief Returns the conversion from centimeters to meters
	 * @param cm centimeters
	 * @returns meters
	 */
	template<typename T>
	static auto centimeters_to_meters(const T cm = _val_)
	{
		return cm / 100;
	}
	template<typename T>
	static auto meters_to_centimeters(const T m = _val_)
	{
		return m * 100;
	}
	template<typename T>
	static auto kilometers_to_meters(const T km = _val_)
	{
		return km * 1000;
	}
	template<typename T>
	static auto millimeters_to_meters(const T mm = _val_)
	{
		return mm / 1000;
	}
	template<typename T>
	static auto micrometers_to_meters(const T Mm = _val_)
	{
		return Mm / pow(1, -6);
	}
	template<typename T>
	static auto nanometers_to_meters(const T nm = _val_)
	{
		return nm / pow(1, -9);
	}
	template<typename T>
	static auto pound_to_kilogram(const T lbs = _val_)
	{
		return lbs / 2.205;
	}
	template<typename T>
	static auto milligram_to_kilogram(const T mg = _val_)
	{
		return mg / pow(1, -6);
	}
	template<typename T>
	static auto gram_to_kilogram(const T g = _val_)
	{
		return g / 1000;
	}
	template<typename T>
	static auto ounce_to_kilogram(const T ounce = _val_)
	{
		return ounce / 35.274;
	}
	template<typename T>
	static auto watts_to_kilowatts(const T watt = _val_)
	{
		return watt / 1000;
	}
	template<typename T>
	static auto kWh_to_joules(const T kWh = _val_)
	{
		return kWh * (3.6*pow(10, 6));
	}
	template<typename T>
	static auto joules_to_kWh(const T j = _val_)
	{
		return j / (3.6 * pow(10, 6));
	}
	template<typename T>
	static auto joules_to_eV(const T j = _val_)
	{
		return j / _PROTON_CHARGE_;
	}
	template<typename T>
	static auto newtonMeters_to_ftPounds(const T Nm = _val_)
	{
		return Nm / .73756;
	}
	template<typename T>
	static auto radians_to_revolutions(const T rad = _val_)
	{
		return rad / (2 * _PI_);
	}
	template<typename T>
	static auto revolutions_to_radians(const T rev = _val_)
	{
		return rev * 2 * _PI_;
	}
	template<typename T>
	static auto atm_to_pascals(const T atm = _val_)
	{
		return atm * 101325.0;
	}

}converter;

/// <summary>
/// structure filled with common densities
/// </summary>
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



/// <summary>
/// the Physics world class that is the driver class of many smaller more
/// specific classes. This class instantiates all them classes for use in the
/// testFactory.cpp driver file.
/// </summary>
class Physics_World
{
private:
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
	VectorND<ld>* vectorNd;
	TriangleSolver* triangle;
	Kinematics* kinematics;
	Friction* friction;
	Drag* drag;
	Elasticity* elasticity;
	UniformCircularMotion* uniformCircularMotion;
	Vector2D* vector2d;
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
	ElectroMagneticInduction* emi;
	ElectromagneticWaves* emWaves;
	GeometricOptics* geometric_optics;
	WaveOptics* wave_optics;
	VisionOpticalInstruments* vision_optical;
	SpecialRelativity* relativity;
	QuantumPhysics* quantum;
	Physics_World * _ptr_;


	Physics_World();
	Physics_World(ld t1, ld t2, ld t3);
	Physics_World(ld t1, ld t2);
	Physics_World(const Physics_World&); //copy constructor
	Physics_World& operator=(const Physics_World&); //copy assignment operator
	Physics_World(Physics_World&& o) noexcept :
		vectorNd(o.vectorNd),
		triangle(o.triangle),
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
		emi(o.emi),
		emWaves(o.emWaves),
		geometric_optics(o.geometric_optics),
		wave_optics(o.wave_optics),
		vision_optical(o.vision_optical),
		relativity(o.relativity),
		quantum(o.quantum),
		_ptr_(o._ptr_){} // move constructor

	/**========================================================================
	 * overloaded operators
	 */
	Physics_World operator+(const Physics_World& r)const
	{
		double x, y, z;
		x = static_cast<ld>(vector3d->returnX() + r.vector3d->returnX());
		y = static_cast<ld>(vector3d->returnY() + r.vector3d->returnY());
		z = static_cast<ld>(vector3d->returnZ() + r.vector3d->returnZ());
		Physics_World sum;
		sum.vector3d->set_coordinates(x, y, z);
		x = static_cast<ld>(vector2d->return_x() + r.vector2d->return_x());
		y = static_cast<ld>(vector2d->return_y() + r.vector2d->return_y());
		sum.vector2d->set_coordinates(x, y);
		sum.vector3d->mode = r.vector3d->mode;
		sum.vector2d->mode = this->vector2d->mode;
		return sum;
	}
	Physics_World operator+(_ld_ n)const
	{
		double x, y, z;
		x = static_cast<ld>(vector3d->returnX() + n);
		y = static_cast<ld>(vector3d->returnY() + n);
		z = static_cast<ld>(vector3d->returnZ() + n);
		Physics_World sum;
		sum.vector3d->set_coordinates(x, y, z);
		x = static_cast<ld>(vector2d->return_x() + n);
		y = static_cast<ld>(vector2d->return_y() + n);
		sum.vector2d->set_coordinates(x, y);
		sum.vector3d->mode = this->vector3d->mode;
		sum.vector2d->mode = this->vector2d->mode;
		_val_ = +n;
		return sum;
	}

	Physics_World& operator+=(const Physics_World& r)
	{
		double x, y, z;
		x = static_cast<ld>(vector3d->returnX() + r.vector3d->returnX());
		y = static_cast<ld>(vector3d->returnY() + r.vector3d->returnY());
		z = static_cast<ld>(vector3d->returnZ() + r.vector3d->returnZ());
		Physics_World sum;
		sum.vector3d->set_coordinates(x, y, z);
		x = static_cast<ld>(vector2d->return_x() + r.vector2d->return_x());
		y = static_cast<ld>(vector2d->return_y() + r.vector2d->return_y());
		sum.vector2d->set_coordinates(x, y);
		sum.vector3d->mode = r.vector3d->mode;
		sum.vector2d->mode = this->vector2d->mode;
		return sum;

	}
	Physics_World operator+()const
	{
		double x, y, z;
		x = static_cast<ld>(vector3d->returnX() + 1.0);
		y = static_cast<ld>(vector3d->returnY() + 1.0);
		z = static_cast<ld>(vector3d->returnZ() + 1.0);
		Physics_World sum;
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
	~Physics_World();
};
#endif


//=============================================================================
//in-line class Implementation

/**
 *default constructor
 */
inline Physics_World::Physics_World()
{
	_ptr_ = nullptr;
	vectorNd = new VectorND<ld>;
	triangle = new TriangleSolver;
	kinematics = new Kinematics;
	drag = new Drag;
	elasticity = new Elasticity;
	friction = new Friction;
	uniformCircularMotion = new UniformCircularMotion;
	vector2d = new Vector2D;
	vector3d = new Vector3D;
	energy = new Energy;
	momentum = new Momentum;
	torque = new Torque;
	statics = new Statics;
	rotationalMotion = new RotationalMotion;
	temperature = new Temperature;
	heat = new Heat;
	thermodynamic = new Thermodynamics;
	dynamics_and_forces = new DynamicsAndForces;
	fluid_statics = new FluidStatics;
	fluid_dynamics = new FluidDynamics;
	waves = new Waves;
	hearing = new Hearing;
	electric_charge = new ElectricCharge;
	electric_potential = new ElectricPotential;
	electric_current = new ElectricCurrent;
	periodic_elements = new PeriodicElements;
	circuits = new Circuits;
	magnetism = new Magnetism;
	emi = new ElectroMagneticInduction;
	emWaves = new ElectromagneticWaves;
	geometric_optics = new GeometricOptics;
	wave_optics = new WaveOptics;
	vision_optical = new VisionOpticalInstruments;
	relativity = new SpecialRelativity;
	quantum = new QuantumPhysics;

	countIncrease();
	//countShow();
}
/**
 *copy constructor
 */
inline Physics_World::Physics_World(const Physics_World& p)
{
	_ptr_ = p._ptr_;
	vectorNd = p.vectorNd;
	//vector_values = p.vector_values;
	triangle = p.triangle;
	kinematics = p.kinematics;
	drag = p.drag;
	elasticity = p.elasticity;
	friction = p.friction;
	vector2d = p.vector2d;
	vector3d = p.vector3d;
	uniformCircularMotion = p.uniformCircularMotion;
	momentum = p.momentum;
	energy = p.energy;
	torque = p.torque;
	statics = p.statics;
	rotationalMotion = p.rotationalMotion;
	temperature = p.temperature;
	heat = p.heat;
	thermodynamic = p.thermodynamic;
	dynamics_and_forces = p.dynamics_and_forces;
	fluid_statics = p.fluid_statics;
	fluid_dynamics = p.fluid_dynamics;
	waves = p.waves;
	hearing = p.hearing;
	electric_charge = p.electric_charge;
	electric_potential = p.electric_potential;
	electric_current = p.electric_current;
	periodic_elements = p.periodic_elements;
	circuits = p.circuits;
	magnetism = p.magnetism;
	emi = p.emi;
	emWaves = p.emWaves;
	geometric_optics = p.geometric_optics;
	wave_optics = p.wave_optics;
	vision_optical = p.vision_optical;
	relativity = p.relativity;
	quantum = p.quantum;
	countIncrease();
}
/**
 *copy assignment operator
 */
inline Physics_World& Physics_World::operator=(const Physics_World& r)
{
	if(this != &r)
	{
		_ptr_ = r._ptr_;
		vectorNd = r.vectorNd;
		triangle = r.triangle;
		//vector_values = r.vector_values;
		kinematics = r.kinematics;
		drag = r.drag;
		elasticity = r.elasticity;
		friction = r.friction;
		vector2d = r.vector2d;
		vector3d = r.vector3d;
		uniformCircularMotion = r.uniformCircularMotion;
		energy = r.energy;
		momentum = r.momentum;
		torque = r.torque;
		statics = r.statics;
		rotationalMotion = r.rotationalMotion;
		temperature = r.temperature;
		heat = r.heat;
		thermodynamic = r.thermodynamic;
		dynamics_and_forces = r.dynamics_and_forces;
		fluid_statics = r.fluid_statics;
		fluid_dynamics = r.fluid_dynamics;
		waves = r.waves;
		hearing = r.hearing;
		electric_charge = r.electric_charge;
		electric_potential = r.electric_potential;
		electric_current = r.electric_current;
		periodic_elements = r.periodic_elements;
		circuits = r.circuits;
		magnetism = r.magnetism;
		emi = r.emi;
		emWaves = r.emWaves;
		geometric_optics = r.geometric_optics;
		wave_optics = r.wave_optics;
		vision_optical = r.vision_optical;
		relativity = r.relativity;
		quantum = r.quantum;
		countIncrease();
	}
	return *this;
}

inline Physics_World::Physics_World(const ld t1, const ld t2, const ld t3)
{
	_ptr_ = nullptr;
	vectorNd = new VectorND<ld>;
	triangle = new TriangleSolver;
	kinematics = new Kinematics;
	drag = new Drag;
	elasticity = new Elasticity;
	friction = new Friction;
	uniformCircularMotion = new UniformCircularMotion;
	vector2d = new Vector2D;
	vector3d = new Vector3D;
	energy = new Energy;
	momentum = new Momentum;
	torque = new Torque;
	statics = new Statics;
	rotationalMotion = new RotationalMotion;
	temperature = new Temperature;
	heat = new Heat;
	thermodynamic = new Thermodynamics;
	dynamics_and_forces = new DynamicsAndForces;
	fluid_statics = new FluidStatics;
	fluid_dynamics = new FluidDynamics;
	waves = new Waves;
	hearing = new Hearing;
	electric_charge = new ElectricCharge;
	electric_potential = new ElectricPotential;
	electric_current = new ElectricCurrent;
	periodic_elements = new PeriodicElements;
	circuits = new Circuits;
	magnetism = new Magnetism;
	emi = new ElectroMagneticInduction;
	emWaves = new ElectromagneticWaves;
	geometric_optics = new GeometricOptics;
	wave_optics = new WaveOptics;
	vision_optical = new VisionOpticalInstruments;
	relativity = new SpecialRelativity;
	quantum = new QuantumPhysics;

	this->vector3d->set_coordinates(t1, t2, t3);

	countIncrease();
}

inline Physics_World::Physics_World(const ld t1, const ld t2)
{
	vectorNd = new VectorND<ld>;
	triangle = new TriangleSolver;
	drag = new Drag;
	kinematics = new Kinematics;
	elasticity = new Elasticity;
	friction = new Friction;
	uniformCircularMotion = new UniformCircularMotion;
	vector2d = new Vector2D;
	vector3d = new Vector3D;
	energy = new Energy;
	momentum = new Momentum;
	torque = new Torque;
	statics = new Statics;
	rotationalMotion = new RotationalMotion;
	temperature = new Temperature;
	heat = new Heat;
	thermodynamic = new Thermodynamics;
	dynamics_and_forces = new DynamicsAndForces;
	fluid_statics = new FluidStatics;
	fluid_dynamics = new FluidDynamics;
	waves = new Waves;
	hearing = new Hearing;
	electric_charge = new ElectricCharge;
	electric_potential = new ElectricPotential;
	electric_current = new ElectricCurrent;
	periodic_elements = new PeriodicElements;
	circuits = new Circuits;
	magnetism = new Magnetism;
	emi = new ElectroMagneticInduction;
	emWaves = new ElectromagneticWaves;
	geometric_optics = new GeometricOptics;
	wave_optics = new WaveOptics;
	vision_optical = new VisionOpticalInstruments;
	relativity = new SpecialRelativity;
	quantum = new QuantumPhysics;
	_ptr_ = nullptr;
	this->vector2d->set_coordinates(t1, t2);
}

inline Physics_World::~Physics_World()
{
	delete vectorNd;
	delete triangle;
	delete kinematics;
	delete elasticity;
	delete friction;
	delete vector2d;
	delete vector3d;
	delete drag;
	delete uniformCircularMotion;
	delete energy;
	delete momentum;
	delete _ptr_;
	delete torque;
	delete statics;
	delete rotationalMotion;
	delete temperature;
	delete heat;
	delete thermodynamic;
	delete dynamics_and_forces;
	delete fluid_statics;
	delete fluid_dynamics;
	delete waves;
	delete hearing;
	delete electric_charge;
	delete electric_potential;
	delete electric_current;
	delete periodic_elements;
	delete circuits;
	delete magnetism;
	delete emi;
	delete emWaves;
	delete geometric_optics;
	delete wave_optics;
	delete vision_optical;
	delete relativity;
	delete quantum;
	countDecrease();
	//countShow();
}