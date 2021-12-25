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
  bundledCode: "#line 2 \"utility/int_literal.cpp\"\n\n#line 2 \"utility/int_alias.cpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nusing i8 = std::int8_t;\nusing u8\
    \ = std::uint8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    #line 6 \"utility/int_literal.cpp\"\n\nconstexpr std::int8_t operator\"\"_i8(unsigned\
    \ long long n) noexcept {\n    return static_cast<std::int8_t>(n);\n}\nconstexpr\
    \ std::int16_t operator\"\"_i16(unsigned long long n) noexcept {\n    return static_cast<std::int16_t>(n);\n\
    }\nconstexpr std::int32_t operator\"\"_i32(unsigned long long n) noexcept {\n\
    \    return static_cast<std::int32_t>(n);\n}\nconstexpr std::int64_t operator\"\
    \"_i64(unsigned long long n) noexcept {\n    return static_cast<std::int64_t>(n);\n\
    }\n\nconstexpr std::int8_t operator\"\"_u8(unsigned long long n) noexcept {\n\
    \    return static_cast<std::uint8_t>(n);\n}\nconstexpr std::uint16_t operator\"\
    \"_u16(unsigned long long n) noexcept {\n    return static_cast<std::uint16_t>(n);\n\
    }\nconstexpr std::uint32_t operator\"\"_u32(unsigned long long n) noexcept {\n\
    \    return static_cast<std::uint32_t>(n);\n}\nconstexpr std::uint64_t operator\"\
    \"_u64(unsigned long long n) noexcept {\n    return static_cast<std::uint64_t>(n);\n\
    }\n\nconstexpr isize operator\"\"_iz(unsigned long long n) noexcept {\n    return\
    \ static_cast<isize>(n);\n}\nconstexpr usize operator\"\"_uz(unsigned long long\
    \ n) noexcept {\n    return static_cast<usize>(n);\n}\n"
  code: "#pragma once\n\n#include \"../utility/int_alias.cpp\"\n#include <cstddef>\n\
    #include <cstdint>\n\nconstexpr std::int8_t operator\"\"_i8(unsigned long long\
    \ n) noexcept {\n    return static_cast<std::int8_t>(n);\n}\nconstexpr std::int16_t\
    \ operator\"\"_i16(unsigned long long n) noexcept {\n    return static_cast<std::int16_t>(n);\n\
    }\nconstexpr std::int32_t operator\"\"_i32(unsigned long long n) noexcept {\n\
    \    return static_cast<std::int32_t>(n);\n}\nconstexpr std::int64_t operator\"\
    \"_i64(unsigned long long n) noexcept {\n    return static_cast<std::int64_t>(n);\n\
    }\n\nconstexpr std::int8_t operator\"\"_u8(unsigned long long n) noexcept {\n\
    \    return static_cast<std::uint8_t>(n);\n}\nconstexpr std::uint16_t operator\"\
    \"_u16(unsigned long long n) noexcept {\n    return static_cast<std::uint16_t>(n);\n\
    }\nconstexpr std::uint32_t operator\"\"_u32(unsigned long long n) noexcept {\n\
    \    return static_cast<std::uint32_t>(n);\n}\nconstexpr std::uint64_t operator\"\
    \"_u64(unsigned long long n) noexcept {\n    return static_cast<std::uint64_t>(n);\n\
    }\n\nconstexpr isize operator\"\"_iz(unsigned long long n) noexcept {\n    return\
    \ static_cast<isize>(n);\n}\nconstexpr usize operator\"\"_uz(unsigned long long\
    \ n) noexcept {\n    return static_cast<usize>(n);\n}\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/int_literal.cpp
  requiredBy: []
  timestamp: '2021-12-08 20:23:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/int_literal.cpp
layout: document
redirect_from:
- /library/utility/int_literal.cpp
- /library/utility/int_literal.cpp.html
title: utility/int_literal.cpp
---
