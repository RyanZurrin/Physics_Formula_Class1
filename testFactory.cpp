#include "PhysicsWorld.h"




int main()
{
	PhysicsWorld electric;





	setVal(electric.emi->transformerEquations_IN(4.0, 0, 8, 489, "ip"));
	show_val("Ip", "A");

	setVal(electric.emWaves->waveLength_dopplerEffect(724.5*SU.kilo, 673.1*SU.nano));
	show_val("S", "m/s");

	std::cout << "c: "<< _c_<<endl;

	//Vector test(4, (3.0*_PI)/2.0,'p');
	//test.showAllData();


	return 0;

}