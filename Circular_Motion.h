#pragma once
// class for doing physics problems
// author: Ryan Zurrin
// last Modified: 10/10/2020
#ifndef CIRCULAR_MOTION_H
#define CIRCULAR_MOTION_H
#include <cmath>
//constant for the degrees in one radian 
const ld _RAD_ = 360 / (2 * _PI_);

class Circular_Motion
{
private:
	// pointer for the class object to use 
	Circular_Motion* _circlePtr;

	// radius variable of object
	ld  _radius_;

	// rotational angle variable of object
	ld  _rotationAngle_;

	// angular velocity variable of object
	ld  _angularVelocity_;

	// arc length variable of object
	ld  _arcLength_;

	// centripetal acceleration variable of object
	ld _centripetalAcceleration_;

public:


	// constructor
	Circular_Motion()
	{
		_circlePtr = nullptr;
		_radius_ = 0.0;
		_rotationAngle_ = 0.0;
		_angularVelocity_ = 0.0;
		_arcLength_ = 0.0;
		_centripetalAcceleration_ = 0.0;
	}
	Circular_Motion(ld radius, ld velocity)
	{
		_circlePtr = nullptr;
		_radius_ = radius;
		_angularVelocity_ = velocity / radius;
		_rotationAngle_ = 0.0;		
		_arcLength_ = 0.0;
		_centripetalAcceleration_ = (velocity * velocity)/(radius);
	}
	/*===================================================================
	 * conversion methods
	 */

	/**
	 * @brief Returns the revolutions in radians per second which is the angular velocity as well
	 * @param revMin revolutions per minute
	 * @returns revolutions in radians per second
	 */
	ld static revolutions_min_to_radians_second(const ld revMin)
	{
		return (revMin * 2 * PI) / 60;
	}

	/**
	 *  @brief Returns the ratio of the value to gravity
	 *  @param unit can be whatever you are dividing by gravity acceleration
	 *  @returns the gravity ratio
	 */
	ld static gravity_ratio(const ld unit)
	{
		return unit / _G_;
	}
	
	/*====================================================================
	 * static methods
	 */

	/**
	 * @brief Returns the angular velocity(w) given the radius and speed 
	 * @param radius from the center of the spin to the outer edge
	 * @param v is velocity of the object
	 * @returns angular velocity 
	 */
	ld static angular_velocity(const ld radius, const ld v)
	{
		return v / radius;
	}

	/**
 * @brief Returns the angular velocity(w) given the radius and speed
 * @param angleChange in total degrees the angle rotated in the given time.
 * 360 degrees in one full rotation and is 2PI radians
 * @param time is time is seconds
 * @returns angular velocity
 */
	ld static angular_velocity_t(const ld angleChange, const ld time)
	{
		return (angleChange/_RAD_) / time;
	}

	/**
	 * @brief Returns the centripetal acceleration using the radius and the angular velocity
	 * @param r radius
	 * @param w angular velocity in radian revolutions per second
	 * @returns the centripetal acceleration
	 */
	ld static centripetal_acceleration_W(const ld r, const ld w)
	{
		return r * (w * w);
	}

	/**
 * @brief Returns the centripetal acceleration using the radius and the velocity
 * @param r radius
 * @param v angular velocity in radian revolutions per second
 * @returns the centripetal acceleration
 */
	ld static centripetal_acceleration_V(const ld r, const ld v)
	{
		return (v * v) / r;
	}

	/**
	 * @brief Returns the centripetal force using mass velocity and radius of object
	 * @param mass in kg of object
	 * @param velocity or speed of object in m/s
	 * @param radius
	 * @returns the centripetal force
	 */
	ld static centripetal_force_V(const ld mass, const ld velocity, const ld radius)
	{
		return (mass * (velocity * velocity)) / (radius);
	}

	/**
	 * @brief Returns the centripetal force using the mass the angular velocity and radius
	 * @param mass in the mass in kg of object
	 * @param angularVelocity is the rotation in radians per second
	 * @param radius form center
	 * @returns the centripetal force
	 */
	ld static centripetal_force_W(const ld mass, const ld angularVelocity, const ld radius)
	{
		return mass * radius * (angularVelocity * angularVelocity);
	}

	/**
	 * @brief Returns the frictional coefficient given the velocity and radius
	 * @param v is the velocity
	 * @param r is the radius
	 * @returns the frictional coefficient
	 */
	ld static coefficient(const ld v, const ld r)
	{
		return (v * v) / (r * _G_);
	}

	/**
	 * @brief Returns the ideal speed to take going around a banked curve
	 * @param r is the radius of the curve
	 * @param angle of the embankment
	 * @returns the ideal velocity to take the corner
	 */
	ld static ideal_speed_banked_curve(const ld r, const ld angle)
	{
		return pow(r * _G_ * tan(angle * RADIAN), .5);
	}

	

	
	~Circular_Motion() = default;
};
#endif
