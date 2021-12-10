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
  bundledCode: "#line 2 \"bit/is_pow2.cpp\"\n\ntemplate <typename T>\nbool is_pow2(const\
    \ T n) {\n    return (n & (n - 1)) == 0;\n}\n"
  code: "#pragma once\n\ntemplate <typename T>\nbool is_pow2(const T n) {\n    return\
    \ (n & (n - 1)) == 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: bit/is_pow2.cpp
  requiredBy: []
  timestamp: '2021-12-10 15:51:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bit/is_pow2.cpp
layout: document
redirect_from:
- /library/bit/is_pow2.cpp
- /library/bit/is_pow2.cpp.html
title: bit/is_pow2.cpp
---
