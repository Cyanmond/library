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
  bundledCode: "#line 2 \"bit/popcount.cpp\"\n\n#line 2 \"utility/int_alias.cpp\"\n\
    \n#include <cstddef>\n#include <cstdint>\n\nusing i8 = std::int8_t;\nusing u8\
    \ = std::uint8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    #line 4 \"bit/popcount.cpp\"\n\nusize popcount(u64 n) {\n#ifdef __GNUC__\n   \
    \ return __builtin_popcountll(n);\n#else\n    n -= n >> 1 & 0x5555555555555555;\n\
    \    n = (n & 0x3333333333333333) + (n >> 2 & 0x3333333333333333);\n    n = n\
    \ + (n >> 4) & 0x0F0F0F0F0F0F0F0F;\n    return n * 0x0101010101010101 >> 56 &\
    \ 0x7f;\n#endif\n}\n"
  code: "#pragma once\n\n#include \"../utility/int_alias.cpp\"\n\nusize popcount(u64\
    \ n) {\n#ifdef __GNUC__\n    return __builtin_popcountll(n);\n#else\n    n -=\
    \ n >> 1 & 0x5555555555555555;\n    n = (n & 0x3333333333333333) + (n >> 2 & 0x3333333333333333);\n\
    \    n = n + (n >> 4) & 0x0F0F0F0F0F0F0F0F;\n    return n * 0x0101010101010101\
    \ >> 56 & 0x7f;\n#endif\n}"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: bit/popcount.cpp
  requiredBy: []
  timestamp: '2021-12-10 15:51:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: bit/popcount.cpp
layout: document
redirect_from:
- /library/bit/popcount.cpp
- /library/bit/popcount.cpp.html
title: bit/popcount.cpp
---
