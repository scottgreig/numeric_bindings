//
// Copyright (c) 2002--2010
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

#ifndef BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_SPEVX_HPP
#define BOOST_NUMERIC_BINDINGS_LAPACK_DRIVER_SPEVX_HPP

#include <boost/assert.hpp>
#include <boost/numeric/bindings/begin.hpp>
#include <boost/numeric/bindings/data_side.hpp>
#include <boost/numeric/bindings/detail/array.hpp>
#include <boost/numeric/bindings/is_mutable.hpp>
#include <boost/numeric/bindings/lapack/workspace.hpp>
#include <boost/numeric/bindings/remove_imaginary.hpp>
#include <boost/numeric/bindings/size.hpp>
#include <boost/numeric/bindings/stride.hpp>
#include <boost/numeric/bindings/value.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>

//
// The LAPACK-backend for spevx is the netlib-compatible backend.
//
#include <boost/numeric/bindings/lapack/detail/lapack.h>
#include <boost/numeric/bindings/lapack/detail/lapack_option.hpp>

namespace boost {
namespace numeric {
namespace bindings {
namespace lapack {

//
// The detail namespace contains value-type-overloaded functions that
// dispatch to the appropriate back-end LAPACK-routine.
//
namespace detail {

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * float value-type.
//
template< typename UpLo >
inline std::ptrdiff_t spevx( const char jobz, const char range, UpLo,
        const fortran_int_t n, float* ap, const float vl, const float vu,
        const fortran_int_t il, const fortran_int_t iu, const float abstol,
        fortran_int_t& m, float* w, float* z, const fortran_int_t ldz,
        float* work, fortran_int_t* iwork, fortran_int_t* ifail ) {
    fortran_int_t info(0);
    LAPACK_SSPEVX( &jobz, &range, &lapack_option< UpLo >::value, &n, ap, &vl,
            &vu, &il, &iu, &abstol, &m, w, z, &ldz, work, iwork, ifail,
            &info );
    return info;
}

//
// Overloaded function for dispatching to
// * netlib-compatible LAPACK backend (the default), and
// * double value-type.
//
template< typename UpLo >
inline std::ptrdiff_t spevx( const char jobz, const char range, UpLo,
        const fortran_int_t n, double* ap, const double vl, const double vu,
        const fortran_int_t il, const fortran_int_t iu, const double abstol,
        fortran_int_t& m, double* w, double* z, const fortran_int_t ldz,
        double* work, fortran_int_t* iwork, fortran_int_t* ifail ) {
    fortran_int_t info(0);
    LAPACK_DSPEVX( &jobz, &range, &lapack_option< UpLo >::value, &n, ap, &vl,
            &vu, &il, &iu, &abstol, &m, w, z, &ldz, work, iwork, ifail,
            &info );
    return info;
}

} // namespace detail

//
// Value-type based template class. Use this class if you need a type
// for dispatching to spevx.
//
template< typename Value >
struct spevx_impl {

    typedef Value value_type;
    typedef typename remove_imaginary< Value >::type real_type;
    typedef tag::column_major order;

