---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/library-checker/point_add_range_sum_1.cpp
    title: verify/library-checker/point_add_range_sum_1.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library-checker/many_aplusb.test.cpp
    title: verify/library-checker/many_aplusb.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utility/rep.cpp\"\n\n#line 2 \"utility/int_alias.cpp\"\n\
    \n#include <cstddef>\n#include <cstdint>\n\nusing i8 = std::int8_t;\nusing u8\
    \ = std::uint8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    #line 4 \"utility/rep.cpp\"\n\nclass rep {\n    struct rep_iterator {\n      \
    \  usize itr;\n        constexpr rep_iterator(const usize pos) noexcept : itr(pos)\
    \ {}\n        constexpr void operator++() noexcept { ++itr; }\n        constexpr\
    \ bool operator!=(const usize &other) const noexcept { return itr != other; }\n\
    \        constexpr usize operator*() const noexcept { return itr; }\n    };\n\
    \    const rep_iterator first;\n    const usize last;\n\n  public:\n    constexpr\
    \ rep(const usize first_, const usize last_) noexcept : first(first_), last(last_)\
    \ {}\n    constexpr rep_iterator begin() const noexcept { return first; }\n  \
    \  constexpr usize end() const noexcept { return last; }\n};\n"
  code: "#pragma once\n\n#include \"../utility/int_alias.cpp\"\n\nclass rep {\n  \
    \  struct rep_iterator {\n        usize itr;\n        constexpr rep_iterator(const\
    \ usize pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept\
    \ { ++itr; }\n        constexpr bool operator!=(const usize &other) const noexcept\
    \ { return itr != other; }\n        constexpr usize operator*() const noexcept\
    \ { return itr; }\n    };\n    const rep_iterator first;\n    const usize last;\n\
    \n  public:\n    constexpr rep(const usize first_, const usize last_) noexcept\
    \ : first(first_), last(last_) {}\n    constexpr rep_iterator begin() const noexcept\
    \ { return first; }\n    constexpr usize end() const noexcept { return last; }\n\
    };\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/rep.cpp
  requiredBy:
  - verify/library-checker/point_add_range_sum_1.cpp
  timestamp: '2021-11-04 00:40:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library-checker/many_aplusb.test.cpp
documentation_of: utility/rep.cpp
layout: document
redirect_from:
- /library/utility/rep.cpp
- /library/utility/rep.cpp.html
title: utility/rep.cpp
---
