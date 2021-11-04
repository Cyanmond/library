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
  bundledCode: "#line 2 \"utility/rec_lambda.cpp\"\n\n#include <utility>\n\ntemplate\
    \ <class F> class rec_lambda {\n    F f;\n\n  public:\n    explicit constexpr\
    \ rec_lambda(F &&f_) : f(std::forward<F>(f_)) {}\n    template <class... Args>\
    \ constexpr auto operator()(Args &&...args) const { return f(*this, std::forward<Args>(args)...);\
    \ }\n};\n"
  code: "#pragma once\n\n#include <utility>\n\ntemplate <class F> class rec_lambda\
    \ {\n    F f;\n\n  public:\n    explicit constexpr rec_lambda(F &&f_) : f(std::forward<F>(f_))\
    \ {}\n    template <class... Args> constexpr auto operator()(Args &&...args) const\
    \ { return f(*this, std::forward<Args>(args)...); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: utility/rec_lambda.cpp
  requiredBy: []
  timestamp: '2021-11-04 11:05:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/rec_lambda.cpp
layout: document
redirect_from:
- /library/utility/rec_lambda.cpp
- /library/utility/rec_lambda.cpp.html
title: utility/rec_lambda.cpp
---