    //
    // Static member function for user-defined workspaces, that
    // * Deduces the required arguments for dispatching to LAPACK, and
    // * Asserts that most arguments make sense.
    //
    template< typename MatrixAP, typename VectorW, typename MatrixZ,
            typename VectorIFAIL, typename WORK, typename IWORK >
    static std::ptrdiff_t invoke( const char jobz, const char range,
            MatrixAP& ap, const real_type vl, const real_type vu,
            const fortran_int_t il, const fortran_int_t iu,
            const real_type abstol, fortran_int_t& m, VectorW& w,
            MatrixZ& z, VectorIFAIL& ifail, detail::workspace2< WORK,
            IWORK > work ) {
        typedef typename result_of::data_side< MatrixAP >::type uplo;
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename value< MatrixAP >::type >::type,
                typename remove_const< typename value<
                VectorW >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (boost::is_same< typename remove_const<
                typename value< MatrixAP >::type >::type,
                typename remove_const< typename value<
                MatrixZ >::type >::type >::value) );
        BOOST_STATIC_ASSERT( (is_mutable< MatrixAP >::value) );
        BOOST_STATIC_ASSERT( (is_mutable< VectorW >::value) );
        BOOST_STATIC_ASSERT( (is_mutable< MatrixZ >::value) );
        BOOST_STATIC_ASSERT( (is_mutable< VectorIFAIL >::value) );
        BOOST_ASSERT( jobz == 'N' || jobz == 'V' );
        BOOST_ASSERT( range == 'A' || range == 'V' || range == 'I' );
        BOOST_ASSERT( size(work.select(fortran_int_t())) >=
                min_size_iwork( size_column(ap) ));
        BOOST_ASSERT( size(work.select(real_type())) >= min_size_work(
                size_column(ap) ));
        BOOST_ASSERT( size_column(ap) >= 0 );
        BOOST_ASSERT( size_minor(z) == 1 || stride_minor(z) == 1 );
        return detail::spevx( jobz, range, uplo(), size_column(ap),
                begin_value(ap), vl, vu, il, iu, abstol, m, begin_value(w),
                begin_value(z), stride_major(z),
                begin_value(work.select(real_type())),
                begin_value(work.select(fortran_int_t())),
                begin_value(ifail) );
    }

    //
    // Static member function that
    // * Figures out the minimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member function
    // * Enables the unblocked algorithm (BLAS level 2)
    //
    template< typename MatrixAP, typename VectorW, typename MatrixZ,
            typename VectorIFAIL >
    static std::ptrdiff_t invoke( const char jobz, const char range,
            MatrixAP& ap, const real_type vl, const real_type vu,
            const fortran_int_t il, const fortran_int_t iu,
            const real_type abstol, fortran_int_t& m, VectorW& w,
            MatrixZ& z, VectorIFAIL& ifail, minimal_workspace work ) {
        typedef typename result_of::data_side< MatrixAP >::type uplo;
        bindings::detail::array< real_type > tmp_work( min_size_work(
                size_column(ap) ) );
        bindings::detail::array< fortran_int_t > tmp_iwork(
                min_size_iwork( size_column(ap) ) );
        return invoke( jobz, range, ap, vl, vu, il, iu, abstol, m, w, z,
                ifail, workspace( tmp_work, tmp_iwork ) );
    }

    //
    // Static member function that
    // * Figures out the optimal workspace requirements, and passes
    //   the results to the user-defined workspace overload of the 
    //   invoke static member
    // * Enables the blocked algorithm (BLAS level 3)
    //
    template< typename MatrixAP, typename VectorW, typename MatrixZ,
            typename VectorIFAIL >
    static std::ptrdiff_t invoke( const char jobz, const char range,
            MatrixAP& ap, const real_type vl, const real_type vu,
            const fortran_int_t il, const fortran_int_t iu,
            const real_type abstol, fortran_int_t& m, VectorW& w,
            MatrixZ& z, VectorIFAIL& ifail, optimal_workspace work ) {
        typedef typename result_of::data_side< MatrixAP >::type uplo;
        return invoke( jobz, range, ap, vl, vu, il, iu, abstol, m, w, z,
                ifail, minimal_workspace() );
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array work.
    //
    static std::ptrdiff_t min_size_work( const std::ptrdiff_t n ) {
        return 8*n;
    }

    //
    // Static member function that returns the minimum size of
    // workspace-array iwork.
    //
    static std::ptrdiff_t min_size_iwork( const std::ptrdiff_t n ) {
        return 5*n;
    }
};


//
// Functions for direct use. These functions are overloaded for temporaries,
// so that wrapped types can still be passed and used for write-access. In
// addition, if applicable, they are overloaded for user-defined workspaces.
// Calls to these functions are passed to the spevx_impl classes. In the 
// documentation, most overloads are collapsed to avoid a large number of
// prototypes which are very similar.
//

//
// Overloaded function for spevx. Its overload differs for
// * MatrixAP&
// * VectorW&
// * MatrixZ&
// * VectorIFAIL&
// * User-defined workspace
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL, typename Workspace >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m, VectorW& w,
        MatrixZ& z, VectorIFAIL& ifail, Workspace work ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail, work );
}

//
// Overloaded function for spevx. Its overload differs for
// * MatrixAP&
// * VectorW&
// * MatrixZ&
// * VectorIFAIL&
// * Default workspace-type (optimal)
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m, VectorW& w,
        MatrixZ& z, VectorIFAIL& ifail ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
            optimal_workspace() );
}

