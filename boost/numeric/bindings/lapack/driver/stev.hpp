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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_STEV_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_STEV_HPP

#include <boost/numeric/bindings/lapack/lapack.h>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/traits/detail/array.hpp>
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
    inline void stev( char const jobz, integer_t const n, float* d, float* e,
            float* z, integer_t const ldz, float* work, integer_t& info ) {
        LAPACK_SSTEV( &jobz, &n, d, e, z, &ldz, work, &info );
    }
    inline void stev( char const jobz, integer_t const n, double* d,
            double* e, double* z, integer_t const ldz, double* work,
            integer_t& info ) {
        LAPACK_DSTEV( &jobz, &n, d, e, z, &ldz, work, &info );
    }
}

// value-type based template
template< typename ValueType >
struct stev_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // user-defined workspace specialization
    template< typename VectorD, typename VectorE, typename MatrixZ,
            typename WORK >
    static void compute( char const jobz, integer_t const n, VectorD& d,
            VectorE& e, MatrixZ& z, integer_t& info, detail::workspace1<
            WORK > work ) {
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::vector_traits<
                VectorE >::value_type > );
        BOOST_STATIC_ASSERT( boost::is_same< typename traits::vector_traits<
                VectorD >::value_type, typename traits::matrix_traits<
                MatrixZ >::value_type > );
#ifndef NDEBUG
        assert( jobz == 'N' || jobz == 'V' );
        assert( n >= 0 );
        assert( traits::vector_size(e) >= n-1 );
        assert( traits::vector_size(work.select(real_type()) >= min_size_work(
                n )));
#endif
        detail::stev( jobz, n, traits::vector_storage(d),
                traits::vector_storage(e), traits::matrix_storage(z),
                traits::leading_dimension(z),
                traits::vector_storage(work.select(real_type())), info );
    }

    // minimal workspace specialization
    template< typename VectorD, typename VectorE, typename MatrixZ >
    static void compute( char const jobz, integer_t const n, VectorD& d,
            VectorE& e, MatrixZ& z, integer_t& info, minimal_workspace work ) {
        traits::detail::array< real_type > tmp_work( min_size_work( n ) );
        compute( jobz, n, d, e, z, info, workspace( tmp_work ) );
    }

    // optimal workspace specialization
    template< typename VectorD, typename VectorE, typename MatrixZ >
    static void compute( char const jobz, integer_t const n, VectorD& d,
            VectorE& e, MatrixZ& z, integer_t& info, optimal_workspace work ) {
        compute( jobz, n, d, e, z, info, minimal_workspace() );
    }

    static integer_t min_size_work( integer_t const n ) {
        return std::max( 1, 2*n-2 );
    }
};


// template function to call stev
template< typename VectorD, typename VectorE, typename MatrixZ,
        typename Workspace >
inline integer_t stev( char const jobz, integer_t const n, VectorD& d,
        VectorE& e, MatrixZ& z, Workspace work = optimal_workspace() ) {
    typedef typename traits::vector_traits< VectorD >::value_type value_type;
    integer_t info(0);
    stev_impl< value_type >::compute( jobz, n, d, e, z, info, work );
    return info;
}

}}}} // namespace boost::numeric::bindings::lapack

#endif
