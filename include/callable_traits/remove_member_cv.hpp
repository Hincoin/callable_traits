/*

@copyright Barrett Adair 2015

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#ifndef CALLABLE_TRAITS_REMOVE_MEMBER_CV_HPP
#define CALLABLE_TRAITS_REMOVE_MEMBER_CV_HPP

#include <callable_traits/detail/core.hpp>

//[ remove_member_cv_hpp
/*`
[section:ref_remove_member_cv remove_member_cv]
[heading Header]
``#include<callable_traits/remove_member_cv.hpp>``
[heading Definition]
*/

namespace callable_traits {

    template<typename T>
    using remove_member_cv_t = //implementation-defined
    //<-
        detail::fail_if_invalid<
            typename detail::traits<T>::remove_member_cv,
            member_qualifiers_are_illegal_for_this_type>;
    //->

    template<typename T>
    struct remove_member_cv {
        using type = remove_member_cv_t<T>;
    };
}

/*`
[heading Constraints]
* `T` must be a function type or a member function pointer type

[heading Behavior]
* A substitution failure occurs if the constraints are violated.
* Removes member `const` and/or `volatile` qualifiers from `T`, if present.

[heading Input/Output Examples]
[table
    [[`T`]                              [`remove_member_cv_t<T>`]]
    [[`int() const volatile`]           [`int()`]]
    [[`int(foo::*)() const volatile`]   [`int(foo::*)()`]]
    [[`int(foo::*)() volatile`]         [`int(foo::*)()`]]
    [[`int(foo::*)() const`]            [`int(foo::*)()`]]
    [[`int(foo::*)() const &`]          [`int(foo::*)() &`]]
    [[`int(foo::*)() const &&`]         [`int(foo::*)() &&`]]
    [[`int(foo::*)() const`]            [`int(foo::*)()`]]
    [[`int`]                            [(substitution failure)]]
    [[`int (&)()`]                      [(substitution failure)]]
    [[`int (*)()`]                      [(substitution failure)]]
    [[`int foo::*`]                     [(substitution failure)]]
    [[`int (foo::* const)()`]           [(substitution failure)]]
]

[heading Example Program]
[import ../example/remove_member_cv.cpp]
[remove_member_cv]
[endsect]
*/
//]

#endif //#ifndef CALLABLE_TRAITS_REMOVE_MEMBER_CV_HPP
