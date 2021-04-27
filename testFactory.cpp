#include "PhysicsWorld.h"




int main()
{
	PhysicsWorld e1;



	ld n2 = setVal(e1.geometric_optics->indexOfRefractionFromCriticalAngle(53.6, 1.00));
	show_val("n2", "");

	ld z =setVal(e1.wave_optics->rayleighEquation(620*SU.nano, 6.10*SU.centi));
	show_val("fringe", "m");



	//ld v = setVal(electric.geometric_optics->indexOfRefractionMedium1(1.50,15.0,  24.0, 2));
	//show_val("n", "");
	//ld val2 = 1.5;
	//const map<string, ld> toPrint = electric.geometric_optics->heightOfMirror(1.59, .13);

	//printMap(toPrint);

	//electric.geometric_optics->indexOfRefractionMedium1(*SU.kilo, 121.0, .004);
	std::cout << "printing map\n";
	printMap(e1.wave_optics->destructiveInterferenceRange(1.55, 0, 4,584*SU.nano));
	//Vector test(4, (3.0*_PI)/2.0,'p');
	//test.showAllData();
	const ld n = 1.66;
	printMapByValue(refractions, n);

	return 0;

}