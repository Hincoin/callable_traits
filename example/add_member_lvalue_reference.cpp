/*<-
Copyright Barrett Adair 2016
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http ://boost.org/LICENSE_1_0.txt)
->*/

//[ add_member_lvalue_reference
#include <type_traits>
#include <callable_traits/add_member_lvalue_reference.hpp>

namespace ct = callable_traits;

struct foo {};

int main() {

    {
        using pmf = void(foo::*)();
        using expect = void(foo::*)() &;
        using test = ct::add_member_lvalue_reference<pmf>;
        static_assert(std::is_same<test, expect>::value, "");
    } {
        // add_member_lvalue_reference doesn't change anything when
        // the function type already has an lvalue qualifier.
        using pmf = void(foo::*)() &;
        using expect = void(foo::*)() &;
        using test = ct::add_member_lvalue_reference<pmf>;
        static_assert(std::is_same<test, expect>::value, "");
    } {
        // add_member_lvalue_reference models C++11 reference collapsing
        // rules, so that adding an lvalue qualifier to an
        // rvalue-qualified type will force the lvalue.
        using pmf = void(foo::*)() &&;
        using expect = void(foo::*)() &;
        using test = ct::add_member_lvalue_reference<pmf>;
        static_assert(std::is_same<test, expect>::value, "");
    } {
        // add_member_lvalue_reference can also be used to create "abominable"
        // function types.
        using f = void();
        using expect = void() &;
        using test = ct::add_member_lvalue_reference<f>;
        static_assert(std::is_same<test, expect>::value, "");
    } {
        // add_member_lvalue_reference does not compile with function pointers,
        // function references, function objects, or member data pointers.
        // However, you can loosen this restriction somewhat by using the
        // callable_traits::permissive namespace instead:
        using f = void(*)();
        using expect = f;
        using test = ct::permissive::add_member_lvalue_reference<f>;
        static_assert(std::is_same<test, expect>::value, "");
    }
}
//]