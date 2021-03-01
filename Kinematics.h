#pragma once
/**
 * @class Kinematics
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @dateBuilt  1/1/2021
 * @lastEdit 1/1/2021
 */

#ifndef KINEMATICS_H
#define KINEMATICS_H
#include <iostream>


static int kinematics_objectCount = 0;


/// <summary>
/// The vector values is for storing answers when there requires multiple
/// answers
/// </summary>
static std::vector<ld> vector_values = { 0.0,0.0,0.0,0.0 };
/// <summary>
/// Sets the vector.
/// </summary>
/// <param name="v">The v.</param>
static void setVector(vector<ld> v)
{
	vector_values = v;
}


/// <summary>
/// Returns the vector.
/// </summary>
/// <param name="v">The v.</param>
/// <returns></returns>
static vector<ld> return_vector(vector<ld>& v) { return v; }
/// <summary>
/// Shows the vector.
/// </summary>
static void showVector()
{
	for (auto it : vector_values)
	{
		std::cout << it << ", ";
	}
	std::cout << std::endl;
}

class Kinematics
{
private:
	static void countIncrease() { kinematics_objectCount += 1; }
	static void countDecrease() { kinematics_objectCount -= 1; }
public:
	Kinematics* _kinematicPtr;

	Kinematics()
	{
		_kinematicPtr = nullptr;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	Kinematics(const Kinematics& t)
	{
		_kinematicPtr = t._kinematicPtr;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	Kinematics(Kinematics&& t) noexcept
	{
		_kinematicPtr = t._kinematicPtr;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	Kinematics& operator=(const Kinematics& t)
	{
		if (this != &t)
		{
			_kinematicPtr = t._kinematicPtr;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\n kinematics object count: "
		<< kinematics_objectCount << std::endl; }
	static int get_objectCount() { return kinematics_objectCount; }


	//=========================================================================
	//chapter 2 formulas

	/**
	 * @brief Returns the displacement between two positions
	 * @param startPos starting position
	 * @param endPos ending position
	 * @returns displacement.
	 */
	static ld displacement(const ld startPos,const ld endPos)
	{ return endPos - startPos; }

	/**
	 * @brief Returns the displacement from knowing the velocity and time.
	 * @param velocity in m/s
	 * @param time in seconds
	 * @returns displacement.
	 */
	static ld displacement_VxT(const ld velocity, const ld time)
	{ return velocity * time; }

	/**
	 * method: displacement_accelerating_object(ld acceleration, ld time)
	 * arguments: acceleration m/s , time in s
	 * purpose: find the displacement of an accelerating object
	 * returns:	ld, displacement
	 */
	static ld displacement_accelerating_object(const ld acceleration, const ld time)
	{ return ((acceleration) * (time * time)) / 2; }

	/**
	 * method: displacement_accelerating_object_PV(ld acceleration, ld time)
	 * arguments: velocity, acceleration m/s , position = 0m default, time in s
	 * purpose: find the displacement of an accelerating object with a starting
	 * 			position and an initial velocity along with acceleration and a time
	 * returns:	ld, displacement
	 */
	static ld displacement_accelerating_object_PV(const ld velocity,
												  const ld acceleration,
												  const ld time,
												  const ld pos = 0)
	{ return pos + (velocity * time) + (acceleration * (time * time)) / 2; }

	/**
	 * @brief calculates the displacement using the kinematic formula
	 * X = Vi*t+ 1/2*a*t^2
	 * @param velocity in m/s
	 * @param acceleration in m/s^2
	 * @param time in s
	 */
	static ld displacement_using_kinematic(const ld velocity,
										   const ld acceleration,
										   const ld time)
	{
		return (velocity * time) + (acceleration * (time * time)) / 2;
	}

	 /// <summary>
	 /// calculate displacement for the distance to stop from moving object
	 /// </summary>
	 /// <param name="pos">The position.</param>
	 /// <param name="velocityStart">The velocity start.</param>
	 /// <param name="velocityFinal">The velocity final.</param>
	 /// <param name="acceleration">The acceleration.</param>
	 /// <returns>final displacement</returns>
	static ld distance_VdA(const ld pos, const ld velocityStart, const ld velocityFinal, const ld acceleration)
	{ return abs(((velocityFinal * velocityFinal) - (velocityStart * velocityStart)) / (2 * acceleration)) + pos; }

	/**
	 * method: velocity_vStart_plus_vEndD2(const ld velocityStart, const ld velocityEnd)
	 * arguments: vStart = starting velocity m/s, vEnd = ending velocity m/s
	 * purpose:	find the displacement when start and end velocity is know
	 * returns: ld, displacement
	 */
	static ld velocity_vStart_plus_vEndD2(const ld velocityStart, const ld velocityEnd)
	{ return (velocityStart + velocityEnd) / 2;	}

	/**
	 *@brief calculates the final velocity using the kinematic equation Vf = Vi + a*t
	 *@param initialVelocity is the initial velocity, many times this is zero
	 *@param acceleration is the acceleration of object
	 *@param time is amount of time taken
	 *@returns the final velocity
	 */
	static ld velocity_final_from_kinematic_time(const ld initialVelocity, const ld acceleration, const ld time)
	{	return initialVelocity + acceleration * time; }

	/**
	 *@brief calculates the final velocity using the kinematic formula vf^2 = vi^2 + 2*a*d
	 *@param initialVelocity m/s
	 *@param acceleration m/s^2
	 *@param displacement m
	 *@returns the final velocity
	 */
	static ld velocity_final_kinematic_no_time(const ld initialVelocity, const ld acceleration , const ld displacement)
	{ return sqrt(initialVelocity * initialVelocity + (2 * (acceleration * displacement))); }

	/**
	 * method: velocity_avg_DdT(ld displacement, ld time)   ss2.3 pg37
	 * arguments: displacement = avg displacement in m, time = total time  in s
	 * purpose: to calculate the average velocity using displacement divided by time
	 * returns: ld, average velocity
	 */
	static ld velocity_avg_DdT(const ld displacement, const ld time)
	{ return  displacement / time; }

	/**
	 * method: PhysicsWorld::velocity_falling_object_down(ld y, ld yf, ld v, ld a)
	 * arguments: y0 = start position,  yf = final position v = velocity, a = acceleration
	 * purpose: find the velocity of a falling object thrown downwards
	 * returns: ld, velocity
	 */
	static ld velocity_kinematic_constant_a(const ld xY0, const ld xYf, const ld velocity, const ld acceleration)
	{ return sqrt((velocity * velocity) + (2 * (acceleration * (xYf - xY0)))); }

	/**
	 * @brief calculates the final velocity using the kinematic formula Vf = Vi*t
	 * @param vi initial velocity
	 * @param t time
	 * @returns the final velocity
	 */
	static ld velocityFinal_kinematic(const ld vi, const ld t)
	{
		return vi * t;
	}

	/**
	 * method: acceleration_avg(ld vChange, ld tChange)   ss2.4  pg40
	 * arguments: vChange = average change in velocity in m/s, tChange = change in time in seconds
	 * purpose:	to find the average acceleration by dividing the avg velocity by the time
	 * returns: ld, average acceleration
	 */
	static ld acceleration_avg(const ld vChange, const ld tChange)
	{ return vChange / tChange; }

	/**
	 * method: acceleration_dispDtimeSqrd(ld displacement, ld time)
	 * arguments: 1)displacement 2)time
	 * purpose: this method can be used to calculate the acceleration of falling objects
	 * returns: ld, acceleration of object
	 */
	static ld acceleration_dispDtimeSqrd(const ld displacement, const ld time)
	{ return (2 * (displacement)) / (time * time); }

	/**
	 * method: acceleration_vStart_vEndDdisplacement(ld velocityStart, ld velocityEnd, ld displacement)const
	 * arguments: velocity start, velocity end, total displacement
	 * purpose: finds the acceleration using the starting and ending velocity and total displacement as known values
	 * returns: ld, acceleration of object
	 */
	static ld acceleration_vStart_vEndDdisplacement(const ld velocityStart, const ld velocityEnd, const ld displacement)
	{ return (velocityEnd * velocityEnd - velocityStart * velocityStart) / (2 * displacement); }

	/**
	 * method: speed_avg_DdT(ld total_distance, ld time)   ss2.3 pg37
	 * arguments: displacement = avg displacement in m, time = total time  in s
	 * purpose: to calculate the average velocity using displacement divided by time
	 * returns: ld, average velocity
	 */
	static ld speed_avg_DdT(const ld total_distance, const ld time)
	{ return abs(total_distance / time); }

	/**
	 * method: time_by_avgVdA(ld acceleration, ld velocityStart, ld velocityEnd)
	 * arguments: a = acceleration, sV = start velocity(default 0), fV = final velocity
	 * purpose: calculate time with know acceleration and final velocity end point
	 * returns: ld, time
	 */
	static ld time_by_avgVdA(const ld acceleration, const ld velocityStart, const ld velocityEnd)
	{ return (velocityEnd - velocityStart) / acceleration; }

	/**
	 * method: time_by_DisTdV(ld distance, ld velocity)
	 * arguments: distance , average velocity
	 * purpose: find the velocity of a falling object thrown downwards
	 * returns: ld, velocity
	 */
	static ld time_by_DisTdV(const ld distance, const ld velocity)
	{ return distance / velocity; }

	/**
	 * method: time_finalPos_acceleration(ld displacement, ld acceleration)
	 * arguments: displacement of object, acceleration of object
	 * purpose: find how long it takes an object with a known acceleration to travel a know distance
	 * returns: ld, time to accelerate a distance
	 */
	static ld time_by_finalPos_acceleration(const ld displacement, const ld acceleration)
	{ return sqrt((2 * displacement) / acceleration); }

	/**
	 * method: time(ld startTime, ld endTime)
	 * arguments: y = startTime = beginning time in seconds, endTime = endTime in seconds
	 * purpose: find the amount of time between two periods
	 * returns: ld, difference in two times
	 */
	static ld time_difference(const ld startTime, const ld endTime)
	{ return endTime - startTime; }

	/**
	 * method: time_kinematic_rearranged(ld velocity, ld y0, ld acceleration) const
	 * arguments: velocity, y0 = position from 0, acceleration
	 * purpose: find the amount of time between two periods
	 * returns: ld, difference in two times
	 */
	static ld time_kinematic_rearranged(const ld velocity, const ld displacement, const ld acceleration)
	{ return (-(velocity)-sqrt((velocity * velocity) - 2 * (acceleration) * (displacement))) / (acceleration); }

	/**
	 * method: slope_formula(ld y1, ld y0, ld x1, ld x0)
	 * arguments: y1 , y0, x1, x0
	 * purpose:	the general slope equation of (y1 - y0)/(x1 - x0)
	 *  to find the slope of a line between two points
	 * returns: ld, slope of line between two points
	 */
	static ld slope_formula(const ld y1, const ld y0, const ld x1, const ld x0)
	{ return (y1 - y0) / (x1 - x0);	}

	/**
	 * method: rotation_speed_2PIxRdT(ld radius, ld rotations, ld time)
	 * arguments: radius = length in m from center of rotation
	 *	rotations = how many rotations in a time period
	 *	time = time units
	 * purpose: find the speed of a spinning object, such as fan blade
	 * returns: average speed of spinning object
	 */
	static ld rotation_speed_2PIxRdT(const ld radius, const ld rotations, const ld time)
	{ return (2.0 * _PI_ * radius) / (time / rotations); }

	/**
	 * method: rotation_avgVelocity_2PIxRdT_in_1_rotation(ld radius, ld time)
	 * arguments: radius , time = time for one rotation
	 * purpose: find average velocity of a spinning object
	 * returns: ld, average velocity
	 */
	static ld rotation_avgVelocity_2PIxRdT_in_1_rotation(const ld radius, const ld time)
	{ return (2.0 * _PI_ * radius) / time; }

	/**
	 * @brief Returns the conversion of given value divided by the acceleration of gravity on earth, 9.80 m/s^2
	 * @param value the value to find the multiples of gravity of
	 * returns: g's
	 */
	static ld conversion_multiple_of_gravity(const ld value)
	{ return value / GA; }

	/**
	 * method: time_using_quadratic(ld a, ld b, ld c)
	 * arguments: a1 = default to 1, b_velocity = constant velocity, c_displacement = total distance to travel
	 * purpose: calculate the time of a merging object when velocity and displacement is know
	 * returns: ld, total time
	 */
	std::vector<ld> time_using_quadratic(ld a1, ld b_velocity, ld c_displacement)const
	{
		vector_values[0] = (-b_velocity + sqrt((b_velocity * b_velocity) - 4 * a1 * c_displacement)) / (2 * a1);
		vector_values[1] = (-b_velocity - sqrt((b_velocity * b_velocity) - 4 * a1 * c_displacement)) / (2 * a1);

		return vector_values;
	}

	/**
	 * method: pos_vel_falling_object_upDown(double p, double v, double a, double t)
	 * arguments: p = position (0),  v = velocity, a = acceleration, t = time is s
	 * purpose: this method will fill a vector with four pieces of data in order from the right to left it
	 *			is: time, position, velocity, acceleration. use the print_vector_values() to see contents.
	 * returns: ld, vector of the time, position, velocity, acceleration.
	 */
	std::vector<ld> pos_vel_falling_object_upDown(ld v, ld a, ld t, ld p = 0.0)const
	{
		ld temp;
		vector_values[0] = t;
		//solution for Position:
		Kinematics obj;

		vector_values[1] = obj.displacement_accelerating_object_PV(v, a, t, p);
		//Solution for Velocity:

		temp = obj.velocity_final_from_kinematic_time(v, a, t);
		vector_values[2] = temp;

		vector_values[3] = a;
		//this->show_vector_values();

		return vector_values;
	}
	/// <summary>
	/// calculates projectile range
	/// </summary>
	/// <param name="velocity">The velocity.</param>
	/// <param name="angleTheta">The angle theta.</param>
	/// <returns>range of projectile</returns>
	static ld range_projectile_level_ground(const ld velocity, const ld angleTheta)
	{ return  ((velocity * velocity) * sin(2 * angleTheta * RADIAN) / (GA));	}

	 /// <summary>
	 /// calculates the angle theta of a projectile
	 /// </summary>
	 /// <param name="distance">The distance.</param>
	 /// <param name="velocity">The velocity.</param>
	 /// <returns>theta</returns>
	static ld projectile_theta(const ld distance, const ld velocity)
	{
		return (asinh(distance * _Ga_) / (velocity * velocity)) / 2;
	}

	 /// <summary>
	 /// calculates the time a projectile with an initial velocity and angle
	 /// take to reach the same level from which it was launched, forms a parabolic curve
	 /// (2* launchVelocity*sin(angleTheta))/(-GA);
	 /// </summary>
	 /// <param name="launchVelocity">The launch velocity.</param>
	 /// <param name="angleTheta">The angle theta.</param>
	 /// <returns>air time</returns>
	static ld time_for_projectile_to_reach_level(ld launchVelocity, ld angleTheta)
	{
		return (2 * launchVelocity * sin(angleTheta)) / (GA);
	}

	/// <summary>
/// calculates the air time from an initial velocity of 0
/// </summary>
/// <param name="displacement">The total displacement.</param>
/// <returns>time is seconds in air</returns>
static ld air_time_initial_velocity0_y0(ld displacement)
{
	return sqrt((-2*(displacement))/GA);
}


/// <summary>
/// calculates the initial velocity of the horizontal component
/// </summary>
/// <param name="y0">The initial starting height.</param>
/// <param name="displacement">The displacement.</param>
/// <returns></returns>
static ld velocity_initial_horizontal_component(ld y0, ld displacement)
{
	return sqrt((-GA/(-2 * y0)))* displacement;
}

/**
 * method: velocity_final_vertical_component(ld y0, ld yf = 0) const
 * arguments: y0 = starting height, yf = final vertical component default = 0
 * purpose:	calculates the final vertical component
 * returns: ld, final vertical velocity
 */
static ld velocity_vertical_component(ld y0, ld yf)
{
	return -sqrt(2 * (-GA) * (yf - y0));
}


/**
 * method: velocity_final_vertical_component(ld y0, ld yf = 0) const
 * arguments: y0 = starting height, yf = final vertical component default = 0
 * purpose:	calculates the final vertical component
 * returns: ld, final vertical velocity
 */
static vector<ld> final_projectile_velocity_vector(ld velocityY, ld velocityX)
{
	vector_values[0] = sqrt(velocityY * velocityY + velocityX * velocityX);
	vector_values[1] = atan(velocityY / velocityX)*DEGREE;
	return vector_values;
}

/**NOT WORKING RIGHT
 * method: velocity_soccer_kick(ld toGoal, ld height_at_goal, ld angle) const
 * arguments: distance to goal, height ball is at goal, and initial angle of kick
 * purpose:	calculates the final velocity of both component vectors
 * returns: ld, magnitude of final velocity vector
 */
static ld velocity_soccer_kick(ld toGoal, ld height_at_goal, ld angle)
{
	return sqrt(pow(horizontal_velocity_using_distance_angle_height(toGoal, height_at_goal, angle), 2) +
		pow(vertical_velocity_by_Xvelocity_with_angle(horizontal_velocity_using_distance_angle_height(toGoal, height_at_goal, angle), angle), 2));
}

/**
 * method: horizontal_velocity_using_distance_angle_height(ld targetDistance, ld targetHeight, ld angle, ld acceleration)
 * arguments: distance, height, angle, acceleration = default is -9.8
 * purpose:	finds x component velocity
 * returns: ld, velocity of X component
 */
static ld horizontal_velocity_using_distance_angle_height(ld targetDistance, ld targetHeight, ld angle, ld acceleration = GA)
{
	return targetDistance * sqrt(-acceleration/((2 * (targetDistance * tan(angle*RADIAN) - targetHeight))));
}

static ld vertical_velocity_by_Xvelocity_with_angle(ld xVelocity, ld angle)
{
	return xVelocity * tan(angle*RADIAN);
}


 /// <summary>
 /// uses quadratic formula to return two angles in a vector, the larger angle
 /// is the best angle to use
 /// </summary>
 /// <param name="launchVelocity">The launch velocity.</param>
 /// <param name="releaseHeight">Height of the ball at its release.</param>
 /// <param name="hoopDistance">The hoop distance from shot.</param>
 /// <returns>angle to shoot</returns>
static vector<ld> basketball_angles(ld launchVelocity, ld releaseHeight, ld hoopDistance)
{
	const ld hoopHeight = 3.05; //meters
	ld a = (((-GA) * (hoopDistance * hoopDistance)) / (2 * (launchVelocity * launchVelocity)));
	ld b = -hoopDistance;
	ld c = ((hoopHeight - releaseHeight) + a);
	vector_values[0] = atan(-((b)+sqrt((b * b) - 4 * a * c)) / (2 * a))*DEGREE;
	vector_values[1] = atan(-((b)-sqrt((b * b) - 4 * a * c)) / (2 * a))*DEGREE;

	return vector_values;
}




	~Kinematics()
	{
		delete _kinematicPtr;
	}

};
#endif


