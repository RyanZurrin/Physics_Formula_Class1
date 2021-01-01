#pragma once
/**
 * @class Hearing
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   12/31/2020
 */

#ifndef HEARING_H
#define HEARING_H

#include "Waves.h"
#include <iostream>


static int hearing_objectCount = 0;


class Hearing :
    public Waves
{
private:
	static void countIncrease() { hearing_objectCount += 1; }
	static void countDecrease() { hearing_objectCount -= 1; }
public:
	Hearing* _hearingPtr;

	Hearing()
	{
		_hearingPtr = nullptr;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	Hearing(const Hearing& t)
		: Waves(t)
	{
		_hearingPtr = t._hearingPtr;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	Hearing(Hearing&& t) noexcept
	{
		_hearingPtr = t._hearingPtr;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	Hearing& operator=(const Hearing& t)
	{
		if (this != &t)
		{
			_hearingPtr = t._hearingPtr;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\n hearing object count: " << hearing_objectCount << std::endl; }
	static int get_objectCount() { return hearing_objectCount; }


	~Hearing()
	{
		delete _hearingPtr;
	}

};
#endif

