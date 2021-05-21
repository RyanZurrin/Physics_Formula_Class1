#pragma once
#include <vector>
#include <Eigen>

template<class T>
class VectorNd
{
public:
	VectorNd();
	explicit VectorNd(...);

private:
	std::vector<T> vector_;
};

template <class T>
VectorNd<T>::VectorNd()
{
	vector_ = new std::vector<T>(0, 0, 0, 0);
}

template <class T>
VectorNd<T>::VectorNd(...)
{

}