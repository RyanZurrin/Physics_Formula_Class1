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
	Vector2D vec(2, 5);
	vec.displayAllData();
	Vector3D vec3(3, 5, 9);
	vec3.displayAllData();
	setVal(AP::magnitudeAngularMomentum(1.0));
	show_val("density", "kg/m^3");
	auto d = Drag::drag_force(5.9, 55.9, 2.3, 33.3);
	std::cout << "d: " << d << endl;
	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
