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

	auto s1 = add(1, 2, 3, 4, 5);
	auto s2 = add("hello"s, " "s, "world"s, "!"s);
	std::cout << s1 << endl;
	std::cout << s2 << endl;
	cout << add_to_one(1, 2, 3, 4, 5) << endl;
	auto t1 = make_even_tuple(1, 2, 3, 4);
	auto m = min(3.9, 1.0, -2.2, 6.4, -5.9, 1.2, 4.3);
	std::cout << "min: " << m << std::endl;

	//setVal(AP::magnitudeAngularMomentum(1.0));
	//show_val("density", "kg/m^3");

	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
