#pragma once
/**
 * @class Momentum
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   10/26/2020
 */
#ifndef MOMENTUM_H
#define MOMENTUM_H

class Momentum
{
private:
public:
	Momentum* _momentumPtr;
	Momentum()
	{
		_momentumPtr = nullptr;
	}

	/**
	 * @brief calculates the momentum of a system from mass and velocity (p = mv)
	 * @param mass should be in kg
	 * @param velocity as m/s
	 * @returns the momentum of a system
	 */
	ld static momentum(const ld mass, const ld velocity)
	{
		return mass * velocity;
	}

	/**
	 * @brief calculates the linear momentum
	 * p = (mass * distance) / time
	 * @param mass in kg
	 * @param distance in meters
	 * @param time is seconds
	 * @returns linear momentum kgm/s
	 */
	ld static momentum_linear(const ld mass, const ld distance, const ld time)
	{
		return (mass * distance) / time;
	}

	/**
	 * @brief calculates the change in momentum (impulse)
	 * @param avgNetForce is the average net external force
	 * @param changeInTime is the time the force acts
	 * @returns impulse (change in momentum)
	 */
	ld static impulse(const ld avgNetForce, const ld changeInTime)
	{
		return avgNetForce * changeInTime;
	}

	/**
	 * @brief computes the average net force exerted on a system
	 * Fn =  (mass * velocity) / time
	 * @param mass in kg
	 * @param velocity in m/s
	 * @param time in seconds
	 * @returns the net force in N (newtons)
	 */
	ld static newtons_2nd_law_as_momentum(const ld mass, const ld velocity, const ld time)
	{
		return (mass * velocity) / time;
	}

	/**
	 * @brief computes the net force using mass, velocity and the distance the force is applied
	 * Fn = mass * (velocity * velocity) / (2 * distance)
	 * @param mass in kg
	 * @param velocity in m/s
	 * @param distance in meters
	 * @returns the net force in N (newtons)
	 */
	ld static force_net_using_distance(const ld mass, const ld velocity, const ld distance)
	{
		return (mass * (velocity * velocity) / (2 * distance));
	}

	/**
	 * @brief calculates the ratio of two numbers
	 * @param ratioOf is the ratio of something to 
	 * @param to is the something the ratio is of
	 * @returns the ratio of something to something else
	 */
	ld static ratio(const ld ratioOf, const ld to)
	{
		return ratioOf / to;
	}

	/**
	 * @brief computes the mass of a system
	 * m = momentum/velocity
	 * @param momentum
	 * @param velocity
	 * @returns mass
	 */
	ld static mass(const ld momentum, const ld velocity)
	{
		return momentum / velocity;
	}

	/**
	 * @brief calculates the mass of an object when the final velocity, the force and the time
	 * m =(force * time) / velocity
	 * @param force in N (newtons)
	 * @param time is seconds
	 * @param velocity in m/s
	 * @returns the mass in kg
	 */
	ld static mass(const ld force, const ld time, const ld velocity)
	{
		return (force * time) / velocity;
	}

	/**
	 * @brief computes the velocity of a system
	 * @param momentum
	 * @param mass
	 * @returns velocity
	 */
	ld static velocity(const ld momentum, const ld mass)
	{
		return momentum / mass;
	}

	/**
	 * @brief calculates the final velocity of a system
	 * Vf =  (impulse + mass * velocityInitial) / mass
	 * @param impulse in kgm/s
	 * @param mass in kg
	 * @param velocityInitial in m/s
	 * @returns the final velocity in m/s
	 */
	ld static velocity_final(const ld impulse, const ld mass, const ld velocityInitial = 0)
	{
		return (impulse + mass * velocityInitial) / mass;
	}

	/**
	 * @brief calculates the velocity of a mass in a two mass system where one velocity and masses are known
	 * Vb = (mass_a * velocity_a) / mass_b
	 * @param mass_a in kg
	 * @param mass_b in kg is the mass of the unknown velocity
	 * @param velocity_a in m/s
	 * @returns the velocity of the second mass 
	 */
	ld static velocity_B_final_mass(const ld mass_a, const ld mass_b, const ld velocity_a)
	{
		return (mass_a * velocity_a) / mass_b;
	}

