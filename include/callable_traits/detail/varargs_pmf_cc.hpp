/*
Copyright (c) 2001 Peter Dimov and Multi Media Ltd.
Copyright (c) 2016 Modified Work Barrett Adair

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

HEADER GUARDS INTENTIONALLY OMITTED
DO NOT INCLUDE THIS HEADER DIRECTLY

*/

#define CALLABLE_TRAITS_SPECIALIZE_PMF_VARARGS(QUAL, ABOM_QUAL)                      \
                                                                                     \
template<typename Ret, typename T, typename... Args>                                 \
struct add_calling_convention_t<                                                     \
    Ret(T::*)(Args..., ...) QUAL, CALLABLE_TRAITS_CC_TAG> {                          \
    using type = Ret(CALLABLE_TRAITS_CC T::*)(Args..., ...);                         \
};                                                                                   \
                                                                                     \
template<typename Ret, typename T, typename... Args>                                 \
struct has_calling_convention_t<                                                     \
    Ret(CALLABLE_TRAITS_VARARGS_CC T::*)(Args..., ...) QUAL,                         \
	CALLABLE_TRAITS_CC_TAG> {                                                        \
    using type = std::true_type;                                                     \
};                                                                                   \
                                                                                     \
template<typename T, typename Return, typename... Args>                              \
struct set_varargs_member_function_qualifiers_t <                                    \
    flag_map<int QUAL>::value, CALLABLE_TRAITS_CC_TAG, T, Return, Args...> {         \
                                                                                     \
    using type =                                                                     \
        Return(CALLABLE_TRAITS_VARARGS_CC T::*)(Args..., ...) QUAL;                  \
};                                                                                   \
                                                                                     \
template<typename OriginalType, typename Return, typename T, typename... Args>       \
struct pmf<OriginalType, Return(CALLABLE_TRAITS_VARARGS_CC T::*)(Args..., ...) QUAL> \
 : qualifier_traits<dummy QUAL>, default_callable_traits {                           \
                                                                                     \
    static constexpr bool value = true;                                              \
                                                                                     \
    using has_varargs = std::true_type;                                              \
    using is_member_pointer = std::true_type;                                        \
    using is_member_function_pointer = std::true_type;                               \
    using traits = pmf;                                                              \
    using return_type = Return;                                                      \
    using arg_types = std::tuple<Args...>;                                           \
    using type = Return(CALLABLE_TRAITS_VARARGS_CC T::*)(Args..., ...) QUAL;         \
                                                                                     \
    using invoke_type = typename std::conditional<                                   \
        std::is_rvalue_reference<T QUAL>::value,                                     \
        T QUAL,                                                                      \
        typename std::add_lvalue_reference<T QUAL>::type                             \
    >::type;                                                                         \
                                                                                     \
    using function_object_type = Return(Args..., ...);                               \
    using function_type = Return(invoke_type, Args..., ...);                         \
    using invoke_arg_types = std::tuple<invoke_type, Args...>;                       \
    using qualified_function_type = Return(Args..., ...) ABOM_QUAL;                  \
                                                                                     \
    using remove_varargs = typename copy_cvr<                                        \
        Return(CALLABLE_TRAITS_CC T::*)(Args...) QUAL,                               \
        OriginalType                                                                 \
    >::type;                                                                         \
                                                                                     \
    using add_varargs = OriginalType;                                                \
    using class_type = T;                                                            \
                                                                                     \
    using qualifiers = qualifier_traits<dummy QUAL>;                                 \
                                                                                     \
    template<flags Flags>                                                            \
    using set_qualifiers = typename copy_cvr<                                        \
        set_varargs_member_function_qualifiers<                                      \
            Flags, CALLABLE_TRAITS_CC_TAG, T, Return, Args...>,                      \
            OriginalType                                                             \
        >::type;                                                                     \
                                                                                     \
    using remove_member_reference = set_qualifiers<qualifiers::cv_flags>;            \
                                                                                     \
    using add_member_lvalue_reference = set_qualifiers<                              \
        collapse_flags<qualifiers::q_flags, lref_>::value>;                          \
                                                                                     \
    using add_member_rvalue_reference = set_qualifiers<                              \
        collapse_flags<qualifiers::q_flags, rref_>::value>;                          \
                                                                                     \
    using add_member_const = set_qualifiers<qualifiers::q_flags | const_>;           \
    using add_member_volatile = set_qualifiers<qualifiers::q_flags | volatile_>;     \
    using add_member_cv = set_qualifiers<qualifiers::q_flags | cv_>;                 \
                                                                                     \
    using remove_member_const = set_qualifiers<                                      \
        qualifiers::ref_flags | remove_const_flag<qualifiers::cv_flags>::value>;     \
                                                                                     \
    using remove_member_volatile = set_qualifiers<                                   \
        qualifiers::ref_flags | remove_volatile_flag<qualifiers::cv_flags>::value>;  \
                                                                                     \
    using remove_member_cv = set_qualifiers<qualifiers::ref_flags>;                  \
                                                                                     \
    template<typename U>                                                             \
    using apply_member_pointer = typename copy_cvr<                                  \
        Return(CALLABLE_TRAITS_VARARGS_CC U::*)(Args..., ...) QUAL,                  \
        OriginalType                                                                 \
    >::type;                                                                         \
                                                                                     \
    template<typename NewReturn>                                                     \
    using apply_return = typename copy_cvr<                                          \
        NewReturn(CALLABLE_TRAITS_VARARGS_CC T::*)(Args..., ...) QUAL,               \
        OriginalType                                                                 \
    >::type;                                                                         \
                                                                                     \
    using remove_member_pointer = qualified_function_type;                           \
                                                                                     \
    template<template<class...> class Container>                                     \
    using expand_args = Container<Args...>;                                          \
                                                                                     \
    using clear_args = typename copy_cvr<                                            \
        Return(CALLABLE_TRAITS_VARARGS_CC T::*)() QUAL,                              \
        OriginalType                                                                 \
	>::type;                                                                         \
                                                                                     \
    template<typename... NewArgs>                                                    \
    using push_args_front = typename copy_cvr<                                       \
	    Return(CALLABLE_TRAITS_VARARGS_CC T::*)(NewArgs..., Args..., ...) QUAL,      \
		OriginalType                                                                 \
	>::type;                                                                         \
                                                                                     \
	template<typename... NewArgs>                                                    \
	using push_args_back = typename copy_cvr<                                        \
		Return(CALLABLE_TRAITS_VARARGS_CC T::*)(Args..., NewArgs..., ...) QUAL,      \
		OriginalType                                                                 \
	>::type;                                                                         \
}                                                                                    \
/**/

