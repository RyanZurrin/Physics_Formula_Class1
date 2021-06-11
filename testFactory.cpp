#include "Physics_World.h"
#include "RunTimer.h"


int main()
{
	//starting time do not edit code between solid comment lines
	//_________________________________________________________________________
	RunTimer timer;
	timer.start();
	//_________________________________________________________________________
	//add test code between starred areas
	//*************************************************************************

	//setVal(QP::acceleratingVoltage(.0103e-9, _PROTON_CHARGE_));
	//show_val("f", "Hz");

	setVal(AP::electromagneticRadiation_wavelengthNeededToPumpLaser(20.61));
	show_val("density", "kg/m^3");

	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
