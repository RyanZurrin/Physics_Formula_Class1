#pragma once
#include <algorithm> // for std::swap
#include <cstddef>
#include <cassert>
#include <vector>
#include <iostream>
// Matrix traits: This describes how a matrix is accessed. By
// externalizing this information into a traits class, the same code
// can be used both with native arrays and matrix classes. To use the
// default implementation of the traits class, a matrix type has to
// provide the following definitions as members:
//
// * typedef ... index_type;
//   - The type used for indexing (e.g. size_t)
// * typedef ... value_type;
//   - The element type of the matrix (e.g. double)
// * index_type min_row() const;
//   - returns the minimal allowed row index
// * index_type max_row() const;
//   - returns the maximal allowed row index
// * index_type min_column() const;
//   - returns the minimal allowed column index
// * index_type max_column() const;
//   - returns the maximal allowed column index
// * value_type& operator()(index_type i, index_type k)
//   - returns a reference to the element i,k, where
//     min_row() <= i <= max_row()
//     min_column() <= k <= max_column()
// * value_type operator()(index_type i, index_type k) const
//   - returns the value of element i,k
//
// Note that the functions are all inline and simple, so the compiler
// should completely optimize them away.
template<typename MatrixType> struct matrix_traits
{
  typedef typename MatrixType::index_type index_type;
  typedef typename MatrixType::value_type value_type;
  static index_type min_row(MatrixType const& A)
  { return A.min_row(); }
  static index_type max_row(MatrixType const& A)
  { return A.max_row(); }
  static index_type min_column(MatrixType const& A)
  { return A.min_column(); }
  static index_type max_column(MatrixType const& A)
  { return A.max_column(); }
  static value_type& element(MatrixType& A, index_type i, index_type k)
  { return A(i,k); }
  static value_type element(MatrixType const& A, index_type i, index_type k)
  { return A(i,k); }
};

// specialization of the matrix traits for built-in two-dimensional
// arrays
template<typename T, std::size_t rows, std::size_t columns>
 struct matrix_traits<T[rows][columns]>
{
  typedef std::size_t index_type;
  typedef T value_type;
  static index_type min_row(T const (&)[rows][columns])
  { return 0; }
  static index_type max_row(T const (&)[rows][columns])
  { return rows-1; }
  static index_type min_column(T const (&)[rows][columns])
  { return 0; }
  static index_type max_column(T const (&)[rows][columns])
  { return columns-1; }
  static value_type& element(T (&A)[rows][columns],
							 index_type i, index_type k)
  { return A[i][k]; }
  static value_type element(T const (&A)[rows][columns],
							index_type i, index_type k)
  { return A[i][k]; }
};

// Swap rows i and k of a matrix A
// Note that due to the reference, both dimensions are preserved for
// built-in arrays
template<typename MatrixType>
 void swap_rows(MatrixType& A,
				 typename matrix_traits<MatrixType>::index_type i,
				 typename matrix_traits<MatrixType>::index_type k)
{
  matrix_traits<MatrixType> mt;
  typedef typename matrix_traits<MatrixType>::index_type index_type;

  // check indices
  assert(mt.min_row(A) <= i);
  assert(i <= mt.max_row(A));

  assert(mt.min_row(A) <= k);
  assert(k <= mt.max_row(A));

  for (index_type col = mt.min_column(A); col <= mt.max_column(A); ++col)
	std::swap(mt.element(A, i, col), mt.element(A, k, col));
}

// divide row i of matrix A by v
template<typename MatrixType>
 void divide_row(MatrixType& A,
				  typename matrix_traits<MatrixType>::index_type i,
				  typename matrix_traits<MatrixType>::value_type v)
{
  matrix_traits<MatrixType> mt;
  typedef typename matrix_traits<MatrixType>::index_type index_type;

  assert(mt.min_row(A) <= i);
  assert(i <= mt.max_row(A));

  assert(v != 0);

  for (index_type col = mt.min_column(A); col <= mt.max_column(A); ++col)
	mt.element(A, i, col) /= v;
}

