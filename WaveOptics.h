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



private:
	ld waveOpticsVar;
	static void countIncrease() { waveOptics_objectCount += 1; }
	static void countDecrease() { waveOptics_objectCount -= 1; }

};

#endif
