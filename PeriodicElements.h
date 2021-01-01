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

	const struct NEUTRON
	{
		const ld atomic_weight = 1.008665;
		const ld halfLife = 622.2;
		const int atomic_number = 0;
	}n;

	const struct HYDROGEN
	{
		const ld atomic_weight = 1.007825; // u
		const int atomic_number = 1;
		const ld density_STP = .0899; // kg/m^3
		const ld melting_point = -259.1; // C
		const ld boiling_point = -252.9; // C
		const ld thermal_conductivity = .18; // W/mK
		const ld electric_conductivity = NULL; // MS/m
		const ld heat_specific= 14300.0; // J/kgK
		const ld heat_vaporization = .452; // kJ/mol
		const ld heat_fusion = .558; // kJ/mol
	}H;

	const struct HELIUM
	{
		const ld atomic_weight = 4.002602; // u
		const int atomic_number = 2;
		const ld density_STP = 0.1785; // kg/m^3
		const ld melting_point = NULL; // C
		const ld boiling_point = -269; // C
		const ld thermal_conductivity = 0.1513; // W/mK
		const ld electric_conductivity = NULL; // MS/m
		const ld heat_specific= 5193.1; // J/kgK
		const ld heat_vaporization = .083; // kJ/mol
		const ld heat_fusion = .02; // kJ/mol
	}He;

	const struct LITHIUM
	{
		const ld atomic_weight = 6.94; // u
		const int atomic_number = 3;
		const ld density_STP = 535.0; // kg/m^3
		const ld melting_point = 180.54; // C
		const ld boiling_point = 1342.0; // C
		const ld thermal_conductivity = 85.0; // W/mK
		const ld electric_conductivity = 11.0; // MS/m
		const ld heat_specific= 3570.0; // J/kgK
		const ld heat_vaporization = 147.0; // kJ/mol
		const ld heat_fusion = 3.0; // kJ/mol
	}Li;

	const struct BERYLLUM
	{
		const ld atomic_weight = 9.0121831; // u
		const int atomic_number = 4;
		const ld density_STP = 1848.0; // kg/m^3
		const ld melting_point = 1287; // C
		const ld boiling_point = 2470; // C
		const ld thermal_conductivity = 190; // W/mK
		const ld electric_conductivity = 25; // MS/m
		const ld heat_specific= 1820.0; // J/kgK
		const ld heat_vaporization = 297.0; // kJ/mol
		const ld heat_fusion = 7.95; // kJ/mol
	}Be;

	const struct BORON
	{
		const ld atomic_weight = 10.81; // u
		const int atomic_number = 5;
		const ld density_STP = 2460.0; // kg/m^3
		const ld melting_point = 2075; // C
		const ld boiling_point = 4000; // C
		const ld thermal_conductivity = 27.0; // W/mK
		const ld electric_conductivity = pow(1.0, -10); // MS/m
		const ld heat_specific= 1030.0; // J/kgK
		const ld heat_vaporization = 507.0; // kJ/mol
		const ld heat_fusion = 50.0; // kJ/mol
	}B;

	const struct CARBON
	{
		const ld atomic_weight = 12.011; // u
		const int atomic_number = 6;
		const ld density_STP = 2260.0; // kg/m^3
		const ld melting_point = 3550; // C
		const ld boiling_point = 4027; // C
		const ld thermal_conductivity = 140.0; // W/mK
		const ld electric_conductivity = .10; // MS/m
		const ld heat_specific= 710.0; // J/kgK
		const ld heat_vaporization = 715.0; // kJ/mol
		const ld heat_fusion = 105; // kJ/mol
	}C;

	const struct NITROGEN
	{
		const ld atomic_weight = 14.007; // u
		const int atomic_number = 7;
		const ld density_STP = 1.251; // kg/m^3
		const ld melting_point = -210.1; // C
		const ld boiling_point = -195.8; // C
		const ld thermal_conductivity = .025; // W/mK
		const ld electric_conductivity = NULL; // MS/m
		const ld heat_specific = 1040; // J/kgK
		const ld heat_vaporization = 2.79; // kJ/mol
		const ld heat_fusion = .36; // kJ/mol
	}N;

	const struct OXYGEN
	{
		const ld atomic_weight = 15.999; // u
		const int atomic_number = 8;
		const ld density_STP = 1.251; // kg/m^3
		const ld melting_point = -218.0; // C
		const ld boiling_point = -183.0; // C
		const ld thermal_conductivity = 0.02658; // W/mK
		const ld electric_conductivity = NULL; // MS/m
		const ld heat_specific = 919; // J/kgK
		const ld heat_vaporization = 3.41; // kJ/mol
		const ld heat_fusion = .222; // kJ/mol
	}O;

	const struct FLUORINE
	{
		const ld atomic_weight = 18.998403163; // u
		const int atomic_number = 9;
		const ld density_STP = 1.696; // kg/m^3
		const ld melting_point = -220.0; // C
		const ld boiling_point = -188.1; // C
		const ld thermal_conductivity = .0277; // W/mK
		const ld electric_conductivity = NULL; // MS/m
		const ld heat_specific = 824; // J/kgK
		const ld heat_vaporization = 3.27; // kJ/mol
		const ld heat_fusion = .26; // kJ/mol
	}F;

	const struct NEON
	{
		const ld atomic_weight = 20.1797; // u
		const int atomic_number = 10;
		const ld density_STP = .900; // kg/m^3
		const ld melting_point = -248.6; // C
		const ld boiling_point = -246.1; // C
		const ld thermal_conductivity = .0491; // W/mK
		const ld electric_conductivity = NULL; // MS/m
		const ld heat_specific = 1030; // J/kgK
		const ld heat_vaporization = 1.75; // kJ/mol
		const ld heat_fusion = 0.34; // kJ/mol
	}Ne;

	const struct SODIUM
	{
		const ld atomic_weight = 22.98976928; // u
		const int atomic_number = 11;
		const ld density_STP = 968; // kg/m^3
		const ld melting_point = 97.720; // C
		const ld boiling_point = 882.9; // C
		const ld thermal_conductivity = 140.0; // W/mK
		const ld electric_conductivity = 21.0; // MS/m
		const ld heat_specific = 1230; // J/kgK
		const ld heat_vaporization = 97.7; // kJ/mol
		const ld heat_fusion = 2.60; // kJ/mol
	}Na;

	const struct MAGNESIUM
	{
		const ld atomic_weight = 24.305; // u
		const int atomic_number = 12;
		const ld density_STP = 1738.0; // kg/m^3
		const ld melting_point = 650; // C
		const ld boiling_point = 1090; // C
		const ld thermal_conductivity = 160.0; // W/mK
		const ld electric_conductivity = 23.0; // MS/m
		const ld heat_specific = 1020; // J/kgK
		const ld heat_vaporization = 128; // kJ/mol
		const ld heat_fusion = 8.7; // kJ/mol
	}Mg;

	const struct ALUMINIUM
	{
		const ld atomic_weight = 26.9815385; // u
		const int atomic_number = 13;
		const ld density_STP = 2700; // kg/m^3
		const ld melting_point = 660.32; // C
		const ld boiling_point = 2519.0; // C
		const ld thermal_conductivity = 235; // W/mK
		const ld electric_conductivity = 38.0; // MS/m
		const ld heat_specific = 904.0; // J/kgK
		const ld heat_vaporization = 293.0; // kJ/mol
		const ld heat_fusion = 10.7; // kJ/mol
	}Al;

	const struct SILICON
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 14;
		const ld density_STP = 2330.0; // kg/m^3
		const ld melting_point = 1414.0; // C
		const ld boiling_point = 2900.0; // C
		const ld thermal_conductivity = 150.0; // W/mK
		const ld electric_conductivity = .0010; // MS/m
		const ld heat_specific = 710.0; // J/kgK
		const ld heat_vaporization = 359.0; // kJ/mol
		const ld heat_fusion = 50.2; // kJ/mol
	}Si;

	const struct PHOSPHORUS
	{
		const ld atomic_weight = 30.973761998; // u
		const int atomic_number = 15;
		const ld density_STP = 1823.0; // kg/m^3
		const ld melting_point = 44.15; // C
		const ld boiling_point = 280.5; // C
		const ld thermal_conductivity = .236; // W/mK
		const ld electric_conductivity = 10.0; // MS/m
		const ld heat_specific = 769.7; // J/kgK
		const ld heat_vaporization = 12.4; // kJ/mol
		const ld heat_fusion = .64; // kJ/mol
	}P;

	const struct SULFUR
	{
		const ld atomic_weight = 32.06; // u
		const int atomic_number = 16;
		const ld density_STP = 1960.0; // kg/m^3
		const ld melting_point = 115.21; // C
		const ld boiling_point = 444.72; // C
		const ld thermal_conductivity = .205; // W/mK
		const ld electric_conductivity = pow(1.0, -21); // MS/m
		const ld heat_specific = 705.0; // J/kgK
		const ld heat_vaporization = 9.8; // kJ/mol
		const ld heat_fusion = 1.73; // kJ/mol
	}S;

	const struct CHLORINE
	{
		const ld atomic_weight =35.45; // u
		const int atomic_number = 17;
		const ld density_STP = 3.214; // kg/m^3
		const ld melting_point = -101.5; // C
		const ld boiling_point = -34.040; // C
		const ld thermal_conductivity = .0089; // W/mK
		const ld electric_conductivity = pow(1.0, -8.0); // MS/m
		const ld heat_specific = 478.2; // J/kgK
		const ld heat_vaporization = 10.2; // kJ/mol
		const ld heat_fusion = 3.2; // kJ/mol
	}Cl;

	const struct ARGON
	{
		const ld atomic_weight = 39.948; // u
		const int atomic_number = 18;
		const ld density_STP = 1784.0; // kg/m^3
		const ld melting_point = -189; // C
		const ld boiling_point = -186; // C
		const ld thermal_conductivity = .01772; // W/mK
		const ld electric_conductivity = NULL; // MS/m
		const ld heat_specific = 520.33; // J/kgK
		const ld heat_vaporization = 6.5; // kJ/mol
		const ld heat_fusion = 1.18; // kJ/mol
	}Ar;

	const struct POTASSIUM
	{
		const ld atomic_weight = 39.0983; // u
		const int atomic_number = 19;
		const ld density_STP = 856; // kg/m^3
		const ld melting_point = 63.380; // C
		const ld boiling_point = 758.9; // C
		const ld thermal_conductivity = 100.0; // W/mK
		const ld electric_conductivity = 14.0; // MS/m
		const ld heat_specific = 757; // J/kgK
		const ld heat_vaporization = 76.9; // kJ/mol
		const ld heat_fusion = 2.33; // kJ/mol
	}K;

	const struct CALCIUM
	{
		const ld atomic_weight = 40.078; // u
		const int atomic_number = 20;
		const ld density_STP = 1550.0; // kg/m^3
		const ld melting_point = 841.9; // C
		const ld boiling_point = 1484; // C
		const ld thermal_conductivity = 200.0; // W/mK
		const ld electric_conductivity = 29; // MS/m
		const ld heat_specific = 631; // J/kgK
		const ld heat_vaporization = 155.0; // kJ/mol
		const ld heat_fusion = 8.54; // kJ/mol
	}Ca;

	const struct SCANDIUM
	{
		const ld atomic_weight = 44.955908; // u
		const int atomic_number = 21;
		const ld density_STP = 2985.0; // kg/m^3
		const ld melting_point = 1541.0; // C
		const ld boiling_point = 2830.0; // C
		const ld thermal_conductivity = 16; // W/mK
		const ld electric_conductivity = 1.8; // MS/m
		const ld heat_specific = 567.0; // J/kgK
		const ld heat_vaporization = 318.0; // kJ/mol
		const ld heat_fusion = 16.0; // kJ/mol
	}Sc;

	const struct TITANIUM
	{
		const ld atomic_weight = 47.867; // u
		const int atomic_number = 22;
		const ld density_STP = 4507.0; // kg/m^3
		const ld melting_point = 1668.0; // C
		const ld boiling_point = 3287.0; // C
		const ld thermal_conductivity = 22.0; // W/mK
		const ld electric_conductivity = 2.5; // MS/m
		const ld heat_specific = 520.0; // J/kgK
		const ld heat_vaporization = 425.0; // kJ/mol
		const ld heat_fusion = 18.7; // kJ/mol
	}Ti;

	const struct VANADIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}V;

	const struct CHROMIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Cr;

	const struct MANGANESE
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Mn;

	const struct IRON
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Fe;

	const struct COBALT
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Co;

	const struct NICKEL
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Ni;

	const struct COPPER
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Cu;

	const struct ZINC
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Zn;

	const struct GALLIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Ga;

	const struct GERMANIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Ge;

	const struct ARSENIC
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}As;

	const struct SELENIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Se;

	const struct BROMINE
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Br;

	const struct KRYPTON
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Kr;

	const struct RUBIDIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Rb;

	const struct STRONTIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Sr;

	const struct YTTRIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Y;

	const struct ZERCONIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Zr;

	const struct NIOBIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Nb;

	const struct MOLYBDENUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Mo;

	const struct TECHNETIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Tc;

	const struct RUTHENIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Ru;

	const struct RHODIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Rh;

	const struct PALLADIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Pd;

	const struct SILVER
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Ag;

	const struct CADMIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Cd;

	const struct INDIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}In;

	const struct TIN
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Sn;

	const struct ANTIMONY
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Sb;

	const struct TELURIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 52;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Te;

	const struct IODINE
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}I;

	const struct XENON
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}XE;



}PE;


#endif

/**
 	const struct TEMPLATEELEMENT
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Tmp;

 */