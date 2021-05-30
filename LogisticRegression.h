#pragma once
#ifndef LogisticRegression_h
#define LogisticRegression_h

#include <Eigen/Dense>
#include <list>
#include <iostream>

class LogisticRegression
{
public:
	LogisticRegression()
	{}

	static Eigen::MatrixXd Sigmoid(Eigen::MatrixXd Z);

	static std::tuple<Eigen::MatrixXd, double, double>
		Propagate(Eigen::MatrixXd W, double b, Eigen::MatrixXd X, Eigen::MatrixXd y, double lambda);
	static std::tuple<Eigen::MatrixXd, double, Eigen::MatrixXd, double, std::list<double>>
		Optimize(Eigen::MatrixXd W, double b, Eigen::MatrixXd X, Eigen::MatrixXd y, int num_iter, double learning_rate, double lambda, bool log_cost);
	Eigen::MatrixXd Predict(Eigen::MatrixXd W, double b, Eigen::MatrixXd X)const;
};

#endif

inline Eigen::MatrixXd LogisticRegression::Sigmoid(Eigen::MatrixXd Z)
{
	return 1/(1+(-Z.array()).exp());
}

inline std::tuple<Eigen::MatrixXd, double, double>
LogisticRegression::Propagate(Eigen::MatrixXd W, double b, Eigen::MatrixXd X,
							  Eigen::MatrixXd y, double lambda)
{
	const int m = static_cast<int>( y.rows());
	//std::cout << "in Propagate(rows) m: " << m << endl;
	//std::cout << "in Propagate(b): " << b << endl;
	//std::cout << "in Propagate(lambda): " << lambda<< endl;
	//std::cout << "in Propagate(W): " << W << endl;
	//std::cout << "in Propagate(X): " << X << endl;
	//std::cout << "in Propagate(y): " << y << endl;


	Eigen::MatrixXd Z = (W.transpose() * X.transpose()).array() + b;
	//std::cout << "in Propagate(Z) = W.transpose * X.transpose.array(): " << Z << endl;
	Eigen::MatrixXd A = 1 / (1 + (-Z.array()).exp());//Sigmoid(Z);
	//std::cout << "in Propagate(A)=  Sigmoid: " << m << endl;
	auto ce_var1 = y.transpose() * (Eigen::VectorXd)A.array().log().transpose();
	auto ce_var2 = ((Eigen::VectorXd)(1 - y.array())).transpose();
	auto ce_var3 = (Eigen::VectorXd)(1 - A.array()).log().transpose();

	auto cross_entropy =
		-(ce_var1 + ce_var2 * ce_var3)/m;
	//std::cout << "in Propagate(cross-entropy): " << cross_entropy << std::endl;
	double l2_reg_cost = W.array().pow(2).sum() * (lambda/(2*m));
	std::cout << "in Propagate(l2 reg cost) = W.array.pow.sum*lamda/2*m: " << l2_reg_cost << endl;

	double cost = static_cast<const double>((cross_entropy.array()[0])) + l2_reg_cost;
	std::cout << "in Propagate(cost) = cross_entrtopy.array[0]+l2regCost: " << cost << endl;
	Eigen::MatrixXd dw =
		(Eigen::MatrixXd)(((Eigen::MatrixXd)(A-y.transpose()) * X)/m) +
		((Eigen::MatrixXd)(lambda/m*W)).transpose();
	//std::cout << "in Propagate(dw): " << m << endl;
	double db = (A-y.transpose()).array().sum()/m;
	//std::cout << "in Propagate(db): " << m << endl;
	return std::make_tuple(dw,db,cost);
}

inline std::tuple<Eigen::MatrixXd, double, Eigen::MatrixXd, double, std::list<double>>
LogisticRegression::Optimize(Eigen::MatrixXd W, double b,
							 Eigen::MatrixXd X, Eigen::MatrixXd y, int num_iter,
							 double learning_rate, double lambda, bool log_cost)
{
	//std::cout << "in Optimize(W): " << W << endl;
	//std::cout << "in Optimize(b): " << b << endl;
	//std::cout << "in Optimize(X): " << X << endl;
	//std::cout << "in Optimize(y): " << y << endl;
	//std::cout << "in Optimize(num_iter): " << num_iter << endl;
	//std::cout << "in Optimize(learning rate): " << learning_rate << endl;
	//std::cout << "in Optimize(lamda): " << lambda << endl;
	//std::cout << "in Optimize(log_cost): " << log_cost << endl;
	std::list<double> costsList;
	//std::cout << "in Optimize(cosltsList loop): " << endl;
	//for (auto cl : costsList)
	//{
	//	std::cout << cl << " ";
	//}
	Eigen::MatrixXd dw;
	//std::cout << "in Optimize(dw): " << dw << endl;
	double db = 0.0, cost = 0.0;

	for(int i=0; i<num_iter; i++){
	//	std::cout << "in Optimize(for prop loop, W): " << W << endl;
	//	std::cout << "in Optimize(for prop loop, b): " << b << endl;
		//std::cout << "in Optimize(for prop loop, X): " << X << endl;
	//	std::cout << "in Optimize(for prop loop, y): " << y << endl;
		std::cout << "in Optimize(for prop loop, lambda): " << lambda << endl;
		std::tuple<Eigen::MatrixXd, double, double> propagate =
			Propagate(W, b, X, y, lambda);
		std::tie(dw, db, cost) = propagate;

		W = W - (learning_rate*dw).transpose();
	//	std::cout << "in Optimize(for loop, W) = W - learningRate*dw.transpose: " << W << endl;
		b = b - (learning_rate*db);
	//	std::cout << "in Optimize(for loop, b):=b-learningRade*db " << W << endl;
		if(i%100==0) {
		//	std::cout << "in Optimize(if i%100==0 costList.pushback(cost)): " << cost<< endl;
			costsList.push_back(cost);
		}

		if(log_cost && i%100==0) {
			std::cout << "Cost after iteration " << i << ": " << cost << std::endl;
		}
	}

	return std::make_tuple(W,b,dw,db,costsList);
}

inline Eigen::MatrixXd
LogisticRegression::Predict(Eigen::MatrixXd W, double b, Eigen::MatrixXd X)const
{
	//std::cout << "in Predict(W): " << W << endl;
	//std::cout << "in Predict(b): " << b << endl;
	//std::cout << "in Predict(X): " << W << endl;
	const int m = static_cast<int>( X.rows());
	//std::cout << "in Predict(m): " << m << endl;


	Eigen::MatrixXd y_pred = Eigen::VectorXd::Zero(m).transpose();
	//std::cout << "in Predict(y_pred): " << y_pred << endl;

	Eigen::MatrixXd Z = (W.transpose() * X.transpose()).array() + b;
	//std::cout << "in Predict(Z): " << Z << endl;
	Eigen::MatrixXd A = 1 / (1 + (-Z.array()).exp());//Sigmoid(Z);
	//std::cout << "in Predict(A): " << A << endl;

	for(int i=0; i<A.cols(); i++) {
		if(A(0,i) <= 0.5) {
			y_pred(0,i) = 0;
		} else {
			y_pred(0,i) = 1;
		}
	}
	//std::cout << "in Predict(y_pred.transpose): " << y_pred.transpose() << endl;
	return y_pred.transpose();
}