	/**
	 * @brief calculates the velocity of a mass in a two mass system where one velocity and masses are known
	 * Vf = ((force_b*time) + (mass_a*velocity_a))/(mass_a);
	 * @param mass_a in kg
	 * @param velocity_a in N (newtons)
	 * @param force_b in m/s
	 * @param time in seconds
	 * @returns the velocity
	 * 
	 */
	ld static velocity_B_final_force(const ld mass_a, const ld velocity_a, const ld force_b, const ld time )
	{
		return ((force_b * time) + (mass_a * velocity_a)) / (mass_a);
	}

	/**
	 * @brief calculates the time it takes to impact a system a certain distance given a starting
	 * velocity and assuming the final velocity is 0
	 * t = (2 * distance) / (velocity_i + velocity_f)
	 * @param velocity_i is the initial velocity of the object
	 * @param distance is the amount of distance something is being impacted such as a nail being
	 * driven into wood
	 * @param velocity_f is the final velocity and it is 0 by default
	 * @returns the time it takes to impact the system a given distance
	 */
	ld static time_impact_duration(const ld velocity_i,  const ld distance, const ld velocity_f = 0)
	{
		return (2 * distance) / (velocity_i + velocity_f);
	}
	
	/**
	 * @brief computes the time for an object to stop given its mass, velocity, and stopping force
	 * t = (mass * velocity) / stoppingForce
	 * @param mass in kg
	 * @param velocity in m/s
	 * @param stoppingForce in N (newtons)
	 * @returns the time to stop in seconds
	 */
	ld static time_to_bring_to_rest(const ld mass, const ld velocity, const ld stoppingForce)
	{
		return (mass * velocity) / stoppingForce;
	}

	/**
	 * @brief calculates the y component of and angled velocity vector
	 * @param v is the magnitude of the velocity vector
	 * @param theta is the angle opposite of the y component in question
	 * @param y_vector90 is any additional 90 degree magnitude that may need to be added.
	 * defaulted to 0
	 * @returns the magnitude of the y component of a vector
	 */
	ld static velocity_vector_y(const ld v, const ld theta, const ld y_vector90 = 0)
	{
		return v * sin(theta * RADIAN) + y_vector90;
	}

	/**
	 * @brief calculates the x component of and angled velocity vector
	 * @param v is the magnitude of the velocity vector
	 * @param theta is the angle opposite of the x component in question
	 * @param x_vector180 is any additional 180 degree magnitude that may need to be added.
	 * defaulted to 0
	 * @returns the magnitude of the x component of a vector
	 */
	ld static velocity_vector_x(const ld v, const ld theta, const ld x_vector180 = 0)
	{		
		return v * cos(theta * RADIAN) + x_vector180;
	}

	/**
	 * @brief calculates the final velocity of two masses colliding and forming one moving mass of debris
	 * @param mass_a in kg
	 * @param v_a velocity of mass a in m/s
	 * @param mass_b in kg
	 * @param v_b velocity of mass_b in m/s
	 * @returns the velocity of the colliding masses
	 */
	ld static collision_velocity_2_moving_masses(const ld mass_a, const ld v_a, const ld mass_b, const ld v_b)
	{
		return ((mass_a * v_a) + (mass_b * v_b)) / (mass_a + mass_b);
	}

	/**
	 * @brief Returns the velocities following an elastic collision with one still mass
	 * @param movingMass1 in kg
	 * @param stillMass in kg
	 * @param v1 in m/s is the velocity of mass1
	 * @returns vector<mass1, mass2>
	 */
	std::vector<ld> static collision_elastic(const ld movingMass1, const ld stillMass, const ld v1)
	{
		vector<ld> velocities = { 0.0, 0.0 };
		velocities[0] = (v1 * (movingMass1 - stillMass)) / (movingMass1 + stillMass);
		velocities[1] = v1 - abs(velocities[0]);		
		return velocities;
	}
	
