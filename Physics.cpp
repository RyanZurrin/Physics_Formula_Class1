#include "Physics.h"
ld Physics::val = 0.0;
vector<ld> Physics::vector_values = { 0.0,0.0,0.0,0.0 };
/*
map<string, ld> Physics::static_friction = {
	{"rubber_concrete_dry", 1.0},
	{"rubber_concrete_wet", 0.7},
	{"wood_wood", 0.5},
	{"waxedWood_wetSnow", 0.14},
	{"metal_wood", 0.5},
	{"steel_steel_dry", 0.6},
	{"steel_steel_oiled", 0.05},
	{"teflon_steel", .04},
	{"bone_lubricated_synovial_fluid", .016},
	{"shoes_wood", .9},
	{"shoes_ice", .1},
	{"ice_ice", .1},
	{"steel_ice", .4}
};
map<string, ld> Physics::kinetic_friction = {
	{"rubber_concrete_dry", 0.7},
	{"rubber_concrete_wet", 0.5},
	{"wood_wood", 0.3},
	{"waxedWood_wetSnow", 0.1},
	{"metal_wood", 0.3},
	{"steel_steel_dry", 0.3},
	{"steel_steel_oiled", 0.03},
	{"teflon_steel", .04},
	{"bone_lubricated_synovial_fluid", .015},
	{"shoes_wood", .7},
	{"shoes_ice", .05},
	{"ice_ice", .03},
	{"steel_ice", .04}
};
*/

Physics::Physics()
{	

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