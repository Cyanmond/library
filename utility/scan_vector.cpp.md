---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/scan_vector.cpp\"\n\n#line 2 \"utility/int_alias.cpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nusing i8 = std::int8_t;\nusing u8\
    \ = std::uint8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    #line 4 \"utility/scan_vector.cpp\"\n#include <iostream>\n#include <vector>\n\n\
    template <typename T> inline std::vector<T> scan_vec(const usize n) {\n    std::vector<T>\
    \ res(n);\n    for (usize i = 0; i < n; ++i) {\n        res[i] = scan<T>();\n\
    \    }\n    return res;\n}\n\ntemplate <typename T, class F> inline std::vector<T>\
    \ scan_vec(const usize n, const F f) {\n    std::vector<T> res(n);\n    for (usize\
    \ i = 0; i < n; ++i) {\n        res[i] = f(scan<T>());\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\n\n#include \"int_alias.cpp\"\n#include <iostream>\n#include\
    \ <vector>\n\ntemplate <typename T> inline std::vector<T> scan_vec(const usize\
    \ n) {\n    std::vector<T> res(n);\n    for (usize i = 0; i < n; ++i) {\n    \
    \    res[i] = scan<T>();\n    }\n    return res;\n}\n\ntemplate <typename T, class\
    \ F> inline std::vector<T> scan_vec(const usize n, const F f) {\n    std::vector<T>\
    \ res(n);\n    for (usize i = 0; i < n; ++i) {\n        res[i] = f(scan<T>());\n\
    \    }\n    return res;\n}"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/scan_vector.cpp
  requiredBy: []
  timestamp: '2021-11-20 02:43:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/scan_vector.cpp
layout: document
redirect_from:
- /library/utility/scan_vector.cpp
- /library/utility/scan_vector.cpp.html
title: utility/scan_vector.cpp
---
