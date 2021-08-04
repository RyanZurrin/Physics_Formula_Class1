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






	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
auto algo(int n)
{
	auto k = static_cast<int>(sqrt(n));
	auto ret = true;
	for (int i = 2; i < k; i++)
	{
		if (n%k==0)
		{
			ret = false;
			break;
		}
		else
		{
		}
	}
}