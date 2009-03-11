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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_HBGVX_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_HBGVX_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/lapack/lapack.h>
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
    inline void hbgvx( char const jobz, char const range, char const uplo,
            integer_t const n, integer_t const ka, integer_t const kb,
            traits::complex_f* ab, integer_t const ldab,
            traits::complex_f* bb, integer_t const ldbb, traits::complex_f* q,
            integer_t const ldq, float const vl, float const vu,
            integer_t const il, integer_t const iu, float const abstol,
            integer_t& m, float* w, traits::complex_f* z, integer_t const ldz,
            traits::complex_f* work, float* rwork, integer_t* iwork,
            integer_t* ifail, integer_t& info ) {
        LAPACK_CHBGVX( &jobz, &range, &uplo, &n, &ka, &kb,
                traits::complex_ptr(ab), &ldab, traits::complex_ptr(bb),
                &ldbb, traits::complex_ptr(q), &ldq, &vl, &vu, &il, &iu,
                &abstol, &m, w, traits::complex_ptr(z), &ldz,
                traits::complex_ptr(work), rwork, iwork, ifail, &info );
    }
    inline void hbgvx( char const jobz, char const range, char const uplo,
            integer_t const n, integer_t const ka, integer_t const kb,
            traits::complex_d* ab, integer_t const ldab,
            traits::complex_d* bb, integer_t const ldbb, traits::complex_d* q,
            integer_t const ldq, double const vl, double const vu,
            integer_t const il, integer_t const iu, double const abstol,
            integer_t& m, double* w, traits::complex_d* z,
            integer_t const ldz, traits::complex_d* work, double* rwork,
            integer_t* iwork, integer_t* ifail, integer_t& info ) {
        LAPACK_ZHBGVX( &jobz, &range, &uplo, &n, &ka, &kb,
                traits::complex_ptr(ab), &ldab, traits::complex_ptr(bb),
                &ldbb, traits::complex_ptr(q), &ldq, &vl, &vu, &il, &iu,
                &abstol, &m, w, traits::complex_ptr(z), &ldz,
                traits::complex_ptr(work), rwork, iwork, ifail, &info );
    }
}

// value-type based template
template< typename ValueType >
struct hbgvx_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixAB, typename MatrixBB, typename MatrixQ,
            typename VectorW, typename MatrixZ, typename VectorIFAIL,
            typename WORK, typename RWORK, typename IWORK >
    static void compute( char const jobz, char const range, integer_t const n,
            integer_t const ka, integer_t const kb, MatrixAB& ab,
            MatrixBB& bb, MatrixQ& q, real_type const vl, real_type const vu,
            integer_t const il, integer_t const iu, real_type const abstol,
            integer_t& m, VectorW& w, MatrixZ& z, VectorIFAIL& ifail,
            integer_t& info, detail::workspace3< WORK, RWORK, IWORK > work ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::matrix_traits<
                MatrixBB >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::matrix_traits<
                MatrixQ >::value_type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::matrix_traits<
                MatrixAB >::value_type, typename traits::matrix_traits<
                MatrixZ >::value_type >::value) );
        BOOST_ASSERT( jobz == 'N' || jobz == 'V' );
        BOOST_ASSERT( range == 'A' || range == 'V' || range == 'I' );
        BOOST_ASSERT( traits::matrix_uplo_tag(ab) == 'U' ||
                traits::matrix_uplo_tag(ab) == 'L' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( ka >= 0 );
        BOOST_ASSERT( kb >= 0 );
        BOOST_ASSERT( traits::leading_dimension(ab) >= ka+1 );
        BOOST_ASSERT( traits::leading_dimension(bb) >= kb+1 );
        BOOST_ASSERT( traits::vector_size(work.select(value_type())) >=
                min_size_work( n ));
        BOOST_ASSERT( traits::vector_size(work.select(real_type())) >=
                min_size_rwork( n ));
        BOOST_ASSERT( traits::vector_size(work.select(integer_t())) >=
                min_size_iwork( n ));
        detail::hbgvx( jobz, range, traits::matrix_uplo_tag(ab), n, ka, kb,
                traits::matrix_storage(ab), traits::leading_dimension(ab),
                traits::matrix_storage(bb), traits::leading_dimension(bb),
                traits::matrix_storage(q), traits::leading_dimension(q), vl,
                vu, il, iu, abstol, m, traits::vector_storage(w),
                traits::matrix_storage(z), traits::leading_dimension(z),
                traits::vector_storage(work.select(value_type())),
                traits::vector_storage(work.select(real_type())),
                traits::vector_storage(work.select(integer_t())),
                traits::vector_storage(ifail), info );
    }

    // minimal workspace specialization
    template< typename MatrixAB, typename MatrixBB, typename MatrixQ,
            typename VectorW, typename MatrixZ, typename VectorIFAIL >
    static void compute( char const jobz, char const range, integer_t const n,
            integer_t const ka, integer_t const kb, MatrixAB& ab,
            MatrixBB& bb, MatrixQ& q, real_type const vl, real_type const vu,
            integer_t const il, integer_t const iu, real_type const abstol,
            integer_t& m, VectorW& w, MatrixZ& z, VectorIFAIL& ifail,
            integer_t& info, minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work( n ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork( n ) );
        traits::detail::array< integer_t > tmp_iwork( min_size_iwork( n ) );
        compute( jobz, range, n, ka, kb, ab, bb, q, vl, vu, il, iu, abstol, m,
                w, z, ifail, info, workspace( tmp_work, tmp_rwork,
                tmp_iwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixAB, typename MatrixBB, typename MatrixQ,
            typename VectorW, typename MatrixZ, typename VectorIFAIL >
    static void compute( char const jobz, char const range, integer_t const n,
            integer_t const ka, integer_t const kb, MatrixAB& ab,
            MatrixBB& bb, MatrixQ& q, real_type const vl, real_type const vu,
            integer_t const il, integer_t const iu, real_type const abstol,
            integer_t& m, VectorW& w, MatrixZ& z, VectorIFAIL& ifail,
            integer_t& info, optimal_workspace work ) {
        compute( jobz, range, n, ka, kb, ab, bb, q, vl, vu, il, iu, abstol, m,
                w, z, ifail, info, minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n ) {
        return n;
    }

    static integer_t min_size_rwork( integer_t const n ) {
        return 7*n;
    }

    static integer_t min_size_iwork( integer_t const n ) {
        return 5*n;
    }
};


// template function to call hbgvx
template< typename MatrixAB, typename MatrixBB, typename MatrixQ,
        typename VectorW, typename MatrixZ, typename VectorIFAIL,
        typename Workspace >
inline integer_t hbgvx( char const jobz, char const range,
        integer_t const n, integer_t const ka, integer_t const kb,
        MatrixAB& ab, MatrixBB& bb, MatrixQ& q,
        typename traits::matrix_traits< MatrixAB >::value_type const vl,
        typename traits::matrix_traits< MatrixAB >::value_type const vu,
        integer_t const il, integer_t const iu,
        typename traits::matrix_traits< MatrixAB >::value_type const abstol,
        integer_t& m, VectorW& w, MatrixZ& z, VectorIFAIL& ifail,
        Workspace work = optimal_workspace() ) {
    typedef typename traits::matrix_traits< MatrixAB >::value_type value_type;
    integer_t info(0);
    hbgvx_impl< value_type >::compute( jobz, range, n, ka, kb, ab, bb, q,
            vl, vu, il, iu, abstol, m, w, z, ifail, info, work );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif