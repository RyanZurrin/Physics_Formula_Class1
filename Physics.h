#pragma once
// class for doing physics problems
// author: Ryan Zurrin
// last Modified: 9/17/2020
#ifndef PHYSICS_H
#define PHYSICS_H

#include <iostream>
#include <cmath>
#include <vector>
#include "Vector3D.h"

typedef long double ld;
//using namespace std;

// PI
//const ld PI = acos(-1);

//gravitational acceleration force 9.80 m/s^2 average.
const ld GA = -9.80;

//Gravitational Constant 6.67408(31) * 10^(-11) * N 

// speed of light in a vacuum is 299792458 m/s
const ld C = 2.99792458*pow(10, 8);

class Physics
{	
public:
	ld val;
	std::vector<ld> vector_values;
	Physics();
	void print() const;
	void print_vector_values(); 	
	//============================================================================
	//chapter 2 formulas	
	
	/**
	 * method: displacement(ld length_1, ld length_2)
	 * arguments: length_1 = starting position, length_2 = ending position
	 * purpose:	find the displacement between two positions
	 * returns: ld, displacement.
	 */
	ld static displacement(const ld length_1,const ld length_2)
	{ return length_2 - length_1; }
	
	/**
	 * method: Physics::displacement_VxT(ld velocity, ld time)
	 * arguments: velocity = avg velocity m/s, time = in s
	 * purpose:	find the displacement from knowing the velocity and time.
	 * returns: ld, displacement.
	 */
	ld static displacement_VxT(const ld velocity, const ld time)
	{ return velocity * time; }
	
	/**
	 * method: displacement_accelerating_object(ld acceleration, ld time)
	 * arguments: acceleration m/s , time in s
	 * purpose: find the displacement of an accelerating object
	 * returns:	ld, displacement
	 */
	ld static displacement_accelerating_object(const ld acceleration, const ld time)
	{ return ((acceleration) * (time * time)) / 2; }
	
	/**
	 * method: displacement_accelerating_object_PV(ld acceleration, ld time)
	 * arguments: velocity, acceleration m/s , position = 0m default, time in s
	 * purpose: find the displacement of an accelerating object with a starting
	 * 			position and an initial velocity along with acceleration and a time
	 * returns:	ld, displacement
	 */
	ld static displacement_accelerating_object_PV(const ld velocity, const ld acceleration, const ld time, const ld pos = 0)
	{ return pos + (velocity * time) + (acceleration * (time * time)) / 2; }
	
	/**
	 * method: displacement_halting_VdA(ld velocity, ld acceleration)
	 * arguments: x0 = starting position(0), Sv = starting velocity, fV = ending velocity(0) a = acceleration
	 * purpose: calculate displacement for the distance to stop from moving object
	 * returns: ld, final displacement
	 */
	ld static distance_VdA(const ld pos, const ld velocityStart, const ld velocityFinal, const ld acceleration)
	{ return abs(((velocityFinal * velocityFinal) - (velocityStart * velocityStart)) / (2 * acceleration)) + pos; }
	
	/**
	 * method: velocity_vStart_plus_vEndD2(const ld velocityStart, const ld velocityEnd)
	 * arguments: vStart = starting velocity m/s, vEnd = ending velocity m/s
	 * purpose:	find the displacement when start and end velocity is know
	 * returns: ld, displacement
	 */
	ld static velocity_vStart_plus_vEndD2(const ld velocityStart, const ld velocityEnd)
	{ return (velocityStart + velocityEnd) / 2;	}

	/**
	 * method: velocity_final_using_time(ld velocity, ld acceleration, ld time)
	 * arguments: initial velocity, amount of acceleration, and time
	 * purpose:	calculate the final velocity using acceleration and time
	 * returns: ld, final velocity
	 */
	ld static velocity_final_using_time(const ld velocity, const ld acceleration, const ld time)
	{	return velocity + acceleration * time; }

	/**
	 * method: final_velocity_no_time(ld v, ld d, ld a)
	 * arguments: v = velocity, d = displacement, a = acceleration
	 * purpose: calculate the final velocity using velocity, displacement and acceleration
	 * returns: ld, final velocity
	 */
	ld static velocity_final_no_time(const ld velocity, const ld displacement, const ld acceleration)
	{ return sqrt(velocity * velocity + (2 * (acceleration * displacement))); }

	/**
	 * method: velocity_avg_DdT(ld displacement, ld time)   ss2.3 pg37
	 * arguments: displacement = avg displacement in m, time = total time  in s
	 * purpose: to calculate the average velocity using displacement divided by time
	 * returns: ld, average velocity
	 */
	ld static velocity_avg_DdT(const ld displacement, const ld time)
	{ return  displacement / time; }
	
