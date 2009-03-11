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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_LARZ_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_LARZ_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/lapack/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/is_complex.hpp>
#include <boost/numeric/bindings/traits/is_real.hpp>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void larz( char const side, integer_t const m, integer_t const n,
            integer_t const l, float* v, integer_t const incv,
            float const tau, float* c, integer_t const ldc, float* work ) {
        LAPACK_SLARZ( &side, &m, &n, &l, v, &incv, &tau, c, &ldc, work );
    }
    inline void larz( char const side, integer_t const m, integer_t const n,
            integer_t const l, double* v, integer_t const incv,
            double const tau, double* c, integer_t const ldc, double* work ) {
        LAPACK_DLARZ( &side, &m, &n, &l, v, &incv, &tau, c, &ldc, work );
    }
    inline void larz( char const side, integer_t const m, integer_t const n,
            integer_t const l, traits::complex_f* v, integer_t const incv,
            traits::complex_f const tau, traits::complex_f* c,
            integer_t const ldc, traits::complex_f* work ) {
        LAPACK_CLARZ( &side, &m, &n, &l, traits::complex_ptr(v), &incv,
                traits::complex_ptr(&tau), traits::complex_ptr(c), &ldc,
                traits::complex_ptr(work) );
    }
    inline void larz( char const side, integer_t const m, integer_t const n,
            integer_t const l, traits::complex_d* v, integer_t const incv,
            traits::complex_d const tau, traits::complex_d* c,
            integer_t const ldc, traits::complex_d* work ) {
        LAPACK_ZLARZ( &side, &m, &n, &l, traits::complex_ptr(v), &incv,
                traits::complex_ptr(&tau), traits::complex_ptr(c), &ldc,
                traits::complex_ptr(work) );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct larz_impl{};

// real specialization
template< typename ValueType >
struct larz_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename VectorV, typename MatrixC, typename WORK >
    static void compute( char const side, integer_t const l, VectorV& v,
            integer_t const incv, real_type const tau, MatrixC& c,
            detail::workspace1< WORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorV >::value_type, typename traits::matrix_traits<
                MatrixC >::value_type >::value) );
        BOOST_ASSERT( side == 'L' || side == 'R' );
        BOOST_ASSERT( traits::leading_dimension(c) >= std::max(1,
                traits::matrix_num_rows(c)) );
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_work( side, traits::matrix_num_rows(c),
                traits::matrix_num_columns(c) ));
        detail::larz( side, traits::matrix_num_rows(c),
                traits::matrix_num_columns(c), l, traits::vector_storage(v),
                incv, tau, traits::matrix_storage(c),
                traits::leading_dimension(c),
                traits::vector_storage(work.select(real_type())) );
    }

    // minimal workspace specialization
    template< typename VectorV, typename MatrixC >
    static void compute( char const side, integer_t const l, VectorV& v,
            integer_t const incv, real_type const tau, MatrixC& c,
            minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work( side,
                traits::matrix_num_rows(c), traits::matrix_num_columns(c) ) );
        compute( side, l, v, incv, tau, c, workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename VectorV, typename MatrixC >
    static void compute( char const side, integer_t const l, VectorV& v,
            integer_t const incv, real_type const tau, MatrixC& c,
            optimal_workspace work ) {
        compute( side, l, v, incv, tau, c, minimal_workspace() );
    }

    static integer_t min_size_work( char const side, integer_t const m,
            integer_t const n ) {
        if ( side == 'L' )
            return n;
        else
            return m;
    }
};

// complex specialization
template< typename ValueType >
struct larz_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename VectorV, typename MatrixC, typename WORK >
    static void compute( char const side, integer_t const l, VectorV& v,
            integer_t const incv, value_type const tau, MatrixC& c,
            detail::workspace1< WORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorV >::value_type, typename traits::matrix_traits<
                MatrixC >::value_type >::value) );
        BOOST_ASSERT( side == 'L' || side == 'R' );
        BOOST_ASSERT( traits::leading_dimension(c) >= std::max(1,
                traits::matrix_num_rows(c)) );
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_work( side, traits::matrix_num_rows(c),
                traits::matrix_num_columns(c) ));
        detail::larz( side, traits::matrix_num_rows(c),
                traits::matrix_num_columns(c), l, traits::vector_storage(v),
                incv, tau, traits::matrix_storage(c),
                traits::leading_dimension(c),
                traits::vector_storage(work.select(value_type())) );
    }

    // minimal workspace specialization
    template< typename VectorV, typename MatrixC >
    static void compute( char const side, integer_t const l, VectorV& v,
            integer_t const incv, value_type const tau, MatrixC& c,
            minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work( side,
                traits::matrix_num_rows(c), traits::matrix_num_columns(c) ) );
        compute( side, l, v, incv, tau, c, workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename VectorV, typename MatrixC >
    static void compute( char const side, integer_t const l, VectorV& v,
            integer_t const incv, value_type const tau, MatrixC& c,
            optimal_workspace work ) {
        compute( side, l, v, incv, tau, c, minimal_workspace() );
    }

    static integer_t min_size_work( char const side, integer_t const m,
            integer_t const n ) {
        if ( side == 'L' )
            return n;
        else
            return m;
    }
};


// template function to call larz
template< typename VectorV, typename MatrixC, typename Workspace >
inline integer_t larz( char const side, integer_t const l, VectorV& v,
        integer_t const incv, typename traits::vector_traits<
        VectorV >::value_type const tau, MatrixC& c,
        Workspace work = optimal_workspace() ) {
    typedef typename traits::vector_traits< VectorV >::value_type value_type;
    integer_t info(0);
    larz_impl< value_type >::compute( side, l, v, incv, tau, c, work );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif