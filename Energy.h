#pragma once
/**
 * @class Energy
 * @details sub class contained within the Physics class and used for solving
 * complex physics problems
 * @author Ryan Zurrin
 * @date   10/21/2020
 */
#ifndef ENERGY_H
#define ENERGY_H
#include <iostream>

typedef  long double ld;

static int energy_objectCount = 0;

class Energy
{
private:
public:
	
	// Energy pointer
	Energy* _energyPtr;
	// variable for storing calculations
	ld _energy_;
	// method to print out the energy variable to the screen
	void show_energy()const { std::cout << "energy: " << _energy_ << std::endl; }
	// method to return the value stored in the energy variable
	ld get_energy()const { return _energy_; }
	static void countIncrease() { energy_objectCount += 1; }
	static void countDecrease() { energy_objectCount -= 1; }
	static void countShow() { std::cout << "energy object count: " << energy_objectCount << std::endl; }
	
	/**
	 * @brief  a structure containing the energy in joules of some common phenomena
	 */
	struct Joules
	{
		const ld big_bang = pow(10, 68);
		const ld super_nova = pow(10, 44);
		const ld fusion_all_hydrogen_earths_oceans = pow(10, 34);
		const ld annual_world_energy_use = 4 * pow(10, 20);
		const ld large_fusion_bomb_9megaTon = 3.8 * pow(10, 16);
		const ld hydrogen_1kg_fusion_to_helium = 6.4 * pow(10, 14);
		const ld uranium_1kg_nuclear_fission = 8 * pow(10, 13);
		const ld fission_bomb_10kiloton = 4.2 * pow(10, 13);
		const ld barrel_crude_oil = 5.9 * pow(10, 9);
		const ld tnt_1ton = 4.2 * pow(10, 9);
		const ld gasoline_1gallon = 1.2 * pow(10, 8);
		const ld electricity_use_daily_per_home = 7 * pow(10, 7);
		const ld food_intake_adult_daily_recommended = 1.2 * pow(10, 7);
		const ld car_1000kg_at_90kmh = 3.1 * pow(10, 5);
		const ld fat_1g_or_9point3_kcal = 3.9 * pow(10, 4);
		const ld carbohydrate_1g_or_4point1_kcal = 1.7 * pow(10, 4);
		const ld protein_1g_or_4point1_kcal = 1.7 * pow(10, 4);
		const ld tennis_ball_100kmh = 22;
		const ld mosquito_point5ms = 1.3 * pow(10, -6);
		const ld single_electron_in_tv_tube_beam = 4.0 * pow(10, -15);
		const ld energy_to_break_dna_strand = pow(10, -19);		
	}joules;
	/**
	 * @brief a structure containing the efficiency percent of common human
	 * body and mechanical devices
	 */
	struct Efficiency
	{
		const int cycling_and_climbing = 20;
		const int swimming_surface = 2;
		const int swimming_submerged = 4;
		const int shoveling = 3;
		const int weightlifting = 9;
		const int steam_engine = 17;
		const int gasoline_engine = 30;
		const int diesel_engine = 35;
		const int nuclear_power_plant = 35;
		const int coal_power_plant = 42;
		const int electric_motor = 98;
		const int compact_fluorescent_light = 20;
		const int gas_heater_residential = 90;
		const int solar_cell = 10;
	}eff;
	/**
	 * @brief Power output or consumption in watts per hour of some common things
	 */
	struct Watts_Per_Hour
	{
		const ld supernova_peak = 5 * pow(10, 37);
		const ld milky_way_galaxy = pow(10, 37);
		const ld crab_nebula_pulsar = pow(10, 28);
		const ld sun_ours = 4 * pow(10, 26);
		const ld volcanic_eruption_maximum = 4 * pow(10, 15);
		const ld lightning_bolt = 2 * pow(10, 12);
		const ld nuclear_power_plant_total_electric_and_heat_transfer = 3 * pow(10, 9);
		const ld aircraft_carrier_total_useful_and_heat_transfer = pow(10, 8);
		const ld dragster_total_useful_and_heat_transfer = 2 * pow(10, 6);
		const ld car_total_useful_and_heat_transfer = 8 * pow(10, 4);
		const ld football_player_total_useful_and_heat_transfer = 5 * pow(10, 3);
		const ld clothes_dryer = 4 * pow(10, 3);
		const ld person_at_rest_all_heat_transfer = 100;
		const ld typical_incandescent_light_buld_total_useful_and_heat_transfer = 60;
		const ld heart_person_at_rest_total_useful_and_heat_transfer = 8;
		const ld electric_clock = 3;
		const ld pocket_calculator = pow(10, -3);	
		
	}watts;
	
