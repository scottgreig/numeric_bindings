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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_HEGVX_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_HEGVX_HPP

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

inline void hegvx( const integer_t itype, const char jobz, const char range,
        const char uplo, const integer_t n, traits::complex_f* a,
        const integer_t lda, traits::complex_f* b, const integer_t ldb,
        const float vl, const float vu, const integer_t il,
        const integer_t iu, const float abstol, integer_t& m, float* w,
        traits::complex_f* z, const integer_t ldz, traits::complex_f* work,
        const integer_t lwork, float* rwork, integer_t* iwork,
        integer_t* ifail, integer_t& info ) {
    LAPACK_CHEGVX( &itype, &jobz, &range, &uplo, &n, traits::complex_ptr(a),
            &lda, traits::complex_ptr(b), &ldb, &vl, &vu, &il, &iu, &abstol,
            &m, w, traits::complex_ptr(z), &ldz, traits::complex_ptr(work),
            &lwork, rwork, iwork, ifail, &info );
}
inline void hegvx( const integer_t itype, const char jobz, const char range,
        const char uplo, const integer_t n, traits::complex_d* a,
        const integer_t lda, traits::complex_d* b, const integer_t ldb,
        const double vl, const double vu, const integer_t il,
        const integer_t iu, const double abstol, integer_t& m, double* w,
        traits::complex_d* z, const integer_t ldz, traits::complex_d* work,
        const integer_t lwork, double* rwork, integer_t* iwork,
        integer_t* ifail, integer_t& info ) {
    LAPACK_ZHEGVX( &itype, &jobz, &range, &uplo, &n, traits::complex_ptr(a),
            &lda, traits::complex_ptr(b), &ldb, &vl, &vu, &il, &iu, &abstol,
            &m, w, traits::complex_ptr(z), &ldz, traits::complex_ptr(work),
            &lwork, rwork, iwork, ifail, &info );
}
} // namespace detail

