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

	int arr[] = { 1,2,3,4,5 };
	std::vector<int> v21;
	v21.insert(v21.begin(), arr, arr + 5);
	std::vector<int> v22;
	v22.insert(v22.begin(), arr, arr + 3);

	printVector(v21);
	printVector(v22);

	printElementData(elements.Ba);
	printElementData(elements.Os);

	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
