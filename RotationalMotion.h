#pragma once
/**
 * @class RotationalMotion
 * @details  class to add to the Physics class to help with solving complex physics problems
 * @author Ryan Zurrin
 * @date  11/15/2020
 */
#ifndef ROTATIONALMOTION_H
#define ROTATIONALMOTION_H
#include "UniformCircularMotion.h"

static int rotationalMotion_objectCount = 0;

class RotationalMotion : UniformCircularMotion
{
private:
	ld _angular_acceleration_;
	ld _linear_acceleration_;
	static void countIncrease() { rotationalMotion_objectCount += 1; }
	static void countDecrease() { rotationalMotion_objectCount -= 1; }
public:
	RotationalMotion* _rotational_motionPtr;
	/**
	 * @brief a structure filled with methods for finding the rotational inertia's of some commonly shaped objects
	 * @param M is the mass in kg
	 * @param R is the radius
	 * @param l is length
	 * @returns rotational Inertia (I)
	 */
	static struct RotationalInertias
	{
		ld static hoop_aboutCylinderAxis(const ld M, const ld R)
		{
			return M * (R * R);
		}
		ld static hoop_aboutAnyDiameter(const ld M, const ld R)
		{
			return (M * (R * R)) / 2.0;
		}
		ld static solidCylinderOrDisk_aboutCylinderAxis(const ld M, const ld R)
		{
			return (M * (R * R)) / 2.0;
		}
		ld static thinRod_aboutAxisThroughCenterToLength(const ld M, const ld l)
		{
			return (M * (l * l)) / 12.0;
		}
		ld static solidSphere_aboutAnyDiameter(const ld M, const ld R)
		{
			return (2.0 * M * (R * R)) / 5.0;
		}
		ld static annularCylinderRing_aboutCylinderAxis(const ld M, const ld R1, const ld R2)
		{
			return (M / 2.0)* ((R1 * R1) + (R2 * R2));
		}
		ld static solidCylinder_aboutCentralDiameter(const ld M, const ld R, const ld l)
		{
			return ((M * (R * R)) / 4.0) + ((M * (l * l)) / 12.0);
		}
		ld static thinRod_aboutAxisThroughOneEndToLength(const ld M, const ld l)
		{
			return (M * (l * l)) / 3.0;
		}
		ld static thinSphericalShell_aboutAnyDiameter(const ld M, const ld R)
		{
			return (2 * M * (R * R)) / 3;
		}
		ld static slab_aboutAxisThroughCenter(const ld M, const ld sideA, const ld sideB)
		{
			return (M * ((sideA * sideA) + (sideB * sideB)) / 12.0);
		}		
	}inertia;

	RotationalMotion()
	{
		_rotational_motionPtr = nullptr;
		_angular_acceleration_ = 0.0;
		_linear_acceleration_ = 0.0;
		countIncrease();
	}
	RotationalMotion(ld rpm, ld time)
	{
		_rotational_motionPtr = nullptr;
		set_angularVelocityW_(conversion_revolutions_min_to_radians_second(rpm));
		_angular_acceleration_ = get_angularVelocityW() / time;
		_linear_acceleration_ = rpm / time;
		countIncrease();
	}

	void set_angular_acceleration(const ld ac) { _angular_acceleration_ = ac; }
	void set_linear_acceleration(const ld ac) { _linear_acceleration_= ac; }
	ld get_angular_acceleration()const { return _angular_acceleration_; }
	ld get_linear_acceleration()const { return _linear_acceleration_; }
	void show_angular_acceleration()const { cout << "angular acceleration: " << _angular_acceleration_ << endl; }
	void show_linear_acceleration()const { cout << "linear acceleration: " <<_linear_acceleration_ << endl; }
	
	/**
	 * @brief calculates the angular acceleration
	 * @param v is the know angular velocity 
	 * @param rt is the radius or the time, works with either
	 * @returns the angular acceleration
	 */
	ld static angularAcceleration(const ld v, const ld rt)
	{
		return v / rt;
	}
	/**
	 * @brief calculates the angular acceleration using net torque and the rotational inertia of an object
	 * @param netTorque is the torque force
	 * @param inertia can be calculated with the inertia methods structure if not given
	 * @returns the angular acceleration
	 */ 
	ld static angularAcceleration_usingTorque_andInertia(const ld netTorque, const ld inertia)
	{
		return netTorque / inertia;
	}

	/**
	 * @brief calculates the angular acceleration using the kinematics formula vf^2 = vi^2 + 2*a*t
	 * reworked as wf^2 = wi^2 + 2 * a * rotationTheta = w = (2*a*rotationTheta)^.5
	 * @param angularAcceleration
	 * @param radians
	 * @return anguloar velocity
	 */
	ld static angularVelocity_kinematicsFormula(const ld angularAcceleration, const ld radians)
	{
		return pow(2 * angularAcceleration * radians, .5);
	}

	/**
	 * @brief calculates the angular velocity using the definition of angular momentum L=Iw so w=L/I
	 * @param L is the momentum of an object
	 * @param I is the inertia of an object
	 * @return angular velocity rad/s
	 */
	ld static angularVelocity(const ld L, const ld I)
	{
		return L / I;
	}
	
	/**
	 * @brief calculates the linear acceleration
	 * @param lv is the known linear velocity
	 * @param t is the time or radius, works with both
	 * @returns linear acceleration(tangential acceleration)
	 */
	ld static linearAcceleration(const ld lv, const ld tr)
	{
		return lv / tr;
	}

