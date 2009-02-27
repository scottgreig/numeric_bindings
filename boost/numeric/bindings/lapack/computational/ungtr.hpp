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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_UNGTR_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_UNGTR_HPP

#include <boost/numeric/bindings/lapack/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/detail/utils.hpp>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp
#include <boost/type_traits/is_same.hpp>
#include <cassert>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void ungtr( char const uplo, integer_t const n,
            traits::complex_f* a, integer_t const lda, traits::complex_f* tau,
            traits::complex_f* work, integer_t const lwork, integer_t& info ) {
        LAPACK_CUNGTR( &uplo, &n, traits::complex_ptr(a), &lda,
                traits::complex_ptr(tau), traits::complex_ptr(work), &lwork,
                &info );
    }
    inline void ungtr( char const uplo, integer_t const n,
            traits::complex_d* a, integer_t const lda, traits::complex_d* tau,
            traits::complex_d* work, integer_t const lwork, integer_t& info ) {
        LAPACK_ZUNGTR( &uplo, &n, traits::complex_ptr(a), &lda,
                traits::complex_ptr(tau), traits::complex_ptr(work), &lwork,
                &info );
    }
}

// value-type based template
template< typename ValueType >
struct ungtr_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename VectorTAU, typename WORK >
    static void compute( integer_t const n, MatrixA& a, VectorTAU& tau,
            integer_t& info, detail::workspace1< WORK > work ) {
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorTAU >::value_type > );
#ifndef NDEBUG
        assert( traits::matrix_uplo_tag(a) == 'U' ||
                traits::matrix_uplo_tag(a) == 'L' );
        assert( n >= 0 );
        assert( traits::leading_dimension(a) >= n );
        assert( traits::vector_size(tau) >= n-1 );
        assert( traits::vector_size(work.select(value_type()) >=
                min_size_work( side, m, n )));
#endif
        detail::ungtr( traits::matrix_uplo_tag(a), n,
                traits::matrix_storage(a), traits::leading_dimension(a),
                traits::vector_storage(tau),
                traits::vector_storage(work.select(value_type())),
                traits::vector_size(work.select(value_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename VectorTAU >
    static void compute( integer_t const n, MatrixA& a, VectorTAU& tau,
            integer_t& info, minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work( side, m,
                n ) );
        compute( n, a, tau, info, workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename VectorTAU >
    static void compute( integer_t const n, MatrixA& a, VectorTAU& tau,
            integer_t& info, optimal_workspace work ) {
        value_type opt_size_work;
        detail::ungtr( traits::matrix_uplo_tag(a), n,
                traits::matrix_storage(a), traits::leading_dimension(a),
                traits::vector_storage(tau), &opt_size_work, -1, info );
        traits::detail::array< value_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        compute( n, a, tau, info, workspace( tmp_work ) );
    }

    static integer_t min_size_work( integer_t const side, integer_t const m,
            integer_t const n ) {
        if ( side == 'L' )
            return std::max( 1, n );
        else
            return std::max( 1, m );
    }
};


// template function to call ungtr
template< typename MatrixA, typename VectorTAU, typename Workspace >
inline integer_t ungtr( integer_t const n, MatrixA& a, VectorTAU& tau,
        Workspace work = optimal_workspace() ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    ungtr_impl< value_type >::compute( n, a, tau, info, work );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
