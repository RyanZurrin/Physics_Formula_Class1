#pragma once
// class for doing physics problems
// author: Ryan Zurrin
// last Modified: 9/13/2020

#ifndef PHYSICS_H
#define PHYSICS_H
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Physics
{
public:
	double displacement_start_finish(double start, double finish);
	double velocity_avg_DdT(double displacement, double time);
	double acceleration_VdT(double velocity, double time);
	double displacement_VxT(double velocity, double time);		
	double displacement_Vstart_Vend(double vStart, double vEnd);
	double final_velocity(double velocity, double acceleration, double time);	
	double displacement_accelerating_object(double acceleration, double time);
	double final_velocity_no_time(double v, double d, double a);
	double displacement_accelerating_object_PV(double p, double v, double a, double t);
	double displacement_halting_VdA(double x0, double sV, double fV, double acceleration);
	vector<double> time_using_quadratic(double a, double b, double c);
	double time_using_VdA(double a, double sV, double fV);


	
	
	


};


#endif // !PHYSICS_H
 
