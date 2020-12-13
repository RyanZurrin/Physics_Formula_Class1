#include "PhysicsWorld.h"

//ld PhysicsWorld::_val_ = 0.0;
vector<ld> PhysicsWorld::vector_values = { 0.0,0.0,0.0,0.0 };
int PhysicsWorld::physics_objectCount = 0;
 
/**
 *default constructor
 */
PhysicsWorld::PhysicsWorld()
{	
	_ptr_ = nullptr;	
	drag = new Drag;
	elasticity = new Elasticity;
	friction = new Friction;
	uniformCircularMotion = new UniformCircularMotion;
	vector2d = new Vector;
	vector3d = new Vector3D;
	energy = new Energy;
	momentum = new Momentum;
	torque = new Torque;
	statics = new Statics;
	rotationalMotion = new RotationalMotion;
	temperature = new Temperature;
	heat = new Heat;
	thermodynamic = new Thermodynamics;
	periodic_elements = new PeriodicElements;
	//physics_common = new PhysicsCommon;
	//world = physics_common->createPhysicsWorld();
	
	countIncrease();
	//countShow();
}
/**
 *copy constructor
 */
PhysicsWorld::PhysicsWorld(const PhysicsWorld& p)
{
	_ptr_ = p._ptr_;	
	vector_values = p.vector_values;	
	drag = p.drag;
	elasticity = p.elasticity;
	friction = p.friction;
	vector2d = p.vector2d;
	vector3d = p.vector3d;
	uniformCircularMotion = p.uniformCircularMotion;
	momentum = p.momentum;
	energy = p.energy;
	torque = p.torque;
	statics = p.statics;
	rotationalMotion = p.rotationalMotion;
	temperature = p.temperature;
	heat = p.heat;
	thermodynamic = p.thermodynamic;
	periodic_elements = p.periodic_elements;
	//PhysicsWorld_common = p.PhysicsWorld_common;
	countIncrease();
	//countShow();
}
/**
 *copy assignment operator
 */
PhysicsWorld& PhysicsWorld::operator=(const PhysicsWorld& r)
{
	if(this != &r)
	{
		_ptr_ = r._ptr_;		
		vector_values = r.vector_values;
		drag = r.drag;
		elasticity = r.elasticity;
		friction = r.friction;
		vector2d = r.vector2d;
		vector3d = r.vector3d;
		uniformCircularMotion = r.uniformCircularMotion;
		energy = r.energy;
		momentum = r.momentum;
		torque = r.torque;
		statics = r.statics;
		rotationalMotion = r.rotationalMotion;
		temperature = r.temperature;
		heat = r.heat;
		thermodynamic = r.thermodynamic;
		periodic_elements = r.periodic_elements;
		countIncrease();
		//countShow();
	}
	return *this;	
}
PhysicsWorld::PhysicsWorld(const ld t1, const ld t2, const ld t3)
{
	_ptr_ = nullptr;
	drag = new Drag;
	elasticity = new Elasticity;
	friction = new Friction;
	uniformCircularMotion = new UniformCircularMotion;
	vector2d = new Vector;
	vector3d = new Vector3D;
	energy = new Energy;
	momentum = new Momentum;
	torque = new Torque;
	statics = new Statics;
	rotationalMotion = new RotationalMotion;
	temperature = new Temperature;
	heat = new Heat;
	thermodynamic = new Thermodynamics;
	periodic_elements = new PeriodicElements;
	
	//vector_values = { 0.0,0.0,0.0,0.0 };
	this->vector3d->set_coordinates(t1, t2, t3);
	
	countIncrease();
}
 
PhysicsWorld::PhysicsWorld(const ld t1, const ld t2)
{
	drag = new Drag;
	elasticity = new Elasticity;
	friction = new Friction;
	uniformCircularMotion = new UniformCircularMotion;
	vector2d = new Vector;
	vector3d = new Vector3D;
	energy = new Energy;
	momentum = new Momentum;
	torque = new Torque;
	statics = new Statics;
	rotationalMotion = new RotationalMotion;
	temperature = new Temperature;
	heat = new Heat;
	thermodynamic = new Thermodynamics;
	periodic_elements = new PeriodicElements;
	_ptr_ = nullptr;
	this->vector2d->set_coordinates(t1, t2);
}





