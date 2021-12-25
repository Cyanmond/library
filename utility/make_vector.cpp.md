---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/make_vector.cpp\"\n\n#line 2 \"utility/int_alias.cpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nusing i8 = std::int8_t;\nusing u8\
    \ = std::uint8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    #line 4 \"utility/make_vector.cpp\"\n#include <vector>\n\ntemplate <typename T>\
    \ std::vector<T> make_vector(const usize n, const T &value) {\n    return std::vector(n,\
    \ value);\n}\n\ntemplate <class... Args> auto make_vector(const usize n, Args...\
    \ args) {\n    return std::vector(n, make_vector(args...));\n}\n"
  code: "#pragma once\n\n#include \"int_alias.cpp\"\n#include <vector>\n\ntemplate\
    \ <typename T> std::vector<T> make_vector(const usize n, const T &value) {\n \
    \   return std::vector(n, value);\n}\n\ntemplate <class... Args> auto make_vector(const\
    \ usize n, Args... args) {\n    return std::vector(n, make_vector(args...));\n\
    }\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/make_vector.cpp
  requiredBy: []
  timestamp: '2021-12-08 20:23:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/make_vector.cpp
layout: document
redirect_from:
- /library/utility/make_vector.cpp
- /library/utility/make_vector.cpp.html
title: utility/make_vector.cpp
---
