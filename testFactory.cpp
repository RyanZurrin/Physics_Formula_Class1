#include "PhysicsWorld.h"




int main()
{
	PhysicsWorld electric;

	ld areaPlate = setVal(electric.electric_potential->capacitance(4.14*SU.micro,145));
	show_val("C");
	ld vm = setVal(electric.electric_potential->vMaxOnCapacitor(dielectric_strength.teflon, 4.89*SU.micro));
	show_val("vMax");
	ld maxCharge = setVal(electric.electric_potential->maxChargeCanBeStoredCapacitor(1.29 * SU.milla,vm));
	show_val("max charge");
	setVal(electric.electric_current->lengthOfResistor(.145*SU.milla/2, .142, 5.6*pow(10,-8)));
	show_val("length");


	return 0;

}