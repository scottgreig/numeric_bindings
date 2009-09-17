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

#ifndef BOOST_NUMERIC_BINDINGS_BLAS_LEVEL2_TBSV_HPP
#define BOOST_NUMERIC_BINDINGS_BLAS_LEVEL2_TBSV_HPP

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
    inline void tbsv( const char uplo, const char trans, const char diag,
            const integer_t n, const integer_t k, float const* a,
            const integer_t lda, float* x, const integer_t incx ) {
        BLAS_STBSV( &uplo, &trans, &diag, &n, &k, a, &lda, x, &incx );
    }
    inline void tbsv( const char uplo, const char trans, const char diag,
            const integer_t n, const integer_t k, double const* a,
            const integer_t lda, double* x, const integer_t incx ) {
        BLAS_DTBSV( &uplo, &trans, &diag, &n, &k, a, &lda, x, &incx );
    }
    inline void tbsv( const char uplo, const char trans, const char diag,
            const integer_t n, const integer_t k, traits::complex_f const* a,
            const integer_t lda, traits::complex_f* x, const integer_t incx ) {
        BLAS_CTBSV( &uplo, &trans, &diag, &n, &k, traits::complex_ptr(a),
                &lda, traits::complex_ptr(x), &incx );
    }
    inline void tbsv( const char uplo, const char trans, const char diag,
            const integer_t n, const integer_t k, traits::complex_d const* a,
            const integer_t lda, traits::complex_d* x, const integer_t incx ) {
        BLAS_ZTBSV( &uplo, &trans, &diag, &n, &k, traits::complex_ptr(a),
                &lda, traits::complex_ptr(x), &incx );
    }
}

// value-type based template
template< typename ValueType >
struct tbsv_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;
    typedef void return_type;

    // templated specialization
    template< typename MatrixA, typename VectorX >
    static return_type invoke( const char trans, const char diag,
            const integer_t k, const MatrixA& a, VectorX& x ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorX >::value_type >::value) );
        detail::tbsv( traits::matrix_uplo_tag(a), trans, diag,
                traits::matrix_num_columns(a), k, traits::matrix_storage(a),
                traits::leading_dimension(a), traits::vector_storage(x),
                traits::vector_stride(x) );
    }
};

// low-level template function for direct calls to level2::tbsv
template< typename MatrixA, typename VectorX >
inline typename tbsv_impl< typename traits::matrix_traits<
        MatrixA >::value_type >::return_type
tbsv( const char trans, const char diag, const integer_t k,
        const MatrixA& a, VectorX& x ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    tbsv_impl< value_type >::invoke( trans, diag, k, a, x );
}

}}}}} // namespace boost::numeric::bindings::blas::level2

#endif
