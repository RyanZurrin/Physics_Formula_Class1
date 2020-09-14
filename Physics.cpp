#include "Physics.h"


/**
 * function: displacement_start_finish(double start, double finish);  ss2.1 pg32
 * arguments: start = starting position in m, finish = ending position in m
 * purpose: using the staring position and ending position in meters it calculates the
 *          total displacement (shortest distance between the two positions.)
 * returns : double, displacement of the two positions in m. m = meters s = seconds
 */
double Physics::displacement_start_finish(double start, double finish)
{
	double displacement = finish - start; // x = xf - x0; <- how you see in most text book f and 0 are sub script
	return displacement;
}

/**
 * function: velocity_avg_DdT(double displacement, double time)   ss2.3 pg37
 * arguments: displacement = avg displacement in m, time = total time  in s
 * purpose: to calculate the average velocity using displacement divided by time
 * returns: double, average velocity 
 */
double Physics::velocity_avg_DdT(double displacement, double time)
{
	double velocity = displacement / time;
	return velocity;
}

/**
 * function: acceleration_VdT(double velocity, double time)    ss2.4  pg40
 * arguments: velocity = average velocity in m/s, time = total time is seconds
 * purpose:	to find the average acceleration by dividing the velocity by the time
 * returns: double, average acceleration 
 */
double Physics::acceleration_VdT(double velocity, double time)
{
	double a = (velocity / time);
	return a;
}


/**
 * function: Physics::displacement_VxT(double velocity, double time)
 * arguments: velocity = avg velocity m/s, time = in s
 * purpose:	find the displacement from knowing the velocity and time. 
 * returns: double, displacement.  
 */
double Physics::displacement_VxT(double velocity, double time)
{
	double displacement = velocity * time;
	return displacement;
}

/**
 * function: displacement_Vstart_Vend(double vStart, double vEnd)
 * arguments: vStart = starting velocity m/s, vEnd = ending velocity m/s
 * purpose:	find the displacement when start and end velocity is know
 * returns: double, disp;acement
 */
double Physics::displacement_Vstart_Vend(double vStart, double vEnd)
{
	return (vStart + vEnd) / 2;
}

/**
 * function: final_velocity(double velocity, double acceleration, double time)
 * arguments: initial velocity, amount of acceleration, and time 
 * purpose:	calculate the final velocity using acceleration and time
 * returns: double, final velocity
 */
double Physics::final_velocity(double velocity, double acceleration, double time)
{
	return velocity + acceleration * time;
}

/**
 * function: displacement_accelerating_object(double acceleration, double time)
 * arguments: acceleration m/s , time in s
 * purpose: find the displacement of an accelerating object
 * returns:	double, displacement
 */
double Physics::displacement_accelerating_object(double acceleration, double time)
{
	double d = ((acceleration) * (time * time)) / 2;

	return d;
}

/**
 * function: displacement_accelerating_object_PV(double acceleration, double time)
 * arguments: position, velocity, acceleration m/s , time in s
 * purpose: find the displacement of an accelerating object with a starting 
 * 			position and an initial velocity along with acceleration and a time
 * returns:	double, displacement
 */
double Physics::displacement_accelerating_object_PV(double p, double v, double a, double t)
{
	return p + (v * t) * ((a) * (t * t)) / 2;
}


/**
 * function: displacement_halting_VdA(double velocity, double acceleration)
 * arguments: x0 = starting position(0), Sv = starting velocity, fV = ending velocity(0) a = acceleration
 * purpose: calculate displacement for the distance to stop from moving object
 * returns: double, final displacement
 */
double Physics::displacement_halting_VdA(double x0 ,double sV, double fV, double acceleration)
{
	double val = (fV * fV) - (sV * sV);
	double divisor = 2 * acceleration;
	return val/divisor + x0;
}


/**
 * function: time_using_quadratic(double a, double b, double c)
 * arguments: a1 = default to 1, b_velocity = constant velocity, c_displacement = total distance to travel
 * purpose: calculate the time of a merging object when velocity and displacement is know
 * returns: double, total time
 */
vector<double> Physics::time_using_quadratic(double a1, double b_velocity, double c_displacement)
{
	vector<double> results = { 0.0, 0.0 };
	results[0] = (-b_velocity + sqrt((b_velocity * b_velocity) - 4 * a1 * c_displacement)) / 2 * a1;
	results[1] = (-b_velocity - sqrt((b_velocity * b_velocity) - 4 * a1 * c_displacement)) / 2 * a1;
	return results;
}


/**
 * function: time_using_VdA(double a, double sV, double fV)
 * arguments: a = acceleration, sV = start velocity(default 0), fV = final velocity
 * purpose: calculate time with know acceleration and final velocity end point
 * returns: double, time
 */
double Physics::time_using_VdA(double a, double sV, double fV)
{
	return (fV - sV) / a;
}

/**
 * function: final_velocity_no_time(double v, double d, double a)
 * arguments: v = velocity, d = displacement, a = acceleration
 * purpose: calculate the final velocity using acceleration and time
 * returns: double, final velocity
 */
double Physics::final_velocity_no_time(double v, double d, double a)
{
	return sqrt(v + (2 * a) * (d));
}
