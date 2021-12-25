---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/lazysegmenttree_utility.cpp
    title: data-structure/lazysegmenttree_utility.cpp
  - icon: ':warning:'
    path: debug/debug_impl.cpp
    title: debug/debug_impl.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 2 "utility/int_infinity.cpp"


    #line 2 "utility/int_alias.cpp"


    #include <cstddef>

    #include <cstdint>


    using i8 = std::int8_t;

    using u8 = std::uint8_t;

    using i16 = std::int16_t;

    using i32 = std::int32_t;

    using i64 = std::int64_t;

    using u16 = std::uint16_t;

    using u32 = std::uint32_t;

    using u64 = std::uint64_t;


    using usize = std::size_t;

    using isize = std::ptrdiff_t;

    #line 4 "utility/int_infinity.cpp"

    #include <limits>


    template <class T, T Div = 2> constexpr T infty = std::numeric_limits<T>::max()
    / Div;


    constexpr i32 infi32 = infty<i32, 2>;

    constexpr i64 infi64 = infty<i64, 4>;


    constexpr u32 infu32 = infty<u32, 4>;

    constexpr u64 infu64 = infty<u32, 4>;


    constexpr isize infisz = infty<isize, 2>;

    constexpr usize infusz = infty<usize, 4>;

    '
  code: '#pragma once


    #include "../utility/int_alias.cpp"

    #include <limits>


    template <class T, T Div = 2> constexpr T infty = std::numeric_limits<T>::max()
    / Div;


    constexpr i32 infi32 = infty<i32, 2>;

    constexpr i64 infi64 = infty<i64, 4>;


    constexpr u32 infu32 = infty<u32, 4>;

    constexpr u64 infu64 = infty<u32, 4>;


    constexpr isize infisz = infty<isize, 2>;

    constexpr usize infusz = infty<usize, 4>;

    '
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/int_infinity.cpp
  requiredBy:
  - debug/debug_impl.cpp
  - data-structure/lazysegmenttree_utility.cpp
  timestamp: '2021-12-08 20:23:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/int_infinity.cpp
layout: document
redirect_from:
- /library/utility/int_infinity.cpp
- /library/utility/int_infinity.cpp.html
title: utility/int_infinity.cpp
---
