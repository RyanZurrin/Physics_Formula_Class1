#ifndef ETL_H
#define ETL_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <Eigen/Dense>
#include <vector>
#include <cmath>
#include <boost/algorithm/string.hpp>

//α=224,ß=225,π=227,Σ=228,σ=229,µ=230,τ=231,Φ=232,Θ=233
//Ω=234,δ=235,∞=236,φ=237,ε=238,∩=239,≡=240,Γ=226,γ, σ, ϑ, Å, Ώ, λ, γ
/**
 * @class ETL
 * @details Extract transform and load, class for reading in data from a csv
 * file and transforms it for use in machine learning and data analysis
 * @author AI coding, implemented by Ryan Zurrin
 * dateBuilt  5/26/2021
 * lastEdit 5/26/2021
 */

class ETL
{
	std::string dataset;
	std::string delimiter;
	bool header;

public:
	ETL()
	{
		dataset = "";
		delimiter = " ";
		header = false;
	}
	ETL(std::string data, std::string separator, bool head) : dataset(data), delimiter(separator), header(head)
	{}

	std::vector<std::vector<std::string>> readCSV();
	Eigen::MatrixXd CSVtoEigen(std::vector<std::vector<std::string>> dataset, int rows, int cols);

	Eigen::MatrixXd Normalize(Eigen::MatrixXd data, bool normalizeTarget);
	//auto Mean(Eigen::MatrixXd data) -> decltype(data.colwise().mean());
	//auto Std(Eigen::MatrixXd data) -> decltype(((data.array().square().colwise().sum())/(data.rows()-1)).sqrt());

	std::tuple<Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd> TrainTestSplit(Eigen::MatrixXd data, float train_size);

	void Vectortofile(std::vector<float> vector, std::string filename);
	void EigentoFile(Eigen::MatrixXd data, std::string filename);
};

#endif

std::vector<std::vector<std::string>> ETL::readCSV()
{

	std::ifstream file(dataset);
	std::vector<std::vector<std::string>> dataString;

	std::string line = "";

	while(getline(file,line)){
		std::vector<std::string> vec;
		boost::algorithm::split(vec,line,boost::is_any_of(delimiter));
		dataString.push_back(vec);
	}

	file.close();

	return dataString;
}

Eigen::MatrixXd ETL::CSVtoEigen(std::vector<std::vector<std::string>>
	dataset, int rows, int cols)
{

	if(header==true){
		rows = rows - 1;
	}

	Eigen::MatrixXd mat(cols,rows);
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; ++j){
			mat(j,i) = atof(dataset[i][j].c_str());
		}
	}

	return mat.transpose();
}

std::tuple<Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd,Eigen::MatrixXd>
ETL::TrainTestSplit(Eigen::MatrixXd data, float train_size)
{

	int rows = data.rows();
	int train_rows = round(train_size*rows);
	int test_rows = rows - train_rows;

	Eigen::MatrixXd train = data.topRows(train_rows);

	Eigen::MatrixXd X_train = train.leftCols(data.cols()-1);
	Eigen::MatrixXd y_train = train.rightCols(1);

	Eigen::MatrixXd test = data.bottomRows(test_rows);

	Eigen::MatrixXd X_test = test.leftCols(data.cols()-1);
	Eigen::MatrixXd y_test = test.rightCols(1);

	return std::make_tuple(X_train, y_train, X_test, y_test);
}

auto Mean(Eigen::MatrixXd data) -> decltype(data.colwise().mean()){
	return data.colwise().mean();
}

auto Std(Eigen::MatrixXd data) ->
decltype(((data.array().square().colwise().sum())/(data.rows()-1)).sqrt())
{
	return ((data.array().square().colwise().sum())/(data.rows()-1)).sqrt();
}

Eigen::MatrixXd ETL::Normalize(Eigen::MatrixXd data, bool normalizeTarget)
{
	Eigen::MatrixXd dataNorm;
	if(normalizeTarget==true) {
		dataNorm = data;
	} else {
		dataNorm = data.leftCols(data.cols()-1);
	}

	auto mean = dataNorm.colwise().mean();
	Eigen::MatrixXd scaled_data = dataNorm.rowwise() - mean;
	auto std = ((scaled_data.array().square().colwise().sum()) / 
		(scaled_data.rows() - 1)).sqrt();

	Eigen::MatrixXd norm = scaled_data.array().rowwise()/std;

	if(normalizeTarget==false) {
		norm.conservativeResize(norm.rows(), norm.cols()+1);
		norm.col(norm.cols()-1) = data.rightCols(1);
	}

	return norm;
}

void ETL::Vectortofile(std::vector<float> vector, std::string filename)
{
	std::ofstream output_file(filename);
	std::ostream_iterator<float> output_iterator(output_file, "\n");
	std::copy(vector.begin(), vector.end(), output_iterator);
}

void ETL::EigentoFile(Eigen::MatrixXd data, std::string filename)
{
	std::ofstream output_file(filename);
	if(output_file.is_open()){
		output_file << data << "\n";
	}
}