#include "PhysicsWorld.h"




int main()
{
	PhysicsWorld electric;


	setVal(electric.circuits->parallelResistance(100, 2500, 4000));
	show_val("parallel Ohms:");

	setVal(electric.circuits->seriesResistance(100, 2500, 4000));
	show_val("series Ohms:");

	setVal(electric.circuits->resistance_fromDCequations(.833333,.632,25*SU.nano));
	show_val("R Ohms:");

	setVal(electric.electric_current->resistance_ohmic(4.5, 83*SU.milla));
	show_val("resistance", "OHMS");




	return 0;

}