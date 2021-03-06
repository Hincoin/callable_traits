/*
Copyright Barrett Adair 2016
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http ://boost.org/LICENSE_1_0.txt)
*/

#include <type_traits>
#include <functional>
#include <tuple>
#include <callable_traits/remove_member_reference.hpp>

#ifdef CALLABLE_TRAITS_DISABLE_REFERENCE_QUALIFIERS
int main(){ return 0; }
#else

#ifndef CT_ASSERT
#define CT_ASSERT(...) static_assert(__VA_ARGS__, #__VA_ARGS__)
#endif //CT_ASSERT

struct foo{};

namespace ct = callable_traits;

int main() {
    {
        using f   = void(foo::*)();
        using l   = void(foo::*)() &;
        using r   = void(foo::*)() &&;
        using c   = void(foo::*)() const;
        using cl  = void(foo::*)() const &;
        using cr  = void(foo::*)() const &&;
        using v   = void(foo::*)() volatile;
        using vl  = void(foo::*)() volatile &;
        using vr  = void(foo::*)() volatile &&;
        using cv  = void(foo::*)() const volatile;
        using cvl = void(foo::*)() const volatile &;
        using cvr = void(foo::*)() const volatile &&;

        CT_ASSERT(std::is_same<f,   ct::remove_member_reference_t<f>>{});
        CT_ASSERT(std::is_same<c,   ct::remove_member_reference_t<c>>{});
        CT_ASSERT(std::is_same<v,   ct::remove_member_reference_t<v>>{});
        CT_ASSERT(std::is_same<cv,  ct::remove_member_reference_t<cv>>{});
        CT_ASSERT(std::is_same<f,   ct::remove_member_reference_t<l>>{});
        CT_ASSERT(std::is_same<c,   ct::remove_member_reference_t<cl>>{});
        CT_ASSERT(std::is_same<v,   ct::remove_member_reference_t<vl>>{});
        CT_ASSERT(std::is_same<cv,  ct::remove_member_reference_t<cvl>>{});
        CT_ASSERT(std::is_same<f,   ct::remove_member_reference_t<r>>{});
        CT_ASSERT(std::is_same<c,   ct::remove_member_reference_t<cr>>{});
        CT_ASSERT(std::is_same<v,   ct::remove_member_reference_t<vr>>{});
        CT_ASSERT(std::is_same<cv,  ct::remove_member_reference_t<cvr>>{});
    }

    {
        using f   = void();
        using l   = void() &;
        using r   = void() &&;
        using c   = void() const;
        using cl  = void() const &;
        using cr  = void() const &&;
        using v   = void() volatile;
        using vl  = void() volatile &;
        using vr  = void() volatile &&;
        using cv  = void() const volatile;
        using cvl = void() const volatile &;
        using cvr = void() const volatile &&;

        CT_ASSERT(std::is_same<f,   ct::remove_member_reference_t<f>>{});
        CT_ASSERT(std::is_same<c,   ct::remove_member_reference_t<c>>{});
        CT_ASSERT(std::is_same<v,   ct::remove_member_reference_t<v>>{});
        CT_ASSERT(std::is_same<cv,  ct::remove_member_reference_t<cv>>{});
        CT_ASSERT(std::is_same<f,   ct::remove_member_reference_t<l>>{});
        CT_ASSERT(std::is_same<c,   ct::remove_member_reference_t<cl>>{});
        CT_ASSERT(std::is_same<v,   ct::remove_member_reference_t<vl>>{});
        CT_ASSERT(std::is_same<cv,  ct::remove_member_reference_t<cvl>>{});
        CT_ASSERT(std::is_same<f,   ct::remove_member_reference_t<r>>{});
        CT_ASSERT(std::is_same<c,   ct::remove_member_reference_t<cr>>{});
        CT_ASSERT(std::is_same<v,   ct::remove_member_reference_t<vr>>{});
        CT_ASSERT(std::is_same<cv,  ct::remove_member_reference_t<cvr>>{});
    }
}

#endif //#ifndef CALLABLE_TRAITS_DISABLE_REFERENCE_QUALIFIERS
