#pragma once
#ifndef VECTOR_ND_H
#define VECTOR_ND_H
#include <cstdarg>
#include <Eigen/Eigen>
#define ll long long



using namespace std;

// Template class to create vector of
// different data_type
template <typename T>
class VectorNd {


public:
	explicit VectorNd(ll = 100);

	template<typename ... Args>
	VectorNd(const T& first, const Args&... args);

	// Function that returns the number of
	// elements in array after pushing the data
	ll push_back(T);

	// function that returns the popped element
	T pop_back();

	template<typename... Args>
	void addValuesToVector(const T& first, const Args&... args);

	void display_vector()const;

	// Function that return the size of vector
	ll size() const;
	T& operator[](ll);
	Eigen::VectorX<T> vec;
	// Iterator Class
	class iterator {

	public:
		explicit iterator()
			: ptr(nullptr)
		{
		}
		explicit iterator(T* p)
			: ptr(p)
		{
		}
		bool operator==(const iterator& rhs) const
		{
			return ptr == rhs.ptr;
		}
		bool operator!=(const iterator& rhs) const
		{
			return !(*this == rhs);
		}
		T operator*() const
		{
			return *ptr;
		}
		iterator& operator++()
		{
			++ptr;
			return *this;
		}
		iterator operator++(int)
		{
			iterator temp(*this);
			++*this;
			return temp;
		}
	private:
		// Dynamic array using pointers
		T* ptr;

	};

	// Begin iterator
	iterator begin() const;

	// End iterator
	iterator end() const;


	bool operator==(const VectorNd& v)const;
	bool operator!=(const VectorNd& v)const;
	bool operator>(const VectorNd& v)const;
	bool operator>=(const VectorNd& v)const;
	bool operator<(const VectorNd& v)const;
	bool operator<=(const VectorNd& v)const;
	VectorNd<T> operator+(const VectorNd &vec)const;    //addition
	VectorNd<T> operator+(VectorNd &vec)const;
	VectorNd<T> &operator+=(const VectorNd &vec);  ////assigning new result to the vector
	VectorNd<T> operator-(const VectorNd &vec);    //subtraction
	VectorNd<T> operator-(const T number)const;
	VectorNd<T> operator-()const;
	VectorNd<T> operator--();
	VectorNd<T> operator--(int);
	VectorNd<T> &operator-=(const VectorNd &vec);  //assigning new result to the vector
	VectorNd<T> operator*(T value);    //multiplication
	VectorNd<T> &operator*=(T value);  //assigning new result to the vector.
	VectorNd<T> &operator=(const VectorNd &vec);

private:
	T* arr;

	// Variable to store the current capacity
	// of the vector
	ll capacity;

	// Variable to store the length of the
	// vector
	ll length;
};
#endif

// Template class to return the size of
// vector of different data_type
template <typename T>
VectorNd<T>::VectorNd(ll n)
	: vec(Eigen::VectorX<T>(n)), arr(new T[100]), capacity(100),length(0)
{
}

template<typename T>
template<typename ...Args>
inline VectorNd<T>::VectorNd(const T& first, const Args & ...args)
	:VectorNd()
{
	vector<T> container;
	container.push_back(first);
	int dummy[] = { 0, (container.push_back(args), 0)... };
	(void)dummy;

	for (const auto& i : container)
	{
		this->push_back(i);
	}
}

template<typename T>
template<typename ...Args>
inline void VectorNd<T>::addValuesToVector(const T& first, const Args & ...args)
{
	vector<T> container;
	container.push_back(first);
	int dummy[] = { 0, (container.push_back(args), 0)... };
	(void)dummy;

	for (const auto &i : container)
	{
		this->push_back(i);
	}

}


// Template class to insert the element
// in vector
template <typename T>
ll VectorNd<T>::push_back(T data)
{
	if (length == capacity) {
		T* old = arr;
		arr = new T[capacity = capacity * 2];
		copy(old, old + length, arr);
		delete[] old;
	}
	arr[length++] = data;
	return length;
}

// Template class to return the popped element
// in vector
template <typename T>
T VectorNd<T>::pop_back()
{
	return arr[length-- - 1];
}

template<class T>
inline void VectorNd<T>::display_vector()const
{
	for (typename VectorNd::iterator ptr = this->begin(); ptr != this->end(); ++ptr) {
		cout << *ptr << ' ';
	}
	cout << '\n';

}

// Template class to return the size of
// vector
template <typename T>
ll VectorNd<T>::size() const
{
	return length;
}

// Template class to return the element of
// vector at given index
template <typename T>
T& VectorNd<T>::operator[](ll index)
{
	// if given index is greater than the
	// size of vector print Error
	if (index >= length) {
		cout << "Error: Array index out of bound";
		exit(0);
	}

	// else return value at that index
	return *(arr + index);
}

