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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_GEGV_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_GEGV_HPP

#include <boost/numeric/bindings/lapack/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
#include <boost/numeric/bindings/traits/detail/utils.hpp>
#include <boost/numeric/bindings/traits/is_complex.hpp>
#include <boost/numeric/bindings/traits/is_real.hpp>
#include <boost/numeric/bindings/traits/traits.hpp>
#include <boost/numeric/bindings/traits/type_traits.hpp>
#include <boost/static_assert.hpp
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>
#include <cassert>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//$DESCRIPTION

// overloaded functions to call lapack
namespace detail {
    inline void gegv( char const jobvl, char const jobvr, integer_t const n,
            float* a, integer_t const lda, float* b, integer_t const ldb,
            float* alphar, float* alphai, float* beta, float* vl,
            integer_t const ldvl, float* vr, integer_t const ldvr,
            float* work, integer_t const lwork, integer_t& info ) {
        LAPACK_SGEGV( &jobvl, &jobvr, &n, a, &lda, b, &ldb, alphar, alphai,
                beta, vl, &ldvl, vr, &ldvr, work, &lwork, &info );
    }
    inline void gegv( char const jobvl, char const jobvr, integer_t const n,
            double* a, integer_t const lda, double* b, integer_t const ldb,
            double* alphar, double* alphai, double* beta, double* vl,
            integer_t const ldvl, double* vr, integer_t const ldvr,
            double* work, integer_t const lwork, integer_t& info ) {
        LAPACK_DGEGV( &jobvl, &jobvr, &n, a, &lda, b, &ldb, alphar, alphai,
                beta, vl, &ldvl, vr, &ldvr, work, &lwork, &info );
    }
    inline void gegv( char const jobvl, char const jobvr, integer_t const n,
            traits::complex_f* a, integer_t const lda, traits::complex_f* b,
            integer_t const ldb, traits::complex_f* alpha,
            traits::complex_f* beta, traits::complex_f* vl,
            integer_t const ldvl, traits::complex_f* vr, integer_t const ldvr,
            traits::complex_f* work, integer_t const lwork, float* rwork,
            integer_t& info ) {
        LAPACK_CGEGV( &jobvl, &jobvr, &n, traits::complex_ptr(a), &lda,
                traits::complex_ptr(b), &ldb, traits::complex_ptr(alpha),
                traits::complex_ptr(beta), traits::complex_ptr(vl), &ldvl,
                traits::complex_ptr(vr), &ldvr, traits::complex_ptr(work),
                &lwork, rwork, &info );
    }
    inline void gegv( char const jobvl, char const jobvr, integer_t const n,
            traits::complex_d* a, integer_t const lda, traits::complex_d* b,
            integer_t const ldb, traits::complex_d* alpha,
            traits::complex_d* beta, traits::complex_d* vl,
            integer_t const ldvl, traits::complex_d* vr, integer_t const ldvr,
            traits::complex_d* work, integer_t const lwork, double* rwork,
            integer_t& info ) {
        LAPACK_ZGEGV( &jobvl, &jobvr, &n, traits::complex_ptr(a), &lda,
                traits::complex_ptr(b), &ldb, traits::complex_ptr(alpha),
                traits::complex_ptr(beta), traits::complex_ptr(vl), &ldvl,
                traits::complex_ptr(vr), &ldvr, traits::complex_ptr(work),
                &lwork, rwork, &info );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct gegv_impl{};

// real specialization
template< typename ValueType >
struct gegv_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorALPHAR,
            typename VectorALPHAI, typename VectorBETA, typename MatrixVL,
            typename MatrixVR, typename WORK >
    static void compute( char const jobvl, char const jobvr, MatrixA& a,
            MatrixB& b, VectorALPHAR& alphar, VectorALPHAI& alphai,
            VectorBETA& beta, MatrixVL& vl, MatrixVR& vr, integer_t& info,
            detail::workspace1< WORK > work ) {
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type > );
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorALPHAR >::value_type > );
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorALPHAI >::value_type > );
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorBETA >::value_type > );
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixVL >::value_type > );
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixVR >::value_type > );
#ifndef NDEBUG
        assert( jobvl == 'N' || jobvl == 'V' );
        assert( jobvr == 'N' || jobvr == 'V' );
        assert( traits::matrix_size2(a) >= 0 );
        assert( traits::leading_dimension(a) >= std::max(1,
                traits::matrix_size2(a)) );
        assert( traits::leading_dimension(b) >= std::max(1,
                traits::matrix_size2(a)) );
        assert( traits::vector_size(alphar) >= traits::matrix_size2(a) );
        assert( traits::vector_size(beta) >= traits::matrix_size2(a) );
        assert( traits::vector_size(work.select(real_type()) >= min_size_work(
                traits::matrix_size2(a) )));
