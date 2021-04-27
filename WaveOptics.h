#pragma once
#include "GeometricOptics.h"

#ifndef WAVEOPTICS_H
#define WAVEOPTICS_H
//α=224,ß=225,π=227,Σ=228,σ=229,µ=230,τ=231,Φ=232,Θ=233
//Ω=234,δ=235,∞=236,φ=237,ε=238,∩=239,≡=240

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
	/// <returns>the angle Θ</returns>
	static ld angleOf_nOrderOfInterference_doubleSlit(int m, const ld λ, const ld d);

	/// <summary>
	///Calculates the separation between two slits for which a wavelength of λ
	/// light has its first maximum at an angle of Θ∘.
	/// </summary>
	/// <param name="m">The order of interference: 0, 1, -1, 2, -2.....</param>
	/// <param name="λ">The wavelength.</param>
	/// <param name="Θ">The angle Θ.</param>
	/// <returns>separation between slits (units)</returns>
	static ld separationBetweenSlits_doubleSlit(const int m, const ld λ, const ld Θ);

	/// <summary>
	/// Calculates the distance between two slits that produces the first minimum
	/// for λ(m) of light at an angle of Θ∘
	/// </summary>
	/// <param name="m">The order of interference: 0, 1, -1, 2, -2....</param>
	/// <param name="λ">The w l.</param>
	/// <param name="Θ">The Θ.</param>
	/// <returns></returns>
	static ld separationBetweenSlits_destructive(const int m, const ld λ, const ld Θ);

	/// <summary>
	/// Calculates the wavelength of light that has its m minimum at an
	/// angle of Θ∘ when falling on double slits separated by d(units).
	/// </summary>
	/// <param name="m">The minimum.</param>
	/// <param name="d">The distance between slits.</param>
	/// <param name="Θ">The angle Θ.</param>
	/// <returns>the wavelength (units)</returns>
	static ld wavelengthAt_nMinimum_doubleSlit(const int m, const ld d, const ld Θ);

	/// <summary>
	/// Calculates the wavelength of light falling on double slits separated by
	/// d units, if the nM maximum is at an angle of Θ∘.
	/// </summary>
	/// <param name="nM">The order of maximum.</param>
	/// <param name="d">The distance between slits.</param>
	/// <param name="Θ">The angle Θ.</param>
	/// <returns>wavelength</returns>
	static ld wavelengthAt_nOrderMaximum_doubleSlit(const ld nM, const ld d, const ld Θ);

	/// <summary>
	/// Calculates the wavelength of light that has its m minimum at an angle
	/// of Θ∘ when it falls on a single slit of width D units.
	/// </summary>
	/// <param name="m">The order of minimum.</param>
	/// <param name="D">The width of slit.</param>
	/// <param name="Θ">The angle θ.</param>
	/// <returns>wavelength</returns>
	static ld wavelength_nMinSingleSlit(const ld m, const ld D, const ld Θ);

	/// <summary>
	/// Calculates the wavelength of light that has its m-order maximum at angle Θ,
	/// when falling on a diffraction grating that has a total of s slits per centimeter.
	/// </summary>
	/// <param name="m">The order of interference </param>
	/// <param name="Θ">The angle θ.</param>
	/// <param name="s">The number of slits per cm.</param>
	/// <returns>the wavelength</returns>
	static ld wavelengthOfLight_nOrderMaxGrating(const ld m, const ld Θ, const ld s);

	/// <summary>
	/// What is the highest-order maximum for light with a wavelength of λ
	/// falling on double slits separated by d units.
	/// </summary>
	/// <param name="d">The distance of separation between slits.</param>
	/// <param name="λ">The wavelength.</param>
	/// <param name="Θ">The angle Θ is default at 90 degrees which
	/// would be thrush hold angle that would cause a maximum order.</param>
	/// <returns>m= order of interference</returns>
	static ld highestOrderMaximum(const ld d, const ld λ, const ld Θ);

	/// <summary>
	/// Calculates angle at nM order maximum, if the first-order maximum for pure-wavelength light
	/// falling on a double slit is at an angle of Θ∘
	/// nM-order maximum
	/// </summary>
	/// <param name="nM">The n m.</param>
	/// <param name="Θ">The Θ.</param>
	/// <returns>angle of Θ at nM maximum</returns>
	static ld angleOf_nOrderMaximum(const ld nM, const ld Θ);

	/// <summary>
	/// Calculates the angle of the nMim minimum, if the first-order minimum
	/// for pure-wavelength light falling on a double slit is at an angle of Θ∘
	/// </summary>
	/// <param name="nMin">The n minimum.</param>
	/// <param name="Θ">The Θ.</param>
	/// <returns>angle Θ at n minimum</returns>
	static ld angleOf_nMinimum(const ld nMin, const ld Θ);

	/// <summary>
	/// Calculates the highest order maximum, If the first-order maximum for pure-wavelength
	/// light falling on a double slit at an angle of Θ.
	/// </summary>
	/// <param name="Θ">The first order maximum Θ.</param>
	/// <returns>highest order of maximum</returns>
	static ld highestOrderMaximum(const ld Θ);

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
	/// <returns>distance between fringes on screen</returns>
	static ld wavelengthFromFringes(const ld x, const ld Δy, const ld d);

	/// <summary>
	/// Waves the length at n order m fringe.
	/// </summary>
	/// <param name="m">The m.</param>
	/// <param name="y">The y.</param>
	/// <param name="x">The x.</param>
	/// <param name="d">The d.</param>
	/// <returns></returns>
	static ld waveLengthAt_nOrderMFringe(const ld m, const ld y, const ld x, const ld d);

	/// <summary>
	/// Young's double slit experiment is one of the quintessential experiments
	/// in physics. The availability of low cost lasers in recent years allows
	/// us to perform the double slit experiment rather easily in class.
	/// Your professor shines a green laser (λ units) on a double slit with a
	/// separation of d units. The diffraction pattern shines on the classroom
	/// wall x units away. Calculate the fringe separation between the m order
	/// and central fringe.
	/// </summary>
	/// <param name="m">The m.</param>
	/// <param name="x">The x.</param>
	/// <param name="λ">The λ.</param>
	/// <param name="d">The d.</param>
	/// <returns></returns>
	static ld fringeSeperationAt_nOrderMFromCenterDS(const ld m, const ld x, const ld λ, const ld d);

	/// <summary>
	/// Distances the between grating slits.
	/// </summary>
	/// <param name="slits">The slits.</param>
	/// <param name="totalLength">The total length in meters.</param>
	/// <returns>distance between the slits in meters</returns>
	static ld distanceBetweenGratingSlits(const ld slits, const ld totalLength);

	/// <summary>
	/// Calculates the distance between lines on a diffraction grating that
	/// produces a m-order maximum for λ-nm light at an angle of Θ∘.
	/// </summary>
	/// <param name="m">The order of interference.</param>
	/// <param name="λ">The wavelength λ.</param>
	/// <param name="Θ">The angle θ.</param>
	/// <returns>distance between lines in a diffraction grating</returns>
	static ld separationBetweenSlitsDiffractionGrating(const ld m, const ld  λ, const ld Θ);

	/// <summary>
	/// Calculates how many lines per centimeter are there on a diffraction
	/// grating that gives a m-order maximum for λ-m light at an angle of Θ.
	/// </summary>
	/// <param name="m">The order of interference.</param>
	/// <param name="λ">The wavelength λ.</param>
	/// <param name="Θ">The angle θ.</param>
	/// <returns>how many lines per centimeter in a diffraction grating</returns>
	static ld linesPer_cmDefractionGrating(const ld m, const ld λ, const ld Θ);

	/// <summary>
	/// Calculates the value of Θ with a order m interference.
	/// </summary>
	/// <param name="m">The order of interference.</param>
	/// <param name="d">The distance between slits.</param>
	/// <param name="λ">The wavelength .</param>
	/// <returns>the angle of Θ</returns>
	static ld thetaAtOrderOfInterference(const ld m, const ld d, const ld λ);

	/// <summary>
	/// Calculates the distance from a desired wave length to the central location
	/// </summary>
	/// <param name="x">The x-direction distance.</param>
	/// <param name="Θ">The angle Θ.</param>
	/// <returns>the length from the center to the where a wavelength fringe
	/// intersects on the screen</returns>
	static ld yDistanceApart(const ld x, const ld Θ);

	/// <summary>
	/// Calculates the width of a single slit.
	/// </summary>
	/// <param name="λ">The wavelength λ.</param>
	/// <param name="m">The order of interference m.</param>
	/// <param name="Θ">The angle theta θ.</param>
	/// <returns>width of slit</returns>
	static ld singleSlitWidth(const ld λ, const ld m, const ld Θ);

	/// <summary>
	/// Uses the Rayleigh criterion to solve for the minimum resolvable angle.
	/// between two objects where  λ is the wavelength of light and D is the
	/// diameter of aperture.
	/// </summary>
	/// <param name="λ">The wavelength λ.</param>
	/// <param name="D">The diameter of aperture.</param>
	/// <returns>the minimum angle between two objects that produce a resolvable
	/// image</returns>
	static ld rayleighEquation(const ld λ, const ld D);

	/// <summary>
	/// calculates the distance s between two object a distance r away and
	/// separated by an angle Θ.
	/// </summary>
	/// <param name="r">The distance away in any units.</param>
	/// <param name="Θ">The angle θ.</param>
	/// <returns>distance the two objects are apart</returns>
	static ld s_distance2Obj_rApart(const ld r, const ld Θ);

	/// <summary>
	/// Uses the Rayleigh criterion to calculate where resolution is still possible
	/// looking through a microscope for which the minimum angular separation where
	/// d is the distance between the specimen and the objective lens, and we have used the small
	/// angle approximation assuming that x is much smaller then d, so that
	/// that tanΘ = sin Θ == Θ. so x is the resolving power from the resolving
	/// power equation.
	/// </summary>
	/// <param name="x">The resolving power.</param>
	/// <param name="d">The distance between the specimen and the
	/// objective lens.</param>
	/// <returns>the minimum angular separation where two point objects can
	/// be resolved</returns>
	static ld minimumAngularSeparation(const ld x, const ld d);

	/// <summary>
	/// Calculates the resolving power of a microscope
	/// </summary>
	/// <param name="λ">The wavelength λ.</param>
	/// <param name="d">The  distance between the specimen and the
	/// objective lens.</param>
	/// <param name="D">The diameter of aperture.</param>
	/// <returns>resolving power</returns>
	static ld resolvingPower(const ld λ, const ld d, const ld D);

	/// <summary>
	/// Calculates the resolving  power for a microscope lens.
	/// </summary>
	/// <param name="λ">The wavelength λ.</param>
	/// <param name="n">The index of refraction between the lens and the object
	/// .</param>
	/// <param name="NA">The Numerical Aperture.</param>
	/// <returns></returns>
	static ld resolvingPower_microscopeLens(const ld λ, const ld n, const ld NA);

	/// <summary>
	/// Calculates the thinnest thickness of a non reflective lens coating.
	/// </summary>
	/// <param name="λ">The λ.</param>
	/// <param name="n">The index of refraction of film.</param>
	/// <returns>thinnest thickness of coating</returns>
	static ld thicknessOfNonReflectiveLensCoating(const ld λ, const ld n);

	/// <summary>
	/// Malus's law used to calculate the intensity of a polarized wave after
	/// passing through a filter. Where Io is the incident wave and Θ is the angle
	/// between the direction of polarization and the axis of a filter.
	/// </summary>
	/// <param name="Io">The intensity of polarized wave.</param>
	/// <param name="Θ">The θ.</param>
	/// <returns>intensity of wave</returns>
	static ld intensityOfTransmittedWave(const ld Io, const ld Θ);

	/// <summary>
	/// Waves the amplitude.
	/// </summary>
	/// <param name="E">The electric field amplitude.</param>
	/// <param name="Θ">The θ.</param>
	/// <returns></returns>
	static ld waveAmplitude(const ld E, const ld Θ);

	/// <summary>
	/// Calculates what angle is needed between the direction of polarized light
	/// and the axis of a polarizing filter to reduce its intensity by a specified
	/// percent. Use the percent value such as 90% you would enter 90 as the
	/// method argument and not .90.
	/// </summary>
	/// <param name="percentReduction">The percent reduction.</param>
	/// <returns>the angle the polarizing filter needs to be to filter
	/// out polarizing light waves.</returns>
	static ld angleForIntensityReductionByPolarizingFilter(const ld percentReduction);

	/// <summary>
	/// Calculates the angle using Brewster's law. tanΘ = n2/n1
	/// </summary>
	/// <param name="n1">The index of refraction for incident.</param>
	/// <param name="n2">The index of refraction for the medium of reflection.
	/// </param>
	/// <returns></returns>
	static ld angleByBrewstersLaw(const ld n1, const ld n2);

	/// <summary>
	/// Calculates index of refraction using Brewster's law solved for n1.
	/// </summary>
	/// <param name="n2">The index of refraction for the medium of reflection.
	/// </param>
	/// <param name="Θ">The angle θ.</param>
	/// <returns>The index of refraction for incident medium.</returns>
	static ld n1FromBrewstersLaw(const ld n2, const ld Θ);

	/// <summary>
	/// Calculates index of refraction using Brewster's law solved for n2.
	/// </summary>
	/// <param name="n1">The index of refraction for the incident medium.</param>
	/// <param name="Θ">The angle θ.</param>
	/// <returns>The index of refraction for the reflected medium.</returns>
	static ld n2FromBrewstersLaw(const ld n1, const ld Θ);

	/// <summary>
	/// Calculates the angle theta when the distance of x and height of y is
	/// known.
	/// </summary>
	/// <param name="x_len">Length of the x.</param>
	/// <param name="y_height">Height of the y.</param>
	/// <returns>angle theta</returns>
	static ld theta_toa_yx(const ld x_len, const ld y_height);

	/// <summary>
	/// light waves averaging  λ units in wavelength falls on a single slit of
	/// width D units.  Calculate the highest-order minimum produced.
	/// </summary>
	/// <param name="D">The d.</param>
	/// <param name="λ">The λ.</param>
	/// <returns></returns>
	static ld highestOrderMinimum_singleSlit(const ld D, const ld  λ);

	/// <summary>
	/// If a single slit produces a first minimum at Θ∘, Calculate at what
	/// angle the m order minimum is.
	/// </summary>
	/// <param name="m">The m-order minimum.</param>
	/// <param name="Θ">The angle theta of first order minimum.</param>
	/// <returns>angle at order m minimum</returns>
	static ld angleAt_nOrderMin(const ld m, const ld Θ);

	/// <summary>
	/// Angles at n order minimum single slit.
	/// </summary>
	/// <param name="m">The m.</param>
	/// <param name="D">The d.</param>
	/// <param name="λ">The λ.</param>
	/// <returns></returns>
	static ld angleAt_nOrderMinimum_singleSlit(const ld m, const ld D, const ld  λ);

	/// <summary>
	///	t = ((m+1/2)*λ)/(2*n)
	/// Working on your car you spill oil (index of refraction = 1.55) on the
	/// ground into a puddle of water (n = 1.33). You notice a rainbow pattern
	/// appear across the oil slick.Recalling the lessons you learned in physics
	/// class, you realize you can calculate where constructive
	/// interference occurs based on the thickness of the oil slick.
	/// (Assume that the average wavelength is 584 nm.)
	/// </summary>
	/// <param name="n">The index of refraction.</param>
	/// <param name="mStart">The m starting of constructive interference.</param>
	/// <param name="mEnd">The m end.</param>
	/// <param name="λ">The wavelength λ.</param>
	/// <returns>a map of values of where constructive interference occurs</returns>
	static map<int, ld> constructiveInterferenceRange(const ld n, const ld mStart, const ld mEnd, const ld λ);

	/// <summary>
	/// t = (m*λ)/(2*n)
	/// Working on your car you spill oil (index of refraction = 1.55) on the
	/// ground into a puddle of water (n = 1.33). You notice a rainbow pattern
	/// appear across the oil slick.Recalling the lessons you learned in physics
	/// class, you realize you can calculate where destructive
	/// interference occurs based on the thickness of the oil slick.
	/// (Assume that the average wavelength is 584 nm.)
	/// </summary>
	/// <param name="n">The n.</param>
	/// <param name="mStart">The m start.</param>
	/// <param name="mEnd">The m end.</param>
	/// <param name="λ">The λ.</param>
	/// <returns></returns>
	static map<int, ld> destructiveInterferenceRange(const ld n, const ld mStart, const ld mEnd, const ld λ);

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

