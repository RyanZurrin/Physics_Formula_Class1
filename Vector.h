#pragma once
#include <array>
#include <iostream>
#include "Core.h"
namespace rez
{
#define DIM2 2
#define DIM3 3
#define X 0
#define Y 1
#define Z 2

	

	template<class coordinate_type, size_t dimension = DIM3>
	class Vector
	{
		static_assert(std::is_arithmetic_v<coordinate_type>, "Vector class can only store Integral or Floats");
		static_assert(dimension >= DIM2, "Vector dimension at least should be 2D");

		std::array<coordinate_type, dimension> coords;

		friend float dotProduct(const Vector<coordinate_type, dimension>& v1, const Vector<coordinate_type, dimension>& v2);

	public:
		Vector(){}
		Vector(std::array<coordinate_type, dimension> _coords) : coords(_coords) {}
		Vector(coordinate_type _x, coordinate_type _y, coordinate_type _z) : coords({_x,_y,_z}) {}
		Vector(coordinate_type _x, coordinate_type _y) : coords({ _x,_y }) {}

		bool operator==(const Vector<coordinate_type, dimension>&);
		bool operator!=(const Vector<coordinate_type, dimension>&);
		Vector<coordinate_type, dimension> operator+(const Vector<coordinate_type, dimension>&) const;
		Vector<coordinate_type, dimension> operator-(const Vector<coordinate_type, dimension>&) const;
		bool operator <(const Vector<coordinate_type, dimension>&);
		bool operator >(const Vector<coordinate_type, dimension>&);
		bool operator <=(const Vector<coordinate_type, dimension>&);
		bool operator >=(const Vector<coordinate_type, dimension>&);

		coordinate_type operator[](int) const;
		void assign(int dim, coordinate_type value);
	};

	typedef Vector<float, DIM2> Vector2f;
	typedef Vector<float, DIM3> Vector3f;
	//_______________________________________________________________________________________________________

	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator==(const Vector<coordinate_type, dimension>& _other)
	{
		for (size_t i = 0; i < dimension; i++)
		{
			if (!isEqualD(coords[i], _other.coords[i]))
			{
				return false;
			}
		}
		return true;
	}

	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator!=(const Vector<coordinate_type, dimension>& _other)
	{
		return !(*this == _other);
	}

	template<class coordinate_type, size_t dimension>
	inline Vector<coordinate_type, dimension> Vector<coordinate_type, dimension>::operator+(const Vector<coordinate_type, dimension>& _other) const
	{
		std::array<coordinate_type, dimension> temp_array;
		for (size_t i = 0; i < dimension; i++)
		{
			temp_array[i] = coords[i] + _other.coords[i];
		}
		return Vector<coordinate_type, dimension>(temp_array);
	}

	template<class coordinate_type, size_t dimension>
	inline Vector<coordinate_type, dimension> Vector<coordinate_type, dimension>::operator-(const Vector<coordinate_type, dimension>& _other) const
	{
		std::array<coordinate_type, dimension> temp_array;
		for (size_t i = 0; i < dimension; i++)
		{
			temp_array[i] = coords[i] - _other.coords[i];
		}
		return Vector<coordinate_type, dimension>(temp_array);
	}

	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator<(const Vector<coordinate_type, dimension>& _other)
	{
		for (size_t i = 0; i < dimension; i++)
		{
			if (this->coords[i] < _other.coords[i])
				return true;
			else if (this->coords[i] > _other.coords[i])
				return false;
		}
		return false;
	}

	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator>(const Vector<coordinate_type, dimension>& _other)
	{
		for (size_t i = 0; i < dimension; i++)
		{
			if (this->coords[i] > _other.coords[i])
				return true;
			else if (this->coords[i] < _other.coords[i])
				return false;
		}
		return false;
	}

	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator<=(const Vector<coordinate_type, dimension>& _other)
	{
		return false;
	}

	template<class coordinate_type, size_t dimension>
	inline bool Vector<coordinate_type, dimension>::operator>=(const Vector<coordinate_type, dimension>& _other)
	{
		return false;
	}

	template<class coordinate_type, size_t dimension>
	inline coordinate_type Vector<coordinate_type, dimension>::operator[](int _index) const
	{
		if (_index >= coords.size())
		{
			std::cout << "Index out of bounds\n";
			return -1;
		}
		return coords[_index];
	}

	template<class coordinate_type, size_t dimension>
	inline void Vector<coordinate_type, dimension>::assign(int dim, coordinate_type value)
	{
		if (dim >= coords.size())
		{
			std::cout << "Index out of bounds\n";
			return;
		}
		coords[dim] = value;
	}

	template<class coordinate_type, size_t dimension>
	float dotProduct(const Vector<coordinate_type, dimension>& v1, const Vector<coordinate_type, dimension>& v2)
	{
		if (v1.coords.size() != v2.coords.size())
			return FLT_MIN;

		float product = 0.0;
		for (size_t i = 0; i < dimension; i++)
		{
			product += v1[i] * v2[i];
		}
		return product;
	}

	float crossProduct2D(Vector2f v1, Vector2f v2);

	Vector3f crossProduct3D(Vector3f v1, Vector3f v2);


}