#endif
        detail::gegv( jobvl, jobvr, traits::matrix_size2(a),
                traits::matrix_storage(a), traits::leading_dimension(a),
                traits::matrix_storage(b), traits::leading_dimension(b),
                traits::vector_storage(alphar),
                traits::vector_storage(alphai), traits::vector_storage(beta),
                traits::matrix_storage(vl), traits::leading_dimension(vl),
                traits::matrix_storage(vr), traits::leading_dimension(vr),
                traits::vector_storage(work.select(real_type())),
                traits::vector_size(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorALPHAR,
            typename VectorALPHAI, typename VectorBETA, typename MatrixVL,
            typename MatrixVR >
    static void compute( char const jobvl, char const jobvr, MatrixA& a,
            MatrixB& b, VectorALPHAR& alphar, VectorALPHAI& alphai,
            VectorBETA& beta, MatrixVL& vl, MatrixVR& vr, integer_t& info,
            minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work(
                traits::matrix_size2(a) ) );
        compute( jobvl, jobvr, a, b, alphar, alphai, beta, vl, vr, info,
                workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorALPHAR,
            typename VectorALPHAI, typename VectorBETA, typename MatrixVL,
            typename MatrixVR >
    static void compute( char const jobvl, char const jobvr, MatrixA& a,
            MatrixB& b, VectorALPHAR& alphar, VectorALPHAI& alphai,
            VectorBETA& beta, MatrixVL& vl, MatrixVR& vr, integer_t& info,
            optimal_workspace work ) {
        real_type opt_size_work;
        detail::gegv( jobvl, jobvr, traits::matrix_size2(a),
                traits::matrix_storage(a), traits::leading_dimension(a),
                traits::matrix_storage(b), traits::leading_dimension(b),
                traits::vector_storage(alphar),
                traits::vector_storage(alphai), traits::vector_storage(beta),
                traits::matrix_storage(vl), traits::leading_dimension(vl),
                traits::matrix_storage(vr), traits::leading_dimension(vr),
                &opt_size_work, -1, info );
        traits::detail::array< real_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        compute( jobvl, jobvr, a, b, alphar, alphai, beta, vl, vr, info,
                workspace( tmp_work ) );
    }

    static integer_t min_size_work( integer_t const n ) {
        return std::max( 1, 8*n );
    }
};

// complex specialization
template< typename ValueType >
struct gegv_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorALPHA,
            typename VectorBETA, typename MatrixVL, typename MatrixVR,
            typename WORK, typename RWORK >
    static void compute( char const jobvl, char const jobvr, MatrixA& a,
            MatrixB& b, VectorALPHA& alpha, VectorBETA& beta, MatrixVL& vl,
            MatrixVR& vr, integer_t& info, detail::workspace2< WORK,
            RWORK > work ) {
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type > );
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorALPHA >::value_type > );
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorBETA >::value_type > );
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixVL >::value_type > );
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixVR >::value_type > );
#ifndef NDEBUG
        assert( jobvl == 'N' || jobvl == 'V' );
        assert( jobvr == 'N' || jobvr == 'V' );
        assert( traits::matrix_size2(a) >= 0 );
        assert( traits::leading_dimension(a) >= std::max(1,
                traits::matrix_size2(a)) );
        assert( traits::leading_dimension(b) >= std::max(1,
                traits::matrix_size2(a)) );
        assert( traits::vector_size(alpha) >= traits::matrix_size2(a) );
        assert( traits::vector_size(beta) >= traits::matrix_size2(a) );
        assert( traits::vector_size(work.select(value_type()) >=
                min_size_work( traits::matrix_size2(a) )));
        assert( traits::vector_size(work.select(real_type()) >=
                min_size_rwork( traits::matrix_size2(a) )));
