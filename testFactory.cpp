#include "PhysicsWorld.h"




int main()
{
	PhysicsWorld electric;





	//setVal(electric.emi->transformerEquations_IN(4.0, 0, 8, 489, "ip"));
	//show_val("Ip", "A");

	setVal(electric.geometric_optics->angleOfRefraction(1.00, 2.419, 30.0));
	show_val("n2", "");

	const map<string, ld> toPrint = electric.geometric_optics->heightOfMirror(1.65, .13);

	print_map(toPrint);
	//Vector test(4, (3.0*_PI)/2.0,'p');
	//test.showAllData();


	return 0;

}