#pragma once
/**
 * @class ElectricCharge
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  12/31/2020
 * @lastEdit 2/8/2021
 */

#ifndef ELECTRICCHARGE_H
#define ELECTRICCHARGE_H
#include <iostream>

#include "Heat.h"

const ld _k_ = 8.988 * pow(10.0, 9);// 8.988 * pow(10.0, 9)Nm^2)/C^2
const ld _ELECTRON_ = -1.6 * pow(10.0, -19);
const ld _PROTON_ = 1.6 * pow(10.0, -19);
const ld _COULOMB_ = 1.0 / _ELECTRON_;

static int electricCharge_objectCount = 0;

static struct ScientificNotationUnits
{
	const ld yotta = pow(10, 24);//10^24
	const ld zetta = pow(10, 21);//10^21
	const ld exa = pow(10, 18);//10^18
	const ld peta = pow(10, 15);//10^15
	const ld tera = pow(10, 12);//10^12
	const ld giga = pow(10, 9);//10^9
	const ld mega = pow(10, 6);//10^6
	const ld kilo = pow(10, 3);//10^3
	const ld hecto = pow(10, 2);//10^2
	const ld deca = pow(10, 1);//10^1
	const ld deci = pow(10, -1);//10^-1
	const ld centi = pow(10, -2);//10^-2
	const ld milla = pow(10, -1);//10^-3
	const ld micro = pow(10, -6);//10^-6
	const ld nano = pow(10, -9);//10^-9
	const ld pico = pow(10, -12);//10^-12
	const ld femto = pow(10, -15);//10^-15
	const ld atto = pow(10, -18);//10^-18
	const ld zepto = pow(10, -21);//10^-21
	const ld yocto = pow(10, -24);//10^-24
	//const ld operator*(ld ld, const ScientificNotationUnits& su);

}SU;

static struct Atom
{
	ld electron = _ELECTRON_;
	ld proton = _PROTON_;
	ld neutron = 0.0;
}atom;


class ElectricCharge
{
private:
	static void countIncrease() { electricCharge_objectCount += 1; }
	static void countDecrease() { electricCharge_objectCount -= 1; }
public:
	ElectricCharge* _electricChargePtr;

