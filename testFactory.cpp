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
	Vector2D x(5, 102.0, 'p');
	Vector2D y(4, 75.0, 'p');
	Vector2D z = x + y;
	x.displayAllData();
	y.displayAllData();
	z.displayAllData("resultant");
	std::cout << "dot product of x and y is " << dot_product(x, y) << endl;

	Eigen::MatrixX<double> test { {1,2,3},{4,5,6},{7,8,9} };
	Eigen::MatrixX<double> test2{ {9,8,7},{6,5,4},{3,2,1} };

	Eigen::MatrixX<double> ns{ {1,1,3,-1},{1,2,4,-3},{2,3,7,-4} };
	std::cout << test << endl;
	std::cout << test2 << endl;
	std::cout << test * test << endl;
	std::cout << "det Test: " << test.determinant();
	std::cout << "test2 " << test2.base();
	FullPivLU<MatrixXd> lu(ns);
	MatrixXd A_null_space = lu.kernel();
	std::cout << "nullspace\n" << A_null_space << endl;

	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
