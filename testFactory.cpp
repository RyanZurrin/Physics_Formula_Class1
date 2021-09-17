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

	Eigen::Vector4i u(1, 2, -1, 2);
	Eigen::Vector4i v(-3, 1, 0, 2);
	Eigen::Vector4i w(0, 1, 1, -1);
	Eigen::Vector4i z = 2 * u + v - 2 * w;
	std::cout << "z: " << z << endl;
	Eigen::MatrixXcd a = Eigen::MatrixXcd::Random(3,3);
	cout << a;
	Eigen::MatrixXcd b = a.transpose();
	cout << "\n" << b;

	VectorND<int> v1(1, 0, 0, 0);
	v1.show_magnitude();
	VectorND<int> u1(0, 1, 0, 0);
	v1.typeOfAngleBetween(u1);
	u1.show_magnitude();
	std::cout << "\ndistance: " << v1.distance(u1);
	std::cout << "\nangle between: " << v1.angle_between_vectors(u1);


	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