	ElectricCharge()
	{
		_electricChargePtr = nullptr;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	ElectricCharge(const ElectricCharge& t)
	{
		_electricChargePtr = t._electricChargePtr;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	ElectricCharge(ElectricCharge&& t) noexcept
	{
		_electricChargePtr = t._electricChargePtr;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	ElectricCharge& operator=(const ElectricCharge& t)
	{
		if (this != &t)
		{
			_electricChargePtr = t._electricChargePtr;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\n electric charge object count: " << electricCharge_objectCount << std::endl; }
	static int get_objectCount() { return electricCharge_objectCount; }

	/// <summary>
	/// Crates mass from energy.
	/// </summary>
	/// <param name="E">The energy.</param>
	/// <param name="c">The c.</param>
	/// <returns>energy</returns>
	static ld massFromEnergy(const ld E, const ld c);
	/// <summary>
	/// Masses from energy.
	/// </summary>
	/// <param name="M">The electrons mass.</param>
	/// <returns>energy</returns>
	static ld massFromEnergy(const ld M);

	/// <summary>
	/// Calculates the magnitude between two electrostatic forces q1 and q2
	/// </summary>
	/// <param name="q1">The q1.</param>
	/// <param name="q2">The q2.</param>
	/// <param name="r">The r.</param>
	/// <returns></returns>
	static ld electrostaticForce(const ld q1, const ld q2, const ld r);

	/// <summary>
	/// Charges the of electrostatic force equal point charges.
	/// </summary>
	/// <param name="q">The q.</param>
	/// <param name="mass">The mass.</param>
	/// <param name="r">The r.</param>
	/// <returns></returns>
	static ld chargeOfElectrostaticForce_equalPointCharges(const ld q, const ld mass, const ld r);

	/// <summary>
	/// Electrics the field e.
	/// </summary>
	/// <param name="Q">The q.</param>
	/// <param name="r">The r.</param>
	/// <returns></returns>
	static ld electricFieldForce(const ld Q, const ld r);

	/// <summary>
	/// Forces the by electric field.
	/// </summary>
	/// <param name="q">The q.</param>
	/// <param name="E">The e.</param>
	/// <returns></returns>
	static ld forceByElectricField(const ld q, const ld E);

	/// <summary>
	///  Calculates the  electrons needed to form a charge of baseNumber to the
	///  su power.
	/// </summary>
	/// <param name="baseNumber">The base number.</param>
	/// <param name="su">The scientific notation multiple.</param>
	/// <returns>number of electrons</returns>
	static ld electrons(const ld baseNumber, const ld su);

	/// <summary>
	/// Electrons the count.
	/// </summary>
	/// <param name="protons">The protons.</param>
	/// <param name="netCharge">The net charge.</param>
	/// <returns></returns>
	static ld netElectronCount(const ld protons, const ld netCharge);

	/// <summary>
	/// Coulombs the specified base number.
	/// </summary>
	/// <param name="baseNumber">The base number.</param>
	/// <param name="su">The su.</param>
	/// <returns></returns>
	static ld coulombs(const ld baseNumber, const ld su);

	/// <summary>
	/// Hows the many fewer electrons then protons.
	/// </summary>
	/// <param name="netCharge">The net charge.</param>
	/// <returns></returns>
	static ld howManyFewerElectronsThenProtons(const ld netCharge);

	/// <summary>
	/// Fractions the protons no electrons.
	/// </summary>
	/// <param name="protons">The protons.</param>
	/// <param name="netCharge">The net charge.</param>
	/// <returns></returns>
	static ld fractionProtonsNoElectrons(const ld protons, const ld netCharge);

	/// <summary>
	/// Forces the change two point charges.
	/// </summary>
	/// <param name="F">The f.</param>
	/// <param name="factorChange">The factor change.</param>
	/// <returns></returns>
	static ld forceChangeTwoPointCharges(const ld F, const ld factorChange);

	/// <summary>
	/// Electrics the field.
	/// </summary>
	/// <param name="F">The force.</param>
	/// <param name="q">The charge.</param>
	/// <returns></returns>
	static ld electricField(const ld F, const ld q);

	/// <summary>
	/// Calculates the magnitude of a point charge that creates a electric field
	/// force of F,  at a distance of r meters.
	/// </summary>
	/// <param name="F">The force.</param>
	/// <param name="r">The distance.</param>
	/// <returns>point charge (C)</returns>
	static ld magnitudePointCharge(const ld F, const ld r);


	~ElectricCharge()
	{
		delete _electricChargePtr;
	}

};
#endif

inline ld ElectricCharge::massFromEnergy(const ld E, const ld c)
{
	return E/(c*c);
}

inline ld ElectricCharge::massFromEnergy(const ld M)
{
	return 2.0*M;
}

inline ld ElectricCharge::electrostaticForce(const ld q1, const ld q2, const ld r)
{
	return _k_*((abs(q1*q2))/(r*r));
}

inline ld ElectricCharge::chargeOfElectrostaticForce_equalPointCharges(const ld q, const ld mass, const ld r)
{
	return r*(sqrt((mass*_Ga_)/_k_));
}

inline ld ElectricCharge::electricFieldForce(const ld Q, const ld r)
{
	return _k_*(abs(Q)/(r*r));
}

inline ld ElectricCharge::forceByElectricField(const ld q, const ld E)
{
	return -q * E;
}

inline ld ElectricCharge::coulombs(const ld baseNumber, const ld su)
{
	return baseNumber * su * _PROTON_;
}

inline ld ElectricCharge::howManyFewerElectronsThenProtons(const ld netCharge)
{
	return netCharge/abs(_ELECTRON_);
}

inline ld ElectricCharge::fractionProtonsNoElectrons(const ld protons, const ld netCharge)
{
	const ld temp = howManyFewerElectronsThenProtons(netCharge);
	return temp/protons;
}

inline ld ElectricCharge::forceChangeTwoPointCharges(const ld F, const ld factorChange)
{
	return F/(factorChange*factorChange);
}

inline ld ElectricCharge::electricField(const ld F, const ld q)
{
	return F/q;
}

inline ld ElectricCharge::magnitudePointCharge(const ld F, const ld r)
{
	return ((r*r)*F)/_k_;
}

inline ld ElectricCharge::electrons(const ld baseNumber, const ld su)
{
	return (baseNumber * su) / _ELECTRON_;
}

inline ld ElectricCharge::netElectronCount(const ld protons, const ld netCharge)
{
	return protons + ((-abs(netCharge))/_PROTON_);
}

