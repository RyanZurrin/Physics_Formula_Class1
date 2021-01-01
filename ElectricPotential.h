#pragma once
/**
 * @class ElectricPotential
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  12/31/2020
 * @lastEdit 12/31/2020
 */

#ifndef ELECTRICALPOTENTIAL_H
#define ELECTRICALPOTENTIAL_H
#include <iostream>


static int electricalPotential_objectCount = 0;

static struct DielectricConstants
{

}dielectric_constants;

static struct DielectricStrength
{

}dielectric_strength;




class ElectricPotential
{
private:
	static void countIncrease() { electricalPotential_objectCount += 1; }
	static void countDecrease() { electricalPotential_objectCount -= 1; }
public:
	ElectricPotential* _electricalPotentialPtr;

	ElectricPotential()
	{
		_electricalPotentialPtr = nullptr;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	ElectricPotential(const ElectricPotential& t)
	{
		_electricalPotentialPtr = t._electricalPotentialPtr;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	ElectricPotential(ElectricPotential&& t) noexcept
	{
		_electricalPotentialPtr = t._electricalPotentialPtr;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	ElectricPotential& operator=(const ElectricPotential& t)
	{
		if (this != &t)
		{
			_electricalPotentialPtr = t._electricalPotentialPtr;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\n electrical potential object count: " << electricalPotential_objectCount << std::endl; }
	static int get_objectCount() { return electricalPotential_objectCount; }


	~ElectricPotential()
	{
		delete _electricalPotentialPtr;
	}

};
#endif