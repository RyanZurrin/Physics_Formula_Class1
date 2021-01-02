#pragma once
/**
 * @class Waves
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   12/17/2020
 ____________________________________________________________________________*/

#ifndef WAVES_H
#define WAVES_H
#include <iostream>
#include "Elasticity.h"
#include "Energy.h"


static int waves_objectCount = 0;



class Waves :
	public Elasticity, public Energy
{
private:
	static void countIncrease() { waves_objectCount += 1; }
	static void countDecrease() { waves_objectCount -= 1; }
public:
	Waves* _wavePtr;
	/**
	 * @brief no argument constructor initiates the _wavePtr to nullptr
	 */
	Waves()
	{
		_wavePtr = nullptr;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	Waves(const Waves& t)
	{
		_wavePtr = t._wavePtr;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	Waves(Waves&& t) noexcept
	{
		_wavePtr = t._wavePtr;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	Waves& operator=(const Waves& t)
	{
		if (this != &t)
		{
			_wavePtr = t._wavePtr;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\n waves object count: "
		<< waves_objectCount << std::endl; }
	static int get_objectCount() { return waves_objectCount; }


	/// <summary>
	/// calculates the energy stored in a deformed system that obey's Hook's law.
	/// </summary>
	/// <param name="k">The force constant.</param>
	/// <param name="x">The displacement from equilibrium.</param>
	/// <returns>PE, stored potential energy</returns>
	static ld elasticPotentialEnergy(const ld k, const ld x)
	{
		return .5 * (k * pow(x, 2));
	}

	/// <summary>
	/// Calculates the applied force.
	/// </summary>
	/// <param name="k">The force constant.</param>
	/// <param name="x">The total displacement from the equilibrium.</param>
	/// <returns>Force, applied</returns>
	static ld appliedForce(const ld k, const ld x)
	{
		return k * x;
	}

	/// <summary>
	/// calculates the restoring force.
	/// </summary>
	/// <param name="k">The force constant.</param>
	/// <param name="x">The total displacement from equilibrium.</param>
	/// <returns>Force, restoring</returns>
	static ld restoringForce(const ld k, const ld x)
	{
		return -k * x;
	}

	/// <summary>
	/// Calculates the force constant (k).
	/// </summary>
	/// <param name="F">The force being applied in newtons.</param>
	/// <param name="x">The displacement from equilibrium position.</param>
	/// <returns>force constant, k</returns>
	static ld forceConstant(const ld F, const ld x)
	{
		return -(F / x);
	}

	/// <summary>
	/// calculates the projectile speed of a spring loaded gun.
	/// </summary>
	/// <param name="PEel">The elastic Potential Energy (J).</param>
	/// <param name="m">The mass of projectile (kg).</param>
	/// <returns>speed in m/s,converted from equivalent (J/kg)^.5</returns>
	static ld projectileSpeedSpringLoadedGun(const ld PEel, const ld m)
	{
		return pow((2.0 * PEel) / m, 1 / 2);
	}

	/// <summary>
	/// calculates the frequency for periodic motion which is the number
	/// of oscillation per unit time.
	/// </summary>
	/// <param name="T">The period T.</param>
	/// <returns>Frequency (Hz); 1 cycle per sec; 1/s</returns>
	static ld frequency(const ld T)
	{
		return 1.0 / T;
	}

	/// <summary>
	/// calculates the frequencies of a simple harmonic oscillator.
	/// </summary>
	/// <param name="m">The mass in kg.</param>
	/// <param name="k">The force constant.</param>
	/// <returns>frequency (Hz)</returns>
	static ld frequency_simpleHarmonicOscillator(const ld m, const ld k)
	{
		return (1.0 / (2.0 * _PI)) * sqrt(k / m);
	}

	/// <summary>
	/// calculates teh period T from the know frequency.
	/// </summary>
	/// <param name="f">The frequency in Hz.</param>
	/// <returns>time per period</returns>
	static ld period(const ld f)
	{
		return 1.0 / f;
	}

	/// <summary>
	/// Periods the simple harmonic oscillator.
	/// </summary>
	/// <param name="m">The m.</param>
	/// <param name="k">The k.</param>
	/// <returns></returns>
	static ld period_simpleHarmonicOscillator(const ld m, const ld k)
	{
		return (2.0 * _PI) * sqrt(m / k);
	}

	/// <summary>
	/// Calculates the displacements as a function of time(t).
	/// </summary>
	/// <param name="X">The Amplitude.</param>
	/// <param name="t">The total time.</param>
	/// <param name="T">The period T of the oscillation.</param>
	/// <returns>displacement</returns>
	static ld displacement_functionOfTime(const ld X, const ld t, const ld T)
	{
		return X * cos(((2.0 * _PI * t) / T) * RADIAN);
	}

	/// <summary>
	/// Calculates the velocity as a function of time.
	/// </summary>
	/// <param name="vMax">The v maximum is a function of Amplitude and
	/// period T.</param>
	/// <param name="t">The total time.</param>
	/// <param name="T">The period T.</param>
	/// <returns>velocity</returns>
	static ld velocity_functionOfTime(const ld vMax, const ld t, const ld T)
	{
		return -vMax * sin(((2.0 * _PI * t) / T) * RADIAN);
	}

	/// <summary>
	/// Calculates the acceleration as a function of time.
	/// </summary>
	/// <param name="k">The force constant.</param>
	/// <param name="X">The amplitude.</param>
	/// <param name="m">The mass.</param>
	/// <param name="t">The time.</param>
	/// <param name="T">The period T.</param>
	/// <returns>acceleration</returns>
	static ld acceleration_functionOfTime
	(const ld k, const ld X, const ld m, const ld t, const ld T)
	{
		return -((k * X) / m) * cos(((2.0 * _PI * t) / T) * RADIAN);
	}



	~Waves()
	{
		delete _wavePtr;
	}

};
#endif


