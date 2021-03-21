/**
 * @class TemplateClass
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  3/18/2021
 * @lastEdit 3/21/2021
 */

#ifndef TEMPLATECLASS_H
#define TEMPLATECLASS_H
#include <iostream>


static int _objectCount = 0;
typedef long double ld;

class TemplateClass
{
private:
	static void countIncrease() { _objectCount += 1; }
	static void countDecrease() { _objectCount -= 1; }
public:
	TemplateClass* _template;
	ld _var;

	TemplateClass()
	{
		_template = nullptr;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	TemplateClass(const TemplateClass& t)
	{
		_template = t._template;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	TemplateClass(TemplateClass&& t) noexcept
	{
		_template = t._template;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	TemplateClass& operator=(const TemplateClass& t)
	{
		if (this != &t)
		{
			_template = t._template;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\n ________ object count: " << _objectCount << std::endl; }
	static int get_objectCount() { return _objectCount; }


	~TemplateClass()
	{
		delete _template;
	}

};
#endif

