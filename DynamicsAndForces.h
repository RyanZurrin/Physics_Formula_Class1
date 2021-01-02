#pragma once
/**
 * @class DynamicsAndForces
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   10/15/2020
 */
#ifndef DYNAMICSANDFORCES_H
#define DYNAMICSANDFORCES_H
#include <iostream>
#include <vector>
const ld GA = 9.8;

static int dynamicsAndForces_objectCount = 0;


class DynamicsAndForces
{
private:
	static void countIncrease() { dynamicsAndForces_objectCount += 1; }
	static void countDecrease() { dynamicsAndForces_objectCount -= 1; }
public:
	DynamicsAndForces* _dynamicForcePtr;

	DynamicsAndForces()
	{
		_dynamicForcePtr = nullptr;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	DynamicsAndForces(const DynamicsAndForces& t)
	{
		_dynamicForcePtr = t._dynamicForcePtr;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	DynamicsAndForces(DynamicsAndForces&& t) noexcept
	{
		_dynamicForcePtr = t._dynamicForcePtr;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	DynamicsAndForces& operator=(const DynamicsAndForces& t)
	{
		if (this != &t)
		{
			_dynamicForcePtr = t._dynamicForcePtr;
			countIncrease();
		}
		return *this;
	}

	static void show_dynamicsAndForces_objectCount() { std::cout << "\ndynamics and forces object count: " << dynamicsAndForces_objectCount << std::endl; }
	static int get_dynamicsAndForces_objectCount() { return dynamicsAndForces_objectCount; }


	/**
	 * method: netForce(const ld totalForces, const ld totalFriction)
	 * arguments: 1)total forces  2)total friction
	 * purpose:	calculates the forces total including frictions
	 * returns: ld net force
	 */
	static ld netForce(const ld totalForces, const ld totalFriction)
	{
		return totalForces - totalFriction;
	}

	/**
	 * method: gravitational_force_on_mass(ld mass) const
	 * arguments: mass
	 * purpose:	applies the force of gravity on a mass to give the weight
	 * returns: ld weight
	 */
	static ld weight(const ld mass)
	{
		return mass * GA;
	}

	/**
	 * method: newtons_second_law_for_force(ld mass, ld acceleration)
	 * arguments: ld mass, ld acceleration
	 * purpose:	uses Newtons second law of motion to calculate the force of a something
	 * returns: ld, force
	 */
	static ld newtons_second_law_for_force(const ld mass, const ld acceleration)
	{
		return mass * acceleration;
	}

	/**
	 * method: newtons_second_law_for_acceleration(ld netForce, ld mass) const
	 * arguments: netForce, mass
	 * purpose:	calculates the acceleration due to a force
	 * returns: ld, acceleration
	 */
	static ld newtons_second_law_for_acceleration(const ld netForce, const ld mass)
	{
		return netForce / mass;
	}

	/**
	 * method: newtons_second_law_for_mass(ld netForce, ld acceleration) const
	 * arguments: netForce, acceleration
	 * purpose:calculates the mass of an object from the force and acceleration
	 * returns: ld, mass
	 */
	static ld newtons_second_law_for_mass(ld netForce, ld acceleration)
	{
		return netForce / acceleration;
	}

	/**
	 * method: drag_force(const ld appliedForce, const ld mass, const ld acceleration)
	 * arguments: 1)appliedForce 2)mass 3)acceleration
	 * purpose:calculates the drag or resistance
	 * returns: ld, drag
	 */
	static ld drag_force(const ld appliedForce, const ld mass, const ld acceleration)
	{
		return appliedForce - (mass * acceleration);
	}

	/**
	 * method: normal_force(const ld mass, const ld acceleration = GA)
	 * arguments: 1)mass 2)acceleration
	 * purpose: calculates the normal force, weight
	 * returns: ld, normal force
	 */
	static ld normalForce(const ld mass, const ld acceleration = GA)
	{
		return mass * acceleration;
	}

	/**
	 * method: normal_force_angle(const ld mass, const ld angleTheta)
	 * arguments: 1)mass 2)acceleration
	 * purpose: calculates the normal force on an angle
	 * returns: ld, normal force
	 */
	static ld normalForce_angleDOWN(const ld mass, const ld angleTheta)
	{
		return mass * GA * cos(angleTheta * RADIAN);
	}
	/**
	 * method: normal_force_angleUp(const ld mass, const ld angleTheta)
	 * arguments: 1)mass 2)acceleration
	 * purpose: calculates the normal force on an angle
	 * returns: ld, normal force
	 */
	static ld normalForce_angleUP(const ld mass, const ld angleTheta)
	{
		return mass * GA * sin(angleTheta * RADIAN);
	}

	/**
	 * @brief calculates the normal force on an angle
	 * @param angleTheta angle in degrees
	 * @param kC kineticCoefficient
	 * @returns ld, normal force
	 */
	static ld acceleration_slope_simpleFriction(const ld angleTheta, const ld kC)
	{
		return GA * (sin(angleTheta * RADIAN) - (kC * cos(angleTheta * RADIAN)));
	}

	/**
	 * @brief finds the ratio between two numbers
	 * @param top is the top part of the ratio
	 * @param bottom is the bottom part of the ratio
	 * @returns the ratio between two numbers
	 */
	static ld ratio(const ld top, const ld bottom)
	{
		return top / bottom;
	}

	/**
	 * @brief calculates the tension on a horizontal rope as it gets hung from
	 * @param mass in kg of object causing tension
	 * @returns tension in Newtons
	 */
	static ld tensionOnSingleStrand(const ld mass)
	{
		return mass * GA;
	}

	/**
	 * @brief calculates the tension on a horizontal rope as it gets hung from
	 * @param mass in kg of object causing tension
	 * @param a acceleration m/s
	 * @returns tension in Newtons
	 */
	static ld tensionOnSingleStrandWithAccelerationUpward(const ld mass, const ld a)
	{
		return (mass * GA) + (mass * a);
	}

	/**
	 * @brief calculates the tension on a horizontal rope as it gets hung from
	 * @param mass in kg of object causing tension
	 * @param fCoeff kinetic frictional coefficient
	 * @param a acceleration m/s
	 * @returns tension in Newtons
	 */
	static ld tensionOnSingleStrandWithFrictionWhileAccelerating(const ld mass, const ld fCoeff, const ld a)
	{
		const ld Nf = mass * GA;
		const ld friction = fCoeff * Nf;
		const ld accF = mass * a;
		return friction + accF;
	}

	/**
	 * @brief calculates the tension on a horizontal rope as it gets hung from
	 * @param mass1 in kg of object1
	 * @param mass2 in kg of object2
	 * @returns tension in Newtons
	 */
	static ld tensionOnMultipleStrandsIdealPully(const ld mass1, const ld mass2)
	{
		return ((2.0*GA)*(mass1*mass2))/(mass1 + mass2);
	}


	/**
	 * @brief calculates the tension on a horizontal rope as it gets hung from
	 * @param mass in kg of object1
	 * @param theta1 angle side 1 in degrees
	 * @param theta2 angle side 2 in degrees
	 * @returns tension in Newtons
	 */
	static vector<ld> tensionOnMultipleStrandsHangingObject(const ld mass, const ld theta1, const ld theta2)
	{
		vector<ld> result = { 0.0, 0.0, 0.0 };
		result[0] = cos(theta1 * RADIAN) * (mass * GA);
		result[1] = cos(theta2 * RADIAN) * (mass * GA);
		result[2] = result[0] + result[1];
		return result;
	}
	/**
	 * @brief calculates the tension on a horizontal rope as it gets hung from
	 * @param mass1 in kg of object1
	 * @param mass2 in kg of object2
	 * @returns tension in Newtons
	 */
	static ld tensionOnCableMultipleStrandsMiddle(const ld mass, const ld theta)
	{
		return (mass * GA)/(2.0*sin(theta*RADIAN));
	}





	~DynamicsAndForces()
	{
		delete _dynamicForcePtr;
	}

};
#endif

