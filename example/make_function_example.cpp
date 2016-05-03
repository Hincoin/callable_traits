/*<-
Copyright Barrett Adair 2016
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http ://boost.org/LICENSE_1_0.txt)
->*/

#include <callable_traits/config.hpp>

#ifdef CALLABLE_TRAITS_DISABLE_CONSTEXPR_CHECKS
int main(){ return 0; }
#else
    
//[ make_function_example
#include <cassert>

#include "make_function.hpp"

using namespace example;
using namespace std::placeholders;

int add(int i, int j) {
    return i + j;
}

struct adder {

    int eval(int i, int j) const {
        return i + j;
    }
};

int main() {

    // function pointer
    auto f = make_function(&add);
    assert(f(99, 1) == 100);

    // function reference
    f = make_function(add);
    assert(f(99, 1) == 100);

    // member function pointer (bound to object)
    f = make_function(&adder::eval, adder{}, _1, _2);
    assert(f(99, 1) == 100);

    // lambda
    f = make_function([](int i, int j) {
        return i + j;
    });

    assert(f(99, 1) == 100);
}
//]
#endif
