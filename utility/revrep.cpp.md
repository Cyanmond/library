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
  bundledCode: "#line 2 \"utility/revrep.cpp\"\n\n#line 2 \"utility/int_alias.cpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nusing i8 = std::int8_t;\nusing u8\
    \ = std::uint8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    #line 4 \"utility/revrep.cpp\"\n\nclass revrep {\n    struct revrep_iterator {\n\
    \        usize itr;\n        constexpr revrep_iterator(const usize pos) noexcept\
    \ : itr(pos) {}\n        constexpr void operator++() noexcept { --itr; }\n   \
    \     constexpr bool operator!=(const usize &other) const noexcept { return itr\
    \ != other; }\n        constexpr usize operator*() const noexcept { return itr;\
    \ }\n    };\n    const revrep_iterator first;\n    const usize last;\n\n  public:\n\
    \    constexpr revrep(const usize first_, const usize last_) noexcept\n      \
    \  : first(last_ - 1), last(first_ - 1) {}\n    constexpr revrep_iterator begin()\
    \ const noexcept { return first; }\n    constexpr usize end() const noexcept {\
    \ return last; }\n};\n"
  code: "#pragma once\n\n#include \"../utility/int_alias.cpp\"\n\nclass revrep {\n\
    \    struct revrep_iterator {\n        usize itr;\n        constexpr revrep_iterator(const\
    \ usize pos) noexcept : itr(pos) {}\n        constexpr void operator++() noexcept\
    \ { --itr; }\n        constexpr bool operator!=(const usize &other) const noexcept\
    \ { return itr != other; }\n        constexpr usize operator*() const noexcept\
    \ { return itr; }\n    };\n    const revrep_iterator first;\n    const usize last;\n\
    \n  public:\n    constexpr revrep(const usize first_, const usize last_) noexcept\n\
    \        : first(last_ - 1), last(first_ - 1) {}\n    constexpr revrep_iterator\
    \ begin() const noexcept { return first; }\n    constexpr usize end() const noexcept\
    \ { return last; }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/revrep.cpp
  requiredBy: []
  timestamp: '2021-11-04 11:05:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/revrep.cpp
layout: document
redirect_from:
- /library/utility/revrep.cpp
- /library/utility/revrep.cpp.html
title: utility/revrep.cpp
---