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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_PPTRS_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_COMPUTATIONAL_PPTRS_HPP

#include <boost/assert.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/numeric/bindings/lapack/detail/lapack.h>
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

inline void pptrs( const char uplo, const integer_t n, const integer_t nrhs,
        const float* ap, float* b, const integer_t ldb, integer_t& info ) {
    LAPACK_SPPTRS( &uplo, &n, &nrhs, ap, b, &ldb, &info );
}
inline void pptrs( const char uplo, const integer_t n, const integer_t nrhs,
        const double* ap, double* b, const integer_t ldb, integer_t& info ) {
    LAPACK_DPPTRS( &uplo, &n, &nrhs, ap, b, &ldb, &info );
}
inline void pptrs( const char uplo, const integer_t n, const integer_t nrhs,
        const traits::complex_f* ap, traits::complex_f* b,
        const integer_t ldb, integer_t& info ) {
    LAPACK_CPPTRS( &uplo, &n, &nrhs, traits::complex_ptr(ap),
            traits::complex_ptr(b), &ldb, &info );
}
inline void pptrs( const char uplo, const integer_t n, const integer_t nrhs,
        const traits::complex_d* ap, traits::complex_d* b,
        const integer_t ldb, integer_t& info ) {
    LAPACK_ZPPTRS( &uplo, &n, &nrhs, traits::complex_ptr(ap),
            traits::complex_ptr(b), &ldb, &info );
}
} // namespace detail

// value-type based template
template< typename ValueType >
struct pptrs_impl {

    typedef ValueType value_type;
    typedef typename traits::type_traits<ValueType>::real_type real_type;

    // templated specialization
    template< typename VectorAP, typename MatrixB >
    static void invoke( const integer_t n, const VectorAP& ap, MatrixB& b,
            integer_t& info ) {
        BOOST_STATIC_ASSERT( (boost::is_same< typename traits::vector_traits<
                VectorAP >::value_type, typename traits::matrix_traits<
                MatrixB >::value_type >::value) );
        BOOST_ASSERT( traits::matrix_uplo_tag(a) == 'U' ||
                traits::matrix_uplo_tag(a) == 'L' );
        BOOST_ASSERT( n >= 0 );
        BOOST_ASSERT( traits::matrix_num_columns(b) >= 0 );
        BOOST_ASSERT( traits::leading_dimension(b) >= std::max<
                std::ptrdiff_t >(1,n) );
        detail::pptrs( traits::matrix_uplo_tag(a), n,
                traits::matrix_num_columns(b), traits::vector_storage(ap),
                traits::matrix_storage(b), traits::leading_dimension(b),
                info );
    }
};


// template function to call pptrs
template< typename VectorAP, typename MatrixB >
inline integer_t pptrs( const integer_t n, const VectorAP& ap,
        MatrixB& b ) {
    typedef typename traits::vector_traits< VectorAP >::value_type value_type;
    integer_t info(0);
    pptrs_impl< value_type >::invoke( n, ap, b, info );
    return info;
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
