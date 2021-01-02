#pragma once

/**
 * @struct PeriodicElements
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   1/1/2021
 */
#ifndef PERIODICELEMENTS_H
#define PERIODICELEMENTS_H


static struct UnifiedAtomicMass
{
	const ld kg = 1.66053906660 * 50 * pow(10, -27);
	const ld Mu = 1.0;
	const ld Me = 1822.888486209 * 53;
} u;


static struct Elements
{
	Elements() { cout << "testing Element" << endl; };

	const struct NEUTRON
	{
		const ld atomic_weight = 1.008665;
		const ld halfLife = 622.2;
		const int atomic_number = 0;
	} n;

	const struct HYDROGEN
	{
		const ld atomic_weight = 1.007825; // 1.007825 u
		const int atomic_number = 1; // 1
		const ld density_STP = .0899; // .0899 kg/m^3
		const ld melting_point = -259.1; // -259.1 C
		const ld boiling_point = -252.9; // -252.9 C
		const ld thermal_conductivity = .18; // .18 W/mK
		const ld electric_conductivity = NULL; // NULL
		const ld resistivity = NULL; //NULL
		const ld heat_specific = 14300.0; // 14300.0 J/kgK
		const ld heat_vaporization = .452; // 452 kJ/mol
		const ld heat_fusion = .558; // .558 kJ/mol
	} H;

	const struct HELIUM
	{
		const ld atomic_weight = 4.002602; // 4.002602 u
		const int atomic_number = 2; // 2
		const ld density_STP = 0.1785; // 0.1785 kg/m^3
		const ld melting_point = NULL; // C
		const ld boiling_point = -269; // -269 C
		const ld thermal_conductivity = 0.1513; // 0.1513 W/mK
		const ld electric_conductivity = NULL; // NULL
		const ld resistivity = NULL; // NULL
		const ld heat_specific = 5193.1; // 5193.1 J/kgK
		const ld heat_vaporization = .083; // .083 kJ/mol
		const ld heat_fusion = .02; // .02 kJ/mol
	} He;

	const struct LITHIUM
	{
		const ld atomic_weight = 6.94; // 6.94 u
		const int atomic_number = 3; // 3
		const ld density_STP = 535.0; // 535.0 kg/m^3
		const ld melting_point = 180.54; // 180.54 C
		const ld boiling_point = 1342.0; // 1342.0 C
		const ld thermal_conductivity = 85.0; // 85.0 W/mK
		const ld electric_conductivity = 11.0; // 11.0 MS/m
		const ld resistivity = 9.40 * pow(10, -8); // 9.4e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 3570.0; // 3570.0 J/kgK
		const ld heat_vaporization = 147.0; // 147.0 kJ/mol
		const ld heat_fusion = 3.0; // 3.0 kJ/mol
	} Li;

	const struct BERYLLUM
	{
		const ld atomic_weight = 9.0121831; // 9.0121831 u
		const int atomic_number = 4; //4
		const ld density_STP = 1848.0; // 1848.0 kg/m^3
		const ld melting_point = 1287; // 1287 C
		const ld boiling_point = 2470; // 2470 C
		const ld thermal_conductivity = 190; // 190 W/mK
		const ld electric_conductivity = 25; // 25 MS/m
		const ld resistivity = 3.999999999998 * pow(10, -8); // 4e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 1820.0; // 1820.0 J/kgK
		const ld heat_vaporization = 297.0; // 297.0 kJ/mol
		const ld heat_fusion = 7.95; // 7.95 kJ/mol
	} Be;

	const struct BORON
	{
		const ld atomic_weight = 10.81; // 10.81 u
		const int atomic_number = 5; // 5
		const ld density_STP = 2460.0; // 2460.0 kg/m^3
		const ld melting_point = 2075; // 2075 C
		const ld boiling_point = 4000; // 4000 C
		const ld thermal_conductivity = 27.0; // 27.0W/mK
		const ld electric_conductivity = 1; // MS/m
		const ld resistivity = 10000.0; // 10000 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 1030.0; // J/kgK
		const ld heat_vaporization = 507.0; // kJ/mol
		const ld heat_fusion = 50.0; // kJ/mol
	} B;

	const struct CARBON
	{
		const ld atomic_weight = 12.011; // u
		const int atomic_number = 6;
		const ld density_STP = 2260.0; // kg/m^3
		const ld melting_point = 3550; // C
		const ld boiling_point = 4027; // C
		const ld thermal_conductivity = 140.0; // W/mK
		const ld electric_conductivity = .10; // MS/m
		const ld resistivity = 0.00001; // 0.00001 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 710.0; // J/kgK
		const ld heat_vaporization = 715.0; // kJ/mol
		const ld heat_fusion = 105; // kJ/mol
	} C;

