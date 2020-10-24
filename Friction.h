#pragma once
#pragma once
// class for doing physics problems
// author: Ryan Zurrin
// last Modified: 10/11/2020
#ifndef FRICTION_H
#define FRICTION_H


typedef long double ld;
static const ld _G_ = 9.8;
const double _PI = acos(-1);
const double _DEGREE_ = 180 / _PI;
const double _RADIAN_ = _PI / 180;
static int friction_objectCount = 0;

class Friction 
{
private:
	
	static void countIncrease() { friction_objectCount += 1; }
	static void countDecrease() { friction_objectCount -= 1; }
public:
	static void countShow() { std::cout << "friction count: " << friction_objectCount << std::endl; }
	Friction* _ptrFriction;
// static friction coefficients	
	struct Static
	{
		ld static_rubber_concrete_dry = 1.0;//returns 1.0
		ld static_rubbedr_concrete_wet = .7; //returns 0.7
		ld static_wood_wood = .5;  //returns 0.5
		ld static_waxedWood_wetSnow = .14;  //returns 0.14
		ld static_metal_wood = .5;  //returns 0.5
		ld static_steel_steel_dry = .6;  //returns 0.6
		ld static_steel_steel_oiled = .05;  //returns 0.05
		ld static_teflon_steel = .04;  //returns 0.04
		ld static_bone_lubricated_synovial_fluid = .016;  //returns 0.016
		ld static_shoes_wood = .9;  //returns 0.9
		ld static_shoes_ice = .1;  //returns 0.1
		ld static_ice_ice = .1;  //returns 0.1
		ld static_steel_ice = 0.4; // returns 0.4
	}s_coefficient;
	
	// Kinetic friction coefficients	
	struct Kinetic
	{
		ld kinetic_rubber_concrete_dry = .7;  //returns 0.7
		ld kinetic_rubber_concrete_wet = .5;  //returns 0.5
		ld kinetic_wood_wood = .3; //return 0.3
		ld kinetic_waxedWood_wetSnow = .1;//return 0.1
		ld kinetic_metal_wood = .3; //returns 0.3
		ld kinetic_steel_steel_dry = .3;  //returns 0.3
		ld kinetic_steel_steel_oiled = .03;  //return 0.03
		ld kinetic_teflon_steel = .4;  //return 0.4
		ld kinetic_bone_lubricated_synovial_fluid = .015; //returns 0.015
		ld kinetic_shoes_wood = .5;  //returns 0.5
		ld kinetic_shoes_ice = .5;  //return 0.5
		ld kinetic_ice_ice = .03;  //return 0.03
		ld kinetic_steel_ice = .04;  // return .04	
	}k_coefficient;
		
	// constructor
	Friction()
	{
		_ptrFriction = nullptr;
		countIncrease();
		//countShow();
	}

	// copy constructor
	Friction(const Friction& f)
	{
		_ptrFriction = f._ptrFriction;
		countIncrease();
		//countShow();
	}

	/**
	 * Returns the calculated force of friction, which is the same as the force
	 * @param mass
	 * @param coefficient of friction
	 * @returns frictional force
	 */
	ld static friction_force(const ld mass,  const ld coefficient)
	{
		return coefficient * mass * _G_;
	}

	/**
	 * Returns the friction coefficient using the Normal Force and the Friction Force as known data
	 * @param normalForce is the amount of normal force found by multiplying mass(kg) * 9.8 (m/s^2)
	 * @param frictionForce is the amount of force the friction is pushing back against something.
	 * @returns the frictional coefficient of objects in question
	 */
	ld static friction_coefficient(const ld normalForce, const ld frictionForce)
	{
		return (frictionForce) / (normalForce);
	}

	/**
	 * Returns the acceleration of an object taking into account its mass and the frictional coefficient
	 * of the materials.
	 * @param mass in kg
	 * @param frictionCoefficient of the materials
	 * @returns magnitude of the acceleration of an object
	 */
	ld static acceleration_magnitude(const ld mass, const ld frictionCoefficient)
	{
		const ld normalForce = mass * _G_;
		const ld frictionForce = normalForce * frictionCoefficient;	 
		return frictionForce / mass;
	}

	/**
	 * Returns the initial velocity when giving the amount of time it takes something
	 * to come to a stop
	 * @param mass of object in kg
	 * @param frictionCoefficient for the materials in consideration
	 * @param time in seconds it took to come to a stop
	 * @returns initial velocity 
	 */
	ld static initial_velocity(const ld mass, const ld frictionCoefficient, const ld time)
	{
		const ld normalForce = mass * _G_;
		const ld frictionForce = normalForce * frictionCoefficient;
		const ld acceleration = frictionForce / mass;
		return acceleration * time; 
	}

	/**
	 * method: acceleration_slope_friction(const ld angleTheta, const ld kineticCoefficient)
	 * arguments: 1)angleTheta 2)kineticCoefficient
	 * purpose: calculates the normal force on an angle
	 * returns: ld, normal force
	 */
	ld static acceleration_down_slope_friction(const ld angleTheta, const ld kineticCoefficient)
	{
		return _G_ * (sin(angleTheta * _RADIAN_) - (kineticCoefficient * cos(angleTheta * _RADIAN_)));
	}

