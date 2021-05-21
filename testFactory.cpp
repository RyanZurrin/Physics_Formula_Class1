#include <chrono>

#include "PhysicsWorld.h"


int main()
{
	//starting time do not edit code between solid comment lines
	//_________________________________________________________________________
	const auto begin =
		std::chrono::high_resolution_clock::now();
	//_________________________________________________________________________
	//add test code between starred areas
	//*************************************************************************
	Matrix<ld, 3, 1> m1;
	m1 << -3, -5, -2;
	std::cout << "matrix m1:\n"<<m1<<std::endl;
	Matrix<ld, 3, 1> m2;
	m2 << 4, -4, -5;
	std::cout << "matrix m2:\n"<<m2<<std::endl;
	Matrix<ld, 3, 1> m3 = m1 + m2;
	std::cout << "matrix m3= m1+m2:\n"<<m3<<std::endl;
	Matrix<ld, 3, 1> m4 = m1.cross(m2);
	std::cout << "matrix m2 length:\n"<<sqrt(m2.dot(m2))<<std::endl;
	Matrix<ld, 3, 1> m5 = m1 * 3.1;
	std::cout << "matrix m5=m1*3.1:\n"<<m5<<std::endl;
	std::cout << "matrix m4 cross:\n"<<m4<<std::endl;


	/*
	Vector2D u(2, 5);
	Vector2D w(7, 1);
	std::cout << "\ndot product: "<< w.dot_product(u) << std::endl;
	Vector3D a(1, 2, 3);
	Vector3D b(-2, 0, 5);
	std::cout << "\ndot product3: "<< b.dot_product(a) << std::endl;
	*/
	//Vector r = u + w;
	//r.showAllData();


	//*************************************************************************
	//calculating run time by subtracting begin time from end time and printing
	//_________________________________________________________________________
	const auto end =
		std::chrono::high_resolution_clock::now();
	const auto elapsed =
		std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	printf("\n\nTime measured: %.9f seconds.\n", elapsed.count() *1e-9);
	//_________________________________________________________________________
	return 0;

}

/*
 *	Vector u(7, 100);
	Vector w(5, 290);
	Vector r = u + w;
	r.showAllData();
 *
 *	//ld n2 = setVal(e1.geometric_optics->indexOfRefractionFromCriticalAngle(53.6, 1.00));
	//show_val("n2", "");

	//const  auto z =
	//const ld c = setVal(e1.electric_potential->capacitanceParallelPlate(26.0*pow(10, -4), 1.1*SU.MILLA));
	//show_val("T", "m");


	//setVal(e1.electric_current->voltageDropAcrossResistor(150*SU.MILLA, 1000.0));
	//show_val("R", "1/C");

	//setVal(e1.circuits->timeConstant_RC(500.0,40.0*SU.MICRO));
	//show_val("t", "s");

	//setVal(e1.magnetism->magneticFieldStrengthInsideSolenoid(58, 1.0*SU.CENTI, 250.0*SU.MILLA));
	//show_val("B1", "A/m");

	//setVal(e1.emi->transformerEquations_VN(0, 120.0, 175.0, 90.0, "vs"));
	//show_val("B2", "A/m");

	//setVal(e1.emWaves->magneticFieldStrength_emWave(6.0*SU.MILLA));
	//show_val("B2", "A/m");

	//setVal(e1.wave_optics->angleAt_nOrderMinimum_singleSlit(1, 1.*SU.MILLA, 600*SU.NANO));
	//show_val("d_0", "m");


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
 *
 *
 */