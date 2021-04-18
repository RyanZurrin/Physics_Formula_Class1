#include "PhysicsWorld.h"




int main()
{
	PhysicsWorld electric;





	setVal(electric.geometric_optics->magnification(1.5, .750));
	show_val("wL", "m");


	//ld v = setVal(electric.geometric_optics->indexOfRefractionMedium2(1.00,38.0,  29.0, 3));
	//show_val("n", "");
	//ld val2 = 1.5;
	//const map<string, ld> toPrint = electric.geometric_optics->heightOfMirror(1.59, .13);

	//printMap(toPrint);

	//const map<string, ld> toPrint2 = electric.geometric_optics->angleAndDistanceOfBouncedLaserToSensor(51.5*SU.kilo, 121.0, .004);

	//printMap(toPrint2);
	//Vector test(4, (3.0*_PI)/2.0,'p');
	//test.showAllData();
	//printMapByValue(refractions, v);

	return 0;

}