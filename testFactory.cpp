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
	Eigen::MatrixXf m(4, 4);
	m << 2, 0, 3, -1,
		 1, 0, 2, 2,
		 0, -1, 1, 4,
		 2, 0, 1, -3;
	std::cout << "here is matrix m:\n" << m << endl;
	m.row(0) -= 2 * m.row(1);
	std::cout << "here is matrix m after R1 - 2R2:\n" << m << endl;
	m.row(3) -= 2 * m.row(1);
	std::cout << "here is matrix m after R4 - 2R2:\n" << m << endl;
	std::cout << "det m = " << m.determinant();
	
	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
