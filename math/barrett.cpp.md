---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: utility/int128_alias.cpp
    title: utility/int128_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/pow_mod.cpp
    title: math/pow_mod.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/barrett.cpp\"\n\n#line 2 \"utility/int128_alias.cpp\"\
    \n\nusing i128 = __int128_t;\nusing u128 = __uint128_t;\n#line 2 \"utility/int_alias.cpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nusing i8 = std::int8_t;\nusing u8\
    \ = std::uint8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    #line 5 \"math/barrett.cpp\"\n\nclass Barrett {\n    u32 mod;\n    u64 near_inv;\n\
    \n  public:\n    explicit constexpr Barrett(const u32 mod_) noexcept\n       \
    \ : mod(mod_), near_inv((u64)(-1) / mod_ + 1) {}\n\n    constexpr u32 product(const\
    \ u32 a, const u32 b) const noexcept {\n        const u64 z = static_cast<u64>(a)\
    \ * static_cast<u64>(b);\n        const u64 x = static_cast<u64>((static_cast<u128>(z)\
    \ * static_cast<u128>(near_inv)) >> 64);\n        const u32 v = static_cast<u32>(z\
    \ - x * mod);\n        return v < mod ? v : v + mod;\n    }\n};\n"
  code: "#pragma once\n\n#include \"../utility/int128_alias.cpp\"\n#include \"../utility/int_alias.cpp\"\
    \n\nclass Barrett {\n    u32 mod;\n    u64 near_inv;\n\n  public:\n    explicit\
    \ constexpr Barrett(const u32 mod_) noexcept\n        : mod(mod_), near_inv((u64)(-1)\
    \ / mod_ + 1) {}\n\n    constexpr u32 product(const u32 a, const u32 b) const\
    \ noexcept {\n        const u64 z = static_cast<u64>(a) * static_cast<u64>(b);\n\
    \        const u64 x = static_cast<u64>((static_cast<u128>(z) * static_cast<u128>(near_inv))\
    \ >> 64);\n        const u32 v = static_cast<u32>(z - x * mod);\n        return\
    \ v < mod ? v : v + mod;\n    }\n};"
  dependsOn:
  - utility/int128_alias.cpp
  - utility/int_alias.cpp
  isVerificationFile: false
  path: math/barrett.cpp
  requiredBy:
  - math/pow_mod.cpp
  timestamp: '2021-12-08 20:23:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/barrett.cpp
layout: document
redirect_from:
- /library/math/barrett.cpp
- /library/math/barrett.cpp.html
title: math/barrett.cpp
---