// Drag class for extending the physics class 
// author: Ryan Zurrin
// last Modified: 10/10/2020
#ifndef DRAG_H
#define DRAG_H
#include <iostream>

#include <string.h>
#include "Friction.h"
#include "Vector2d.h"

static int drag_objectCount = 0;

static struct DragCoefficients
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
	const ld frisbee = .080; // returns .080
	const ld rectangularBox = 2.1; //returns 2.1
	const ld longFlatPlate90deg = 1.98; // returns 1.98
	const ld motorcycleAndRider = 1.8; // returns 1.8
	const ld personUpright = 1.15; // returns 1.15
	const ld convertibleOpenTop = .65; // returns .65
	const ld supersonicFighter = .016; // returns .016
	const ld solarPanelArray6x4 = 4.1; // returns 4.1


}drag_coefficients;

class Drag 
{
	
private:	
	static void countIncrease() { drag_objectCount += 1; }
	static void countDecrease() { drag_objectCount -= 1; }
	ld _dragForce_;
	ld _dragCoefficient_;
	
public:
	static void countShow() { std::cout << "drag count: " << drag_objectCount << std::endl; }
	Drag* _ptrDrag;	

	/**
	 * @brief displays the data stored in the dragForce variable
	 */
	void show_dragForce()const { std::cout << "drag force: " << _dragForce_ << std::endl; }
	/**
	 * @brief displays the data stored in the dragCoefficient variable
	 */
	void show_dragCoefficient()const { std::cout << "drag coefficient: " << _dragCoefficient_ << std::endl; }

	/**
	 * @brief sets the dragForce variable;
	 */
	void set_dragForce(const ld dF) { _dragForce_ = dF; }
	/**
	 * @brief sets the dragCoefficient variable;
	 */
	void set_dragCoefficient(const ld C) { _dragCoefficient_ = C; }
	

	//suppresses the default constructor
	Drag()
	{
		_ptrDrag =  nullptr;
		_dragForce_ = 0.0;
		_dragCoefficient_ = 0.0;
		countIncrease();
		//countShow();
	}
	Drag(string obj)
	{
		
		_ptrDrag = nullptr;
		_dragForce_ = 0.0;
		
		_dragCoefficient_ = setCoefficient(obj);
		countIncrease();
	}

	Drag(ld dC)
	{
		_ptrDrag = nullptr;
		_dragForce_ = 0.0;
		_dragCoefficient_ = dC;
		countIncrease();
	}

	//copy constructor
	Drag(const Drag& r)
	{
		_ptrDrag = r._ptrDrag;
		_dragForce_ = r._dragForce_;
		_dragCoefficient_ = r._dragCoefficient_;
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
			_dragCoefficient_ = r._dragCoefficient_;
			countIncrease();
			countShow();
		}
		return *this;
	}
private:
	ld static setCoefficient(string &test)
	{
		ld val = 0;
		if (test == "airfoil" || test == "airFoil" || test == "AirFoil") { return val = .05; }
		if (test == "toyotaCamry" || test == "toyotacamry" || test == "ToyotaCamry" || test == "toyotaC") { return val = .28; }
		if (test == "fordFocus" || test == "FordFocus" || test == "fordfocus" || test == "fordF") { return val = .32; }
		if (test == "hodnaCivic") { return val = .36; }
		if (test == "ferrariTestarossa") { return val = .37; }
		if (test == "dodgeRamPickup") { return val = .43; }
		if (test == "sphere") { return val = .45; }
		if (test == "hummerH2SUV") { return val = .64; }
		if (test == "skyDiverFeetFirst" || test == "skyDiverff") { return val = .70; }
		if (test == "skyDiver_horizontal") { return val = 1.0; }
		if (test == "bicycle") { return val = .90; }
		if (test == "dolphin") { return val = .0036; }
		if (test == "bird") { return val = .4; }
		if (test == "frisbee") { return val = .080; }
		if (test == "rectangularBox") { return val = 2.1; }
		if (test == "longFlatPlate90deg") { return val = 1.98; }
		if (test == "motorcycleAndRider") { return val = 1.8; }
		if (test == "personUpright") { return val = 1.15; }
		if (test == "convertibleOpenTop") { return val = .65; }
		if (test == "supersonicFighter") { return val = .016; }
		if (test == "solarPanels") { return val = 4.1; }
		else
			val = stod(test);

		return val;
	}
	
public:
	/**
	 * @brief Returns the value in the dragForce variable
	 * @returns dragForce
	 */
	ld return_dragForce()const { return _dragForce_; }

	/**
	 * @brief Returns the value in the dragCoefficient variable
	 * @returns drag coefficient
	 */
	ld return_dragCoefficient()const { return _dragCoefficient_; }

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
