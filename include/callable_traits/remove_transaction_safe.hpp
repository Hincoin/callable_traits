/*!
@file remove_transaction_safe

@copyright Barrett Adair 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#ifndef CALLABLE_TRAITS_REMOVE_TRANSACTION_SAFE_HPP
#define CALLABLE_TRAITS_REMOVE_TRANSACTION_SAFE_HPP

#include <callable_traits/detail/core.hpp>

//[ remove_transaction_safe_hpp
/*`
[section:ref_remove_transaction_safe remove_transaction_safe]
[heading Header]
``#include<callable_traits/remove_transaction_safe.hpp>``
[heading Definition]
*/

namespace callable_traits {

    template<typename T>
    using remove_transaction_safe_t = //implementation-defined
    //<-
        detail::fail_if_invalid<
            typename detail::traits<T>::remove_transaction_safe,
            cannot_remove_transaction_safe_from_this_type>;
    //->

    template<typename T>
    struct remove_transaction_safe {
        using type = remove_transaction_safe_t<T>;
    };
}

/*`

[heading Constraints]
* `T` must be one of the following:
  * function type
  * function pointer type
  * function reference type
  * member function pointer type

[heading Behavior]
* A substitution failure occurs if the constraints are violated.
* Removes the member `transaction_safe` specifier from `T`, if present.

[heading Input/Output Examples]
[table
    [[`T`]                              [`remove_transaction_safe_t<T>`]]
    [[`int() const transaction_safe`]   [`int() const`]]
    [[`int(*)() transaction_safe`]      [`int(*)()`]]
    [[`int(&)() transaction_safe`]      [`int(&)()`]]
    [[`int(foo::*)() transaction_safe`] [`int(foo::*)()`]]
    [[`int() const`]                    [`int() const`]]
    [[`int(*)()`]                       [`int(*)()`]]
    [[`int(&)()`]                       [`int(&)()`]]
    [[`int`]                            [(substitution failure)]]
    [[`int foo::*`]                     [(substitution failure)]]
    [[`int (foo::* const)()`]           [(substitution failure)]]
]

[heading Example Program]
[import ../example/remove_transaction_safe.cpp]
[remove_transaction_safe]
[endsect]
*/
//]

#endif //#ifndef CALLABLE_TRAITS_REMOVE_TRANSACTION_SAFE_HPP
