#include "Physics.h"


Physics::Physics()
{	
	this->val = 0.0;
	this->vector_values = { 0.0,0.0,0.0,0.0 };
}

/**
 * method: displacement_start_finish(ld start, ld finish);  ss2.1 pg32
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
 * method: velocity_avg_DdT(ld displacement, ld time)   ss2.3 pg37
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
 * method: acceleration_VdT(ld velocity, ld time)    ss2.4  pg40
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
 * method: Physics::displacement_VxT(ld velocity, ld time)
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
 * method: displacement_Vstart_Vend(ld vStart, ld vEnd)
 * arguments: vStart = starting velocity m/s, vEnd = ending velocity m/s
 * purpose:	find the displacement when start and end velocity is know
 * returns: ld, disp;acement
 */
ld Physics::displacement_Vstart_Vend(ld vStart, ld vEnd)
{
	return (vStart + vEnd) / 2;
}

/**
 * method: final_velocity(ld velocity, ld acceleration, ld time)
 * arguments: initial velocity, amount of acceleration, and time 
 * purpose:	calculate the final velocity using acceleration and time
 * returns: ld, final velocity
 */
ld Physics::final_velocity(ld velocity, ld acceleration, ld time)
{
	return velocity + acceleration * time;
}

/**
 * method: displacement_accelerating_object(ld acceleration, ld time)
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
 * method: displacement_accelerating_object_PV(ld acceleration, ld time)
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
 * method: displacement_halting_VdA(ld velocity, ld acceleration)
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
 * method: time_using_quadratic(ld a, ld b, ld c)
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
 * method: time_using_VdA(ld a, ld sV, ld fV)
 * arguments: a = acceleration, sV = start velocity(default 0), fV = final velocity
 * purpose: calculate time with know acceleration and final velocity end point
 * returns: ld, time
 */
ld Physics::time_using_VdA(ld a, ld sV, ld fV)
{
	return (fV - sV) / a;
}


/**
 * method: time_by_DisTdV(ld distance, ld time)
 * arguments: distance , average velocity
 * purpose: find the velocity of a falling object thrown downwards
 * returns: ld, velocity
 */
ld Physics::time_by_DisTdV(ld distance, ld v)
{
	return distance / v;
}

/**
 * method: Physics::velocity_falling_object_down(ld y, ld yf, ld v, ld a)
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
 * method: acceleration_dispDtimeSqrd(ld y0, ld yf, ld v, ld t)
 * arguments: y0 = start(0), yf = end position, v = start velocity, t = time it took 
 * purpose: this method can be used to calculate the acceleration of falling objects 
 * returns: ld, acceleration of object
 */
ld Physics::acceleration_dispDtimeSqrd(ld y0, ld yf, ld v, ld t)
{
	return (2 * (yf - y0)) / (t * t);
}
/**
 * method: pos_vel_falling_object_upDown(double p, double v, double a, double t)
 * arguments: p = position (0),  v = velocity, a = acceleration, t = time is s
 * purpose: this method will fill a vector with four pieces of data in order from the right to left it
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


/**
 * method: slope_formula(ld y1, ld y0, ld x1, ld x0)
 * arguments: y1 , y0, x1, x0 
 * purpose:	the general slope equation of (y1 - y0)/(x1 - x0) to find the slope of a line between two points
 * returns: ld, slope of line between two points
 */
ld Physics::slope_formula(ld y1, ld y0, ld x1, ld x0)
{
	return (y1 - y0)/(x1 - x0);
}


/**
 * method: rotation_speed_2PIxRdT(ld radius, ld rotations, ld time)
 * arguments: radius = length in m from center of rotation
 *			  rotations = how many rotations in a time period
 *			  time = time units
 * purpose: find the speed of a spinning object, such as fan blade 
 * returns: average speed of spinning object
 */
ld Physics::rotation_speed_2PIxRdT(ld radius, ld rotations, ld time)
{
	return (2*PI*radius)/(time/rotations);
}

/**
 * method: rotation_avgVelocity_2PIxRdT_in_1_rotation(ld radius, ld time)
 * arguments: radius , time = time for one rotation
 * purpose: find average velocity of a spinning object
 * returns: ld, average velocity
 */
ld Physics::rotation_avgVelocity_2PIxRdT_in_1_rotation(ld radius, ld time)
{
	return (2 * PI * radius)/time;
}

/**
 * method: print()const
 * arguments: none
 * purpose:	print out the value stored in val
 * returns: void
 */
void Physics::print()const
{
	std::cout << "current calculation:  " << val << std::endl;
}

/**
 * method: print_vector_values()
 * arguments: none
 * purpose:	print the values contained within the vector variable;
 * returns: void
 */
void Physics::print_vector_values()
{
	for (auto it : this->vector_values)
	{
		std::cout << it << ", ";
	}	
}

/**
 * method: final_velocity_no_time(ld v, ld d, ld a)
 * arguments: v = velocity, d = displacement, a = acceleration
 * purpose: calculate the final velocity using acceleration and time
 * returns: ld, final velocity
 */
ld Physics::final_velocity_no_time(ld v, ld d, ld a)
{
	return sqrt(v + (2 * a) * (d));
}
