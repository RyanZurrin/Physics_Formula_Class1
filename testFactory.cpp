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

	setVal(electric.magnetism->currentInLongStraightWire(5.0*SU.centi,1.0*pow(10,-4)));
	show_val("I", "A");

	setVal(electric.magnetism->angleThetaOfElectronToMagneticField(4.0*SU.kilo, 1.25, 1.40*pow(10,-16)));
	show_val("theta", "degrees");




	return 0;

}