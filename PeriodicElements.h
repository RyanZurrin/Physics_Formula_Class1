﻿#pragma once

/**
 * @struct PeriodicElements
 * @details driver class for solving complex physics problems
 * @author Ryan Zurrin
 * @date   1/1/2021
 */
#ifndef PERIODIC_ELEMENTS_H
#define PERIODIC_ELEMENTS_H


static struct UnifiedAtomicMass
{
	const ld kg = 1.66053906660 * 50 * pow(10, -27);
	const ld Mu = 1.0;
	const ld Me = 1822.888486209 * 53;
} u;


/// <summary>
/// The periodic table, also known as the periodic table of elements, is a
/// tabular display of the chemical elements, which are arranged by atomic
/// number, electron configuration, and recurring chemical properties.
/// The structure of the table shows periodic trends.\n\n
///
/// atomic_weight: The atomic mass is the mass of an atom. Although the SI unit
///		of mass is kilogram, the atomic mass is often expressed in the non-SI unit
///		dalton where 1 dalton is defined as 1⁄12 of the mass of a single
///		carbon-12 atom, at rest.\n\n
///
/// atomic_number: The atomic number or proton number (symbol Z) of a chemical
///		element is the number of protons found in the nucleus of every atom of
///		that element. The atomic number uniquely identifies a chemical element.
///		It is identical to the charge number of the nucleus. In an uncharged atom,
///		the atomic number is also equal to the number of electrons.\n\n
///
/// density_STP: Density is a measure of an element's mass per unit volume.\n\n
///
/// melting_point: Melting point, temperature at which the solid and liquid forms
///		of a pure substance can exist in equilibrium. ... As heat is applied to a
///		solid, its temperature will increase until the melting point is reached.
///		More heat then will convert the solid into a liquid with no temperature change.\n\n
///
/// boiling_point: The boiling point of a substance is the temperature at which
///		the vapor pressure of a liquid equals the pressure surrounding the liquid
///		and the liquid changes into a vapor. ... The standard boiling point has
///		been defined by IUPAC since 1982 as the temperature at which boiling
///		occurs under a pressure of one bar.\n\n
///
/// thermal_conductivity: The heat transfer characteristics of a solid material
///		are measured by a property called the thermal conductivity, k (or λ),
///		measured in W/m.K. It is a measure of a substance's ability to transfer
///		heat through a material by conduction.\n\n
///
/// electric_conductivity: in metals is a result of the movement of electrically
///		charged particles. The atoms of metal elements are characterized by the
///		presence of valence electrons, which are electrons in the outer shell of
///		an atom that are free to move about.\n\n
///
/// resistivity: (also called specific electrical resistance or volume resistivity)
///		is a fundamental property of a material that measures how strongly it resists
///		electric current. Its inverse, called electrical conductivity, quantifies
///		how well a material conducts electricity.\n\n
///
/// heat_specific: the quantity of heat required to raise the temperature of one
///		gram of a substance by one Celsius degree. The units of specific heat are
///		usually calories or joules per gram per Celsius degree.\n\n
///
/// heat_vaporization: The enthalpy of vaporization, also known as the heat of
///		vaporization or heat of evaporation, is the amount of energy that must
///		be added to a liquid substance to transform a quantity of that substance
///		into a gas. The enthalpy of vaporization is a function of the pressure at
///		which that transformation takes place.\n\n
///
///  heat_fusion: The enthalpy of fusion of a substance, also known as heat of
///		fusion is the change in its enthalpy resulting from providing energy, typically
///		 heat, to a specific quantity of the substance to change its state from a
///		 solid to a liquid, at constant pressure.\n\n
///
/// ionization_1st: Ionization energy is the minimum amount of energy required
///		to remove the most loosely bound electron of a neutral atom.
///
/// </summary>
static struct Elements
{
	Elements() { //cout << "testing Element" << endl;
		};

	/// <summary>
	///
	/// </summary>
	const struct NEUTRON
	{
		const ld atomic_weight = 1.008665;
		const ld halfLife = 622.2;
		const int atomic_number = 0;
	} n;

	/// <summary>
	/// Hydrogen is the chemical element with the symbol H and atomic number 1.
	/// With a standard atomic weight of 1.008, hydrogen is the lightest element
	/// in the periodic table. Hydrogen is the most abundant chemical substance
	/// in the universe, constituting roughly 75% of all baryonic mass
	/// </summary>
	const struct HYDROGEN
	{
		const ld atomic_weight = 1.007825; // 1.007825 u
		const int atomic_number = 1; // Z = 1
		const ld density_STP = .0899; // .0899 kg/m^3
		const ld melting_point = -259.1; // -259.1 C
		const ld boiling_point = -252.9; // -252.9 C
		const ld thermal_conductivity = .18; // .18 W/mK
		const ld electric_conductivity = NULL; // NULL
		const ld resistivity = NULL; //NULL
		const ld heat_specific = 14300.0; // 14300.0 J/kgK
		const ld heat_vaporization = .452; // 452 kJ/mol
		const ld heat_fusion = .558; // .558 kJ/mol
		const ld ionization_1st = 13.598;
	} H;

	/// <summary>
	///	Helium is a chemical element with the symbol He and atomic number 2.
	///	It is a colorless, odorless, tasteless, non-toxic, inert, monatomic gas,
	///	the first in the noble gas group in the periodic table. Its boiling point
	///	is the lowest among all the elements
	/// </summary>
	const struct HELIUM
	{
		const ld atomic_weight = 4.002602; // 4.002602 u
		const int atomic_number = 2; // Z = 2
		const ld density_STP = 0.1785; // 0.1785 kg/m^3
		const ld melting_point = NULL; // C
		const ld boiling_point = -269; // -269 C
		const ld thermal_conductivity = 0.1513; // 0.1513 W/mK
		const ld electric_conductivity = NULL; // NULL
		const ld resistivity = NULL; // NULL
		const ld heat_specific = 5193.1; // 5193.1 J/kgK
		const ld heat_vaporization = .083; // .083 kJ/mol
		const ld heat_fusion = .02; // .02 kJ/mol
		const ld ionization_1st = 24.587; // eV
	} He;

	/// <summary>
	///	Lithium is a chemical element with the symbol Li and atomic number 3.
	///	It is a soft, silvery-white alkali metal. Under standard conditions,
	///	it is the lightest metal and the lightest solid element.
	/// </summary>
	const struct LITHIUM
	{
		const ld atomic_weight = 6.941; // 6.94 u
		const int atomic_number = 3; // Z = 3
		const ld density_STP = 535.0; // 535.0 kg/m^3
		const ld melting_point = 180.54; // 180.54 C
		const ld boiling_point = 1342.0; // 1342.0 C
		const ld thermal_conductivity = 85.0; // 85.0 W/mK
		const ld electric_conductivity = 11.0; // 11.0 MS/m
		const ld resistivity = 9.40 * pow(10, -8); // 9.4e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 3570.0; // 3570.0 J/kgK
		const ld heat_vaporization = 147.0; // 147.0 kJ/mol
		const ld heat_fusion = 3.0; // 3.0 kJ/mol
		const ld ionization_1st = 5.391; // eV
	} Li;

