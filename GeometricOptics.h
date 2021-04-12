#pragma once
#include <map>

#include "ElectromagneticWaves.h"

#ifndef GEOMETRICOPTICS_H
#define GEOMETRICOPTICS_H
#include <iostream>


static int geometricOptics_objectCount = 0;

static struct RefractionIndexes
{
	//gases at 0 C, 1 atm
	const ld AIR = 1.000293;
	const ld CARBON_DIOXIDE = 1.00045;
	const ld HYDROGEN = 1.000139;
	const ld OXYGEN = 1.000271;
	//Liquids at 20 C
	const ld BENZENE = 1.501;
	const ld CARBON_DISULFIDE = 1.628;
	const ld CARBON_TETRACHLORIDE = 1.461;
	const ld ETHANOL = 1.361;
	const ld GLYCERINE = 1.473;
	const ld WATER_FRESH = 1.333;
	//Solids at 20 C
	const ld DIAMOND = 2.419;
	const ld FLUORITE = 1.434;
	const ld GLASS_CROWN = 1.52;
	const ld GLASS_FLINT = 1.66;
	const ld ICE = 1.309;
	const ld POLYSTYRENE = 1.49;
	const ld PLEXIGLAS = 1.51;
	const ld QUARTZ_CRYSTALLINE = 1.544;
	const ld QUARTZ_FUSED = 1.458;
	const ld SODIUM_CHLORIDE = 1.544;
	const ld ZIRCON = 1.923;

}refraction;


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

	/// <summary>
	/// Calculates the index of refraction (n) where v is the observed speed of
	/// light in the material.
	/// </summary>
	/// <param name="v">The observed speed of light in a material.</param>
	/// <returns>the index of refraction (n) is unit less</returns>
	static ld indexOfRefraction(const ld v);

	/// <summary>
	/// Calculates the speeds of the light from a know refraction index of n
	/// </summary>
	/// <param name="n">The refraction index.</param>
	/// <returns>the speed of the light through a substance or material</returns>
	static ld speedOfLightFromRefractionIndex(const ld n);

	/// <summary>
	/// calculates the index of refraction medium 2.
	/// </summary>
	/// <param name="n1">The index of refraction from the incident ray.</param>
	/// <param name="incidentAng1">The incident ray angle.</param>
	/// <param name="angRefraction2">The angle of the refracted ray.</param>
	/// <returns>index of refraction for medium 2</returns>
	static ld indexOfRefractionMedium2(const ld n1, const ld incidentAng1, const ld angRefraction2);

	/// <summary>
	/// Calculates the angle of refraction.
	/// </summary>
	/// <param name="n1">The index of refraction from the incident ray.</param>
	/// <param name="n2">The index of refraction from refracted ray.</param>
	/// <param name="incidentAng1">The incident angle.</param>
	/// <returns>the angle of refraction</returns>
	static ld angleOfRefraction(const ld n1, const ld n2, const ld incidentAng1);

	/// <summary>
	/// Calculates the incident angle.
	/// </summary>
	/// <param name="n1">The index of refraction from the incident ray.</param>
	/// <param name="n2">The index of refraction from refracted ray.</param>
	/// <param name="angRefraction2">The angle of refraction.</param>
	/// <returns>the incident angle</returns>
	static ld incidentAngle(const ld n1, const ld n2, const ld angRefraction2);

	/// <summary>
	/// Calculates the critical angle for conditions {n1 > n2}
	/// </summary>
	/// <param name="n1">The n1.</param>
	/// <param name="n2">The n2.</param>
	/// <returns>the critical angle</returns>
	static ld criticalAngle(const ld n1, const ld n2);

	static map<string, ld> heightOfMirror(const ld floorToEyes, const ld eyesToTopHead);




private:
	ld geometricOpticsVar;
	static void countIncrease() { geometricOptics_objectCount += 1; }
	static void countDecrease() { geometricOptics_objectCount -= 1; }

};

#endif
//=============================================================================
//in-line class Implementation

inline ld GeometricOptics::indexOfRefraction(const ld v)
{
	return _c_ / v;
}

inline ld GeometricOptics::speedOfLightFromRefractionIndex(const ld n)
{
	return _c_ / n;
}

inline ld GeometricOptics::indexOfRefractionMedium2(const ld n1, const ld incidentAng1, const ld angRefraction2)
{
	return n1*(sin(incidentAng1*RADIAN)/sin(angRefraction2*RADIAN));
}

inline ld GeometricOptics::angleOfRefraction(const ld n1, const ld n2, const ld incidentAng1)
{
	ld temp = (n1 / n2) * sin(incidentAng1*RADIAN);
	return asin(temp)*DEGREE;
}

inline ld GeometricOptics::incidentAngle(const ld n1, const ld n2, const ld angRefraction2)
{
	ld temp = (n2 / n1) * sin(angRefraction2 * RADIAN);
	return asin(temp) * DEGREE;
}

inline ld GeometricOptics::criticalAngle(const ld n1, const ld n2)
{
	return asin(n2/n1)*DEGREE;
}

inline map<string, ld> GeometricOptics::heightOfMirror(const ld floorToEyes, const ld eyesToTopHead)
{
	map<string, ld> result;
	result["floor to bottom of mirror"] = floorToEyes / 2.0;//height from floor to bottom of mirror

	result["1/2 from eyes to top of head"] =  eyesToTopHead / 2.0;

	result["height of person"] = floorToEyes + eyesToTopHead;

	result["length of mirror"] = result.at("height of person") -
		result.at("floor to bottom of mirror") -
		result.at("1/2 from eyes to top of head");
	result["floor to top of mirror"] = result.at("floor to bottom of mirror") +
		result.at("length of mirror");

	return result;
}
