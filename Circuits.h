/**
 * @class Circuits
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  3/3/2021
 * @lastEdit 3/3/2021
 */

#ifndef CIRCUITS_H
#define CIRCUITS_H
#include <iostream>


static int circuits_objectCount = 0;


class Circuits
{
private:
	static void countIncrease() { circuits_objectCount += 1; }
	static void countDecrease() { circuits_objectCount -= 1; }
public:
	Circuits* _circuitPtr;

	Circuits()
	{
		_circuitPtr = nullptr;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	Circuits(const Circuits& c)
	{
		_circuitPtr = c._circuitPtr;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	Circuits(Circuits&& c) noexcept
	{
		_circuitPtr = c._circuitPtr;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	Circuits& operator=(const Circuits& c)
	{
		if (this != &c)
		{
			_circuitPtr = c._circuitPtr;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\n ________ object count: "
										<< circuits_objectCount << std::endl; }
	static int get_objectCount() { return circuits_objectCount; }


	~Circuits()
	{
		delete _circuitPtr;
	}

};
#endif