	const struct NITROGEN
	{
		const ld atomic_weight = 14.007; // u
		const int atomic_number = 7;
		const ld density_STP = 1.251; // kg/m^3
		const ld melting_point = -210.1; // C
		const ld boiling_point = -195.8; // C
		const ld thermal_conductivity = .025; // W/mK
		const ld electric_conductivity = NULL; // MS/m
		const ld resistivity = NULL; //NULL
		const ld heat_specific = 1040; // J/kgK
		const ld heat_vaporization = 2.79; // kJ/mol
		const ld heat_fusion = .36; // kJ/mol
	} N;

	const struct OXYGEN
	{
		const ld atomic_weight = 15.999; // u
		const int atomic_number = 8;
		const ld density_STP = 1.251; // kg/m^3
		const ld melting_point = -218.0; // C
		const ld boiling_point = -183.0; // C
		const ld thermal_conductivity = 0.02658; // W/mK
		const ld electric_conductivity = NULL; // MS/m
		const ld resistivity = NULL; // NULL
		const ld heat_specific = 919; // J/kgK
		const ld heat_vaporization = 3.41; // kJ/mol
		const ld heat_fusion = .222; // kJ/mol
	} O;

	const struct FLUORINE
	{
		const ld atomic_weight = 18.998403163; // u
		const int atomic_number = 9;
		const ld density_STP = 1.696; // kg/m^3
		const ld melting_point = -220.0; // C
		const ld boiling_point = -188.1; // C
		const ld thermal_conductivity = .0277; // W/mK
		const ld electric_conductivity = NULL; // MS/m
		const ld resistivity = NULL; // NULL
		const ld heat_specific = 824; // J/kgK
		const ld heat_vaporization = 3.27; // kJ/mol
		const ld heat_fusion = .26; // kJ/mol
	} F;

	const struct NEON
	{
		const ld atomic_weight = 20.1797; // u
		const int atomic_number = 10;
		const ld density_STP = .900; // kg/m^3
		const ld melting_point = -248.6; // C
		const ld boiling_point = -246.1; // C
		const ld thermal_conductivity = .0491; // W/mK
		const ld electric_conductivity = NULL; // MS/m
		const ld resistivity = NULL; // NULL
		const ld heat_specific = 1030; // J/kgK
		const ld heat_vaporization = 1.75; // kJ/mol
		const ld heat_fusion = 0.34; // kJ/mol
	} Ne;

	const struct SODIUM
	{
		const ld atomic_weight = 22.98976928; // u
		const int atomic_number = 11;
		const ld density_STP = 968; // kg/m^3
		const ld melting_point = 97.720; // C
		const ld boiling_point = 882.9; // C
		const ld thermal_conductivity = 140.0; // W/mK
		const ld electric_conductivity = 21.0; // MS/m
		const ld resistivity = 4.699999999998 * pow(10, -8); // 4.7e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 1230; // J/kgK
		const ld heat_vaporization = 97.7; // kJ/mol
		const ld heat_fusion = 2.60; // kJ/mol
	} Na;

	const struct MAGNESIUM
	{
		const ld atomic_weight = 24.305; // u
		const int atomic_number = 12;
		const ld density_STP = 1738.0; // kg/m^3
		const ld melting_point = 650; // C
		const ld boiling_point = 1090; // C
		const ld thermal_conductivity = 160.0; // W/mK
		const ld electric_conductivity = 23.0; // MS/m
		const ld resistivity = 4.399999999999 * pow(10, -8); // 4.4e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 1020; // J/kgK
		const ld heat_vaporization = 128; // kJ/mol
		const ld heat_fusion = 8.7; // kJ/mol
	} Mg;

	const struct ALUMINIUM
	{
		const ld atomic_weight = 26.9815385; // 26.9815385 u
		const int atomic_number = 13; // 13
		const ld density_STP = 2700; // 2700 kg/m^3
		const ld melting_point = 660.32; // 660.32 C
		const ld boiling_point = 2519.0; // 2519C
		const ld thermal_conductivity = 235; // 235 W/mK
		const ld electric_conductivity = 38.0; // 38 MS/m
		const ld resistivity = 2.6 * pow(10, -8); // 2.6e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 904.0; // 904 J/kgK
		const ld heat_vaporization = 293.0; // 293 kJ/mol
		const ld heat_fusion = 10.7; // 10.7 kJ/mol
	} Al;

