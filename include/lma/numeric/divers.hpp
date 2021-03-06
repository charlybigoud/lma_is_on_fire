/**

\file
\author Datta Ramadasan
//==============================================================================
//         Copyright 2015 INSTITUT PASCAL UMR 6602 CNRS/Univ. Clermont II
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================

*/

#ifndef __SRC_DIVERS_DIVERS_HPP__
#define __SRC_DIVERS_DIVERS_HPP__

#include <stdlib.h>

#include <lma/ttt/traits/int.hpp>

namespace lma
{
  template<class T>
  T random()
  {
    return static_cast<T>(rand()) / static_cast<T>(RAND_MAX);
  }

  template<class T>
  T random(const T& max)
  {
    return random<double>() * max;
  }

  inline double randomd(double inf, double sup)
  {
    return random<double>( sup * 2.0 ) - (sup - inf);
  }

  template<class T>
  bool is_borned(const T& val, const T& min, const T& max)
  {
    return val > min && val < max;
  }

  template<class T>
  void borne(T& val, const T& min, const T& max)
  {
    if (val > max) val = max;
    if (val < min) val = min;
  }

  template<class T>
  int signe(const T& val)
  {
    return (val >= 0 ? 1 : -1);
  }

  template<class T>
  bool out_of_bounded(const T& x, const T& y, const T& infx, const T& infy, const T& supx, const T& supy)
  {
    return ( x < infx || y < infy || x >=supx || y >= supy );
  }
  
  
  namespace detail {

    template<int n, class T>
    struct pow
    {
      static T eval(T x)
      {
        return x * pow<n - 1, T>::eval(x);
      }
    };

    template<class T>
    struct pow<0, T>
    {
      static T eval(T)
      {
        return 1;
      }
    };

  }

  template<int n, class T> T pow(T x)
  {
    return detail::pow<n, T>::eval(x);
  }

}



#endif
