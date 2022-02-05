#include <stack>

#include "Physics_World.h"
#include "GeoUtils.h"
#include "RunTimer.h"
#include "BinarySearchTree.h"



int main(int argc, char* argv[])
{
	//starting time do not edit code between solid comment lines
	//_________________________________________________________________________
	RunTimer timer(SECONDS);
	timer.start();
	//_________________________________________________________________________
	//add test code between starred areas
	//*************************************************************************
	Vector2D A(3, 0);
	Vector2D B(0, 4);
	Vector2D C = -A - B;
	C.displayAllData();
	

	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.display();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}