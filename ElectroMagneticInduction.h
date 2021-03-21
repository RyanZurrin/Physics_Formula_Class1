/**
 * @class ElectroMagneticInduction
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  3/21/2021
 * @lastEdit 3/21/2021
 */
#pragma once
#ifndef ELECTROMAGNETICINDUCTION_H
#define ELECTROMAGNETICINDUCTION_H
#include <iostream>

#include "Magnetism.h"


static int emi_objectCount = 0;
typedef long double ld;

class ElectroMagneticInduction :
	public Magnetism
{

public:
	ElectroMagneticInduction* _emiPtr;


	ElectroMagneticInduction()
	{
		_emiPtr = nullptr;
		_electroMagVar = 0.0;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	ElectroMagneticInduction(const ElectroMagneticInduction& t)
	{
		_emiPtr = t._emiPtr;
		_electroMagVar = t._electroMagVar;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	ElectroMagneticInduction(ElectroMagneticInduction&& t) noexcept
	{
		_emiPtr = t._emiPtr;
		_electroMagVar = t._electroMagVar;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	ElectroMagneticInduction& operator=(const ElectroMagneticInduction& t)
	{
		if (this != &t)
		{
			_emiPtr = t._emiPtr;
			_electroMagVar = t._electroMagVar;
			countIncrease();
		}
		return *this;
	}
	void setElectroMagVar(ld var) { _electroMagVar = var; }
	ld getElectroMagVar() { return _electroMagVar; }
	static void show_objectCount() { std::cout << "\n electromagnetic induction object count: "
				<< emi_objectCount << std::endl; }
	static int get_objectCount() { return emi_objectCount; }


	~ElectroMagneticInduction()
	{
		delete _emiPtr;
	}

	private:
	static void countIncrease() { emi_objectCount += 1; }
	static void countDecrease() { emi_objectCount -= 1; }
	ld _electroMagVar;

};
#endif

