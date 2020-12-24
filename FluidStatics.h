#pragma once
/**
 * @class FluidStatics
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   10/15/2020
 */
#ifndef FLUIDSTATICS_H
#define FLUIDSTATICS_H
#include <iostream>
typedef long double ld;
static int fluidStatics_objectCount = 0;


class FluidStatics
{
private:
	static void countIncrease() { fluidStatics_objectCount += 1; }
	static void countDecrease() { fluidStatics_objectCount -= 1; }
public:
	FluidStatics* _fluidStaticPtr;
	

	FluidStatics()
	{
		_fluidStaticPtr = nullptr;
		countIncrease();
	}

	/**
 * @brief copy constructor
 */
	FluidStatics(const FluidStatics& t)
	{
		_fluidStaticPtr = t._fluidStaticPtr;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	FluidStatics(FluidStatics&& t) noexcept
	{
		_fluidStaticPtr = t._fluidStaticPtr;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	FluidStatics& operator=(const FluidStatics& t)
	{
		if (this != &t)
		{
			_fluidStaticPtr = t._fluidStaticPtr;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\nfluid statics object count: " << fluidStatics_objectCount << std::endl; }
	static int get_objectCount() { return fluidStatics_objectCount; }

	/**
	*@brief calculates density
	* p = m * v
	* @param m mass kg
	* @param V volume in m^3
	*/
	static ld density(const ld m, const ld v) {
		return m / v;
	}

	/**
	*@brief calculates volume
	* v = m / p
	* @param m mass kg
	* @param p volume in m^3
	*/
	static ld volume(const ld m, const ld p) {
		return m / p;
	}

	/**
	*@brief calculates mass
	* m = p * v
	* @param p mass kg
	* @param v volume in m^3
	*/
	static ld mass(const ld p, const ld v) {
		return p * v;
	}

	/**
	* 
	*/






	~FluidStatics()
	{
		delete _fluidStaticPtr;
		countDecrease();
	}
};

#endif
