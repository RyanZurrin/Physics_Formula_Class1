#pragma once
#pragma once
/**
 * @struct PeriodicElements
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   11/29/2020
 */
#ifndef PERIODICELEMENTS_H
#define PERIODICELEMENTS_H


static struct UnifiedAtomicMass
{
	const ld kg = 1.66053906660 * 50 * pow(10, -27);
	const ld Mu = 1.0;
	const ld Me = 1822.888486209 * 53;	
}u;
static struct PeriodicElements
{

	static struct neutron
	{
		const ld atomicMass_u = 1.008665;
		const ld halfLife = 622.2;
		const int atomic_number_z = 0;
		const  int atomic_mass_A = 1;
		const string symbol = "n";		
	}n;

	static struct Hydrogen
	{
		const ld atomicMass_u = 1.007825;
		const int atomic_number_z = 1;
		const  int atomic_mass_A = 1;
		const string symbol = "H";
	}H;

	static struct Helium
	{
		const ld atomicMass_u = 3.016030;
		const int atomic_number_z = 2;
		const  int atomic_mass_A = 3;
		const string symbol = "He";
	}He;

	static struct Lithium
	{
		const ld atomicMass_u = 6.015121;
		const int atomic_number_z = 3;
		const  int atomic_mass_A = 6;
		const string symbol = "Li";
	}Li;

	static struct Beryllum
	{
		const ld atomicMass_u = 7.016003;
		const int atomic_number_z = 4;
		const  int atomic_mass_A = 7;
		const string symbol = "Be";
	}Be;

	static struct Boron
	{
		const ld atomicMass_u = 10.012937;
		const int atomic_number_z = 5;
		const  int atomic_mass_A = 10;
		const string symbol = "B";
	}B;

	static struct Carbon
	{
		const ld atomicMass_u = 11.011432;
		const int atomic_number_z = 6;
		const  int atomic_mass_A = 11;
		const string symbol = "C";
	}C; 

	static struct Nitrogen
	{
		const ld atomicMass_u = 13.005738;
		const int atomic_number_z = 7;
		const  int atomic_mass_A = 13;
		const string symbol = "N";
	}N;

	static struct Oxygen
	{
		const ld atomicMass_u = 15.003065;
		const int atomic_number_z = 8;
		const  int atomic_mass_A = 15;
		const string symbol = "O";
	}O;

}periodic_elements;

/*class PeriodicElements
{
public:
	
};*/
#endif