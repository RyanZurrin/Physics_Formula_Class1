#pragma once
//#include "ElectricCharge.h"
#include "ElectricCurrent.h"

#ifndef MAGNETISM_H
#define MAGNETISM_H

static int magnetism_objectCount = 0;

const ld _GAUSS_ = pow(10, -4); //Tesla's


class Magnetism :
	public ElectricCurrent, public ElectricCharge
{


public:
	Magnetism* _magnetismPtr;

	Magnetism()
	{
		_magnetismPtr= nullptr;
		_magnetismVar = 0.0;
		countIncrease();
	}

		Magnetism(ld var)
	{
		_magnetismPtr= nullptr;
		_magnetismVar = 0.0;
		countIncrease();
	}


	/**
	 * @brief copy constructor
	 */
	Magnetism(const Magnetism& t)
	{
		_magnetismPtr = t._magnetismPtr;
		_magnetismVar = t._magnetismVar;
		countIncrease();
	}

	/**
	 * #brief move constructor
	 */
	Magnetism(Magnetism&& t) noexcept
	{
		_magnetismPtr = t._magnetismPtr;
		_magnetismVar = t._magnetismVar;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	Magnetism& operator=(const Magnetism& t)
	{
		if (this != &t)
		{
			_magnetismPtr = t._magnetismPtr;
			_magnetismVar = t._magnetismVar;
			countIncrease();
		}
		return *this;
	}
	void setMagnetismVar(ld var) { _magnetismVar = var; }
	static void show_objectCount() { std::cout << "\n magnetism object count: "
			<< magnetism_objectCount << std::endl; }
	static int get_objectCount() { return magnetism_objectCount; }


	~Magnetism()
	{
		delete _magnetismPtr;
	}


private:
	static void countIncrease() { magnetism_objectCount += 1; }
	static void countDecrease() { magnetism_objectCount -= 1; }
	ld _magnetismVar;





};
#endif

