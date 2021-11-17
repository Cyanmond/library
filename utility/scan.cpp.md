---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library-checker/many_aplusb.test.cpp
    title: verify/library-checker/many_aplusb.test.cpp
  - icon: ':x:'
    path: verify/library-checker/point_add_range_sum.test.cpp
    title: verify/library-checker/point_add_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/scan.cpp\"\n\n#include <iostream>\n\ntemplate <class\
    \ T> T scan() {\n    T x;\n    std::cin >> x;\n    return x;\n}\n"
  code: "#pragma once\n\n#include <iostream>\n\ntemplate <class T> T scan() {\n  \
    \  T x;\n    std::cin >> x;\n    return x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/scan.cpp
  requiredBy: []
  timestamp: '2021-11-03 23:24:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/library-checker/many_aplusb.test.cpp
  - verify/library-checker/point_add_range_sum.test.cpp
documentation_of: utility/scan.cpp
layout: document
redirect_from:
- /library/utility/scan.cpp
- /library/utility/scan.cpp.html
title: utility/scan.cpp
---