inline ld WaveOptics::separationBetweenSlits_doubleSlit(const int m, const ld λ, const ld Θ)
{
	return (static_cast<ld>(m) * λ) / sin(Θ * RADIAN);
}

inline ld WaveOptics::separationBetweenSlits_destructive(const int m, const ld λ, const ld Θ)
{
	return (((m-1) + (1 / 2)) * λ) / sin(Θ*RADIAN);
}

inline ld WaveOptics::wavelengthAt_nMinimum_doubleSlit(const int m, const ld d, const ld Θ)
{
	return (d * sin(Θ * RADIAN)) / ((m - 1.0) + (1 / 2));
}

inline ld WaveOptics::wavelengthAt_nOrderMaximum_doubleSlit(const ld nM, const ld d, const ld Θ)
{
	return (d * sin(Θ * RADIAN)) / nM;
}

inline ld WaveOptics::wavelength_nMinSingleSlit(const ld m, const ld D, const ld Θ)
{
	return (D * sin(Θ * RADIAN)) / m;
}

inline ld WaveOptics::wavelengthOfLight_nOrderMaxGrating(const ld m, const ld Θ, const ld s)
{
	const ld d = distanceBetweenGratingSlits(s, 1.0 * SU.centi);
	return (d * sin(Θ*RADIAN)) / m;
}

