#pragma once
/**
 * @class QuantumPhysics
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  5/15/2021
 * @lastEdit 5/15/2021
 */

#ifndef QUANTUM_PHYSICS
#define QUANTUM_PHYSICS
#include "SpecialRelativity.h"
#include <iostream>

static int quantum_objectCount = 0;
class QuantumPhysics :
	public SpecialRelativity
{

public:
	QuantumPhysics* _quantumPtr;

	QuantumPhysics()
	{
		_quantumPtr = nullptr;
		quantumVar = 0.0;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	QuantumPhysics(const QuantumPhysics& t)
	{
		_quantumPtr = t._quantumPtr;
		quantumVar = t.quantumVar;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	QuantumPhysics(QuantumPhysics&& t) noexcept
	{
		_quantumPtr = t._quantumPtr;
		quantumVar = t.quantumVar;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	QuantumPhysics& operator=(QuantumPhysics&& t) noexcept
	{
		if (this != &t)
		{
			_quantumPtr = t._quantumPtr;
			quantumVar = t.quantumVar;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\n quantum object count: "
							<< quantum_objectCount << std::endl; }
	static int get_objectCount() { return quantum_objectCount; }


	~QuantumPhysics()
	{
		delete _quantumPtr;
	}
	void setTemplateVar(ld var) { quantumVar = var; }
	auto getTemplateVar() const { return quantumVar; }





private:
	ld quantumVar;
	static void countIncrease() { quantum_objectCount += 1; }
	static void countDecrease() { quantum_objectCount -= 1; }


};

#endif