	/**
	 * method: acceleration_up_slope_friction(const ld angleTheta, const ld frictionalCoefficient)
	 * arguments: 1)angleTheta 2)frictionalCoefficient
	 * purpose: calculates the acceleration of an object going up a slope, like a 4 wheel drive car
	 * returns: ld, acceleration
	 */
	ld static acceleration_up_slope_friction(const ld angleTheta, const ld frictionalCoefficient)
	{
		return _G_ * ((frictionalCoefficient*cos(angleTheta * _RADIAN_) - sin(angleTheta*_RADIAN_)));
	}
	
	/**
	 * method: car2wheel_acceleration_up_slope_friction(const ld angleTheta, const ld kineticCoefficient)
	 * arguments: 1)angleTheta 2)kineticCoefficient
	 * purpose: calculates the normal force on an angle
	 * returns: ld, normal force
	 */
	ld static car2wheel_acceleration_up_slope_friction(const ld angleTheta, const ld kineticCoefficient)
	{
		return _G_ * ((kineticCoefficient*cos(angleTheta*_RADIAN_)/2)-(sin(angleTheta * _RADIAN_)));
	}

	/**
	 * method: tension_rope_rockClimber(const ld angleRope, const ld angleLegs,  const ld mass)
	 * arguments: 1)angleRope 2)angleLegs 3)mass
	 * purpose: calculates the tension on a rope from a hanging rock climber or similar situation
	 * returns: ld, tension force
	 */
	ld static tension_rope_rockClimber(const ld angleRope, const ld angleLegs,  const ld mass)
	{	
		return (mass * _G_) / (cos(angleRope*_RADIAN_) + sin(angleRope*_RADIAN_) * tan(angleLegs*_RADIAN_));
	}

	/**
	 * method:  tension_legs_rockClimber(const ld angleRope, const ld angleLegs, const ld mass)
	 * arguments: 1)angleRope 2)angleLegs 3)mass
	 * purpose: calculates the tension on a rope from a hanging rock climber or similar situation
	 * returns: ld, tension force on legs
	 */
	ld static tension_legs_rockClimber(const ld angleRope, const ld angleLegs, const ld mass)
	{
		return (tension_rope_rockClimber(angleRope, angleLegs, mass)*sin(angleRope*_RADIAN_)/cos(angleLegs*_RADIAN_));
	}

	/**
	 * method:  minimum_force_start_move_push(const ld mass, const ld pushAngle, const ld frictionCoefficient)
	 * arguments: 1)mass 2)pushAngle 3)frictionCoefficient
	 * purpose: calculates the minimum force it takes to start moving an object pushing at a downward angle
	 * returns: ld, minimum force to start moving block
	 */
	ld static minimum_force_start_move_downPush(const ld mass, const ld pushAngle, const ld staticCoefficient)
	{
		return (staticCoefficient * mass*_G_) / (cos(pushAngle*_RADIAN_)- staticCoefficient * sin(pushAngle*_RADIAN_));
	}

	/**
	 * method:  magnitude_acceleration_moving_object_downPush(const ld mass, const ld pushAngle, const ld frictionCoefficient)
	 * arguments: 1)mass 2)pushAngle 3)frictionCoefficient
	 * purpose: calculates the acceleration of the object once it starts moving if force is maintained
	 * returns: ld, acceleration
	 */
	ld static magnitude_acceleration_moving_object_downPush(const ld mass, const ld pushAngle, const ld kineticCoefficient, const ld staticCoefficient)
	{
		return ((minimum_force_start_move_downPush(mass, pushAngle, staticCoefficient) * cos(pushAngle*_RADIAN_) - kineticCoefficient *sin(pushAngle*_RADIAN_))-(kineticCoefficient)*mass*_G_)/(mass);
	}

	/**
	 * method:   minimum_force_start_move_upPull(const ld mass, const ld pullAngle, const ld staticCoefficient)
	 * arguments: 1)mass 2)pushAngle 3)frictionCoefficient
	 * purpose: calculates the minimum force it takes to start moving an object pulling on it upward by a rope
	 * returns: ld, minimum force to start moving block fro pulling up
	 */
	ld static minimum_force_start_move_upPull(const ld mass, const ld pullAngle, const ld staticCoefficient)
	{
		return (staticCoefficient*mass*_G_)/(cos(pullAngle*_RADIAN_) + staticCoefficient*sin(pullAngle*_RADIAN_));
	}

	/**
	 * method:  magnitude_acceleration_moving_object_pullingUp(const ld mass, const ld pullAngle, const ld kineticCoefficient)
	 * arguments: 1)mass 2)pushAngle 3)frictionCoefficient
	 * purpose: calculates the minimum force it takes to start moving an object pulling on it upward by a rope
	 * returns: ld, minimum force to start moving block fro pulling up
	 */
	ld static magnitude_acceleration_moving_object_pullingUp(const ld mass, const ld pullAngle, const ld kineticCoefficient, const ld maintainingForce)
	{
		ld a, b;
		a = maintainingForce * cos(pullAngle * _RADIAN_);
		b = kineticCoefficient * ((mass * _G_) - maintainingForce * sin(pullAngle * _RADIAN_));
		return  (a-b)/(mass);
	}
	
	// destructor
	~Friction()
	{
		delete _ptrFriction;
		countDecrease();
		//countShow();
	}	
	
};



#endif
