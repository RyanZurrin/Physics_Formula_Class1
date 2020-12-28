#pragma once
/**
 * @class FluidDynamics
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   12/17/2020
 */

#ifndef FLUIDDYNAMICS_H
#define FLUIDDYNAMICS_H
#include <iostream>


static int fluidDynamic_objectCount = 0;

static struct FlowRateConversions
{
	static ld litersPerSecond_to_cubicMetersPerSecond(const ld lps)
	{
		return lps * .001; // m^3/sec
	}
	static ld litersPerSecond_to_cubicMetersPerMin(const ld lps)
	{
		return lps * .06; // m^3/min
	}

	static ld literMin_to_cubicCentimeterSecond(const ld ltrMin)
	{
		return ltrMin * 16.6667; // cm^3/s
	}
	static ld cubicCentimeterSecond_to_literMin(const ld ccms)
	{
		return ccms / 16.6667; // L/min
	}
	static ld literMin_to_cubicMeterSecond(const ld ltrMin)
	{
		return ltrMin * 1.6667 * pow(10.0, -5.0); // m^3/s
	}
	static ld cubicMeterSecond_to_literMin(const ld cms)
	{
		return cms / 1.6667 * pow(10.0, -5.0); // L/min
	}


}flow_rate_converter;

class FluidDynamics
{
private:
	static void countIncrease() { fluidDynamic_objectCount += 1; }
	static void countDecrease() { fluidDynamic_objectCount -= 1; }
public:
	FluidDynamics* _fluidDynamicPtr;

