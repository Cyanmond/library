---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 2 "utility/int_infinity.cpp"


    #include <limits>


    template <class T, T Div = 2>

    constexpr T infty = std::numeric_limits<T>::max() / Div;

    '
  code: '#pragma once


    #include <limits>


    template <class T, T Div = 2>

    constexpr T infty = std::numeric_limits<T>::max() / Div;'
  dependsOn: []
  isVerificationFile: false
  path: utility/int_infinity.cpp
  requiredBy: []
  timestamp: '2021-11-03 23:24:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/int_infinity.cpp
layout: document
redirect_from:
- /library/utility/int_infinity.cpp
- /library/utility/int_infinity.cpp.html
title: utility/int_infinity.cpp
---
