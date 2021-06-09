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

	setVal(Heat::timeToHeatObject(4.0, c.human_body_average_S[0], 2.0, 200.0));
	show_val("photons", "per second");


	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