inline ld WaveOptics::highestOrderMaximum(const ld d, const ld λ, const ld Θ = 90)
{
	return floor( (d * sin(Θ * RADIAN)) / λ);
}

inline ld WaveOptics::angleOf_nOrderMaximum(const ld nM, const ld Θ)
{
	return asin(nM * sin(Θ * RADIAN))*DEGREE;
}

inline ld WaveOptics::angleOf_nMinimum(const ld nMin, const ld Θ)
{
	return asin(((nMin - 1.0) + (1.0 / 2.0)) * sin(Θ * RADIAN));
}

inline ld WaveOptics::highestOrderMaximum(const ld Θ)
{
	return floor(1.0 / sin(Θ * RADIAN));
}

inline ld WaveOptics::distanceBetweenFringes(const ld x, const ld λ, const ld d)
{
	return (x * λ) / d;
}

inline ld WaveOptics::wavelengthFromFringes(const ld x, const ld Δy, const ld d)
{
	return (Δy * d) / x;
}

inline ld WaveOptics::waveLengthAt_nOrderMFringe(const ld m, const ld y, const ld x, const ld d)
{
	return (y * d) / (m * x);
}

inline ld WaveOptics::fringeSeperationAt_nOrderMFromCenterDS(const ld m, const ld x, const ld λ, const ld d)
{
	return (m * x * λ) / d;
}


