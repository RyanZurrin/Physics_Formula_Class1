#pragma once


#include "Vector2D.h"
#include "VectorND.h"
#include <Eigen/Eigen>
#include <gsl/gsl_blas.h>




template<typename VECTOR>
auto dot_product(VECTOR& v, VECTOR& u)
{
	return v.dot_product(u);
}

template<typename VECTOR>
VECTOR cross_product(VECTOR& v, VECTOR& u)
{
	return v.cross_product(u);
}