#endif
        detail::gegv( jobvl, jobvr, traits::matrix_size2(a),
                traits::matrix_storage(a), traits::leading_dimension(a),
                traits::matrix_storage(b), traits::leading_dimension(b),
                traits::vector_storage(alpha), traits::vector_storage(beta),
                traits::matrix_storage(vl), traits::leading_dimension(vl),
                traits::matrix_storage(vr), traits::leading_dimension(vr),
                traits::vector_storage(work.select(value_type())),
                traits::vector_size(work.select(value_type())),
                traits::vector_storage(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorALPHA,
            typename VectorBETA, typename MatrixVL, typename MatrixVR >
    static void compute( char const jobvl, char const jobvr, MatrixA& a,
            MatrixB& b, VectorALPHA& alpha, VectorBETA& beta, MatrixVL& vl,
            MatrixVR& vr, integer_t& info, minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work(
                traits::matrix_size2(a) ) );
        traits::detail::array< real_type > tmp_rwork( min_size_rwork(
                traits::matrix_size2(a) ) );
        compute( jobvl, jobvr, a, b, alpha, beta, vl, vr, info,
                workspace( tmp_work, tmp_rwork ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorALPHA,
            typename VectorBETA, typename MatrixVL, typename MatrixVR >
    static void compute( char const jobvl, char const jobvr, MatrixA& a,
            MatrixB& b, VectorALPHA& alpha, VectorBETA& beta, MatrixVL& vl,
            MatrixVR& vr, integer_t& info, optimal_workspace work ) {
        value_type opt_size_work;
        traits::detail::array< real_type > tmp_rwork( min_size_rwork(
                traits::matrix_size2(a) ) );
        detail::gegv( jobvl, jobvr, traits::matrix_size2(a),
                traits::matrix_storage(a), traits::leading_dimension(a),
                traits::matrix_storage(b), traits::leading_dimension(b),
                traits::vector_storage(alpha), traits::vector_storage(beta),
                traits::matrix_storage(vl), traits::leading_dimension(vl),
                traits::matrix_storage(vr), traits::leading_dimension(vr),
                &opt_size_work, -1, traits::vector_storage(tmp_rwork), info );
        traits::detail::array< value_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        compute( jobvl, jobvr, a, b, alpha, beta, vl, vr, info,
                workspace( tmp_work, tmp_rwork ) );
    }

    static integer_t min_size_work( integer_t const n ) {
        return std::max( 1, 2*n );
    }

    static integer_t min_size_rwork( integer_t const n ) {
        return 8*n;
    }
};


// template function to call gegv
template< typename MatrixA, typename MatrixB, typename VectorALPHAR,
        typename VectorALPHAI, typename VectorBETA, typename MatrixVL,
        typename MatrixVR, typename Workspace >
inline integer_t gegv( char const jobvl, char const jobvr, MatrixA& a,
        MatrixB& b, VectorALPHAR& alphar, VectorALPHAI& alphai,
        VectorBETA& beta, MatrixVL& vl, MatrixVR& vr,
        Workspace work = optimal_workspace() ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    gegv_impl< value_type >::compute( jobvl, jobvr, a, b, alphar,
            alphai, beta, vl, vr, info, work );
    return info;
}
// template function to call gegv
template< typename MatrixA, typename MatrixB, typename VectorALPHA,
        typename VectorBETA, typename MatrixVL, typename MatrixVR,
        typename Workspace >
inline integer_t gegv( char const jobvl, char const jobvr, MatrixA& a,
        MatrixB& b, VectorALPHA& alpha, VectorBETA& beta, MatrixVL& vl,
        MatrixVR& vr, Workspace work = optimal_workspace() ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    gegv_impl< value_type >::compute( jobvl, jobvr, a, b, alpha, beta,
            vl, vr, info, work );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
