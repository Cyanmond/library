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
  bundledCode: "#line 2 \"math/pow_int.cpp\"\n\ntemplate <typename T>\nconstexpr T\
    \ pow_int(T n,T k) {\n    auto m = n;\n    while (k != 0) {\n        if (k & 1)\
    \ m *= n;\n        n *= n;\n        k >>= 1;\n    }\n    return m;\n}\n"
  code: "#pragma once\n\ntemplate <typename T>\nconstexpr T pow_int(T n,T k) {\n \
    \   auto m = n;\n    while (k != 0) {\n        if (k & 1) m *= n;\n        n *=\
    \ n;\n        k >>= 1;\n    }\n    return m;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/pow_int.cpp
  requiredBy: []
  timestamp: '2021-11-21 02:55:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/pow_int.cpp
layout: document
redirect_from:
- /library/math/pow_int.cpp
- /library/math/pow_int.cpp.html
title: math/pow_int.cpp
---
