#include "PhysicsWorld.h"




int main()
{
	PhysicsWorld electric;





	//setVal(electric.emi->transformerEquations_IN(4.0, 0, 8, 489, "ip"));
	//show_val("Ip", "A");

	ld v = setVal(electric.geometric_optics->indexOfRefraction(.2290*SU.giga));
	show_val("v", "m/s");

	const map<string, ld> toPrint = electric.geometric_optics->heightOfMirror(1.65, .13);

	printMap(toPrint);
	//Vector test(4, (3.0*_PI)/2.0,'p');
	//test.showAllData();
	printMapByValue(refractions, v);

	return 0;

}