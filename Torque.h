#pragma once
/**
 * @class Torque
 * @details class for composition with Physics class to help in solving complex physics problems
 * @author Ryan Zurrin
 * @date   10/26/2020
 */
#ifndef TORQUE_H
#define TORQUE_H

class Torque
{
public:
	Torque* _torquePtr;

	/**
	 * constructor
	 */
	Torque()
	{
		_torquePtr = nullptr;
	}

	
	/**
	 * @brief Returns the magnitude of torque
	 * @param r is the distance from the pivot point to the point where the force
	 * is applied
	 * @param F is the magnitude of the force
	 * @param theta is the angle between the force and the vector directed form the
	 * point of application to the pivot point
	 */
	ld static torque(const ld r, const ld F, const ld theta)
	{
		return r * F * sin(theta * RADIAN);
	}




	/**
	 * destructor
	 */
	~Torque()
	{
		delete _torquePtr;
	}
};
#endif

