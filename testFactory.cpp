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
	/*
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
	std::cout << "det m = " << m.determinant() << endl;
	*/
	RCP<const Basic> x = symbol("x");
	RCP<const Basic> y = symbol("y");
	RCP<const Basic> z = symbol("z");
	RCP<const Basic> w = symbol("w");
	RCP<const Basic> i100 = integer(100);

	RCP<const Basic> e, r;

	e = pow(add(add(pow(x, y), pow(y, x)), pow(z, x)), i100);

	std::cout << "Expanding: " << *e << std::endl;

	auto t1 = std::chrono::high_resolution_clock::now();
	r = expand(e);
	auto t2 = std::chrono::high_resolution_clock::now();
	//std::cout << *r << std::endl;
	std::cout
		<< std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
		<< "ms" << std::endl;
	std::cout << "number of terms: "
		<< rcp_dynamic_cast<const Add>(r)->get_dict().size() << std::endl;

	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime("s");
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
