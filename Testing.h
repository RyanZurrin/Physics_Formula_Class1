#pragma once
#pragma warning(suppress : 4996)

#include <iostream>
#include <any>
#include <chrono>
template <typename T>
auto add(T value)
{
	return value;
}


template<typename T, typename... Ts>
auto add(T head, Ts... rest)
{
	return head + add(rest...);
}


template<typename... T>
auto make_even_tuple(T... a)
{
	static_assert(sizeof...(a) % 2 == 0,
		"expected an even number of arguments");
	std::tuple<T...> t{ a... };

	return t;
}


//left folding wit a unary form (... op pack):
template <typename... Ts>
auto add(Ts... args)
{
	return (... + args);
}

//left folding with a binary form (init op ... op pack):
template <typename... Ts>
auto add_to_one(Ts... args)
{
	return (1 + ... + args);
}
/*
//right folding wit a unary form (pack op ...):
template <typename... Ts>
auto add(Ts... args)
{
	return (args + ...);
}

//right folding with a binary form (pack op ... op init):
template <typename... Ts>
auto add_to_one(Ts... args)
{
	return (args + ... + 1);
}

*/

template <typename T>
struct wrapper
{
	T const& value;
};

template <typename T>
constexpr auto operator<(wrapper<T> const & lhs,
						 wrapper<T> const & rhs)
{
	return wrapper<T> {
		lhs.value < rhs.value ? lhs.value : rhs.value};
}

template <typename... Ts>
constexpr auto min(Ts&&... args)
{
	return (wrapper<Ts>{args} < ...).value;
}


inline void log(std::any const & value)
{
	if (value.has_value())
	{
		auto const& tv = value.type();
		if (tv == typeid(int))
		{
			std::cout << std::any_cast<int>(value) << '\n';
		}
		else if (tv == typeid(std::string))
		{
			std::cout << std::any_cast<std::string>(value) << '\n';
		}
		else if (tv == typeid(double))
		{
			std::cout << std::fixed << std::setprecision(2) << std::any_cast<double>(value) << '\n';
		}
		else if (tv == typeid(char))
		{
			std::cout << std::any_cast<char>(value) << '\n';
		}
		else if (tv == typeid(std::chrono::time_point<std::chrono::system_clock>))
		{
			auto t = std::any_cast<std::chrono::time_point<std::chrono::system_clock>>(value);
			auto now = std::chrono::system_clock::to_time_t(t);
			std::cout << std::put_time(std::localtime(&now), "%F %T")
				<< '\n';
		}
		else
		{
			std::cout << "Unexpected value type: " << '\n';
		}
	}
	else
	{
		std::cout << "(empty)" << '\n';
	}
}