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
	cout << "weight: " << converter.kilogram_to_pound(box.getWeight(elements.Cu.density_STP)) << endl;

	Rectangle rec(3, 8);
	rec.printRectangleInfo();

	RectangularPrism block(4.0, 2.3, 5.0);
	block.printRectangularPrismInfo();

	block.setHeight(15.5);
	block.printRectangularPrismInfo();

	Cylinder cyl(12.0, 4.0);
	cyl.printCylinderInfo();

	Cone cone(14.0, 5.0);
	cone.printConeInfo();

	//ld iron = Elements::IRON::density_STP;
	Sphere sphere(4.0);
	sphere.printSphereInfo();
	cout << "weight: " << converter.kilogram_to_pound(sphere.getWeight(elements.Fe.density_STP)) << endl;

	Pyramid pyramid(2.0, 3.0, 4.0);
	pyramid.printPyramidInfo();

	Circle circle(4.5);
	circle.printCircleInfo();

	Parallelogram para(3.0, 4.0, 5.0);
	para.printParallelogramInfo();

	cout << Kinematics::range_of_projectile_flight(0, 80.0, 30.0) << endl;

	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
