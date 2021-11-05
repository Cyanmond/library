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
  bundledCode: '#line 2 "utility/int_literal.cpp"


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

    #line 6 "utility/int_literal.cpp"


    constexpr std::int8_t operator""_i8(unsigned long long n) noexcept { return static_cast<std::int8_t>(n);
    }

    constexpr std::int16_t operator""_i16(unsigned long long n) noexcept { return
    static_cast<std::int16_t>(n); }

    constexpr std::int32_t operator""_i32(unsigned long long n) noexcept { return
    static_cast<std::int32_t>(n); }

    constexpr std::int64_t operator""_i64(unsigned long long n) noexcept { return
    static_cast<std::int64_t>(n); }


    constexpr std::int8_t operator""_u8(unsigned long long n) noexcept { return static_cast<std::uint8_t>(n);
    }

    constexpr std::uint16_t operator""_u16(unsigned long long n) noexcept { return
    static_cast<std::uint16_t>(n); }

    constexpr std::uint32_t operator""_u32(unsigned long long n) noexcept { return
    static_cast<std::uint32_t>(n); }

    constexpr std::uint64_t operator""_u64(unsigned long long n) noexcept { return
    static_cast<std::uint64_t>(n); }


    constexpr isize operator""_iz(unsigned long long n) noexcept { return static_cast<isize>(n);
    }

    constexpr usize operator""_uz(unsigned long long n) noexcept { return static_cast<usize>(n);
    }

    '
  code: '#pragma once


    #include "../utility/int_alias.cpp"

    #include <cstddef>

    #include <cstdint>


    constexpr std::int8_t operator""_i8(unsigned long long n) noexcept { return static_cast<std::int8_t>(n);
    }

    constexpr std::int16_t operator""_i16(unsigned long long n) noexcept { return
    static_cast<std::int16_t>(n); }

    constexpr std::int32_t operator""_i32(unsigned long long n) noexcept { return
    static_cast<std::int32_t>(n); }

    constexpr std::int64_t operator""_i64(unsigned long long n) noexcept { return
    static_cast<std::int64_t>(n); }


    constexpr std::int8_t operator""_u8(unsigned long long n) noexcept { return static_cast<std::uint8_t>(n);
    }

    constexpr std::uint16_t operator""_u16(unsigned long long n) noexcept { return
    static_cast<std::uint16_t>(n); }

    constexpr std::uint32_t operator""_u32(unsigned long long n) noexcept { return
    static_cast<std::uint32_t>(n); }

    constexpr std::uint64_t operator""_u64(unsigned long long n) noexcept { return
    static_cast<std::uint64_t>(n); }


    constexpr isize operator""_iz(unsigned long long n) noexcept { return static_cast<isize>(n);
    }

    constexpr usize operator""_uz(unsigned long long n) noexcept { return static_cast<usize>(n);
    }'
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/int_literal.cpp
  requiredBy: []
  timestamp: '2021-11-04 01:00:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/int_literal.cpp
layout: document
redirect_from:
- /library/utility/int_literal.cpp
- /library/utility/int_literal.cpp.html
title: utility/int_literal.cpp
---
