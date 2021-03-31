#include "PhysicsWorld.h"




int main()
{
	PhysicsWorld electric;

	/*
	setVal(electric.circuits->parallelResistance(100, 2500, 4000));
	show_val("parallel Ohms");

	setVal(electric.circuits->seriesResistance(100, 2500, 4000));
	show_val("series Ohms");

	setVal(electric.circuits->time_fromDischargeEquation(80.0*SU.micro,250*SU.kilo,.250));
	show_val("time .250%", "V");
	*/

	setVal(electric.magnetism->magneticFieldStrength_straightCurrentCarryingWire(.5, .05));
	show_val("B", "T");

	Magnetism lpul;
	lpul.setMagnetismVar(lpul.loopsPerUnitLength(2000, 2.0));

	electric.emi->setElectroMagVar(electric.emi->inductanceSolenoid(200, .040, .10, 'd'));

	setVal(electric.emi->magneticFieldMagnitude(2.70*pow(10, -5),.0850, 58,'r'));
	show_val("B", "T");

	Vector test(-4, -5);
	test.showAllData();


	return 0;

}