CALLABLE_TRAITS_SPECIALIZE_PMF_VARARGS(CALLABLE_TRAITS_EMPTY, CALLABLE_TRAITS_EMPTY);
CALLABLE_TRAITS_SPECIALIZE_PMF_VARARGS(const, CALLABLE_TRAITS_ABOMINABLE_CONST);
CALLABLE_TRAITS_SPECIALIZE_PMF_VARARGS(volatile, CALLABLE_TRAITS_ABOMINABLE_VOLATILE);
CALLABLE_TRAITS_SPECIALIZE_PMF_VARARGS(const volatile, CALLABLE_TRAITS_ABOMINABLE_CONST CALLABLE_TRAITS_ABOMINABLE_VOLATILE);

#ifndef CALLABLE_TRAITS_DISABLE_REFERENCE_QUALIFIERS

CALLABLE_TRAITS_SPECIALIZE_PMF_VARARGS(&, &);
CALLABLE_TRAITS_SPECIALIZE_PMF_VARARGS(&&, &&);
CALLABLE_TRAITS_SPECIALIZE_PMF_VARARGS(const &, const &);
CALLABLE_TRAITS_SPECIALIZE_PMF_VARARGS(volatile &, volatile &);
CALLABLE_TRAITS_SPECIALIZE_PMF_VARARGS(const volatile &, const volatile &);
CALLABLE_TRAITS_SPECIALIZE_PMF_VARARGS(const &&, const &&);
CALLABLE_TRAITS_SPECIALIZE_PMF_VARARGS(volatile &&, volatile &&);
CALLABLE_TRAITS_SPECIALIZE_PMF_VARARGS(const volatile &&, const volatile &&);

#endif //#ifndef CALLABLE_TRAITS_DISABLE_REFERENCE_QUALIFIERS

#undef CALLABLE_TRAITS_SPECIALIZE_PMF_VARARGS
