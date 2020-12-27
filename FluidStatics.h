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
	* @brief calculates the volume of a sphere
	* @param r radius
	*/
	ld sphere(const ld r) const
	{
		return (4 / 3) * _PI * pow(r, 3.0);
	}
	/**
	* @brief calculates the volume of a cone
	* @param r radius
	* @param h height
	*/
	ld cone(const ld r, const ld h)const
	{
		return (1 / 3) * _PI * pow(r, 2.0) * h;
	}
	/**
	* @brief calculates the volume of a cube
	* @param edgeL edge length
	*/
	ld cube(const ld edgeL)const
	{
		return pow(edgeL, 3);
	}
	/**
	* @brief calculates the volume of a cylinder
	* @param r radius
	* @param h height
	*/
	ld cylinder(const ld r, const ld h)const
	{
		return _PI * r * 2 * h;
	}
	/**
	* @brief calculates the volume of rectangular tank
	* @param l length
	* @param w width
	* @param h height
	*/
	ld rectangularTank(const ld l, const ld w, const ld h)const
	{
		return l * w * h;
	}

	/**
	* @brief calculates the volume of capsule
	* @param r radius
	* @param h height
	* returns volume m^3
	*/
	ld capsule(const ld r, const ld h)const
	{
		return (_PI * pow(r, 2)) * ((4 / 3) * r + h);
	}

	/**
	* @brief calculates the volume of spherical cap (button-like)
	* @param r radius
	* @param h height
	* returns volume m^3
	*/
	ld sphericalCap(const ld r, const ld h)const
	{
		return ((1 / 3) * _PI * pow(h, 2.0)) * (3 * r - h);
	}

}v;

static struct PressureConversions
{
	ld atm_to_Pa(const ld atm)const
	{
		return atm * 1.013 * pow(10, 5);// Pa = N/m^2
	}

	ld dynePer_cmSquared_to_Pa(const ld d)const
	{
		return d * .10;// Pa = N/m^2
	}
	ld Pa_to_dynePer_cmSquared(const ld Pa)const
	{
		return Pa / .10;// dyne/cm^2
	}
	ld kgPer_cmSquared_to_Pa(const ld kg)const
	{
		return kg * 9.8 * pow(10, 4);// N/m^2
	}
	ld Pa_to_kgPer_cmSquared(const ld Pa)const
	{
		return Pa / 9.8 * pow(10, 4);// kg/cm^2
	}
	ld lbPer_inSquared_to_Pa(const ld atm)const
	{
		return atm * 1.013 * pow(10, 5);// N/m^2
	}
	ld Pa_to_lbPer_inSquared(const ld Pa)const
	{
		return Pa / 1.013 * pow(10, 5);// lb/in^2
	}
	ld mmHg_to_Pa(const ld mm)const
	{
		return mm * 133.3224;// N/m^2
	}
	ld Pa_to_mmHg(const ld Pa)const
	{
		return Pa / 133.3224;// mm Hg
	}
	ld cmHg_to_Pa(const ld cm)const
	{
		return cm * 1.33 * pow(10, 3);// N/m^2
	}
	ld Pa_to_cmHg(const ld Pa)const
	{
		return Pa / 1.33 * pow(10, 3);// cm Hg
	}
	ld cmWater_to_Pa(const ld w)const
	{
		return w * 98.1;// N/m^2
	}
	ld Pa_to_cmWater(const ld Pa)const
	{
		return Pa / 98.1;// cm water
	}
	ld bar_to_Pa(const ld bar)const
	{
		return bar * 1.000 * pow(10, 5);// N/m^2
	}
	ld Pa_to_bar(const ld Pa)const
	{
		return Pa / 1.000 * pow(10, 5);// bar
	}
	ld millibar_to_Pa(const ld cm)const
	{
		return cm * 1.000 * pow(10, 2);// Pa = N/m^2
	}
	ld Pa_to_millibar(const ld Pa)const
	{
		return Pa / 1.000 * pow(10, 2);// millibar
	}
	ld atm_to_dyneCmSquared(const ld atm)const
	{
		return atm * 1.013 * pow(10, 6);// dyne/cm^2
	}
	ld dyneCmSquared_to_atm(const ld n)const
	{
		return n / 1.013 * pow(10, 6);// atm
	}
	ld atm_to_kgCmSquared(const ld atm)const
	{
		return atm * 1.013;// kg/cm^2
	}
	ld kgCmSquared_to_atm(const ld n)const
	{
		return n / 1.013;// atm
	}
	ld atm_to_lbsPerInchSquared(const ld atm)const
	{
		return atm * 14.7;// lb/in^2
	}
	ld lbsPerInchSquared_to_atm(const ld n)const
	{
		return n / 14.7;// atm
	}
	ld atm_to_mmHg(const ld atm)const
	{
		return atm * 760.0;// mm Hg
	}
	ld mmHg_to_atm(const ld n)const
	{
		return n / 760.0;// atm
	}
	ld atm_to_cmHg(const ld atm)const
	{
		return atm * 76.0;// cm Hg
	}
	ld cmHg_to_atm(const ld n)const
	{
		return n / 76.0;// atm
	}
	ld atm_to_cmWater(const ld atm)const
	{
		return atm * 1.03 * pow(10, 3);// cm water
	}
	ld cmWater_to_atm(const ld n)const
	{
		return n / 1.03 * pow(10, 3);// atm
	}
	ld atm_to_bar(const ld atm)const
	{
		return atm * 1.013;// bar
	}
	ld bar_to_atm(const ld n)const
	{
		return n / 1.013;// atm
	}
	ld atm_to_millibar(const ld atm)const
	{
		return atm * 1013;// millibar
	}
	ld millibar_to_atm(const ld n)const
	{
		return n / 1013;// atm
	}
}converter_pressures;

