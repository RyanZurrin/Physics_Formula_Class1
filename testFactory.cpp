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


	ETL etl("adult_data_short.csv", ",", false);

	std::vector<std::vector<std::string>> dataset = etl.readCSV();

	int rows = dataset.size();
	//std::cout << "rows: " << rows << std::endl;
	int cols = dataset[0].size();
	//std::cout << "cols: " << cols << std::endl;

	Eigen::MatrixXd dataMat = etl.CSVtoEigen(dataset,rows,cols);
	Eigen::MatrixXd norm = etl.Normalize(dataMat, false);

	//std::cout << norm;
	Eigen::MatrixXd X_train, y_train, X_test, y_test;
	std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd, Eigen::MatrixXd>
	split_data = etl.TrainTestSplit(norm, 0.8);
	std::tie(X_train, y_train, X_test, y_test) = split_data;
	std::cout << "x-train rows: " << X_train.rows() << std::endl;
	std::cout << "x-train cols: " << X_train.cols() << std::endl;
	std::cout << "y-train rows: " << y_train.rows() << std::endl;
	std::cout << "y-train cols: " << y_train.cols() << std::endl;
	std::cout << "x-test rows: " << X_test.rows() << std::endl;
	std::cout << "x-test cols: " << X_test.cols() << std::endl;
	std::cout << "y-test rows: " << y_test.rows() << std::endl;
	std::cout << "y-test cols: " << y_test.cols() << std::endl;

	LogisticRegression lr;

	int dims = X_train.cols();
	Eigen::MatrixXd W = Eigen::VectorXd::Zero(dims);
	double b = 0.0;
	double lambda = 0.0;
	bool log_cost = true;
	double learning_rate = 0.01;
	int num_iter = 5000;

	Eigen::MatrixXd dw;
	double db;
	std::list<double> costs;
	std::tuple<Eigen::MatrixXd, double, Eigen::MatrixXd, double, std::list<double>>
	optimize = lr.Optimize(W, b, X_train, y_train, num_iter, learning_rate, lambda, log_cost);
	std::tie(W,b,dw,db,costs) = optimize;

	Eigen::MatrixXd y_pred_test = lr.Predict(W,b,X_test);
	Eigen::MatrixXd y_pred_train = lr.Predict(W,b,X_train);

	auto train_acc = (100-(y_pred_train-y_train).cwiseAbs().mean()*100);
	auto test_acc = (100-(y_pred_test-y_test).cwiseAbs().mean()*100);

	std::cout << "Train Accuracy: " << train_acc << std::endl;
	std::cout << "Test Accuracy: " << test_acc << std::endl;

	//std::vector<float> costVec(costs.begin(), costs.end());
	//etl.Vectortofile(costVec,"datasets/cost.txt");

	return EXIT_SUCCESS;

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
	//return EXIT_SUCCESS;

}
