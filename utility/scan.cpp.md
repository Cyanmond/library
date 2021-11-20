---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: utility/scan_vector.cpp
    title: utility/scan_vector.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library-checker/many_aplusb.test.cpp
    title: verify/library-checker/many_aplusb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library-checker/point_add_range_sum.test.cpp
    title: verify/library-checker/point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/scan.cpp\"\n\n#include <iostream>\n\ntemplate <typename\
    \ T> inline T scan() {\n    T x;\n    std::cin >> x;\n    return x;\n}\n"
  code: "#pragma once\n\n#include <iostream>\n\ntemplate <typename T> inline T scan()\
    \ {\n    T x;\n    std::cin >> x;\n    return x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: utility/scan.cpp
  requiredBy:
  - utility/scan_vector.cpp
  timestamp: '2021-11-19 22:47:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library-checker/point_add_range_sum.test.cpp
  - verify/library-checker/many_aplusb.test.cpp
documentation_of: utility/scan.cpp
layout: document
redirect_from:
- /library/utility/scan.cpp
- /library/utility/scan.cpp.html
title: utility/scan.cpp
---