//
// Overloaded function for spevx. Its overload differs for
// * const MatrixAP&
// * VectorW&
// * MatrixZ&
// * VectorIFAIL&
// * User-defined workspace
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL, typename Workspace >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        const MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m, VectorW& w,
        MatrixZ& z, VectorIFAIL& ifail, Workspace work ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail, work );
}

//
// Overloaded function for spevx. Its overload differs for
// * const MatrixAP&
// * VectorW&
// * MatrixZ&
// * VectorIFAIL&
// * Default workspace-type (optimal)
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        const MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m, VectorW& w,
        MatrixZ& z, VectorIFAIL& ifail ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
            optimal_workspace() );
}

//
// Overloaded function for spevx. Its overload differs for
// * MatrixAP&
// * const VectorW&
// * MatrixZ&
// * VectorIFAIL&
// * User-defined workspace
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL, typename Workspace >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m,
        const VectorW& w, MatrixZ& z, VectorIFAIL& ifail, Workspace work ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail, work );
}

//
// Overloaded function for spevx. Its overload differs for
// * MatrixAP&
// * const VectorW&
// * MatrixZ&
// * VectorIFAIL&
// * Default workspace-type (optimal)
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m,
        const VectorW& w, MatrixZ& z, VectorIFAIL& ifail ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
            optimal_workspace() );
}

//
// Overloaded function for spevx. Its overload differs for
// * const MatrixAP&
// * const VectorW&
// * MatrixZ&
// * VectorIFAIL&
// * User-defined workspace
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL, typename Workspace >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        const MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m,
        const VectorW& w, MatrixZ& z, VectorIFAIL& ifail, Workspace work ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail, work );
}

//
// Overloaded function for spevx. Its overload differs for
// * const MatrixAP&
// * const VectorW&
// * MatrixZ&
// * VectorIFAIL&
// * Default workspace-type (optimal)
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        const MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m,
        const VectorW& w, MatrixZ& z, VectorIFAIL& ifail ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
            optimal_workspace() );
}

//
// Overloaded function for spevx. Its overload differs for
// * MatrixAP&
// * VectorW&
// * const MatrixZ&
// * VectorIFAIL&
// * User-defined workspace
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL, typename Workspace >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m, VectorW& w,
        const MatrixZ& z, VectorIFAIL& ifail, Workspace work ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail, work );
}

//
// Overloaded function for spevx. Its overload differs for
// * MatrixAP&
// * VectorW&
// * const MatrixZ&
// * VectorIFAIL&
// * Default workspace-type (optimal)
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m, VectorW& w,
        const MatrixZ& z, VectorIFAIL& ifail ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
            optimal_workspace() );
}

//
// Overloaded function for spevx. Its overload differs for
// * const MatrixAP&
// * VectorW&
// * const MatrixZ&
// * VectorIFAIL&
// * User-defined workspace
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL, typename Workspace >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        const MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m, VectorW& w,
        const MatrixZ& z, VectorIFAIL& ifail, Workspace work ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail, work );
}

