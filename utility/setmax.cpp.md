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
  bundledCode: "#line 2 \"utility/setmax.cpp\"\n\ntemplate <typename T> bool setmax(T\
    \ &lhs, const T &rhs) {\n    if(rhs > lhs) {\n        lhs = rhs;\n        return\
    \ true;\n    }\n    return false;\n}\n"
  code: "#pragma once\n\ntemplate <typename T> bool setmax(T &lhs, const T &rhs) {\n\
    \    if(rhs > lhs) {\n        lhs = rhs;\n        return true;\n    }\n    return\
    \ false;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: utility/setmax.cpp
  requiredBy: []
  timestamp: '2021-12-08 20:23:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/setmax.cpp
layout: document
redirect_from:
- /library/utility/setmax.cpp
- /library/utility/setmax.cpp.html
title: utility/setmax.cpp
---
