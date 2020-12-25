#pragma once
/**
 * @class FluidStatics
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   10/15/2020
 */
#ifndef FLUIDSTATICS_H
#define FLUIDSTATICS_H
#include <iostream>
typedef long double ld;
static int fluidStatics_objectCount = 0;

static struct Volumes
{
	/**
	* @brief calculates the volume of a shpere
	* @param r radius
	*/
	const ld sphere(const ld r) {
		return (4 / 3) * _PI * pow(r, 3.0);
	}
	/**
	* @brief calculates the volume of a cone
	* @param r radius
	* @param h height
	*/
	const ld cone(const ld r, const ld h) {
		return (1 / 3) * _PI * pow(r, 2.0) * h;
	}
	/**
	* @brief calculates the volume of a cube
	* @param edgeL edge length 
	*/
	const ld cube(const ld edgeL) {
		return pow(edgeL, 3);
	}
	/**
	* @brief caluculates the volume of a cylinder
	* @param r radius
	* @param h height
	*/
	const ld cylinder(const ld r, const ld h) {
		return _PI * r * 2 * h;
	}
	/**
	* @brief calculates the volume of rectangular tank
	* @param l length 
	* @param w width
	* @param h height
	*/
	const ld rectangularTank(const ld l, const ld w, const ld h) {
		return l * w * h;
	}

	/**
	* @brief calculates the volume of capsule
	* @param r radius
	* @param h height 
	* returns volume m^3
	*/
	const ld capsule(const ld r, const ld h) {
		return (_PI * pow(r, 2)) * ((4 / 3) * r + h);
	}

	/**
	* @brief calculates the volume of spherical cap (button-like)
	* @param r radius
	* @param h height
	* returns volume m^3
	*/
	const ld sphericalCap(const ld r, const ld h) {
		return ((1 / 3) * _PI * pow(h, 2.0)) * (3 * r - h);
	}

}v;

/**
* @brief circumfrence to radius
*/
static ld radiusFromCircumfrence(const ld c) {
	return c / (2 * _PI);
}
/**
* @brief diameter to radius
*/
static ld radiusFromCircumfrence(const ld d){
	return d/2;
}

class FluidStatics
{
private:
	static void countIncrease() { fluidStatics_objectCount += 1; }
	static void countDecrease() { fluidStatics_objectCount -= 1; }
public:
	FluidStatics* _fluidStaticPtr;
	

	FluidStatics()
	{
		_fluidStaticPtr = nullptr;
		countIncrease();
	}

	/**
 * @brief copy constructor
 */
	FluidStatics(const FluidStatics& t)
	{
		_fluidStaticPtr = t._fluidStaticPtr;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	FluidStatics(FluidStatics&& t) noexcept
	{
		_fluidStaticPtr = t._fluidStaticPtr;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	FluidStatics& operator=(const FluidStatics& t)
	{
		if (this != &t)
		{
			_fluidStaticPtr = t._fluidStaticPtr;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\nfluid statics object count: " << fluidStatics_objectCount << std::endl; }
	static int get_objectCount() { return fluidStatics_objectCount; }

	/**
	*@brief calculates density
	* p = m * v
	* @param m mass kg
	* @param V volume in m^3
	*/
	static ld density(const ld m, const ld v) {
		return m / v;
	}

	/**
	*@brief calculates volume
	* v = m / p
	* @param m mass kg
	* @param p volume in m^3
	*/
	static ld volume(const ld m, const ld p) {
		return m / p;
	}

	/**
	*@brief calculates mass
	* m = p * v
	* @param p mass kg
	* @param v volume in m^3
	*/
	static ld mass(const ld p, const ld v) {
		return p * v;
	}

	/**
	* @brief calculates force of air on flat end of tank
	*/
	static ld force(const ld p, const ld A) {
		return p * A;
	}






	~FluidStatics()
	{
		delete _fluidStaticPtr;
		countDecrease();
	}
};

#endif