inline ld WaveOptics::distanceBetweenGratingSlits(const ld slits, const ld totalLength)
{
	return totalLength / slits;
}

inline ld WaveOptics::separationBetweenSlitsDiffractionGrating(const ld m, const ld λ, const ld Θ)
{
	return (m * λ) / sin(Θ*RADIAN);
}

inline ld WaveOptics::linesPer_cmDefractionGrating(const ld m, const ld λ, const ld Θ)
{
	return floor(1.0/((m * λ) / sin(Θ * RADIAN))*(1.0/100.0));
}

inline ld WaveOptics::thetaAtOrderOfInterference(const ld m, const ld d, const ld λ)
{
	return asin((m * λ) / d)*DEGREE;
}

inline ld WaveOptics::yDistanceApart(const ld x, const ld Θ)
{
	return x * tan(Θ*RADIAN);
}

inline ld WaveOptics::singleSlitWidth(const ld λ, const ld m, const ld Θ)
{
	return (m * λ) / sin(Θ*RADIAN);
}

inline ld WaveOptics::rayleighEquation(const ld λ, const ld D)
{
	return 1.22 * (λ / D);
}

inline ld WaveOptics::s_distance2Obj_rApart(const ld r, const ld Θ)
{
	return r * Θ;
}

inline ld WaveOptics::minimumAngularSeparation(const ld x, const ld d)
{
	return x / d;
}

