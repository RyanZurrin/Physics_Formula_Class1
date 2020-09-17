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
	ld displacement_start_finish(ld start, ld finish);
	ld velocity_avg_DdT(ld displacement, ld t);
	ld acceleration_VdT(ld velocity, ld t);
	ld displacement_VxT(ld velocity, ld t);		
	ld displacement_Vstart_Vend(ld v0, ld vf);
	ld final_velocity(ld velocity, ld acceleration, ld t);	
	ld displacement_accelerating_object(ld a, ld t);
	ld final_velocity_no_time(ld v, ld d, ld a);
	ld displacement_accelerating_object_PV(ld p, ld v, ld a, ld t);
	ld displacement_halting_VdA(ld x0, ld V0, ld Vf, ld a);	
	ld time_using_VdA(ld a, ld sV, ld fV);
	ld velocity_falling_object_down(ld y0, ld yf, ld v, ld a);
	ld acceleration_dispDtimeSqrd(ld y0, ld yf, ld v, ld t);
	std::vector<ld> time_using_quadratic(ld a, ld b, ld c);
	std::vector<ld> pos_vel_falling_object_upDown(ld p, ld v, ld a, ld t);

	void print() const;
	void print_vector_values();
	
	
	
	


};


#endif // !PHYSICS_H
 
