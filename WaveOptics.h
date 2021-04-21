#pragma once
#include "GeometricOptics.h"

#ifndef WAVEOPTICS_H
#define WAVEOPTICS_H


static int waveOptics_objectCount = 0;

class WaveOptics :
	public GeometricOptics
{

public:
	WaveOptics* _waveOpticPtr;
	ld _var;

	WaveOptics()
	{
		_waveOpticPtr = nullptr;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	WaveOptics(const WaveOptics& t)
	{
		_waveOpticPtr = t._waveOpticPtr;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	WaveOptics(WaveOptics&& t) noexcept
	{
		_waveOpticPtr = t._waveOpticPtr;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	WaveOptics& operator=(const WaveOptics& t)
	{
		if (this != &t)
		{
			_waveOpticPtr = t._waveOpticPtr;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout <<"\n wave optics object count: "
							      << waveOptics_objectCount << std::endl; }
	static int get_objectCount() { return waveOptics_objectCount; }


	~WaveOptics()
	{
		delete _waveOpticPtr;
	}
	void setGeometricOpticsVar(ld var) { waveOpticsVar = var; }
	ld getGeometricOpticsVar() const { return waveOpticsVar; }


	/// <summary>
	/// Calculates the wavelength in a medium when the λ in a vacuum is λ and
	/// the index of refraction of the medium is n.
	/// </summary>
	/// <param name="λ">The wavelength in a vacuum.</param>
	/// <param name="n">The index of refraction.</param>
	/// <returns>the wavelength in a medium</returns>
	static ld wavelengthInMedium(const ld λ, const ld n);

	/// <summary>
	/// Calculates the wavelength of medium.
	/// </summary>
	/// <param name="n">The index of refraction of medium.</param>
	/// <param name="f">The frequency.</param>
	/// <returns>the wavelength of medium (Hz)</returns>
	static ld wavelengthOfMedium(const ld n, const ld f);

	/// <summary>
	/// Show that when light passes from nTop to nBottom, its wavelength changes
	/// to some value times its original value.
	/// </summary>
	/// <param name="nTop">The index of refraction of medium in.</param>
	/// <param name="nBottom">The index of refraction medium moving too.</param>
	/// <returns>ratio of wavelengths</returns>
	static ld wavelength_ratioOf2IndexOfRefractions(const ld nTop, const ld nBottom);

	/// <summary>
	/// Distances traveled by a wave front.
	/// </summary>
	/// <param name="v">The wave speed.</param>
	/// <param name="t">The time.</param>
	/// <returns></returns>
	static ld distanceTraveledByWaveFront(const ld v, const ld t);

	/// <summary>
	/// Calculates the index of refraction of a material for which the wavelength
	/// of light is xTimes its value in a vacuum? prints out medium if found
	/// </summary>
	/// <param name="xTimes">The x times.</param>
	/// <returns>index of refraction</returns>
	static ld indexOfRefractionFromRatioPrintMedium(const ld xTimes);

	/// <summary>
	/// Analysis of an interference effect in a clear solid shows that the
	/// wavelength of light in the solid is 329 nm. Knowing this light comes
	/// from a He-Ne laser and has a wavelength of 633 nm in air, is the
	/// substance zircon or diamond?
	/// </summary>
	/// <param name="λMedium">The w l medium.</param>
	/// <param name="λ2">The w l2.</param>
	/// <returns></returns>
	static ld indexOfRefractionFromWavelengths(const ld λMedium, const ld λ2);

	/// <summary>
	/// Calculates the angle of the n order of maximum for λ wavelength
	/// of light falling on double slits separated by d (m)?
	/// </summary>
	/// <param name="m">The order of interference: 0, 1, -1, 2, -2.....</param>
	/// <param name="λ">The wavelength.</param>
	/// <param name="d">The distance between slits.</param>
	/// <returns>the angle theta</returns>
	static ld angleOf_nOrderOfInterference_doubleSlit(int m, const ld λ, const ld d);

	/// <summary>
	///Calculates the separation between two slits for which a wavelength of λ
	/// light has its first maximum at an angle of theta∘.
	/// </summary>
	/// <param name="m">The order of interference: 0, 1, -1, 2, -2.....</param>
	/// <param name="λ">The wavelength.</param>
	/// <param name="theta">The angle theta.</param>
	/// <returns>separation between slits (units)</returns>
	static ld separationBetweenSlits_doubleSlit(const int m, const ld λ, const ld theta);

	/// <summary>
	/// Calculates the distance between two slits that produces the first minimum
	/// for λ(m) of light at an angle of theta∘
	/// </summary>
	/// <param name="m">The order of interference: 0, 1, -1, 2, -2....</param>
	/// <param name="λ">The w l.</param>
	/// <param name="theta">The theta.</param>
	/// <returns></returns>
	static ld separationBetweenSlits_destructive(const int m, const ld λ, const ld theta);

	/// <summary>
	/// Calculates the wavelength of light that has its m minimum at an
	/// angle of theta∘ when falling on double slits separated by d(units).
	/// </summary>
	/// <param name="m">The minimum.</param>
	/// <param name="d">The distance between slits.</param>
	/// <param name="theta">The angle theta.</param>
	/// <returns>the wavelength (units)</returns>
	static ld wavelengthAt_nMinimum_doubleSlit(const int m, const ld d, const ld theta);

	/// <summary>
	/// Calculates the wavelength of light falling on double slits separated by
	/// d units, if the nM maximum is at an angle of theta∘.
	/// </summary>
	/// <param name="nM">The order of maximum.</param>
	/// <param name="d">The distance between slits.</param>
	/// <param name="theta">The angle theta.</param>
	/// <returns>wavelength</returns>
	static ld wavelengthAt_nOrderMaximum_doubleSlit(const ld nM, const ld d, const ld theta);

	/// <summary>
	/// What is the highest-order maximum for light with a wavelength of λ
	/// falling on double slits separated by d units.
	/// </summary>
	/// <param name="d">The distance of separation between slits.</param>
	/// <param name="λ">The wavelength.</param>
	/// <param name="theta">The angle theta is default at 90 degrees which
	/// would be thrush hold angle that would cause a maximum order.</param>
	/// <returns>m= order of interference</returns>
	static ld highestOrderMaximum(const ld d, const ld λ, const ld theta);

	/// <summary>
	/// Calculates angle at nM order maximum, if the first-order maximum for pure-wavelength light
	/// falling on a double slit is at an angle of theta∘
	/// nM-order maximum
	/// </summary>
	/// <param name="nM">The n m.</param>
	/// <param name="theta">The theta.</param>
	/// <returns>angle of theta at nM maximum</returns>
	static ld angleOf_nOrderMaximum(const ld nM, const ld theta);

	/// <summary>
	/// Calculates the angle of the nMim minimum, if the first-order minimum
	/// for pure-wavelength light falling on a double slit is at an angle of theta∘
	/// </summary>
	/// <param name="nMin">The n minimum.</param>
	/// <param name="theta">The theta.</param>
	/// <returns>angle theta at n minimum</returns>
	static ld angleOf_nMinimum(const ld nMin, const ld theta);

	/// <summary>
	/// Calculates the highest order maximum, If the first-order maximum for pure-wavelength
	/// light falling on a double slit at an angle of theta.
	/// </summary>
	/// <param name="theta">The first order maximum theta.</param>
	/// <returns>highest order of maximum</returns>
	static ld highestOrderMaximum(const ld theta);

	/// <summary>
	/// Using Δy=x*λ*d, calculate the distance between fringes for 633-nm light
	/// falling on double slits separated by 0.0800 mm, located 3.00 m from a
	/// screen as in Figure
	/// </summary>
	/// <param name="x">The x.</param>
	/// <param name="λ">The w l.</param>
	/// <param name="d">The d.</param>
	/// <returns></returns>
	static ld distanceBetweenFringes(const ld x, const ld λ, const ld d);

	/// <summary>
	/// Calculate the wavelength of light that produces fringes Δy units
	/// apart on a screen x units from double slits separated by d units.
	/// </summary>
	/// <param name="x">The x.</param>
	/// <param name="Δy">The δy.</param>
	/// <param name="d">The d.</param>
	/// <returns></returns>
	static ld wavelengthFromFringes(const ld x, const ld Δy, const ld d);




private:
	ld waveOpticsVar;
	static void countIncrease() { waveOptics_objectCount += 1; }
	static void countDecrease() { waveOptics_objectCount -= 1; }

};

#endif
//=============================================================================
//in-line class Implementation


inline ld WaveOptics::wavelengthInMedium(const ld λ, const ld n)
{
	return λ / n;//Hz
}

inline ld WaveOptics::wavelengthOfMedium(const ld n, const ld f)
{
	return _c_ / (n * f);
}

inline ld WaveOptics::wavelength_ratioOf2IndexOfRefractions(const ld nTop, const ld nBottom)
{
	return nTop / nBottom;
}

inline ld WaveOptics::distanceTraveledByWaveFront(const ld v, const ld t)
{
	return v * t;
}

inline ld WaveOptics::indexOfRefractionFromRatioPrintMedium(const ld xTimes)
{
	const ld val = 1.0 / xTimes;
	const ld scale = 0.001;
	const ld val2 = floor(val / scale + .5) * scale;
	printMedium(refractions, val2);
	return val2;
}

inline ld WaveOptics::indexOfRefractionFromWavelengths(const ld λMedium, const ld λ2)
{
	const ld temp = λ2 / λMedium;
	const ld scale = 0.001;
	const ld n = floor(temp / scale + .5) * scale;
	printMedium(refractions, n);
	return n;
}

inline ld WaveOptics::angleOf_nOrderOfInterference_doubleSlit(int m, const ld λ, const ld d)
{
	return asin((static_cast<ld>(m) * λ) / d) * DEGREE;
}

inline ld WaveOptics::separationBetweenSlits_doubleSlit(const int m, const ld λ, const ld theta)
{
	return (static_cast<ld>(m) * λ) / sin(theta * RADIAN);
}

inline ld WaveOptics::separationBetweenSlits_destructive(const int m, const ld λ, const ld theta)
{
	return (((m-1) + (1 / 2)) * λ) / sin(theta*RADIAN);
}

inline ld WaveOptics::wavelengthAt_nMinimum_doubleSlit(const int m, const ld d, const ld theta)
{
	return (d * sin(theta * RADIAN)) / ((m - 1.0) + (1 / 2));
}

inline ld WaveOptics::wavelengthAt_nOrderMaximum_doubleSlit(const ld nM, const ld d, const ld theta)
{
	return (d * sin(theta * RADIAN)) / nM;
}

inline ld WaveOptics::highestOrderMaximum(const ld d, const ld λ, const ld theta = 90)
{
	return floor( (d * sin(theta * RADIAN)) / λ);
}

inline ld WaveOptics::angleOf_nOrderMaximum(const ld nM, const ld theta)
{
	return asin(nM * sin(theta * RADIAN))*DEGREE;
}

inline ld WaveOptics::angleOf_nMinimum(const ld nMin, const ld theta)
{
	return asin(((nMin - 1.0) + (1.0 / 2.0)) * sin(theta * RADIAN));
}

inline ld WaveOptics::highestOrderMaximum(const ld theta)
{
	return floor(1.0 / sin(theta * RADIAN));
}

inline ld WaveOptics::distanceBetweenFringes(const ld x, const ld λ, const ld d)
{
	return (x * λ) / d;
}

inline ld WaveOptics::wavelengthFromFringes(const ld x, const ld Δy, const ld d)
{
	return (Δy * d) / x;
}


