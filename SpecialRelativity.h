#pragma once
/**
 * class: SpecialRelativity
 * details: driver class for solving complex physics problems
 * author: Ryan Zurrin
 * dateBuilt:  5/3/2021
 * lastEdit: 5/3/2021
 */
#ifndef SPECIAL_RELATIVITY_H
#define SPECIAL_RELATIVITY_H
#include <iostream>
static int specialRelativity_objectCount = 0;
typedef long double ld;

class SpecialRelativity
{
public:
	SpecialRelativity* _specialRelativityPtr;

	SpecialRelativity()
	{
		_specialRelativityPtr = nullptr;
		specialRelativityVar = 0.0;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	SpecialRelativity(const SpecialRelativity& t)
	{
		_specialRelativityPtr = t._specialRelativityPtr;
		specialRelativityVar = t.specialRelativityVar;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	SpecialRelativity(SpecialRelativity&& t) noexcept
	{
		_specialRelativityPtr = t._specialRelativityPtr;
		specialRelativityVar = t.specialRelativityVar;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	SpecialRelativity& operator=(const SpecialRelativity& t)
	{
		if (this != &t)
		{
			_specialRelativityPtr = t._specialRelativityPtr;
			specialRelativityVar = t.specialRelativityVar;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\n ________ object count: "
							<< specialRelativity_objectCount << std::endl; }
	static int get_objectCount() { return specialRelativity_objectCount; }


	~SpecialRelativity()
	{
		delete _specialRelativityPtr;
	}
	void setTemplateVar(ld var) { specialRelativityVar = var; }
	ld getTemplateVar() const { return specialRelativityVar; }

private:
	ld specialRelativityVar;
	static void countIncrease() { specialRelativity_objectCount += 1; }
	static void countDecrease() { specialRelativity_objectCount -= 1; }

};
#endif

