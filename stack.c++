// stack standard header

// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#pragma once
#ifndef _STACK_
#define _STACK_
#include <yvals_core.h>
#if _STL_COMPILER_PREPROCESSOR
#include <deque>

#pragma pack(push, _CRT_PACKING)
#pragma warning(push, _STL_WARNING_LEVEL)
#pragma warning(disable : _STL_DISABLED_WARNINGS)
_STL_DISABLE_CLANG_WARNINGS
#pragma push_macro("new")
#undef new

_STD_BEGIN
// CLASS TEMPLATE stack
template <class _Ty, class _Container = deque<_Ty>>
class stack {
public:
    using value_type      = typename _Container::value_type;
    using reference       = typename _Container::reference;
    using const_reference = typename _Container::const_reference;
    using size_type       = typename _Container::size_type;
    using container_type  = _Container;

    static_assert(is_same_v<_Ty, value_type>, "container adaptors require consistent types");

    stack() = default;

    explicit stack(const _Container& _Cont) : c(_Cont) {}

    explicit stack(_Container&& _Cont) noexcept(is_nothrow_move_constructible_v<_Container>) // strengthened
        : c(_STD move(_Cont)) {}

    template <class _Alloc, enable_if_t<uses_allocator_v<_Container, _Alloc>, int> = 0>
    explicit stack(const _Alloc& _Al) noexcept(is_nothrow_constructible_v<_Container, const _Alloc&>) // strengthened
        : c(_Al) {}

    template <class _Alloc, enable_if_t<uses_allocator_v<_Container, _Alloc>, int> = 0>
    stack(const _Container& _Cont, const _Alloc& _Al) : c(_Cont, _Al) {}

    template <class _Alloc, enable_if_t<uses_allocator_v<_Container, _Alloc>, int> = 0>
    stack(_Container&& _Cont, const _Alloc& _Al) noexcept(
        is_nothrow_constructible_v<_Container, _Container, const _Alloc&>) // strengthened
        : c(_STD move(_Cont), _Al) {}

    template <class _Alloc, enable_if_t<uses_allocator_v<_Container, _Alloc>, int> = 0>
    stack(const stack& _Right, const _Alloc& _Al) : c(_Right.c, _Al) {}

    template <class _Alloc, enable_if_t<uses_allocator_v<_Container, _Alloc>, int> = 0>
    stack(stack&& _Right, const _Alloc& _Al) noexcept(
        is_nothrow_constructible_v<_Container, _Container, const _Alloc&>) // strengthened
        : c(_STD move(_Right.c), _Al) {}

    _NODISCARD bool empty() const noexcept(noexcept(c.empty())) /* strengthened */ {
        return c.empty();
    }

    _NODISCARD size_type size() const noexcept(noexcept(c.size())) /* strengthened */ {
        return c.size();
    }

    _NODISCARD reference top() noexcept(noexcept(c.back())) /* strengthened */ {
        return c.back();
    }

    _NODISCARD const_reference top() const noexcept(noexcept(c.back())) /* strengthened */ {
        return c.back();
    }

    void push(const value_type& _Val) {
        c.push_back(_Val);
    }

    void push(value_type&& _Val) {
        c.push_back(_STD move(_Val));
    }

    template <class... _Valty>
    decltype(auto) emplace(_Valty&&... _Val) {
#if _HAS_CXX17
        return c.emplace_back(_STD forward<_Valty>(_Val)...);
#else // ^^^ C++17 or newer / C++14 vvv
        c.emplace_back(_STD forward<_Valty>(_Val)...);
#endif // _HAS_CXX17
    }

    void pop() noexcept(noexcept(c.pop_back())) /* strengthened */ {
        c.pop_back();
    }

    void swap(stack& _Right) noexcept(_Is_nothrow_swappable<_Container>::value) {
        _Swap_adl(c, _Right.c);
    }

    _NODISCARD const _Container& _Get_container() const noexcept { // TRANSITION, VSO-1307828
        return c;
    }

protected:
    _Container c{};
};

#if _HAS_CXX17
template <class _Container, enable_if_t<!_Is_allocator<_Container>::value, int> = 0>
stack(_Container) -> stack<typename _Container::value_type, _Container>;

template <class _Container, class _Alloc,
    enable_if_t<
        conjunction_v<negation<_Is_allocator<_Container>>, _Is_allocator<_Alloc>, uses_allocator<_Container, _Alloc>>,
        int> = 0>
stack(_Container, _Alloc) -> stack<typename _Container::value_type, _Container>;
#endif // _HAS_CXX17

template <class _Ty, class _Container>
_NODISCARD bool operator==(const stack<_Ty, _Container>& _Left, const stack<_Ty, _Container>& _Right) {
    return _Left._Get_container() == _Right._Get_container();
}

template <class _Ty, class _Container>
_NODISCARD bool operator!=(const stack<_Ty, _Container>& _Left, const stack<_Ty, _Container>& _Right) {
    return _Left._Get_container() != _Right._Get_container();
}

template <class _Ty, class _Container>
_NODISCARD bool operator<(const stack<_Ty, _Container>& _Left, const stack<_Ty, _Container>& _Right) {
    return _Left._Get_container() < _Right._Get_container();
}

template <class _Ty, class _Container>
_NODISCARD bool operator>(const stack<_Ty, _Container>& _Left, const stack<_Ty, _Container>& _Right) {
    return _Left._Get_container() > _Right._Get_container();
}

template <class _Ty, class _Container>
_NODISCARD bool operator<=(const stack<_Ty, _Container>& _Left, const stack<_Ty, _Container>& _Right) {
    return _Left._Get_container() <= _Right._Get_container();
}

template <class _Ty, class _Container>
_NODISCARD bool operator>=(const stack<_Ty, _Container>& _Left, const stack<_Ty, _Container>& _Right) {
    return _Left._Get_container() >= _Right._Get_container();
}

#ifdef __cpp_lib_concepts
template <class _Ty, three_way_comparable _Container>
_NODISCARD compare_three_way_result_t<_Container> operator<=>(
    const stack<_Ty, _Container>& _Left, const stack<_Ty, _Container>& _Right) {
    return _Left._Get_container() <=> _Right._Get_container();
}
#endif // __cpp_lib_concepts

template <class _Ty, class _Container, enable_if_t<_Is_swappable<_Container>::value, int> = 0>
void swap(stack<_Ty, _Container>& _Left, stack<_Ty, _Container>& _Right) noexcept(noexcept(_Left.swap(_Right))) {
    _Left.swap(_Right);
}

template <class _Ty, class _Container, class _Alloc>
struct uses_allocator<stack<_Ty, _Container>, _Alloc> : uses_allocator<_Container, _Alloc>::type {};
_STD_END

#pragma pop_macro("new")
_STL_RESTORE_CLANG_WARNINGS
#pragma warning(pop)
#pragma pack(pop)
#endif // _STL_COMPILER_PREPROCESSOR
#endif // _STACK_
