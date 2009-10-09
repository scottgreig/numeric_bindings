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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_SBGST_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_SBGST_HPP

#include <boost/assert.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {

inline void sbgst( const char vect, const char uplo, const integer_t n,
        const integer_t ka, const integer_t kb, float* ab,
        const integer_t ldab, const float* bb, const integer_t ldbb, float* x,
        const integer_t ldx, float* work, integer_t& info ) {
    LAPACK_SSBGST( &vect, &uplo, &n, &ka, &kb, ab, &ldab, bb, &ldbb, x, &ldx,
            work, &info );
}
inline void sbgst( const char vect, const char uplo, const integer_t n,
        const integer_t ka, const integer_t kb, double* ab,
        const integer_t ldab, const double* bb, const integer_t ldbb,
        double* x, const integer_t ldx, double* work, integer_t& info ) {
    LAPACK_DSBGST( &vect, &uplo, &n, &ka, &kb, ab, &ldab, bb, &ldbb, x, &ldx,
            work, &info );
}
} // namespace detail

// value-type based template
template< typename ValueType >
struct sbgst_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixAB, typename MatrixBB, typename MatrixX,
            typename WORK >
    static void invoke( const char vect, const integer_t n,
            const integer_t ka, const integer_t kb, MatrixAB& ab,
            const MatrixBB& bb, MatrixX& x, integer_t& info,
            detail::workspace1< WORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::matrix_traits<
                MatrixBB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::matrix_traits<
                MatrixX >::value_type >::value) );
        BOOST_ASSERT( vect == 'N' || vect == 'V' );
        BOOST_ASSERT( traits::matrix_uplo_tag(a) == 'U' ||
                traits::matrix_uplo_tag(a) == 'L' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( ka >= 0 );
        BOOST_ASSERT( kb >= kb );
        BOOST_ASSERT( traits::leading_dimension(ab) >= ka+1 );
        BOOST_ASSERT( traits::leading_dimension(bb) >= kb+1 );
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_work( n ));
        detail::sbgst( vect, traits::matrix_uplo_tag(a), n, ka, kb,
                traits::matrix_storage(ab), traits::leading_dimension(ab),
                traits::matrix_storage(bb), traits::leading_dimension(bb),
                traits::matrix_storage(x), traits::leading_dimension(x),
                traits::vector_storage(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixAB, typename MatrixBB, typename MatrixX >
    static void invoke( const char vect, const integer_t n,
            const integer_t ka, const integer_t kb, MatrixAB& ab,
            const MatrixBB& bb, MatrixX& x, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work( n ) );
        invoke( vect, n, ka, kb, ab, bb, x, info, workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename MatrixAB, typename MatrixBB, typename MatrixX >
    static void invoke( const char vect, const integer_t n,
            const integer_t ka, const integer_t kb, MatrixAB& ab,
            const MatrixBB& bb, MatrixX& x, integer_t& info,
            optimal_workspace work ) {
        invoke( vect, n, ka, kb, ab, bb, x, info, minimal_workspace() );
    }

    static integer_t min_size_work( const integer_t n ) {
        return 2*n;
    }
};


// template function to call sbgst
template< typename MatrixAB, typename MatrixBB, typename MatrixX,
        typename Workspace >
inline integer_t sbgst( const char vect, const integer_t n,
        const integer_t ka, const integer_t kb, MatrixAB& ab,
        const MatrixBB& bb, MatrixX& x, Workspace work ) {
    typedef typename traits::matrix_traits< MatrixAB >::value_type value_type;
    integer_t info(0);
    sbgst_impl< value_type >::invoke( vect, n, ka, kb, ab, bb, x, info,
            work );
    return info;
}

// template function to call sbgst, default workspace type
template< typename MatrixAB, typename MatrixBB, typename MatrixX >
inline integer_t sbgst( const char vect, const integer_t n,
        const integer_t ka, const integer_t kb, MatrixAB& ab,
        const MatrixBB& bb, MatrixX& x ) {
    typedef typename traits::matrix_traits< MatrixAB >::value_type value_type;
    integer_t info(0);
    sbgst_impl< value_type >::invoke( vect, n, ka, kb, ab, bb, x, info,
            optimal_workspace() );
    return info;
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
