﻿#pragma once
#ifndef QUANTUM_PHYSICS
#define QUANTUM_PHYSICS
#include "SpecialRelativity.h"
#include <iostream>

static int quantum_objectCount = 0;
//α=224,ß=225,π=227,Σ=228,σ=229,µ=230,τ=231,Φ=232,Θ=233
//Ω=234,δ=235,∞=236,φ=237,ε=238,∩=239,≡=240,Γ=226,γ, σ, ϑ, Å, Ώ, λ, γ, Δ
/**
 * @class QuantumPhysics
 * @details class of static methods that relate to chapter 29 of the open-stax
 * college physics text book.
 * @author Ryan Zurrin
 * dateBuilt  5/15/2021
 * lastEdit 6/8/2021
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
	/// Calculates the binding energy in joules.
	/// </summary>
	/// <param name="λ">The λ.</param>
	/// <returns>energy in joules</returns>
	template<typename T>
	static constexpr auto bindingEnergy_Joules(const T λ);

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
	/// Calculate the energy in eV of an IR photon of frequency 2.00×10^13 Hz.
	/// How many of these photons would need to be absorbed simultaneously by
	/// a tightly bound molecule to break it apart
	/// </summary>
	/// <param name="E_tot">The e tot.</param>
	/// <param name="E">The e.</param>
	/// <returns>number of photons</returns>
	template<typename T>
	static constexpr  auto numberOfSimultaneouslyAbsorbedPhotons(const T E_tot, const T E);

	/// <summary>
	/// Numbers the of tightly bound molecules γ ray can break apart.
	/// </summary>
	/// <param name="E_tot">The e tot.</param>
	/// <param name="E">The e.</param>
	/// <returns></returns>
	template<typename T>
	static constexpr auto numOfTightlyBoundMolecules_γRayCanBreakApart(const T E_tot, const T E);

	/// <summary>
	/// What is the accelerating voltage of an x-ray tube that produces x-rays
	/// with a shortest wavelength of  λ nm?
	/// </summary>
	/// <param name="λ">The wavelength λ.</param>
	/// <param name="q">The charge.</param>
	/// <returns>accelerating voltage</returns>
	template<typename T>
	static constexpr auto acceleratingVoltage(const T λ, const T q);

	/// <summary>
	/// Calculate the maximum energy in eV of photons produced in a CRT using a
	/// 25.0-kV(volts) accelerating potential, such as a color TV
	/// </summary>
	/// <param name="q">The charge of a proton or other molecule.</param>
	/// <param name="volts">The volts.</param>
	/// <returns>the max energy produced</returns>
	template<typename Q, typename V>
	static constexpr auto energyMax_eV(const Q q, const V volts);

	/// <summary>
	///  Calculate the ratio of power outputs by two microwave ovens having
	///  frequencies of f_1 and f_2 Hz, if they emit the same number of
	///  photons per second
	/// </summary>
	/// <param name="f_1">The first frequency.</param>
	/// <param name="f_2">The second frequency.</param>
	/// <returns>ratio of the frequency</returns>
	template<typename F>
	static constexpr auto ratioOf_frequencies(const F f_1, const F f_2);


	/// <summary>
	/// calculate the ratio of photons per second if two microwave ovens having
	///  frequencies of f_1 and f_2 Hz have the same power output
	/// </summary>
	/// <param name="f_1">The f 1.</param>
	/// <param name="f_2">The f 2.</param>
	/// <returns>ratio of photons per second</returns>
	template<typename F>
	static constexpr auto ratioOf_photonsPerSecond(const F f_1, const F f_2);

	/// <summary>
	/// Calculate how many photons per second are emitted by the antenna of a microwave
	/// oven, if its power output is P_ at a frequency of f Hz
	/// </summary>
	/// <param name="P_">The power.</param>
	/// <param name="f">The frequency.</param>
	/// <returns>number of photons per second emitted</returns>γ
	template<typename P, typename F>
	static constexpr auto photonsPerSecondEmitted(const P P_, const F f);

	/// <summary>
	/// Some satellites use nuclear power. If such a satellite emits a
	/// 1.00-W(P_) flux of γ rays having an average energy of 0.500 MeV(E_),
	/// Calculate how many are emitted per second.
	/// </summary>
	/// <param name="P_">The power.</param>
	/// <param name="E_">The energy.</param>
	/// <returns>gamma rays emitted per second</returns>
	template<typename P, typename E>
	static constexpr auto gammaRaysPerSecondEmitted(const P P_, const E E_);

	/// <summary>
	/// Some satellites use nuclear power. If such a satellite emits a
	/// 1.00-W(P_) flux of γ rays having an average energy of 0.500 MeV(E_),
	/// Using the number of emitted per second and that these γ rays affect other
	/// satellites. Calculate how far away must another satellite be to only
	/// receive one γ ray per second per square meter.
	/// </summary>
	/// <param name="P_">The power.</param>
	/// <param name="E_">The energy.</param>
	/// <param name="Φ">The φ or number of gamma rays per second received by
	/// satellite.</param>
	/// <returns>radius r, or distance away</returns>
	template<typename P, typename E, typename F>
	static constexpr auto distanceBetween2Satellites(const P P_, const E E_, const F Φ);

	/// <summary>
	/// Find the momentum of a 4.00-cm-wavelength(λ) microwave photon
	/// </summary>
	/// <param name="λ">The wavelength λ.</param>
	/// <returns>photon momentum</returns>
	template<typename W>
	static constexpr auto photonMomentum(const W λ);

	/// <summary>
	/// Find the momentum of a 100-keV(E_) x-ray photon
	/// </summary>
	/// <param name="E_">The e.</param>
	/// <returns></returns>
	template<typename E>
	static constexpr auto momentum_fromEnergy(const E E_);

	/// <summary>
	/// the momentum of a  photon is p for which it can
	/// detect details of an atom. What is its energy in eV
	/// </summary>
	/// <param name="p">The momentum.</param>
	/// <returns>energy in eV</returns>
	template<typename P>
	static constexpr auto energy_fromMomentum(const P p);

	/// <summary>
	/// What is the wavelength of a photon that has a momentum of 5.00×10−29 kg⋅m/s? .
	/// </summary>
	/// <param name="p">The momentum.</param>
	/// <returns>wavelength</returns>
	template<typename P>
	static constexpr auto wavelength_fromMomentum(const P p);

	/// <summary>
	/// Velocities from momentum.
	/// </summary>
	/// <param name="p">The p.</param>
	/// <param name="m">The m.</param>
	/// <returns></returns>
	template<typename P, typename M>
	static constexpr auto velocityFromMomentum(const P p, const M m);

	/// <summary>
	/// Kinetics the energy.
	/// </summary>
	/// <param name="m">The m.</param>
	/// <param name="v">The v.</param>
	/// <returns></returns>
	template<typename M, typename V>
	static constexpr auto kineticEnergy(const M m, const V v);

	/// <summary>
	/// Calculate the kinetic energy of an electron in a TEM having a 0.0100-nm
	/// wavelength
	/// </summary>
	/// <param name="m">The mass.</param>
	/// <param name="λ">The wavelength λ.</param>
	/// <returns>the kinetic energy</returns>
	template<typename M, typename W>
	static constexpr auto kineticEnergy_fromWavelength(const M m, const W λ);

	/// <summary>
	/// Calculate at what velocity an electron will have a wavelength of λ
	/// </summary>
	/// <param name="λ">The wavelength λ.</param>
	/// <returns>velocity of electron</returns>
	template<typename W>
	static constexpr auto electronVelocity(const W  λ);

	/// <summary>
	/// Calculate the velocity of a 0.400-kg(m) billiard ball if its wavelength
	/// is 7.50 cm(λ) (large enough for it to interfere with other billiard balls
	/// </summary>
	/// <param name="m">The mass.</param>
	/// <param name="λ">The wavelength λ.</param>
	/// <returns></returns>
	template<typename M, typename W>
	static constexpr auto objectVelocity(const M m, const W λ);

	/// <summary>
	/// What is the wavelength of an electron moving at 3.00%(percentOfLightSpeed)
	/// of the speed of light
	/// </summary>
	/// <param name="percentOfLightSpeed">The percent of light speed.</param>
	/// <returns></returns>
	template<typename V>
	static constexpr auto electronWavelength_movingAtPercentSpeedOfLight(
		const V percentOfLightSpeed
	);


	/// <summary>
	/// Find the wavelength of a particle of mass m moving at the speed of v
	/// </summary>
	/// <param name="m">The m.</param>
	/// <param name="v">The speed.</param>
	/// <returns></returns>
	template<typename M, typename V>
	static constexpr auto deBrogile_wavelength(const M m, const V v);

	/// <summary>
	/// Calculate the wavelength of an electron(m,q) accelerated through a
	/// 30.0-kV(v) potential, as in a TV tube?
	/// </summary>
	/// <param name="m">The mass of particle.</param>
	/// <param name="q">The charge of particle.</param>
	/// <param name="v">The voltage accelerated through.</param>
	/// <returns>the wavelength</returns>
	template<typename M, typename Q, typename V>
	static constexpr auto wavelengthParticleAcceleratedThroughVoltageOf(
		const M m, const Q q, const V v
	);

	/// <summary>
	/// Calculate through what voltage must an electron be accelerated to have
	/// a speed of (velocity)
	/// </summary>
	/// <param name="m">The mass of particle.</param>
	/// <param name="q">The charge of particle.</param>
	/// <param name="velocity">The velocity.</param>
	/// <returns>voltage accelerated through to have certain speed</returns>
	template<typename M, typename Q, typename V>
	static constexpr auto voltageToHaveVelocityOf(const M m, const Q q, const V velocity);

	/// <summary>
	/// If the position of an electron in a membrane is measured to an
	/// accuracy of 1.00 μm(x), what is the electron’s(m) minimum uncertainty
	/// in velocity
	/// </summary>
	/// <param name="x">The accuracy of measurement.</param>
	/// <param name="m">The mass.</param>
	/// <returns>minimum uncertainty of velocity</returns>
	template<typename XX, typename M>
	static constexpr auto min_uncertaintyInVelocity(const XX x, const M m);

	/// <summary>
	/// Suppose the velocity of an electron(m) in an atom is known to an accuracy
	/// of 2.0×10^3 m/s(v) (reasonably accurate compared with orbital velocities).
	/// Calculate the electron’s minimum uncertainty in position
	/// </summary>
	/// <param name="v">The velocity.</param>
	/// <param name="m">The mass.</param>
	/// <returns>minimum uncertainty in position</returns>
	template<typename M, typename V>
	static constexpr auto min_uncertaintyInPosition(const V v, const M m);

	/// <summary>
	/// A relatively long-lived excited state of an atom has a lifetime of
	/// 3.00 ms(t). What is the minimum uncertainty in its energy
	/// </summary>
	/// <param name="t">The t.</param>
	/// <returns>minimum uncertainty in energy</returns>
	template<typename T>
	static constexpr auto min_uncertaintyInEnergy(const T t);

	/// <summary>
	/// The decay energy of a short-lived particle has an uncertainty of
	/// 1.0 MeV(E_) due to its short lifetime. Calculate the smallest lifetime
	/// it can have
	/// </summary>
	/// <param name="E_">The energy.</param>
	/// <returns>minimum possible lifespan of particle</returns>
	template<typename E>
	static constexpr auto min_uncertaintyInLifetime(const E E_);

	/// <summary>
	/// What is the approximate uncertainty in the mass of a muon, as
	/// determined from its decay lifetime(t).
	/// </summary>
	/// <param name="t">The decay time.</param>
	/// <returns>uncertainty in mass</returns>
	template<typename T>
	static constexpr auto min_uncertaintyInMass(const T t);

	/// <summary>
	/// A certain heat lamp has a binding energy of E_.
	/// How many of these photons are required to increase the temperature
	/// of a object by  Δ_temp∘ , assuming the affected object is has a mass kg
	/// with a specific heat of specHeat⋅C∘. Also assume no other
	/// significant heat transfer
	/// </summary>
	/// <param name="mass">The mass.</param>
	/// <param name="specHeat">The spec heat.</param>
	/// <param name="Δ_temp">The δ temporary.</param>
	/// <param name="E_">The e.</param>
	/// <returns></returns>
	template<typename M, typename C, typename T, typename E>
	static constexpr  auto photonsRequiredToIncreaseTemperature(
		const M mass, const C specHeat, const T Δ_temp, const E E_
	);

	/// <summary>
	/// A certain heat lamp emits 200 W of mostly IR radiation averaging
	/// 1500 nm in wavelength. How many of these photons are required to
	/// increase the temperature of a person’s shoulder by 2.0C∘ , assuming
	/// the affected mass is 4.0 kg with a specific heat of 0.83 kcal/kg⋅C∘.
	/// Also assume no other significant heat transfer
	/// </summary>
	/// <param name="watts">The watts.</param>
	/// <param name="λ">The wavelength λ.</param>
	/// <param name="mass">The mass.</param>
	/// <param name="specHeat">The specific heat.</param>
	/// <param name="Δ_temp">The δ(change in) temperature.</param>
	/// <returns>total Number of photons to increase mass by
	/// temperature specified</returns>
	template<typename P, typename W, typename M, typename C, typename T>
	static constexpr  auto photonsRequiredToIncreaseTemperature(
		const P watts, const W λ, const M mass, const C specHeat, const T Δ_temp
	);


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

template<typename T>
constexpr auto QuantumPhysics::bindingEnergy_Joules(const T λ)
{
	return (_PLANKS_J_ * _C_) / λ;
}

template<typename T, typename K>
constexpr auto QuantumPhysics::bindingEnergy(const T λ, const K KE)
{
	return ((_PLANKS_C_) / λ) - KE;
}

template<typename T, typename K>
constexpr auto QuantumPhysics::bindingEnergy_f(const T f, const K KE)
{
	return (_PLANKS_J_*f) - KE;
}

template<typename T, typename B>
constexpr auto QuantumPhysics::maximumKineticEnergy(const T λ, const B BE)
{
	return ((_PLANKS_C_)/ λ) - BE;
}

template<typename T, typename B>
constexpr auto QuantumPhysics::maximumKineticEnergy_f(const T f, const B BE)
{
	return _PLANKS_EM_ * f - BE;
}

template<typename K, typename B>
constexpr auto QuantumPhysics::wavelength(const K KE, const B BE)
{
	return _PLANKS_C_ / (KE + BE);
}

template<typename T>
constexpr auto QuantumPhysics::wavelength(const T E)
{
	return _PLANKS_C_ / E;
}

template<typename T, typename M, typename B>
constexpr auto QuantumPhysics::maximumVelocity(const T λ, const M m, const B BE)
{
	return sqrt((2.0 / m) * (((_PLANKS_J_*_C_) / λ) - (BE*1.602e-19 )));
}

template<typename T, typename M, typename B, typename D>
constexpr auto QuantumPhysics::timeToTravelDistance(const T λ, const M m, const B BE, const D dis)
{
	return dis/sqrt((2.0 / m) * (((_PLANKS_J_ * _C_) / λ) - (BE * 1.602e-19)));
}

template<typename T, typename P>
constexpr auto QuantumPhysics::electronsPerSecondEjected(const T λ, const P P_)
{
	return (P_ * λ) / (_PLANKS_J_ * _C_);
}

template<typename T>
constexpr auto QuantumPhysics::photoelectronsPerSecondEjected(const T A, const T λ, const T I)
{
	return (I * (A * A) * λ) / (_PLANKS_J_ * _C_);
}

template<typename T>
constexpr auto QuantumPhysics::powerCarriedAwayByElectrons(const T λ, const T P, const T BE)
{
	return (((_PLANKS_J_ * _C_) / λ) - (BE*1.602e-19)) * electronsPerSecondEjected(λ, P);
}

template<typename T>
constexpr auto QuantumPhysics::powerCarriedAwayByElectrons(const T A, const T λ, const T I, const T BE)
{
	return I * (A * A) * (1.0 - (BE * λ) / _PLANKS_C_);
}

template<typename T>
constexpr auto QuantumPhysics::frequency_fromE(const T E)
{
	return E / _PLANKS_EM_;
}

template<typename T>
constexpr auto QuantumPhysics::numberOfSimultaneouslyAbsorbedPhotons(const T E_tot, const T E)
{
	return E_tot / E;
}

template<typename T>
constexpr auto QuantumPhysics::numOfTightlyBoundMolecules_γRayCanBreakApart(const T E_tot, const T E)
{
	return E / E_tot;
}

template<typename T>
constexpr auto QuantumPhysics::acceleratingVoltage(const T λ, const T q)
{
	return (_PLANKS_J_ * _C_) / (q * λ);
}

template<typename Q, typename V>
constexpr auto QuantumPhysics::energyMax_eV(const Q q, const V volts)
{
	return q * volts * _JOULES2eV_;
}

template<typename F>
constexpr auto QuantumPhysics::ratioOf_frequencies(const F f_1, const F f_2)
{
	return static_cast<ld>( f_1) / static_cast<ld>( f_2);
}

template<typename F>
 constexpr auto QuantumPhysics::ratioOf_photonsPerSecond(const F f_1, const F f_2)
{
	return static_cast<ld>( f_2) / static_cast<ld>( f_1);
}

template<typename P, typename F>
 constexpr auto QuantumPhysics::photonsPerSecondEmitted(const P P_, const F f)
{
	 return P_ / (_PLANKS_J_ * f);
}

 template<typename P, typename E>
 constexpr auto QuantumPhysics::gammaRaysPerSecondEmitted(const P P_, const E E_)
 {
	 return P_ / (E_ * _PROTON_CHARGE_);
 }

 template<typename P, typename E, typename F>
 constexpr auto QuantumPhysics::distanceBetween2Satellites(const P P_, const E E_, const F Φ)
 {
	 return sqrt(gammaRaysPerSecondEmitted(P_, E_) / (4.0 * _PI * Φ));
 }

 template<typename W>
 constexpr auto QuantumPhysics::photonMomentum(const W λ)
 {
	 return _PLANKS_J_ / λ;
 }

 template<typename E>
 constexpr auto QuantumPhysics::momentum_fromEnergy(const E E_)
 {
	 return (E_*_PROTON_CHARGE_) / _C_;
 }

 template<typename P>
 constexpr auto QuantumPhysics::energy_fromMomentum(const P p)
 {
	 return p * _C_ * _JOULES2eV_;
 }

 template<typename P>
 constexpr auto QuantumPhysics::wavelength_fromMomentum(const P p)
 {
	 return _PLANKS_J_ / p;
 }

 template<typename P, typename M>
 constexpr auto QuantumPhysics::velocityFromMomentum(const P p, const M m)
 {
	 return p / m;
 }

 template<typename M, typename V>
 constexpr auto QuantumPhysics::kineticEnergy(const M m, const V v)
 {
	 return (1.0 / 2.0) * m * (v * v);
 }

 template<typename M, typename W>
 constexpr auto QuantumPhysics::kineticEnergy_fromWavelength(const M m, const W λ)
 {
	 return pow(_PLANKS_J_, 2) / (2.0 * m * (λ * λ)) * _JOULES2eV_;
 }

 template<typename W>
 constexpr auto QuantumPhysics::electronVelocity(const W λ)
 {
	 return _PLANKS_J_ / (_ELECTRON_MASS_ * λ);
 }

 template<typename M, typename W>
 constexpr auto QuantumPhysics::objectVelocity(const M m, const W λ)
 {
	 return _PLANKS_J_ / (m * λ);
 }

 template<typename V>
 constexpr auto QuantumPhysics::electronWavelength_movingAtPercentSpeedOfLight(const V percentOfLightSpeed)
 {
	auto decimalVal = percentOfLightSpeed / 100.0;
	return _PLANKS_J_ / (_ELECTRON_MASS_ * decimalVal * _C_);
 }

 template<typename M, typename V>
 constexpr auto QuantumPhysics::deBrogile_wavelength(const M m, const V v)
 {
	 return _PLANKS_J_ / (m * v);
 }

 template<typename M, typename Q, typename V>
 constexpr auto QuantumPhysics::wavelengthParticleAcceleratedThroughVoltageOf(const M m, const Q q, const V v)
 {
	 return _PLANKS_J_ / (sqrt((2.0 * q * m * v)));
 }

 template<typename M, typename Q, typename V>
 constexpr auto QuantumPhysics::voltageToHaveVelocityOf(const M m, const Q q, const V velocity)
 {
	 return (m * (velocity * velocity)) / (2.0 * q);
 }

 template<typename XX, typename M>
 constexpr auto QuantumPhysics::min_uncertaintyInVelocity(const XX x, const M m)
 {
	 return _PLANKS_J_ / (4.0 * _PI * x * m);
 }

 template<typename M, typename V>
 constexpr auto QuantumPhysics::min_uncertaintyInPosition(const V v, const M m)
 {
	 return _PLANKS_J_ / (4.0 * _PI * m * v);
 }

 template<typename T>
 constexpr auto QuantumPhysics::min_uncertaintyInEnergy(const T t)
 {
	 return _PLANKS_EM_ / (4.0 * _PI * t);
 }

 template<typename E>
 constexpr auto QuantumPhysics::min_uncertaintyInLifetime(const E E_)
 {
	 return _PLANKS_EM_ / (4.0 * _PI * E_);
 }

 template<typename T>
 constexpr auto QuantumPhysics::min_uncertaintyInMass(const T t)
 {
	 return _PLANKS_J_ / (4.0 * _PI * (_C_ * _C_) * t);
 }

 template<typename M, typename C, typename T, typename E>
 constexpr auto QuantumPhysics::photonsRequiredToIncreaseTemperature(
	 const M mass, const C specHeat, const T Δ_temp, const E E_)
 {
	 return (mass * specHeat * Δ_temp) / E_;
 }

 template<typename P, typename W, typename M, typename C, typename T>
 constexpr auto QuantumPhysics::photonsRequiredToIncreaseTemperature(
	 const P watts, const W λ, const M mass, const C specHeat, const T Δ_temp)
 {
	auto engJ = bindingEnergy_Joules(λ);
	return  (mass * specHeat * Δ_temp) / engJ;
 }
