#pragma once
/**
 * @class Waves
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   12/17/2020
 ____________________________________________________________________________*/

#ifndef WAVES_H
#define WAVES_H
#include <iostream>
#include "Elasticity.h"
#include "Energy.h"


static int waves_objectCount = 0;



class Waves :
	public Elasticity, public Energy
{
private:
	static void countIncrease() { waves_objectCount += 1; }
	static void countDecrease() { waves_objectCount -= 1; }
public:
	Waves* _wavePtr;

	Waves()
	{
		_wavePtr = nullptr;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	Waves(const Waves& t)
	{
		_wavePtr = t._wavePtr;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	Waves(Waves&& t) noexcept
	{
		_wavePtr = t._wavePtr;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	Waves& operator=(const Waves& t)
	{
		if (this != &t)
		{
			_wavePtr = t._wavePtr;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\n waves object count: "
		<< waves_objectCount << std::endl; }
	static int get_objectCount() { return waves_objectCount; }


	/// <summary>
	/// calculates the energy stored in a deformed system that obey's Hook's law.
	/// </summary>
	/// <param name="k">The force constant.</param>
	/// <param name="x">The displacement from equilibrium.</param>
	/// <returns>PE, stored potential energy</returns>
	static ld elasticPotentialEnergy(const ld k, const ld x)
	{
		return .5 * (k * pow(x, 2));
	}





	~Waves()
	{
		delete _wavePtr;
	}

};
#endif


