// Drag class for extending the physics class 
// author: Ryan Zurrin
// last Modified: 10/10/2020
#ifndef DRAG_H
#define DRAG_H
#include <iostream>

#include "Friction.h"
#include "Vector2d.h"

static int drag_objectCount = 0;


class Drag 
{
	
private:	
	static void countIncrease() { drag_objectCount += 1; }
	static void countDecrease() { drag_objectCount -= 1; }
	
	
public:
	static void countShow() { std::cout << "drag count: " << drag_objectCount << std::endl; }
	
	Drag* _ptrDrag;
	ld _dragForce_;
	void show_dragForce()const { std::cout << "drag force: " << _dragForce_ << std::endl; }
	
	struct drag_coefficient
	{
		const ld airfoil = .05; // returns .05
		const ld toyotaCamry = .28; // returns .28
		const ld fordFocus = .32; // returns .32
		const ld hodnaCivic = .36; // returns .36
		const ld ferrariTestarossa = .37; // returns .37
		const ld dodgeRamPickup = .43; // returns .43
		const ld sphere = .45; // returns.45
		const ld hummerH2SUV = .64; // returns .64
		const ld skyDiver_feetFirst = .70; // returns .70 
		const ld bicycle = .90; // returns .90
		const ld skyDiver_horizontal = 1.0; // returns  1.0
		const ld circularFlatPlate = 1.12; // returns 1.12
		const ld dolphin = .0036; // returns .0036
		const ld bird = .4; // returns .4
		
	}coefficient;
	//suppresses the default constructor
	Drag()
	{
		_ptrDrag =  nullptr;
		_dragForce_ = 0.0;
		countIncrease();
		//countShow();
	}

	//copy constructor
	Drag(const Drag& r)
	{
		_ptrDrag = r._ptrDrag;
		_dragForce_ = r._dragForce_;
		countIncrease();
		//countShow();
	}

	//copy assignment operator
	Drag& operator=(const Drag& r)
	{
		if (this != &r)
		{
			_dragForce_ = r._dragForce_;
			_ptrDrag = r._ptrDrag;
			countIncrease();
			countShow();
		}
		return *this;
	}

	/**
	 * @brief Returns the value in the dragForce variable
	 * @returns dragForce
	 */
	ld return_dragForce()const { return _dragForce_; }

	/**
	 * @brief Returns the terminal velocity from drag force equation.
	 * fx = sqrt((2 * (mass * acceleration))/(density * dragCoeff * areaFace))
	 * @param mass of the object 
	 * @param dragCoeff is the drag coefficient 
	 * @param areaFace is the area the drag is working against
	 * @param density 
	 * @param acceleration
	 * @returns the terminal velocity.
	 */
	ld static terminal_velocity(const ld mass,
								const ld dragCoeff,
								const ld areaFace,
								const ld density,
								const ld acceleration = 9.8)
	{
		return sqrt((2 * (mass * acceleration))/(density * dragCoeff * areaFace));
	}

	/**
	 * @brief Returns the drag force experienced by an object.
	 * fx =.5 * (dragCoeff * density * areaFace * pow(velocity, 2))
	 * @param dragCoeff can be found with tables or by computation
	 * @param areaFace is total area being effected by drag and resistance
	 * @param density of the moving object
	 * @param velocity is the speed with a direction
	 * @returns: drag force
	 */
	ld static drag_force(const ld dragCoeff, const ld areaFace, const ld density, const ld velocity)
	{ return .5 * (dragCoeff * density * areaFace * pow(velocity, 2)); }
	
	 /**
	  * @brief Returns the frictional force – also called drag force – exerted on spherical objects with very
	  * small Reynolds numbers in a viscous fluid. fx = 6 * PI * radius * viscosity * velocity
	  * @param radius
	  * @param viscosity
	  * @param velocity	
	  * @returns force of sphere moving through a viscous matter
	  */
	 ld static stokes_law(const ld radius, const ld viscosity, const ld velocity)
	 { return 6.0 * _PI_ * radius * viscosity * velocity; }

	/**
	 * @brief Returns the viscosity of a fluid by using the time it takes an objects with
	 * know density and diameter.
	 * fx = (2 * density * time * (radius * radius) * _G_) / (9 * distance)
	 * @param density of object being measured
	 * @param diameter of the object
	 * @param distance the object is falling through the fluid
	 * @param time it takes in seconds for the objects to reach bottom
	 * @returns the viscosity of a fluid
	 */
	 ld static viscosity(const ld density, const ld diameter, const ld distance, const ld time)
	{
		 const ld radius = diameter / 2;
		 return (2 * density * time * (radius * radius) * _G_) / (9 * distance);		
	}


	/**
	 * destructor
	 */
	~Drag()
	{
		delete _ptrDrag;
		countDecrease();
		//countShow();
	}

};

#endif
