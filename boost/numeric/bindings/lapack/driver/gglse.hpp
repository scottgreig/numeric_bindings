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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_GGLSE_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_GGLSE_HPP

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
    inline void gglse( integer_t const m, integer_t const n,
            integer_t const p, float* a, integer_t const lda, float* b,
            integer_t const ldb, float* c, float* d, float* x, float* work,
            integer_t const lwork, integer_t& info ) {
        LAPACK_SGGLSE( &m, &n, &p, a, &lda, b, &ldb, c, d, x, work, &lwork,
                &info );
    }
    inline void gglse( integer_t const m, integer_t const n,
            integer_t const p, double* a, integer_t const lda, double* b,
            integer_t const ldb, double* c, double* d, double* x,
            double* work, integer_t const lwork, integer_t& info ) {
        LAPACK_DGGLSE( &m, &n, &p, a, &lda, b, &ldb, c, d, x, work, &lwork,
                &info );
    }
    inline void gglse( integer_t const m, integer_t const n,
            integer_t const p, traits::complex_f* a, integer_t const lda,
            traits::complex_f* b, integer_t const ldb, traits::complex_f* c,
            traits::complex_f* d, traits::complex_f* x,
            traits::complex_f* work, integer_t const lwork, integer_t& info ) {
        LAPACK_CGGLSE( &m, &n, &p, traits::complex_ptr(a), &lda,
                traits::complex_ptr(b), &ldb, traits::complex_ptr(c),
                traits::complex_ptr(d), traits::complex_ptr(x),
                traits::complex_ptr(work), &lwork, &info );
    }
    inline void gglse( integer_t const m, integer_t const n,
            integer_t const p, traits::complex_d* a, integer_t const lda,
            traits::complex_d* b, integer_t const ldb, traits::complex_d* c,
            traits::complex_d* d, traits::complex_d* x,
            traits::complex_d* work, integer_t const lwork, integer_t& info ) {
        LAPACK_ZGGLSE( &m, &n, &p, traits::complex_ptr(a), &lda,
                traits::complex_ptr(b), &ldb, traits::complex_ptr(c),
                traits::complex_ptr(d), traits::complex_ptr(x),
                traits::complex_ptr(work), &lwork, &info );
    }
}

// value-type based template
template< typename ValueType, typename Enable = void >
struct gglse_impl{};

// real specialization
template< typename ValueType >
struct gglse_impl< ValueType, typename boost::enable_if< traits::is_real<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorC,
            typename VectorD, typename VectorX, typename WORK >
    static void compute( MatrixA& a, MatrixB& b, VectorC& c, VectorD& d,
            VectorX& x, integer_t& info, detail::workspace1< WORK > work ) {
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type > );
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorC >::value_type > );
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorD >::value_type > );
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorX >::value_type > );
#ifndef NDEBUG
        assert( traits::matrix_size1(a) >= 0 );
        assert( traits::matrix_size2(b) >= 0 );
        assert( traits::leading_dimension(a) >= std::max(1,
                traits::matrix_size1(a)) );
        assert( traits::leading_dimension(b) >= std::max(1,
                traits::matrix_size1(b)) );
        assert( traits::vector_size(c) >= traits::matrix_size1(a) );
        assert( traits::vector_size(d) >= traits::matrix_size1(b) );
        assert( traits::vector_size(x) >= traits::matrix_size2(b) );
        assert( traits::vector_size(work.select(real_type()) >= min_size_work(
                traits::matrix_size1(a), traits::matrix_size2(b),
                traits::matrix_size1(b) )));
