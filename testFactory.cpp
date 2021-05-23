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

	//setVal(QP::timeToTravelDistance(420e-9, _ELECTRON_MASS_, 2.71, 2.50e-2));
	//show_val("wl", "nm");
	Vector3D bb(4, 6, -3);
	Vector3D a(2, -4, 1, "helpme");
	a.displayAllData();
	a.normalize_vector();
	a.displayAllData("a normal:");
	Vector3D b(-1, 4, 7);
	Vector3D c = a.cross_product(b);
	c.displayAllData("c = axb:");
	Vector3D d = c.cross_product(bb);

	std::cout << "mag: "<< c.return_mag()<< std::endl;
	std::cout << "dot: "<< a.dot_product(b)<< std::endl;
	std::cout << "angle between: "<< a.angle_between_vectors(b)<< std::endl;
	std::cout << "angle between: "<< b.angle_between_vectors(a)<< std::endl;


	Vector2D a1(1, 7);
	Vector2D b1(15, 3);
	std::cout << "2d Dot prod: "<< a1.dot_product(b1)<< std::endl;
	std::cout << "projection: "<< a1.projection(b1)<< std::endl;
	std::cout << "b*proj: "<< a1.projection(b1)* b1.return_mag()<< std::endl;


	TriangleSolver triangle(5, 3, 7);
	std::cout << triangle;
	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return 0;

}
