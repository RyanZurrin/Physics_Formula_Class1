#include "Physics.h"


Physics::Physics()
{	
	this->val = 0.0;
	this->vector_values = { 0.0,0.0,0.0,0.0 };
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
 * method: time_kinematic_rearranged(ld velocity, ld y0, ld acceleration) const
 * arguments: velocity, y0 = position from 0, acceleration
 * purpose: find the amount of time between two periods
 * returns: ld, difference in two times
 */
ld Physics::time_kinematic_rearranged(ld velocity, ld displacement, ld acceleration)
{
	return (-(velocity)-sqrt((velocity*velocity)-2*(acceleration)*(displacement)))/(acceleration);
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
	this->print_vector_values();
	return rock.vector_values;
}


/**
 * method: projectile_range_level_ground(ld velocity, ld theta)
 * arguments: velocity, theta (initial angle relitive to the horizontal
 * purpose:	calculates projectile range
 * returns: ld, range of a projectile
 */
ld Physics::projectile_range_level_ground(ld velocity, ld angleTheta)const
{
	return  ((velocity*velocity)*sin(2* angleTheta)/(GA));
}

/**
 * method: projectile_time_to_reach_level(ld launchVelocity, ld angleTheta)
 * arguments: launch velocity, initial angle
 * purpose:	calculates the time a projectile with an initial velocity and angle
 *  take to reach the same level from which it was launched, forms a parabolic curve
 * returns: ld, time units
 */
ld Physics::time_for_projectile_to_reach_level(ld launchVelocity, ld angleTheta)const
{
	return (2* launchVelocity*sin(angleTheta))/(GA);
}

/**
 * method: air_time_initial_velocity0_y0(ld displacement)const
 * arguments: displacement, assumes initial velocity to be 0 and y0 to be 0
 * purpose:	calculates time projectile is in the air
 * returns: ld, time units
 */
ld Physics::air_time_initial_velocity0_y0(ld displacement)const
{
	return sqrt((-2*(displacement))/-GA);
}

/**
 * method: velocity_initial_horizontal_component(ld y0, ld displacement) const
 * arguments: y0 = starting height, displacement. this equation assumes horizontal start 
 * purpose:	calculates initial velocity of an object
 * returns: ld, initial velocity
 */
ld Physics::velocity_initial_horizontal_component(ld y0, ld displacement) const
{
	return sqrt((-GA/(-2 * y0)))* displacement;
}

/**
 * method: velocity_final_vertical_component(ld y0, ld yf = 0) const
 * arguments: y0 = starting height, yf = final vertical component default = 0
 * purpose:	calculates the final vertical component
 * returns: ld, final vertical velocity
 */
ld Physics::velocity_vertical_component(ld y0, ld yf)const
{
	return -sqrt(2 * (-GA) * (yf - y0));
}


/**
 * method: velocity_final_vertical_component(ld y0, ld yf = 0) const
 * arguments: y0 = starting height, yf = final vertical component default = 0
 * purpose:	calculates the final vertical component
 * returns: ld, final vertical velocity
 */
std::vector<ld> Physics::final_projectile_velocity_vector(ld velocityY, ld velocityX)
{
	this->vector_values[0] = sqrt(velocityY * velocityY + velocityX * velocityX);
	this->vector_values[1] = atan(velocityY / velocityX)*DEGREE;
	this->print_vector_values();
	return vector_values;
}

/**NOT WORKING RIGHT
 * method: velocity_soccer_kick(ld toGoal, ld height_at_goal, ld angle) const
 * arguments: distance to goal, height ball is at goal, and initial angle of kick
 * purpose:	calculates the final velocity of both component vectors
 * returns: ld, magnitude of final velocity vector
 */
ld Physics::velocity_soccer_kick(ld toGoal, ld height_at_goal, ld angle) const
{
	return sqrt(pow(horizontal_velocity_using_distance_angle_height(toGoal, height_at_goal, angle), 2) +
		pow(vertical_velocity_by_Xvelocity_with_angle(horizontal_velocity_using_distance_angle_height(toGoal, height_at_goal, angle), angle), 2));
}


/**
 * method: slope_formula(ld y1, ld y0, ld x1, ld x0)
 * arguments: y1 , y0, x1, x0 
 * purpose:	the general slope equation of (y1 - y0)/(x1 - x0)
 *  to find the slope of a line between two points
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
 * method: horizontal_velocity_using_distance_angle_height(ld targetDistance, ld targetHeight, ld angle, ld acceleration)
 * arguments: distance, height, angle, acceleration = default is -9.8
 * purpose:	finds x componant velocity
 * returns: ld, velocity of X component
 */
ld Physics::horizontal_velocity_using_distance_angle_height(ld targetDistance, ld targetHeight, ld angle, ld acceleration)const
{
	return targetDistance * sqrt(-acceleration/((2 * (targetDistance * tan(angle*RADIAN) - targetHeight))));
}

ld Physics::vertical_velocity_by_Xvelocity_with_angle(ld xVelocity, ld angle) const
{
	return xVelocity * tan(angle*RADIAN);
}


/**
 * method: basketball_angles(ld launchVelocity, ld releaseHeight, ld hoopDistance)
 * arguments: launch velocity, height or ball release, distance from hoop
 * purpose:	uses quadratic formula to return two angles in a vector, the larger angle is the best angle to use
 * returns: vector data
 */
std::vector<ld> Physics::basketball_angles(ld launchVelocity, ld releaseHeight, ld hoopDistance)
{
	const ld hoopHeight = 3.05; //meters
	ld a = (((-GA) * (hoopDistance * hoopDistance)) / (2 * (launchVelocity * launchVelocity)));
	ld b = -hoopDistance;
	ld c = ((hoopHeight - releaseHeight) + a);
	vector_values[0] = atan(-((b)+sqrt((b * b) - 4 * a * c)) / (2 * a))*DEGREE;
	vector_values[1] = atan(-((b)-sqrt((b * b) - 4 * a * c)) / (2 * a))*DEGREE;
	this->print_vector_values();
	
	return vector_values;
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
	std::cout << std::endl;
}