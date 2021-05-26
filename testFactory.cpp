﻿#include "Physics_World.h"
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

	VectorNd<ld> v(4, 3 ,2 ,1, 8);
	v.display_vector("v");
	VectorNd<ld> vv(1, 8,5,8, 2);
	vv.display_vector("vv");
	bool val = vv > v;
	std::cout << "v > vv ->" << val << std::endl;
	v *= 2;
	v.display_vector("v");
	val = vv > v;
	std::cout << "v*=2 > vv ->" << val<< std::endl;
	VectorNd<ld> test = v*2;
	std::cout << "";
	std::cout << "test length" << test.size()<<std::endl;
	test.display_vector("test");
	v.vec << 1, 4, 7, 9, 6;

	//v.push_back(88);
	//v.push_back(55);

	MatrixX<ld> m = MatrixX<ld>::Random(4,4);
	m = (m + MatrixX<ld>::Constant(4,4,1.2)) * 50;
	cout << "m =" << endl << m << endl;
	VectorX<ld> v2(4);
	v2 << 1, 2, 3, 4;
	cout << "m * v =" << endl << m * v2<< endl;
	std::cout << v.vec << std::endl;

	v.addValuesToVector(5, 8, 1, 3, 6, 7, 3, 7.7, 8.99);
	v.display_vector();

	Vector3D v3a(1, 2, 3);
	Vector3D v3b(1, 1, 4);
	Vector3D v3c = v3a.cross_product(v3b);

	v3c.displayAllData("v3c");




	//setVal(QP::powerCarriedAwayByElectrons(1.00e-3, 500e-9, 1.30e3,2.28));
	//show_val("N/t", "elec/sec");


	//*************************************************************************
	//Stopping timer and displaying the programs execution time
	//_________________________________________________________________________
	timer.stop();
	timer.displayRunTime();
	//_________________________________________________________________________
	return 0;

}