// value-type based template
template< typename ValueType >
struct hegvx_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorW,
            typename MatrixZ, typename VectorIFAIL, typename WORK,
            typename RWORK, typename IWORK >
    static void invoke( const integer_t itype, const char jobz,
            const char range, const integer_t n, MatrixA& a, MatrixB& b,
            const real_type vl, const real_type vu, const integer_t il,
            const integer_t iu, const real_type abstol, integer_t& m,
            VectorW& w, MatrixZ& z, VectorIFAIL& ifail, integer_t& info,
            detail::workspace3< WORK, RWORK, IWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixZ >::value_type >::value) );
        BOOST_ASSERT( jobz == 'N' || jobz == 'V' );
        BOOST_ASSERT( range == 'A' || range == 'V' || range == 'I' );
        BOOST_ASSERT( traits::matrix_uplo_tag(a) == 'U' ||
                traits::matrix_uplo_tag(a) == 'L' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::leading_dimension(a) >= std::max<
                std::ptrdiff_t >(1,n) );
        BOOST_ASSERT( traits::leading_dimension(b) >= std::max<
                std::ptrdiff_t >(1,n) );
        BOOST_ASSERT( traits::vector_size(w) >= n );
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_work( n ));
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_rwork( n ));
        BOOST_ASSERT( traits::vector_size(work.select(integer_t())) >=
                min_size_iwork( n ));
        detail::hegvx( itype, jobz, range, traits::matrix_uplo_tag(a), n,
                traits::matrix_storage(a), traits::leading_dimension(a),
                traits::matrix_storage(b), traits::leading_dimension(b), vl,
                vu, il, iu, abstol, m, traits::vector_storage(w),
                traits::matrix_storage(z), traits::leading_dimension(z),
                traits::vector_storage(work.select(value_type())),
                traits::vector_size(work.select(value_type())),
                traits::vector_storage(work.select(real_type())),
                traits::vector_storage(work.select(integer_t())),
                traits::vector_storage(ifail), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorW,
            typename MatrixZ, typename VectorIFAIL >
    static void invoke( const integer_t itype, const char jobz,
            const char range, const integer_t n, MatrixA& a, MatrixB& b,
            const real_type vl, const real_type vu, const integer_t il,
            const integer_t iu, const real_type abstol, integer_t& m,
            VectorW& w, MatrixZ& z, VectorIFAIL& ifail, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work( n ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork( n ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( n ) );
        invoke( itype, jobz, range, n, a, b, vl, vu, il, iu, abstol, m, w, z,
                ifail, info, workspace( tmp_work, tmp_rwork, tmp_iwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorW,
            typename MatrixZ, typename VectorIFAIL >
    static void invoke( const integer_t itype, const char jobz,
            const char range, const integer_t n, MatrixA& a, MatrixB& b,
            const real_type vl, const real_type vu, const integer_t il,
            const integer_t iu, const real_type abstol, integer_t& m,
            VectorW& w, MatrixZ& z, VectorIFAIL& ifail, integer_t& info,
            optimal_workspace work ) {
        value_type opt_size_work;
        traits::detail::array< real_type > tmp_rwork( min_size_rwork( n ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( n ) );
        detail::hegvx( itype, jobz, range, traits::matrix_uplo_tag(a), n,
                traits::matrix_storage(a), traits::leading_dimension(a),
                traits::matrix_storage(b), traits::leading_dimension(b), vl,
                vu, il, iu, abstol, m, traits::vector_storage(w),
                traits::matrix_storage(z), traits::leading_dimension(z),
                &opt_size_work, -1, traits::vector_storage(tmp_rwork),
                traits::vector_storage(tmp_iwork),
                traits::vector_storage(ifail), info );
        traits::detail::array< value_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        invoke( itype, jobz, range, n, a, b, vl, vu, il, iu, abstol, m, w, z,
                ifail, info, workspace( tmp_work, tmp_rwork, tmp_iwork ) );
    }

    static integer_t min_size_work( const integer_t n ) {
        return std::max( 1, 2*n );
    }

    static integer_t min_size_rwork( const integer_t n ) {
        return 7*n;
    }

    static integer_t min_size_iwork( const integer_t n ) {
        return 5*n;
    }
};


// template function to call hegvx
template< typename MatrixA, typename MatrixB, typename VectorW,
        typename MatrixZ, typename VectorIFAIL, typename Workspace >
inline integer_t hegvx( const integer_t itype, const char jobz,
        const char range, const integer_t n, MatrixA& a, MatrixB& b,
        const typename traits::type_traits< typename traits::matrix_traits<
        MatrixA >::value_type >::real_type vl,
        const typename traits::type_traits< typename traits::matrix_traits<
        MatrixA >::value_type >::real_type vu, const integer_t il,
        const integer_t iu, const typename traits::type_traits<
        typename traits::matrix_traits<
        MatrixA >::value_type >::real_type abstol, integer_t& m, VectorW& w,
        MatrixZ& z, VectorIFAIL& ifail, Workspace work ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    hegvx_impl< value_type >::invoke( itype, jobz, range, n, a, b, vl,
            vu, il, iu, abstol, m, w, z, ifail, info, work );
    return info;
}

// template function to call hegvx, default workspace type
template< typename MatrixA, typename MatrixB, typename VectorW,
        typename MatrixZ, typename VectorIFAIL >
inline integer_t hegvx( const integer_t itype, const char jobz,
        const char range, const integer_t n, MatrixA& a, MatrixB& b,
        const typename traits::type_traits< typename traits::matrix_traits<
        MatrixA >::value_type >::real_type vl,
        const typename traits::type_traits< typename traits::matrix_traits<
        MatrixA >::value_type >::real_type vu, const integer_t il,
        const integer_t iu, const typename traits::type_traits<
        typename traits::matrix_traits<
        MatrixA >::value_type >::real_type abstol, integer_t& m, VectorW& w,
        MatrixZ& z, VectorIFAIL& ifail ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    hegvx_impl< value_type >::invoke( itype, jobz, range, n, a, b, vl,
            vu, il, iu, abstol, m, w, z, ifail, info, optimal_workspace() );
    return info;
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
