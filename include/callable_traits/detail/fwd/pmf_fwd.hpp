/*!
@file

@copyright Barrett Adair 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#ifndef CALLABLE_TRAITS_DETAIL_FWD_PMF_FWD_HPP
#define CALLABLE_TRAITS_DETAIL_FWD_PMF_FWD_HPP

#include <callable_traits/detail/utility.hpp>

namespace callable_traits {

    namespace detail {

        template<typename T, typename U = shallow_decay<T>>
        struct pmf;

    }
}

#endif
