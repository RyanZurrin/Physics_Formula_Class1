#pragma once

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
#include "ElectricCurrent.h"


static int circuits_objectCount = 0;

class Circuits:
	public ElectricCurrent
{

public:
	Circuits* _circuitPtr;


	Circuits()
	{
		_circuitPtr = nullptr;
		_circuitVal = 0.0;
		countIncrease();
	}
	Circuits(ld val)
	{
		_circuitPtr = nullptr;
		_circuitVal = val;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	Circuits(const Circuits& c)
	{
		_circuitPtr = c._circuitPtr;
		_circuitVal = 0.0;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	Circuits(Circuits&& c) noexcept
	{
		_circuitPtr = c._circuitPtr;
		_circuitVal = c._circuitVal;
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
			_circuitVal = c._circuitVal;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\n circuits object count: "
										<< circuits_objectCount << std::endl; }
	static int get_objectCount() { return circuits_objectCount; }

	void setCircuitVal(ld val) { _circuitVal = val; }


	/// <summary>
	/// Calculates the total resistance of a Series of   resistors.
	/// </summary>
	/// <param name="R1">The resistor 1.</param>
	/// <param name="R2">The resistor 2.</param>
	/// <param name="R3">The resistor 3.</param>
	/// <param name="R4">The resistor 4.</param>
	/// <param name="R5">The resistor 5.</param>
	/// <param name="R6">The resistor 6.</param>
	/// <param name="R7">The resistor 7.</param>
	/// <param name="R8">The resistor 8.</param>
	/// <param name="R9">The resistor 9.</param>
	/// <param name="R10">The resistor 10.</param>
	/// <returns>resistance in ohms</returns>
	static ld seriesResistance(const ld R1, const ld R2, const ld R3, const ld R4,
		const ld R5, const ld R6, const ld R7, const ld R8, const ld R9, const ld R10);

	/// <summary>
	/// Calculates the total resistance of resistors hooked up in parallel.
	/// </summary>
	/// <param name="R1">The resistor 1.</param>
	/// <param name="R2">The resistor 2.</param>
	/// <param name="R3">The resistor 3.</param>
	/// <param name="R4">The resistor 4.</param>
	/// <param name="R5">The resistor 5.</param>
	/// <param name="R6">The resistor 6.</param>
	/// <param name="R7">The resistor 7.</param>
	/// <param name="R8">The resistor 8.</param>
	/// <param name="R9">The resistor 9.</param>
	/// <param name="R10">The resistor 10.</param>
	/// <returns>resistance in ohms</returns>
	static ld parallelResistance(const ld R1, const ld R2, const ld R3, const ld R4,
		const ld R5, const ld R6, const ld R7, const ld R8, const ld R9, const ld R10);

		/// <summary>
	/// Calculates the total capacitor of a Series of   capacitors.
	/// </summary>
	/// <param name="C1">The capacitor 1.</param>
	/// <param name="C2">The capacitor 2.</param>
	/// <param name="C3">The capacitor 3.</param>
	/// <param name="C4">The capacitor 4.</param>
	/// <param name="C5">The capacitor 5.</param>
	/// <param name="C6">The capacitor 6.</param>
	/// <param name="C7">The capacitor 7.</param>
	/// <param name="C8">The capacitor 8.</param>
	/// <param name="C9">The capacitor 9.</param>
	/// <param name="C10">The capacitor 10.</param>
	/// <returns>capacitance (F)</returns>
	static ld seriesCapacitance(const ld C1, const ld C2, const ld C3, const ld C4,
		const ld C5, const ld C6, const ld C7, const ld C8, const ld C9, const ld C10);

	/// <summary>
	/// Calculates the total resistance of resistors hooked up in parallel.
	/// </summary>
	/// <param name="C1">The capacitor 1.</param>
	/// <param name="C2">The capacitor 2.</param>
	/// <param name="C3">The capacitor 3.</param>
	/// <param name="C4">The capacitor 4.</param>
	/// <param name="C5">The capacitor 5.</param>
	/// <param name="C6">The capacitor 6.</param>
	/// <param name="C7">The capacitor 7.</param>
	/// <param name="C8">The capacitor 8.</param>
	/// <param name="C9">The capacitor 9.</param>
	/// <param name="C10">The capacitor 10.</param>
	/// <returns>capacitance (F)</returns>
	static ld parallelCapacitance(const ld C1, const ld C2, const ld C3, const ld C4,
		const ld C5, const ld C6, const ld C7, const ld C8, const ld C9, const ld C10);


	/// <summary>
	/// Calculates the terminal  voltage.
	/// </summary>
	/// <param name="emf">The electromotive force.</param>
	/// <param name="r">The internal resistance.</param>
	/// <param name="I">The Charge.</param>
	/// <returns>Voltage</returns>
	static ld terminalVoltage(const ld emf, const ld r, const ld I);


	/// <summary>
	/// Calculates the Current of a  ohms law.
	/// </summary>
	/// <param name="emf">The EMF.</param>
	/// <param name="RLoad">The resistance load of all resistors connected.</param>
	/// <param name="r">The internal resistance.</param>
	/// <returns>current I in amperes</returns>
	static ld current_OhmsLaw(const ld emf, const ld RLoad, const ld r);

	/// <summary>
	/// Calculates the powers dissipated
	/// </summary>
	/// <param name="I">The current.</param>
	/// <param name="Rload">The Resistance load.</param>
	/// <returns>power output in watts (W)S</returns>
	static ld powerDissipation(const ld I, const ld R);

	/// <summary>
	/// add the total emfs for a series connection. where emf is the electromagnetic force
	/// </summary>
	/// <param name="emf1">The emf1.</param>
	/// <param name="emf2">The emf2.</param>
	/// <param name="emf3">The emf3.</param>
	/// <param name="emf4">The emf4.</param>
	/// <returns>net emf</returns>
	static ld emfsParallelConnection_added(const ld emf1, const ld emf2, const ld emf3, const ld emf4);

	/// <summary>
	/// add the total emfs for a series connection. where emf is the electromagnetic force
	/// </summary>
	/// <param name="emf1">The emf1.</param>
	/// <param name="emf2">The emf2.</param>
	/// <param name="emf3">The emf3.</param>
	/// <param name="emf4">The emf4.</param>
	/// <returns></returns>
	static ld emfsSeriesConnection_subtracted(const ld emf1, const ld emf2, const ld emf3, const ld emf4);

	/// <summary>
	/// calculates the internals resistance.
	/// </summary>
	/// <param name="Vt">The terminal voltage.</param>
	/// <param name="E">The emf.</param>
	/// <param name="I">The current.</param>
	/// <returns>the internal resistance (r)</returns>
	static ld internalResistance(const ld Vt, const ld E, const ld I);

	/// <summary>
	/// calculates the RC time constant of a circuit containing a resistor and a
	/// capacitor.
	/// </summary>
	/// <param name="R">The resistance.</param>
	/// <param name="C">The capacitance.</param>
	/// <returns>tau(Greek letter)</returns>
	static ld timeConstant_RC(const ld R, const ld C);

	/// <summary>
	/// calculates the resistances from time constant and capacitance.
	/// </summary>
	/// <param name="tau">The tau(time constant).</param>
	/// <param name="C">The capacitance.</param>
	/// <returns>the resistance Ohms</returns>
	static ld resistance_fromTimeConstant(const ld tau, const ld C);

	/// <summary>
	/// calculates the capacitance from time constant and resistance.
	/// </summary>
	/// <param name="tau">The tau.</param>
	/// <param name="R">The resistance.</param>
	/// <returns></returns>
	static ld capacitance_fromTimeConstant(const ld tau, const ld R);

	/// <summary>
	/// Voltages the vs time charging capacitor.
	/// </summary>
	/// <param name="emf">The EMF.</param>
	/// <param name="t">The time.</param>
	/// <param name="R">The resistance.</param>
	/// <param name="C">The capacitance.</param>
	/// <returns></returns>
	static ld voltageVsTimeChargingCapacitor(const ld emf, const ld t, const ld R, const ld C);

	/// <summary>
	/// calculates the Frequency from cycles and seconds.
	/// </summary>
	/// <param name="cycles">The cycles.</param>
	/// <param name="seconds">The seconds.</param>
	/// <returns>frequency</returns>
	static ld frequency(const ld cycles, const ld seconds);

	/// <summary>
	/// Frequencies the specified period.
	/// </summary>
	/// <param name="period">The period.</param>
	/// <returns></returns>
	static ld frequency(const ld period);

	/// <summary>
	/// calculates the periods from the specified f.
	/// </summary>
	/// <param name="f">The f.</param>
	/// <returns>period</returns>
	static ld period(const ld f);


	/// <summary>
	/// Resistances from DC equations.
	/// </summary>
	/// <param name="t">The time.</param>
	/// <param name="VoverE">The V/E .</param>
	/// <param name="C">The capacitance.</param>
	/// <returns></returns>
	static ld resistance_fromDCequations(const ld t, const ld VoverE, const ld C);

	/// <summary>
	/// calculates using the exact exponential treatment, how much time is required to
	/// discharge a C F capacitor through a R Ω resistor down to pOv% of
	/// its original voltage.
	/// </summary>
	/// <param name="C">The capacitance.</param>
	/// <param name="R">The resistance.</param>
	/// <param name="pOv">The percent of original voltage.</param>
	/// <returns>time in seconds</returns>
	static ld time_fromDischargeEquation(const ld C, const ld R, const ld pOv);

	/// <summary>
	/// If you wish to take a picture of a bullet traveling at v m/s, then a
	/// very brief flash of light produced by an RC discharge through a flash
	/// tube can limit blurring. Assuming d m of motion during one RC constant
	/// is acceptable, and given that the flash is driven by a C F capacitor,
	/// what is the resistance in the flash tube?
	/// </summary>
	/// <param name="d">The distance in meters.</param>
	/// <param name="C">The capacitance.</param>
	/// <param name="v">The velocity.</param>
	/// <returns>resistance in Ohms</returns>
	static ld resistance_fromDistanceVelocity(const ld d, const ld C, const ld v);

	/// <summary>
	/// A flashing lamp in a Christmas earring is based on an RC discharge of a
	/// capacitor through its resistance. The effective duration of the flash
	/// is t s, during which it produces an average 0.500 W from an average
	/// 3.00 V. calculates the energy it dissipates?
	/// </summary>
	/// <param name="P">The power.</param>
	/// <param name="t">The time.</param>
	/// <returns>energy in joules</returns>
	static ld energyUsed(const ld P, const ld t);

	/// A flashing lamp in a Christmas earring is based on an RC discharge of a
	/// capacitor through its resistance. The effective duration of the flash
	/// is t s, during which it produces an average 0.500 W from an average
	/// 3.00 V. calculates the charge that moves through the lamp.
	/// <param name="P">The power.</param>
	/// <param name="V">The volts.</param>
	/// <param name="t">The time.</param>
	/// <returns>coulombs</returns>
	static ld charge_fromPowerVoltsTime(const ld P, const ld V, const ld t);

	/// <summary>
	/// A C F capacitor charged to V is discharged through a resistor.
	/// Calculate the temperature increase of the resistor, given that its of a mass
	/// in kg and its specific heat is c kJ/kg⋅C∘, noting that most of the thermal
	/// energy is retained in the short time of the discharge.
	/// </summary>
	/// <param name="C">The capacitance.</param>
	/// <param name="V">The volts.</param>
	/// <param name="mass">The mass.</param>
	/// <param name="c">The specific heat.</param>
	/// <returns>temp in C</returns>
	static ld temperatureIncreaseOfResistor(const ld C, const ld V, const ld mass, const ld c);

	/// <summary>
	/// EMFs the specified r.
	/// </summary>
	/// <param name="r">The r.</param>
	/// <param name="R_load">The r load.</param>
	/// <param name="I">The i.</param>
	/// <returns></returns>
	static ld emf(const ld r, const ld R_load, const ld I);



	~Circuits()
	{
		delete _circuitPtr;
	}

private:
	static void countIncrease() { circuits_objectCount += 1; }
	static void countDecrease() { circuits_objectCount -= 1; }
	ld _circuitVal;

};
#endif

inline ld Circuits::seriesResistance(const ld R1 = 0, const ld R2 = 0, const ld R3 = 0,
	const ld R4 = 0, const ld R5 = 0, const ld R6 = 0, const ld R7 = 0, const ld R8 = 0,
	const ld R9 = 0, const ld R10 = 0)
{

return R1 + R2 + R3 + R4 + R5 + R6 + R7 + R8 + R9 + R10;//Ohms
}

inline ld Circuits::parallelResistance(const ld R1 = 0, const ld R2 = 0, const ld R3 = 0,
	const ld R4 = 0, const ld R5 = 0, const ld R6 = 0, const ld R7 = 0, const ld R8 = 0,
	const ld R9 = 0, const ld R10 = 0)
{
	ld total = 0;
	if (R1>0)
	{
		total += 1 / R1;
	}
	if (R2>0)
	{
		total += 1 / R2;
	}
	if (R3 > 0)
	{
		total += 1 / R3;
	}
	if (R4 > 0)
	{
		total += 1 / R4;
	}
	if (R5 > 0)
	{
		total += 1 / R5;
	}
	if (R6 > 0)
	{
		total += 1 / R6;
	}
	if (R7 > 0)
	{
		total += 1 / R7;
	}
	if (R8 > 0)
	{
		total += 1 / R8;
	}
	if (R9 > 0)
	{
		total += 1 / R9;
	}
	if (R10 > 0)
	{
		total += 1 / R10;
	}
	return 1/total;
}

inline ld Circuits::seriesCapacitance(const ld C1, const ld C2, const ld C3, const ld C4, const ld C5, const ld C6, const ld C7, const ld C8, const ld C9, const ld C10)
{
	ld total = 0;
	if (C1>0)
	{
		total += 1 / C1;
	}
	if (C2>0)
	{
		total += 1 / C2;
	}
	if (C3 > 0)
	{
		total += 1 / C3;
	}
	if (C4 > 0)
	{
		total += 1 / C4;
	}
	if (C5 > 0)
	{
		total += 1 / C5;
	}
	if (C6 > 0)
	{
		total += 1 / C6;
	}
	if (C7 > 0)
	{
		total += 1 / C7;
	}
	if (C8 > 0)
	{
		total += 1 / C8;
	}
	if (C9 > 0)
	{
		total += 1 / C9;
	}
	if (C10 > 0)
	{
		total += 1 / C10;
	}
	return 1/total;


}

inline ld Circuits::parallelCapacitance(const ld C1, const ld C2, const ld C3, const ld C4, const ld C5, const ld C6, const ld C7, const ld C8, const ld C9, const ld C10)
{
	return  C1 + C2 + C3 + C4 + C5 + C6 + C7 + C8 + C9 + C10;//Ohms

}

inline ld Circuits::terminalVoltage(const ld emf, const ld r, const ld I)
{
	return emf - I*r;// V
}

inline ld Circuits::current_OhmsLaw(const ld emf, const ld RLoad, const ld r)
{
	return emf/(RLoad+r);//amperes (I)
}

inline ld Circuits::powerDissipation(const ld I, const ld Rload)
{
	return (I*I)*Rload;//Watts
}

inline ld Circuits::emfsParallelConnection_added(const ld emf1=0, const ld emf2=0, const ld emf3=0, const ld emf4=0)
{
	return emf1 + emf2 + emf3 + emf4;
}

inline ld Circuits::emfsSeriesConnection_subtracted(const ld emf1=0, const ld emf2=0, const ld emf3=0, const ld emf4=0)
{
	return emf1 - emf2 - emf3 - emf4;
}

inline ld Circuits::internalResistance(const ld Vt, const ld E, const ld I)
{
	return (Vt - E)/I;//Ohms
}

inline ld Circuits::timeConstant_RC(const ld R, const ld C)
{
	return R*C;//seconds
}

inline ld Circuits::resistance_fromTimeConstant(const ld tau, const ld C)
{
	return tau/C;//Ohms
}

inline ld Circuits::capacitance_fromTimeConstant(const ld tau, const ld R)
{
	return tau/R;//Farads
}

inline ld Circuits::voltageVsTimeChargingCapacitor(const ld emf, const ld t, const ld R, const ld C)
{
	const double tau = R * C;
	const double toRaise = -t / tau;
	return emf*(1.0 - exp(toRaise));
}

inline ld Circuits::frequency(const ld cycles, const ld seconds)
{
	return cycles/seconds;
}

inline ld Circuits::frequency(const ld period)
{
	return 1 / period;
}

inline ld Circuits::period(const ld f)
{
	return 1 / f;//period t
}

inline ld Circuits::resistance_fromDCequations(const ld t, const ld VoverE, const ld C)
{
	return (-t/(log(1-VoverE)*C));//ohms
}

inline ld Circuits::time_fromDischargeEquation(const ld C, const ld R, const ld pOv)
{
	return -R*C*log(pOv/100.0);//seconds
}

inline ld Circuits::resistance_fromDistanceVelocity(const ld d, const ld C, const ld v)
{
	return d / (C * v);//Ohms
}

inline ld Circuits::energyUsed(const ld P, const ld t)
{
	return P*t;//joules
}

inline ld Circuits::charge_fromPowerVoltsTime(const ld P, const ld V, const ld t)
{
	return (P/V)*t;//C
}

inline ld Circuits::temperatureIncreaseOfResistor(const ld C, const ld V, const ld mass, const ld c)
{
	return (C*(V*V))/(2.0*mass*c);//temperature in C
}

inline ld Circuits::emf(const ld r, const ld R_load, const ld I)
{
	return I * (r + R_load);
}
