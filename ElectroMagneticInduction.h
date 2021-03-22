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


	/// <summary>
	/// Calculates the magnetic flux where B is the magnetic field strength(T)
	/// over an area of A (m^2), at an angle theta with the perpendicular to
	/// the area. Any change in the magnetic flux induces an emf. This process
	/// is defined to be electromagnetic induction.
	/// </summary>
	/// <param name="B">The magnetic field strength(T).</param>
	/// <param name="A">The area(m^2).</param>
	/// <param name="theta">The angle theta default is at 0 degrees which
	/// is equal to 1 making the equation flux = B*A.</param>
	/// <returns>the magnetic flux (T*m^2)</returns>
	static ld magneticFlux(const ld B, const ld A, const ld theta);

	/// <summary>
	/// Calculates the EMF induced by magnetic flux over t time having N turns
	/// </summary>
	/// <param name="N">The amount of turns in coil.</param>
	/// <param name="flux">The flux.</param>
	/// <param name="t">The time.</param>
	/// <returns>emf = volts(V)</returns>
	static ld emf_inducedByMagneticFlux(const ld N, const ld flux, const ld t);

	/// <summary>
	/// number of turns in a coil from EMF and time t over the flux;
	/// </summary>
	/// <param name="t">The time.</param>
	/// <param name="emf">The EMF.</param>
	/// <param name="flux">The flux.</param>
	/// <returns>turns in a coil</returns>
	static ld n_turnsInCoilFromEMFEquation(const ld t, const ld emf, const ld flux);

	/// <summary>
	/// calculates the fluxes from EMF equation, with a time of t and N turns in
	/// a coil
	/// </summary>
	/// <param name="emf">The EMF.</param>
	/// <param name="t">The time.</param>
	/// <param name="N">The number of turns in a coil.</param>
	/// <returns>magnetic flux(T*m^2)</returns>
	static ld flux_fromEMFEquation(const ld emf, const ld t, const ld N);

	/// <summary>
	/// calculates the times from EMF equation with a flux and emf with N turns
	/// of a coil.
	/// </summary>
	/// <param name="N">The number of turns of a coil</param>
	/// <param name="flux">The flux.</param>
	/// <param name="emf">The EMF.</param>
	/// <returns>time in seconds</returns>
	static ld time_fromEMFEquation(const ld N, const ld flux, const ld emf);




	






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

inline ld ElectroMagneticInduction::magneticFlux(const ld B, const ld A, const ld theta = 0)
{
	return B * A * cos(theta * RADIAN);//T*m^2 = Tesla meters squared
}

inline ld ElectroMagneticInduction::emf_inducedByMagneticFlux(const ld N, const ld flux, const ld t)
{
	return -N * (flux / t);
}

inline ld ElectroMagneticInduction::n_turnsInCoilFromEMFEquation(const ld t, const ld emf, const ld flux)
{
	return (t / flux) * emf;//turns in coil
}

inline ld ElectroMagneticInduction::flux_fromEMFEquation(const ld emf, const ld t, const ld N)
{
	return -(t * emf) / N;//T*m^2
}

inline ld ElectroMagneticInduction::time_fromEMFEquation(const ld N, const ld flux, const ld emf)
{
	return N * (flux / emf);//seconds
}
