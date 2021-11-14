---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: utility/difference.cpp
    title: utility/difference.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/int_binary_search.cpp\"\n\n#line 2 \"utility/difference.cpp\"\
    \n\ntemplate <typename T> constexpr T difference(const T a,const T b){\n    return\
    \ (a > b) ? (a - b) : (b - a);\n}\n#line 4 \"utility/int_binary_search.cpp\"\n\
    #include <type_traits>\n\ntemplate <typename T, class F> constexpr T intbinarysearch(T\
    \ ok, T ng, const F &f) {\n    static_assert(std::is_integral_v<T>);\n    while\
    \ (difference(ok, ng) != 0) {\n        const auto mid = (ok + ng) >> 1;\n    \
    \    (f(mid) ? ok : ng) = mid;\n    }\n    return ok;\n}\n"
  code: "#pragma once\n\n#include \"difference.cpp\"\n#include <type_traits>\n\ntemplate\
    \ <typename T, class F> constexpr T intbinarysearch(T ok, T ng, const F &f) {\n\
    \    static_assert(std::is_integral_v<T>);\n    while (difference(ok, ng) != 0)\
    \ {\n        const auto mid = (ok + ng) >> 1;\n        (f(mid) ? ok : ng) = mid;\n\
    \    }\n    return ok;\n}"
  dependsOn:
  - utility/difference.cpp
  isVerificationFile: false
  path: utility/int_binary_search.cpp
  requiredBy: []
  timestamp: '2021-11-14 23:32:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/int_binary_search.cpp
layout: document
redirect_from:
- /library/utility/int_binary_search.cpp
- /library/utility/int_binary_search.cpp.html
title: utility/int_binary_search.cpp
---
