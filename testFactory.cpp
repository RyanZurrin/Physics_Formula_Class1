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


	arma::arma_rng::set_seed_random();

	arma::Mat<double> A = arma::randu(4, 4);
	std::cout << "A:\n" << A << endl;

	std::cout << "A * A.t() =\n";
	std::cout << A * A.t() << endl;

	A.row(0) = A.row(1) + A.row(3);
	A.col(3).zeros();
	std::cout << "add rows 1 and 3, store result in row 0, also fill 4th column with zeros:\n";
	std::cout << "A:\n" << A << "\n";

	arma::Mat<double>B = arma::diagmat(A);
	std::cout << "B:\n" << B << "\n";

	A.save("A_mat.txt", arma::arma_ascii);
	B.save("B_mat.txt", arma::arma_ascii);




	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
