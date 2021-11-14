---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/pow_mod.cpp
    title: math/pow_mod.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/normalize_mod.cpp\"\n\n#include <cassert>\n\ntemplate\
    \ <typename T> constexpr T normalize_mod(const T x, const T mod) {\n    assert(mod\
    \ > 0);\n    if (x >= 0)\n        return x % mod;\n    else\n        return x\
    \ % mod + mod;\n}\n"
  code: "#pragma once\n\n#include <cassert>\n\ntemplate <typename T> constexpr T normalize_mod(const\
    \ T x, const T mod) {\n    assert(mod > 0);\n    if (x >= 0)\n        return x\
    \ % mod;\n    else\n        return x % mod + mod;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/normalize_mod.cpp
  requiredBy:
  - math/pow_mod.cpp
  timestamp: '2021-11-14 16:09:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/normalize_mod.cpp
layout: document
redirect_from:
- /library/math/normalize_mod.cpp
- /library/math/normalize_mod.cpp.html
title: math/normalize_mod.cpp
---
