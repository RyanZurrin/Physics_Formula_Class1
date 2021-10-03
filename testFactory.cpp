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


	double A[3][4] = {
		{1.0, 1.0, -1.0, 2.0},
		{3.0, 1.0, 4.0, 11.0},
		{2.0, 3.0, -5.0, 2.0}
	};
	to_reduced_row_echelon_form(A);

	print_matrix(A, 3, 4);
	Vector3D t(-1, 2, 1);
	std::cout << "distance: " << t.distance_to_plane(1, 2, -2, -13) << endl;

	Vector2D g(2, 4);
	std::cout << "distance: " << g.distance_to_line(1, 2, -3) << endl;

	Eigen::Matrix<double, 3, 3> det;
	det << 1, 2, 4, 2, -1, 3, 4, 0, 1;
	std::cout << det << endl;
	std::cout << "\ndeterminant: " << det.determinant() << endl;;

	Eigen::Matrix<double, 4, 4> dett;
	dett << 1, 2, 3, 4, 1, 0, 2, 0, 0, 1, 2, 3, 2, 3, 0, 0;
	std::cout << dett << endl;
	std::cout << "\ndeterminant: " << det.determinant() << endl;

	std::cout << "\ninverse:\n" << det.inverse() << endl;




	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
