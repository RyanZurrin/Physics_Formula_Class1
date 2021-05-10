#pragma once
/**
 * class: SpecialRelativity
 * details: driver class for solving complex physics problems
 * author: Ryan Zurrin
 * dateBuilt:  5/3/2021
 * lastEdit: 5/3/2021
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

	static void show_objectCount() { std::cout << "\n ________ object count: "
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
	auto lorentzFactor(const T ν);

	/// <summary>
	/// Find the value of γ(gamma) for the following situation. An Earth-bound
	/// observer measures t h to have passed while signals from a high-velocity
	/// space probe indicate that t_o h have passed on board.
	/// </summary>
	/// <param name="t">The t.</param>
	/// <param name="t_o">The t o.</param>
	/// <returns></returns>
	template<typename T, typename K>
	auto lorentzValue(const T t, const K t_o);

	/// <summary>
	/// Particles called π-mesons are produced by accelerator beams. If these
	/// particles travel at v m/s and live t s when at rest
	/// relative to an observer, this method will calculate how long they
	/// live as viewed in the laboratory?
	/// </summary>
	/// <param name="ν">The speed of particle.</param>
	/// <param name="t">The time in seconds particle can live.</param>
	/// <returns>relativistic time alive is seconds, time dilation</returns>
	template<typename T, typename K>
	auto relativisticTime(const T ν, const K t);

	/// <summary>
	/// Suppose a particle called a kaon is created by cosmic radiation striking
	/// the atmosphere. It moves by you at vc, and it lives t s when
	/// at rest relative to an observer. How long does it live as you observe it?
	/// </summary>
	/// <param name="ν">The velocity .</param>
	/// <param name="t">The relatively observed time.</param>
	/// <returns>time from observers perspective</returns>
	template<typename T, typename K>
	auto observersTime(const T νc, const K t);

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
	auto relativeVelocity(const T t, const K t_o);

	/// <summary>
	/// If relativistic effects are to be less than percent_γ %, then γ must be less
	/// than x = 1.00 + %. At what relative velocity is γ=x
	/// </summary>
	/// <param name="percent_γ">The percent of Lorentz(γ).</param>
	/// <returns>speed to achieve desired percent of Lorentz factor</returns>
	template<typename T>
	auto relativeVelocity_percentLorentz(const T percent_γ);

	/// <summary>
	/// Calculate at what relative velocity is gamma= γ
	/// </summary>
	/// <param name="γ">The γ.</param>
	/// <returns></returns>
	template<typename T>
	auto relativeVelocity_lorantzAt(const T γ);

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
	auto observedVelocity(const T t, const K t_o);


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
	auto length_earthBoundObserver(const T L_o, const K vc);

	/// <summary>
	/// How fast would a l_o m-long sports car have to be going past you in
	/// order for it to appear only l m long?
	/// </summary>
	/// <param name="l_o">The original length, real length.</param>
	/// <param name="l">The relativistic length.</param>
	/// <returns>velocity to appear length</returns>
	template<typename T, typename K>
	auto speedToAppearSomeLength(const T l_o, const K l);

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
	auto distanceTraveled_earthBoundObserver(const T t_o, const K vc);

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
	auto distanceTraveled_relativeObserver(const T t_o, const K vc);


	/// <summary>
	/// Verify that two distances are related through length contraction
	/// if gamma = γ.
	/// </summary>
	/// <param name="l_o">The proper length.</param>
	/// <param name="γ">The γ.</param>
	/// <returns>contracted length</returns>
	template<typename T, typename K>
	auto contractedLength(const T l_o, const K γ);





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
inline auto SpecialRelativity::relativisticTime(const T ν, const K t)
{
	return t / sqrt(1.0 - ((ν * ν)/(C_*C_) ));
}

template<typename T, typename K>
inline auto SpecialRelativity::observersTime(const T νc, const K t)
{
	return t / sqrt(1.0 - (νc * νc));
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
inline auto SpecialRelativity::length_earthBoundObserver(const T L_o, const K vc)
{
	return L_o * sqrt(1.0 - (vc * vc));
}

template<typename T, typename K>
inline auto SpecialRelativity::speedToAppearSomeLength(const T l_o, const K l)
{
	return _c_ * sqrt(1.0 - (l / l_o));
}

template<typename T, typename K>
inline auto SpecialRelativity::distanceTraveled_earthBoundObserver(const T t_o, const K vc)
{
	return sqrt(1.0 - (vc * vc)) * vc * _c_ * t_o;
}

template<typename T, typename K>
inline auto SpecialRelativity::distanceTraveled_relativeObserver(const T t_o, const K vc)
{
	return vc * _c_ * t_o;
}

template<typename T, typename K>
inline auto SpecialRelativity::contractedLength(const T l_o, const K γ)
{
	return l_o / γ;
}
