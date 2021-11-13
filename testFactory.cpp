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

	std::cout << Kinematics::trajectory_equation(6.0, 60.0, 0.0);

	MatrixND<int> test(3, 3, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	test.print();
	MatrixND<int> transposed = test.transpose();
	transposed.print();
	MatrixND<int> test2(3, 3, 9, 8, 7, 6, 5, 4, 3, 2, 1);
	test2.print();
	MatrixND<int> result = test.mult(test2);
	result.print();
	std::cout <<	"dot: " << test.dot(test2);
	MatrixND<int> test3(3, 2, 1, 2, 3, 4, 5, 6);
	test3.print();
	MatrixND<int> test4(2, 3, 9, 8, 7, 6, 5, 4);
	test4.print();
	MatrixND<int> result2 = test3.mult(test4);
	result2.print();
	
	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime("ms");
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
