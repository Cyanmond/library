---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/static_modint.cpp\"\n\n#line 2 \"utility/int_alias.cpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nusing i8 = std::int8_t;\nusing u8\
    \ = std::uint8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    #line 6 \"math/static_modint.cpp\"\n#include <type_traits>\n\ntemplate <u32 MOD>\
    \ class StaticModint {\n    using this_type = StaticModint;\n    u32 value;\n\n\
    \  public:\n    static constexpr u32 mod() noexcept {\n        return MOD;\n \
    \   }\n    template <class T> static constexpr T mod() noexcept {\n        return\
    \ static_cast<T>(MOD);\n    }\n\n    template <class T, std::enable_if_t<std::is_unsigned_v<T>>\
    \ * = nullptr>\n    static constexpr u32 normalize(const T v) noexcept {\n   \
    \     return static_cast<u32>(v % mod<T>());\n    }\n    template <class T, std::enable_if_t<std::is_signed_v<T>>\
    \ * = nullptr>\n    static constexpr u32 normalize(const T v) noexcept {\n   \
    \     if (v < 0)\n            return static_cast<u32>(v % mod<T>() + mod<T>());\n\
    \        else\n            return static_cast<u32>(v % mod<T>());\n    }\n\n \
    \   constexpr StaticModint() noexcept : value(0) {}\n    template <class T> constexpr\
    \ StaticModint(const T v) noexcept : value(normalize(v)) {}\n\n    template <class\
    \ T> static constexpr this_type raw(const T v) noexcept {\n        this_type ret;\n\
    \        ret.value = static_cast<u32>(v);\n        return ret;\n    }\n\n    constexpr\
    \ const u32 &val() const noexcept {\n        return value;\n    }\n    constexpr\
    \ this_type operator-() const noexcept {\n        return value == 0 ? 0 : mod()\
    \ - value;\n    }\n\n    constexpr bool operator==(const this_type &rhs) const\
    \ noexcept {\n        return value == rhs.value;\n    }\n    constexpr bool operator!=(const\
    \ this_type &rhs) const noexcept {\n        return value != rhs.value;\n    }\n\
    \    constexpr bool operator<(const this_type &rhs) const noexcept {\n       \
    \ return value < rhs.value;\n    }\n    constexpr bool operator<=(const this_type\
    \ &rhs) const noexcept {\n        return value <= rhs.value;\n    }\n    constexpr\
    \ bool operator>(const this_type &rhs) const noexcept {\n        return value\
    \ > rhs.value;\n    }\n    constexpr bool operator>=(const this_type &rhs) const\
    \ noexcept {\n        return value >= rhs.value;\n    }\n    constexpr this_type\
    \ &operator++() noexcept {\n        ++value;\n        if (value == mod()) value\
    \ = 0;\n        return *this;\n    }\n    constexpr this_type &operator--() noexcept\
    \ {\n        if (value == 0) value = mod();\n        --value;\n        return\
    \ *this;\n    }\n    constexpr this_type operator++(int) noexcept {\n        this_type\
    \ ret(*this);\n        ++*this;\n        return ret;\n    }\n    constexpr this_type\
    \ operator--(int) noexcept {\n        this_type ret(*this);\n        --*this;\n\
    \        return ret;\n    }\n\n    constexpr this_type operator+(const this_type\
    \ &rhs) const noexcept {\n        return this_type(*this) += rhs;\n    }\n   \
    \ constexpr this_type operator-(const this_type &rhs) const noexcept {\n     \
    \   return this_type(*this) -= rhs;\n    }\n    constexpr this_type operator*(const\
    \ this_type &rhs) const noexcept {\n        return this_type(*this) *= rhs;\n\
    \    }\n    constexpr this_type operator/(const this_type &rhs) const noexcept\
    \ {\n        return this_type(*this) /= rhs;\n    }\n\n    constexpr this_type\
    \ &operator+=(const this_type &rhs) noexcept {\n        if ((value += rhs.value)\
    \ >= mod()) value -= mod();\n        return *this;\n    }\n    constexpr this_type\
    \ &operator-=(const this_type &rhs) noexcept {\n        if (value < rhs.value)\
    \ value += mod();\n        value -= rhs.value;\n        return *this;\n    }\n\
    \    constexpr this_type &operator*=(const this_type &rhs) noexcept {\n      \
    \  value =\n            static_cast<u32>(static_cast<u64>(value) * static_cast<u64>(rhs.value)\
    \ % mod<u64>());\n        return *this;\n    }\n    constexpr this_type &operator/=(const\
    \ this_type &rhs) noexcept {\n        return *this *= rhs.inv();\n    }\n\n  \
    \  template <class T> constexpr this_type pow(T n) {\n        this_type ret(1),\
    \ x(*this);\n        while (n != 0) {\n            if (n & 1) ret *= x;\n    \
    \        x *= x;\n            n >>= 1;\n        }\n        return ret;\n    }\n\
    \    constexpr this_type inv() const {\n        i64 s = mod<i64>(), t = static_cast<i64>(value),\
    \ a = 0, b = 1;\n        while (t != 0) {\n            const i64 u = s / t;\n\
    \            s -= t * u;\n            a -= b * u;\n            auto k = s;\n \
    \           s = t;\n            t = k;\n            k = a;\n            a = b;\n\
    \            b = k;\n        }\n        if (a < 0) a += mod<i64>();\n        return\
    \ this_type::raw(a);\n    }\n};\n\nusing Modint1000000007 = StaticModint<1000000007>;\n\
    using Modint998244353 = StaticModint<998244353>;\n"
  code: "#pragma once\n\n#include \"../utility/int_alias.cpp\"\n#include <cstddef>\n\
    #include <cstdint>\n#include <type_traits>\n\ntemplate <u32 MOD> class StaticModint\
    \ {\n    using this_type = StaticModint;\n    u32 value;\n\n  public:\n    static\
    \ constexpr u32 mod() noexcept {\n        return MOD;\n    }\n    template <class\
    \ T> static constexpr T mod() noexcept {\n        return static_cast<T>(MOD);\n\
    \    }\n\n    template <class T, std::enable_if_t<std::is_unsigned_v<T>> * = nullptr>\n\
    \    static constexpr u32 normalize(const T v) noexcept {\n        return static_cast<u32>(v\
    \ % mod<T>());\n    }\n    template <class T, std::enable_if_t<std::is_signed_v<T>>\
    \ * = nullptr>\n    static constexpr u32 normalize(const T v) noexcept {\n   \
    \     if (v < 0)\n            return static_cast<u32>(v % mod<T>() + mod<T>());\n\
    \        else\n            return static_cast<u32>(v % mod<T>());\n    }\n\n \
    \   constexpr StaticModint() noexcept : value(0) {}\n    template <class T> constexpr\
    \ StaticModint(const T v) noexcept : value(normalize(v)) {}\n\n    template <class\
    \ T> static constexpr this_type raw(const T v) noexcept {\n        this_type ret;\n\
    \        ret.value = static_cast<u32>(v);\n        return ret;\n    }\n\n    constexpr\
    \ const u32 &val() const noexcept {\n        return value;\n    }\n    constexpr\
    \ this_type operator-() const noexcept {\n        return value == 0 ? 0 : mod()\
    \ - value;\n    }\n\n    constexpr bool operator==(const this_type &rhs) const\
    \ noexcept {\n        return value == rhs.value;\n    }\n    constexpr bool operator!=(const\
    \ this_type &rhs) const noexcept {\n        return value != rhs.value;\n    }\n\
    \    constexpr bool operator<(const this_type &rhs) const noexcept {\n       \
    \ return value < rhs.value;\n    }\n    constexpr bool operator<=(const this_type\
    \ &rhs) const noexcept {\n        return value <= rhs.value;\n    }\n    constexpr\
    \ bool operator>(const this_type &rhs) const noexcept {\n        return value\
    \ > rhs.value;\n    }\n    constexpr bool operator>=(const this_type &rhs) const\
    \ noexcept {\n        return value >= rhs.value;\n    }\n    constexpr this_type\
    \ &operator++() noexcept {\n        ++value;\n        if (value == mod()) value\
    \ = 0;\n        return *this;\n    }\n    constexpr this_type &operator--() noexcept\
    \ {\n        if (value == 0) value = mod();\n        --value;\n        return\
    \ *this;\n    }\n    constexpr this_type operator++(int) noexcept {\n        this_type\
    \ ret(*this);\n        ++*this;\n        return ret;\n    }\n    constexpr this_type\
    \ operator--(int) noexcept {\n        this_type ret(*this);\n        --*this;\n\
    \        return ret;\n    }\n\n    constexpr this_type operator+(const this_type\
    \ &rhs) const noexcept {\n        return this_type(*this) += rhs;\n    }\n   \
    \ constexpr this_type operator-(const this_type &rhs) const noexcept {\n     \
    \   return this_type(*this) -= rhs;\n    }\n    constexpr this_type operator*(const\
    \ this_type &rhs) const noexcept {\n        return this_type(*this) *= rhs;\n\
    \    }\n    constexpr this_type operator/(const this_type &rhs) const noexcept\
    \ {\n        return this_type(*this) /= rhs;\n    }\n\n    constexpr this_type\
    \ &operator+=(const this_type &rhs) noexcept {\n        if ((value += rhs.value)\
    \ >= mod()) value -= mod();\n        return *this;\n    }\n    constexpr this_type\
    \ &operator-=(const this_type &rhs) noexcept {\n        if (value < rhs.value)\
    \ value += mod();\n        value -= rhs.value;\n        return *this;\n    }\n\
    \    constexpr this_type &operator*=(const this_type &rhs) noexcept {\n      \
    \  value =\n            static_cast<u32>(static_cast<u64>(value) * static_cast<u64>(rhs.value)\
    \ % mod<u64>());\n        return *this;\n    }\n    constexpr this_type &operator/=(const\
    \ this_type &rhs) noexcept {\n        return *this *= rhs.inv();\n    }\n\n  \
    \  template <class T> constexpr this_type pow(T n) {\n        this_type ret(1),\
    \ x(*this);\n        while (n != 0) {\n            if (n & 1) ret *= x;\n    \
    \        x *= x;\n            n >>= 1;\n        }\n        return ret;\n    }\n\
    \    constexpr this_type inv() const {\n        i64 s = mod<i64>(), t = static_cast<i64>(value),\
    \ a = 0, b = 1;\n        while (t != 0) {\n            const i64 u = s / t;\n\
    \            s -= t * u;\n            a -= b * u;\n            auto k = s;\n \
    \           s = t;\n            t = k;\n            k = a;\n            a = b;\n\
    \            b = k;\n        }\n        if (a < 0) a += mod<i64>();\n        return\
    \ this_type::raw(a);\n    }\n};\n\nusing Modint1000000007 = StaticModint<1000000007>;\n\
    using Modint998244353 = StaticModint<998244353>;"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: math/static_modint.cpp
  requiredBy: []
  timestamp: '2021-11-17 22:31:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/static_modint.cpp
layout: document
redirect_from:
- /library/math/static_modint.cpp
- /library/math/static_modint.cpp.html
title: math/static_modint.cpp
---