/**
* @brief circumference to radius
*/
static ld radiusFromCircumference(const ld c)
{
	return c / (2 * _PI);
}
/**
* @brief diameter to radius
*/
static ld radiusFromDiameter(const ld d){
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
	* @brief calculates density
	* p = m / v
	* @param m mass kg
	* @param v volume in m^3
	*/
	static ld density(const ld m, const ld v) {
		return m / v;
	}

	/// <summary>
	/// Densities the parts by mass.
	/// </summary>
	/// <param name="partsA">The parts of substance A.</param>
	/// <param name="pA">The density of substance A.</param>
	/// <param name="partsB">The parts of substance B.</param>
	/// <param name="pB">The density of substance B.</param>
	/// <param name="partsC">The parts of substance dC</param>
	/// <param name="pC">The density of substance C.</param>
	/// <returns></returns>
	static ld density_partsByMass(const ld partsA, const ld pA, const ld partsB, const ld pB, const ld partsC, const ld pC)
	{
		return (partsA + partsB + partsC) / ((partsA / pA) + (partsB / pB) + (partsC / pC));
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
	* @param p density
	* @param v volume in m^3
	*/
	static ld mass(const ld p, const ld v) {
		return p * v;
	}

	/**
	* @brief calculate the pressure
	* @param F is the force
	* @param A is the area perpendicular to force
	*/
	static ld pressure(const ld F, const ld A) {
		return F / A;
	}

	/**
	 * @brief calculates the pressure on bottom of tank
	 * using P = F / A, F = ma and A = l*w
	 * @param m the mass
	 * @param l the length
	 * @param w the width
	 * @returns the pressure on bottom of tank
	 */
	static ld pressure(const ld m, const ld l, const ld w)
	{
		return (m * _Ga_) / (l * w);
	}

	/**
	 * @brief calculates the average pressure.
	 * @param p the density
	 * @param l the length
	 * @param h the height
	 * @return the average pressure
	 */
	static ld pressureAvg(const ld p, const ld l, const ld h)
	{
		return ((p * _Ga_ * h) / 2.0) * (l * h);
	}

	/// <summary>
	/// Force caused by a pressure.
	/// </summary>
	/// <param name="P">The pressure</param>
	/// <param name="a">the area</param>
	/// <returns>force</returns>
	static ld force(const ld P, const ld a) {
		return P * a;
	}

	/// <summary>
	/// Force needed by the master hydraulic to support weight on the slave.
	/// </summary>
	/// <param name="m">The mass.</param>
	/// <param name="dM">The diameter master.</param>
	/// <param name="dS">The diameter slave s.</param>
	/// <returns>Force master cylinder</returns>
	static ld forceMaster_hydraulicSystemPascal(const ld m, const ld dM, const ld dS)
	{
		return (m * _Ga_ * (dM * dM)) / (dS * dS);
	}

	/// <summary>
	/// Force2 using pascals principles.
	/// </summary>
	/// <param name="F1">Force 1.</param>
	/// <param name="a1">The area 1.</param>
	/// <param name="a2">The area 2.</param>
	/// <returns>Force 2 in newtons</returns>
	static ld force2pascalPrinciples(const ld F1, const ld a1, const ld a2)
	{
		return F1 * (a2 / a1);
	}


	/// <summary>
	/// Radius of a cylinder.
	/// </summary>
	/// <param name="m">The mass.</param>
	/// <param name="h">The height.</param>
	/// <param name="_p">The density.</param>
	/// <returns>the radius</returns>
	static ld radiusCylinder(const ld m, const ld h, const ld _p)
	{
		return sqrt((m * _p) / (_PI * h));
	}


	 /// <summary>
	 /// Depth of a rectangular tank.
	 /// </summary>
	 /// <param name="m">The mass.</param>
	 /// <param name="_p">The density.</param>
	 /// <param name="l">The length.</param>
	 /// <param name="w">The width.</param>
	 /// <returns></returns>
	static ld depthRectangularTank(const ld m, const ld _p, const ld l, const ld w)
	{
		return m / (_p * l * w);
	}


	/// <summary>
	/// Ratios the of density.
	/// </summary>
	/// <param name="percentDecrease">The percent decrease.</param>
	/// <returns></returns>
	static ld ratioOfDensity(const ld percentDecrease)
	{
		return 1.0 / percentDecrease;
	}


	/// <summary>
	/// Radius of a sphere with a known mass and density
	/// </summary>
	/// <param name="m">The mass.</param>
	/// <param name="p">The density.</param>
	/// <returns>radius</returns>
	static ld radiusOfSphere(const ld m, const ld p)
	{
		return pow((3.0 * m) / (4.0 * _PI * p),1/3);
	}

	/**
	 * @brief calculates the height from known pressure and density
	 * (think mercury in a tube)
	 * @param P the pressure
	 * @param _p the density
	 * @return the height of a fluid
	 */
	static ld heightOfFluid(const ld P, const ld _p)
	{
		return P / (_p * _Ga_);
	}

	/**
	 * @brief calculates the Gage pressure
	 *
	 */
	static ld pressureGauge(const ld p, const ld h)
	{
		return p * _Ga_ * h;
	}



	/**
	* @brief destructor
	*/
	~FluidStatics()
	{
		delete _fluidStaticPtr;
		countDecrease();
	}
};

#endif
