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

	Vector3D u(1.0/2.0, -1.0/4.0, -1.0/2.0);
	Vector3D v(2.0, 2.0, -2.0);
	cout << u.distance(v) << endl;
	cout << v.angle_between_vectors(u) << endl;

	cout << u.dot_product(v) << endl;
	cout << "orthogonal: " << u.isOrthogonalWith(v);
	cout << "\nproj v on u: " << u.projection(v) << endl;
	cout << "\nproj u on v: " << v.projection(u) << endl;

	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
