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
  bundledCode: "#line 2 \"utility/to4.cpp\"\n\n#line 2 \"utility/int_alias.cpp\"\n\
    \n#include <cstddef>\n#include <cstdint>\n\nusing i8 = std::int8_t;\nusing u8\
    \ = std::uint8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    #line 4 \"utility/to4.cpp\"\n#include <array>\n#include <limits>\n#include <type_traits>\n\
    \nclass to4 {\n    using value_type = usize;\n    static_assert(std::is_unsigned_v<value_type>);\n\
    \    static constexpr value_type minus1 = std::numeric_limits<value_type>::max();\n\
    \    static constexpr std::array<value_type, 5> dx = {minus1, 0, 1, 0, 0}, dy\
    \ = {0, minus1, 0, 1, 0};\n\n    struct to4_iterator {\n        int d;\n     \
    \   const value_type h, w, maxh, maxw;\n        constexpr to4_iterator(const value_type\
    \ h_, const value_type w_, const value_type maxh_,\n                         \
    \      const value_type maxw_) noexcept\n            : d(0), h(h_), w(w_), maxh(maxh_),\
    \ maxw(maxw_) {\n\n            while (d != 4 and (h + dx[d] == minus1 or h + dx[d]\
    \ == maxh or w + dy[d] == minus1 or\n                               w + dy[d]\
    \ == maxw)) {\n                ++d;\n            }\n        }\n        constexpr\
    \ void operator++() noexcept {\n            do {\n                ++d;\n     \
    \       } while (d != 4 and (h + dx[d] == minus1 or h + dx[d] == maxh or w + dy[d]\
    \ == minus1 or\n                                 w + dy[d] == maxw));\n      \
    \  }\n        constexpr bool operator!=(const int other) const noexcept {\n  \
    \          return d != other;\n        }\n        constexpr std::pair<value_type,\
    \ value_type> operator*() const noexcept {\n            return {h + dx[d], w +\
    \ dy[d]};\n        }\n    };\n\n    const to4_iterator i;\n\n  public:\n    constexpr\
    \ to4(const value_type h, const value_type w, const value_type maxh,\n       \
    \           const value_type maxw) noexcept\n        : i(h, w, maxh, maxw) {}\n\
    \    constexpr to4_iterator begin() const noexcept {\n        return i;\n    }\n\
    \    constexpr int end() const noexcept {\n        return 4;\n    }\n};\n"
  code: "#pragma once\n\n#include \"../utility/int_alias.cpp\"\n#include <array>\n\
    #include <limits>\n#include <type_traits>\n\nclass to4 {\n    using value_type\
    \ = usize;\n    static_assert(std::is_unsigned_v<value_type>);\n    static constexpr\
    \ value_type minus1 = std::numeric_limits<value_type>::max();\n    static constexpr\
    \ std::array<value_type, 5> dx = {minus1, 0, 1, 0, 0}, dy = {0, minus1, 0, 1,\
    \ 0};\n\n    struct to4_iterator {\n        int d;\n        const value_type h,\
    \ w, maxh, maxw;\n        constexpr to4_iterator(const value_type h_, const value_type\
    \ w_, const value_type maxh_,\n                               const value_type\
    \ maxw_) noexcept\n            : d(0), h(h_), w(w_), maxh(maxh_), maxw(maxw_)\
    \ {\n\n            while (d != 4 and (h + dx[d] == minus1 or h + dx[d] == maxh\
    \ or w + dy[d] == minus1 or\n                               w + dy[d] == maxw))\
    \ {\n                ++d;\n            }\n        }\n        constexpr void operator++()\
    \ noexcept {\n            do {\n                ++d;\n            } while (d !=\
    \ 4 and (h + dx[d] == minus1 or h + dx[d] == maxh or w + dy[d] == minus1 or\n\
    \                                 w + dy[d] == maxw));\n        }\n        constexpr\
    \ bool operator!=(const int other) const noexcept {\n            return d != other;\n\
    \        }\n        constexpr std::pair<value_type, value_type> operator*() const\
    \ noexcept {\n            return {h + dx[d], w + dy[d]};\n        }\n    };\n\n\
    \    const to4_iterator i;\n\n  public:\n    constexpr to4(const value_type h,\
    \ const value_type w, const value_type maxh,\n                  const value_type\
    \ maxw) noexcept\n        : i(h, w, maxh, maxw) {}\n    constexpr to4_iterator\
    \ begin() const noexcept {\n        return i;\n    }\n    constexpr int end()\
    \ const noexcept {\n        return 4;\n    }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/to4.cpp
  requiredBy: []
  timestamp: '2021-12-08 20:23:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/to4.cpp
layout: document
redirect_from:
- /library/utility/to4.cpp
- /library/utility/to4.cpp.html
title: utility/to4.cpp
---
