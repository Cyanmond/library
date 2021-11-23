---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
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
  bundledCode: "#line 2 \"utility/scan.cpp\"\n\n#line 2 \"utility/int_alias.cpp\"\n\
    \n#include <cstddef>\n#include <cstdint>\n\nusing i8 = std::int8_t;\nusing u8\
    \ = std::uint8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    #line 4 \"utility/scan.cpp\"\n#include <iostream>\n#include <vector>\n\ntemplate\
    \ <typename T> inline T scan() {\n    T x;\n    std::cin >> x;\n    return x;\n\
    }\n\ntemplate <typename T> std::vector<T> scan_vec(const usize n) {\n    std::vector<T>\
    \ res(n);\n    for (auto &e : res)\n        e = scan<T>();\n    return res;\n\
    }\n\ntemplate <typename T, class... Args> auto scan_vec(const usize n, Args...\
    \ args) {\n    std::vector<decltype(scan_vec(args...))> res(n);\n    for (auto\
    \ &vec : res)\n        vec = scan_vec(args...);\n    return res;\n}\n\ntemplate\
    \ <typename T, class F> std::vector<T> scan_vec_f(const usize n, const F &f) {\n\
    \    std::vector<T> res;\n    for (auto &e : res)\n        e = f(scan<T>());\n\
    \    return res;\n}\n\ntemplate <typename T, class... Args> auto scan_vec_f(const\
    \ usize n, Args... args) {\n    std::vector<decltype(scan_vec_f(args...))> res(n);\n\
    \    for (auto &vec : res)\n        vec = scan_vec_f(args...);\n    return res;\n\
    }\n"
  code: "#pragma once\n\n#include \"int_alias.cpp\"\n#include <iostream>\n#include\
    \ <vector>\n\ntemplate <typename T> inline T scan() {\n    T x;\n    std::cin\
    \ >> x;\n    return x;\n}\n\ntemplate <typename T> std::vector<T> scan_vec(const\
    \ usize n) {\n    std::vector<T> res(n);\n    for (auto &e : res)\n        e =\
    \ scan<T>();\n    return res;\n}\n\ntemplate <typename T, class... Args> auto\
    \ scan_vec(const usize n, Args... args) {\n    std::vector<decltype(scan_vec(args...))>\
    \ res(n);\n    for (auto &vec : res)\n        vec = scan_vec(args...);\n    return\
    \ res;\n}\n\ntemplate <typename T, class F> std::vector<T> scan_vec_f(const usize\
    \ n, const F &f) {\n    std::vector<T> res;\n    for (auto &e : res)\n       \
    \ e = f(scan<T>());\n    return res;\n}\n\ntemplate <typename T, class... Args>\
    \ auto scan_vec_f(const usize n, Args... args) {\n    std::vector<decltype(scan_vec_f(args...))>\
    \ res(n);\n    for (auto &vec : res)\n        vec = scan_vec_f(args...);\n   \
    \ return res;\n}"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/scan.cpp
  requiredBy: []
  timestamp: '2021-11-23 18:07:55+09:00'
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