//
// Overloaded function for spevx. Its overload differs for
// * const MatrixAP&
// * VectorW&
// * const MatrixZ&
// * VectorIFAIL&
// * Default workspace-type (optimal)
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        const MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m, VectorW& w,
        const MatrixZ& z, VectorIFAIL& ifail ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
            optimal_workspace() );
}

//
// Overloaded function for spevx. Its overload differs for
// * MatrixAP&
// * const VectorW&
// * const MatrixZ&
// * VectorIFAIL&
// * User-defined workspace
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL, typename Workspace >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m,
        const VectorW& w, const MatrixZ& z, VectorIFAIL& ifail,
        Workspace work ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail, work );
}

//
// Overloaded function for spevx. Its overload differs for
// * MatrixAP&
// * const VectorW&
// * const MatrixZ&
// * VectorIFAIL&
// * Default workspace-type (optimal)
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m,
        const VectorW& w, const MatrixZ& z, VectorIFAIL& ifail ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
            optimal_workspace() );
}

//
// Overloaded function for spevx. Its overload differs for
// * const MatrixAP&
// * const VectorW&
// * const MatrixZ&
// * VectorIFAIL&
// * User-defined workspace
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL, typename Workspace >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        const MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m,
        const VectorW& w, const MatrixZ& z, VectorIFAIL& ifail,
        Workspace work ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail, work );
}

//
// Overloaded function for spevx. Its overload differs for
// * const MatrixAP&
// * const VectorW&
// * const MatrixZ&
// * VectorIFAIL&
// * Default workspace-type (optimal)
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        const MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m,
        const VectorW& w, const MatrixZ& z, VectorIFAIL& ifail ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
            optimal_workspace() );
}

//
// Overloaded function for spevx. Its overload differs for
// * MatrixAP&
// * VectorW&
// * MatrixZ&
// * const VectorIFAIL&
// * User-defined workspace
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL, typename Workspace >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m, VectorW& w,
        MatrixZ& z, const VectorIFAIL& ifail, Workspace work ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail, work );
}

//
// Overloaded function for spevx. Its overload differs for
// * MatrixAP&
// * VectorW&
// * MatrixZ&
// * const VectorIFAIL&
// * Default workspace-type (optimal)
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m, VectorW& w,
        MatrixZ& z, const VectorIFAIL& ifail ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
            optimal_workspace() );
}

//
// Overloaded function for spevx. Its overload differs for
// * const MatrixAP&
// * VectorW&
// * MatrixZ&
// * const VectorIFAIL&
// * User-defined workspace
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL, typename Workspace >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        const MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m, VectorW& w,
        MatrixZ& z, const VectorIFAIL& ifail, Workspace work ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail, work );
}

//
// Overloaded function for spevx. Its overload differs for
// * const MatrixAP&
// * VectorW&
// * MatrixZ&
// * const VectorIFAIL&
// * Default workspace-type (optimal)
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        const MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m, VectorW& w,
        MatrixZ& z, const VectorIFAIL& ifail ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
            optimal_workspace() );
}

//
// Overloaded function for spevx. Its overload differs for
// * MatrixAP&
// * const VectorW&
// * MatrixZ&
// * const VectorIFAIL&
// * User-defined workspace
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL, typename Workspace >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m,
        const VectorW& w, MatrixZ& z, const VectorIFAIL& ifail,
        Workspace work ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail, work );
}

//
// Overloaded function for spevx. Its overload differs for
// * MatrixAP&
// * const VectorW&
// * MatrixZ&
// * const VectorIFAIL&
// * Default workspace-type (optimal)
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m,
        const VectorW& w, MatrixZ& z, const VectorIFAIL& ifail ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
            optimal_workspace() );
}

//
// Overloaded function for spevx. Its overload differs for
// * const MatrixAP&
// * const VectorW&
// * MatrixZ&
// * const VectorIFAIL&
// * User-defined workspace
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL, typename Workspace >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        const MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m,
        const VectorW& w, MatrixZ& z, const VectorIFAIL& ifail,
        Workspace work ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail, work );
}

