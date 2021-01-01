#pragma once
/**
 * @class ElectricCharge
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  12/31/2020
 * @lastEdit 12/31/2020
 */

#ifndef ELECTRICCHARGE_H
#define ELECTRICCHARGE_H
#include <iostream>


static int electricCharge_objectCount = 0;


class ElectricCharge
{
private:
	static void countIncrease() { electricCharge_objectCount += 1; }
	static void countDecrease() { electricCharge_objectCount -= 1; }
public:
	ElectricCharge* _electricChargePtr;

	ElectricCharge()
	{
		_electricChargePtr = nullptr;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	ElectricCharge(const ElectricCharge& t)
	{
		_electricChargePtr = t._electricChargePtr;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	ElectricCharge(ElectricCharge&& t) noexcept
	{
		_electricChargePtr = t._electricChargePtr;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	ElectricCharge& operator=(const ElectricCharge& t)
	{
		if (this != &t)
		{
			_electricChargePtr = t._electricChargePtr;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\n electric charge object count: " << electricCharge_objectCount << std::endl; }
	static int get_objectCount() { return electricCharge_objectCount; }


	~ElectricCharge()
	{
		delete _electricChargePtr;
	}

};
#endif

