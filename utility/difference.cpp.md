---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: utility/int_binary_search.cpp
    title: utility/int_binary_search.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/difference.cpp\"\n\ntemplate <typename T> constexpr\
    \ T difference(const T a,const T b){\n    return (a > b) ? (a - b) : (b - a);\n\
    }\n"
  code: "#pragma once\n\ntemplate <typename T> constexpr T difference(const T a,const\
    \ T b){\n    return (a > b) ? (a - b) : (b - a);\n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/difference.cpp
  requiredBy:
  - utility/int_binary_search.cpp
  timestamp: '2021-11-14 20:45:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/difference.cpp
layout: document
redirect_from:
- /library/utility/difference.cpp
- /library/utility/difference.cpp.html
title: utility/difference.cpp
---
