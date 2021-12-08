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
  bundledCode: "#line 2 \"utility/repstep.cpp\"\n\n#line 2 \"utility/int_alias.cpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nusing i8 = std::int8_t;\nusing u8\
    \ = std::uint8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    #line 4 \"utility/repstep.cpp\"\n\nclass repstep {\n    struct repstep_iterator\
    \ {\n        usize itr, stepsize;\n        constexpr repstep_iterator(const usize\
    \ pos, const usize stp) noexcept\n            : itr(pos), stepsize(stp) {}\n \
    \       constexpr void operator++() noexcept {\n            itr += stepsize;\n\
    \        }\n        constexpr bool operator!=(const usize &other) const noexcept\
    \ {\n            return itr < other;\n        }\n        constexpr usize operator*()\
    \ const noexcept {\n            return itr;\n        }\n    };\n\n    const repstep_iterator\
    \ first;\n    const usize last;\n\n  public:\n    constexpr repstep(const usize\
    \ first_, const usize last_, const usize stp_)\n        : first(first_, stp_),\
    \ last(last_) {}\n    constexpr repstep_iterator begin() const noexcept {\n  \
    \      return first;\n    }\n    constexpr usize end() const noexcept {\n    \
    \    return last;\n    }\n};\n"
  code: "#pragma once\n\n#include \"../utility/int_alias.cpp\"\n\nclass repstep {\n\
    \    struct repstep_iterator {\n        usize itr, stepsize;\n        constexpr\
    \ repstep_iterator(const usize pos, const usize stp) noexcept\n            : itr(pos),\
    \ stepsize(stp) {}\n        constexpr void operator++() noexcept {\n         \
    \   itr += stepsize;\n        }\n        constexpr bool operator!=(const usize\
    \ &other) const noexcept {\n            return itr < other;\n        }\n     \
    \   constexpr usize operator*() const noexcept {\n            return itr;\n  \
    \      }\n    };\n\n    const repstep_iterator first;\n    const usize last;\n\
    \n  public:\n    constexpr repstep(const usize first_, const usize last_, const\
    \ usize stp_)\n        : first(first_, stp_), last(last_) {}\n    constexpr repstep_iterator\
    \ begin() const noexcept {\n        return first;\n    }\n    constexpr usize\
    \ end() const noexcept {\n        return last;\n    }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/repstep.cpp
  requiredBy: []
  timestamp: '2021-12-08 20:23:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/repstep.cpp
layout: document
redirect_from:
- /library/utility/repstep.cpp
- /library/utility/repstep.cpp.html
title: utility/repstep.cpp
---
