#pragma once
#ifndef ELECTROMAGNETICWAVES_H
#define ELECTROMAGNETICWAVES_H

#include "ElectroMagneticInduction.h"

static int emWaves_objectCount = 0;

// speed of light in a vacuum is 299792458 m/s
const ld _c_ = 2.99792 * pow(10, 8);

class ElectromagneticWaves :
	public ElectroMagneticInduction
{

public:
	ElectromagneticWaves* _emWavesPtr;


	ElectromagneticWaves()
	{
		_emWavesPtr = nullptr;
		emWaveVar = 0.0;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	ElectromagneticWaves(const ElectromagneticWaves& t)
	{
		_emWavesPtr = t._emWavesPtr;
		emWaveVar = t.getMagVar();
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	ElectromagneticWaves(ElectromagneticWaves&& t) noexcept
	{
		_emWavesPtr = t._emWavesPtr;
		emWaveVar = t.getEmWaveVar();
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	ElectromagneticWaves& operator=(const ElectromagneticWaves& t)
	{
		if (this != &t)
		{
			_emWavesPtr = t._emWavesPtr;
			emWaveVar = getEmWaveVar();
			countIncrease();
		}
		return *this;
	}

	void setEmWaveVar(ld var) { emWaveVar = var; }
	ld getEmWaveVar() const { return emWaveVar; }

	static void show_objectCount() { std::cout << "\n emWaves object count: "
										<< emWaves_objectCount << std::endl; }
	static int get_objectCount() { return emWaves_objectCount; }

	static ld speedOfElectroMagneticWaves();

	/// <summary>
	/// B fields the strength electromagnetic wave
	/// </summary>
	/// <param name="E">The e field strength.</param>
	/// <returns>electromagnetic B field strength</returns>
	static ld B_fieldStrength_emWave(const ld E);

	/// <summary>
	/// magnetic field strength of em wave. E field
	/// </summary>
	/// <param name="B">The B field strength of an emWave.</param>
	/// <returns>electromagnetic E field strength</returns>
	static ld magneticFieldStrength_emWave(const ld B);

	/// <summary>
	/// The maximum magnetic field strength of an electromagnetic field is B
	/// Calculate the maximum electric field strength if the wave is traveling
	/// in a medium in which the speed of the wave is percentOfc of c
	/// </summary>
	/// <param name="B">The B field strength of an emWave.</param>
	/// <param name="percentOfc">The percent ofc.</param>
	/// <returns></returns>
	static ld magneticFieldStrength_emWavew(const ld B, const ld percentOfc);

	/// <summary>
	/// Calculates the wave length of a em wave having a frequency of f.
	/// </summary>
	/// <param name="f">The frequency.</param>
	/// <returns>the wave length (m)</returns>
	static ld waveLength_emWave(const ld f);

	/// <summary>
	/// Calculates the frequency an em wave having a wave length of waveLen.
	/// </summary>
	/// <param name="waveLen">Length of the wave.</param>
	/// <returns>frequency(Hz)</returns>
	static ld frequency_emWave(const ld waveLen);

	/// <summary>
	/// A radar used to detect the presence of aircraft receives a pulse that
	/// has reflected off an object t(s) after it was transmitted. What is
	/// the distance from the radar station to the reflecting object?
	/// </summary>
	/// <param name="t">The time in seconds.</param>
	/// <returns>distance from radar station (m)</returns>
	static ld distanceFromRadarStation(const ld t);

	/// <summary>
	/// Determine the amount of time it takes for X-rays to travel
	/// a distance of d(m).
	/// </summary>
	/// <param name="d">The distance.</param>
	/// <returns>time is seconds</returns>
	static ld timeFor_emWaveToTravelDistance(const ld d);

	/// <summary>
	/// What is the echo time for a car d m from a Highway Police radar
	/// unit?
	/// </summary>
	/// <param name="d">The distance.</param>
	/// <returns>time for radar echo to return</returns>
	static ld echoTime(const ld d);

	/// <summary>
	/// Find the intensity of an electromagnetic wave having a peak magnetic
	/// field strength of B(T)
	/// </summary>
	/// <param name="B">The magnetic field strength.</param>
	/// <returns>Intensity ( W/m^2)</returns>
	static ld intensityAvg_emWave_B(const ld B);

	/// <summary>
	/// A university communications satellite dish receives
	/// TV signals that have a maximum electric field strength
	/// (for one channel) of E V/m . What is the intensity of this wave?
	/// </summary>
	/// <param name="E">The maximum electric field strength.</param>
	/// <returns>intensity W/m^2</returns>
	static ld intensityAvg_emWave_E(const ld E);

	/// <summary>
	/// A d(m)-diameter university communications satellite dish receives
	/// TV signals that have a intensity of I
	/// (for one channel). What is the power received by the antenna?
	/// </summary>
	/// <param name="d">The d.</param>
	/// <param name="I">The I.</param>
	/// <returns>power in (W)</returns>
	static ld powerReceivedByAntenna(const ld d, const ld I);

	/// <summary>
	/// Astronomers determine that a particular star in our galaxy is moving
	/// toward Earth at a speed of v m/s with respect to the Earth.
	/// If Earth receives a wavelength 𝜆 = receivedWL m from this star, what
	/// was the wavelength emitted by the star?
	/// </summary>
	/// <param name="v">The speed.</param>
	/// <param name="receivedWL">The received wavelength.</param>
	/// <returns></returns>
	static ld waveLength_dopplerEffect(const ld v, const ld receivedWL);

	~ElectromagneticWaves()
	{
		delete _emWavesPtr;
	}
private:
	ld emWaveVar;
	static void countIncrease() { emWaves_objectCount += 1; }
	static void countDecrease() { emWaves_objectCount -= 1; }
};

#endif
//=============================================================================
//in-line class Implementation
inline ld ElectromagneticWaves::speedOfElectroMagneticWaves()
{
	return 1.0 / sqrt (_Uo_ * _E0_);
}

inline ld ElectromagneticWaves::B_fieldStrength_emWave(const ld E)
{
	return E / _c_;
}

inline ld ElectromagneticWaves::magneticFieldStrength_emWave(const ld B)
{
	return _c_ * B;
}

inline ld ElectromagneticWaves::magneticFieldStrength_emWavew(const ld B, const ld percentOfc)
{
	return percentOfc * _c_ * B;
}

inline ld ElectromagneticWaves::waveLength_emWave(const ld f)
{
	return _c_ / f;
}

inline ld ElectromagneticWaves::frequency_emWave(const ld waveLen)
{
	return _c_ / waveLen;
}

inline ld ElectromagneticWaves::distanceFromRadarStation(const ld t)
{
	return (_c_ * t) / 2.0;
}

inline ld ElectromagneticWaves::timeFor_emWaveToTravelDistance(const ld d)
{
	return d / _c_;
}

inline ld ElectromagneticWaves::echoTime(const ld d)
{
	return (2.0 * d) / _c_;
}

inline ld ElectromagneticWaves::intensityAvg_emWave_E(const ld E)
{
	return (_c_ * _E0_ * (E * E)) / 2.0;
}

inline ld ElectromagneticWaves::powerReceivedByAntenna(const ld d, const ld I)
{
	return (I * _PI * (d * d)) / 4.0;
}

inline ld ElectromagneticWaves::waveLength_dopplerEffect(const ld v, const ld recievedWL)
{
	return recievedWL / (1.0 - (v / _c_));
}

inline ld ElectromagneticWaves::intensityAvg_emWave_B(const ld B)
{
	return (_c_ * (B * B)) / (2.0 * _Uo_);
}