/**
 * @brief prints out the values stored in the objects vector
 */
void PhysicsWorld::show_vector_values()
{
	for (auto it : vector_values)
	{
		std::cout << it << ", ";
	}
	std::cout << std::endl;
}

/**
 * method: air_time_initial_velocity0_y0(ld displacement)const
 * arguments: displacement, assumes initial velocity to be 0 and y0 to be 0
 * purpose:	calculates time projectile is in the air
 * returns: ld, time units
 */
ld PhysicsWorld::air_time_initial_velocity0_y0(ld displacement)const
{
	return sqrt((-2*(displacement))/GA);
}

/**
 * method: velocity_initial_horizontal_component(ld y0, ld displacement) const
 * arguments: y0 = starting height, displacement. this equation assumes horizontal start 
 * purpose:	calculates initial velocity of an object
 * returns: ld, initial velocity
 */
ld PhysicsWorld::velocity_initial_horizontal_component(ld y0, ld displacement) const
{
	return sqrt((-GA/(-2 * y0)))* displacement;
}

/**
 * method: velocity_final_vertical_component(ld y0, ld yf = 0) const
 * arguments: y0 = starting height, yf = final vertical component default = 0
 * purpose:	calculates the final vertical component
 * returns: ld, final vertical velocity
 */
ld PhysicsWorld::velocity_vertical_component(ld y0, ld yf)const
{
	return -sqrt(2 * (-GA) * (yf - y0));
}


/**
 * method: velocity_final_vertical_component(ld y0, ld yf = 0) const
 * arguments: y0 = starting height, yf = final vertical component default = 0
 * purpose:	calculates the final vertical component
 * returns: ld, final vertical velocity
 */
std::vector<ld> PhysicsWorld::final_projectile_velocity_vector(ld velocityY, ld velocityX)
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
ld PhysicsWorld::velocity_soccer_kick(ld toGoal, ld height_at_goal, ld angle) const
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
ld PhysicsWorld::horizontal_velocity_using_distance_angle_height(ld targetDistance, ld targetHeight, ld angle, ld acceleration)const
{
	return targetDistance * sqrt(-acceleration/((2 * (targetDistance * tan(angle*RADIAN) - targetHeight))));
}

ld PhysicsWorld::vertical_velocity_by_Xvelocity_with_angle(ld xVelocity, ld angle) const
{
	return xVelocity * tan(angle*RADIAN);
}


/**
 * method: basketball_angles(ld launchVelocity, ld releaseHeight, ld hoopDistance)
 * arguments: launch velocity, height or ball release, distance from hoop
 * purpose:	uses quadratic formula to return two angles in a vector, the larger angle is the best angle to use
 * returns: vector data
 */
std::vector<ld> PhysicsWorld::basketball_angles(ld launchVelocity, ld releaseHeight, ld hoopDistance)
{
	const ld hoopHeight = 3.05; //meters
	ld a = (((-GA) * (hoopDistance * hoopDistance)) / (2 * (launchVelocity * launchVelocity)));
	ld b = -hoopDistance;
	ld c = ((hoopHeight - releaseHeight) + a);
	vector_values[0] = atan(-((b)+sqrt((b * b) - 4 * a * c)) / (2 * a))*DEGREE;
	vector_values[1] = atan(-((b)-sqrt((b * b) - 4 * a * c)) / (2 * a))*DEGREE;
	this->show_vector_values();
	
	return vector_values;
}

PhysicsWorld::~PhysicsWorld()
{
	delete elasticity;
	delete friction;
	delete vector2d;
	delete vector3d;
	delete drag;
	delete uniformCircularMotion;
	delete energy;
	delete momentum;	
	delete _ptr_;
	delete torque;
	delete statics;
	delete rotationalMotion;
	delete temperature;
	delete heat;
	delete thermodynamic;
	delete periodic_elements;
	countDecrease();
	//countShow();
}

