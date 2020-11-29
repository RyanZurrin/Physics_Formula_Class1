#pragma once
/**
 * @class Heat
 * @details driver class for solving physics problems
 * @author Ryan Zurrin
 * @date   11/29/2020
 */
#ifndef HEAT_H
#define HEAT_H

static int heat_objectCount = 0;

static struct HeatEnergyUnitConversion
{
	static ld kiloCalorie_to_joule(const ld kcal) { return kcal * 4186.0; } //returns Joules
	static ld joule_to_kCal(const ld joule) { return joule / 4186.0; } // returns kCal
	
}heatEnergyConverter;

/**
 * @brief structure holding the heat values of different substances. this is the c value in the
 * heat transfer equation, that we must use. Each value is a vector holding two different units
 * of heat; J/kg*C`  or kCal/kg*C`. So c.aluminum[0] would give the value of 900J/kg*C` and
 * c.aluminum[1] holds the value of .215 kCal/kg*C` respectfully.
 * @variable c stands for specific heat
 */
static struct SubstanceHeatValues 
{
	
	const vector<ld> aluminum_S = { 900.0, .215 };//< 900J/kg*C`, .215kCal/kg*C` >
	const vector<ld> asbestos_S = { 800.0, .19 };//< 800J/kg*C`, .19kCal/kg*C` >
	const vector<ld> concrete_granite_average_S = { 840.0, .20 };//< 840J/kg*C`, .20kCal/kg*C` >
	const vector<ld> copper_S = { 387.0, .0924 };//< 387J/kg*C`, .0924kCal/kg*C` >
	const vector<ld> glass_S = { 840.0, .20 };//< 840.0J/kg*C`, .20kCal/kg*C` >
	const vector<ld> gold_S = { 129.0, .0308 };//< 129.0J/kg*C`,.0308kCal/kg*C` >
	const vector<ld> human_body_average_S = { 3500.0, .83 };//< 3500.0J/kg*C`, .83kCal/kg*C` >
	const vector<ld> ice_average_S = { 2090.0, .50 };//< 2090.0J/kg*C`, .50kCal/kg*C` >
	const vector<ld> iron_steel_S = { 452, .108 };//< 452J/kg*C`, .108kCal/kg*C` >
	const vector<ld> lead_S = { 128.0, .0305 };//< 128.0J/kg*C`, .0305kCal/kg*C` >
	const vector<ld> silver_S = { 235.0, .0562 };//< 235.0J/kg*C`, .0562kCal/kg*C` >
	const vector<ld> wood_S = { 1700, .40 };//< 1700J/kg*C`, .40kCal/kg*C` >
	const vector<ld> benzene_L = { 1740.0, .415 };//< 1740.0J/kg*C`, .415kCal/kg*C` >
	const vector<ld> ethanol_L = { 2450, .586 };//< 2450J/kg*C`, .586kCal/kg*C` >
	const vector<ld> glycerin_L = { 2410.0, .576 };//< 2410.0J/kg*C`, .576kCal/kg*C` >
	const vector<ld> mercury_L = { 139, .0333 };//< 139J/kg*C`, .0333kCal/kg*C` >
	const vector<ld> water_L = { 4186.0, 1.0 };//< 4186.0J/kg*C`, 1.0kCal/kg*C` >
	const vector<ld> air_G = { 721.0, .172 };//< 721.0J/kg*C`, .172kCal/kg*C` >
	const vector<ld> air_dry_G = { 1015.0, .242 };//< 1015.0J/kg*C`, .242kCal/kg*C` >
	const vector<ld> ammonia_G = { 1670.0, .399 };//< 1670.0J/kg*C`, .399kCal/kg*C` >
	const vector<ld> ammonia_dry_G = { 2190.0, .523 };//< 2190.0J/kg*C`, .523kCal/kg*C` >
	const vector<ld> carbonDioxide_G = { 638.0, .152 };//< 638.0J/kg*C`, .152kCal/kg*C` >
	const vector<ld> carbonDioxide_dry_G = { 833.0, .199 };//< 833.0J/kg*C`, .199kCal/kg*C` >
	const vector<ld> nitrogen_G = { 739.0, .177 };//< 739.0J/kg*C`, .177kCal/kg*C` >
	const vector<ld> nitrogen_dry_G = { 1040, .248 };//< 1040J/kg*C`,.248kCal/kg*C` >
	const vector<ld> oxygen_G = { 651.0, .156 };//< 651.0J/kg*C`, .156kCal/kg*dC` >
	const vector<ld> oxygen_dry_G = { 913.0, .218 };//< 913.0J/kg*C`, .218kCal/kg*dC` >
	const vector<ld> steam_100C_G = { 1520.0, .363 };//< 1520.0J/kg*C`, .363kCal/kg*dC` >
	const vector<ld> steam_dry_100C_G = { 2020.0, .482 };//< 2020.0J/kg*C`, .482kCal/kg*dC` >
	
}c;

#include "Temperature.h"
class Heat :
    public Temperature
{
private:
	static void countIncrease() { heat_objectCount += 1; }
	static void countDecrease() { heat_objectCount -= 1; }
public:
	//null pointer to class if ever needed
	Heat* _heatPtr;
	
	/**
	 * @brief no argument constructor
	 */
	Heat()
	{
		_heatPtr = nullptr;
	}

	

	/**
	 * @brief display method for outputting the count of Heat objects
	 */
	static void show_heat_objectCount() { std::cout << "\nheat object count: " << heat_objectCount << std::endl; }
	/**
	 * @brief getter method returns the value of heat objects 
	 */
	static int get_heat_objectCount() { return heat_objectCount; }

	/**
	 * @brief calculates the required heat to heat an object up
	 * @param mass is the mass of the object
	 * @param c is the specific heat which depends on object type
	 * @param deltaTemp is the change in temperature
	 * @returns the heat in Joules
	 */
	static ld heatRequired(const ld mass, const ld c, const ld deltaTemp)
	{
		return mass * c * deltaTemp;
	}

	/**
	 * @brief calculates the temp from heat transferred 
	 */

	



	/**
	 *@brief destructor
	 */
	~Heat()
	{
		delete _heatPtr;
	}
};

#endif
