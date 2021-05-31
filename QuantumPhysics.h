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
	/// Calculates the energy in joules a photon in a radio wave from
	/// an AM station that has a 1530-kHz(f) broadcast frequency
	/// </summary>
	/// <param name="f">The frequency.</param>
	/// <returns>Energy in Joules</returns>
	template<typename T>
	static constexpr auto energy_J(const T f);

	/// <summary>
	/// Calculates the energy in eV of a photon in a radio wave from
	/// an AM station that has a 1530-kHz(f) broadcast frequency
	/// </summary>
	/// <param name="f">The frequency.</param>
	/// <returns>Energy in eV</returns>
	template<typename T>
	static constexpr auto energy_eM(const T f);

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
	/// Violet light of wavelength 400 nm(λ) ejects electrons with a maximum
	/// kinetic energy of 0.860 eV(KE) from sodium metal. Calculate the binding
	/// energy of electrons to sodium metal
	/// </summary>
	/// <param name="λ">The wavelength λ.</param>
	/// <param name="KE">The kinetic energy.</param>
	/// <returns>binding energy (eV)</returns>
	template<typename T, typename K>
	static constexpr auto bindingEnergy(const T λ, const K KE);

	/// <summary>
	/// Bindings the energy f.
	/// </summary>
	/// <param name="f">The f.</param>
	/// <param name="KE">The ke.</param>
	/// <returns></returns>
	template<typename T, typename K>
	static constexpr auto bindingEnergy_f(const T f, const K KE);

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

	/// <summary>
	/// Maximums the kinetic energy f.
	/// </summary>
	/// <param name="f">The f.</param>
	/// <param name="BE">The be.</param>
	/// <returns></returns>
	template<typename T, typename B>
	static constexpr auto maximumKineticEnergy_f(const T f, const B BE);

	/// <summary>
	///Calculate the wavelength of EM radiation that ejects 2.00-eV(KE) electrons
	/// from calcium metal, given that the binding energy is 2.71 eV(BE).
	/// </summary>
	/// <param name="KE">The kinetic energy.</param>
	/// <param name="BE">The binding energy.</param>
	/// <returns>wavelength</returns>
	template<typename K, typename B>
	static constexpr auto wavelength(const K KE, const B BE);

	/// <summary>
	/// Calculates the wavelength of a 1.00-eV(E) photon
	/// </summary>
	/// <param name="E">The Energy.</param>
	/// <returns>wavelength  λ</returns>
	template<typename T>
	static constexpr auto wavelength(const T E);

	/// <summary>
	/// Calculate the maximum velocity of electrons(m) ejected from a material by
	/// 80-nm photons( λ), if they are bound to the material by 4.73 eV(BE)
	/// </summary>
	/// <param name="λ">The λ.</param>
	/// <param name="m">The mass.</param>
	/// <param name="BE">The binding energy.</param>
	/// <returns>maximum velocity</returns>
	template<typename T, typename M, typename B>
	static constexpr auto maximumVelocity(const T λ, const M m, const B BE);

	/// <summary>
	/// Photoelectrons(m) from a material with a binding energy of 2.71 eV(BE) are
	/// ejected by 420-nm(λ) photons. Once ejected, how long does it take these
	/// electrons to travel 2.50 cm(dis) to a detection device
	/// </summary>
	/// <param name="λ">The λ.</param>
	/// <param name="m">The m.</param>
	/// <param name="BE">The be.</param>
	/// <param name="dis">The dis.</param>
	/// <returns></returns>
	template<typename T, typename M, typename B, typename D>
	static constexpr auto timeToTravelDistance(const T λ, const M m, const B BE, const D dis);

	/// <summary>
	/// A laser with a power output of 2.00 mW(P) at a wavelength of 400 nm(λ)
	/// is projected onto calcium metal. Calculate How many electrons per second
	/// are ejected.
	/// </summary>
	/// <param name="λ">The wavelength λ.</param>
	/// <param name="P">The power output.</param>
	/// <returns>how many electrons per second are ejected</returns>
	template<typename T, typename P>
	static constexpr auto electronsPerSecondEjected(const T λ, const P P_);

	/// <summary>
	///  Calculate the number of photoelectrons per second ejected from a
	///  1.00 mm^2 area(A) of sodium metal by 500-nm EM(λ) radiation having an
	///  intensity of 1.30 kW/m2(I) (the intensity of sunlight above the
	///  Earth’s atmosphere)
	/// </summary>
	/// <param name="A">area.</param>
	/// <param name="λ">The wavelength λ.</param>
	/// <param name="I">The intensity.</param>
	/// <returns></returns>
	template<typename T>
	static constexpr auto photoelectronsPerSecondEjected(const T A, const T λ, const T I);

	/// <summary>
	/// A laser with a power output of 2.00 mW(P) at a wavelength of 400 nm(λ)
	/// is projected onto calcium metal. What power is carried away by the
	/// electrons, given that the binding energy is 2.71 eV(BE).
	/// </summary>
	/// <param name="λ">The wavelength λ.</param>
	/// <param name="P">The power output.</param>
	/// <param name="BE">The binding energy.</param>
	/// <returns>power carried away by the electrons (W)</returns>
	template<typename T>
	static constexpr auto powerCarriedAwayByElectrons(const T λ, const T P, const T BE);

	/// <summary>
	/// If the number of photoelectrons per second ejected from a
	/// 1.00 mm^2 area of sodium metal by 500-nm EM radiation having an
	/// intensity of 1.30 kW/m2 as well as a binding energy is 2.28 eV,
	/// calculate the power that is carried away by the electrons.
	/// </summary>
	/// <param name="A">a.</param>
	/// <param name="λ">The λ.</param>
	/// <param name="I">The i.</param>
	/// <param name="BE">The be.</param>
	/// <returns></returns>
	template<typename T>
	static constexpr auto powerCarriedAwayByElectrons(const T A, const T λ, const T I, const T BE);

	/// <summary>
	/// Calculates the frequency in hertz of a 1.00-MeV(E) γ-ray photon.
	/// </summary>
	/// <param name="E">The Energy.</param>
	/// <returns>the frequency in (Hz)</returns>
	template<typename T>
	static constexpr auto frequency_fromE(const T E);

	/// <summary>
	/// Calculate the energy in eV of an IR photon of frequency 2.00×1013 Hz.
	/// How many of these photons would need to be absorbed simultaneously by
	/// a tightly bound molecule to break it apart
	/// </summary>
	/// <param name="E_tot">The e tot.</param>
	/// <param name="E">The e.</param>
	/// <returns>number of photons</returns>
	template<typename T>
	static constexpr  auto numberOfSimultaneouslyAbsorbedPhotons(const T E_tot, const T E);

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
inline constexpr auto QuantumPhysics::energy_J(const T f)
{
	return _PLANKS_J_ * f;
}

