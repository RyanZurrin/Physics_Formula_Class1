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

		ElectroMagneticInduction(ld val)
	{
		_emiPtr = nullptr;
		_electroMagVar = val;
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
	/// A generator coil is rotated through a revolution from 0 to theta degrees,
	/// in t seconds. Having N turns the coil has a radius of r (m) and is in a
	/// uniform magnetic field of B. Calculate the average emf induced.
	/// </summary>
	/// <param name="N">The number of turns in coil.</param>
	/// <param name="r">The radius of coil.</param>
	/// <param name="B">The magnetic uniform field.</param>
	/// <param name="t">The time it takes to rotate theta degrees.</param>
	/// <param name="thetaS">The starting angle of rotation.</param>
	/// <param name="thetaF">The finishing angle of rotation.</param>
	/// <returns>emf average (V)</returns>
	static ld emfFaradyFullEquation(const ld N, const ld r, const ld B, const ld t, const ld thetaS, const ld thetaF);

	/// <summary>
	/// Calculates the magnitude of an induced emf when a bar magnet  is thrust
	/// into a coil with N loops having a radius of r (m) and the average value of
	/// B cos(theta) that is given due to complexity as increasing from B1 to B2
	/// over a period of t seconds.
	/// </summary>
	/// <param name="N">The number of loops.</param>
	/// <param name="r">The radius.</param>
	/// <param name="B1">The starting magnetic field.</param>
	/// <param name="B2">The ending magnetic field.</param>
	/// <param name="t">The time over which the increase of the
	/// magnetic field takes place.</param>
	/// <returns>magnitude of emf (V)</returns>
	static ld emfMagnitude_FaradayNoMinus(const ld N, const ld r, const ld B1, const ld B2, const ld t);

	/// <summary>
	/// Calculates the change in flux.
	/// </summary>
	/// <param name="A">the area = pi*r^2.</param>
	/// <param name="deltaB">The delta b = .</param>
	/// <returns></returns>
	static ld deltaFlux(const ld A, const ld deltaB);

	/// <summary>
	/// EMFs the induced in generator coil.
	/// </summary>
	/// <param name="N">The number of loop in coil.</param>
	/// <param name="l">The length of the loop.</param>
	/// <param name="w">The width of coil loop.</param>
	/// <param name="aW">a angular velocity.</param>
	/// <param name="B">The magnetic field strength.</param>
	/// <param name="t">The time for a rotation.</param>
	/// <returns>emf total from generator coil (V)</returns>
	static ld emf_inducedInGeneratorCoil(const ld N, const ld l, const ld w, const ld aW, const ld B, const ld t);

	/// <summary>
	/// Calculates the peek emf.
	/// </summary>
	/// <param name="N">The number of turns in a coil.</param>
	/// <param name="A">The area.</param>
	/// <param name="B">The magnetic field strength.</param>
	/// <param name="aW">The angular velocity.</param>
	/// <returns>peek emf (V)</returns>
	static ld emf_peek(const ld N, const ld A, const ld B, const ld aW);

	/// <summary>
	/// Calculates the peek emf.
	/// </summary>
	/// <param name="N">The number of turns in a coil.</param>
	/// <param name="r">The radius of coil.</param>
	/// <param name="B">The magnetic field strength.</param>
	/// <param name="rad">The angle of rotation in radians.</param>
	/// <param name="t">The time for a rotation.</param>
	/// <returns>peek emf (V)</returns>
	static ld emf_peek(const ld N, const ld r, const ld B, const ld rad, const ld t);

	/// <summary>
	/// Calculate the peak voltage of a generator that rotates its N-turn,
	/// d m diameter coil rotating at rpm rpms in a B T field.
	/// </summary>
	/// <param name="N">The number of loops in coil.</param>
	/// <param name="d">The diameter of coil.</param>
	/// <param name="B">The magnetic filed strength.</param>
	/// <param name="rpm">The RPMs.</param>
	/// <returns>peek emf voltage</returns>
	static ld emf_peekFromDiameterAndRPMs(const ld N, const ld d, const ld B, const ld rpm);

	/// <summary>
	/// Calculates the EMF induced by magnetic flux over t time having N turns
	/// is considered Faraday's law of induction: Lenz's Law->(why there is a
	/// minus sign.
	/// </summary>
	/// <param name="N">The amount of turns in coil.</param>
	/// <param name="f">The flux.</param>
	/// <param name="t">The time.</param>
	/// <returns>emf = volts(V)</returns>
	static ld emf_inducedByMagneticFlux(const ld N, const ld f, const ld t);

	/// <summary>
	/// An MRI technician moves his hand from a region of very low magnetic field
	/// strength into an MRI scannerís magnetic field of B(T) with his fingers
	/// pointing in the direction of the field. Calculate the average emf induced in
	/// his wedding ring, given its diameter is d(m) and assuming it takes time
	/// t(s) to move it into the field.
	/// </summary>
	/// <param name="B">The magnetic filed.</param>
	/// <param name="d">The diameter.</param>
	/// <param name="t">The time in seconds.</param>
	/// <returns>average emf (V)</returns>
	static ld emf_avgOnCoil(const ld B, const ld d, const ld t);

	/// <summary>
	/// number of turns in a coil from EMF and time t over the flux;
	/// </summary>
	/// <param name="t">The time.</param>
	/// <param name="emf">The EMF.</param>
	/// <param name="f">The flux.</param>
	/// <returns>turns in a coil</returns>
	static ld n_turnsInCoilFromEMFEquation(const ld t, const ld emf, const ld f);

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
	/// <param name="f">The flux.</param>
	/// <param name="emf">The EMF.</param>
	/// <returns>time in seconds</returns>
	static ld time_fromEMFEquation(const ld N, const ld f, const ld emf);

	/// <summary>
	/// Calculates the motional  EMF.
	/// </summary>
	/// <param name="B">The magnetic field.</param>
	/// <param name="l">The length of rod.</param>
	/// <param name="x">The distance the rod moves.</param>
	/// <param name="t">The time it moves over.</param>
	/// <returns>emf from motion (V)</returns>
	static ld motionalEMF(const ld B, const ld l, const ld x, const ld t);

	/// <summary>
	/// Calculates the motional EMF.
	/// </summary>
	/// <param name="B">The magnetic field.</param>
	/// <param name="l">The length of rod.</param>
	/// <param name="v">The velocity -> x/t .</param>
	/// <returns>emf from motion(V)</returns>
	static ld motionalEMF(const ld B, const ld l, const ld v);

	/// <summary>
	/// calculates the length a magnetic rod must be when producing an emf of V.
	/// </summary>
	/// <param name="V">The EMF voltage (V).</param>
	/// <param name="B">The magnetic field (B).</param>
	/// <param name="v">The velocity (v).</param>
	/// <returns>length of magnetic rod</returns>
	static ld lengthOfRod_emfEq(const ld V, const ld B, const ld v);

	/// <summary>
	/// Calculates the velocity of the motion of magnetic rod when a emf of V is
	/// created with a magnetic field of B and having a rod of length l (m).
	/// </summary>
	/// <param name="V">The emf voltage (V).</param>
	/// <param name="B">The magnetic field (T).</param>
	/// <param name="l">The length of rod (m).</param>
	/// <returns>velocity (m/s)</returns>
	static ld velocityOfMotion_emfEq(const ld V, const ld B, const ld l);

	/// <summary>
	/// Calculates the magnetic field from when a rod of length l moves at a
	/// velocity of v causing a magnetic field strength of B.
	/// </summary>
	/// <param name="V">The emf voltage.</param>
	/// <param name="l">The length of rod.</param>
	/// <param name="v">The velocity.</param>
	/// <returns>magnetic field strength (T)</returns>
	static ld magneticFieldFrom_emfEq(const ld V, const ld l, const ld v);

	/// <summary>
	/// Magnetics the field magnitude.
	/// </summary>
	/// <param name="flux">The flux.</param>
	/// <param name="Ard">The Area, radius or diameter.</param>
	/// <param name="theta">The theta, is at default value of 0.</param>
	/// <param name="mode">The mode is used as a switch between what
	/// information you use for the Ard argument: use 'r' for radius or 'd'
	/// for diameter and if you are using the already calculated cross sectional
	/// then leave out..</param>
	/// <returns>magnetic field (T)</returns>
	static ld magneticFieldMagnitude(const ld flux, const ld Ard, const ld theta, const ld mode);

	/// <summary>
	/// Calculates the voltage or number of loops in a transformer. Use a 0 as
	/// placeholder in the unknowns method argument.
	/// </summary>
	/// <param name="Vs">The volts secondary(output).</param>
	/// <param name="Vp">The volts primary(input).</param>
	/// <param name="Ns">The number of loops secondary(output).</param>
	/// <param name="Np">The number of loops primary(input).</param>
	/// <param name="mode">The mode used to specify what you want to solve for,\n
	/// "Vs" = volts secondary,\n
	/// "vp" = volts primary,\n
	/// "Ns" = number of loops secondary,\n
	/// "Np" = number of loops primary.\n
	/// example: transformerEquation(2.5,3.4,5,10,"Ns");\n
	/// this would solve for the number of loops in the secondary transformer</param>
	/// <returns>volts or loops depending on mode used</returns>
	static ld transformerEquations_VN(const ld Vs, const ld Vp, const ld Ns, const ld Np, string mode);

	/// <summary>
	/// Calculates the voltage or current in a transformer. use a 0 as a place
	/// holder in the unknown variables method argument.
	/// </summary>
	/// <param name="Vs">The volts secondary(output).</param>
	/// <param name="Vp">The volts primary(input).</param>
	/// <param name="Is">The current secondary(output).</param>
	/// <param name="Ip">The current primary(input).</param>
	/// <param name="mode">The mode used to specify what you want to solve for,\n
	/// "Vs" = volts secondary,\n
	/// "vp" = volts primary,\n
	/// "Is" = current secondary,\n
	/// "Ip" = current primary.\n
	/// example: transformerEquation(2.5,3.4,5,10,"Is");\n
	/// this would solve for the current in the secondary transformer</param>
	/// <returns>volts or current depending on the mode picked</returns>
	static ld transformerEquations_VI(const ld Vs, const ld Vp, const ld Is, const ld Ip, string mode);

	/// <summary>
	/// Calculates the current or number of loops in a transformer. use a 0 as a place
	/// holder in the unknown variables method argument.
	/// </summary>
	/// <param name="Is">The current secondary(output).</param>
	/// <param name="Ip">The current primary(input).</param>
	/// <param name="Ns">The number of loops secondary(output).</param>
	/// <param name="Np">The number of loops primary(input).</param>
	/// <param name="mode">The mode used to specify what you want to solve for,\n
	/// "Is" = current secondary,\n
	/// "Ip" = current primary,\n
	/// "Ns" = number of loops secondary,\n
	/// "Np" = number of loops primary.\n
	/// example: transformerEquation(2.5,3.4,5,10,"Is");\n
	/// this would solve for the current in the secondary transformer</param>
	/// <returns>current or number of loops depending on the mode picked</returns>
	static ld transformerEquations_IN(const ld Is, const ld Ip, const ld Ns, const ld Np, string mode);

	/// <summary>
	/// Calculates the frequencies from a know angular velocity of aW.
	/// </summary>
	/// <param name="aW">a angular velocity.</param>
	/// <returns>frequency (Hz</returns>
	static ld frequency(const ld aW);

	/// <summary>
	/// Calculates the period from the known frequency of f.
	/// </summary>
	/// <param name="f">The frequency.</param>
	/// <returns></returns>
	static ld period(const ld f);

	/// <summary>
	/// Calculates the current in the coil.
	/// </summary>
	/// <param name="emf">The EMF.</param>
	/// <param name="R">The resistance.</param>
	/// <returns>current (A)</returns>
	static ld currentInCoil(const ld emf, const ld R);

	/// <summary>
	/// Calculates the emf2 from the mutual inductance of M between two devices
	/// where the current from device one is I and the time t over which the
	/// current changes.
	/// </summary>
	/// <param name="M">The Mutual inductance.</param>
	/// <param name="I">The current.</param>
	/// <param name="t">The time.</param>
	/// <returns>emf voltage</returns>
	static ld emf_byMutualInductance(const ld M, const ld I, const ld t);


	/// <summary>
	/// Calculates the mutual inductance.
	/// </summary>
	/// <param name="emf">The EMF.</param>
	/// <param name="I">The current.</param>
	/// <param name="t">The time.</param>
	/// <returns>henry(H)</returns>
	static ld mutualInductance(const ld emf, const ld I, const ld t);

	/// <summary>
	/// calculates the EMF by self inductance.
	/// </summary>
	/// <param name="L">The self inductance of the device.</param>
	/// <param name="I">The current.</param>
	/// <param name="t">The time.</param>
	/// <returns>emf voltage</returns>
	static ld emf_bySelfInductance(const ld L, const ld I, const ld t);

	/// <summary>
	/// calculates the self inductance.
	/// </summary>
	/// <param name="emf">The EMF.</param>
	/// <param name="I">The current.</param>
	/// <param name="t">The time.</param>
	/// <returns>inductance of inductor(H)</returns>
	static ld selfInductance(const ld emf, const ld I, const ld t);

	/// <summary>
	/// calculates the self inductance.
	/// </summary>
	/// <param name="N">The number of loops.</param>
	/// <param name="B">The flux.</param>
	/// <param name="I">The current.</param>s
	/// <returns>inductance(H)</returns>
	static ld selfInductance_N(const ld N, const ld B, const ld I);

	/// <summary>
	/// Calculates the inductance of a solenoid.
	/// </summary>
	/// <param name="N">The number of turns in coil.</param>
	/// <param name="Ard">the area, radius or diameter.</param>
	/// <param name="l">The length of solenoid.</param>
	/// <param name="mode">put a 'r' if use a radius or a 'd' if using the
	/// diameter in the Ard argument.</param>
	/// <returns>inductance(H)</returns>
	static ld inductanceSolenoid(const ld N, const ld A, const ld l, char mode);

	/// <summary>
	/// Calculates the energy stored in an inductor.
	/// </summary>
	/// <param name="L">The inductance.</param>
	/// <param name="I">The current.</param>
	/// <returns>energy (J)</returns>
	static ld energyStoredInInductor(const ld L, const ld I);





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

//=============================================================================
//in-line class Implementation

inline ld ElectroMagneticInduction::magneticFlux(const ld B, const ld A, const ld theta = 0)
{
	return B * A * cos(theta * RADIAN);//T*m^2 = Tesla meters squared
}

inline ld ElectroMagneticInduction::emfFaradyFullEquation(const ld N, const ld r, const ld B, const ld t, const ld thetaS, const ld thetaF)
{
	const ld area = _PI * (r * r);
	const ld deltaTheta = cos(thetaF * RADIAN) - cos(thetaS * RADIAN);
	const ld flux = area * B * deltaTheta;
	return  -N * (flux / t);
}

inline ld ElectroMagneticInduction::emfMagnitude_FaradayNoMinus(const ld N, const ld r, const ld B1, const ld B2, const ld t)
{
	const ld area = _PI * (r * r);
	const ld deltaB = abs(B2 - B1);
	const ld deltaFlux = area * deltaB;

	return N * (deltaFlux / t);//V
}

inline ld ElectroMagneticInduction::deltaFlux(const ld A, const ld deltaB)
{

	return A * deltaB;
}

inline ld ElectroMagneticInduction::emf_inducedInGeneratorCoil(const ld N, const ld l, const ld w, const ld aW, const ld B, const ld t)
{
	const ld area = l * w;

	return N * area * B * aW * sin((aW * t) * RADIAN);//V
}

inline ld ElectroMagneticInduction::emf_peek(const ld N, const ld A, const ld B, const ld aW)
{
	return N * A * B * aW;//V
}

inline ld ElectroMagneticInduction::emf_peek(const ld N, const ld r, const ld B, const ld rad, const ld t)
{
	const ld area = _PI * (r * r);
	const ld aW = rad / t;
	return N * area * B * aW;//V
}

inline ld ElectroMagneticInduction::emf_peekFromDiameterAndRPMs(const ld N, const ld d, const ld B, const ld rpm)
{
	const ld aW = (rpm * 2.0 * _PI) / 60.0;//angular velocity
	const ld A = (_PI * (d * d)) / 4;//cross sectional
	return N * A * B * aW;//V
}

inline ld ElectroMagneticInduction::emf_inducedByMagneticFlux(const ld N, const ld f, const ld t)
{
	return -N * (f / t);//V
}

inline ld ElectroMagneticInduction::emf_avgOnCoil(const ld B, const ld d, const ld t)
{
	return (_PI * B * (d * d)) / (4.0 * t);//V
}

inline ld ElectroMagneticInduction::n_turnsInCoilFromEMFEquation(const ld t, const ld emf, const ld f)
{
	return (t / f) * emf;//turns in coil
}

inline ld ElectroMagneticInduction::flux_fromEMFEquation(const ld emf, const ld t, const ld N)
{
	return -(t * emf) / N;//T*m^2
}

inline ld ElectroMagneticInduction::time_fromEMFEquation(const ld N, const ld f, const ld emf)
{
	return N * (f / emf);//seconds
}

inline ld ElectroMagneticInduction::motionalEMF(const ld B, const ld l, const ld x, const ld t)
{
	return B * ((l * x) / t);//V
}

inline ld ElectroMagneticInduction::motionalEMF(const ld B, const ld l, const ld v)
{
	return B * l * v;//V
}

inline ld ElectroMagneticInduction::lengthOfRod_emfEq(const ld V, const ld B, const ld v)
{
	return V / (B * v);//m
}

inline ld ElectroMagneticInduction::velocityOfMotion_emfEq(const ld V, const ld B, const ld l)
{
	return V / (B * l);// m/s
}

inline ld ElectroMagneticInduction::magneticFieldFrom_emfEq(const ld V, const ld l, const ld v)
{
	return V / (l * v);//T
}

inline ld ElectroMagneticInduction::magneticFieldMagnitude(const ld flux, const ld Ard, const ld theta = 0, const ld mode = 'A')
{
	ld area;
	if (mode == 'a' || mode == 'A')
	{
		return flux/(Ard*cos(theta*RADIAN));//(T)
	}
	else if (mode == 'r' || mode == 'R')
	{
		area = _PI * (Ard * Ard);
		return flux/(area*cos(theta*RADIAN));//(T)
	}
	else
	{
		area = _PI * ((Ard * Ard) / 4.0);
		return flux/(area*cos(theta*RADIAN));//(T)
	}
}

inline ld ElectroMagneticInduction::transformerEquations_VN(const ld Vs, const ld Vp, const ld Ns, const ld Np, string mode)
{
	if (mode == "Vs" || mode == "vs" || mode == "VS" || mode == "vS")
	{
		return (Ns / Np) * Vp;//voltage secondary
	}
	else if (mode == "Vp" || mode == "vp" || mode == "VP" || mode == "vP")
	{
		return (Np / Ns) * Vs;//voltage primary
	}
	else if (mode == "Ns" || mode == "ns" || mode == "NS" || mode == "nS")
	{
		return (Vs / Vp) * Np;//number of loops secondary
	}
	else if (mode == "Np" || mode == "np" || mode == "NP" || mode == "nP")
	{
		return (Vp / Vs) * Ns;//number of loops primary
	}
	else
		return -111111111111;//error

}

inline ld ElectroMagneticInduction::transformerEquations_VI(const ld Vs, const ld Vp, const ld Is, const ld Ip, string mode)
{
	if (mode == "Vs" || mode == "vs" || mode == "VS" || mode == "vS")
	{
		return (Ip / Is) * Vp;//voltage secondary
	}
	else if (mode == "Vp" || mode == "vp" || mode == "VP" || mode == "vP")
	{
		return (Is / Ip) * Vs;//voltage primary
	}
	else if (mode == "Is" || mode == "is" || mode == "IS" || mode == "iS")
	{
		return (Vp / Vs) * Ip;//current secondary
	}
	else if (mode == "Ip" || mode == "ip" || mode == "IP" || mode == "iP")
	{
		return (Vs / Vp) * Is;//current primary
	}
	else
		return -111111111111;//error
}

inline ld ElectroMagneticInduction::transformerEquations_IN(const ld Is, const ld Ip, const ld Ns, const ld Np, string mode)
{
	if (mode == "Is" || mode == "is" || mode == "IS" || mode == "iS")
	{
		return (Np / Ns) * Ip;//current secondary
	}
	else if (mode == "Ip" || mode == "ip" || mode == "IP" || mode == "iP")
	{
		return (Ns / Np) * Is;//current primary
	}
	else if (mode == "Ns" || mode == "ns" || mode == "NS" || mode == "nS")
	{
		return (Ip / Is) * Np;//number of loops secondary
	}
	else if (mode == "Np" || mode == "np" || mode == "NP" || mode == "nP")
	{
		return (Ns / Np) * Is;//number of loops primary
	}
	else
		return -111111111111;//error
}

inline ld ElectroMagneticInduction::frequency(const ld aW)
{
	return aW/(2.0*_PI);//Hz
}

inline ld ElectroMagneticInduction::period(const ld f)
{
	return 1 / f;//s
}

inline ld ElectroMagneticInduction::currentInCoil(const ld emf, const ld R)
{
	return emf/R;//A
}

inline ld ElectroMagneticInduction::emf_byMutualInductance(const ld M, const ld I, const ld t)
{
	return -M * (I / t);//V
}

inline ld ElectroMagneticInduction::mutualInductance(const ld emf, const ld I, const ld t)
{
	return -emf * (t / I);//henry(H) = (V*s)/A = Ohm*s
}

inline ld ElectroMagneticInduction::emf_bySelfInductance(const ld L, const ld I, const ld t)
{
	return -L * (I / t);//V
}

inline ld ElectroMagneticInduction::selfInductance(const ld emf, const ld I, const ld t)
{
	return -emf * (t / I);//henry(H)= (V*s)/A = Ohm*s
}

inline ld ElectroMagneticInduction::selfInductance_N(const ld N, const ld B, const ld I)
{
	return N * (B / I);//(H)
}

inline ld ElectroMagneticInduction::inductanceSolenoid(const ld N, const ld Ard, const ld l, char mode = 'a')
{
	ld area;
	if (mode == 'a' || mode == 'A')
	{
		return (_Uo_ * (N * N) * Ard) / l;//(H)
	}
	else if	(mode == 'r' || mode == 'R')
	{
		area = _PI * (Ard * Ard);
		return (_Uo_ * (N * N) * area) / l;//(H)
	}
	else
	{
		area = _PI * ((Ard * Ard) / 4.0);
		return (_Uo_ * (N * N) * area) / l;//(H)
	}
}

inline ld ElectroMagneticInduction::energyStoredInInductor(const ld L, const ld I)
{
	return (1.0 / 2.0) * L * (I * I);//J
}
