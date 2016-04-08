/*!
@file add_function_const

@copyright Barrett Adair 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#ifndef CALLABLE_TRAITS_ADD_CALLING_CONVENTION_HPP
#define CALLABLE_TRAITS_ADD_CALLING_CONVENTION_HPP

#include <callable_traits/detail/calling_conventions.hpp>
#include <callable_traits/detail/required_definitions.hpp>

namespace callable_traits {

    namespace detail {

        template<bool Sfinae, typename Tag>
        struct add_calling_convention_error {

            static_assert(Sfinae,
                "Unknown calling convention type. Did you use a type "
				"from namespace callable_traits::calling_conventions?");
        };
		
		template<bool Sfinae>
        struct add_calling_convention_error<Sfinae, calling_conventions::stdcall> {

			#ifdef CALLABLE_TRAITS_ENABLE_STDCALL
            static_assert(Sfinae,
				"Unable to add __stdcall to type T in "
				"callable_traits::add_calling_convention<T, "
				"callable_traits::calling_conventions::stdcall>.");
			#else
            static_assert(Sfinae,
				"__stdcall functionality not enabled. Define "
				"CALLABLE_TRAITS_ENABLE_STDCALL to enable.");	
			#endif
        };
		
		template<bool Sfinae>
        struct add_calling_convention_error<Sfinae, calling_conventions::fastcall> {

			#ifdef CALLABLE_TRAITS_ENABLE_FASTCALL
            static_assert(Sfinae,
				"Unable to add __fastcall to type T in "
				"callable_traits::add_calling_convention<T, "
				"callable_traits::calling_conventions::fastcall>.");
			#else
            static_assert(Sfinae,
				"__fastcall functionality not enabled. Define "
				"CALLABLE_TRAITS_ENABLE_FASTCALL to enable.");	
			#endif
        };
		
		template<bool Sfinae>
        struct add_calling_convention_error<Sfinae, calling_conventions::cdecl> {

			#ifdef CALLABLE_TRAITS_ENABLE_CDECL
            static_assert(Sfinae,
				"Unable to add __cdecl to type T in "
				"callable_traits::add_calling_convention<T, "
				"callable_traits::calling_conventions::cdecl>.");
			#else
            static_assert(Sfinae,
				"__cdecl functionality not enabled. Define "
				"CALLABLE_TRAITS_ENABLE_CDECL to enable.");	
			#endif
        };
		
		template<bool Sfinae>
        struct add_calling_convention_error<Sfinae, calling_conventions::pascal> {

#ifdef CALLABLE_TRAITS_ENABLE_PASCAL
            static_assert(Sfinae,
				"Unable to add pascal to type T in "
				"callable_traits::add_calling_convention<T, "
				"callable_traits::calling_conventions::pascal>.");
#else
            static_assert(Sfinae,
				"pascal functionality not enabled. Define "
				"CALLABLE_TRAITS_ENABLE_PASCAL to enable.");	
#endif
        };
    }

    namespace permissive {

        template<typename T, typename Tag>
        using add_calling_convention = detail::fallback_if_invalid<
            typename detail::add_calling_convention_t<T, Tag>::type,
            T>;
    }

    namespace verbose {

        template<typename T, typename Tag>
        using add_calling_convention = detail::fail_if_invalid<
            typename detail::add_calling_convention_t<T, Tag>::type,
            detail::add_calling_convention_error<false, Tag>>;
    }

    template<typename T, typename Tag>
    using add_calling_convention = detail::fail_if_invalid<
        typename detail::add_calling_convention_t<T, Tag>::type,
        detail::add_calling_convention_error<true, Tag>>;
}

#endif //CALLABLE_TRAITS_ADD_CALLING_CONVENTION_HPP