	//constructor	
	Energy()
	{
		_energy_ = 0.0;
		_energyPtr = nullptr;
		countIncrease();
	}
	
	/**
	 * @brief Returns the conversion from joules to kilo calories
	 * @param joules
	 * @returns kilocalories
	 */
	ld static conversion_joules_to_kcal(const ld joules)
	{
		const int num = 4184;
		return joules / num;
	}
	/**
	 * @brief Returns the work(W) done on a system by a constant force in the
	 * direction of motion times the distance through which the force acts
	 * @param force is the magnitude of the force on the system
	 * @param displacement_magnitude is the displacement of the system
	 * @param theta is the angle between the force vector and the displacement vector
	 * @returns the work done on a system
	 */
	ld static work(const ld force, const ld displacement_magnitude, const ld theta = 1)
	{
		return force * displacement_magnitude * cos(theta * RADIAN);
	}
	/**
	 * @brief Returns the work when the mass, final velocity, and height of y are known
	 * @param mass is the mass in kg
	 * @param vf is the final velocity
	 * @param h is the height of the y component
	 * @param g is the acceleration which is defaulted to 9.8 for gravity
	 * @returns the total work 
	 */
	ld static work2(const ld mass, const ld vf, const ld h, const ld g = 9.8)
	{
		return (.5 * mass * (vf * vf) + (mass * g * h));
	}
	/**
	 * @brief Returns the work going up stairs with constant acceleration
	 * @param mass in kg
	 * @param height in m
	 * @returns total work
	 */
	ld static work3(const ld mass, const ld height)
	{
		return mass * _G_ * height;
	}
	/**
	 * @brief Returns the work down by friction lowering something down a slope
	 * @param coefficient is of friction
	 * @param mass in kg
	 * @param theta1
	 * @param distance
	 * @param theta2 is defaulted to 180 degrees if you set your coordinate system perpendicular to the motion
	 * @returns the work done by friction
	 */
	ld static work_friction_down_slope(const ld coefficient, const ld mass, const ld theta1, const ld distance, const ld theta2 = 180)
	{
		return coefficient * mass * _G_ * cos(theta1 * RADIAN) * distance * cos(theta2);
	}
	/**
	 * @brief Returns the kinetic energy of an object
	 * fx = .5 * mass * (velocity * velocity)
	 * @param mass of object in kg
	 * @param velocity of object in m/s
	 * @returns KE (kinetic energy)
	 */
	ld static kinetic_energy_translational(const ld mass, const ld velocity)
	{
		return .5 * mass * (velocity * velocity);
	}
	/**
	 * @brief Returns the velocity(speed) solved by rearranging the work-energy theorem
	 * fx = sqrt((2 * netWork) / (mass))
	 * @param netWork is the total energy in newtons
	 * @param mass in kg
	 * @returns the velocity 
	 */
	ld static velocity_from_work_energy_theorem(const ld netWork, const ld mass)
	{
		return sqrt((2 * netWork) / (mass));
	}
	/**
	 * @brief Returns the speed calculated from something falling from a specified height
	 * @param height is the height of the object
	 * @param initialVelocity is the initial speed if not starting from a rest.
	 * Default is 0 assumed to be starting from rest
	 * @returns final speed
	 */
	ld static speed_from_height(const ld height, const ld initialVelocity = 0)
	{
		return sqrt(2 * _G_ * height + (initialVelocity*initialVelocity));
	}
	/**
	 * @brief Returns the distance traveld
	 * @param netWork is the total work from a system
	 * @param frictionForce is the force the friction is causing on the system
	 * @returns the distance
	 */
	ld static distance(const ld netWork, const ld frictionForce)
	{
		return abs(netWork / frictionForce);
	}
	/**
	 * @brief Returns the change in gravitational potential energy
	 * fx = mass * _G_ * height;
	 * @param mass is in kg
	 * @param height is the displacement in the y value
	 */
	ld static potential_energy_gravity_PEg(const ld mass, const ld height)
	{
		return mass * _G_ * height;
	}
	/**
	 * @brief Returns the potential energy of a conservative source, such as a spring
	 * @param forceConstant
	 * @param deformation is the amount of change in the system
	 */
	ld static potential_energy_conservative_PEc(const ld forceConstant, const ld deformation)
	{
		return .5 * (forceConstant * (deformation * deformation));
	}
	/**
	 * @brief Returns the force on impact
	 * @param mass in kg
	 * @param height from which the fall occurs
	 * @param compressionDistance is the distance of deformation on impact
	 * @returns the net force acting on the system
	 */
	ld static force_to_stop(const ld mass, const ld height, const ld compressionDistance)
	{
		return ((mass * _G_) * height)/ (compressionDistance);
	}
	/**
	 * @brief Returns the speed of object just after release using the equation
	 * for the conservation of mechanical energy solved for the final velocity just
	 * after toy car released by spring
	 * @param k is the force in Newtons/min
	 * @param m is the mass in kg of object
	 * @param x is the deformation of the spring used or object of PE
	 * @returns the speed m/s
	 */
	ld static conservation_equation_for_velocityFinal_bottom(const ld k, const ld m, const ld x)
	{
		return sqrt(k / m) * x;
	}
	/**
	 * @brief Returns the speed of an object after it reaches the top of a slope
	 * from being pushed by a spring
	 * @param k is the force in N/m
	 * @param m is the mass in kg
	 * @param x is the deformation of the spring
	 * @param y is the change in the y component value
	 * @returns the final speed
	 * 
	 */
	ld static conservation_equation_for_velocityFinal_top(const ld k, const ld m, const ld x, const ld y)
	{
		return sqrt((k / m) * (x * x) - (2 * _G_ * y));
	}
	/**
	 * @brief Returns the distance traveled sliding on level surface
	 * fx = m * (vi * vi) / (2 * ff)
	 * @param m is the mass in kg
	 * @param vi is the initial velocity
	 * @param ff is the frictional force
	 * @returns the distance traveled while sliding on level surface
	 */
	ld static distance_traveled_sliding_level(const ld m, const ld vi, const ld ff)
	{
		return (m * (vi * vi) / (2 * ff));
	}
	/**
	 * @brief Returns the distance traveled sliding on an incline
	 * fx = (.5 * (m * (vi * vi)) / (ff + (m * _G_) * sin(theta * RADIAN)))
	 * @param m is the mass in kg
	 * @param vi is the initial velocity
	 * @param ff is the frictional force
	 * @param theta is the angle of the slope
	 * @returns the distance traveled while sliding on incline
	 */
	ld static distance_traveled_sliding_slope(const ld m, const ld vi, const ld ff, const ld theta)
	{
		return (.5 * (m * (vi * vi)) / (ff + (m * _G_) * sin(theta * RADIAN)));
	}
	/**
	 * @brief Returns the efficiency (Eff) of an energy conversion process
	 * fx = workEnergyOut / totalEnergyIn
	 * @param workEnergyOut is the total energy used
	 * @param totalEnergyIn is the total amount of energy being provided to a system for work
	 * @returns the efficiency
	 */
	ld static efficiency(const ld workEnergyOut, const ld totalEnergyIn)
	{
		return workEnergyOut / totalEnergyIn;
	}
	/**
	 * @brief Returns the power 
	 */
	ld static power(const ld work, const ld time)
	{
		return work / time;
	}
	/**
	 * @brief calculates the force needed to bring a car to rest given its mass, its speed and the distance
	 * it took to stop. This can be used to calculate the force from crashes and similar scenarios
	 * @param mass in gk
	 * @param velocity in m/s
	 * @param distance in m
	 * @returns the force exerted to make stop
	 */
	ld static force_needed_to_bring_car_to_rest(const ld mass, const ld velocity, const ld distance)
	{
		return (.5 * mass * (velocity * velocity)) / (distance);
	}
	/**
	 * @brief calculates the weight of a system from the loss in PE over a distance
	 * @param jouleLoss is the total loss in PE(potential energy)
	 * @param distance is the total distance that caused the energy loss
	 * @returns the weight of a system
	 */
	ld static weight_from_joule_loss_over_distance(const ld jouleLoss, const ld distance)
	{
		return jouleLoss / distance;
	}

	//ld static force


	
	~Energy()
	{
		delete _energyPtr;
		countDecrease();
	}
	
};
#endif

