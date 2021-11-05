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
	Square test(5.0);
	test.printSquareInfo();

	Cube box(2.0);
	box.printCubeInfo();

	Rectangle rec(3, 8);
	rec.printRectangleInfo();

	RectangularPrism block(4.0, 2.3, 5.0);
	block.printRectangularPrismInfo();

	block.setHeight(15.5);
	block.printRectangularPrismInfo();

	Cylinder cyl(12.0, 4.0);
	cyl.printCylinderInfo();

	cout << Kinematics::range_of_projectile_flight(0, 80.0, 30.0) << endl;

	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
