/**
 * @class TemplateClass
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  3/18/2021
 * @lastEdit 3/21/2021
 */

#ifndef TEMPLATE_CLASS_H
#define TEMPLATE_CLASS_H
#include <iostream>


static int _objectCount = 0;
typedef long double ld;

class TemplateClass
{

public:
	TemplateClass* _template;

	TemplateClass()
	{
		_template = nullptr;
		templateVar = 0.0;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	TemplateClass(const TemplateClass& t)
	{
		_template = t._template;
		templateVar = t.templateVar;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	TemplateClass(TemplateClass&& t) noexcept
	{
		_template = t._template;
		templateVar = t.templateVar;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	TemplateClass& operator=(TemplateClass&& t) noexcept
	{
		if (this != &t)
		{
			_template = t._template;
			templateVar = t.templateVar;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\n ________ object count: "
							<< _objectCount << std::endl; }
	static int get_objectCount() { return _objectCount; }


	~TemplateClass()
	{
		delete _template;
	}
	void setTemplateVar(ld var) { templateVar = var; }
	ld getTemplateVar() const { return templateVar; }

private:
	ld templateVar;
	static void countIncrease() { _objectCount += 1; }
	static void countDecrease() { _objectCount -= 1; }
};
#endif

