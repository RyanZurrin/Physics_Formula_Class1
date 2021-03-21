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

	setVal(electric.magnetism->currentFromWire2ParallelRunning(4.6,.048, 2.3*pow(10,-4)));
	show_val("d", "m");

	Magnetism lpul;
	lpul.setMagnetismVar(lpul.loopsPerUnitLength(2000, 2.0));

	setVal(electric.magnetism->magneticForceOnIdenticalParticle(31.7, 5.14, 2.1*pow(10,-4),90,23.2));
	show_val("F2", "N");



	return 0;

}