	/**
	 * @brief calculates the starting velocity of a mass2 in a totally inelastic collision
	 */
	ld static totally_inelastic_collision_v2(const ld mass1, const ld mass2, const ld m1StartingMomentum, const ld m1EndingMomentum)
	{
		const ld m1vs = m1StartingMomentum/mass1;
		const ld m1vf = m1EndingMomentum / mass1;
	

		return ((mass1 * m1vf) + (mass2 * m1vf) - (mass1 * m1vs)) / (mass2);
		
	}

	
	/**
	 * @brief Returns a vector with the values of recoil velocity, internal kinetic energy of system,
	 * kinetic energy of system after system, and the total change of energy in system
	 * @param movingMass1 in kg
	 * @param stillMass in kg
	 * @param v1 is the velocity of the movingMass1
	 * @returns vector<recoilVelocity, internalKineticEnergySystem, afterCollisionKEofSystem, totalChangeInSystem>
	 */
	std::vector<ld> static collision_inelastic(const ld movingMass1, const ld stillMass, const ld v1)
	{		
		const ld recoilVelocity = (movingMass1) / (movingMass1 + stillMass) * v1;		
		const ld internalKineticEnergySystem = .5 * (movingMass1) * (v1 * v1);		
		const ld afterCollisionKEofSystem = .5 * (movingMass1 + stillMass) * (recoilVelocity * recoilVelocity);		
		const ld totalChangeInSystem = afterCollisionKEofSystem - internalKineticEnergySystem;
		vector<ld> results = { recoilVelocity, internalKineticEnergySystem, afterCollisionKEofSystem, totalChangeInSystem };
			
		return results;
	}

	/**
	 * @brief Returns the velocity of a rocket launch when lift mass, ehaust velocity and fuel burn rate is known
	 * @param liftMass in kg
	 * @param exhaustVelocity in m/s
	 * @param fuelBurnRate in kg/s
	 * @returns acceleration of rocket
	 */
	ld static rocket_launch_acceleration(const ld liftMass, const ld exhaustVelocity, const ld fuelBurnRate)
	{
		return ((exhaustVelocity / liftMass) * (fuelBurnRate)) - _Ga_;
	}

	/**
	 * @brief Returns the impact force experienced by a crash test dummy by the seat belt
	 * @param mass in kg
	 * @param v in m/s is the velocity of the moving object before coming to rest v=0
	 * @param time in seconds
	 * @returns Force in newtons of the impact 
	 */
	ld static force_impact(const ld mass, const ld v, const ld time)
	{
		return (-(mass)*v) / (time);
	}

	/**
	 * @brief Returns the initial speed of a projectile as it launches from ground level at a particular angle
	 * and returns to ground level a certain distance away 
	 * Vi = sqrt((distance * _Ga_) / (2 * cos(angle * RADIAN) * sin(angle * RADIAN)))
	 * @param distance
	 * @param angle
	 * @returns the initial launch speed
	 */
	ld static projectile_launch_speed(const ld distance, const ld angle)
	{
		return sqrt((distance * _Ga_) / (2 * cos(angle * RADIAN) * sin(angle * RADIAN)));
	}

	/**
	 * @brief Returns the total amount of fuel mass loss a projectile would need to achieve the specified
	 * launch speed  %loss = 1 - exp(-projectileLaunchSpeed / fuelEjectionSpeed)
	 * @param projectileLaunchSpeed in m/s
	 * @param fuelEjectionSpeed in m/s
	 * @returns mass loss % 
	 */
	ld static mass_loss_of_projectile(const ld projectileLaunchSpeed, const ld fuelEjectionSpeed)
	{
		return 1 - exp(-projectileLaunchSpeed / fuelEjectionSpeed);
	}

	/**
	 * @brief Returns the Range based off of velocity, angle and total time in seconds
	 * @param v in m/s is the velocity or initial launch speed
	 * @param angle is the angle of launch
	 * @param time in seconds is the time in flight
	 * @returns  range in meters
	 */
	ld static range_of_projectile(const ld v, const ld angle, const ld time)
	{
		return v * cos(angle * RADIAN) * time;
	}

	
	
	~Momentum()
	{
		delete _momentumPtr;
	}
	
};
#endif
