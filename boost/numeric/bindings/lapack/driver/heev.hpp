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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_HEEV_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_HEEV_HPP

#include <boost/assert.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/detail/utils.hpp>
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

inline void heev( const char jobz, const char uplo, const integer_t n,
        traits::complex_f* a, const integer_t lda, float* w,
        traits::complex_f* work, const integer_t lwork, float* rwork,
        integer_t& info ) {
    LAPACK_CHEEV( &jobz, &uplo, &n, traits::complex_ptr(a), &lda, w,
            traits::complex_ptr(work), &lwork, rwork, &info );
}
inline void heev( const char jobz, const char uplo, const integer_t n,
        traits::complex_d* a, const integer_t lda, double* w,
        traits::complex_d* work, const integer_t lwork, double* rwork,
        integer_t& info ) {
    LAPACK_ZHEEV( &jobz, &uplo, &n, traits::complex_ptr(a), &lda, w,
            traits::complex_ptr(work), &lwork, rwork, &info );
}
} // namespace detail

// value-type based template
template< typename ValueType >
struct heev_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename VectorW, typename WORK,
            typename RWORK >
    static void invoke( const char jobz, MatrixA& a, VectorW& w,
            integer_t& info, detail::workspace2< WORK, RWORK > work ) {
        BOOST_ASSERT( jobz == 'N' || jobz == 'V' );
        BOOST_ASSERT( traits::matrix_uplo_tag(a) == 'U' ||
                traits::matrix_uplo_tag(a) == 'L' );
        BOOST_ASSERT( traits::matrix_num_columns(a) >= 0 );
        BOOST_ASSERT( traits::leading_dimension(a) >= std::max<
                std::ptrdiff_t >(1,traits::matrix_num_columns(a)) );
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_work( traits::matrix_num_columns(a) ));
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_rwork( traits::matrix_num_columns(a) ));
        detail::heev( jobz, traits::matrix_uplo_tag(a),
                traits::matrix_num_columns(a), traits::matrix_storage(a),
                traits::leading_dimension(a), traits::vector_storage(w),
                traits::vector_storage(work.select(value_type())),
                traits::vector_size(work.select(value_type())),
                traits::vector_storage(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename VectorW >
    static void invoke( const char jobz, MatrixA& a, VectorW& w,
            integer_t& info, minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work(
                traits::matrix_num_columns(a) ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork(
                traits::matrix_num_columns(a) ) );
        invoke( jobz, a, w, info, workspace( tmp_work, tmp_rwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename VectorW >
    static void invoke( const char jobz, MatrixA& a, VectorW& w,
            integer_t& info, optimal_workspace work ) {
        value_type opt_size_work;
        traits::detail::array< real_type > tmp_rwork( min_size_rwork(
                traits::matrix_num_columns(a) ) );
        detail::heev( jobz, traits::matrix_uplo_tag(a),
                traits::matrix_num_columns(a), traits::matrix_storage(a),
                traits::leading_dimension(a), traits::vector_storage(w),
                &opt_size_work, -1, traits::vector_storage(tmp_rwork), info );
        traits::detail::array< value_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        invoke( jobz, a, w, info, workspace( tmp_work, tmp_rwork ) );
    }

    static integer_t min_size_work( const integer_t n ) {
        return std::max( 1, 2*n-1 );
    }

    static integer_t min_size_rwork( const integer_t n ) {
        return std::max( 1, 3*n-2 );
    }
};


// template function to call heev
template< typename MatrixA, typename VectorW, typename Workspace >
inline integer_t heev( const char jobz, MatrixA& a, VectorW& w,
        Workspace work ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    heev_impl< value_type >::invoke( jobz, a, w, info, work );
    return info;
}

// template function to call heev, default workspace type
template< typename MatrixA, typename VectorW >
inline integer_t heev( const char jobz, MatrixA& a, VectorW& w ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    heev_impl< value_type >::invoke( jobz, a, w, info,
            optimal_workspace() );
    return info;
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
