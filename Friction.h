#pragma once
typedef long double ld;

class Friction
{
public:
	Friction* _ptrFriction;
// static friction coefficients
	struct Static
	{
		ld static_rubber_concrete_dry = 1.0;//() { return 1.0; } //returns 1.0
		ld static_rubbedr_concrete_wet = .7; // () { return 0.7; } //returns 0.7
		ld static_wood_wood = .5; // () { return  0.5; } //returns 0.5
		ld static_waxedWood_wetSnow = .14; //() { return 0.14; } //returns 0.14
		ld static_metal_wood = .5; // () { return 0.5; } //returns 0.5
		ld static_steel_steel_dry = .6; // () { return 0.6; } //returns 0.6
		ld static_steel_steel_oiled = .05; // () { return  0.05; } //returns 0.05
		ld static_teflon_steel = .04; // () { return .04; } //returns 0.04
		ld static_bone_lubricated_synovial_fluid = .016; // () { return 0.016; } //returns 0.016
		ld static_shoes_wood = .9; // () { return 0.9; } //returns 0.9
		ld static_shoes_ice = .1; // () { return 0.1; } //returns 0.1
		ld static_ice_ice = .1; // () { return 0.1; } //returns 0.1
		ld static_steel_ice = 0.4; // () { return 0.4; } // returns 0.4
	}s_coefficient;

	struct Kinetic
	{
		ld kinetic_rubber_concrete_dry = .7; // () { return 0.7; } //returns 0.7
		ld kinetic_rubber_concrete_wet = .5; // () { return 0.5; } //returns 0.5
		ld kinetic_wood_wood = .3; // () { return 0.3; } //return 0.3
		ld kinetic_waxedWood_wetSnow = .1; // () { return 0.1; } //return 0.1
		ld kinetic_metal_wood = .3; // () { return 0.3; } //returns 0.3
		ld kinetic_steel_steel_dry = .3; // () { return 0.3; } //returns 0.3
		ld kinetic_steel_steel_oiled = .03; // () { return 0.03; } //return 0.03
		ld kinetic_teflon_steel = .4; // () { return 0.4; } //return 0.4
		ld kinetic_bone_lubricated_synovial_fluid = .15; // () { return 0.15; } //returns 0.15
		ld kinetic_shoes_wood = .5; // () { return 0.5; } //returns 0.5
		ld kinetic_shoes_ice = .5; // () { return 0.5; } //return 0.5
		ld kinetic_ice_ice = .03; // () { return 0.03; } //return 0.03
		ld kinetic_steel_ice = .04; // () { return 0.04; } // return .04	
	}k_coefficient;
		
	/**
	 * method: friction_force(const ld mass, const ld acceleration, const ld friction)
	 * arguments: 1)mass 2)acceleration 3)friction
	 * purpose:calculates the force of friction, which is the same as the force
	 * returns: ld, friction
	 */
	ld static friction_force(const ld mass, const ld acceleration, const ld friction)
	{
		return mass * acceleration + friction;
	}

	/**
	 * method: friction_coefficient(const ld normalForce, const ld weight, const ld frictionForce)
	 * arguments: 1)normal force 2)weight 3)friction force
	 * purpose: calculates the frictional coefficient
	 * returns: ld, frictional coefficient
	 */
	ld static friction_coefficient(const ld normalForce, const ld frictionForce)
	{
		return (frictionForce) / (normalForce);
	}
	Friction()
	{
		_ptrFriction = nullptr;
	}
	
	Friction(const Friction& f)
	{
		_ptrFriction = f._ptrFriction;
	}
	~Friction() = default;
		
	
};