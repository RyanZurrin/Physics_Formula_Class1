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

	string test = "........hello. all. you .beautiful .letters........";
	std::cout << "test with spaces: " << test << std::endl;
	const string test3 = remove(test, '.');
	std::cout << "test3: " << test3 << std::endl;
	string t2 = "HELLO ALL YOU BEAUTIFUL LETTERS";

	string t3 = to_upper(test3);
	std::cout << "test to upper: " << t3 << std::endl;

	string tlow = to_lower(t2);
	std::cout << "t2: " << tlow << std::endl;

	string revS = reverse(tlow);
	std::cout << "reversed test: " << revS << std::endl;




	//setVal(QP::acceleratingVoltage(.0103e-9, _PROTON_CHARGE_));
	//show_val("f", "Hz");

	//setVal(QP::energy_eM(90e6));
	//show_val("E", "eV");


	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return EXIT_SUCCESS;

}
