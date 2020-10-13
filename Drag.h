#pragma once
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
	//default constructor
	Drag()
	{
		_ptrDrag = nullptr;
		_dragForce_ = 0.0;
		countIncrease();
		countShow();
	}

	//copy constructor
	Drag(const Drag& r)
	{
		_ptrDrag = r._ptrDrag;
		_dragForce_ = r._dragForce_;
		countIncrease();
		countShow();
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
	 * method: return_drag_force()const 
	 * arguments: none
	 * purpose:	returns the value in the dragForce variable
	 * returns: ld, displacement.
	 */
	ld return_dragForce()const { return _dragForce_; }

	/**
	 * method:  terminal_velocity
	 * arguments: 1)mass 2)drag coefficient 3)area face 4)density 5)acceleration
	 * purpose:	returns the terminal velocity from drag force equation
	 * returns: ld, terminal velocity.
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
	 * method:  drag_force(const ld dragCoeff, const ld areaFace, const ld density, const ld velocity)
	 * arguments: 1)dragCoeff 2)areaFace 3) 4)density 5)velocity
	 * purpose:	returns the drag force experienced by an object
	 * returns: ld, drag force
	 */
	ld static drag_force(const ld dragCoeff, const ld areaFace, const ld density, const ld velocity)
	{ return .5 * (dragCoeff * density * areaFace * pow(velocity, 2)); }
	
	 /**
	  * method:  stokes_law(const ld radius, const ld viscosity, const ld velocity)
	  * arguments: 1)radius 2)viscosity 3)velocity
	  * purpose:	returns the terminal velocity from drag force equation
	  * returns: ld, force of sphere moving through a viscosious matter
	  */
	 ld static stokes_law(const ld radius, const ld viscosity, const ld velocity)
	 { return 6 * PI * radius * viscosity * velocity; }


	/**
	 * destructor
	 */
	~Drag()
	{
		delete _ptrDrag;
		countDecrease();
		countShow();
	}

};

#endif