	/**
	 * @brief calculates the angular momentum using radius, Force, and time
	 * @param r is the radius
	 * @param F is the force
	 * @param t is the time
	 * @returns momentum in kgm^2/s
	 */
	ld static angularMomentum(const ld r, const ld F, const ld t)
	{
		return r * F * t;
	}
	
	/**
	 * @brief calculate the angular momentum of a object
	 * @param _I is the moment of inertia of the object
	 * @param w is the angular velocity
	 * @returns the the angular momentum kgm^2/s
	 */
	ld static angularMomentum(const ld _I, const ld w)
	{
		return _I * w;
	}	

	/**
	 * @brief calculates the linear acceleration which is (la = deltaV/deltaT, deltaV = rw, so la = r*deltaW/deltaT, a = deltaW/deltaT, so la = ra)
	 * @param r is the radius
	 * @param a is the angular acceleration
	 * @returns the tangential acceleration(linear acceleration)
	 */
	ld static tangentialAcceleration(const ld r, const ld a)
	{
		return r * a;
	}
	
	/**
	 * @brief calculates the time to stop from known angular velocities
	 */
	ld static timeToStopSpinning(const ld startAngVelocity, const ld endAngVelocity)
	{
		return -startAngVelocity / endAngVelocity;
	}

	/**
	 * @brief Sums inertia's of a system to return the total inertia 
	 */
	ld static inertiaSUM(const ld i1 = 0.0, const ld i2 = 0.0, const ld i3 = 0.0,const ld i4 = 0.0,
						 const ld i5 = 0.0, const ld i6 = 0.0, const ld i7 = 0.0, const ld i8 = 0.0,
						 const ld i9 = 0.0, const ld i10 = 0.0, const ld i11 = 0.0, const ld i12 = 0.0)
	{
		return i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9 + i10 + i11 + i12;
	}


	/**
	 * @brief calculate the net Work done in rotation
	 * @param netTorque is the total sum of all the torques acting in a system
	 * @param totalTheta is the total distance of rotation expressed in rad
	 * @returns net work causing rotation
	 */
	ld static netWork(const ld netTorque, const ld rad)
	{
		return netTorque * rad;
	}

	/**
	 * @brief calculates the net torque
	 * @param L is the change in angular momentum
	 * @param t is the time it takes
	 * @returns the net torque
	 */
	ld static netTorque(const ld L, const ld t)
	{
		return L / t;
	}

	/**
	 * @brief calculates the net torque using the radius and Force and angle
	 * @param r is the radius
	 * @param F is the force being applied in Newtons
	 * @param angleTheta is the angle the force is applied, default is at 90 degrees
	 * @return the net torque Nm
	 */
	ld static netTorque(const ld r, const ld F, const ld angleTheta = 90)
	{
		return r * F * sin(angleTheta * RADIAN);
	}

	/**
	 * @brief calculates the work-energy-theorem for rotational motion only'
	 * @param iRi initial Rotational Inertia
	 * @param iAv initial Angular Velocity
	 * @param fRi final Rotational Inertia
	 * @param fAv final Angular Velocity
	 * @returns the net Work
	 */
	ld static work_energy_theorem_for_rotation(const ld iRi, const ld iAv, const ld fRi, const ld fAv)
	{
		return (.5 * fRi * (fAv * fAv)) - (.5 * iRi * (iAv * iAv));
	}

	/**
	 * @brief calculates the rotational kinetic energy for an object what a moment of inertia _I and an angualr velocity w
	 * @param _I is the moment of inertia
	 * @param w is the angular velocity
	 * @returns the rotational kinetic energy
	 */
	ld static kinetic_energy_for_rotation(const ld _I, const ld w)
	{
		return (.5 * _I * (w * w));
	}

	/**
	 * @brief finds the max height of a helicptor of mass m a known KE
	 */
	ld static maxHeight(const ld KE, const ld mass)
	{
		return ((KE) / (mass * _Ga_));
	}

	/**
	 * @brief calculates the speed of a cylinder rolling down an incline
	 */
	ld static speedOfRollingCylinder(const ld height)
	{
		return pow(((4.0 * _Ga_ * height) / 3.0), .5);
	}
	/**
	 * @brief calculates the distance something moves from the radius and the radians
	 * @param radius is the radius of thing moving
	 * @param radians is the total rotation in radians
	 * @returns the distance traveled.
	 */
	ld static distanceTraveled(const ld radius, const ld radians)
	{
		return radius * radians;
	}

	/**
	 * @brief calculates the rotational torque which is the rotational analog of newtons law of F = ma
	 * @param m is the mass
	 * @param r is the radius
	 * @param aa is the angular acceleration
	 * @returns torque of rotation
	 */
	ld static rotationalTorque(const ld m, const ld r, const ld aa)
	{
		return m * (r * r) * aa;
	}

	/**
	 * @brief calculates the angular velocity of a spinning ice skater
	 * @param exA_inertia is the inertia of the skater with arms extended
	 * @param exA_angularVelocity is the rate of the skaters spinning in rev/s
	 * @param clA_inertia is the inertia of the skater with closed arms
	 * @returns the angular velocity of the skater with closed arms
	 */
	ld static angularVelocitySpinningSkater(const ld exA_inertia, const ld exA_angularVelocity, const ld clA_inertia)
	{
		return (exA_inertia / clA_inertia) * exA_angularVelocity;
	}




	
	~RotationalMotion()
	{
		delete _rotational_motionPtr;
		countDecrease();
	}
	
};

#endif
