/*  Copyright (C) 2013-2014  Povilas Kanapickas <povilas@radix.lt>

    Distributed under the Boost Software License, Version 1.0.
        (See accompanying file LICENSE_1_0.txt or copy at
            http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef LIBSIMDPP_SIMDPP_CORE_BIT_OR_H
#define LIBSIMDPP_SIMDPP_CORE_BIT_OR_H

#ifndef LIBSIMDPP_SIMD_H
    #error "This file must be included through simd.h"
#endif

#include <simdpp/types.h>
#include <simdpp/detail/insn/bit_or.h>
#include <simdpp/detail/expr/bit_or.h>
#include <simdpp/detail/cast_expr.h>
#include <simdpp/core/detail/get_expr_bitwise.h>
#include <simdpp/core/detail/scalar_arg_impl.h>

namespace simdpp {
namespace SIMDPP_ARCH_NAMESPACE {

/** Computes bitwise OR of integer vectors.

    @code
    r0 = a0 | b0
    ...
    rN = aN | bN
    @endcode

    @todo icost
*/
template<unsigned N, class V1, class V2> SIMDPP_INL
typename detail::get_expr_bit_or<V1, V2>::type
        bit_or(const any_vec<N,V1>& a, const any_vec<N,V2>& b)
{
    using expr = detail::get_expr_bit_or<V1, V2>;
    return { { detail::cast_expr<typename expr::v1_type>(a.wrapped()),
               detail::cast_expr<typename expr::v2_type>(b.wrapped()) } };
}

// support scalar arguments
template<unsigned N, class V> SIMDPP_INL
typename detail::get_expr_bit_or<typename detail::get_expr_nomask<V, expr_scalar_bitwise<uint32_t>>::type, V>::type
        bit_or(const unsigned& a, const any_vec<N,V>& b)
{
    return bit_or(detail::cast_expr<typename detail::get_expr_nomask<V, expr_scalar_bitwise<uint32_t>>::type>(a), b);
}
template<unsigned N, class V> SIMDPP_INL
typename detail::get_expr_bit_or<typename detail::get_expr_nomask<V, expr_scalar_bitwise<uint64_t>>::type, V>::type
        bit_or(const unsigned long& a, const any_vec<N,V>& b)
{
    return bit_or(detail::cast_expr<typename detail::get_expr_nomask<V, expr_scalar_bitwise<uint64_t>>::type>(a), b);
}
template<unsigned N, class V> SIMDPP_INL
typename detail::get_expr_bit_or<typename detail::get_expr_nomask<V, expr_scalar_bitwise<uint64_t>>::type, V>::type
        bit_or(const unsigned long long& a, const any_vec<N,V>& b)
{
    return bit_or(detail::cast_expr<typename detail::get_expr_nomask<V, expr_scalar_bitwise<uint64_t>>::type>(a), b);
}
template<unsigned N, class V> SIMDPP_INL
typename detail::get_expr_bit_or<typename detail::get_expr_nomask<V, expr_scalar_bitwise<int32_t>>::type, V>::type
        bit_or(const int& a, const any_vec<N,V>& b)
{
    return bit_or(detail::cast_expr<typename detail::get_expr_nomask<V, expr_scalar_bitwise<int32_t>>::type>(a), b);
}
template<unsigned N, class V> SIMDPP_INL
typename detail::get_expr_bit_or<typename detail::get_expr_nomask<V, expr_scalar_bitwise<int64_t>>::type, V>::type
        bit_or(const long& a, const any_vec<N,V>& b)
{
    return bit_or(detail::cast_expr<typename detail::get_expr_nomask<V, expr_scalar_bitwise<int64_t>>::type>(a), b);
}
template<unsigned N, class V> SIMDPP_INL
typename detail::get_expr_bit_or<typename detail::get_expr_nomask<V, expr_scalar_bitwise<int64_t>>::type, V>::type
        bit_or(const long long& a, const any_vec<N,V>& b)
{
    return bit_or(detail::cast_expr<typename detail::get_expr_nomask<V, expr_scalar_bitwise<int64_t>>::type>(a), b);
}


template<unsigned N, class V> SIMDPP_INL
typename detail::get_expr_bit_or<V, typename detail::get_expr_nomask<V, expr_scalar_bitwise<uint32_t>>::type>::type
        bit_or(const any_vec<N,V>& a, const unsigned& b)
{
    return bit_or(a, detail::cast_expr<typename detail::get_expr_nomask<V, expr_scalar_bitwise<uint32_t>>::type>(b));
}
template<unsigned N, class V> SIMDPP_INL
typename detail::get_expr_bit_or<V, typename detail::get_expr_nomask<V, expr_scalar_bitwise<uint64_t>>::type>::type
        bit_or(const any_vec<N,V>& a, const unsigned long& b)
{
    return bit_or(a, detail::cast_expr<typename detail::get_expr_nomask<V, expr_scalar_bitwise<uint64_t>>::type>(b));
}
template<unsigned N, class V> SIMDPP_INL
typename detail::get_expr_bit_or<V, typename detail::get_expr_nomask<V, expr_scalar_bitwise<uint64_t>>::type>::type
        bit_or(const any_vec<N,V>& a, const unsigned long long& b)
{
    return bit_or(a, detail::cast_expr<typename detail::get_expr_nomask<V, expr_scalar_bitwise<uint64_t>>::type>(b));
}
template<unsigned N, class V> SIMDPP_INL
typename detail::get_expr_bit_or<V, typename detail::get_expr_nomask<V, expr_scalar_bitwise<int32_t>>::type>::type
        bit_or(const any_vec<N,V>& a, const int& b)
{
    return bit_or(a, detail::cast_expr<typename detail::get_expr_nomask<V, expr_scalar_bitwise<int32_t>>::type>(b));
}
template<unsigned N, class V> SIMDPP_INL
typename detail::get_expr_bit_or<V, typename detail::get_expr_nomask<V, expr_scalar_bitwise<int64_t>>::type>::type
        bit_or(const any_vec<N,V>& a, const long& b)
{
    return bit_or(a, detail::cast_expr<typename detail::get_expr_nomask<V, expr_scalar_bitwise<int64_t>>::type>(b));
}
template<unsigned N, class V> SIMDPP_INL
typename detail::get_expr_bit_or<V, typename detail::get_expr_nomask<V, expr_scalar_bitwise<int64_t>>::type>::type
        bit_or(const any_vec<N,V>& a, const long long& b)
{
    return bit_or(a, detail::cast_expr<typename detail::get_expr_nomask<V, expr_scalar_bitwise<int64_t>>::type>(b));
}


} // namespace SIMDPP_ARCH_NAMESPACE
} // namespace simdpp

#endif


