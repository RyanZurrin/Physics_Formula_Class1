#include "Physics.h"


Physics::Physics()
{	
	this->val = 0.0;
	this->vector_values = { 0.0,0.0,0.0,0.0 };
}

/**
 * function: displacement_start_finish(ld start, ld finish);  ss2.1 pg32
 * arguments: start = starting position in m, finish = ending position in m
 * purpose: using the staring position and ending position in meters it calculates the
 *          total displacement (shortest distance between the two positions.)
 * returns : ld, displacement in m
 */
ld Physics::displacement_start_finish(ld start, ld finish)
{
	ld displacement = finish - start; // x = xf - x0; <- how you see in most text book f and 0 are sub script
	return displacement;
}

/**
 * function: velocity_avg_DdT(ld displacement, ld time)   ss2.3 pg37
 * arguments: displacement = avg displacement in m, time = total time  in s
 * purpose: to calculate the average velocity using displacement divided by time
 * returns: ld, average velocity 
 */
ld Physics::velocity_avg_DdT(ld displacement, ld time)
{
	ld velocity = displacement / time;
	return velocity;
}

/**
 * function: acceleration_VdT(ld velocity, ld time)    ss2.4  pg40
 * arguments: velocity = average velocity in m/s, time = total time is seconds
 * purpose:	to find the average acceleration by dividing the velocity by the time
 * returns: ld, average acceleration 
 */
ld Physics::acceleration_VdT(ld velocity, ld time)
{
	ld a = (velocity / time);
	return a;
}


/**
 * function: Physics::displacement_VxT(ld velocity, ld time)
 * arguments: velocity = avg velocity m/s, time = in s
 * purpose:	find the displacement from knowing the velocity and time. 
 * returns: ld, displacement.  
 */
ld Physics::displacement_VxT(ld velocity, ld time)
{
	ld displacement = velocity * time;
	return displacement;
}

/**
 * function: displacement_Vstart_Vend(ld vStart, ld vEnd)
 * arguments: vStart = starting velocity m/s, vEnd = ending velocity m/s
 * purpose:	find the displacement when start and end velocity is know
 * returns: ld, disp;acement
 */
ld Physics::displacement_Vstart_Vend(ld vStart, ld vEnd)
{
	return (vStart + vEnd) / 2;
}

/**
 * function: final_velocity(ld velocity, ld acceleration, ld time)
 * arguments: initial velocity, amount of acceleration, and time 
 * purpose:	calculate the final velocity using acceleration and time
 * returns: ld, final velocity
 */
ld Physics::final_velocity(ld velocity, ld acceleration, ld time)
{
	return velocity + acceleration * time;
}

/**
 * function: displacement_accelerating_object(ld acceleration, ld time)
 * arguments: acceleration m/s , time in s
 * purpose: find the displacement of an accelerating object
 * returns:	ld, displacement
 */
ld Physics::displacement_accelerating_object(ld acceleration, ld time)
{
	ld d = ((acceleration) * (time * time)) / 2;

	return d;
}

/**
 * function: displacement_accelerating_object_PV(ld acceleration, ld time)
 * arguments: position, velocity, acceleration m/s , time in s
 * purpose: find the displacement of an accelerating object with a starting 
 * 			position and an initial velocity along with acceleration and a time
 * returns:	ld, displacement
 */
ld Physics::displacement_accelerating_object_PV(ld p, ld v, ld a, ld t)
{
	return p + (v * t) + (a * (t * t)) / 2;
}


/**
 * function: displacement_halting_VdA(ld velocity, ld acceleration)
 * arguments: x0 = starting position(0), Sv = starting velocity, fV = ending velocity(0) a = acceleration
 * purpose: calculate displacement for the distance to stop from moving object
 * returns: ld, final displacement
 */
ld Physics::displacement_halting_VdA(ld x0 ,ld sV, ld fV, ld acceleration)
{
	const ld value = (fV * fV) - (sV * sV);
	ld divisor = 2 * acceleration;
	return value/divisor + x0;
}


/**
 * function: time_using_quadratic(ld a, ld b, ld c)
 * arguments: a1 = default to 1, b_velocity = constant velocity, c_displacement = total distance to travel
 * purpose: calculate the time of a merging object when velocity and displacement is know
 * returns: ld, total time
 */
std::vector<ld> Physics::time_using_quadratic(ld a1, ld b_velocity, ld c_displacement)
{
	std::vector<ld> results = { 0.0, 0.0 };
	results[0] = (-b_velocity + sqrt((b_velocity * b_velocity) - 4 * a1 * c_displacement)) / 2 * a1;
	results[1] = (-b_velocity - sqrt((b_velocity * b_velocity) - 4 * a1 * c_displacement)) / 2 * a1;
	return results;
}



/**
 * function: time_using_VdA(ld a, ld sV, ld fV)
 * arguments: a = acceleration, sV = start velocity(default 0), fV = final velocity
 * purpose: calculate time with know acceleration and final velocity end point
 * returns: ld, time
 */
ld Physics::time_using_VdA(ld a, ld sV, ld fV)
{
	return (fV - sV) / a;
}

/**
 * function: Physics::velocity_falling_object_down(ld y, ld yf, ld v, ld a)
 * arguments: y = start position,  yf = final position v = velocity, a = acceleration
 * purpose: find the velocity of a falling object thrown downwards
 * returns: ld, velocity
 */
ld Physics::velocity_falling_object_down(ld y, ld yf, ld v, ld a)
{
	ld value = sqrt(pow(v, 2) +( 2 * (a) * (yf - y)));
	return value;
}


/**
 * function: acceleration_dispDtimeSqrd(ld y0, ld yf, ld v, ld t)
 * arguments: y0 = start(0), yf = end position, v = start velocity, t = time it took 
 * purpose: this function can be used to calculate the acceleration of falling objects 
 * returns: ld, acceleration of object
 */
ld Physics::acceleration_dispDtimeSqrd(ld y0, ld yf, ld v, ld t)
{
	return (2 * (yf - y0)) / (t * t);
}
/**
 * function: pos_vel_falling_object_upDown(double p, double v, double a, double t)
 * arguments: p = position,  v = velocity, a = acceleration, t = time is s
 * purpose: this function fill a vector with four pieces of data in order from the right to left it
 *			is: time, position, velocity, acceleration. use the print_vector_values() to see contents.
 * returns: ld, vector of the time, position, velocity, acceleration.
 */
std::vector<ld> Physics::pos_vel_falling_object_upDown(ld p, ld v, ld a, ld t)
{
	
	this->vector_values[0] = t;
	//solution for Position:
	Physics rock;
	rock.val = rock.displacement_accelerating_object_PV(p, v, a, t);
	
	this->vector_values[1] = rock.val;
	//Solution for Velocity:
	
	rock.val = rock.final_velocity(v, a, t);
	this->vector_values[2] = rock.val;
	
	this->vector_values[3] = a;
	
	return rock.vector_values;
}

void Physics::print()const
{
	std::cout << "current calculation:  " << val << std::endl;
}

void Physics::print_vector_values()
{
	//int len = this->vector_values.size();
	for (auto it : this->vector_values)
	{
		std::cout << it << ", ";
	}
	
}

/**
 * function: final_velocity_no_time(ld v, ld d, ld a)
 * arguments: v = velocity, d = displacement, a = acceleration
 * purpose: calculate the final velocity using acceleration and time
 * returns: ld, final velocity
 */
ld Physics::final_velocity_no_time(ld v, ld d, ld a)
{
	return sqrt(v + (2 * a) * (d));
}
