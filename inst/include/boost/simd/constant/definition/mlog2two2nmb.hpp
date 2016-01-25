//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_MLOG2TWO2NMB_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_MLOG2TWO2NMB_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/dispatch/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct mlog2two2nmb_ : boost::dispatch::constant_value_<mlog2two2nmb_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,mlog2two2nmb_,boost::dispatch::constant_value_<mlog2two2nmb_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0xc1b80000UL, 0xc04a000000000000ULL); //was C04A8 ?
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,mlog2two2nmb_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::mlog2two2nmb_,mlog2two2nmb);
  }

  template<typename T> BOOST_FORCEINLINE auto Mlog2two2nmb() BOOST_NOEXCEPT
  -> decltype(functional::mlog2two2nmb( boost::dispatch::as_<T>{}))
  {
    return functional::mlog2two2nmb( boost::dispatch::as_<T>{} );
  }
} }

#endif