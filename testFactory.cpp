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


	ETL etl("winedata.csv", ",", false);
	LinearRegression lr;

	std::vector<std::vector<std::string>> dataset = etl.readCSV();

	int rows = dataset.size();
	//std::cout << "rows: " << rows << std::endl;
	int cols = dataset[0].size();
	//std::cout << "cols: " << cols << std::endl;

	Eigen::MatrixXd dataMat = etl.CSVtoEigen(dataset,rows,cols);
	Eigen::MatrixXd nor = etl.Normalize(dataMat, true);
	//std::cout << nor;
	//std::cout << dataMat.rows() << std::endl;

	Eigen::MatrixXd X_train, y_train, X_test, y_test;
	std::tuple<Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd> split_data = etl.TrainTestSplit(nor, 0.8);
	std::tie(X_train, y_train, X_test, y_test) = split_data;
	std::cout << "x-train rows: " << X_train.rows() << std::endl;
	std::cout << "x-train cols: " << X_train.cols() << std::endl;
	std::cout << "y-train rows: " << y_train.rows() << std::endl;
	std::cout << "y-train cols: " << y_train.cols() << std::endl;
	std::cout << "x-test rows: " << X_test.rows() << std::endl;
	std::cout << "x-test cols: " << X_test.cols() << std::endl;
	std::cout << "y-test rows: " << y_test.rows() << std::endl;
	std::cout << "y-test cols: " << y_test.cols() << std::endl;




	Eigen::VectorXd vec_train = Eigen::VectorXd::Ones(X_train.rows());
	Eigen::VectorXd vec_test = Eigen::VectorXd::Ones(X_test.rows());

	X_train.conservativeResize(X_train.rows(), X_train.cols()+1);
	X_train.col(X_train.cols()-1) = vec_train;

	X_test.conservativeResize(X_test.rows(), X_test.cols()+1);
	X_test.col(X_train.cols()-1) = vec_test;

	Eigen::VectorXd theta = Eigen::VectorXd::Zero(X_train.cols());
	float alpha = 0.01;
	int iters = 1000;

	Eigen::VectorXd thetaOut;
	//std::cout <<"theta: "<< theta <<std::endl;
	std::vector<float> cost;


	std::tuple<Eigen::VectorXd,std::vector<float>> gd = lr.GradientDescent(X_train, y_train, theta, alpha, iters);
	std::tie(thetaOut,cost) = gd;

	//std::cout << "thetaout: " << thetaOut << std::endl;


	//etl.Vectortofile(cost,"datasets/cost.txt");
	//etl.EigentoFile(thetaOut,"datasets/thetaOut.txt");

	auto mu_data = dataMat.colwise().mean();
	std::cout << "mu_data: " << mu_data << std::endl;
	auto mu_z = mu_data(0,11);
	std::cout << "mu_z: " << mu_z << std::endl;
	auto scaled_data = dataMat.rowwise() - dataMat.colwise().mean();
	std::cout << "scaled data: " << scaled_data << std::endl;
	auto sigma_data = ((scaled_data.array().square().colwise().sum())/(scaled_data.rows()-1)).sqrt();
	std::cout << "sigma data: " << sigma_data << std::endl;
	auto sigma_z = sigma_data(0,11);
	std::cout << "sigma z: " << sigma_z << std::endl;
	Eigen::MatrixXd y_train_hat = (X_train*thetaOut*sigma_z).array() + mu_z;
	std::cout << "yTrain hat: " << y_train_hat << std::endl;
	Eigen::MatrixXd y = dataMat.col(11).topRows(1279);
	std::cout << "y: " << y << std::endl;
	float R_Squared = lr.RSquared(y,y_train_hat);
	std::cout << "R-Squared: " << R_Squared << std::endl;

	//etl.EigentoFile(y_train_hat,"datasets/y_train_hat.txt");

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