// in matrix A, add v times row k to row i
template<typename MatrixType>
 void add_multiple_row(MatrixType& A,
				  typename matrix_traits<MatrixType>::index_type i,
				  typename matrix_traits<MatrixType>::index_type k,
				  typename matrix_traits<MatrixType>::value_type v)
{
  matrix_traits<MatrixType> mt;
  typedef typename matrix_traits<MatrixType>::index_type index_type;

  assert(mt.min_row(A) <= i);
  assert(i <= mt.max_row(A));

  assert(mt.min_row(A) <= k);
  assert(k <= mt.max_row(A));

  for (index_type col = mt.min_column(A); col <= mt.max_column(A); ++col)
	mt.element(A, i, col) += v * mt.element(A, k, col);
}

// convert A to reduced row echelon form
template<typename MatrixType>
 void to_reduced_row_echelon_form(MatrixType& A)
{
  matrix_traits<MatrixType> mt;
  typedef typename matrix_traits<MatrixType>::index_type index_type;

  index_type lead = mt.min_row(A);

  for (index_type row = mt.min_row(A); row <= mt.max_row(A); ++row)
  {
	if (lead > mt.max_column(A))
	  return;
	index_type i = row;
	while (mt.element(A, i, lead) == 0)
	{
	  ++i;
	  if (i > mt.max_row(A))
	  {
		i = row;
		++lead;
		if (lead > mt.max_column(A))
		  return;
	  }
	}
	swap_rows(A, i, row);
	divide_row(A, row, mt.element(A, row, lead));
	for (i = mt.min_row(A); i <= mt.max_row(A); ++i)
	{
	  if (i != row)
		add_multiple_row(A, i, row, -mt.element(A, i, lead));
	}
  }
}