#endif
        detail::gglse( traits::matrix_size1(a), traits::matrix_size2(b),
                traits::matrix_size1(b), traits::matrix_storage(a),
                traits::leading_dimension(a), traits::matrix_storage(b),
                traits::leading_dimension(b), traits::vector_storage(c),
                traits::vector_storage(d), traits::vector_storage(x),
                traits::vector_storage(work.select(real_type())),
                traits::vector_size(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorC,
            typename VectorD, typename VectorX >
    static void compute( MatrixA& a, MatrixB& b, VectorC& c, VectorD& d,
            VectorX& x, integer_t& info, minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work(
                traits::matrix_size1(a), traits::matrix_size2(b),
                traits::matrix_size1(b) ) );
        compute( a, b, c, d, x, info, workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorC,
            typename VectorD, typename VectorX >
    static void compute( MatrixA& a, MatrixB& b, VectorC& c, VectorD& d,
            VectorX& x, integer_t& info, optimal_workspace work ) {
        real_type opt_size_work;
        detail::gglse( traits::matrix_size1(a), traits::matrix_size2(b),
                traits::matrix_size1(b), traits::matrix_storage(a),
                traits::leading_dimension(a), traits::matrix_storage(b),
                traits::leading_dimension(b), traits::vector_storage(c),
                traits::vector_storage(d), traits::vector_storage(x),
                &opt_size_work, -1, info );
        traits::detail::array< real_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        compute( a, b, c, d, x, info, workspace( tmp_work ) );
    }

    static integer_t min_size_work( integer_t const m, integer_t const n,
            integer_t const p ) {
        return std::max( 1, m+n+p );
    }
};

// complex specialization
template< typename ValueType >
struct gglse_impl< ValueType, typename boost::enable_if< traits::is_complex<ValueType> >::type > {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorC,
            typename VectorD, typename VectorX, typename WORK >
    static void compute( MatrixA& a, MatrixB& b, VectorC& c, VectorD& d,
            VectorX& x, integer_t& info, detail::workspace1< WORK > work ) {
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type > );
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorC >::value_type > );
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorD >::value_type > );
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::matrix_traits<
                MatrixA >::value_type, typename traits::vector_traits<
                VectorX >::value_type > );
#ifndef NDEBUG
        assert( traits::matrix_size1(a) >= 0 );
        assert( traits::matrix_size2(b) >= 0 );
        assert( traits::leading_dimension(a) >= std::max(1,
                traits::matrix_size1(a)) );
        assert( traits::leading_dimension(b) >= std::max(1,
                traits::matrix_size1(b)) );
        assert( traits::vector_size(c) >= traits::matrix_size1(a) );
        assert( traits::vector_size(d) >= traits::matrix_size1(b) );
        assert( traits::vector_size(x) >= traits::matrix_size2(b) );
        assert( traits::vector_size(work.select(value_type()) >=
                min_size_work( traits::matrix_size1(a),
                traits::matrix_size2(b), traits::matrix_size1(b) )));
#endif
        detail::gglse( traits::matrix_size1(a), traits::matrix_size2(b),
                traits::matrix_size1(b), traits::matrix_storage(a),
                traits::leading_dimension(a), traits::matrix_storage(b),
                traits::leading_dimension(b), traits::vector_storage(c),
                traits::vector_storage(d), traits::vector_storage(x),
                traits::vector_storage(work.select(value_type())),
                traits::vector_size(work.select(value_type())), info );
    }

    // minimal workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorC,
            typename VectorD, typename VectorX >
    static void compute( MatrixA& a, MatrixB& b, VectorC& c, VectorD& d,
            VectorX& x, integer_t& info, minimal_workspace work ) {
        traits::detail::array< value_type > tmp_work( min_size_work(
                traits::matrix_size1(a), traits::matrix_size2(b),
                traits::matrix_size1(b) ) );
        compute( a, b, c, d, x, info, workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename MatrixA, typename MatrixB, typename VectorC,
            typename VectorD, typename VectorX >
    static void compute( MatrixA& a, MatrixB& b, VectorC& c, VectorD& d,
            VectorX& x, integer_t& info, optimal_workspace work ) {
        value_type opt_size_work;
        detail::gglse( traits::matrix_size1(a), traits::matrix_size2(b),
                traits::matrix_size1(b), traits::matrix_storage(a),
                traits::leading_dimension(a), traits::matrix_storage(b),
                traits::leading_dimension(b), traits::vector_storage(c),
                traits::vector_storage(d), traits::vector_storage(x),
                &opt_size_work, -1, info );
        traits::detail::array< value_type > tmp_work(
                traits::detail::to_int( opt_size_work ) );
        compute( a, b, c, d, x, info, workspace( tmp_work ) );
    }

    static integer_t min_size_work( integer_t const m, integer_t const n,
            integer_t const p ) {
        return std::max( 1, m+n+p );
    }
};


// template function to call gglse
template< typename MatrixA, typename MatrixB, typename VectorC,
        typename VectorD, typename VectorX, typename Workspace >
inline integer_t gglse( MatrixA& a, MatrixB& b, VectorC& c, VectorD& d,
        VectorX& x, Workspace work = optimal_workspace() ) {
    typedef typename traits::matrix_traits< MatrixA >::value_type value_type;
    integer_t info(0);
    gglse_impl< value_type >::compute( a, b, c, d, x, info, work );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