template<typename T>
inline constexpr auto QuantumPhysics::energy_eM(const T f)
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
	return (_PLANKS_C_) / BE;
}

template<typename T>
constexpr auto QuantumPhysics::bindingEnergy(const T λ)
{
	return (_PLANKS_C_) / λ;
}

template<typename T, typename K>
inline constexpr auto QuantumPhysics::bindingEnergy(const T λ, const K KE)
{
	return ((_PLANKS_C_) / λ) - KE;
}

template<typename T, typename K>
inline constexpr auto QuantumPhysics::bindingEnergy_f(const T f, const K KE)
{
	return (_PLANKS_J_*f) - KE;
}

template<typename T, typename B>
inline constexpr auto QuantumPhysics::maximumKineticEnergy(const T λ, const B BE)
{
	return ((_PLANKS_C_)/ λ) - BE;
}

template<typename T, typename B>
inline constexpr auto QuantumPhysics::maximumKineticEnergy_f(const T f, const B BE)
{
	return _PLANKS_EM_ * f - BE;
}

template<typename K, typename B>
inline constexpr auto QuantumPhysics::wavelength(const K KE, const B BE)
{
	return _PLANKS_C_ / (KE + BE);
}

template<typename T>
inline constexpr auto QuantumPhysics::wavelength(const T E)
{
	return _PLANKS_C_ / E;
}

template<typename T, typename M, typename B>
inline constexpr auto QuantumPhysics::maximumVelocity(const T λ, const M m, const B BE)
{
	return sqrt((2.0 / m) * (((_PLANKS_J_*_C_) / λ) - (BE*1.602e-19 )));
}

template<typename T, typename M, typename B, typename D>
inline constexpr auto QuantumPhysics::timeToTravelDistance(const T λ, const M m, const B BE, const D dis)
{
	return dis/sqrt((2.0 / m) * (((_PLANKS_J_ * _C_) / λ) - (BE * 1.602e-19)));
}

template<typename T, typename P>
inline constexpr auto QuantumPhysics::electronsPerSecondEjected(const T λ, const P P_)
{
	return (P_ * λ) / (_PLANKS_J_ * _C_);
}

template<typename T>
inline constexpr auto QuantumPhysics::photoelectronsPerSecondEjected(const T A, const T λ, const T I)
{
	return (I * (A * A) * λ) / (_PLANKS_J_ * _C_);
}

template<typename T>
inline constexpr auto QuantumPhysics::powerCarriedAwayByElectrons(const T λ, const T P, const T BE)
{
	return (((_PLANKS_J_ * _C_) / λ) - (BE*1.602e-19)) * electronsPerSecondEjected(λ, P);
}

template<typename T>
inline constexpr auto QuantumPhysics::powerCarriedAwayByElectrons(const T A, const T λ, const T I, const T BE)
{
	return I * (A * A) * (1.0 - (BE * λ) / _PLANKS_C_);
}

template<typename T>
inline constexpr auto QuantumPhysics::frequency_fromE(const T E)
{
	return E / _PLANKS_EM_;
}

template<typename T>
inline constexpr auto QuantumPhysics::numberOfSimultaneouslyAbsorbedPhotons(const T E_tot, const T E)
{
	return E_tot / E;
}