	/// <summary>
	/// Beryllium is a chemical element with the symbol Be and atomic number 4.
	/// It is a relatively rare element in the universe, usually occurring as a
	/// product of the spallation of larger atomic nuclei that have collided
	/// with cosmic rays. Within the cores of stars, beryllium is depleted as
	/// it is fused into heavier elements.
	/// </summary>
	const struct BERYLLIUM
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
		const ld ionization_1st = 9.323; // eV
	} Be;

	/// <summary>
	/// Boron is a chemical element with the symbol B and atomic number 5.
	/// Produced entirely by cosmic ray spallation and supernovae and not by
	/// stellar nucleosynthesis, it is a low-abundance element in the Solar
	/// System and in the Earth's crust. It constitutes about 0.001 percent
	/// by weight of Earth's crust.
	/// </summary>
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
		const ld ionization_1st = 8.298; // eV
	} B;

	/// <summary>
	/// Carbon is a chemical element with the symbol C and atomic number 6.
	/// It is nonmetallic and tetravalent—making four electrons available to
	/// form covalent chemical bonds. It belongs to group 14 of the periodic
	/// table. Carbon makes up only about 0.025 percent of Earth's crust.
	/// </summary>
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
		const ld ionization_1st = 11.261; // eV
	} C;

	/// <summary>
	/// Nitrogen is the chemical element with the symbol N and atomic number 7.
	/// It was first discovered and isolated by Scottish physician Daniel
	/// Rutherford in 1772.
	/// </summary>
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
		const ld ionization_1st = 14.534; // eV
	} N;

	/// <summary>
	/// Oxygen is the chemical element with the symbol O and atomic number 8.
	/// It is a member of the chalcogen group in the periodic table, a highly
	/// reactive nonmetal, and an oxidizing agent that readily forms oxides with
	/// most elements as well as with other compounds.
	/// </summary>
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
		const ld ionization_1st = 13.681; // eV
	} O;

	/// <summary>
	/// Fluorine is a chemical element with the symbol F and atomic number 9.
	/// It is the lightest halogen and exists at standard conditions as a highly
	/// toxic, pale yellow diatomic gas. As the most electronegative element,
	/// it is extremely reactive, as it reacts with all other elements, except
	/// for argon, neon, and helium.
	/// </summary>
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
		const ld ionization_1st = 17.422; // eV
	} F;

	/// <summary>
	/// Neon is a chemical element with the symbol Ne and atomic number 10.
	/// It is a noble gas. Neon is a colorless, odorless, inert monatomic gas
	/// under standard conditions, with about two-thirds the density of air.
	/// </summary>
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
		const ld ionization_1st = 21.565; // eV
	} Ne;

	/// <summary>
	/// Sodium is a chemical element with the symbol Na and atomic number 11.
	/// It is a soft, silvery-white, highly reactive metal. Sodium is an
	/// alkali metal, being in group 1 of the periodic table. Its only stable
	/// isotope is ²³Na. The free metal does not occur in nature, and must be
	/// prepared from compounds.
	/// </summary>
	const struct SODIUM
	{
		const ld atomic_weight = 22.98976928; // u
		const int atomic_number = 11;
		const ld density_STP = 968; // kg/m^3
		const ld melting_point = 97.720; // C
		const ld boiling_point = 882.9; // C
		const ld thermal_conductivity = 140.0; // W/mK
		const ld electric_conductivity = 21.0; // MS/m
		const ld resistivity = 4.69999999e-8; // 4.7e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 1230; // J/kgK
		const ld heat_vaporization = 97.7; // kJ/mol
		const ld heat_fusion = 2.60; // kJ/mol
		const ld ionization_1st = 5.139; // eV
	} Na;

	/// <summary>
	/// Magnesium is a chemical element with the symbol Mg and atomic number 12.
	/// It is a shiny gray solid which bears a close physical resemblance to
	/// the other five elements in the second column of the periodic
	/// </summary>
	const struct MAGNESIUM
	{
		const ld atomic_weight = 24.305; // u
		const int atomic_number = 12;
		const ld density_STP = 1738.0; // kg/m^3
		const ld melting_point = 650; // C
		const ld boiling_point = 1090; // C
		const ld thermal_conductivity = 160.0; // W/mK
		const ld electric_conductivity = 23.0; // MS/m
		const ld resistivity = 4.39999999e-8; // 4.4e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 1020; // J/kgK
		const ld heat_vaporization = 128; // kJ/mol
		const ld heat_fusion = 8.7; // kJ/mol
		const ld ionization_1st = 7.646; // eV
	} Mg;

	/// <summary>
	/// Aluminium is a chemical element with the symbol Al and atomic number 13.
	/// Aluminium has a density lower than those of other common metals, at
	/// approximately one third that of steel. It has a great affinity towards
	/// oxygen, and forms a protective layer of oxide on the surface when
	/// exposed to air.
	/// </summary>
	const struct ALUMINIUM
	{
		const ld atomic_weight = 26.9815385; // 26.9815385 u
		const int atomic_number = 13; // 13
		const ld density_STP = 2700; // 2700 kg/m^3
		const ld melting_point = 660.32; // 660.32 C
		const ld boiling_point = 2519.0; // 2519C
		const ld thermal_conductivity = 235; // 235 W/mK
		const ld electric_conductivity = 38.0; // 38 MS/m
		const ld resistivity = 2.6e-8; // 2.6e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 904.0; // 904 J/kgK
		const ld heat_vaporization = 293.0; // 293 kJ/mol
		const ld heat_fusion = 10.7; // 10.7 kJ/mol
		const ld ionization_1st = 5.985; // eV
	} Al;

	/// <summary>
	/// Silicon is a chemical element with the symbol Si and atomic number 14.
	/// It is a hard, brittle crystalline solid with a blue-grey metallic lustre,
	/// and is a tetravalent metalloid and semiconductor. It is a member of group
	/// 14 in the periodic table: carbon is above it; and germanium, tin, lead
	/// and flerovium, are below it
	/// </summary>
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
		const ld ionization_1st = 8.151; // eV
	} Si;

	/// <summary>
	/// Phosphorus is a chemical element with the symbol P and atomic number 15.
	/// Elemental phosphorus exists in two major forms, white phosphorus and
	/// red phosphorus, but because it is highly reactive, phosphorus is never
	/// found as a free element on Earth.
	/// </summary>
	const struct PHOSPHORUS
	{
		const ld atomic_weight = 30.973761998; // 30.973761998 u
		const int atomic_number = 15; //15
		const ld density_STP = 1823.0; // 1823 kg/m^3
		const ld melting_point = 44.15; // 44.15 C
		const ld boiling_point = 280.5; // 280.5 C
		const ld thermal_conductivity = .236; // .236 W/mK
		const ld electric_conductivity = 10.0; // 10 MS/m
		const ld resistivity = 1e-7; // 1e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 769.7; // 769.7 J/kgK
		const ld heat_vaporization = 12.4; // 12.4 kJ/mol
		const ld heat_fusion = .64; // .64 kJ/mol
		const ld ionization_1st = 10.487; // eV
	} P;

	/// <summary>
	/// Sulfur is a chemical element with the symbol S and atomic number 16.
	/// It is abundant, multivalent and nonmetallic. Under normal conditions,
	/// sulfur atoms form cyclic octatomic molecules with a chemical formula S₈.
	/// Elemental sulfur is a bright yellow, crystalline solid at room temperature
	/// </summary>
	const struct SULFUR
	{
		const ld atomic_weight = 32.06; // 32.06 u
		const int atomic_number = 16; // 16
		const ld density_STP = 1960.0; // 1960.0 kg/m^3
		const ld melting_point = 115.21; // 115.21 C
		const ld boiling_point = 444.72; // 444.72 C
		const ld thermal_conductivity = .205; // .205 W/mK
		const ld electric_conductivity = pow(1.0, -21); // 1e-21 MS/m
		const ld resistivity = 1e15; // 1e15 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 705.0; // 705 J/kgK
		const ld heat_vaporization = 9.8; // 9.8 kJ/mol
		const ld heat_fusion = 1.73; // 1.73 kJ/mol
		const ld ionization_1st = 10.36; // eV
	} S;

	/// <summary>
	/// Chlorine is a chemical element with the symbol Cl and atomic number 17.
	/// The second-lightest of the halogens, it appears between fluorine and
	/// bromine in the periodic table and its properties are mostly intermediate
	/// between them. Chlorine is a yellow-green gas at room temperature.
	/// </summary>
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
		const ld ionization_1st = 12.968; // eV
	} Cl;

	/// <summary>
	/// Argon is a chemical element with the symbol Ar and atomic number 18.
	/// It is in group 18 of the periodic table and is a noble gas. Argon is
	/// the third-most abundant gas in the Earth's atmosphere, at 0.934%
	/// </summary>
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
		const ld ionization_1st = 15.760; // eV
	} Ar;

	/// <summary>
	/// Potassium is a chemical element with the symbol K and atomic number 19.
	/// Potassium is a silvery-white metal that is soft enough to be cut with a
	/// knife with little force. Potassium metal reacts rapidly with atmospheric
	/// oxygen to form flaky white potassium peroxide in only seconds of exposure.
	/// </summary>
	const struct POTASSIUM
	{
		const ld atomic_weight = 39.0983; // 39.0983 u
		const int atomic_number = 19; // 19
		const ld density_STP = 856; // 856 kg/m^3
		const ld melting_point = 63.380; // 63.38C
		const ld boiling_point = 758.9; // 758.9C
		const ld thermal_conductivity = 100.0; // 100 W/mK
		const ld electric_conductivity = 14.0; // 14 MS/m
		const ld resistivity = 7.000000000002e-8; // 7.0e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 757; // 757 J/kgK
		const ld heat_vaporization = 76.9; // 76.9 kJ/mol
		const ld heat_fusion = 2.33; // 2.33kJ/mol
		const ld ionization_1st = 4.341; // eV
	} K;

	/// <summary>
	/// Calcium is a chemical element with the symbol Ca and atomic number 20.
	/// As an alkaline earth metal, calcium is a reactive metal that forms a
	/// dark oxide-nitride layer when exposed to air. ... It is the fifth most
	/// abundant element in Earth's crust, and the third most abundant metal,
	/// after iron and aluminium
	/// </summary>
	const struct CALCIUM
	{
		const ld atomic_weight = 40.078; // 40.078 u
		const int atomic_number = 20; // 20
		const ld density_STP = 1550.0; // 1550kg/m^3
		const ld melting_point = 841.9; // 841.9C
		const ld boiling_point = 1484; // 1484 C
		const ld thermal_conductivity = 200.0; //200 W/mK
		const ld electric_conductivity = 29; // 29 MS/m
		const ld resistivity = 3.39999999e-8; // 3.4e-8 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 631; // 631 J/kgK
		const ld heat_vaporization = 155.0; // 155 kJ/mol
		const ld heat_fusion = 8.54; // 8.54 kJ/mol
		const ld ionization_1st = 6.113; // eV
	} Ca;

	/// <summary>
	/// Scandium is a chemical element with the symbol Sc and atomic number 21.
	/// A silvery-white metallic d-block element, it has historically been
	/// classified as a rare-earth element, together with yttrium and the
	/// lanthanide.
	/// </summary>
	const struct SCANDIUM
	{
		const ld atomic_weight = 44.955908; // 44.955908 u
		const int atomic_number = 21; // 21
		const ld density_STP = 2985.0; // 2985 kg/m^3
		const ld melting_point = 1541.0; // 1541 C
		const ld boiling_point = 2830.0; // 2830 C
		const ld thermal_conductivity = 16; // 16W/mK
		const ld electric_conductivity = 1.8; // 1.8 MS/m
		const ld resistivity = 5.5e-7; // 5.5e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 567.0; // 567 J/kgK
		const ld heat_vaporization = 318.0; // 318 kJ/mol
		const ld heat_fusion = 16.0; // 16 kJ/mol
		const ld ionization_1st = 6.562; // eV
	} Sc;

	/// <summary>
	/// Titanium is a chemical element with the symbol Ti and atomic number 22.
	/// Its atomic weight is 47.867 measured in daltons. It is a lustrous
	/// transition metal with a silver color, low density, and high strength.
	/// Titanium is resistant to corrosion in sea water, aqua regia, and chlorine.
	/// </summary>
	const struct TITANIUM
	{
		const ld atomic_weight = 47.867; // 47.867 u
		const int atomic_number = 22; //22
		const ld density_STP = 4507.0; // 4507 kg/m^3
		const ld melting_point = 1668.0; // 1668 C
		const ld boiling_point = 3287.0; // 3287 C
		const ld thermal_conductivity = 22.0; // 22.0 W/mK
		const ld electric_conductivity = 2.5; // 2.5 MS/m
		const ld resistivity = 4e-7; // 4e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 520.0; // 525 J/kgK
		const ld heat_vaporization = 425.0; // 425 kJ/mol
		const ld heat_fusion = 18.7; // 18.7 kJ/mol
		const ld ionization_1st = 6.828; // eV
	} Ti;

	/// <summary>
	/// Vanadium is a chemical element with the symbol V and atomic number 23.
	/// It is a hard, silvery-grey, malleable transition metal. The elemental
	/// metal is rarely found in nature, but once isolated artificially, the
	/// formation of an oxide layer somewhat stabilizes the free metal against
	/// further oxidation.
	/// </summary>
	const struct VANADIUM
	{
		const ld atomic_weight = 50.9415; // 50.9415 u
		const int atomic_number = 23; // 19
		const ld density_STP = 6110; // kg/m^3
		const ld melting_point = 1910; // 1910 C
		const ld boiling_point = 3407; // 3407 C
		const ld thermal_conductivity = 31; // 31 W/mK
		const ld electric_conductivity = 5; // MS/m
		const ld resistivity = 2e-7; // 2e-7 m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 489; // J/kgK
		const ld heat_vaporization = 453; // kJ/mol
		const ld heat_fusion = 22.8; // kJ/mol
		const ld ionization_1st = 6.746; // eV
	} V;

	/// <summary>
	/// Chromium is a chemical element with the symbol Cr and atomic number 24.
	/// It is the first element in group 6. It is a steely-grey, lustrous, hard,
	/// and brittle transition metal. Chromium is the main additive in stainless
	/// steel, to which it adds anti-corrosive properties.
	/// </summary>
	const struct CHROMIUM
	{
		const ld atomic_weight = 51.996; // u
		const int atomic_number = 24;
		const ld density_STP = 7190; // kg/m^3
		const ld melting_point = 1907; // C
		const ld boiling_point = 2671; // C
		const ld thermal_conductivity = 94; // W/mK
		const ld electric_conductivity = 7.9; // MS/m
		const ld resistivity = 1.3e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 448; // J/kgK
		const ld heat_vaporization = 339; // kJ/mol
		const ld heat_fusion = 20.5; // kJ/mol
		const ld ionization_1st = 6.767; // eV
	} Cr;

	/// <summary>
	/// Manganese is a chemical element with the symbol Mn and atomic number 25.
	/// It is not found as a free element in nature; it is often found in minerals
	/// in combination with iron. Manganese is a transition metal with a
	/// multifaceted array of industrial alloy uses, particularly in
	/// stainless steels.
	/// </summary>
	const struct MANGANESE
	{
		const ld atomic_weight = 54.938; // u
		const int atomic_number = 25;
		const ld density_STP = 7470; // kg/m^3
		const ld melting_point = 1246; // C
		const ld boiling_point = 2061; // C
		const ld thermal_conductivity = 7.8; // W/mK
		const ld electric_conductivity = .62; // MS/m
		const ld resistivity = 1.6e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 479; // J/kgK
		const ld heat_vaporization = 220; // kJ/mol
		const ld heat_fusion = 13.2; // kJ/mol
		const ld ionization_1st = 7.434; // eV
	} Mn;

	/// <summary>
	/// Iron is a chemical element with symbol Fe and atomic number 26.
	/// It is a metal that belongs to the first transition series and group
	/// 8 of the periodic table. It is, by mass, the most common element on
	/// Earth, right in front of oxygen, forming much of Earth's outer and
	/// inner core.
	/// </summary>
	const struct IRON
	{
		const ld atomic_weight = 55.845; // u
		const int atomic_number = 26;
		const ld density_STP = 7874; // kg/m^3
		const ld melting_point = 1538; // C
		const ld boiling_point = 2861; // C
		const ld thermal_conductivity = 80; // W/mK
		const ld electric_conductivity = 10; // MS/m
		const ld resistivity = 9.7e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 449; // J/kgK
		const ld heat_vaporization = 347; // kJ/mol
		const ld heat_fusion = 13.8; // kJ/mol
		const ld ionization_1st = 7.903; // eV
	} Fe;

	/// <summary>
	/// Cobalt is a chemical element with the symbol Co and atomic number 27.
	/// Like nickel, cobalt is found in the Earth's crust only in a chemically
	/// combined form, save for small deposits found in alloys of natural meteoric
	/// iron. The free element, produced by reductive smelting, is a hard,
	/// lustrous, silver-gray metal.
	/// </summary>
	const struct COBALT
	{
		const ld atomic_weight = 58.933; // u
		const int atomic_number = 27;
		const ld density_STP = 8900; // kg/m^3
		const ld melting_point = 1495; // C
		const ld boiling_point = 2900; // C
		const ld thermal_conductivity = 100; // W/mK
		const ld electric_conductivity = 17; // MS/m
		const ld resistivity = 6e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 421; // J/kgK
		const ld heat_vaporization = 375; // kJ/mol
		const ld heat_fusion = 16.2; // kJ/mol
		const ld ionization_1st = 7.881; // eV
	} Co;

	/// <summary>
	/// Nickel is a chemical element with the symbol Ni and atomic number 28.
	/// It is a silvery-white lustrous metal with a slight golden tinge.
	/// Nickel belongs to the transition metals and is hard and ductile.
	/// </summary>
	const struct NICKEL
	{
		const ld atomic_weight = 58.693; // u
		const int atomic_number = 28;
		const ld density_STP = 8908; // kg/m^3
		const ld melting_point = 1455; // C
		const ld boiling_point = 2913; // C
		const ld thermal_conductivity = 91; // W/mK
		const ld electric_conductivity = 14; // MS/m
		const ld resistivity = 7e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 445; // J/kgK
		const ld heat_vaporization = 378; // kJ/mol
		const ld heat_fusion = 17.2; // kJ/mol
		const ld ionization_1st = 7.641; // eV
	} Ni;

	/// <summary>
	/// Copper is a chemical element with the symbol Cu and atomic number 29.
	/// It is a soft, malleable, and ductile metal with very high thermal and
	/// electrical conductivity. A freshly exposed surface of pure copper has
	/// a pinkish-orange color.
	/// </summary>
	const struct COPPER
	{
		const ld atomic_weight = 63.546; // u
		const int atomic_number = 29;
		const ld density_STP = 8960; // kg/m^3
		const ld melting_point = 1084; // C
		const ld boiling_point = 2562; // C
		const ld thermal_conductivity = 400; // W/mK
		const ld electric_conductivity = 59; // MS/m
		const ld resistivity = 1.7e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 384.4; // J/kgK
		const ld heat_vaporization = 300; // kJ/mol
		const ld heat_fusion = 13.1; // kJ/mol
		const ld ionization_1st = 7.727; // eV
	} Cu;

	/// <summary>
	/// Zinc is a chemical element with the symbol Zn and atomic number 30.
	/// Zinc is a slightly brittle metal at room temperature and has a
	/// silvery-greyish appearance when oxidation is removed. It is the first
	/// element in group 12 of the periodic table.
	/// </summary>
	const struct ZINC
	{
		const ld atomic_weight = 65.38; // u
		const int atomic_number = 30;
		const ld density_STP = 7140; // kg/m^3
		const ld melting_point = 419.53; // C
		const ld boiling_point = 906.9; // C
		const ld thermal_conductivity = 120; // W/mK
		const ld electric_conductivity = 17; // MS/m
		const ld resistivity = 5.9e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 388; // J/kgK
		const ld heat_vaporization = 119; // kJ/mol
		const ld heat_fusion = 7.35; // kJ/mol
		const ld ionization_1st = 9.394; // eV
	} Zn;

	/// <summary>
	/// Gallium is a chemical element with the symbol Ga and atomic number 31.
	/// Elemental gallium is a soft, silvery metal at standard temperature and
	/// pressure; however in its liquid state it becomes silvery white. If too
	/// much force is applied, the gallium may fracture conchoidally.
	/// </summary>
	const struct GALLIUM
	{
		const ld atomic_weight = 69.723; // u
		const int atomic_number = 31;
		const ld density_STP = 5904.0; // kg/m^3
		const ld melting_point = 29.760; // C
		const ld boiling_point = 2204.0; // C
		const ld thermal_conductivity = 29.0; // W/mK
		const ld electric_conductivity = 7.1; // MS/m
		const ld resistivity = 1.4e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 371.0; // J/kgK
		const ld heat_vaporization = 256.0; // kJ/mol
		const ld heat_fusion = 5.59; // kJ/mol
		const ld ionization_1st = 5.999; // eV
	} Ga;

	/// <summary>
	/// Germanium is a chemical element with the symbol Ge and atomic number 32.
	/// It is a lustrous, hard-brittle, grayish-white metalloid in the carbon
	/// group, chemically similar to its group neighbors silicon and tin.
	/// Pure germanium is a semiconductor with an appearance similar to
	/// elemental silicon.
	/// </summary>
	const struct GERMANIUM
	{
		const ld atomic_weight = 72.630; // u
		const int atomic_number = 32;
		const ld density_STP = 5323; // kg/m^3
		const ld melting_point = 938.25; // C
		const ld boiling_point = 2820; // C
		const ld thermal_conductivity = 60.0; // W/mK
		const ld electric_conductivity = .0020; // MS/m
		const ld resistivity = .0005; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 321.4; // J/kgK
		const ld heat_vaporization = 334.0; // kJ/mol
		const ld heat_fusion = 31.8; // kJ/mol
		const ld ionization_1st = 7.90; // eV
	} Ge;

	/// <summary>
	/// Arsenic is a chemical element with the symbol As and atomic number 33.
	/// Arsenic occurs in many minerals, usually in combination with sulfur and
	/// metals, but also as a pure elemental crystal. Arsenic is a metalloid.
	/// </summary>
	const struct ARSENIC
	{
		const ld atomic_weight = 74.922; // u
		const int atomic_number = 33;
		const ld density_STP = 5727; // kg/m^3
		const ld melting_point = 816.9; // C
		const ld boiling_point = 614; // C
		const ld thermal_conductivity = 50.0; // W/mK
		const ld electric_conductivity = 3.3; // MS/m
		const ld resistivity = 3e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 328.0; // J/kgK
		const ld heat_vaporization = 32.4; // kJ/mol
		const ld heat_fusion = 27.7; // kJ/mol
		const ld ionization_1st = 9.815; // eV
	} As;

	/// <summary>
	/// Selenium is a chemical element with the symbol Se and atomic number 34.
	/// It is a nonmetal with properties that are intermediate between the
	/// elements above and below in the periodic table, sulfur and tellurium,
	/// and also has similarities to arsenic
	/// </summary>
	const struct SELENIUM
	{
		const ld atomic_weight = 78.971; // u
		const int atomic_number = 34;
		const ld density_STP = 4819; // kg/m^3
		const ld melting_point = 221; // C
		const ld boiling_point = 685; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = NULL; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 321.2; // J/kgK
		const ld heat_vaporization = 26.0; // kJ/mol
		const ld heat_fusion = 5.4; // kJ/mol
		const ld ionization_1st = 9.753; // eV
	} Se;

	/// <summary>
	/// Bromine is a chemical element with the symbol Br and atomic number 35.
	/// It is the third-lightest halogen, and is a fuming red-brown liquid at
	/// room temperature that evaporates readily to form a similarly coloured
	/// vapour. Its properties are intermediate between those of chlorine
	/// and iodine.
	/// </summary>
	const struct BROMINE
	{
		const ld atomic_weight = 79.904; // u
		const int atomic_number = 35;
		const ld density_STP = 3120; // kg/m^3
		const ld melting_point = -7.350; // C
		const ld boiling_point = 58.9; // C
		const ld thermal_conductivity = 0.12; // W/mK
		const ld electric_conductivity = 1.0e-16; // MS/m
		const ld resistivity = 1.0e10; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 947.3; // J/kgK
		const ld heat_vaporization = 14.8; // kJ/mol
		const ld heat_fusion = 5.8; // kJ/mol
		const ld ionization_1st = 11.814; // eV
	} Br;

	/// <summary>
	/// Krypton is a chemical element with the symbol Kr and atomic number 36.
	/// It is a colorless, odorless, tasteless noble gas that occurs in trace
	/// amounts in the atmosphere and is often used with other rare gases in
	/// fluorescent lamps. With rare exceptions, krypton is chemically inert
	/// </summary>
	const struct KRYPTON
	{
		const ld atomic_weight = 83.798; // u
		const int atomic_number = 36;
		const ld density_STP = 3.75; // kg/m^3
		const ld melting_point = -157.36; // C
		const ld boiling_point = -153.22; // C
		const ld thermal_conductivity = 0.00943; // W/mK
		const ld electric_conductivity = NULL; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 248.05; // J/kgK
		const ld heat_vaporization = 9.02; // kJ/mol
		const ld heat_fusion = 1.64; // kJ/mol
		const ld ionization_1st = 14.000; // eV
	} Kr;

	/// <summary>
	/// Rubidium is the chemical element with the symbol Rb and atomic number 37.
	/// Rubidium is a very soft, silvery-white metal in the alkali metal group.
	/// Rubidium metal shares similarities to potassium metal and caesium metal
	/// in physical appearance, softness and conductivity.
	/// </summary>
	const struct RUBIDIUM
	{
		const ld atomic_weight = 85.468; // u
		const int atomic_number = 37;
		const ld density_STP = 1532; // kg/m^3
		const ld melting_point = 39.310; // C
		const ld boiling_point = 688.0; // C
		const ld thermal_conductivity = 58.0; // W/mK
		const ld electric_conductivity = 8.30; // MS/m
		const ld resistivity = 1.2e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 364; // J/kgK
		const ld heat_vaporization = 72.0; // kJ/mol
		const ld heat_fusion = 2.19; // kJ/mol
		const ld ionization_1st = 4.177; // eV
	} Rb;

	/// <summary>
	/// Strontium is the chemical element with the symbol Sr and atomic number 38.
	/// An alkaline earth metal, strontium is a soft silver-white yellowish metallic
	/// element that is highly chemically reactive. The metal forms a dark oxide
	/// layer when it is exposed to air.
	/// </summary>
	const struct STRONTIUM
	{
		const ld atomic_weight = 87.62; // u
		const int atomic_number = 38;
		const ld density_STP = 2630; // kg/m^3
		const ld melting_point = 776.9; // C
		const ld boiling_point = 1382.0; // C
		const ld thermal_conductivity = 35; // W/mK
		const ld electric_conductivity = 7.7; // MS/m
		const ld resistivity = 1.3e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 300.0; // J/kgK
		const ld heat_vaporization = 137.0; // kJ/mol
		const ld heat_fusion = 8.0; // kJ/mol
		const ld ionization_1st = 5.695; // eV
	} Sr;

	/// <summary>
	/// Yttrium is a chemical element with the symbol Y and atomic number 39.
	/// It is a silvery-metallic transition metal chemically similar to the
	/// lanthanides and has often been classified as a "rare-earth element"
	/// </summary>
	const struct YTTRIUM
	{
		const ld atomic_weight = 88.906; // u
		const int atomic_number = 39;
		const ld density_STP = 4472; // kg/m^3
		const ld melting_point = 1526.0; // C
		const ld boiling_point = 3345.0; // C
		const ld thermal_conductivity = 17; // W/mK
		const ld electric_conductivity = 1.80; // MS/m
		const ld resistivity = 5.6e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 298.0; // J/kgK
		const ld heat_vaporization = 380.0; // kJ/mol
		const ld heat_fusion = 11.4; // kJ/mol
		const ld ionization_1st = 6.22; // eV
	} Y;

	/// <summary>
	/// Zirconium is a chemical element with the symbol Zr and atomic number 40.
	/// The name zirconium is taken from the name of the mineral zircon, the
	/// most important source of zirconium. It is a lustrous, grey-white, strong
	/// transition metal that closely resembles hafnium and, to a lesser
	/// extent, titanium.
	/// </summary>
	const struct ZIRCONIUM
	{
		const ld atomic_weight = 91.224; // u
		const int atomic_number = 40;
		const ld density_STP = 6511; // kg/m^3
		const ld melting_point = 1855.0; // C
		const ld boiling_point = 4409.0; // C
		const ld thermal_conductivity = 23; // W/mK
		const ld electric_conductivity = 2.4; // MS/m
		const ld resistivity = 4.2e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 278.0; // J/kgK
		const ld heat_vaporization = 580.0; // kJ/mol
		const ld heat_fusion = 21.0; // kJ/mol
		const ld ionization_1st = 6.634; // eV
	} Zr;

	/// <summary>
	/// Niobium, also known as columbium,
	/// is a chemical element with the symbol Nb and atomic number 41.
	/// Niobium is a light grey, crystalline, and ductile transition metal.
	/// Pure niobium has a Mohs hardness rating similar to that of pure titanium,
	/// and it has similar ductility to iron.
	/// </summary>
	const struct NIOBIUM
	{
		const ld atomic_weight = 92.906; // u
		const int atomic_number = 41;
		const ld density_STP = 8570; // kg/m^3
		const ld melting_point = 2477.0; // C
		const ld boiling_point = 4744.0; // C
		const ld thermal_conductivity = 54; // W/mK
		const ld electric_conductivity = 6.7; // MS/m
		const ld resistivity = 1.5e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 265.0; // J/kgK
		const ld heat_vaporization = 690.0; // kJ/mol
		const ld heat_fusion = 26.8; // kJ/mol
		const ld ionization_1st = 6.759; // eV
	} Nb;

	/// <summary>
	/// Molybdenum is a chemical element with the symbol Mo and atomic number 42.
	/// The name is from Neo-Latin molybdaenum, which is based on Ancient Greek
	/// Μόλυβδος molybdos, meaning lead, since its ores were confused with lead ores.
	/// </summary>
	const struct MOLYBDENUM
	{
		const ld atomic_weight = 95.95; // u
		const int atomic_number = 42;
		const ld density_STP = 10280; // kg/m^3
		const ld melting_point = 2623.0; // C
		const ld boiling_point = 4639.0; // C
		const ld thermal_conductivity = 139.0; // W/mK
		const ld electric_conductivity = 20.0; // MS/m
		const ld resistivity = 5.0e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 251.0; // J/kgK
		const ld heat_vaporization = 600.0; // kJ/mol
		const ld heat_fusion = 36.0; // kJ/mol
		const ld ionization_1st = 7.092; // eV
	} Mo;

	/// <summary>
	/// Technetium is a chemical element with the symbol Tc and atomic number 43.
	/// It is the lightest element whose isotopes are all radioactive, none of
	/// which is stable other than the fully ionized state of ⁹⁷Tc. Nearly all
	/// available technetium is produced as a synthetic element.
	/// </summary>
	const struct TECHNETIUM
	{
		const ld atomic_weight = (98); // u
		const int atomic_number = 43;
		const ld density_STP = 11500; // kg/m^3
		const ld melting_point = 2157.0; // C
		const ld boiling_point = 4265.0; // C
		const ld thermal_conductivity = 51.0; // W/mK
		const ld electric_conductivity = 5.0; // MS/m
		const ld resistivity = 2.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 63.0; // J/kgK
		const ld heat_vaporization = 550.0; // kJ/mol
		const ld heat_fusion = 23.0; // kJ/mol
		const ld ionization_1st = 7.28; // eV
	} Tc;

	/// <summary>
	/// Ruthenium is a chemical element with the symbol Ru and atomic number 44.
	/// It is a rare transition metal belonging to the platinum group of the
	/// periodic table. Like the other metals of the platinum group, ruthenium
	/// is inert to most other chemicals.
	/// </summary>
	const struct RUTHENIUM
	{
		const ld atomic_weight = 101.07; // u
		const int atomic_number = 44;
		const ld density_STP = 12370; // kg/m^3
		const ld melting_point = 2334.0; // C
		const ld boiling_point = 4150.0; // C
		const ld thermal_conductivity = 120.0; // W/mK
		const ld electric_conductivity = 14.0; // MS/m
		const ld resistivity = 7.1e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 238.0; // J/kgK
		const ld heat_vaporization = 580.0; // kJ/mol
		const ld heat_fusion = 25.7; // kJ/mol
		const ld ionization_1st = 7.361; // eV
	} Ru;

	/// <summary>
	/// Rhodium is a chemical element with the symbol Rh and atomic number 45.
	/// It is an extraordinarily rare, silvery-white, hard, corrosion-resistant,
	/// and chemically inert transition metal. It is a noble metal and a member
	/// of the platinum group. It has only one naturally occurring isotope, ¹⁰³Rh
	/// </summary>
	const struct RHODIUM
	{
		const ld atomic_weight = 102.91; // u
		const int atomic_number = 45;
		const ld density_STP = 12450; // kg/m^3
		const ld melting_point = 1964.0; // C
		const ld boiling_point = 3695.0; // C
		const ld thermal_conductivity = 150.0; // W/mK
		const ld electric_conductivity = 23.0; // MS/m
		const ld resistivity = 4.3e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 240.0; // J/kgK
		const ld heat_vaporization = 495.0; // kJ/mol
		const ld heat_fusion = 21.7; // kJ/mol
		const ld ionization_1st = 7.459; // eV
	} Rh;

	/// <summary>
	/// Palladium is a chemical element with the symbol Pd and atomic number 46.
	/// It is a rare and lustrous silvery-white metal discovered in 1803 by the
	/// English chemist William Hyde Wollaston.
	/// </summary>
	const struct PALLADIUM
	{
		const ld atomic_weight = 106.42; // u
		const int atomic_number = 46;
		const ld density_STP = 12023; // kg/m^3
		const ld melting_point = 1554.90; // C
		const ld boiling_point = 2963.0; // C
		const ld thermal_conductivity = 72.0; // W/mK
		const ld electric_conductivity = 10.0; // MS/m
		const ld resistivity = 1.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 240.0; // J/kgK
		const ld heat_vaporization = 380.0; // kJ/mol
		const ld heat_fusion = 16.7; // kJ/mol
		const ld ionization_1st = 8.337; // eV
	} Pd;

	/// <summary>
	/// Silver is a chemical element with the symbol Ag and atomic number 47.
	/// A soft, white, lustrous transition metal, it exhibits the highest
	/// electrical conductivity, thermal conductivity, and reflectivity of
	/// any metal.
	/// </summary>
	const struct SILVER
	{
		const ld atomic_weight = 107.87; // u
		const int atomic_number = 47;
		const ld density_STP = 10490; // kg/m^3
		const ld melting_point = 961.780; // C
		const ld boiling_point = 2162.0; // C
		const ld thermal_conductivity = 430.0; // W/mK
		const ld electric_conductivity = 62.0; // MS/m
		const ld resistivity = 1.6e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 235.0; // J/kgK
		const ld heat_vaporization = 255.0; // kJ/mol
		const ld heat_fusion = 11.3; // kJ/mol
		const ld ionization_1st = 7.576; // eV
	} Ag;

	/// <summary>
	/// Cadmium is a chemical element with the symbol Cd and atomic number 48.
	/// This soft, silvery-white metal is chemically similar to the two other
	/// stable metals in group 12, zinc and mercury.
	/// </summary>
	const struct CADMIUM
	{
		const ld atomic_weight = 112.41; // u
		const int atomic_number = 48;
		const ld density_STP = 8650; // kg/m^3
		const ld melting_point = 321.07; // C
		const ld boiling_point = 766.9; // C
		const ld thermal_conductivity = 97.0; // W/mK
		const ld electric_conductivity = 14.0; // MS/m
		const ld resistivity = 7.0e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 230.0; // J/kgK
		const ld heat_vaporization = 100.0; // kJ/mol
		const ld heat_fusion = 6.3; // kJ/mol
		const ld ionization_1st = 8.994; // eV
	} Cd;

	/// <summary>
	/// Indium is a chemical element with the symbol In and atomic number 49.
	/// Indium is the softest metal that is not an alkali metal. It is a
	/// silvery-white metal that resembles tin in appearance. It is a
	/// post-transition metal that makes up 0.21 parts per million of the
	/// Earth's crust
	/// </summary>
	const struct INDIUM
	{
		const ld atomic_weight = 114.82; // u
		const int atomic_number = 49;
		const ld density_STP = 7310; // kg/m^3
		const ld melting_point = 156.60; // C
		const ld boiling_point = 2072.0; // C
		const ld thermal_conductivity = 82.0; // W/mK
		const ld electric_conductivity = 12.0; // MS/m
		const ld resistivity = 8.0e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 233.0; // J/kgK
		const ld heat_vaporization = 230.0; // kJ/mol
		const ld heat_fusion = 3.26; // kJ/mol
		const ld ionization_1st = 5.786; // eV
	} In;

	/// <summary>
	/// Tin is a chemical element with the symbol Sn and atomic number 50.
	/// Tin is a silvery metal that characteristically has a faint yellow hue.
	/// Tin, like indium, is soft enough to be cut without much force.
	/// </summary>
	const struct TIN
	{
		const ld atomic_weight = 118.71; // u
		const int atomic_number = 50;
		const ld density_STP = 7310; // kg/m^3
		const ld melting_point = 231.93; // C
		const ld boiling_point = 2602.0; // C
		const ld thermal_conductivity = 67.0; // W/mK
		const ld electric_conductivity = 9.1; // MS/m
		const ld resistivity = 1.1e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 217.0; // J/kgK
		const ld heat_vaporization = 290.0; // kJ/mol
		const ld heat_fusion = 7.0; // kJ/mol
		const ld ionization_1st = 7.344; // eV
	} Sn;

	const struct ANTIMONY
	{
		const ld atomic_weight = 121.76; // u
		const int atomic_number = 51;
		const ld density_STP = 6697; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 4.0e-7; //m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 207.0; // J/kgK
		const ld heat_vaporization = 68.0; // kJ/mol
		const ld heat_fusion = 19.7; // kJ/mol
		const ld ionization_1st = 8.64; // eV
	} Sb;

	const struct TELURIUM
	{
		const ld atomic_weight = 127.60; // u
		const int atomic_number = 52;
		const ld density_STP = 62420; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = .0001; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 201.0; // J/kgK
		const ld heat_vaporization = 48.0; // kJ/mol
		const ld heat_fusion = 17.5; // kJ/mol
		const ld ionization_1st = 9.010; // eV
	} Te;

	const struct IODINE
	{
		const ld atomic_weight = 126.90; // u
		const int atomic_number = 53;
		const ld density_STP = 4940; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 1.0e7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 429.0; // J/kgK
		const ld heat_vaporization = 20.9; // kJ/mol
		const ld heat_fusion = 7.76; // kJ/mol
		const ld ionization_1st = 10.451; // eV
	} I;

	const struct XENON
	{
		const ld atomic_weight = 131.29; // u
		const int atomic_number = 54;
		const ld density_STP = 5.9; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 158.32; // J/kgK
		const ld heat_vaporization = 12.64; // kJ/mol
		const ld heat_fusion = 2.30; // kJ/mol
		const ld ionization_1st = 12.130; // eV
	} XE;

	const struct CAESIUM
	{
		const ld atomic_weight = 132.91; // u
		const int atomic_number = 55;
		const ld density_STP = 1879; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 2.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 242.0; // J/kgK
		const ld heat_vaporization = 65.0; // kJ/mol
		const ld heat_fusion = 2.09; // kJ/mol
		const ld ionization_1st = 3.894; // eV
	} Cs;

	const struct BARIUM
	{
		const ld atomic_weight = 137.33; // u
		const int atomic_number = 56;
		const ld density_STP = 3510; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 3.5e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 205.0; // J/kgK
		const ld heat_vaporization = 140.0; // kJ/mol
		const ld heat_fusion = 8.0; // kJ/mol
		const ld ionization_1st = 5.212; // eV
	} Ba;


