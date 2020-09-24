#include "Physics.h"


Physics::Physics()
{	
	this->val = 0.0;
	this->vector_values = { 0.0,0.0,0.0,0.0 };
}

/**
 * method: velocity_avg_DdT(ld displacement, ld time)   ss2.3 pg37
 * arguments: displacement = avg displacement in m, time = total time  in s
 * purpose: to calculate the average velocity using displacement divided by time
 * returns: ld, average velocity
 */
ld Physics::speed_avg_DdT(ld total_distance, ld time)
{
	return total_distance/time;
}


/**
 * method: velocity_avg_DdT(ld displacement, ld time)   ss2.3 pg37
 * arguments: displacement = avg displacement in m, time = total time  in s
 * purpose: to calculate the average velocity using displacement divided by time
 * returns: ld, average velocity 
 */
ld Physics::velocity_avg_DdT(ld displacement, ld time)
{
	return  displacement / time;
}

/**
 * method: acceleration_avg(ld vChange, ld tChange)   ss2.4  pg40
 * arguments: vChange = average change in velocity in m/s, tChange = change in time in seconds
 * purpose:	to find the average acceleration by dividing the avg velocity by the time
 * returns: ld, average acceleration 
 */
ld Physics::acceleration_avg(ld vChange, ld tChange)
{
	return vChange / tChange;
}

/**
 * method: displacement(ld length_1, ld length_2)
 * arguments: length_1 = starting position, length_2 = ending position
 * purpose:	find the displacement between two positions
 * returns: ld, displacement.
 */
ld Physics::displacement(ld length_1, ld length_2)
{
	return length_2 - length_1;
}


/**
 * method: Physics::displacement_VxT(ld velocity, ld time)
 * arguments: velocity = avg velocity m/s, time = in s
 * purpose:	find the displacement from knowing the velocity and time. 
 * returns: ld, displacement.  
 */
ld Physics::displacement_VxT(ld velocity, ld time)
{
	return velocity * time;
}

/**
 * method: displacement_Vstart_Vend(ld vStart, ld vEnd)
 * arguments: vStart = starting velocity m/s, vEnd = ending velocity m/s
 * purpose:	find the displacement when start and end velocity is know
 * returns: ld, disp;acement
 */
ld Physics::velocity_vStart_plus_vEndD2(ld velocityStart, ld velocityEnd)
{
	return (velocityStart + velocityEnd) / 2;
}

/**
 * method: velocity_final_using_time(ld velocity, ld acceleration, ld time)
 * arguments: initial velocity, amount of acceleration, and time 
 * purpose:	calculate the final velocity using acceleration and time
 * returns: ld, final velocity
 */
ld Physics::velocity_final_using_time(ld velocity, ld acceleration, ld time)
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
	return ((acceleration) * (time * time)) / 2;
}

/**
 * method: displacement_accelerating_object_PV(ld acceleration, ld time)
 * arguments: velocity, acceleration m/s , position = 0m default, time in s
 * purpose: find the displacement of an accelerating object with a starting 
 * 			position and an initial velocity along with acceleration and a time
 * returns:	ld, displacement
 */
ld Physics::displacement_accelerating_object_PV(ld velocity, ld acceleration, ld time, ld pos)
{
	return pos + (velocity * time) + (acceleration * (time * time)) / 2;
}


/**
 * method: displacement_halting_VdA(ld velocity, ld acceleration)
 * arguments: x0 = starting position(0), Sv = starting velocity, fV = ending velocity(0) a = acceleration
 * purpose: calculate displacement for the distance to stop from moving object
 * returns: ld, final displacement
 */
ld Physics::distance_VdA(ld pos ,ld velocityStart, ld velocityFinal, ld acceleration) const
{
	return abs(((velocityFinal * velocityFinal) - (velocityStart * velocityStart)) / (2 * acceleration)) + pos;
}


/**
 * method: time_using_quadratic(ld a, ld b, ld c)
 * arguments: a1 = default to 1, b_velocity = constant velocity, c_displacement = total distance to travel
 * purpose: calculate the time of a merging object when velocity and displacement is know
 * returns: ld, total time
 */
std::vector<ld> Physics::time_using_quadratic(ld a1, ld b_velocity, ld c_displacement)
{
	
	vector_values[0] = (-b_velocity + sqrt((b_velocity * b_velocity) - 4 * a1 * c_displacement)) / (2 * a1);
	vector_values[1] = (-b_velocity - sqrt((b_velocity * b_velocity) - 4 * a1 * c_displacement))/ (2 * a1);
	return this->vector_values;
}



