#include "PhysicsWorld.h"




int main()
{
	PhysicsWorld e1;



	//ld n2 = setVal(e1.geometric_optics->indexOfRefractionFromCriticalAngle(53.6, 1.00));
	//show_val("n2", "");

	//const  auto z =
	setVal(e1.vision_optical->angleAt_nOrderMinimum_singleSlit(2, .34*SU.MILLA, 720*SU.NANO));
	show_val("T", "m");



	//ld v = setVal(electric.geometric_optics->indexOfRefractionMedium1(1.50,15.0,  24.0, 2));
	//show_val("n", "");
	//ld val2 = 1.5;
	//const map<string, ld> toPrint = e1.geometric_optics->heightOfMirror(1.59, .13);
	//printMap(toPrint);

	//electric.geometric_optics->indexOfRefractionMedium1(*SU.kilo, 121.0, .004);

	//std::cout << "printing destructive map\n";
	//printMap(e1.wave_optics->destructiveInterferenceRange(1.33, 0, 5,579*SU.nano));

	//std::cout << "printing constructive map\n";
	//printMap(e1.wave_optics->constructiveInterferenceRange(1.33, 0, 5,579*SU.nano));
	//Vector test(4, (3.0*_PI)/2.0,'p');
	//test.showAllData();
	//const ld n = 1.66;
	//printMapByValue(refractions, z);

	return 0;

}