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




private:
	ld visOpticInstVar;
	static void countIncrease() { visionOpticInstrument_objectCount += 1; }
	static void countDecrease() { visionOpticInstrument_objectCount -= 1; }
};

#endif