/**
 * method: time_using_VdA(ld a, ld sV, ld fV)
 * arguments: a = acceleration, sV = start velocity(default 0), fV = final velocity
 * purpose: calculate time with know acceleration and final velocity end point
 * returns: ld, time
 */
ld Physics::time_by_avgVdA(ld acceleration, ld velocityStart, ld velocityEnd)
{
	return (velocityEnd - velocityStart) / acceleration;
}


/**
 * method: time_by_DisTdV(ld distance, ld time)
 * arguments: distance , average velocity
 * purpose: find the velocity of a falling object thrown downwards
 * returns: ld, velocity
 */
ld Physics::time_by_DisTdV(ld distance, ld velocity)
{
	return distance / velocity;
}


/**
 * method: time_finalPos_and_acceleration(ld displacement, ld acceleration)
 * arguments: displacement of object, acceleration of object
 * purpose: find how long it takes an object with a known acceleration to travel a know distance
 * returns: ld, time to accelerate a distance
 */
ld Physics::time_by_finalPos_and_acceleration(ld displacement, ld acceleration)
{
	return sqrt((2*displacement)/acceleration);
}

/**
 * method: time(ld startTime, ld endTime)
 * arguments: y = startTime = beginning time in seconds, endTime = endTime in seconds
 * purpose: find the amount of time between two periods
 * returns: ld, difference in two times
 */
ld Physics::time_difference(ld startTime, ld endTime)
{
	return endTime - startTime;
}


/**
 * method: time_kinematic_rearranged(ld velocity, ld y0, ld acceleration) const
 * arguments: velocity, y0 = position from 0, acceleration
 * purpose: find the amount of time between two periods
 * returns: ld, difference in two times
 */
ld Physics::time_kinematic_rearranged(ld velocity, ld displacement, ld acceleration) const
{
	return (-(velocity)-sqrt((velocity*velocity)-2*(acceleration)*(displacement)))/(acceleration);
}

/**
 * method: Physics::velocity_falling_object_down(ld y, ld yf, ld v, ld a)
 * arguments: y0 = start position,  yf = final position v = velocity, a = acceleration
 * purpose: find the velocity of a falling object thrown downwards
 * returns: ld, velocity
 */
ld Physics::velocity_kinematic_constant_a(ld xY0, ld xYf, ld velocity, ld acceleration) const
{
	return sqrt((velocity * velocity) + (2 * (acceleration * (xYf - xY0))));
}

/**
 * method: acceleration_dispDtimeSqrd(ld y0, ld yf, ld v, ld t)
 * arguments: y0 = start(0), yf = end position, t = time it took 
 * purpose: this method can be used to calculate the acceleration of falling objects 
 * returns: ld, acceleration of object
 */
ld Physics::acceleration_dispDtimeSqrd(ld displacement, ld time)
{
	return (2 * (displacement)) / (time * time);
}

/**
 * method: acceleration_vStart_vEndDdisplacement(ld velocityStart, ld velocityEnd, ld displacement)const
 * arguments: velocity start, velocity end, total displacement
 * purpose: finds the acceleration using the starting and ending velocity and total displacement as known values
 * returns: ld, acceleration of object
 */
ld Physics::acceleration_vStart_vEndDdisplacement(ld velocityStart, ld velocityEnd, ld displacement)const
{
	return (velocityEnd * velocityEnd - velocityStart * velocityStart) / (2 * displacement);
}

/**
 * method: pos_vel_falling_object_upDown(double p, double v, double a, double t)
 * arguments: p = position (0),  v = velocity, a = acceleration, t = time is s
 * purpose: this method will fill a vector with four pieces of data in order from the right to left it
 *			is: time, position, velocity, acceleration. use the print_vector_values() to see contents.
 * returns: ld, vector of the time, position, velocity, acceleration.
 */
std::vector<ld> Physics::pos_vel_falling_object_upDown(ld v, ld a, ld t, ld p)
{
	
	this->vector_values[0] = t;
	//solution for Position:
	Physics rock;
	
	this->vector_values[1] = rock.displacement_accelerating_object_PV(v, a, t, p);
	//Solution for Velocity:
	
	rock.val = rock.velocity_final_using_time(v, a, t);
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
 * method: multiple_of_gravity(ld value)
 * arguments: value = the value you want to find the multiples of gravity of
 * purpose:	finds the times gravity acceleration can be divided out of the value
 * returns: ld, multiple of gravity
 */
ld Physics::multiple_of_gravity(ld value)
{
	return value/GA;
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
 * purpose: calculate the final velocity using velocity, displacement and acceleration
 * returns: ld, final velocity
 */
ld Physics::velocity_final_no_time(ld velocity, ld displacement, ld acceleration)
{
	return sqrt(velocity*velocity + (2 * (acceleration * displacement)));
}