const struct LANTHANUM
	{
		const ld atomic_weight = 138.91; // u
		const int atomic_number = 57;
		const ld density_STP = 6146; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 6.1e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 195.0; // J/kgK
		const ld heat_vaporization = 400.0; // kJ/mol
		const ld heat_fusion = 6.2; // kJ/mol
		const ld ionization_1st = 5.577; // eV
	} La;

	const struct CERIUM
	{
		const ld atomic_weight = 140.12; // u
		const int atomic_number = 58;
		const ld density_STP = 6689; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 7.4e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 192.0; // J/kgK
		const ld heat_vaporization = 350.0; // kJ/mol
		const ld heat_fusion = 5.5; // kJ/mol
		const ld ionization_1st = 5.539; // eV
	} Ce;

	const struct PRASEODYMIUM
	{
		const ld atomic_weight = 140.91; // u
		const int atomic_number = 59;
		const ld density_STP = 6640; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 7.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 193.0; // J/kgK
		const ld heat_vaporization = 330.0; // kJ/mol
		const ld heat_fusion = 6.9; // kJ/mol
		const ld ionization_1st = 5.46; // eV
	}Pr;

	const struct NEODYMIUM
	{
		const ld atomic_weight = 144.24; // u
		const int atomic_number = 60;
		const ld density_STP = 7010; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 6.4e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 190.0; // J/kgK
		const ld heat_vaporization = 285.0; // kJ/mol
		const ld heat_fusion = 7.1; // kJ/mol
		const ld ionization_1st = 5.525; // eV
	} Nd;

	const struct PROMETHIUM
	{
		const ld atomic_weight = (145); // u
		const int atomic_number = 61;
		const ld density_STP = 7264; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 7.5e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = 290.0; // kJ/mol
		const ld heat_fusion = 7.7; // kJ/mol
		const ld ionization_1st = 5.6; // eV
	} Pm;

	const struct SAMARIUM
	{
		const ld atomic_weight = 150.36; // u
		const int atomic_number = 62;
		const ld density_STP = 7353; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 9.4e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 196.0; // J/kgK
		const ld heat_vaporization = 175.0; // kJ/mol
		const ld heat_fusion = 8.6; // kJ/mol
		const ld ionization_1st = 5.643; // eV
	} Sm;

	const struct EUROPIUM
	{
		const ld atomic_weight = 151.96; // u
		const int atomic_number = 63;
		const ld density_STP = 5244; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 9.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 182.0; // J/kgK
		const ld heat_vaporization = 175.0; // kJ/mol
		const ld heat_fusion = 9.2; // kJ/mol
		const ld ionization_1st = 5.670; // eV
	} Eu;

	const struct GADOLINIUM
	{
		const ld atomic_weight = 157.25; // u
		const int atomic_number = 64;
		const ld density_STP = 7901; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 1.3e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 240.0; // J/kgK
		const ld heat_vaporization = 305.0; // kJ/mol
		const ld heat_fusion = 10.0; // kJ/mol
		const ld ionization_1st = 6.150; // eV
	} Gd;

	const struct TERBIUM
	{
		const ld atomic_weight = 158.93; // u
		const int atomic_number = 65;
		const ld density_STP = 8219; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 1.2e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 182.0; // J/kgK
		const ld heat_vaporization = 295.0; // kJ/mol
		const ld heat_fusion = 10.8; // kJ/mol
		const ld ionization_1st = 5.864; // eV
	} Tb;

	const struct DYSPROSIUM
	{
		const ld atomic_weight = 162.50; // u
		const int atomic_number = 66;
		const ld density_STP = 8551; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 9.1e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 167.0; // J/kgK
		const ld heat_vaporization = 280.0; // kJ/mol
		const ld heat_fusion = 11.1; // kJ/mol
		const ld ionization_1st = 5.934; // eV
	} Dy;

	const struct HOLMIUM
	{
		const ld atomic_weight = 164.93; // u
		const int atomic_number = 67;
		const ld density_STP = 8795; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 9.4e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 165.0; // J/kgK
		const ld heat_vaporization = 265.0; // kJ/mol
		const ld heat_fusion = 17.0; // kJ/mol
		const ld ionization_1st = 6.022; // eV
	} Ho;

	const struct ERBIUM
	{
		const ld atomic_weight = 167.26; // u
		const int atomic_number = 68;
		const ld density_STP = 9066; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 8.6e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 168.0; // J/kgK
		const ld heat_vaporization = 285.0; // kJ/mol
		const ld heat_fusion = 19.9; // kJ/mol
		const ld ionization_1st = 6.108; // eV
	} Er;

	const struct THULIUM
	{
		const ld atomic_weight = 168.93; // u
		const int atomic_number = 69;
		const ld density_STP = 9320; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 7.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 160.0; // J/kgK
		const ld heat_vaporization = 250.0; // kJ/mol
		const ld heat_fusion = 16.8; // kJ/mol
		const ld ionization_1st = 6.184; // eV
	} Tm;

	const struct YTTERBIUM
	{
		const ld atomic_weight = 173.05; // u
		const int atomic_number = 70;
		const ld density_STP = 6570; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 2.8e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 154.0; // J/kgK
		const ld heat_vaporization = 160.0; // kJ/mol
		const ld heat_fusion = 7.7; // kJ/mol
		const ld ionization_1st = 6.254; // eV
	} Yb;

	const struct LUTERTIUM
	{
		const ld atomic_weight = 174.97; // u
		const int atomic_number = 71;
		const ld density_STP = 9841; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 5.6e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 154.0; // J/kgK
		const ld heat_vaporization = 415.0; // kJ/mol
		const ld heat_fusion = 22.0; // kJ/mol
		const ld ionization_1st = 5.426; // eV
	} Lu;


	const struct HAFNIUM
	{
		const ld atomic_weight = 178.49; // u
		const int atomic_number = 72;
		const ld density_STP = 13310; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 3.0e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 144.0; // J/kgK
		const ld heat_vaporization = 630.0; // kJ/mol
		const ld heat_fusion = 25.5; // kJ/mol
		const ld ionization_1st = 6.825; // eV
	} Hf;


	const struct TANTALUM
	{
		const ld atomic_weight = 180.95; // u
		const int atomic_number = 73;
		const ld density_STP = 16650; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 1.3e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 140.0; // J/kgK
		const ld heat_vaporization = 735.0; // kJ/mol
		const ld heat_fusion = 36.0; // kJ/mol
		const ld ionization_1st = 7.89; // eV
	} Ta;
	const struct TUNGSTEN
	{
		const ld atomic_weight = 183.84; // u
		const int atomic_number = 74;
		const ld density_STP = 19250; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 5.0e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 132.0; // J/kgK
		const ld heat_vaporization = 800.0; // kJ/mol
		const ld heat_fusion = 35.0; // kJ/mol
		const ld ionization_1st = 7.98; // eV
	} W;

	const struct RHENIUM
	{
		const ld atomic_weight = 186.21; // u
		const int atomic_number = 75;
		const ld density_STP = 21020; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 1.8e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 137.0; // J/kgK
		const ld heat_vaporization = 705.0; // kJ/mol
		const ld heat_fusion = 33.0; // kJ/mol
		const ld ionization_1st = 7.88; // eV
	} Re;

	const struct OSMIUM
	{
		const ld atomic_weight = 190.23; // u
		const int atomic_number = 76;
		const ld density_STP = 22590; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 8.1e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 130.0; // J/kgK
		const ld heat_vaporization = 630.0; // kJ/mol
		const ld heat_fusion = 31.0; // kJ/mol
		const ld ionization_1st = 8.71; // eV
	} Os;

	const struct IRIDIUM
	{
		const ld atomic_weight = 192.22; // u
		const int atomic_number = 77;
		const ld density_STP = 22560; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 4.7e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 131.0; // J/kgK
		const ld heat_vaporization = 560.0; // kJ/mol
		const ld heat_fusion = 26.0; // kJ/mol
		const ld ionization_1st = 9.12; // eV
	} Ir;

	const struct PLATINUM
	{
		const ld atomic_weight = 195.08; // u
		const int atomic_number = 78;//Z
		const ld density_STP = 21450; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 1.1e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 133.0; // J/kgK
		const ld heat_vaporization = 490.0; // kJ/mol
		const ld heat_fusion = 20.0; // kJ/mol
		const ld ionization_1st = 9.02; // eV
	} Pt;

	const struct GOLD
	{
		const ld atomic_weight = 196.97; // u
		const int atomic_number = 79;
		const ld density_STP = 19300; // kg/m^3
		const ld melting_point = 1064.18; // C
		const ld boiling_point = 2856; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 2.2e-8; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 129.1; // J/kgK
		const ld heat_vaporization = 330.0; // kJ/mol
		const ld heat_fusion = 12.5; // kJ/mol
		const ld ionization_1st = 9.225; // eV
	} Au;

	const struct MERCURY
	{
		const ld atomic_weight = 200.59; // u
		const int atomic_number = 80;
		const ld density_STP = 13534; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 9.6e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 139.5; // J/kgK
		const ld heat_vaporization = 59.2; // kJ/mol
		const ld heat_fusion = 2.29; // kJ/mol
		const ld ionization_1st = 10.438; // eV
	} Hg;

	const struct THALLIUM
	{
		const ld atomic_weight = 204.38; // u
		const int atomic_number = 81;
		const ld density_STP = 11850; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 1.5e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 129.0; // J/kg
		const ld heat_vaporization = 165.0; // kJ/mol
		const ld heat_fusion = 4.2; // kJ/mol
		const ld ionization_1st = 6.109; // eV
	} Tl;

	const struct LEAD
	{
		const ld atomic_weight = 207.2; // u
		const int atomic_number = 82;
		const ld density_STP = 11340; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 2.1e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 127.0; // J/kgK
		const ld heat_vaporization = 178.0; // kJ/mol
		const ld heat_fusion = 4.77; // kJ/mol
		const ld ionization_1st = 7.417; // eV
	} Pb;

	const struct BISMUTH
	{
		const ld atomic_weight = 208.98; // u
		const int atomic_number = 83;
		const ld density_STP = 9780; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 1.3e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 122.0; // J/kgK
		const ld heat_vaporization = 160.0; // kJ/mol
		const ld heat_fusion = 10.9; // kJ/mol
		const ld ionization_1st = 7.29; // eV
	} Bi;

	const struct POLONIUM
	{
		const ld atomic_weight = (209); // u
		const int atomic_number = 84;
		const ld density_STP = 9196.0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 4.3e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = 100.0; // kJ/mol
		const ld heat_fusion = 13.0; // kJ/mol
		const ld ionization_1st = 8.417; // eV
	} Po;

	const struct ASTATINE
	{
		const ld atomic_weight = (210); // u
		const int atomic_number = 85;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = 40.0; // kJ/mol
		const ld heat_fusion = 6.0; // kJ/mol
		const ld ionization_1st = 9.22; // eV
	} At;

	const struct RADON
	{
		const ld atomic_weight = (222); // u
		const int atomic_number = 86;
		const ld density_STP = 9.73; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 93.65; // J/kgK
		const ld heat_vaporization = 17.0; // kJ/mol
		const ld heat_fusion = 3.0; // kJ/mol
		const ld ionization_1st = 10.75; // eV
	} Rn;

	const struct FRANCIUM
	{
		const ld atomic_weight = (223); // u
		const int atomic_number = 87;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = 65.0; // kJ/mol
		const ld heat_fusion = 2.0; // kJ/mol
		const ld ionization_1st = 3.94; // eV
	} Fr;

	const struct RADIUM
	{
		const ld atomic_weight = (226); // u
		const int atomic_number = 88;
		const ld density_STP = 5000.0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 1.0e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 92.0; // J/kgK
		const ld heat_vaporization = 125.0; // kJ/mol
		const ld heat_fusion = 8.0; // kJ/mol
		const ld ionization_1st = 5.279; // eV
	} Ra;


	const struct ACTINIUM
	{
		const ld atomic_weight = (227); // u
		const int atomic_number = 89;
		const ld density_STP = 10070.0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 120.0; // J/kgK
		const ld heat_vaporization = 400.0; // kJ/mol
		const ld heat_fusion = 14.0; // kJ/mol
		const ld ionization_1st = 5.17; // eV
	} Ac;

	const struct THORIUM
	{
		const ld atomic_weight = 232.04; // u
		const int atomic_number = 90;
		const ld density_STP = 11724.0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 1.5e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 118.0; // J/kgK
		const ld heat_vaporization = 530.0; // kJ/mol
		const ld heat_fusion = 16.0; // kJ/mol
		const ld ionization_1st = 6.08; // eV
	} Th;

	const struct PROTACTINIUM
	{
		const ld atomic_weight = 231.04; // u
		const int atomic_number = 91;
		const ld density_STP = 15370.0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 1.8e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 99.1; // J/kgK
		const ld heat_vaporization = 470.0; // kJ/mol
		const ld heat_fusion = 15.0; // kJ/mol
		const ld ionization_1st = 5.89; // eV
	} Pa;

	const struct URANIUM
	{
		const ld atomic_weight = 238.03; // u
		const int atomic_number = 92;
		const ld density_STP = 19050.0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 2.8e-7; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = 116.0; // J/kgK
		const ld heat_vaporization = 420.0; // kJ/mol
		const ld heat_fusion = 14.0; // kJ/mol
		const ld ionization_1st = 6.194; // eV
	} U;

	const struct NEPTUNIUM
	{
		const ld atomic_weight = (237); // u
		const int atomic_number = 93;
		const ld density_STP = 20450.0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 1.2e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = 335.0; // kJ/mol
		const ld heat_fusion = 10.0; // kJ/mol
		const ld ionization_1st = 6.265; // eV
	} Np;

	const struct PLUTONIUM
	{
		const ld atomic_weight = (244); // u
		const int atomic_number = 94;
		const ld density_STP = 19816.0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = 1.5e-6; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = 325.0; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = 6.060; // eV
	} Pu;

	const struct AMERICIUM
	{
		const ld atomic_weight = (243); // u
		const int atomic_number = 95;
		const ld density_STP = 13670.0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = 5.99; // eV
	} Am;

	const struct CURIUM
	{
		const ld atomic_weight = (247); // u
		const int atomic_number = 96;
		const ld density_STP = 13510.0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = 6.02; // eV
	} Cm;

	const struct BERKELIUM
	{
		const ld atomic_weight = (247); // u
		const int atomic_number = 97;
		const ld density_STP = 14780.00; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = 6.23; // eV
	} Bk;

	const struct CALIFORNIUM
	{
		const ld atomic_weight = (251); // u
		const int atomic_number = 98;
		const ld density_STP = 15100.0; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = 6.30; // eV
	} Cf;

	const struct EINSTEINIUM
	{
		const ld atomic_weight = (252); // u
		const int atomic_number = 99;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = 6.42; // eV
	} Es;

	const struct FERMIUM
	{
		const ld atomic_weight = (257); // u
		const int atomic_number = 100;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = 6.50; // eV
	} Fm;

	const struct MANDELEVIUM
	{
		const ld atomic_weight = (258); // u
		const int atomic_number = 101;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = 6.58; // eV
	} Md;

	const struct NOBELIUM
	{
		const ld atomic_weight = (259); // u
		const int atomic_number = 102;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = 6.65; // eV
	} No;

	const struct LAWRENCIUM
	{
		const ld atomic_weight = (266); // u
		const int atomic_number = 103;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = 4.87; // eV
	} Lr;

	const struct RUTHERFORDIUM
	{
		const ld atomic_weight = (267); // u
		const int atomic_number = 104;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = 6.01; // eV
	} Rf;

	const struct DUBNIUM
	{
		const ld atomic_weight = (268); // u
		const int atomic_number = 105;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = NULL; // eV
	} Db;

	const struct SEABORGIUM
	{
		const ld atomic_weight = (269); // u
		const int atomic_number = 106;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = NULL; // eV
	} Sg;

	const struct BOHRIUM
	{
		const ld atomic_weight = (270); // u
		const int atomic_number = 107;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = NULL; // eV
	} Bh;

	const struct HASSIUM
	{
		const ld atomic_weight = 277; // u
		const int atomic_number = 108;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = NULL; // eV
	} Hs;

	const struct MEITNERIUM
	{
		const ld atomic_weight = 278; // u
		const int atomic_number = 109;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = NULL; // eV
	} Mt;

	const struct DARMSTADTIUM
	{
		const ld atomic_weight = 281; // u
		const int atomic_number = 110;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = NULL; // eV
	} Ds;


	const struct ROENTGENUIM
	{
		const ld atomic_weight = 282; // u
		const int atomic_number = 111;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = NULL; // eV
	} Rg;

	const struct COPERNICIUM
	{
		const ld atomic_weight = 285; // u
		const int atomic_number = 112;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = NULL; // eV
	} Cn;

	const struct NIHONIUM
	{
		const ld atomic_weight = 286; // u
		const int atomic_number = 113;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = NULL; // eV
	} Nh;

	/// <summary>
	///
	/// </summary>
	const struct FLEROVIUM
	{
		const ld atomic_weight = 289; // u
		const int atomic_number = 114;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = NULL; // eV
	} Fl;

	/// <summary>
	///
	/// </summary>
	const struct MOSCOVIUM
	{
		const ld atomic_weight = 290; // u
		const int atomic_number = 115;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = NULL; // eV
	} Mc;

	/// <summary>
	///
	/// </summary>
	const struct LIVERMORIUM
	{
		const ld atomic_weight = 293; // u
		const int atomic_number = 116;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = NULL; // eV
	} Lv;

	/// <summary>
	///
	/// </summary>
	const struct TENNESSINE
	{
		const ld atomic_weight = 294; // u
		const int atomic_number = 117;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = NULL; // eV
	} Ts;

	/// <summary>
	///
	/// </summary>
	const struct OGANESSON
	{
		const ld atomic_weight = 294; // u
		const int atomic_number = 118;
		const ld density_STP = NULL; // kg/m^3
		const ld melting_point = -0; // C
		const ld boiling_point = -0; // C
		const ld thermal_conductivity = 0; // W/mK
		const ld electric_conductivity = 0; // MS/m
		const ld resistivity = NULL; // m Ohm (m * kg*m^2*s^-3*A^-2)
		const ld heat_specific = NULL; // J/kgK
		const ld heat_vaporization = NULL; // kJ/mol
		const ld heat_fusion = NULL; // kJ/mol
		const ld ionization_1st = NULL; // eV
	} Og;


}elem;


static int periodicElement_objectCount = 0;


class PeriodicElements
{
	static void countIncrease() { periodicElement_objectCount += 1; }
	static void countDecrease() { periodicElement_objectCount -= 1; }
public:
	PeriodicElements* _elementPtr;
	Elements periodic_table;
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
