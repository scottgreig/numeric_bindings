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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_SPGVX_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_SPGVX_HPP

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

inline void spgvx( const integer_t itype, const char jobz, const char range,
        const char uplo, const integer_t n, float* ap, float* bp,
        const float vl, const float vu, const integer_t il,
        const integer_t iu, const float abstol, integer_t& m, float* w,
        float* z, const integer_t ldz, float* work, integer_t* iwork,
        integer_t* ifail, integer_t& info ) {
    LAPACK_SSPGVX( &itype, &jobz, &range, &uplo, &n, ap, bp, &vl, &vu, &il,
            &iu, &abstol, &m, w, z, &ldz, work, iwork, ifail, &info );
}
inline void spgvx( const integer_t itype, const char jobz, const char range,
        const char uplo, const integer_t n, double* ap, double* bp,
        const double vl, const double vu, const integer_t il,
        const integer_t iu, const double abstol, integer_t& m, double* w,
        double* z, const integer_t ldz, double* work, integer_t* iwork,
        integer_t* ifail, integer_t& info ) {
    LAPACK_DSPGVX( &itype, &jobz, &range, &uplo, &n, ap, bp, &vl, &vu, &il,
            &iu, &abstol, &m, w, z, &ldz, work, iwork, ifail, &info );
}
} // namespace detail

// value-type based template
template< typename ValueType >
struct spgvx_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixAP, typename MatrixBP, typename VectorW,
            typename MatrixZ, typename VectorIFAIL, typename WORK,
            typename IWORK >
    static void invoke( const integer_t itype, const char jobz,
            const char range, const integer_t n, MatrixAP& ap, MatrixBP& bp,
            const real_type vl, const real_type vu, const integer_t il,
            const integer_t iu, const real_type abstol, integer_t& m,
            VectorW& w, MatrixZ& z, VectorIFAIL& ifail, integer_t& info,
            detail::workspace2< WORK, IWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAP >::value_type, typename traits::matrix_traits<
                MatrixBP >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAP >::value_type, typename traits::vector_traits<
                VectorW >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAP >::value_type, typename traits::matrix_traits<
                MatrixZ >::value_type >::value) );
        BOOST_ASSERT( jobz == 'N' || jobz == 'V' );
        BOOST_ASSERT( range == 'A' || range == 'V' || range == 'I' );
        BOOST_ASSERT( traits::matrix_uplo_tag(ap) == 'U' ||
                traits::matrix_uplo_tag(ap) == 'L' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::vector_size(w) >= n );
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_work( n ));
        BOOST_ASSERT( traits::vector_size(work.select(integer_t())) >=
                min_size_iwork( n ));
        detail::spgvx( itype, jobz, range, traits::matrix_uplo_tag(ap), n,
                traits::matrix_storage(ap), traits::matrix_storage(bp), vl,
                vu, il, iu, abstol, m, traits::vector_storage(w),
                traits::matrix_storage(z), traits::leading_dimension(z),
                traits::vector_storage(work.select(real_type())),
                traits::vector_storage(work.select(integer_t())),
                traits::vector_storage(ifail), info );
    }

    // minimal workspace specialization
    template< typename MatrixAP, typename MatrixBP, typename VectorW,
            typename MatrixZ, typename VectorIFAIL >
    static void invoke( const integer_t itype, const char jobz,
            const char range, const integer_t n, MatrixAP& ap, MatrixBP& bp,
            const real_type vl, const real_type vu, const integer_t il,
            const integer_t iu, const real_type abstol, integer_t& m,
            VectorW& w, MatrixZ& z, VectorIFAIL& ifail, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work( n ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( n ) );
        invoke( itype, jobz, range, n, ap, bp, vl, vu, il, iu, abstol, m, w,
                z, ifail, info, workspace( tmp_work, tmp_iwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixAP, typename MatrixBP, typename VectorW,
            typename MatrixZ, typename VectorIFAIL >
    static void invoke( const integer_t itype, const char jobz,
            const char range, const integer_t n, MatrixAP& ap, MatrixBP& bp,
            const real_type vl, const real_type vu, const integer_t il,
            const integer_t iu, const real_type abstol, integer_t& m,
            VectorW& w, MatrixZ& z, VectorIFAIL& ifail, integer_t& info,
            optimal_workspace work ) {
        invoke( itype, jobz, range, n, ap, bp, vl, vu, il, iu, abstol, m, w,
                z, ifail, info, minimal_workspace() );
    }

    static integer_t min_size_work( const integer_t n ) {
        return 8*n;
    }

    static integer_t min_size_iwork( const integer_t n ) {
        return 5*n;
    }
};


// template function to call spgvx
template< typename MatrixAP, typename MatrixBP, typename VectorW,
        typename MatrixZ, typename VectorIFAIL, typename Workspace >
inline integer_t spgvx( const integer_t itype, const char jobz,
        const char range, const integer_t n, MatrixAP& ap, MatrixBP& bp,
        const typename traits::type_traits< typename traits::matrix_traits<
        MatrixAP >::value_type >::real_type vl,
        const typename traits::type_traits< typename traits::matrix_traits<
        MatrixAP >::value_type >::real_type vu, const integer_t il,
        const integer_t iu, const typename traits::type_traits<
        typename traits::matrix_traits<
        MatrixAP >::value_type >::real_type abstol, integer_t& m, VectorW& w,
        MatrixZ& z, VectorIFAIL& ifail, Workspace work ) {
    typedef typename traits::matrix_traits< MatrixAP >::value_type value_type;
    integer_t info(0);
    spgvx_impl< value_type >::invoke( itype, jobz, range, n, ap, bp, vl,
            vu, il, iu, abstol, m, w, z, ifail, info, work );
    return info;
}

// template function to call spgvx, default workspace type
template< typename MatrixAP, typename MatrixBP, typename VectorW,
        typename MatrixZ, typename VectorIFAIL >
inline integer_t spgvx( const integer_t itype, const char jobz,
        const char range, const integer_t n, MatrixAP& ap, MatrixBP& bp,
        const typename traits::type_traits< typename traits::matrix_traits<
        MatrixAP >::value_type >::real_type vl,
        const typename traits::type_traits< typename traits::matrix_traits<
        MatrixAP >::value_type >::real_type vu, const integer_t il,
        const integer_t iu, const typename traits::type_traits<
        typename traits::matrix_traits<
        MatrixAP >::value_type >::real_type abstol, integer_t& m, VectorW& w,
        MatrixZ& z, VectorIFAIL& ifail ) {
    typedef typename traits::matrix_traits< MatrixAP >::value_type value_type;
    integer_t info(0);
    spgvx_impl< value_type >::invoke( itype, jobz, range, n, ap, bp, vl,
            vu, il, iu, abstol, m, w, z, ifail, info, optimal_workspace() );
    return info;
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
