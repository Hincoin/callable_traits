/*
 *
@copyright Barrett Adair 2015

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#ifndef CALLABLE_TRAITS_IS_VOLATILE_MEMBER_HPP
#define CALLABLE_TRAITS_IS_VOLATILE_MEMBER_HPP

#include <callable_traits/detail/core.hpp>

//[ is_volatile_member_hpp
/*`[section:ref_is_volatile_member is_volatile_member]
[heading Header]
``#include<callable_traits/is_volatile_member.hpp>``
[heading Definition]
*/

namespace callable_traits {

    template<typename T>
    struct is_volatile_member; //implementation-defined

    //<-
    template<typename T>
    struct is_volatile_member
        : detail::traits<T>::is_volatile_member {

        using type = typename detail::traits<T>::is_volatile_member;
    };

    #ifdef CALLABLE_TRAITS_DISABLE_VARIABLE_TEMPLATES

    template<typename T>
    struct is_volatile_member_v {
        static_assert(sizeof(T) < 1,
            "Variable templates not supported on this compiler.");
    };

    #else
    //->
    template<typename T>
    constexpr bool is_volatile_member_v = //implementation-defined
    //<-
        detail::traits<T>::is_volatile_member::value;

    #endif
    //->
}

/*`
[heading Constraints]
* none

[heading Behavior]
* `std::false_type` is inherited by `is_volatile_member<T>` and is aliased by `typename is_volatile_member<T>::type`, except when one of the following criteria is met, in which case `std::true_type` would be similarly inherited and aliased:
  * `T` is a function type with a `volatile` member qualifier
  * `T` is a pointer to a member function with a `volatile` member qualifier
  * `T` is a function object with a non-overloaded `operator()`, where the `operator()` has a `volatile` member qualifier
* On compilers that support variable templates, `is_volatile_member_v<T>` is equivalent to `is_volatile_member<T>::value`.

[heading Input/Output Examples]
[table
    [[`T`]                              [`is_volatile_member_v<T>`]]
    [[`int() volatile`]                 [`true`]]
    [[`int() const volatile`]           [`true`]]
    [[`int() volatile &&`]              [`true`]]
    [[`int(foo::*)() volatile`]         [`true`]]
    [[`int(foo::*)() const volatile`]   [`true`]]
    [[`int(foo::*)() const volatile &&`][`true`]]
    [[`int()`]                          [`false`]]
    [[`int() const`]                    [`false`]]
    [[`int() &&`]                       [`false`]]
    [[`int(*)()`]                       [`false`]]
    [[`int(foo::* const)() volatile`]   [`false`]]
    [[`int`]                            [`false`]]
    [[`int foo::*`]                     [`false`]]
    [[`volatile int foo::*`]            [`false`]]
]

[heading Example Program]
[import ../example/is_volatile_member.cpp]
[is_volatile_member]
[endsect]
*/
//]

#endif //#ifndef CALLABLE_TRAITS_IS_VOLATILE_MEMBER_HPP