	FluidDynamics()
	{
		_fluidDynamicPtr = nullptr;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	FluidDynamics(const FluidDynamics& t)
	{
		_fluidDynamicPtr = t._fluidDynamicPtr;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	FluidDynamics(FluidDynamics&& t) noexcept
	{
		_fluidDynamicPtr = t._fluidDynamicPtr;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	FluidDynamics& operator=(const FluidDynamics& t)
	{
		if (this != &t)
		{
			_fluidDynamicPtr = t._fluidDynamicPtr;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\n fluid dynamic object count: " << fluidDynamic_objectCount << std::endl; }
	static int get_objectCount() { return fluidDynamic_objectCount; }

	/// <summary>
	/// calculates the volumes of a cylinder.
	/// </summary>
	/// <param name="radius">The radius is used to find the cross sectional area of a cylinder.</param>
	/// <param name="distance">The distance.</param>
	/// <returns>volume</returns>
	static ld volumeCylinder(const ld radius, const ld distance)
	{
		return _PI * (radius * radius) * distance;
	}

	/// <summary>
	/// finds the flow rate of fluid in a cylinder.
	/// </summary>
	/// <param name="radius">The radius.</param>
	/// <param name="distance">The distance.</param>
	/// <param name="time">The time.</param>
	/// <returns>flow rate (Q)</returns>
	static ld flowRateCylinder_radius(const ld radius, const ld distance, const ld time)
	{
		return _PI * (radius * radius) * distance * time;
	}

	/// <summary>
	/// calculates the flow rate of a cylinder using the diameter.
	/// </summary>
	/// <param name="diameter">The diameter.</param>
	/// <param name="velocity">The velocity.</param>
	/// <returns></returns>
	static ld flowRateCylinder_diameter(const ld diameter, const ld velocity)
	{
		return (_PI * (diameter * diameter) / 4.0) * velocity;
	}

	/// <summary>
	/// calculates the flow rate.
	/// </summary>
	/// <param name="volume">The volume.</param>
	/// <param name="time">The time.</param>
	/// <returns>flow rate</returns>
	static ld flowRate(const ld volume, const ld time)
	{
		return volume / time;
	}

	/// <summary>
	/// calculates the volume of flow rate.
	/// </summary>
	/// <param name="crossSectionalArea">The cross sectional area.</param>
	/// <param name="avgVelocity">The average velocity.</param>
	/// <returns>volume flow rate</returns>
	static ld volumeFlowRate(const ld crossSectionalArea, const ld avgVelocity)
	{
		return crossSectionalArea * avgVelocity;
	}

	/// <summary>
	/// finds the average velocity.
	/// </summary>
	/// <param name="volumeFlowRate">The volume flow rate.</param>
	/// <param name="area">The area.</param>
	/// <returns>average velocity</returns>
	static ld averageVelocity(const ld volumeFlowRate, const ld area)
	{
		return volumeFlowRate / area;
	}

	/// <summary>
	/// average velocity in tube or aorta with given radius and flow.
	/// </summary>
	/// <param name="volumeFlowRate">The volume flow rate.</param>
	/// <param name="radius">The radius.</param>
	/// <returns>average velocity</returns>
	static ld averageVelocity_tubeLike(const ld volumeFlowRate, const ld radius)
	{
		return volumeFlowRate / (_PI * (radius * radius));
	}

	/// <summary>
	/// calculates the volume from flow rate and time
	/// </summary>
	/// <param name="flowRate">The flow rate.</param>
	/// <param name="time">The time.</param>
	/// <returns>volume</returns>
	static ld volume(const ld flowRate, const ld time)
	{
		return flowRate * time;
	}
	/// <summary>
	/// calculates the time
	/// </summary>
	/// <param name="flowRate">The flow rate.</param>
	/// <param name="volume">The volume.</param>
	/// <returns>time</returns>
	static ld time(const ld flowRate, const ld volume)
	{
		return volume / flowRate;
	}
	/// <summary>
	/// finds the velocity using the equation of continuity solved for
	/// velocity2.
	/// </summary>
	/// <param name="velocity1">The velocity of flow through the area1.</param>
	/// <param name="area1">The cross-sectional area1.</param>
	/// <param name="area2">The cross-sectional area2.</param>
	/// <returns>velocity through area2</returns>
	static ld velocity2_eqOfContinuity(const ld velocity1, const ld area1, const ld area2)
	{
		return (area1 / area2) * velocity1;
	}

	/// <summary>
	/// Flows the rate tube like.
	/// </summary>
	/// <param name="radius">The radius.</param>
	/// <param name="avgVelocity">The average velocity.</param>
	/// <returns></returns>
	static ld flowRate_tubeLike(const ld radius, const ld avgVelocity)
	{
		return _PI * (radius * radius) * avgVelocity;
	}

	/// <summary>
	/// calculates the total volume to flow over a period of time.
	/// </summary>
	/// <param name="radius">The radius.</param>
	/// <param name="avgVelocity">The average velocity.</param>
	/// <param name="time">The time.</param>
	/// <returns>volume total</returns>
	static ld volumeTotal(const ld radius, const ld avgVelocity, const ld time)
	{
		return _PI * (radius * radius) * avgVelocity * time;
	}

	/// <summary>
	/// finds the factor the velocity is reduced by branching.
	/// </summary>
	/// <param name="mainRadius">The main radius.</param>
	/// <param name="branchRadius">The branch radius.</param>
	/// <param name="branches">The number of smaller branches.</param>
	/// <returns>factor of velocity reduction</returns>
	static ld reducedVelocity_branchingArteries(const ld mainRadius, const ld branchRadius, const ld branches)
	{
		return (1.0 * mainRadius) / (branches * branchRadius);
	}

	/// <summary>
	/// Average velocity of blood flow through ad capillary.
	/// </summary>
	/// <param name="flowRate">The flow rate.</param>
	/// <param name="capillaryVessels">The capillary vessels.</param>
	/// <param name="diameterEach">The diameter each.</param>
	/// <returns>average blood flow</returns>
	static ld averageVelocityBloodFlowThroughCapillary_diameter(const ld flowRate, const ld capillaryVessels, const ld diameterEach)
	{
		return (4.0 * flowRate) / (capillaryVessels * _PI * (diameterEach * diameterEach));
	}

	/// <summary>
	/// Averages the velocity blood flow through capillary with the radius.
	/// </summary>
	/// <param name="flowRate">The flow rate.</param>
	/// <param name="radius">The radius.</param>
	/// <returns></returns>
	static ld averageVelocityBloodFlowThroughCapillary_radius(const ld flowRate, const ld radius)
	{
		return flowRate / (_PI * (radius * radius));
	}

	/// <summary>
	/// calculates the total nubmer of capillaries.
	/// </summary>
	/// <param name="area">The area.</param>
	/// <param name="diameter">The diameter.</param>
	/// <returns>capillaries</returns>
	static ld capillaryFlowTotal_diameter(const ld area, const ld diameter)
	{
		return (4.0 * area) / (_PI * (diameter * diameter));
	}

	/// <summary>
	/// calculates the total number of Capillaries with the radius.
	/// </summary>
	/// <param name="flow">The flow.</param>
	/// <param name="radius">The radius.</param>
	/// <returns></returns>
	static ld capillaryFlowTotal_radius(const ld flow, const ld radius)
	{
		return flow / (_PI * (radius * radius));
	}

	/// <summary>
	/// calculates the total flow rate
	/// </summary>
	/// <param name="capillaries">The number of capillaries.</param>
	/// <param name="crossSectionalArea">The cross sectional area.</param>
	/// <param name="avgVelocity">The average velocity.</param>
	/// <returns>total flow rate</returns>
	static ld totalFlowRate_capillary(const ld capillaries, const ld crossSectionalArea, const ld avgVelocity)
	{
		return capillaries * crossSectionalArea * avgVelocity;
	}

	/// <summary>
	/// Calculates the air flow through a circular duct into a rectangular room.
	/// </summary>
	/// <param name="roomVolume">The rooms volume = L * W * H.</param>
	/// <param name="radiusDuct">The radius duct or r = diameter/2.</param>
	/// <param name="time">The time in seconds.</param>
	/// <returns>average speed of air flow out of duct</returns>
	static ld airFlowThroughCircularDuctIntoRectangularRoom(const ld roomVolume, const ld radiusDuct, const ld time)
	{
		return roomVolume / (_PI * (radiusDuct * radiusDuct) * time);
	}

	/// <summary>
	/// calculates the inside diameters of a hose nozzle.
	/// </summary>
	/// <param name="flowRate">The flow rate.</param>
	/// <param name="velocity">The velocity.</param>
	/// <returns>diameter</returns>
	static ld diameterInsideNozzle(const ld flowRate, const ld velocity)
	{
		return 2.0 * sqrt((flowRate) / (_PI * velocity));
	}


	~FluidDynamics()
	{
		delete _fluidDynamicPtr;
	}

};
#endif

