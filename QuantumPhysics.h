#pragma once
#ifndef QUANTUM_PHYSICS
#define QUANTUM_PHYSICS
#include "SpecialRelativity.h"
#include <iostream>

static int quantum_objectCount = 0;
//α=224,ß=225,π=227,Σ=228,σ=229,µ=230,τ=231,Φ=232,Θ=233
//Ω=234,δ=235,∞=236,φ=237,ε=238,∩=239,≡=240,Γ=226,γ, σ, ϑ, Å, Ώ, λ, γ
/**
 * @class QuantumPhysics
 * @details class of static methods that relate to chapter 29 of the open stax
 * college physics text book.
 * @author Ryan Zurrin
 * dateBuilt  5/15/2021
 * lastEdit 5/15/2021
 */

class QuantumPhysics :
	public SpecialRelativity
{

public:
	QuantumPhysics* _quantumPtr;

	QuantumPhysics()
	{
		_quantumPtr = nullptr;
		quantumVar = 0.0;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	QuantumPhysics(const QuantumPhysics& t)
	{
		_quantumPtr = t._quantumPtr;
		quantumVar = t.quantumVar;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	QuantumPhysics(QuantumPhysics&& t) noexcept
	{
		_quantumPtr = t._quantumPtr;
		quantumVar = t.quantumVar;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	QuantumPhysics& operator=(QuantumPhysics&& t) noexcept
	{
		if (this != &t)
		{
			_quantumPtr = t._quantumPtr;
			quantumVar = t.quantumVar;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\n quantum object count: "
							<< quantum_objectCount << std::endl; }
	static int get_objectCount() { return quantum_objectCount; }


	~QuantumPhysics()
	{
		delete _quantumPtr;
	}
	void setTemplateVar(ld var) { quantumVar = var; }
	auto getTemplateVar() const { return quantumVar; }

	/// <summary>
	/// A LiBr molecule oscillates with a frequency of 1.7×10^13 Hz(f). Calculate
	/// the difference in energy in eV between allowed oscillator states.
	/// </summary>
	/// <param name="f">The frequency (Hz).</param>
	/// <returns>Energy between oscillator states in eV</returns>
	template<typename T>
	static constexpr auto energyBetweenOscillatorStates_eM(const T f);

	/// <summary>
	/// A physicist is watching a 15-kg orangutan at a zoo swing lazily in a
	/// tire at the end of a rope. He (the physicist) notices that each
	/// oscillation takes 3.00 s(time) and hypothesizes that the energy is
	/// quantized. Calculate the difference in energy in joules between allowed
	/// oscillator states
	/// </summary>
	/// <param name="time">The time.</param>
	/// <returns>energy between oscillator states in joules</returns>
	template<typename T>
	static constexpr auto energyBetweenOscillatorStates_J(const T time);

	/// <summary>
	/// A LiBr molecule oscillates with a frequency of 1.7×1013 Hz(frequency).
	/// Calculate the approximate value of n for a state having an
	/// energy of 1.0 eV(energy).
	/// </summary>
	/// <param name="frequency">The frequency.</param>
	/// <param name="energy">The energy.</param>
	/// <returns>the n state, where n is some whole number</returns>
	template<typename F, typename E>
	static constexpr auto valueOf_nState_f(const F frequency, const E energy);

	/// <summary>
	/// A physicist is watching a 15-kg orangutan at a zoo swing lazily in a
	/// tire at the end of a rope. He (the physicist) notices that each
	/// oscillation takes 3.00 s(time) and hypothesizes that the energy is quantized.
	/// Calculate the value of n for a state where the energy is 5.00 J?(energy)
	/// </summary>
	/// <param name="time">The time.</param>
	/// <param name="energy">The energy.</param>
	/// <returns>the n state, where n is some whole number</returns>
	template<typename T, typename E>
	static constexpr auto valueOf_nState_t(const T time, const E energy);

	/// <summary>
	/// The difference in energy between allowed oscillator states in HBr
	/// molecules is 0.330 eV(energy). What is the oscillation frequency of
	/// this molecule?
	/// </summary>
	/// <param name="energy">The energy.</param>
	/// <returns>frequency between oscillation states</returns>
	template<typename E>
	static constexpr auto oscillationFrequency(const E energy);

	/// <summary>
	/// Calculate the longest-wavelength EM radiation that can eject a
	/// photo-electron from silver, given that the binding energy is 4.73 eV(BE)
	/// Is this in the visible range?
	/// </summary>
	/// <param name="BE">The binding energy.</param>
	/// <returns>longest wavelength </returns>
	template<typename T>
	static constexpr auto longestWavelength_eMRadiationEjection(const T BE);

	/// <summary>
	/// What is the binding energy in eV of electrons in magnesium, if the
	/// longest-wavelength photon that can eject electrons is 337 nm(λ)
	/// </summary>
	/// <param name="λ">The wavelength(λ).</param>
	/// <returns>binding energy</returns>
	template<typename T>
	static constexpr auto bindingEnergy(const T λ);

	/// <summary>
	/// Calculate the maximum kinetic energy in eV of electrons ejected from
	/// sodium metal by 450-nm EM(λ) radiation, given that the binding energy
	/// is 2.28 eV?(BE)
	/// </summary>
	/// <param name="λ">The λ.</param>
	/// <param name="BE">The be.</param>
	/// <returns></returns>
	template<typename T, typename B>
	static constexpr auto maximumKineticEnergy(const T λ, const B BE);

private:
	ld quantumVar;
	static void countIncrease() { quantum_objectCount += 1; }
	static void countDecrease() { quantum_objectCount -= 1; }


};

#endif
template<typename T>
constexpr auto QuantumPhysics::energyBetweenOscillatorStates_eM(const T f)
{
	return _PLANKS_EM_ * f;
}

template<typename T>
constexpr auto QuantumPhysics::energyBetweenOscillatorStates_J(const T time)
{
	return _PLANKS_J_ * (1.0 / time);
}

template<typename F, typename E>
constexpr auto QuantumPhysics::valueOf_nState_f(const F frequency, const E energy)
{
	return round((energy / (_PLANKS_EM_ * frequency)) - (1 / 2));
}

template<typename T, typename E>
constexpr auto QuantumPhysics::valueOf_nState_t(const T time, const E energy)
{
	return ((energy * time) / _PLANKS_J_) - 1 / 2;
}

template<typename E>
constexpr auto QuantumPhysics::oscillationFrequency(const E energy)
{
	return energy / _PLANKS_EM_;
}

template<typename T>
constexpr auto QuantumPhysics::longestWavelength_eMRadiationEjection(const T BE)
{
	return (_C_ * _PLANKS_EM_) / BE;
}

template<typename T>
constexpr auto QuantumPhysics::bindingEnergy(const T λ)
{
	return (_PLANKS_EM_ * _C_) / λ;
}

template<typename T, typename B>
inline constexpr auto QuantumPhysics::maximumKineticEnergy(const T λ, const B BE)
{
	return (_PLANKS_C_ / λ) - BE;
}