inline ld WaveOptics::resolvingPower(const ld λ, const ld d, const ld D)
{
	return 1.22 * ((λ * d) / D);
}

inline ld WaveOptics::resolvingPower_microscopeLens(const ld λ, const ld n, const ld NA)
{
	return .61 * ((λ * n) / NA);
}

inline ld WaveOptics::thicknessOfNonReflectiveLensCoating(const ld λ, const ld n)
{
	return ((λ / n) / 4.0);
}

inline ld WaveOptics::intensityOfTransmittedWave(const ld Io, const ld Θ)
{
	return Io * pow(cos(Θ), 2);
}

inline ld WaveOptics::waveAmplitude(const ld E, const ld Θ)
{
	return E * cos(Θ);
}

inline ld WaveOptics::angleForIntensityReductionByPolarizingFilter(const ld percentReduction)
{
	const ld I = (1.00 - (percentReduction / 100));
	return acos(sqrt(I / 1.0)) * DEGREE;
}

inline ld WaveOptics::angleByBrewstersLaw(const ld n1, const ld n2)
{
	return atan(n2 / n1)*DEGREE;
}

inline ld WaveOptics::n1FromBrewstersLaw(const ld n2, const ld Θ)
{
	return n2 / tan(Θ*RADIAN);
}

inline ld WaveOptics::n2FromBrewstersLaw(const ld n1, const ld Θ)
{
	return tan(Θ * RADIAN) * n1;
}