template<typename MatrixType>
void print_matrix(MatrixType m, int rows, int cols)
{
	std::cout << right << setprecision(4) << std::endl;
	for (size_t r = 0; r < rows; r++)
	{
		for (size_t c = 0; c < cols; c++)
		{
			std::cout<<setw(7)<<right << m[r][c] << '\t';
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}



template <typename T> class MatrixND;
template <typename T> std::ostream& operator<<(std::ostream& os, const MatrixND<T>& rhs);



template<typename T>
class MatrixND
{
	int rows;
	int cols;
	std::vector<T> data;


public:
	MatrixND();

	template<typename ... Args>
	explicit MatrixND(const int& r_, const int& c_, const T& first, const Args&... args);

	MatrixND(std::vector<T>, int rows, int cols);
	void set(std::vector<T>, int rows, int cols);
	//Matrix(const Matrix<T>&);

	void print();
	MatrixND<T> transpose();
	MatrixND<T> dot(const MatrixND<T> &);
	MatrixND<T> add(const MatrixND<T> &);
	MatrixND<T> sub(const MatrixND<T> &);
	MatrixND<T> mult(const MatrixND<T> &);
	MatrixND<T> mult(const T &);
	bool isEqual(const MatrixND<T> &);
	MatrixND<T> concat(const MatrixND<T> &);
	MatrixND<T> stack(const MatrixND<T> &);
	MatrixND<T> kronecker(const MatrixND<T> &);

	int getRows()const;
	int getCols()const;


	MatrixND<T> operator+(const MatrixND<T> &);
	MatrixND<T> operator-(const MatrixND<T> &);
	MatrixND<T> operator*(const MatrixND<T> &);
	MatrixND<T> operator*(const T &);
	bool operator==(const MatrixND<T> &);


	template <typename T>
	friend ostream& operator<<(ostream& os, const MatrixND<T>& rhs);


	/*
	MatrixND& operator+=(T a);
	MatrixND& operator-=(T a);
	MatrixND& operator*=(T a);
	MatrixND& operator/=(T a);

	MatrixND& operator+=(MatrixND const& a);
	MatrixND& operator-=(MatrixND const& a);

	MatrixND operator-() const; // unary negation

	// free functions:

	MatrixND<T> operator+(MatrixND<T> const& a, T b);
	MatrixND<T> operator-(MatrixND<T> const& a, T b);
	MatrixND<T> operator*(MatrixND<T> const& a, T b);
	MatrixND<T> operator/(MatrixND<T> const& a, T b);

	MatrixND<T> operator+(T a, MatrixND<T> const& b);
	MatrixND<T> operator-(T a, MatrixND<T> const& b);
	MatrixND<T> operator*(T a, MatrixND<T> const& b);
	MatrixND<T> operator/(T a, MatrixND<T> const& b);

	MatrixND<T> operator+(MatrixND<T> const& a, MatrixND<T> const& b);
	MatrixND<T> operator-(MatrixND<T> const& a, MatrixND<T> const& b);

	MatrixND<T> operator*(MatrixND<T> const& a, MatrixND<T> const& b);

	Vector<T> operator*(MatrixND<T> const& a, Vector<T> const& b);
	Vector<T> operator*(Vector<T> const& a, MatrixND<T> const& b);
	*/

	~MatrixND();

};

/** Default Constructor

	creates an empty matrix

*/

template <typename T>
MatrixND<T>::MatrixND()
{
	data.clear();
	rows = 0;
	cols = 0;
}


template<typename T>
template<typename ...Args>
MatrixND<T>::MatrixND(const int& r_, const int& c_, const T& first, const Args & ...args)
{
	data.clear();
	rows = r_;
	cols = c_;
	auto total = rows * cols;
	data.push_back(first);
	int dummy[] = { 0, (data.push_back(args), 0)... };
	(void)dummy;
	for (const auto& i : data)
	{
		if(i<=total)
		{
			data.push_back(i);
		}
	}


}

/** Constructor

	creates the matrix as the following:

	@params elements, - the elements of the matrix in Row-major form
			numRows, - the number of rows in the matrix
			numCols; - the number of coumns in the matrix

*/

template <typename T>
MatrixND<T>::MatrixND(std::vector<T> elements, int numRows, int numCols)
{
	rows = numRows;
	cols = numCols;
	data.clear();
	for(unsigned int i = 0; i < elements.size(); i++) {
		data.push_back(elements[i]);
	}
}




/** set

	resets the matrix to the input

	@params elements, - the elements of the matrix in Row-major form
			numRows, - the number of rows in the matrix
			numCols; - the number of coumns in the matrix
	@return void; nothing to return

*/

template <typename T>
void MatrixND<T>::set(std::vector<T> elements, int numRows, int numCols)
{
	rows = numRows;
	cols = numCols;
	data.clear();
	for(unsigned int i = 0; i < elements.size(); i++) {
		data.push_back(elements[i]);
	}
}


/** operator+ (add)
	lhs + rhs;
	elementwise adition of rhs to lhs

	@params rhs; the matrix to add
	@return matrix; the sum

*/

template <typename T>
MatrixND<T> MatrixND<T>::operator+(const MatrixND<T> & rhs)
{
	return this->add(rhs);
}


/** operator- (subtract)
	lhs - rhs;
	elementwise subtraction of rhs from lhs

	@params rhs; the matrix to subtract
	@return matrix; the difference

*/

template <typename T>
MatrixND<T> MatrixND<T>::operator-(const MatrixND<T> & rhs)
{
	return this->sub(rhs);
}



/** operator(*) dot product
	lhs * rhs;
	https://en.wikipedia.org/wiki/Matrix_multiplication
	calculate dot product of a matrix

	@params rhs; the second matrix
	@return matrix; the transformed product matrix

*/
template <typename T>
MatrixND<T> MatrixND<T>::operator*(const MatrixND<T> & rhs)
{
	return this->dot(rhs);
}

/** operator* (scalar multiplication)
	M<T> * T;
	calculate scalar product of a matrix

	@params rhs; the scalar;
	@return matrix; the transformed product matrix

*/
template <typename T>
MatrixND<T> MatrixND<T>::operator*(const T & T)
{
	return this->mult(T);
}

/** operator ==

	elemetnwise comparison of two matrices of equal size

	@params rhs; the second matrix
	@return bool; true if same size and elements all equal

*/
template <typename T>
bool MatrixND<T>::operator==(const MatrixND<T> & rhs)
{
	return this->isEqual(rhs);
}

template<typename T>
inline MatrixND<T>::~MatrixND() = default;
/* ostream operator

	adds elements to output stream
	formatted
	 e11, e12
	 e21, e22

	 @params os, rhs; ostream refernece and matrix to output
	 @return os, ostream reference

*/
template<typename T>
 std::ostream& operator<<(std::ostream& os, const MatrixND<T>& rhs)
{
	 auto total = rhs.rows * rhs.cols;
	for (size_t i = 0; i < total; i++) {
		os << setw(5) << left << rhs.data[i] << "  ";
		if ((i + 1) % rhs.cols == 0)
			os << std::endl;
	}
	return os;
}

/**
 *isEqual
 *
 * element wise comparison of two matrices of equal size
 *
 *@params rhs; the second matrix
 *@return bool; true if same size and elements all equal
*/
template <typename T>
bool MatrixND<T>::isEqual(const MatrixND<T> & rhs)
{


	if(rows != rhs.rows || cols != rhs.cols) {
		return false;
	}

	for(unsigned int i = 0; i < data.size(); i++) {
		if(data[i] != rhs.data[i])
			return false;
	}

	return true;
}

/** add

	elementwise adition of rhs to lhs

	@params rhs; the matrix to add
	@return matrix; the sum

*/

template <typename T>
MatrixND<T> MatrixND<T>::add(const MatrixND<T> & rhs)
{


	if(rows != rhs.rows || cols != rhs.cols) {
		MatrixND<T> matrix;
		return matrix;
	}

	std::vector<T> vec;
	for(unsigned int i = 0; i < data.size(); i++) {
		vec.push_back(data[i] + rhs.data[i]);
	}

	return MatrixND<T>(vec,rows,cols);
}

/** dot product
	https://en.wikipedia.org/wiki/Matrix_multiplication
	calculate dot product of a matrix

	@params rhs; the second matrix
	@return matrix; the transformed product matrix

*/

template <typename T>
MatrixND<T> MatrixND<T>::dot(const MatrixND<T> & rhs)
{
	if(cols != rhs.rows) {
		std::cout << "Error! Can not resolve dot product on these matrices!"
				  << std::endl;
		std::cout << "Requested: [" << rows << "x" << cols << "] <alt+7> ["
				  << rhs.rows << "x" << rhs.cols << "]" << std::endl;
		MatrixND<T> matrix;
		return matrix;
	}

	std::vector<T> vec;
	T sum = 0;
	for(int j = 0; j < rows; j++) {
		for(int k = 0; k < rhs.cols; k++) {
			for(int i = 0; i < cols; i++) {
				sum += data[i+j*cols] * rhs.data[k+i*rhs.cols];
			}
			vec.push_back(sum);
			sum = 0;
		}
	}
	return MatrixND(vec,rows,rhs.cols);
}

/** multiplication (Hardamard Product)
	https://en.wikipedia.org/wiki/Hadamard_product_(matrices)
	calculate elemetnwise product of a matrix

	@params rhs; the second matrix
	@return matrix; the transformed product matrix

*/

template <typename T>
MatrixND<T> MatrixND<T>::mult(const MatrixND<T> & rhs)
{
	if(rows != rhs.rows || cols != rhs.cols) {
		MatrixND<T> matrix;
		return matrix;
	}

	std::vector<T> vec;
	for(unsigned int i = 0; i < data.size(); i++) {
		vec.push_back(data[i] * rhs.data[i]);
	}

	return MatrixND<T>(vec,rows,cols);
}

/** multiplication (scalar)

	calculate scalar product of a matrix

	@params rhs; the scalar;
	@return matrix; the transformed product matrix

*/

template <typename T>
MatrixND<T> MatrixND<T>::mult(const T & scalar)
{

	std::vector<T> vec;
	for(unsigned int i = 0; i < data.size(); i++) {
		vec.push_back(data[i] * scalar);
	}

	return MatrixND<T>(vec,rows,cols);
}

/** subtract

	elementwise subtraction of rhs from lhs

	@params rhs; the matrix to subtract
	@return matrix; the difference

*/

template <typename T>
MatrixND<T> MatrixND<T>::sub(const MatrixND<T> & rhs)
{
	if(rows != rhs.rows || cols != rhs.cols) {
		MatrixND<T> matrix;
		return matrix;
	}

	std::vector<T> vec;
	for(unsigned int i = 0; i < data.size(); i++) {
		vec.push_back(data[i] - rhs.data[i]);
	}

	return MatrixND<T>(vec,rows,cols);
}

template <typename T>
void MatrixND<T>::print()
{
	const auto total = rows * cols;
	for(unsigned int i = 0; i < total; i++) {
		std::cout<< setw(5) << left << data[i];
		if((i+1) % cols == 0)
			std::cout << std::endl;
	}
}


/** transpose

	Calculate transpose of matrix

	@return matrix; the transpose of this matrix

*/

template <typename T>
MatrixND<T> MatrixND<T>::transpose()
{
	std::vector<T> vec;
	for(unsigned int i = 0; i < data.size(); i++) {
		vec.push_back(data[(cols*(i%rows)+i/rows)]);
	}
	return Matrix<T>(vec, cols, rows);
}

/** Concat

	append two matrices of equal row count

	@params rhs; the matrix to concatanate
	@return matrix; the contanated matrix

*/

template <typename T>
MatrixND<T> MatrixND<T>::concat(const MatrixND<T> & rhs)
{

	if(rows != rhs.rows)
		return MatrixND<T>(*this);

	std::vector<T> vec;
	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < cols; j++) {
			vec.push_back(data[i*cols + j]);
		}
		for(int j = 0; j < rhs.cols; j++) {
			vec.push_back(rhs.data[i*rhs.cols + j]);
		}
	}

	return MatrixND<T>(vec,rows,cols+rhs.cols);
}

