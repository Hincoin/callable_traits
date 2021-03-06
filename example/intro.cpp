/*<-
Copyright Barrett Adair 2016
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http ://boost.org/LICENSE_1_0.txt)
->*/

#include <callable_traits/config.hpp>
#ifdef CALLABLE_TRAITS_DISABLE_ABOMINABLE_FUNCTIONS
int main(){ return 0; }
#else

//[ intro
//` This short program showcases some, but not all, of the features available in [libname].

#include <type_traits>
#include <functional>
#include <tuple>
#include <callable_traits/callable_traits.hpp>

namespace ct = callable_traits;

// foo is an example of a function object
struct foo {
    void operator()(int, int&&, const int&, void* = nullptr) const {}
};

int main() {

    // indexed argument types
    using second_arg = ct::arg_at_t<1, foo>;
    static_assert(std::is_same<second_arg, int&&>::value, "");

    // arg types are packaged into std::tuple, which serves as the default
    // type list in ``[libname]`` (runtime capabilities are not used).
    using args = ct::args_t<foo>;
    using expected_args = std::tuple<int, int&&, const int&, void*>;
    static_assert(std::is_same<args, expected_args>::value, "");

    // ``[namespace_scoped]``function_type "decays" a callable type to a plain
    // function type, which is structured in terms of INVOKE.
    using function_type = ct::function_type_t<foo>;
    using expected_function_type = void(int, int&&, const int&, void*);
    static_assert(std::is_same<function_type, expected_function_type>::value, "");

    // quick check for void return
    static_assert(ct::has_void_return<foo>::value, ""); //with type

    // C-style variadics detection (e.g. an ellipses in a signature)
    static_assert(!ct::has_varargs<foo>::value, "");

    // For function objects, the following checks are determined by the
    // function qualifiers on operator(), rather than the qualifiers on
    // of the type passed. This is done for consistency with member function
    // pointers, where the checks below would look at the function qualifiers
    // (rather than qualifiers on the pointer itself).
    static_assert(ct::is_const_member<foo>(), "");
    static_assert(!ct::is_volatile_member<foo>(), "");
    static_assert(!ct::is_reference_member<foo>(), "");
    static_assert(!ct::is_lvalue_reference_member<foo>(), "");
    static_assert(!ct::is_rvalue_reference_member<foo>(), "");

    using pmf = decltype(&foo::operator());

    // So that you don't have to scroll to the top to check,
    // here's the type of pmf for reference.
    using with_const = void (foo::*)(int, int&&, const int&, void*) const;
    static_assert(std::is_same<pmf, with_const>::value, "");

    // If you find yourself in the unfortunate-and-probably-avoidable
    // situation of needing to transform member function pointer
    // types, ``[libname]`` has all the tools you need to prolong
    // your sanity.

    // ``[libname]`` lets you manipulate qualifiers on PMF types.
    // To remove const:
    using mutable_pmf = ct::remove_member_const_t<pmf>;
    using without_const = void (foo::*)(int, int&&, const int&, void*) /*no const!*/;
    static_assert(std::is_same<mutable_pmf, without_const>::value, "");

    // To add an rvalue qualifier:
    using rvalue_pmf = ct::add_member_rvalue_reference_t<pmf>;
    using with_rvalue = void (foo::*)(int, int&&, const int&, void*) const &&;
    static_assert(std::is_same<rvalue_pmf, with_rvalue>::value, "");

    // Just like std::add_rvalue_reference, ``[namespace_scoped]``add_member_rvalue_reference
    // follows C++11 reference collapsing rules. While remove_member_const
    // and add_member_rvalue_reference are somewhat clumsy names, they are the best
    // the best the author could provide while still allowing both terseness
    // and grep-ability against std::remove_const, etc. in <type_traits>.
    // Naturally, ``[libname]`` provides similar tools for the other C++
    // function qualifiers. Head to the reference section of this documentation
    // for more examples.

    // To remove member const:
    using fn = void (int) const;
    using not_abominable = ct::remove_member_const_t<fn>;
    using expected_fn2 = void (int);
    static_assert(std::is_same<not_abominable, expected_fn2>::value, "");
}

//]
#endif
