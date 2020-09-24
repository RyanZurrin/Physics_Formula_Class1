#pragma once
// class for doing physics problems
// author: Ryan Zurrin
// last Modified: 9/17/2020
#ifndef PHYSICS_H
#define PHYSICS_H

#include <iostream>
//#include <iomanip>
#include <cmath>
#include <vector>

typedef long double ld;
//using namespace std;

// PI
const ld PI = acos(-1);

//gravitational acceleration force 9.80 m/s^2 average.
const ld GA = 9.80;

//Gravitational Constant 6.67408(31) * 10^(-11) * N 

// speed of light in a vacuum is 299792458 m/s
const ld C = 2.99792458*pow(10, 8);

class Physics
{	
public:
	ld val;
	std::vector<ld> vector_values;
	Physics();
	
	// length_2 - length_1
	ld displacement(ld length_1, ld length_2);
	
	//  velocity * time
	ld displacement_VxT(ld velocity, ld time);
	
	//((acceleration) * (time * time)) / 2
	ld displacement_accelerating_object(ld acceleration, ld time);
	
	// pos + (velocity * time) + (acceleration * (time * time)) / 2
	ld displacement_accelerating_object_PV(ld velocity, ld acceleration, ld time, ld pos = 0);
	
	// (((velocityFinal * velocityFinal) - (velocityStart * velocityStart)) / (2 * acceleration)) + pos;
	ld distance_VdA(ld pos, ld velocityStart, ld velocityFinal, ld acceleration) const;

	// (velocityStart + velocityEnd) / 2;
	ld velocity_vStart_plus_vEndD2(ld velocityStart, ld velocityEnd);

	// velocity + acceleration * time;
	ld velocity_final_using_time(ld velocity, ld acceleration, ld t);

	// sqrt(velocity + (2 * acceleration) * (displacement))
	ld velocity_final_no_time(ld velocity, ld displacement, ld acceleration);

	// displacement / time;
	ld velocity_avg_DdT(ld displacement, ld t);
	
	// sqrt((velocity * velocity) + (2 * (acceleration * (xYf - xY0))))
	ld velocity_kinematic_constant_a(ld xY0, ld xYf, ld velocity, ld acceleration) const; // 2.54
	
	// vChange / tChange;     change in velocity devided by change in time
	ld acceleration_avg(ld vChange, ld tChange);

	// (2 * (displacement)) / (time * time)
	ld acceleration_dispDtimeSqrd(ld displacement, ld time);

	// (velocityEnd * velocityEnd - velocityStart * velocityStart) / (2 * displacement)
	ld acceleration_vStart_vEndDdisplacement(ld velocityStart, ld velocityEnd, ld displacement)const;

	// total_distance/time;
	ld speed_avg_DdT(ld total_distance, ld time);
	
	// (velocityEnd - velocityStart) / acceleration    
	ld time_by_avgVdA(ld acceleration, ld velocityStart, ld velocityEnd);

	// distance / velocity
	ld time_by_DisTdV(ld distance, ld velocity);

	// sqrt((2*displacement)/acceleration)
	ld time_by_finalPos_and_acceleration(ld displacement, ld acceleration);

	// endTime - startTime 
	ld time_difference(ld startTime, ld endTime);

	//
	ld time_kinematic_rearranged(ld velocity, ld displacement, ld acceleration)const;
	
	// (y1 - y0) / (x1 - x0)
	ld slope_formula(ld y1, ld y0, ld x1, ld x0);

	// (2 * PI * radius) / (time / rotations)
	ld rotation_speed_2PIxRdT(ld radius, ld rotations, ld time);

	// (2 * PI * radius)/time
	ld rotation_avgVelocity_2PIxRdT_in_1_rotation(ld radius, ld time);

	ld multiple_of_gravity(ld value);
	
	std::vector<ld> time_using_quadratic(ld a1, ld b_velocity, ld c_displacement);
	std::vector<ld> pos_vel_falling_object_upDown(ld v, ld a, ld t, ld p = 0.0);

	void print() const;
	void print_vector_values();


};


#endif // !PHYSICS_H
 