/** stack

	append two matrices of equal column count

	@params rhs; the matrix to stack below
	@return matrix; the lhs stacked ontop of rhs matrix

*/

template <typename T>
MatrixND<T> MatrixND<T>::stack(const MatrixND<T> & rhs)
{
	if(cols != rhs.cols)
		return MatrixND<T>(*this);

	std::vector<T> vec;

	for(unsigned int i = 0; i < data.size(); i++) {
		vec.push_back(data[i]);
	}
	for(unsigned int i = 0; i < rhs.data.size(); i++) {
		vec.push_back(rhs.data[i]);
	}

	return MatrixND<T>(vec,rows+rhs.rows,cols);
}

/** Kronecker
	https://en.wikipedia.org/wiki/Kronecker_product
	calculate kroncker product of two matrices

	@params rhs; the matrix operand
	@return matrix; the Kronecker product matrix

*/

template <typename T>
MatrixND<T> MatrixND<T>::kronecker(const MatrixND<T> & rhs)
{
	std::vector<T> vec;

	for(int i = 0; i < (rows*cols*rhs.rows*rhs.cols); i++) {
		int j = (i/rhs.cols)%cols + (i/(cols*rhs.rows*rhs.cols))*cols; //iterate lhs in proper order
		int k = (i%rhs.cols) + ((i / (cols * rhs.cols))%rhs.rows)*rhs.cols;  //iterate rhs in proper order
		//can use scalar multiplactions, matrix concat and stacking, but this is a single iteration through the vector.
		//Kronecker iterates both matrices in a pattern relative to the large product matrix.
		//std::cout << i << " : " << j << " : " << k << std::endl;
		//std::cout << i << " : " << j << " : " << k << " : " << l << std::endl;
		vec.push_back(data[j]*rhs.data[k]);
	}

	return MatrixND<T>(vec,rows*rhs.rows,cols*rhs.cols);
}

template <typename T>
int MatrixND<T>::getRows()const
{
	return rows;
}

template <typename T>
int MatrixND<T>::getCols()const
{
	return cols;
}



