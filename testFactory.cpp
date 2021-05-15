#include <functional>

#include "PhysicsWorld.h"


int main()
{
	PhysicsWorld e1;

	const auto x = setVal(e1.relativity->relativisticMomentum(_PROTON_MASS_));
	show_val("u", "c");

	//setVal(e1.relativity->velocityFrom_momentum(x, 1.00*SU.NANO));
	//show_val("dust", "m/s");

	std::cout << "kev:"<< converter.joules_to_eV();

	return 0;

}

/*
 *	//ld n2 = setVal(e1.geometric_optics->indexOfRefractionFromCriticalAngle(53.6, 1.00));
	//show_val("n2", "");

	//const  auto z =
	//const ld c = setVal(e1.electric_potential->capacitanceParallelPlate(26.0*pow(10, -4), 1.1*SU.MILLA));
	//show_val("T", "m");


	//setVal(e1.electric_current->voltageDropAcrossResistor(150*SU.MILLA, 1000.0));
	//show_val("R", "1/C");

	//setVal(e1.circuits->timeConstant_RC(500.0,40.0*SU.MICRO));
	//show_val("t", "s");

	//setVal(e1.magnetism->magneticFieldStrengthInsideSolenoid(58, 1.0*SU.CENTI, 250.0*SU.MILLA));
	//show_val("B1", "A/m");

	//setVal(e1.emi->transformerEquations_VN(0, 120.0, 175.0, 90.0, "vs"));
	//show_val("B2", "A/m");

	//setVal(e1.emWaves->magneticFieldStrength_emWave(6.0*SU.MILLA));
	//show_val("B2", "A/m");

	//setVal(e1.wave_optics->angleAt_nOrderMinimum_singleSlit(1, 1.*SU.MILLA, 600*SU.NANO));
	//show_val("d_0", "m");


	//ld v = setVal(electric.geometric_optics->indexOfRefractionMedium1(1.50,15.0,  24.0, 2));
	//show_val("n", "");
	//ld val2 = 1.5;
	//const map<string, ld> toPrint = e1.geometric_optics->heightOfMirror(1.59, .13);
	//printMap(toPrint);

	//electric.geometric_optics->indexOfRefractionMedium1(*SU.kilo, 121.0, .004);

	//std::cout << "printing destructive map\n";
	//printMap(e1.wave_optics->destructiveInterferenceRange(1.33, 0, 5,579*SU.nano));

	//std::cout << "printing constructive map\n";
	//printMap(e1.wave_optics->constructiveInterferenceRange(1.33, 0, 5,579*SU.nano));
	//Vector test(4, (3.0*_PI)/2.0,'p');
	//test.showAllData();
	//const ld n = 1.66;
	//printMapByValue(refractions, z);
 *
 *
 */