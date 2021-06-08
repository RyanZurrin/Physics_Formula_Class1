#pragma once
#ifndef ATOMIC_PHYSICS_H
#define ATOMIC_PHYSICS_H


#include "ElectricCharge.h"

// speed of light in a vacuum is 299792458 m/s
constexpr auto _LIGHT_SPEED_ = 2.99792458e8;//2.9979*10^8

static int atomicPhysics_objectCount = 0;

//α=224,ß=225,π=227,Σ=228,σ=229,µ=230,τ=231,Φ=232,Θ=233
//Ω=234,δ=235,∞=236,φ=237,ε=238,∩=239,≡=240,Γ=226,γ, σ, ϑ, Å, Ώ, λ, γ, Δ
/**
 * @class AtomicPhysics
 * @details class of static methods that relate to chapter 30 of the
 * open-stax college physics text book.
 * @author Ryan Zurrin
 * dateBuilt  6/8/2021
 * lastEdit 6/8/2021
 */
class AtomicPhysics
{

	ld atomPhysicsVar;
	static auto countIncrease() { atomicPhysics_objectCount += 1; }
	static auto countDecrease() { atomicPhysics_objectCount -= 1; }
public:

	AtomicPhysics()
	{
		atomPhysicsVar = 0.0;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	AtomicPhysics(const AtomicPhysics& t)
	{
		atomPhysicsVar = t.atomPhysicsVar;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	AtomicPhysics(AtomicPhysics&& t) noexcept
	{
		atomPhysicsVar = t.atomPhysicsVar;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	AtomicPhysics& operator=(AtomicPhysics&& t) noexcept
	{
		if (this != &t)
		{
			atomPhysicsVar = t.atomPhysicsVar;
			countIncrease();
		}
		return *this;
	}

	/// <summary>
	/// Operator=s the specified other.
	/// </summary>
	/// <param name="other">The other.</param>
	/// <returns>copy assignment operator</returns>
	AtomicPhysics& operator=(AtomicPhysics other)
	{
		std::swap(atomPhysicsVar, other.atomPhysicsVar);
		return *this;
	}

	static void show_objectCount() { std::cout << "\n atomic physics object count: "
							<< atomicPhysics_objectCount << std::endl; }
	static int get_objectCount() { return atomicPhysics_objectCount; }


	~AtomicPhysics() = default;

	auto setTemplateVar(ld var) { atomPhysicsVar = var; }
	[[nodiscard]] auto getTemplateVar() const { return atomPhysicsVar; }


};
#endif

