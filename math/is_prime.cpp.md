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
  bundledCode: "#line 2 \"math/is_prime.cpp\"\n\ntemplate <typename T> constexpr bool\
    \ is_prime(const T n) {\n    if (n == 1) return false;\n    for (T i = 2; i *\
    \ i <= n; ++i)\n        if (n % i == 0) return false;\n    return true;\n}\n"
  code: "#pragma once\n\ntemplate <typename T> constexpr bool is_prime(const T n)\
    \ {\n    if (n == 1) return false;\n    for (T i = 2; i * i <= n; ++i)\n     \
    \   if (n % i == 0) return false;\n    return true;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/is_prime.cpp
  requiredBy: []
  timestamp: '2021-11-20 02:46:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/is_prime.cpp
layout: document
redirect_from:
- /library/math/is_prime.cpp
- /library/math/is_prime.cpp.html
title: math/is_prime.cpp
---
