#include <chrono>

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

	setVal(QP::timeToTravelDistance(420e-9, _ELECTRON_MASS_, 2.71, 2.50e-2));
	show_val("wl", "nm");



	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return 0;

}