	const struct SILICON
	{
		const ld atomic_weight = 28.085; // 28.085 u
		const int atomic_number = 14; //14
		const ld density_STP = 2330.0; // 2330 kg/m^3
		const ld melting_point = 1414.0; // 1414 C
		const ld boiling_point = 2900.0; // 2000 C
		const ld thermal_conductivity = 150.0; // 150 W/mK
		const ld electric_conductivity = .0010; // .0010 MS/m
		const ld resistivity = .001; // .001 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 710.0; // 710 J/kgK
		const ld heat_vaporization = 359.0; // 359 kJ/mol
		const ld heat_fusion = 50.2; // 50.2 kJ/mol
	} Si;

	const struct PHOSPHORUS
	{
		const ld atomic_weight = 30.973761998; // 30.973761998 u
		const int atomic_number = 15; //15
		const ld density_STP = 1823.0; // 1823 kg/m^3
		const ld melting_point = 44.15; // 44.15 C
		const ld boiling_point = 280.5; // 280.5 C
		const ld thermal_conductivity = .236; // .236 W/mK
		const ld electric_conductivity = 10.0; // 10 MS/m
		const ld resistivity = 1 * pow(10, -7); // 1e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 769.7; // 769.7 J/kgK
		const ld heat_vaporization = 12.4; // 12.4 kJ/mol
		const ld heat_fusion = .64; // .64 kJ/mol
	} P;

	const struct SULFUR
	{
		const ld atomic_weight = 32.06; // 32.06 u
		const int atomic_number = 16; // 16
		const ld density_STP = 1960.0; // 1960.0 kg/m^3
		const ld melting_point = 115.21; // 115.21 C
		const ld boiling_point = 444.72; // 444.72 C
		const ld thermal_conductivity = .205; // .205 W/mK
		const ld electric_conductivity = pow(1.0, -21); // 1e-21 MS/m
		const ld resistivity = 1 * pow(10, 15); // 1e15 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 705.0; // 705 J/kgK
		const ld heat_vaporization = 9.8; // 9.8 kJ/mol
		const ld heat_fusion = 1.73; // 1.73 kJ/mol
	} S;

	const struct CHLORINE
	{
		const ld atomic_weight = 35.45; // 35.45 u
		const int atomic_number = 17; //17
		const ld density_STP = 3.214; // 3.214 kg/m^3
		const ld melting_point = -101.5; // -101.5 C
		const ld boiling_point = -34.040; // -34.040 C
		const ld thermal_conductivity = .0089; // .0089 W/mK
		const ld electric_conductivity = pow(1.0, -8.0); // 1e-8 MS/m
		const ld resistivity = 100; // 100 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 478.2; // 478.2 J/kgK
		const ld heat_vaporization = 10.2; // 10.2 kJ/mol
		const ld heat_fusion = 3.2; // 3.2 kJ/mol
	} Cl;

	const struct ARGON
	{
		const ld atomic_weight = 39.948; // 39.948 u
		const int atomic_number = 18; //18
		const ld density_STP = 1784.0; // 1784 kg/m^3
		const ld melting_point = -189; // -189 C
		const ld boiling_point = -186; // -186 C
		const ld thermal_conductivity = .01772; // .01772 W/mK
		const ld electric_conductivity = NULL; // NULL
		const ld resistivity = NULL; // NULL
		const ld heat_specific = 520.33; // 520.33 J/kgK
		const ld heat_vaporization = 6.5; // 6.5 kJ/mol
		const ld heat_fusion = 1.18; // 1.18 kJ/mol
	} Ar;

	const struct POTASSIUM
	{
		const ld atomic_weight = 39.0983; // 39.0983 u
		const int atomic_number = 19; // 19
		const ld density_STP = 856; // 856 kg/m^3
		const ld melting_point = 63.380; // 63.38C
		const ld boiling_point = 758.9; // 758.9C
		const ld thermal_conductivity = 100.0; // 100 W/mK
		const ld electric_conductivity = 14.0; // 14 MS/m
		const ld resistivity = 7.000000000002 * pow(10, -8); // 7.0e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 757; // 757 J/kgK
		const ld heat_vaporization = 76.9; // 76.9 kJ/mol
		const ld heat_fusion = 2.33; // 2.33kJ/mol
	} K;

	const struct CALCIUM
	{
		const ld atomic_weight = 40.078; // 40.078 u
		const int atomic_number = 20; // 20
		const ld density_STP = 1550.0; // 1550kg/m^3
		const ld melting_point = 841.9; // 841.9C
		const ld boiling_point = 1484; // 1484 C
		const ld thermal_conductivity = 200.0; //200 W/mK
		const ld electric_conductivity = 29; // 29 MS/m
		const ld resistivity = 3.399999999999 * pow(10, -8); // 3.4e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 631; // 631 J/kgK
		const ld heat_vaporization = 155.0; // 155 kJ/mol
		const ld heat_fusion = 8.54; // 8.54 kJ/mol
	} Ca;

