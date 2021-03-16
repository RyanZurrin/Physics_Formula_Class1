#include "PhysicsWorld.h"




int main()
{
	PhysicsWorld electric;


	setVal(electric.circuits->parallelResistance(100, 2500, 4000));
	show_val("parallel Ohms");

	setVal(electric.circuits->seriesResistance(100, 2500, 4000));
	show_val("series Ohms");

	setVal(electric.circuits->time_fromDischargeEquation(80.0*SU.micro,250*SU.kilo,.250));
	show_val("time .250%", "V");

	setVal(electric.electric_current->resistanceUsingResistivity(resistivity.COPPER,30,circleArea(AWG.AWG19/2)));
	show_val("resistance", "OHMS");

	Magnetism magnet;


	return 0;

}