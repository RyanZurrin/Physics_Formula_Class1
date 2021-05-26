#include "Physics_World.h"
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


	ETL test("winedata.csv", ",", false);
	std::vector<std::vector<std::string>> dataset = test.readCSV();

	int rows = dataset.size();
	int cols = dataset[0].size();

	Eigen::MatrixXd dataMat = test.CSVtoEigen(dataset, rows, cols);

	std::cout << dataMat << std::endl;





	/*
	VectorND<ld> v(4, 3 ,2 ,1, 8);
	v.display_vector("v");
	VectorND<ld> vv(1, 8,5,8, 2);
	vv.display_vector("vv");
	bool val = vv > v;
	std::cout << "v < vv ->" << val << std::endl;
	v *= 2;
	v.display_vector("v");
	val = vv > v;
	std::cout << "v*=2 < vv ->" << val<< std::endl;
	VectorND<ld> test = v*vv;
	test.display_eigen("test eigen");
	std::cout << "";
	std::cout << "test length" << test.size()<<std::endl;
	test.display_vector("test");
	v.push_back(88);
	v.push_back(55);

	MatrixX<ld> m = MatrixX<ld>::Random(5,5);
	m = (m + MatrixX<ld>::Constant(5,5,1.2)) * 50;
	cout << "m =" << endl << m << endl;
	VectorX<ld> v2(4);
	v2 << 1, 2, 3, 4;
	cout << "m * v =" << endl << m * test.returnEigenVector()<< endl;

	v.addValuesToVector(5, 8, 1, 3, 6, 7, 3, 7.7, 8.99);
	v.display_vector();
	v.display_eigen("v eigen");
	vv.display_eigen("vv eigen");
	Vector3D v3a(1, 2, 3);
	Vector3D v3b(1, 1, 4);
	Vector3D v3c = v3a.cross_product(v3b);

	v3c.displayAllData("v3c");

	VectorND<ld> aaa(1, 2, 3, 4);
	VectorND<ld> bbb(1, 2, 3, 4);
	bool value = aaa == bbb;
	std::cout << "aaa==bbb:"<<value<< endl;
	aaa.push_back(9);
	value = aaa != bbb;
	std::cout << "aaa!=bbb:"<<value<< endl;

	*/
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
