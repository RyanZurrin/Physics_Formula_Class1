#pragma once
/**
 * @class ElectricCurrent
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  12/31/2020
 * @lastEdit 12/31/2020
 */

#ifndef ELECTRICCURRENT_H
#define ELECTRICCURRENT_H
#include "ElectricPotential.h"

#include <iostream>

static struct Resistivities
{
	const ld SILVER = 1.59 * pow(10, -8); //conductor, OHm*m
	const ld COPPER = 1.72 * pow(10, -8); //conductor, OHm*m
	const ld GOLD = 2.44 * pow(10, -8); //conductor, OHm*m
	const ld ALUMINUM = 2.65 * pow(10, -8); //conductor, OHm*m
	const ld TUNGSTEN = 5.6 * pow(10, -8); //conductor, OHm*m
	const ld IRON = 9.71 * pow(10, -8); //conductor, OHm*m
	const ld PLATINUM = 10.6 * pow(10, -8); //conductor, OHm*m
	const ld STEEL = 20.0 * pow(10, -8); //conductor, OHm*m
	const ld LEAD = 22.0 * pow(10, -8); //conductor, OHm*m
	const ld MANGANIN = 44.0 * pow(10, -8); //conductor, OHm*m
	const ld CONSTANTAN = 49.0 * pow(10, -8); //conductor, OHm*m
	const ld MERCURY = 96.0 * pow(10, -8); //conductor, OHm*m
	const ld NICHROME = 100.0 * pow(10, -8); //conductor, OHm*m

	const ld CARBON_PURE = 3.5 * pow(10, 5); //semiconductor, OHm*m
	/// <summary>
	/// The CARBON variable can be between 3.5 and 60 * 10^5 OHm*m. there is a
	/// setCARBON method you can use to adjust its value. Its not checked so if you
	/// put in a invalid number its on you, your calculation will be wrong. In the
	/// argument only pass the first part, example 18.7. not 18.7*10^5. that gets added
	/// automatically.
	/// </summary>
	ld CARBON = 10 * pow(10, 5); //semiconductor, OHm*m
	/// <summary>
	/// Sets the carbon variable.
	/// </summary>
	/// <param name="value">The value passed should be between 3.5 and 60.</param>
	void setCARBON(ld value) { CARBON = value * pow(10, 5); }

	const ld GERMANIUM_PURE = 600.0 * pow(10, -3); //semiconductor, OHm*m
	/// <summary>
	/// The GERMANIUM variable can be between 1 and 600 * 10^5 OHm*m. there is a
	/// setGERMANIUM method you can use to adjust its value. Its not checked so if you
	/// put in a invalid number its on you, your calculation will be wrong. In the
	/// argument only pass the first part, example 18.7. not 18.7*10^-3. that gets added
	/// automatically.
	/// </summary>
	ld GERMANIUM = 300 * pow(10, -3); //semiconductor, OHm*m
	/// <summary>
	/// Sets the GERMANIUM variable.
	/// </summary>
	/// <param name="value">The value passed should be between 1 and 600.</param>
	void setGERMANIUM(ld value) { GERMANIUM = value * pow(10, -3); }

	const ld SILICON_PURE = 2300; //semiconductor, OHm*m
	/// <summary>
	/// The SILICON variable can be between .1 and 2300 OHm*m. there is a
	/// setSILICON method you can use to adjust its value. Its not checked so if you
	/// put in a invalid number its on you, your calculation will be wrong.
	/// </summary>
	ld SILICON = .1; //semiconductor, OHm*m
	/// <summary>
	/// Sets the Silicon variable.
	/// </summary>
	/// <param name="value">The value passed should be between .1 and 2299.</param>
	void setSILICON(ld value) { SILICON = value * pow(10, -3); }

	const ld AMBER = 5.0 * pow(10, 14); // insulator, OHm*m

	/// <summary>
	/// The GLASS variable can be between 10^9 and 10^14 OHm*m. there is a
	/// setGLASS method you can use to adjust its value. Its not checked so if you
	/// put in a invalid number its on you, your calculation will be wrong.
	/// </summary>
	ld GLASS = pow(10, 9); //semiconductor, OHm*m
	/// <summary>
	/// Sets the GLASS variable.
	/// </summary>
	/// <param name="value">The value passed should be between 10^9 - 10^14.</param>
	void setGLASS(ld value) { SILICON = value * pow(10, -3); }


}resistivity;


static struct TemperatureCoefficientsOfResistivity
{
	const ld SILVER = 3.8 * pow(10, -3); //1/C
	const ld COPPER = 3.9 * pow(10, -3); //1/C
	const ld GOLD = 3.4 * pow(10, -3); //1/C

}coefficients_of_resistivity;


static int electricCurrent_objectCount = 0;


class ElectricCurrent
{
private:
	static void countIncrease() { electricCurrent_objectCount += 1; }
	static void countDecrease() { electricCurrent_objectCount -= 1; }
public:
	ElectricCurrent* _electricCurrentPtr;

	ElectricCurrent()
	{
		_electricCurrentPtr = nullptr;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	ElectricCurrent(const ElectricCurrent& t)
	{
		_electricCurrentPtr = t._electricCurrentPtr;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	ElectricCurrent(ElectricCurrent&& t) noexcept
	{
		_electricCurrentPtr = t._electricCurrentPtr;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	ElectricCurrent& operator=(const ElectricCurrent& t)
	{
		if (this != &t)
		{
			_electricCurrentPtr = t._electricCurrentPtr;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\n electric current object count: " << electricCurrent_objectCount << std::endl; }
	static int get_objectCount() { return electricCurrent_objectCount; }


	/// <summary>
	/// calculates the electric current (I) defined as the rate at which charge
	/// (Q) flows through a given time (t).
	/// </summary>
	/// <param name="Q">The change in current.</param>
	/// <param name="t">The time over which current passes through.</param>
	/// <returns>the electric current SI unit of ampere (A)</returns>
	static ld electricCurrent(const ld Q, const ld t);





	~ElectricCurrent()
	{
		delete _electricCurrentPtr;
	}

};

inline ld ElectricCurrent::electricCurrent(const ld Q, const ld t)
{
	return Q / t;
}

#endif

