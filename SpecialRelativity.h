﻿#pragma once
/**
 * class: SpecialRelativity
 * details: driver class for solving complex physics problems
 * author: Ryan Zurrin
 * dateBuilt:  5/3/2021
 * lastEdit: 5/9/2021
 */
//α=224,ß=225,π=227,Σ=228,σ=229,µ=230,τ=231,Φ=232,Θ=233
//Ω=234,δ=235,∞=236,φ=237,ε=238,∩=239,≡=240,Γ=226,γ, σ, ϑ, Å, Ώ, λ
#ifndef SPECIAL_RELATIVITY_H
#define SPECIAL_RELATIVITY_H
#include <iostream>
static int specialRelativity_objectCount = 0;
typedef long double ld;

class SpecialRelativity:
	public VisionOpticalInstruments
{
public:
	SpecialRelativity* _specialRelativityPtr;

	SpecialRelativity()
	{
		_specialRelativityPtr = nullptr;
		specialRelativityVar = 0.0;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	SpecialRelativity(const SpecialRelativity& t)
	{
		_specialRelativityPtr = t._specialRelativityPtr;
		specialRelativityVar = t.specialRelativityVar;
		countIncrease();
	}
	/**
	 * #brief move constructor
	 */
	SpecialRelativity(SpecialRelativity&& t) noexcept
	{
		_specialRelativityPtr = t._specialRelativityPtr;
		specialRelativityVar = t.specialRelativityVar;
		countIncrease();
	}
	/**
	 * @brief copy assignment operator
	 */
	SpecialRelativity& operator=(const SpecialRelativity& t)
	{
		if (this != &t)
		{
			_specialRelativityPtr = t._specialRelativityPtr;
			specialRelativityVar = t.specialRelativityVar;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount() { std::cout << "\n special relativity object count: "
							<< specialRelativity_objectCount << std::endl; }
	static int get_objectCount() { return specialRelativity_objectCount; }

	/// <summary>
	/// Calculates the Lorentz factor(γ) if v is a decimal of the percent of the
	/// speed of light, for instance if something was going half the speed of
	/// light you would put a value of .500 for v.
	/// </summary>
	/// <param name="ν">The velocity .</param>
	/// <returns>Lorentz factor, gamma (γ)</returns>
	template<typename T>
	static auto lorentzFactor(const T ν);

	/// <summary>
	/// Find the value of γ(gamma) for the following situation. An Earth-bound
	/// observer measures t h to have passed while signals from a high-velocity
	/// space probe indicate that t_o h have passed on board.
	/// </summary>
	/// <param name="t">The relativistic time(should be greater then proper).</param>
	/// <param name="t_o">The proper time.</param>
	/// <returns>value of gamma, Lorentz factor</returns>
	template<typename T, typename K>
	static auto lorentzValue(const T t, const K t_o);

	/// <summary>
	/// Particles called π-mesons are produced by accelerator beams. If these
	/// particles travel at v m/s and live t s when at rest
	/// relative to an observer, this method will calculate how long they
	/// live as viewed in the laboratory?
	/// </summary>
	/// <param name="ν">The speed of particle.</param>
	/// <param name="t_o">The time in seconds particle can live.</param>
	/// <returns>relativistic time alive is seconds, time dilation</returns>
	template<typename T, typename K>
	static auto relativisticTimeDilation(const T ν, const K t_o);

	/// <summary>
	/// Suppose a particle called a kaon is created by cosmic radiation striking
	/// the atmosphere. It moves by you at vc, and it lives t s when
	/// at rest relative to an observer. How long does it live as you observe it?
	/// </summary>
	/// <param name="ν">The velocity .</param>
	/// <param name="t_o">The relatively observed time.</param>
	/// <returns>time from observers perspective</returns>
	template<typename T, typename K>
	static auto timeDilation(const T νc, const K t_o);

	/// <summary>
	/// A neutral π-meson is a particle that can be created by accelerator
	/// beams. If one such particle lives t s as measured in the
	/// laboratory, and t_o s when at rest relative to an observer,
	/// what is its velocity relative to the laboratory?
	/// </summary>
	/// <param name="t">The observed time.</param>
	/// <param name="t_o">The proper time, time at rest.</param>
	/// <returns>speed relative to the observed time</returns>
	template<typename T, typename K>
	static auto relativeVelocity(const T t, const K t_o);

	/// <summary>
	/// If relativistic effects are to be less than percent_γ %, then γ must be less
	/// than x = 1.00 + %. At what relative velocity is γ=x
	/// </summary>
	/// <param name="percent_γ">The percent of Lorentz(γ).</param>
	/// <returns>speed to achieve desired percent of Lorentz factor</returns>
	template<typename T>
	static auto relativeVelocity_percentLorentz(const T percent_γ);

	/// <summary>
	/// Calculate at what relative velocity is gamma= γ
	/// </summary>
	/// <param name="γ">The γ.</param>
	/// <returns></returns>
	template<typename T>
	static auto relativeVelocity_lorantzAt(const T γ);

	/// <summary>
	/// A neutron lives t_o s when at rest relative to an observer. How fast
	/// is the neutron moving relative to an observer who measures its life
	/// span to be t s?
	/// </summary>
	/// <param name="t">The time at rest with respect to observer(proper time).</param>
	/// <param name="t_o">The observed time.</param>
	/// <returns>speed of particle as measured by while being observed in
	/// under proper time</returns>
	template<typename T, typename K>
	static auto observedVelocity(const T t, const K t_o);


	/// <summary>
	/// A spaceship, L_o m long as seen on board, moves by the Earth at vc.
	/// (.950 = .950c) ->leave out the c but this is what % of the speed of
	/// light something is traveling.
	/// What is its length as measured by an Earth-bound observer?
	/// </summary>
	/// <param name="L_o">The actual length.</param>
	/// <param name="vc">The velocity relative to light speed c.</param>
	/// <returns>observed length, relativistic length</returns>
	template<typename T, typename K>
	static auto relativisticLength(const T L_o, const K vc);

	/// <summary>
	/// How fast would a l_o m-long sports car have to be going past you in
	/// order for it to appear only l m long?
	/// </summary>
	/// <param name="l_o">The original length, real length.</param>
	/// <param name="l">The relativistic length.</param>
	/// <returns>velocity to appear length</returns>
	template<typename T, typename K>
	static auto speedToAppearSomeLength(const T l_o, const K l);

	/// <summary>
	/// Suppose a cosmic ray colliding with a nucleus in the Earth’s upper
	/// atmosphere produces a muon that has a velocity v=0.950c(vc). The muon then
	/// travels at constant velocity and lives 1.52μs(t_o) as measured in the muon’s
	/// frame of reference. (You can imagine this as the muon’s internal clock.)
	/// How long does the muon live as measured by an Earth-bound observer?
	/// </summary>
	/// <param name="t_o">The t o.</param>
	/// <param name="vc">The vc.</param>
	/// <returns>distance traveled by particle from stationary observers
	/// perspective</returns>
	template<typename T, typename K>
	static auto distanceTraveled_earthBoundObserver(const T t_o, const K vc);

	/// <summary>
	/// Suppose a cosmic ray colliding with a nucleus in the Earth’s upper
	/// atmosphere produces a muon that has a velocity v=0.950c(vc). The muon then
	/// travels at constant velocity and lives 1.52μs(t_o) as measured in the muon’s
	/// frame of reference. (You can imagine this as the muon’s internal clock.)
	/// How far does it travel as viewed by an observer moving with it?
	/// Base your calculation on its velocity relative to the Earth and the
	/// time it lives (proper time)
	/// </summary>
	/// <param name="t_o">The t o.</param>
	/// <param name="vc">The vc.</param>
	/// <returns>distance traveled (m)</returns>
	template<typename T, typename K>
	static auto distanceTraveled_proper(const T t_o, const K vc);


	/// <summary>
	/// Verify that two distances are related through length contraction
	/// if gamma = γ.
	/// </summary>
	/// <param name="l_o">The proper length.</param>
	/// <param name="γ">The γ.</param>
	/// <returns>contracted length</returns>
	template<typename T, typename K>
	static auto contractedLength(const T l_o, const K γ);

	/// <summary>
	///  How long does it take the astronaut  to travel
	///  l_o units at vc units of speed (as measured by the Earth- bound observer)
	/// </summary>
	/// <param name="l_o">The proper length.</param>
	/// <param name="vc">The velocity with respect to speed of light.</param>
	/// <returns>time to travel some distance</returns>
	template<typename T, typename K>
	static auto time(const T l_o, const K vc);

	/// <summary>
	/// How long does it take a astronaut to travel t units at a speed of vc units
	/// according to the astronaut, which is proper time
	/// </summary>
	/// <param name="t">The relativistic time.</param>
	/// <param name="vc">The speed.</param>
	/// <returns>proper time</returns>
	template<typename T, typename K>
	static auto properTime(const T t, const K vc);

	/// <summary>
	/// Verify time is related through time dilation with gamma = γ as given.
	/// </summary>
	/// <param name="t_o">The t o.</param>
	/// <param name="γ">The γ.</param>
	/// <returns></returns>
	template<typename T, typename K>
	static auto timeGamma(const T t_o, const K  γ);

	/// <summary>
	/// A spaceship is heading directly toward the Earth at a velocity of
	/// 0.800c(uv) . The astronaut on board claims that he can send a canister
	/// toward the Earth at 1.20c(v) relative to the Earth. Calculate the
	/// velocity the canister must have relative to the spaceship.
	/// </summary>
	/// <param name="v">The v.</param>
	/// <param name="uv">The uv.</param>
	/// <returns>speed relativity relationship</returns>
	template<typename T, typename K>
	static auto relative_velocity_away(const T v, const K uv);

	/// <summary>
	/// Relatives the velocity towards.
	/// </summary>
	/// <param name="v">The v.</param>
	/// <param name="uv">The uv.</param>
	/// <returns></returns>
	template<typename T, typename K>
	static auto relative_velocity_towards(const T v, const K uv);

	/// <summary>
	/// When a missile is shot from one spaceship towards another, it leaves
	/// the first at 0.950c(u_) and approaches the other at 0.750c(u). What is the
	/// relative velocity of the two ships?
	/// </summary>
	/// <param name="u">The relative velocity of object to observer .</param>
	/// <param name="u_">The relative velocity to the other observer.</param>
	/// <returns>relative velocity between the two observers</returns>
	template<typename T, typename K>
	static auto relativeVelocity_between2Objects(const T u, const K u_);

	/// <summary>
	/// Suppose the speed of light were only 3000 m/s(c_) . A jet fighter moving
	/// toward a target on the ground at 800 m/s(v) shoots bullets, each having a
	/// muzzle velocity of 1000 m/s(uv). calculate the bullets’ velocity relative
	/// to the target.
	/// </summary>
	/// <param name="v">The velocity of observer.</param>
	/// <param name="uv">The velocity of object.</param>
	/// <param name="c_">The speed of light.</param>
	/// <returns>velocity relative to target</returns>
	template<typename T, typename K, typename C>
	static auto relative_velocity(const T v, const K uv, const C c_);

	/// <summary>
	/// If a galaxy moving away from the Earth has a speed of 1000 km/s(u) and
	/// emits 656 nm(λ_s) light characteristic of hydrogen (the most common element
	/// in the universe). Calculate the wavelength we observe on the Earth
	/// </summary>
	/// <param name="u">The speed.</param>
	/// <param name="λ_s">The wavelength source.</param>
	/// <returns>observed wavelength</returns>
	template<typename T, typename K>
	static auto wavelengthObserved(const T u, const K λ_s);

	/// <summary>
	/// A space probe speeding towards the nearest star moves at 0.250c(u) and
	/// sends radio information at a broadcast frequency of 1.00 GHz(f_s).
	/// Calculate what frequency is received on the Earth.
	/// </summary>
	/// <param name="uc">The speed.</param>
	/// <param name="f_s">The f s.</param>
	/// <returns></returns>
	template<typename T, typename K>
	static auto frequencyObserved(const T uc, const K f_s);

	/// <summary>
	/// Near the center of our galaxy, hydrogen gas is moving directly away
	/// from us in its orbit about a black hole. We receive 1900(λ_obs) nm electromagnetic
	/// radiation and know that it was 1875 nm(λ_s) when emitted by the hydrogen gas.
	/// What is the speed of the gas
	/// </summary>
	/// <param name="λ_s">The λ s.</param>
	/// <param name="λ_obs">The λ obs.</param>
	/// <returns></returns>
	template<typename T, typename K>
	static auto velocity_fromWaveLengths(const T λ_s, const K λ_obs);

	/// <summary>
	/// A highway patrol officer uses a device that measures the speed of
	/// vehicles by bouncing radar off them and measuring the Doppler shift.
	/// The outgoing radar has a frequency of 100 GHz(f_S) and the returning echo
	/// has a frequency 15.0 kHz(increase) higher. What is the velocity of the vehicle?
	/// Note that there are two Doppler shifts in echoes. Be certain not to
	/// round off until the end of the problem, because the effect is small.
	/// </summary>
	/// <param name="f_s">The frequency from the source.</param>
	/// <param name="increase">The increase in the frequency from it bouncing
	/// back to the radar gun.</param>
	/// <returns>velocity of moving object the frequency bounced off of</returns>
	template<typename T, typename K>
	static auto velocity_fromFrequencyEcho(const T f_s, const K increase);

	/// <summary>
	/// All but the closest galaxies are receding from our own Milky Way Galaxy.
	/// If a galaxy 12.0×109 ly(l_o) away is receding from us at 0.900c(v), if
	/// the velocity relative to us of the probe moving towards the other galaxy
	/// is 0.99947c(u), as measured from that galaxy, calculate
	/// How long it will take the probe to reach the other galaxy as
	/// measured from the Earth. You may assume that the velocity of the other
	/// galaxy remains constant.
	/// <param name="u">The u.</param>
	/// <param name="v">The v.</param>
	/// <param name="l_o">The l o.</param>
	/// <returns>time for probe to reach other galaxy</returns>
	template<typename T, typename K, typename L>
	static auto relativisticTime(const T u, const K v, const L l_o);

	/// <summary>
	/// Find the momentum of a helium nucleus having a mass of 6.68×10−27 kg(m)
	/// that is moving at 0.200c.(u)
	/// </summary>
	/// <param name="m">The mass.</param>
	/// <param name="u">The velocity.</param>
	/// <returns>relativistic momentum</returns>
	template<typename T, typename K>
	static auto momentum(const T m, const K u);

	/// <summary>
	/// Find the momentum of a 1.00×109 kg(m) asteroid heading towards the
	/// Earth at 30.0 km/s(u).
	/// </summary>
	/// <param name="m">The m.</param>
	/// <param name="u">The u.</param>
	/// <returns></returns>
	template<typename T, typename K>
	static auto momentum_slowerObject(const T m, const K u);

	/// <summary>
	///  Find the ratio of this momentum to the classical momentum.
	///  (Use the approximation that γ=1+12v2c2 at low velocities.)
	/// </summary>
	/// <param name="v">The velocity.</param>
	/// <returns>gamma, Lorentz factor</returns>
	template<typename T>
	static auto momentumRatios_classical2relativistic(const T v);

	/// <summary>
	/// What is the velocity of an electron that has a momentum of
	/// 3.04×10−21 kg⋅m/s?(p) Note that you must calculate the velocity to
	/// at least four digits to see the difference from c.
	/// </summary>
	/// <param name="p">The relativistic momentum.</param>
	/// <param name="m">The mass.</param>
	/// <returns>velocity</returns>
	template<typename T, typename M>
	static auto velocityFrom_momentum(const T p, const M m);

	/// <summary>
	/// What is the rest energy of an electron, given its mass is 9.11
	/// *10^-31 kg(m)
	/// </summary>
	/// <param name="m">The mass.</param>
	/// <returns>energy in joules</returns>
	template<typename T>
	static auto restEnergy(const T m);




	~SpecialRelativity()
	{
		delete _specialRelativityPtr;
	}
	void setTemplateVar(ld var) { specialRelativityVar = var; }
	ld getTemplateVar() const { return specialRelativityVar; }

private:
	ld specialRelativityVar;
	static void countIncrease() { specialRelativity_objectCount += 1; }
	static void countDecrease() { specialRelativity_objectCount -= 1; }

};
#endif

template<typename T>
inline auto SpecialRelativity::lorentzFactor(const T νc)
{
	return 1.0 / sqrt(1.0 - (νc * νc));
}

template<typename T, typename K>
inline auto SpecialRelativity::lorentzValue(const T t, const K t_o)
{
	return t / t_o;
}

template<typename T, typename K>
inline auto SpecialRelativity::relativisticTimeDilation(const T ν, const K t_o)
{
	return t_o / sqrt(1.0 - ((ν * ν)/(C_*C_) ));
}

template<typename T, typename K>
inline auto SpecialRelativity::timeDilation(const T νc, const K t_o)
{
	return t_o / sqrt(1.0 - (νc * νc));
}

template<typename T, typename K>
inline auto SpecialRelativity::relativeVelocity(const T t, const K t_o)
{
	return (_c_ / t) * sqrt(pow(t, 2) - pow(t_o, 2));
}

template<typename T>
inline auto SpecialRelativity::relativeVelocity_percentLorentz(const T percent_γ)
{// γ = gamma = Lorentz
	const auto γ = 1.00 + percent_γ / 100;
	return (_c_ / γ) * sqrt((γ * γ) - 1);
}

template<typename T>
inline auto SpecialRelativity::relativeVelocity_lorantzAt(const T γ)
{
	return _c_ * sqrt(1.0 - (1.0 / (γ * γ)));
}

template<typename T, typename K>
inline auto SpecialRelativity::observedVelocity(const T t, const K t_o)
{
	return _c_ * sqrt((1.0 - (t_o * t_o) / (t * t)));
}

template<typename T, typename K>
inline auto SpecialRelativity::relativisticLength(const T L_o, const K vc)
{
	return L_o * sqrt(1.0 - (vc * vc));
}

template<typename T, typename K>
inline auto SpecialRelativity::speedToAppearSomeLength(const T l_o, const K l)
{
	return _c_ * sqrt(1.0 - ((l*l)/ (l_o* l_o)));
}

template<typename T, typename K>
inline auto SpecialRelativity::distanceTraveled_earthBoundObserver(const T t_o, const K vc)
{
	return sqrt(1.0 - (vc * vc)) * vc * _c_ * t_o;
}

template<typename T, typename K>
inline auto SpecialRelativity::distanceTraveled_proper(const T t_o, const K vc)
{
	return vc * _c_ * t_o;
}

template<typename T, typename K>
inline auto SpecialRelativity::contractedLength(const T l_o, const K γ)
{
	return l_o / γ;
}

template<typename T, typename K>
inline auto SpecialRelativity::time(const T l_o, const K vc)
{
	return l_o / (vc*_c_);
}

template<typename T, typename K>
inline auto SpecialRelativity::properTime(const T t, const K vc)
{
	return sqrt(1.0 - (vc * vc)) * t;
}

template<typename T, typename K>
inline auto SpecialRelativity::timeGamma(const T t_o, const K γ)
{
	return  γ * t_o;
}

template<typename T, typename K>
inline auto SpecialRelativity::relative_velocity_away(const T v, const K uv)
{
	return (v - uv) / (1.0 - (v * uv));
}

template<typename T, typename K>
inline auto SpecialRelativity::relative_velocity_towards(const T v, const K uv)
{
	return (v + uv) / (1.0 + (v * uv));
}

template<typename T, typename K>
inline auto SpecialRelativity::relativeVelocity_between2Objects(const T u, const K u_)
{
	return (u_ - u) / ((u_ * u) - 1);
}

template<typename T, typename K, typename C>
inline auto SpecialRelativity::relative_velocity(const T v, const K uv, const C c_)
{
	return (v + uv) / (1.0 + ((v * uv)/(c_*c_)));
}

template<typename T, typename K>
inline auto SpecialRelativity::wavelengthObserved(const T u, const K λ_s)
{
	return λ_s * sqrt((1.0 + (u / _c_)) / (1.0 - (u / _c_)));
}

template<typename T, typename K>
inline auto SpecialRelativity::frequencyObserved(const T uc, const K f_s)
{
	return f_s * sqrt((1.0 - (uc )) / (1.0 + (uc )));
}

template<typename T, typename K>
inline auto SpecialRelativity::velocity_fromWaveLengths(const T λ_s, const K λ_obs)
{
	return _c_ * ((((λ_obs * λ_obs) / (λ_s * λ_s)) - 1.0) / (1.0 + (((λ_obs * λ_obs) / (λ_s * λ_s)))));
}

template<typename T, typename K>
inline auto SpecialRelativity::velocity_fromFrequencyEcho(const T f_s, const K increase)
{
	return _c_ * (-increase) / (2.0 * f_s + increase);
}

template<typename T, typename K, typename L>
inline auto SpecialRelativity::relativisticTime(const T u, const K v, const L l_o)
{
	return l_o / (u - v);
}

template<typename T, typename K>
inline auto SpecialRelativity::momentum(const T m, const K u)
{
	return (m * (u * _c_)) / sqrt(1.0 - (u * u));
}

template<typename T, typename K>
inline auto SpecialRelativity::momentum_slowerObject(const T m, const K u)
{
	return (m * u) / sqrt(1.0 - ((u * u)/(_c_*_c_)));
}

template<typename T>
inline auto SpecialRelativity::momentumRatios_classical2relativistic(const T v)
{
	return 1.0 + (1 / 2) * ((v * v) / (_c_ * _c_));
}

template<typename T, typename M>
inline auto SpecialRelativity::velocityFrom_momentum(const T p, const M m)
{
	return p / sqrt((m * m) + ((p * p) / (_c_ * _c_)));
}

template<typename T>
inline auto SpecialRelativity::restEnergy(const T m)
{
	return m * (_c_ * _c_);
}

