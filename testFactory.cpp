#include "PhysicsWorld.h"




int main()
{
	PhysicsWorld electric;





	setVal(electric.emi->impedance(40.0, 3.0*SU.milla, 5.0*SU.micro,60.0));
	show_val("Z@60", "ohm");

	setVal(electric.emi->impedance(40.0, 3.0*SU.milla, 5.0*SU.micro,10.0*SU.kilo));
	show_val("Z@10kHz", "ohm");



	//Vector test(4, (3.0*_PI)/2.0,'p');
	//test.showAllData();


	return 0;

}