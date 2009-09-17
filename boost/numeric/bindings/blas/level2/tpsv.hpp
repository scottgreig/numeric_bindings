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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_LEVEL2_TPSV_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_LEVEL2_TPSV_HPP

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
namespace level2 {

// overloaded functions to call blas
namespace detail {
    inline void tpsv( const char uplo, const char trans, const char diag,
            const integer_t n, float const* ap, float* x,
            const integer_t incx ) {
        BLAS_STPSV( &uplo, &trans, &diag, &n, ap, x, &incx );
    }
    inline void tpsv( const char uplo, const char trans, const char diag,
            const integer_t n, double const* ap, double* x,
            const integer_t incx ) {
        BLAS_DTPSV( &uplo, &trans, &diag, &n, ap, x, &incx );
    }
    inline void tpsv( const char uplo, const char trans, const char diag,
            const integer_t n, traits::complex_f const* ap,
            traits::complex_f* x, const integer_t incx ) {
        BLAS_CTPSV( &uplo, &trans, &diag, &n, traits::complex_ptr(ap),
                traits::complex_ptr(x), &incx );
    }
    inline void tpsv( const char uplo, const char trans, const char diag,
            const integer_t n, traits::complex_d const* ap,
            traits::complex_d* x, const integer_t incx ) {
        BLAS_ZTPSV( &uplo, &trans, &diag, &n, traits::complex_ptr(ap),
                traits::complex_ptr(x), &incx );
    }
}

// value-type based template
template< typename ValueType >
struct tpsv_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;
    typedef void return_type;

    // templated specialization
    template< typename MatrixAP, typename VectorX >
    static return_type invoke( const char trans, const char diag,
            const MatrixAP& ap, VectorX& x ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAP >::value_type, typename traits::vector_traits<
                VectorX >::value_type >::value) );
        detail::tpsv( traits::matrix_uplo_tag(ap), trans, diag,
                traits::matrix_num_columns(ap), traits::matrix_storage(ap),
                traits::vector_storage(x), traits::vector_stride(x) );
    }
};

// low-level template function for direct calls to level2::tpsv
template< typename MatrixAP, typename VectorX >
inline typename tpsv_impl< typename traits::matrix_traits<
        MatrixAP >::value_type >::return_type
tpsv( const char trans, const char diag, const MatrixAP& ap,
        VectorX& x ) {
    typedef typename traits::matrix_traits< MatrixAP >::value_type value_type;
    tpsv_impl< value_type >::invoke( trans, diag, ap, x );
}

}}}}} // namespace boost::numeric::bindings::blas::level2

#endif
