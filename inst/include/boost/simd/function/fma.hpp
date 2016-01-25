//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_FMA_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FMA_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the (fused) multiply add of the three parameters.

    @par semantic:
    For any given value @c x,  @c y,  @c z of type @c T:

    @code
    T r = fma(x, y, z);
    @endcode

    The code is similar to:

    @code
    T r = x*y+z;
    @endcode

    @par Note
    Correct fused multiply/add implies

    - only one rounding

    - no "intermediate" overflow

    fma provides this each time it is reasonable
    in terms of performance (mainly if the system has the hard
    wired capability).

    If you need "real" fma capabilities in all circumstances in your own
    code you can use correct_fma (although it can be expansive).

    Also :

    - fma(x, y, z, accurate_) always gives a result in accordance to the full definition of fma

    - fma(x, y, z, nooverflow_) provides a "only one rounding" mode but does not care for possible
    intermediate overflow.

    - fma((x, y, z, std_) calls the stdlibc++ function std::fma

    @par Alias

    @c madd

    @see  correct_fma, fms, fnma, fnms

    @return  a value of the same type as the input.


**/
  template<typename T> auto fma(T const& x, T const& y, T const& z) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the (fused) multiply add of the three parameters.


      Function object tied to simd::fma

      @see simd::fma
    **/
    const boost::dispatch::functor<tag::fma_> fma = {};
  }
} }
#endif

#include <boost/simd/function/definition/fma.hpp>
#include <boost/simd/arch/common/generic/function/fma.hpp>
#include <boost/simd/function/simd/fma.hpp>

#endif