	/**
	 * method: Physics::velocity_falling_object_down(ld y, ld yf, ld v, ld a)
	 * arguments: y0 = start position,  yf = final position v = velocity, a = acceleration
	 * purpose: find the velocity of a falling object thrown downwards
	 * returns: ld, velocity
	 */
	ld static velocity_kinematic_constant_a(const ld xY0, const ld xYf, const ld velocity, const ld acceleration)
	{ return sqrt((velocity * velocity) + (2 * (acceleration * (xYf - xY0)))); }
	
	/**
	 * method: acceleration_avg(ld vChange, ld tChange)   ss2.4  pg40
	 * arguments: vChange = average change in velocity in m/s, tChange = change in time in seconds
	 * purpose:	to find the average acceleration by dividing the avg velocity by the time
	 * returns: ld, average acceleration
	 */
	ld static acceleration_avg(const ld vChange, const ld tChange)
	{ return vChange / tChange; }


	/**
	 * method: acceleration_dispDtimeSqrd(ld displacement, ld time)
	 * arguments: 1)displacement 2)time
	 * purpose: this method can be used to calculate the acceleration of falling objects
	 * returns: ld, acceleration of object
	 */
	ld static acceleration_dispDtimeSqrd(const ld displacement, const ld time)
	{ return (2 * (displacement)) / (time * time); }

	/**
	 * method: acceleration_vStart_vEndDdisplacement(ld velocityStart, ld velocityEnd, ld displacement)const
	 * arguments: velocity start, velocity end, total displacement
	 * purpose: finds the acceleration using the starting and ending velocity and total displacement as known values
	 * returns: ld, acceleration of object
	 */
	ld static acceleration_vStart_vEndDdisplacement(const ld velocityStart, const ld velocityEnd, const ld displacement)
	{ return (velocityEnd * velocityEnd - velocityStart * velocityStart) / (2 * displacement); }

	/**
	 * method: speed_avg_DdT(ld total_distance, ld time)   ss2.3 pg37
	 * arguments: displacement = avg displacement in m, time = total time  in s
	 * purpose: to calculate the average velocity using displacement divided by time
	 * returns: ld, average velocity
	 */
	ld static speed_avg_DdT(const ld total_distance, const ld time)
	{ return abs(total_distance / time); }
	
	/**
	 * method: time_by_avgVdA(ld acceleration, ld velocityStart, ld velocityEnd)
	 * arguments: a = acceleration, sV = start velocity(default 0), fV = final velocity
	 * purpose: calculate time with know acceleration and final velocity end point
	 * returns: ld, time
	 */
	ld static time_by_avgVdA(const ld acceleration, const ld velocityStart, const ld velocityEnd)
	{ return (velocityEnd - velocityStart) / acceleration; }

	/**
	 * method: time_by_DisTdV(ld distance, ld velocity)
	 * arguments: distance , average velocity
	 * purpose: find the velocity of a falling object thrown downwards
	 * returns: ld, velocity
	 */
	ld static time_by_DisTdV(const ld distance, const ld velocity)
	{ return distance / velocity; }

	// sqrt((2*displacement)/acceleration)
	ld time_by_finalPos_and_acceleration(ld displacement, ld acceleration);

	/**
	 * method: time(ld startTime, ld endTime)
	 * arguments: y = startTime = beginning time in seconds, endTime = endTime in seconds
	 * purpose: find the amount of time between two periods
	 * returns: ld, difference in two times
	 */
	ld static time_difference(const ld startTime, const ld endTime)
	{ return endTime - startTime; }

	// (-(v)-sqrt((v*v)-2*(a)*(d)))/(d)
	ld static time_kinematic_rearranged(const ld velocity, const ld displacement, const ld acceleration);
	
	// (y1 - y0) / (x1 - x0)
	ld static slope_formula(const ld y1, const ld y0, const ld x1, const ld x0);

	// (2 * PI * radius) / (time / rotations)
	ld static rotation_speed_2PIxRdT(const ld radius, const ld rotations, const ld time);

	// (2 * PI * radius)/time
	ld static rotation_avgVelocity_2PIxRdT_in_1_rotation(const ld radius, const ld time);

	// value/GA;
	ld multiple_of_gravity(ld value);

	//(-b + sqrt((b * b) - 4 * a1 * c)) / (2 * a1);
	//(-b - sqrt((b * b) - 4 * a1 * c)) / (2 * a1);
	std::vector<ld> time_using_quadratic(ld a1, ld b_velocity, ld c_displacement);

