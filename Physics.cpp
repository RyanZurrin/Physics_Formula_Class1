#include "Physics.h"

ld Physics::_val_ = 0.0;
int Physics::physics_objectCount = 0;
 
/**
 *default constructor
 */
Physics::Physics()
{	
	_ptr_ = nullptr;
	drag = new Drag;
	elasticity = new Elasticity;
	friction = new Friction;
	circularMotion = new Circular_Motion;
	vector2d = new Vector;
	vector3d = new Vector3D;
	_mass_ = 0.0;
	_weight_ = 0.0;
	_length_ = 0.0;
	_width_ = 0.0;
	_height_ = 0.0;
	_volume_ = 0.0;
	_density_ = 0.0;
	_force_ = 0.0;
	_velocity_ = 0.0;
	_acceleration_ = 0.0;
	vector_values = { 0.0,0.0,0.0,0.0 };
	countIncrease();
	//countShow();
}
/**
 *copy constructor
 */
Physics::Physics(const Physics& p)
{
	_ptr_ = p._ptr_;	
	vector_values = p.vector_values;
	_mass_ = p._mass_;
	_weight_ = p._weight_;
	_length_ = p._length_;
	_width_ = p._weight_;
	_height_ = p._height_;
	_volume_ = p._volume_;
	_density_ = p._density_;
	_force_ = p._force_;
	_velocity_ = p._velocity_;
	_acceleration_ = p._acceleration_;	
	_ptr_ = nullptr;
	drag = p.drag;
	elasticity = p.elasticity;
	friction = p.friction;
	vector2d = p.vector2d;
	vector3d = p.vector3d;
	circularMotion = p.circularMotion;
	countIncrease();
	//countShow();
}
/**
 *copy assignment operator
 */
Physics& Physics::operator=(const Physics& r)
{
	if(this != &r)
	{
		_ptr_ = r._ptr_;		
		_weight_ = r._weight_;
		_density_ = r._density_;
		_height_ = r._height_;
		_length_ = r._length_;
		_mass_ = r._mass_;
		_width_ = r._width_;
		_force_ = r._force_;
		_velocity_ = r._velocity_;
		_acceleration_ = r._acceleration_;
		vector_values = r.vector_values;
		countIncrease();
		//countShow();
	}
	return *this;	
}

/**
 * method: print()const
 * arguments: none
 * purpose:	print out the value stored in val
 * returns: void
 */
void Physics::print(ld _val)const
{
	std::cout << "current calculation:  " << _val << std::endl;
}

/**
 * method: printAll()const
 * arguments: none
 * purpose:	print out the value stored in val
 * returns: void
 */
void Physics::printAll()const
{
	show_density();
	show_height();
	show_length();
	show_mass();
	show_volume();
	show_width();
	show_weight();
	show_val();

}


/**
 * @brief static member fuction to print values of objects vector variable
 * @param obj is reference to a physics object  * 
 */
void Physics::show_vector_values(Physics &obj)
{
	for (auto it : obj.vector_values)
	{
		std::cout << it << ", ";
	}
	std::cout << std::endl;
}

/**
 * @brief prints out the values stored in the objects vector
 */
void Physics::show_vector_values()
{
	for (auto it : this->vector_values)
	{
		std::cout << it << ", ";
	}
	std::cout << std::endl;
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
	return (2* launchVelocity*sin(angleTheta))/(_ga_);
}

/**
 * method: air_time_initial_velocity0_y0(ld displacement)const
 * arguments: displacement, assumes initial velocity to be 0 and y0 to be 0
 * purpose:	calculates time projectile is in the air
 * returns: ld, time units
 */
ld Physics::air_time_initial_velocity0_y0(ld displacement)const
{
	return sqrt((-2*(displacement))/_ga_);
}

/**
 * method: velocity_initial_horizontal_component(ld y0, ld displacement) const
 * arguments: y0 = starting height, displacement. this equation assumes horizontal start 
 * purpose:	calculates initial velocity of an object
 * returns: ld, initial velocity
 */
ld Physics::velocity_initial_horizontal_component(ld y0, ld displacement) const
{
	return sqrt((-_ga_/(-2 * y0)))* displacement;
}

/**
 * method: velocity_final_vertical_component(ld y0, ld yf = 0) const
 * arguments: y0 = starting height, yf = final vertical component default = 0
 * purpose:	calculates the final vertical component
 * returns: ld, final vertical velocity
 */
ld Physics::velocity_vertical_component(ld y0, ld yf)const
{
	return -sqrt(2 * (-_ga_) * (yf - y0));
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
	this->show_vector_values();
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
	ld a = (((-_ga_) * (hoopDistance * hoopDistance)) / (2 * (launchVelocity * launchVelocity)));
	ld b = -hoopDistance;
	ld c = ((hoopHeight - releaseHeight) + a);
	vector_values[0] = atan(-((b)+sqrt((b * b) - 4 * a * c)) / (2 * a))*DEGREE;
	vector_values[1] = atan(-((b)-sqrt((b * b) - 4 * a * c)) / (2 * a))*DEGREE;
	this->show_vector_values();
	
	return vector_values;
}

Physics::~Physics()
{
	delete elasticity;
	delete friction;
	delete vector2d;
	delete vector3d;
	delete drag;
	delete _ptr_;
	countDecrease();
	//countShow();
}

