/*!
@file

@copyright Barrett Adair 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

#ifndef CALLABLE_TRAITS_CALLABLE_TRAITS_HPP
#define CALLABLE_TRAITS_CALLABLE_TRAITS_HPP

#include <callable_traits/detail/core.hpp>
#include <callable_traits/add_member_const.hpp>
#include <callable_traits/add_member_cv.hpp>
#include <callable_traits/add_member_lvalue_reference.hpp>
#include <callable_traits/add_member_rvalue_reference.hpp>
#include <callable_traits/add_member_volatile.hpp>
#include <callable_traits/add_varargs.hpp>
#include <callable_traits/apply_member_pointer.hpp>
#include <callable_traits/apply_return.hpp>
#include <callable_traits/arg_at.hpp>
#include <callable_traits/args.hpp>
#include <callable_traits/clear_args.hpp>
#include <callable_traits/expand_args.hpp>
#include <callable_traits/expand_args_left.hpp>
#include <callable_traits/expand_args_right.hpp>
#include <callable_traits/function_type.hpp>
#include <callable_traits/has_member_qualifiers.hpp>
#include <callable_traits/has_varargs.hpp>
#include <callable_traits/has_void_return.hpp>
#include <callable_traits/insert_args.hpp>
#include <callable_traits/is_const_member.hpp>
#include <callable_traits/is_lvalue_reference_member.hpp>
#include <callable_traits/is_reference_member.hpp>
#include <callable_traits/is_rvalue_reference_member.hpp>
#include <callable_traits/is_volatile_member.hpp>
#include <callable_traits/replace_args.hpp>
#include <callable_traits/parent_class_of.hpp>
#include <callable_traits/pop_back_args.hpp>
#include <callable_traits/pop_front_args.hpp>
#include <callable_traits/push_back_args.hpp>
#include <callable_traits/push_front_args.hpp>
#include <callable_traits/qualified_parent_class_of.hpp>
#include <callable_traits/remove_args.hpp>
#include <callable_traits/remove_member_const.hpp>
#include <callable_traits/remove_member_cv.hpp>
#include <callable_traits/remove_member_reference.hpp>
#include <callable_traits/remove_member_volatile.hpp>
#include <callable_traits/remove_varargs.hpp>
#include <callable_traits/return_type.hpp>
#include <callable_traits/is_transaction_safe.hpp>
#include <callable_traits/remove_transaction_safe.hpp>
#include <callable_traits/add_transaction_safe.hpp>
#endif