// Template class to return begin iterator
template <typename T>
typename VectorNd<T>::iterator
					  VectorNd<T>::begin() const
{
	return iterator(arr);
}

// Template class to return end iterator
template <typename T>
typename VectorNd<T>::iterator
						VectorNd<T>::end() const
{
	return iterator(arr + length);
}

template<typename T>
bool VectorNd<T>::operator==(const VectorNd& v) const
{
	return this->arr == v.arr;
}

template<typename T>
bool VectorNd<T>::operator!=(const VectorNd& v) const
{
	return this->arr != v.arr;
}

template<typename T>
bool VectorNd<T>::operator>(const VectorNd& v) const
{
	return this->arr > v.arr;
}

template<typename T>
bool VectorNd<T>::operator>=(const VectorNd& v) const
{
	return this->arr >= v.arr;
}

template<typename T>
bool VectorNd<T>::operator<(const VectorNd& v) const
{
	return this->arr < v.arr;
}

template<typename T>
bool VectorNd<T>::operator<=(const VectorNd& v) const
{
	return this->arr <= v.arr;
}

template<typename T>
VectorNd<T> VectorNd<T>::operator+(const VectorNd& vec) const
{
	VectorNd<T> temp(length);
	for (size_t i = 0; i < length; i++)
	{
		temp[i] = this->arr[i] + vec.arr[i];
	}
	return temp;
}

template <typename T>
VectorNd<T> VectorNd<T>::operator+(VectorNd& vec) const
{
	VectorNd<T> temp(length);
	for (size_t i = 0; i < length; i++)
	{
		temp[i] = this->arr[i] + vec.arr[i];
	}
	return temp;
}

template<typename T>
 VectorNd<T>& VectorNd<T>::operator+=(const VectorNd& vec)
{
	 for (size_t i = 0; i < length; i++)
	 {
		 this->arr[i] += vec.arr[i];
	 }
	 return *this;
}

 template<typename T>
 VectorNd<T> VectorNd<T>::operator-(const VectorNd& vec)
 {
	 VectorNd<T> temp;
	 for (size_t i = 0; i < length; i++)
	 {
		 temp.arr[i] = this->arr[i] - vec.arr[i];
	 }
	 return temp;
 }

 template<typename T>
 VectorNd<T> VectorNd<T>::operator-(const T number) const
 {
	 VectorNd<T> temp;
	 for (size_t i = 0; i < length; i++)
	 {
		 temp = this.arr[i] - number;
	 }
	 return temp;
 }

 template<typename T>
 inline VectorNd<T> VectorNd<T>::operator-() const
 {
	 VectorNd<T> temp;
	 for (size_t i = 0; i < length; i++)
	 {
		 temp.arr[i] = this->arr[-i];
	 }
	 return temp;
 }

 template<typename T>
 inline VectorNd<T> VectorNd<T>::operator--()
 {
	 VectorNd<T> temp;
	 for (size_t i = 0; i < length; i++)
	 {
		 temp.arr[i] = this->arr[--i];
	 }
	 return temp;
 }

 template<typename T>
 inline VectorNd<T> VectorNd<T>::operator--(int)
 {
	 VectorNd<T> temp;
	 for (size_t i = 0; i < length; i++)
	 {
		 temp.arr[i] = this->arr[i--];
	 }
	 return temp;
 }

 template<typename T>
 inline VectorNd<T>& VectorNd<T>::operator-=(const VectorNd& vec)
 {
	 for (size_t i = 0; i < length; i++)
	 {
		 this->arr[i] -= vec.arr[i];
	 }
	 return *this;
 }

 template<typename T>
 VectorNd<T> VectorNd<T>::operator*(T value)
 {
	 VectorNd<T> temp;
	 for (size_t i = 0; i < length; i++)
	 {
		 temp.arr[i] = this->arr[i] * value;
	 }
	 return VectorNd();
 }

 template<typename T>
 VectorNd<T>& VectorNd<T>::operator*=(T value)
 {
	 for (size_t i = 0; i < length; i++)
	 {
		 this.arr[i] *= value;
	 }
	 return *this;
 }

 template<typename T>
 inline VectorNd<T>& VectorNd<T>::operator=(const VectorNd& v)
 {
	 this->vec = v.vec;
	 this->length = v.length;
	 this->capacity = v.capacity;
	 for (size_t i = 0; i < length; i++)
	 {
		 this->arr[i] = v.arr[i];
	 }
	 return *this;
 }



// Template class to display element in
// vector
template <typename T>
void display_vector(T& v)
{
	// Declare iterator
	typename T::iterator ptr;
	for (ptr = v.begin(); ptr != v.end(); ++ptr) {
		cout << *ptr << ' ';
	}
	cout << '\n';
}




