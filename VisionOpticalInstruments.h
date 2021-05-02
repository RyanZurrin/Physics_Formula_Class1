#pragma once
#include "WaveOptics.h"

#ifndef VISION_OPTICAL_INSTRUMENTS_H
#define VISION_OPTICAL_INSTRUMENTS_H

static auto visionOpticInstrument_objectCount = 0;

class VisionOpticalInstruments :
	public WaveOptics
{

public:
	VisionOpticalInstruments* _visOpticPtr;

	VisionOpticalInstruments()
	{
		_visOpticPtr = nullptr;
		visOpticInstVar = 0.0;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	VisionOpticalInstruments(const VisionOpticalInstruments& t)
	{
		_visOpticPtr = t._visOpticPtr;
		visOpticInstVar = t.visOpticInstVar;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	VisionOpticalInstruments(VisionOpticalInstruments&& t) noexcept
	{
		_visOpticPtr = t._visOpticPtr;
		visOpticInstVar = t.visOpticInstVar;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	VisionOpticalInstruments& operator=(const VisionOpticalInstruments& t)
	{
		if (this != &t)
		{
			_visOpticPtr = t._visOpticPtr;
			visOpticInstVar = t.visOpticInstVar;
			countIncrease();
		}
		return *this;
	}

	static auto show_objectCount() { std::cout << "\n visOptInstrument object count: "
							<< visionOpticInstrument_objectCount << std::endl; }
	static auto get_objectCount() { return visionOpticInstrument_objectCount; }


	~VisionOpticalInstruments()
	{
		delete _visOpticPtr;
	}
	void setTemplateVar(ld var) { visOpticInstVar = var; }
	ld getTemplateVar() const { return visOpticInstVar; }

	/// <summary>
	/// Calculates the power of the eye when viewing an object d_o units away and
	/// with an image distance d_i units away. (this chapter uses the value of
	/// 2.00 cm for all the d_i values when dealing with problems relating to
	/// the eye)
	/// </summary>
	/// <param name="d_o">The object distance.</param>
	/// <param name="d_i">The image distance(default at 2.0*10^-2).</param>
	/// <returns>the power of the eye in diopters(D)</returns>
	template<typename T>
	static auto powerOfEye(const T d_o, const T d_i = 2.0*SU.CENTI);

	/// <summary>
	/// The print in many books averages h_o units in height. Calculate How high
	/// the image of the print on the retina when the book is held d_o units from
	/// the eye.
	/// </summary>
	/// <param name="h_o">The object height.</param>
	/// <param name="d_o">The object distance.</param>
	/// <param name="d_i">The image distance(default at 2.0*10^-2).</param>
	/// <returns>image height</returns>
	template<typename T>
	static auto imageHeight( const T h_o, const T d_o, const T d_i = 2.0*SU.CENTI);

	/// <summary>
	/// Suppose a certain person’s visual acuity is such that he can see objects
	/// clearly that form an image h_i units high on his retina. Calculate the maximum
	/// distance at which he can read the h_o units high letters on the side of
	/// an airplane?
	/// </summary>
	/// <param name="h_o">The object height.</param>
	/// <param name="h_i">The image height.</param>
	/// <param name="d_i">The image distance(default at 2.0*10^-2).</param>
	/// <returns>object distance</returns>
	template<typename T>
	static auto objectDistance(const T h_o, const T h_i, const T d_i = 2.0 * SU.CENTI);

	/// <summary>
	/// Calculate the far point of a person whose eyes have a relaxed
	/// power of P_ (D).
	/// </summary>
	/// <param name="P_">The power of the eye.</param>
	/// <param name="d_i">The image distance(default at 2.0*10^-2).</param>
	/// <returns>object distance</returns>
	template<typename T>
	static auto objectDistance_usingPower(const T P_, const T d_i = 2.00 * SU.CENTI);

	/// <summary>
	/// A severely myopic patient has a far point of d_o units. Calculate how many
	/// diopters the power of their eye should be reduced in laser vision
	/// correction to obtain normal distant vision.
	/// </summary>
	/// <param name="d_o">The d object distance.</param>
	/// <param name="d_i">The image distance(default at 2.0*10^-2).</param>
	/// <returns>power reduction in eye</returns>
	template<typename T>
	static auto eyePowerReductionLaserSurgery(const T d_o, const T d_i = 2.00 * SU.CENTI);







private:
	ld visOpticInstVar;
	static void countIncrease() { visionOpticInstrument_objectCount += 1; }
	static void countDecrease() { visionOpticInstrument_objectCount -= 1; }
};

#endif

template<typename T>
inline auto VisionOpticalInstruments::powerOfEye(const T d_o, const T d_i)
{
	return (1.0 / d_o) + (1 / d_i);//(D)
}

template<typename T>
inline auto VisionOpticalInstruments::imageHeight(const T h_o, const T d_o, const T d_i)
{
	return -(d_i * h_o) / d_o;
}

template<typename T>
inline auto VisionOpticalInstruments::objectDistance(const T h_o, const T h_i, const T d_i)
{
	return -(d_i * h_o) / h_i;
}

template<typename T>
inline auto VisionOpticalInstruments::objectDistance_usingPower(const T P_, const T d_i)
{
	return 1.0 / (P_ - (1.0 / d_i));
}

template<typename T>
inline auto VisionOpticalInstruments::eyePowerReductionLaserSurgery(const T d_o, const T d_i)
{
	return  (1.0 / d_i) - ((1.0 / d_o) + (1.0 / d_i));
}


