#include "Physics_World.h"
#include "RunTimer.h"




int main(int argc, char* argv[])
{
	//starting time do not edit code between solid comment lines
	//_________________________________________________________________________
	RunTimer timer;
	timer.start();
	//_________________________________________________________________________
	//add test code between starred areas
	//*************************************************************************

	Vector3D u("u");
	Vector3D v("v");
	cin >> u;
	cin >> v;
	std::cout << "dot product of u and v is " << u.dot_product(v) << endl;
	std::cout << "angle between u and v is " << u.cross_product(v) << endl;
	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime("ms");
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
