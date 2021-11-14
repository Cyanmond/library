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
  bundledCode: "#line 2 \"bit/ceil_log2.cpp\"\n\ntemplate <class T> int ceil_log2(const\
    \ T v) {\n    int res = 0;\n    while ((T(1) << res) < v)\n        ++res;\n  \
    \  return res;\n}\n"
  code: "#pragma once\n\ntemplate <class T> int ceil_log2(const T v) {\n    int res\
    \ = 0;\n    while ((T(1) << res) < v)\n        ++res;\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: bit/ceil_log2.cpp
  requiredBy: []
  timestamp: '2021-11-14 20:48:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bit/ceil_log2.cpp
layout: document
redirect_from:
- /library/bit/ceil_log2.cpp
- /library/bit/ceil_log2.cpp.html
title: bit/ceil_log2.cpp
---
