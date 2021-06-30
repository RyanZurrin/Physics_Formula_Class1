#pragma once
#include <iostream>


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