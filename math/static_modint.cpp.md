---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/static_modint.cpp\"\n\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <type_traits>\n\ntemplate <std::uint32_t MOD> class StaticModint\
    \ {\n    using this_type = StaticModint;\n    std::uint32_t value;\n\n  public:\n\
    \    static constexpr std::uint32_t mod() noexcept { return MOD; }\n    template\
    \ <class T> static constexpr T mod() noexcept { return static_cast<T>(MOD); }\n\
    \n    template <class T, std::enable_if_t<std::is_unsigned_v<T>> * = nullptr>\
    \ static constexpr std::uint32_t normalize(const T v) noexcept {\n        return\
    \ static_cast<std::uint32_t>(v % mod<T>());\n    }\n    template <class T, std::enable_if_t<std::is_signed_v<T>>\
    \ * = nullptr> static constexpr std::uint32_t normalize(const T v) noexcept {\n\
    \        if(v < 0)\n            return static_cast<std::uint32_t>(v % mod<T>()\
    \ + mod<T>());\n        else\n            return static_cast<std::uint32_t>(v\
    \ % mod<T>());\n    }\n\n    constexpr StaticModint() noexcept : value(0) {}\n\
    \    template <class T> constexpr StaticModint(const T v) noexcept : value(normalize(v))\
    \ {}\n\n    template <class T> static constexpr this_type raw(const T v) noexcept\
    \ {\n        this_type ret;\n        ret.value = static_cast<std::uint32_t>(v);\n\
    \        return ret;\n    }\n\n    constexpr const std::uint32_t &val() const\
    \ noexcept { return value; }\n    constexpr this_type operator-() const noexcept\
    \ { return value == 0 ? 0 : mod() - value; }\n\n    constexpr bool operator==(const\
    \ this_type &rhs) const noexcept { return value == rhs.value; }\n    constexpr\
    \ bool operator!=(const this_type &rhs) const noexcept { return value != rhs.value;\
    \ }\n    constexpr bool operator<(const this_type &rhs) const noexcept { return\
    \ value < rhs.value; }\n    constexpr bool operator<=(const this_type &rhs) const\
    \ noexcept { return value <= rhs.value; }\n    constexpr bool operator>(const\
    \ this_type &rhs) const noexcept { return value > rhs.value; }\n    constexpr\
    \ bool operator>=(const this_type &rhs) const noexcept { return value >= rhs.value;\
    \ }\n    constexpr this_type &operator++() noexcept {\n        ++value;\n    \
    \    if(value == mod())\n            value = 0;\n        return *this;\n    }\n\
    \    constexpr this_type &operator--() noexcept {\n        if(value == 0)\n  \
    \          value = mod();\n        --value;\n        return *this;\n    }\n  \
    \  constexpr this_type operator++(int) noexcept {\n        this_type ret(*this);\n\
    \        ++*this;\n        return ret;\n    }\n    constexpr this_type operator--(int)\
    \ noexcept {\n        this_type ret(*this);\n        --*this;\n        return\
    \ ret;\n    }\n\n    constexpr this_type operator+(const this_type &rhs) const\
    \ noexcept { return this_type(*this) += rhs; }\n    constexpr this_type operator-(const\
    \ this_type &rhs) const noexcept { return this_type(*this) -= rhs; }\n    constexpr\
    \ this_type operator*(const this_type &rhs) const noexcept { return this_type(*this)\
    \ *= rhs; }\n    constexpr this_type operator/(const this_type &rhs) const noexcept\
    \ { return this_type(*this) /= rhs; }\n\n    constexpr this_type &operator+=(const\
    \ this_type &rhs) noexcept {\n        if((value += rhs.value) >= mod())\n    \
    \        value -= mod();\n        return *this;\n    }\n    constexpr this_type\
    \ &operator-=(const this_type &rhs) noexcept {\n        if(value < rhs.value)\n\
    \            value += mod();\n        value -= rhs.value;\n        return *this;\n\
    \    }\n    constexpr this_type &operator*=(const this_type &rhs) noexcept {\n\
    \        value = static_cast<std::uint32_t>(static_cast<std::uint64_t>(value)\
    \ * static_cast<std::uint64_t>(rhs.value) % mod<std::uint64_t>());\n        return\
    \ *this;\n    }\n    constexpr this_type &operator/=(const this_type &rhs) noexcept\
    \ { return *this *= rhs.inv(); }\n\n    template <class T> constexpr this_type\
    \ pow(T n) {\n        this_type ret(1), x(*this);\n        while(n != 0) {\n \
    \           if(n & 1)\n                ret *= x;\n            x *= x;\n      \
    \      n >>= 1;\n        }\n        return ret;\n    }\n    constexpr this_type\
    \ inv() const {\n        std::int64_t s = mod<std::int64_t>(), t = static_cast<std::int64_t>(value),\
    \ a = 0, b = 1;\n        while(t != 0) {\n            const std::int64_t u = s\
    \ / t;\n            s -= t * u;\n            a -= b * u;\n            auto k =\
    \ s;\n            s = t;\n            t = k;\n            k = a;\n           \
    \ a = b;\n            b = k;\n        }\n        if(a < 0)\n            a += mod<std::int64_t>();\n\
    \        return this_type::raw(a);\n    }\n};\n\nusing Modint1000000007 = StaticModint<1000000007>;\n\
    using Modint998244353 = StaticModint<998244353>;\n"
  code: "#pragma once\n\n#include <cstddef>\n#include <cstdint>\n#include <type_traits>\n\
    \ntemplate <std::uint32_t MOD> class StaticModint {\n    using this_type = StaticModint;\n\
    \    std::uint32_t value;\n\n  public:\n    static constexpr std::uint32_t mod()\
    \ noexcept { return MOD; }\n    template <class T> static constexpr T mod() noexcept\
    \ { return static_cast<T>(MOD); }\n\n    template <class T, std::enable_if_t<std::is_unsigned_v<T>>\
    \ * = nullptr> static constexpr std::uint32_t normalize(const T v) noexcept {\n\
    \        return static_cast<std::uint32_t>(v % mod<T>());\n    }\n    template\
    \ <class T, std::enable_if_t<std::is_signed_v<T>> * = nullptr> static constexpr\
    \ std::uint32_t normalize(const T v) noexcept {\n        if(v < 0)\n         \
    \   return static_cast<std::uint32_t>(v % mod<T>() + mod<T>());\n        else\n\
    \            return static_cast<std::uint32_t>(v % mod<T>());\n    }\n\n    constexpr\
    \ StaticModint() noexcept : value(0) {}\n    template <class T> constexpr StaticModint(const\
    \ T v) noexcept : value(normalize(v)) {}\n\n    template <class T> static constexpr\
    \ this_type raw(const T v) noexcept {\n        this_type ret;\n        ret.value\
    \ = static_cast<std::uint32_t>(v);\n        return ret;\n    }\n\n    constexpr\
    \ const std::uint32_t &val() const noexcept { return value; }\n    constexpr this_type\
    \ operator-() const noexcept { return value == 0 ? 0 : mod() - value; }\n\n  \
    \  constexpr bool operator==(const this_type &rhs) const noexcept { return value\
    \ == rhs.value; }\n    constexpr bool operator!=(const this_type &rhs) const noexcept\
    \ { return value != rhs.value; }\n    constexpr bool operator<(const this_type\
    \ &rhs) const noexcept { return value < rhs.value; }\n    constexpr bool operator<=(const\
    \ this_type &rhs) const noexcept { return value <= rhs.value; }\n    constexpr\
    \ bool operator>(const this_type &rhs) const noexcept { return value > rhs.value;\
    \ }\n    constexpr bool operator>=(const this_type &rhs) const noexcept { return\
    \ value >= rhs.value; }\n    constexpr this_type &operator++() noexcept {\n  \
    \      ++value;\n        if(value == mod())\n            value = 0;\n        return\
    \ *this;\n    }\n    constexpr this_type &operator--() noexcept {\n        if(value\
    \ == 0)\n            value = mod();\n        --value;\n        return *this;\n\
    \    }\n    constexpr this_type operator++(int) noexcept {\n        this_type\
    \ ret(*this);\n        ++*this;\n        return ret;\n    }\n    constexpr this_type\
    \ operator--(int) noexcept {\n        this_type ret(*this);\n        --*this;\n\
    \        return ret;\n    }\n\n    constexpr this_type operator+(const this_type\
    \ &rhs) const noexcept { return this_type(*this) += rhs; }\n    constexpr this_type\
    \ operator-(const this_type &rhs) const noexcept { return this_type(*this) -=\
    \ rhs; }\n    constexpr this_type operator*(const this_type &rhs) const noexcept\
    \ { return this_type(*this) *= rhs; }\n    constexpr this_type operator/(const\
    \ this_type &rhs) const noexcept { return this_type(*this) /= rhs; }\n\n    constexpr\
    \ this_type &operator+=(const this_type &rhs) noexcept {\n        if((value +=\
    \ rhs.value) >= mod())\n            value -= mod();\n        return *this;\n \
    \   }\n    constexpr this_type &operator-=(const this_type &rhs) noexcept {\n\
    \        if(value < rhs.value)\n            value += mod();\n        value -=\
    \ rhs.value;\n        return *this;\n    }\n    constexpr this_type &operator*=(const\
    \ this_type &rhs) noexcept {\n        value = static_cast<std::uint32_t>(static_cast<std::uint64_t>(value)\
    \ * static_cast<std::uint64_t>(rhs.value) % mod<std::uint64_t>());\n        return\
    \ *this;\n    }\n    constexpr this_type &operator/=(const this_type &rhs) noexcept\
    \ { return *this *= rhs.inv(); }\n\n    template <class T> constexpr this_type\
    \ pow(T n) {\n        this_type ret(1), x(*this);\n        while(n != 0) {\n \
    \           if(n & 1)\n                ret *= x;\n            x *= x;\n      \
    \      n >>= 1;\n        }\n        return ret;\n    }\n    constexpr this_type\
    \ inv() const {\n        std::int64_t s = mod<std::int64_t>(), t = static_cast<std::int64_t>(value),\
    \ a = 0, b = 1;\n        while(t != 0) {\n            const std::int64_t u = s\
    \ / t;\n            s -= t * u;\n            a -= b * u;\n            auto k =\
    \ s;\n            s = t;\n            t = k;\n            k = a;\n           \
    \ a = b;\n            b = k;\n        }\n        if(a < 0)\n            a += mod<std::int64_t>();\n\
    \        return this_type::raw(a);\n    }\n};\n\nusing Modint1000000007 = StaticModint<1000000007>;\n\
    using Modint998244353 = StaticModint<998244353>;"
  dependsOn: []
  isVerificationFile: false
  path: math/static_modint.cpp
  requiredBy: []
  timestamp: '2021-11-04 00:39:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/static_modint.cpp
layout: document
redirect_from:
- /library/math/static_modint.cpp
- /library/math/static_modint.cpp.html
title: math/static_modint.cpp
---
