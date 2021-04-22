#include "PhysicsWorld.h"




int main()
{
	PhysicsWorld electric;



	ld n2 = setVal(electric.geometric_optics->indexOfRefractionFromCriticalAngle(53.6, 1.00));
	show_val("n2", "");


	setVal(electric.wave_optics->distanceBetweenFringes(3.0, 633*SU.nano,.0800*SU.milla ));
	show_val("angle", "degrees");


	ld v = setVal(electric.geometric_optics->indexOfRefractionMedium1(1.50,15.0,  24.0, 2));
	show_val("n", "");
	//ld val2 = 1.5;
	//const map<string, ld> toPrint = electric.geometric_optics->heightOfMirror(1.59, .13);

	//printMap(toPrint);

	//electric.geometric_optics->indexOfRefractionMedium1(*SU.kilo, 121.0, .004);

	//printMap(toPrint2);
	//Vector test(4, (3.0*_PI)/2.0,'p');
	//test.showAllData();
	printMapByValue(refractions, v);

	return 0;

}