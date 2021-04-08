#pragma once
#include "ElectromagneticWaves.h"

#ifndef GEOMETRICOPTICS_H
#define GEOMETRICOPTICS_H
#include <iostream>


static int geometricOptics_objectCount = 0;


class GeometricOptics :
	public ElectromagneticWaves
{


public:
	GeometricOptics* _geoOpticPtr;

	GeometricOptics()
	{
		_geoOpticPtr = nullptr;
		geometricOpticsVar = 0.0;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	GeometricOptics(const GeometricOptics& t)
	{
		_geoOpticPtr = t._geoOpticPtr;
		geometricOpticsVar = t.getGeometricOpticsVar();
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	GeometricOptics(GeometricOptics&& t) noexcept
	{
		_geoOpticPtr = t._geoOpticPtr;
		geometricOpticsVar = t.getGeometricOpticsVar();
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	GeometricOptics& operator=(const GeometricOptics& t)
	{
		if (this != &t)
		{
			_geoOpticPtr = t._geoOpticPtr;
			geometricOpticsVar = t.getGeometricOpticsVar();
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout
					<< "\n geometric optics object count: "
					<< geometricOptics_objectCount << std::endl; }
	static int get_objectCount() { return geometricOptics_objectCount; }


	~GeometricOptics()
	{
		delete _geoOpticPtr;
	}

	void setGeometricOpticsVar(ld var) { geometricOpticsVar = var; }
	ld getGeometricOpticsVar() const { return geometricOpticsVar; }



private:
	ld geometricOpticsVar;
	static void countIncrease() { geometricOptics_objectCount += 1; }
	static void countDecrease() { geometricOptics_objectCount -= 1; }

};

#endif
