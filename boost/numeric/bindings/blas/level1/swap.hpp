//
// Copyright (c) 2003--2009
// Toon Knapen, Karl Meerbergen, Kresimir Fresl,
// Thomas Klimpel and Rutger ter Borg
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// THIS FILE IS AUTOMATICALLY GENERATED
// PLEASE DO NOT EDIT!
//

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_LEVEL1_SWAP_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_LEVEL1_SWAP_HPP

#include <boost/mpl/bool.hpp>
#include <boost/numeric/bindings/blas/detail/blas.h>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace blas {
namespace level1 {

// overloaded functions to call blas
namespace detail {
    inline void swap( const integer_t n, float* x, const integer_t incx,
            float* y, const integer_t incy ) {
        BLAS_SSWAP( &n, x, &incx, y, &incy );
    }
    inline void swap( const integer_t n, double* x, const integer_t incx,
            double* y, const integer_t incy ) {
        BLAS_DSWAP( &n, x, &incx, y, &incy );
    }
    inline void swap( const integer_t n, traits::complex_f* x,
            const integer_t incx, traits::complex_f* y,
            const integer_t incy ) {
        BLAS_CSWAP( &n, traits::complex_ptr(x), &incx, traits::complex_ptr(y),
                &incy );
    }
    inline void swap( const integer_t n, traits::complex_d* x,
            const integer_t incx, traits::complex_d* y,
            const integer_t incy ) {
        BLAS_ZSWAP( &n, traits::complex_ptr(x), &incx, traits::complex_ptr(y),
                &incy );
    }
}

// value-type based template
template< typename ValueType >
struct swap_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;
    typedef void return_type;

    // templated specialization
    template< typename VectorX, typename VectorY >
    static return_type invoke( VectorX& x, VectorY& y ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorX >::value_type, typename traits::vector_traits<
                VectorY >::value_type >::value) );
        detail::swap( traits::vector_size(x), traits::vector_storage(x),
                traits::vector_stride(x), traits::vector_storage(y),
                traits::vector_stride(y) );
    }
};

// low-level template function for direct calls to level1::swap
template< typename VectorX, typename VectorY >
inline typename swap_impl< typename traits::vector_traits<
        VectorX >::value_type >::return_type
swap( VectorX& x, VectorY& y ) {
    typedef typename traits::vector_traits< VectorX >::value_type value_type;
    swap_impl< value_type >::invoke( x, y );
}

}}}}} // namespace boost::numeric::bindings::blas::level1

#endif