	//
	std::vector<ld> pos_vel_falling_object_upDown(ld v, ld a, ld t, ld p = 0.0);
	
	//=================================================================================
	// chapter 3 formulas

	// ((velocity*velocity)*sin(2* angleTheta)/(GA))
	ld projectile_range_level_ground(ld velocity, ld angleTheta)const;

	// (2* launchVelocity*sin(angleTheta))/(-GA);
	ld time_for_projectile_to_reach_level(ld launchVelocity, ld angleTheta)const;

	// sqrt((-2*(displacement))/-GA)
	ld air_time_initial_velocity0_y0(ld displacement)const;

	//  sqrt((-GA/(-2 * y0)))* displacement
	ld velocity_initial_horizontal_component(ld y0, ld displacement)const;

	//velocity_final_vertical_component(ld y0) const
	ld velocity_vertical_component(ld y0, ld yf = 0)const;

	// sqrt(velocityY * velocityY + velocityX * velocityX);
	// atan(velocityY / velocityX) * DEGREE;
	std::vector<ld> final_projectile_velocity_vector(ld velocityY, ld velocityX);

	// sqrt(pow(horizontal_velocity_using_distance_angle_height(toGoal,height_at_goal, angle), 2) +
	// pow(vertical_velocity_by_Xvelocity_with_angle(horizontal_velocity_using_distance_angle_height(toGoal, height_at_goal, angle), angle), 2))
	ld velocity_soccer_kick(ld toGoal, ld height_at_goal, ld angle)const;
	
	// targetDistance * sqrt((abs(acceleration)/((2 * (targetDistance * (tan(angle)*DEGREE) - targetHeight)))))
	ld horizontal_velocity_using_distance_angle_height(ld targetDistance, ld targetHeight, ld angle, ld acceleration = GA)const;

	// xVelocity * tan(angle*RADIAN)
	ld vertical_velocity_by_Xvelocity_with_angle(ld xVelocity, ld angle)const;

	//  atan(-((b)+sqrt((b * b) - 4 * a * c)) / (2 * a))*DEGREE;
	//  atan(-((b)-sqrt((b * b) - 4 * a * c)) / (2 * a)) * DEGREE;
	std::vector<ld> basketball_angles(ld launchVelocity, ld releaseHeight, ld hoopDistance);

	//=================================================================================
	// chapter 4 formulas

	/**
	 * method: netForce(const ld totalForces, const ld totalFriction)
	 * arguments: 1)total forces  2)total friction
	 * purpose:	calculates the forces total including frictions
	 * returns: ld net force
	 */
	ld static netForce(const ld totalForces, const ld totalFriction)
	{ return totalForces - totalFriction; }
	
	/**
	 * method: gravitational_force_on_mass(ld mass) const
	 * arguments: mass
	 * purpose:	applies the force of gravity on a mass to give the weight
	 * returns: ld weight
	 */
	ld static gravitational_force_on_mass(const ld mass)
	{ return mass * GA; }
	
	/**
	 * method: newtons_second_law_for_force(ld mass, ld acceleration) 
	 * arguments: ld mass, ld acceleration
	 * purpose:	uses Newtons second law of motion to calculate the force of a something
	 * returns: ld, force
	 */
	ld static newtons_second_law_for_force(const ld mass, const ld acceleration)
	{ return mass * acceleration; }

	/**
	 * method: newtons_second_law_for_acceleration(ld netForce, ld mass) const
	 * arguments: netForce, mass
	 * purpose:	calculates the acceleration due to a force
	 * returns: ld, acceleration
	 */
	ld static newtons_second_law_for_acceleration(const ld netForce, const ld mass)
	{ return netForce / mass; }

	/**
	 * method: newtons_second_law_for_mass(ld netForce, ld acceleration) const
	 * arguments: netForce, acceleration
	 * purpose:calculates the mass of an object from the force and acceleration
	 * returns: ld, mass
	 */
	ld static newtons_second_law_for_mass(ld netForce, ld acceleration)
	{ return netForce / acceleration; }

	/**
	 * method: drag_force(const ld appliedForce, const ld mass, const ld acceleration)
	 * arguments: 1)appliedForce 2)mass 3)acceleration
	 * purpose:calculates the drag or resistance
	 * returns: ld, drag
	 */
	ld static drag_force(const ld appliedForce, const ld mass, const ld acceleration)
	{ return appliedForce - (mass * acceleration); }

};


#endif // !PHYSICS_H
 