inline ld WaveOptics::theta_toa_yx(const ld x_len, const ld y_height)
{
	return atan(y_height / x_len);
}

inline ld WaveOptics::highestOrderMinimum_singleSlit(const ld D, const ld λ)
{
	return floor(D / λ);
}

inline ld WaveOptics::angleAt_nOrderMin(const ld m, const ld Θ)
{
	const ld ratio = sin(Θ * RADIAN)/1.0;
	return asin(m * ratio) * DEGREE;
}

inline ld WaveOptics::angleAt_nOrderMinimum_singleSlit(const ld m, const ld D, const ld λ)
{
	return asin((m * λ) / D) * DEGREE;
}

inline map<int, ld> WaveOptics::constructiveInterferenceRange(const ld n, const ld mStart, const ld mEnd, const ld λ)
{
	map<int, ld> results;
	for (int i = mStart, j = 1; i < mEnd; i++, j++)
	{
		ld val = ((i + .5) * λ / (2.0 * n));
		results[j] = val;
	}
	return results;
}

inline map<int, ld> WaveOptics::destructiveInterferenceRange(const ld n, const ld mStart, const ld mEnd, const ld λ)
{
	map<int, ld> results;
	for (int i = mStart, j = 1; i < mEnd; i++, j++)
	{
		ld val = ((i ) * λ / (2.0 * n));
		results[j] = val;
	}
	return results;
}