//
// Overloaded function for spevx. Its overload differs for
// * const MatrixAP&
// * const VectorW&
// * MatrixZ&
// * const VectorIFAIL&
// * Default workspace-type (optimal)
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        const MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m,
        const VectorW& w, MatrixZ& z, const VectorIFAIL& ifail ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
            optimal_workspace() );
}

//
// Overloaded function for spevx. Its overload differs for
// * MatrixAP&
// * VectorW&
// * const MatrixZ&
// * const VectorIFAIL&
// * User-defined workspace
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL, typename Workspace >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m, VectorW& w,
        const MatrixZ& z, const VectorIFAIL& ifail, Workspace work ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail, work );
}

//
// Overloaded function for spevx. Its overload differs for
// * MatrixAP&
// * VectorW&
// * const MatrixZ&
// * const VectorIFAIL&
// * Default workspace-type (optimal)
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m, VectorW& w,
        const MatrixZ& z, const VectorIFAIL& ifail ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
            optimal_workspace() );
}

//
// Overloaded function for spevx. Its overload differs for
// * const MatrixAP&
// * VectorW&
// * const MatrixZ&
// * const VectorIFAIL&
// * User-defined workspace
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL, typename Workspace >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        const MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m, VectorW& w,
        const MatrixZ& z, const VectorIFAIL& ifail, Workspace work ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail, work );
}

//
// Overloaded function for spevx. Its overload differs for
// * const MatrixAP&
// * VectorW&
// * const MatrixZ&
// * const VectorIFAIL&
// * Default workspace-type (optimal)
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        const MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m, VectorW& w,
        const MatrixZ& z, const VectorIFAIL& ifail ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
            optimal_workspace() );
}

//
// Overloaded function for spevx. Its overload differs for
// * MatrixAP&
// * const VectorW&
// * const MatrixZ&
// * const VectorIFAIL&
// * User-defined workspace
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL, typename Workspace >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m,
        const VectorW& w, const MatrixZ& z, const VectorIFAIL& ifail,
        Workspace work ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail, work );
}

//
// Overloaded function for spevx. Its overload differs for
// * MatrixAP&
// * const VectorW&
// * const MatrixZ&
// * const VectorIFAIL&
// * Default workspace-type (optimal)
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m,
        const VectorW& w, const MatrixZ& z, const VectorIFAIL& ifail ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
            optimal_workspace() );
}

//
// Overloaded function for spevx. Its overload differs for
// * const MatrixAP&
// * const VectorW&
// * const MatrixZ&
// * const VectorIFAIL&
// * User-defined workspace
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL, typename Workspace >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        const MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m,
        const VectorW& w, const MatrixZ& z, const VectorIFAIL& ifail,
        Workspace work ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail, work );
}

//
// Overloaded function for spevx. Its overload differs for
// * const MatrixAP&
// * const VectorW&
// * const MatrixZ&
// * const VectorIFAIL&
// * Default workspace-type (optimal)
//
template< typename MatrixAP, typename VectorW, typename MatrixZ,
        typename VectorIFAIL >
inline std::ptrdiff_t spevx( const char jobz, const char range,
        const MatrixAP& ap, const typename remove_imaginary< typename value<
        MatrixAP >::type >::type vl, const typename remove_imaginary<
        typename value< MatrixAP >::type >::type vu,
        const fortran_int_t il, const fortran_int_t iu,
        const typename remove_imaginary< typename value<
        MatrixAP >::type >::type abstol, fortran_int_t& m,
        const VectorW& w, const MatrixZ& z, const VectorIFAIL& ifail ) {
    return spevx_impl< typename value< MatrixAP >::type >::invoke( jobz,
            range, ap, vl, vu, il, iu, abstol, m, w, z, ifail,
            optimal_workspace() );
}

} // namespace lapack
} // namespace bindings
} // namespace numeric
} // namespace boost

#endif
