#pragma once
/**
 * @class FluidStatics
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   10/15/2020
 */
#ifndef FLUIDSTATICS_H
#define FLUIDSTATICS_H

class FluidStatics
{
private:
public:
	FluidStatics* _fluidPtr;
	struct Density
	{
		const double aluminum = 2.7;
		
	}density;

	FluidStatics()
	{
		_fluidPtr = nullptr;
	}

	~FluidStatics()
	{
		delete _fluidPtr;
	}
};

#endif