	const struct SCANDIUM
	{
		const ld atomic_weight = 44.955908; // 44.955908 u
		const int atomic_number = 21; // 21
		const ld density_STP = 2985.0; // 2985 kg/m^3
		const ld melting_point = 1541.0; // 1541 C
		const ld boiling_point = 2830.0; // 2830 C
		const ld thermal_conductivity = 16; // 16W/mK
		const ld electric_conductivity = 1.8; // 1.8 MS/m
		const ld resistivity = 5.5 * pow(10, -7); // 5.5e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 567.0; // 567 J/kgK
		const ld heat_vaporization = 318.0; // 318 kJ/mol
		const ld heat_fusion = 16.0; // 16 kJ/mol
	} Sc;

	const struct TITANIUM
	{
		const ld atomic_weight = 47.867; // 47.867 u
		const int atomic_number = 22; //22
		const ld density_STP = 4507.0; // 4507 kg/m^3
		const ld melting_point = 1668.0; // 1668 C
		const ld boiling_point = 3287.0; // 3287 C
		const ld thermal_conductivity = 22.0; // 22.0 W/mK
		const ld electric_conductivity = 2.5; // 2.5 MS/m
		const ld resistivity = 4 * pow(10, -7); // 4e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 520.0; // 525 J/kgK
		const ld heat_vaporization = 425.0; // 425 kJ/mol
		const ld heat_fusion = 18.7; // 18.7 kJ/mol
	} Ti;

	const struct VANADIUM
	{
		const ld atomic_weight = 50.9415; // 50.9415 u
		const int atomic_number = 19; // 19
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = 1910; // 1910 C
		const ld boiling_point = 3407; // 3407 C
		const ld thermal_conductivity = 31; // 31 W/mK
		const ld electric_conductivity = 5; // MS/m
		const ld resistivity = 2 * pow(10, -7); // 2e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 489; // J/kgK
		const ld heat_vaporization = 453; // kJ/mol
		const ld heat_fusion = 22.8; // kJ/mol
	} V;

	const struct CHROMIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Cr;

	const struct MANGANESE
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Mn;

	const struct IRON
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Fe;

	const struct COBALT
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Co;

	const struct NICKEL
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Ni;

	const struct COPPER
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Cu;

	const struct ZINC
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Zn;

	const struct GALLIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Ga;

	const struct GERMANIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Ge;

	const struct ARSENIC
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} As;

	const struct SELENIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Se;

	const struct BROMINE
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Br;

	const struct KRYPTON
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Kr;

	const struct RUBIDIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Rb;

	const struct STRONTIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Sr;

	const struct YTTRIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Y;

	const struct ZERCONIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Zr;

	const struct NIOBIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Nb;

	const struct MOLYBDENUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Mo;

	const struct TECHNETIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Tc;

	const struct RUTHENIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Ru;

	const struct RHODIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Rh;

	const struct PALLADIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Pd;

	const struct SILVER
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Ag;

	const struct CADMIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Cd;

	const struct INDIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} In;

	const struct TIN
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Sn;

	const struct ANTIMONY
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; //m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Sb;

	const struct TELURIUM
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 52;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} Te;

	const struct IODINE
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} I;

	const struct XENON
	{
		const ld atomic_weight = 0; // u
		const int atomic_number = 19;
		const ld density_STP = 0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	} XE;

}elements;


static int periodicElement_objectCount = 0;


class PeriodicElements
{
private:
	static void countIncrease() { periodicElement_objectCount += 1; }
	static void countDecrease() { periodicElement_objectCount -= 1; }
public:
	PeriodicElements* _elementPtr;

	PeriodicElements()
	{
		_elementPtr = nullptr;
		countIncrease();
	}

	/**
	 * @brief copy constructor
	 */
	PeriodicElements(const PeriodicElements& t)
	{
		_elementPtr = t._elementPtr;
		countIncrease();
	}

	/**
	 * #brief move constructor
	 */
	PeriodicElements(PeriodicElements&& t) noexcept
	{
		_elementPtr = t._elementPtr;
		countIncrease();
	}

	/**
	 * @brief copy assignment operator
	 */
	PeriodicElements& operator=(const PeriodicElements& t)
	{
		if (this != &t)
		{
			_elementPtr = t._elementPtr;
			countIncrease();
		}
		return *this;
	}

	static void show_objectCount()
	{
		std::cout << "\n periodic element object count: " << periodicElement_objectCount << std::endl;
	}

	static int get_objectCount() { return periodicElement_objectCount; }


	~PeriodicElements()
	{
		delete _elementPtr;
	}
};
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
		const ld resistivity = 0; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 0; // J/kgK
		const ld heat_vaporization = 0; // kJ/mol
		const ld heat_fusion = 0; // kJ/mol
	}Tmp;

 */
