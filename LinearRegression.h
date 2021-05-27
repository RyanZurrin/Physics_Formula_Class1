#pragma once
#ifndef LinearRegression_h
#define LinearRegression_h

#include <Eigen/Dense>
//α=224,ß=225,π=227,Σ=228,σ=229,µ=230,τ=231,Φ=232,Θ=233
//Ω=234,δ=235,∞=236,φ=237,ε=238,∩=239,≡=240,Γ=226,γ, σ, ϑ, Å, Ώ, λ, γ
/**
 * @class LinearRegression
 * @details
 * dateBuilt  5/26/2021
 * lastEdit 5/26/2021
 */
class LinearRegression
{

public:
	LinearRegression()
	{}

	/// <summary>
	/// Ordianry least squares (OLS) used to find the slope m of a data set
	/// </summary>
	/// <param name="X">The x.</param>
	/// <param name="y">The y.</param>
	/// <param name="theta">The theta.</param>
	/// <returns></returns>
	float OLS_Cost(Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::MatrixXd theta);
	std::tuple<Eigen::VectorXd,std::vector<float>> GradientDescent(Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::VectorXd theta, float alpha, int iters);
	float RSquared(Eigen::MatrixXd y, Eigen::MatrixXd y_hat);
};

#endif

float LinearRegression::OLS_Cost(Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::MatrixXd theta){

	Eigen::MatrixXd inner = pow(((X*theta)-y).array(),2);

	return inner.sum()/(2*X.rows());
}

std::tuple<Eigen::VectorXd,std::vector<float>> LinearRegression::GradientDescent(Eigen::MatrixXd X, Eigen::MatrixXd y, Eigen::VectorXd theta, float alpha, int iters){

	Eigen::MatrixXd temp = theta;

	int parameters = theta.rows();

	std::vector<float> cost;
	cost.push_back(OLS_Cost(X,y,theta));

	for(int i=0; i<iters; ++i){
		Eigen::MatrixXd error = X*theta - y;
		for(int j=0; j<parameters; ++j){
			Eigen::MatrixXd X_i = X.col(j);
			Eigen::MatrixXd term = error.cwiseProduct(X_i);
			temp(j,0) = theta(j,0) - ((alpha/X.rows())*term.sum());
		}
		theta = temp;
		cost.push_back(OLS_Cost(X,y,theta));
	}

	return std::make_tuple(theta,cost);
}

float LinearRegression::RSquared(Eigen::MatrixXd y, Eigen::MatrixXd y_hat){
	std::cout << "in Rsq - y:" << y << std::endl;
	std::cout << "in Rsq - yhat: " << y_hat << std::endl;
	auto num = pow((y-y_hat).array(),2).sum();
	std::cout << "in Rsq num: " << num << std::endl;
	auto den = pow(y.array()-y.mean(),2).sum();
	std::cout << "in Rsq den: " << den << std::endl;
	return 1 - num/den;
}