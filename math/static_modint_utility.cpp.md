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
  bundledCode: "#line 2 \"math/static_modint_utility.cpp\"\n\n#line 2 \"utility/int_alias.cpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nusing i8 = std::int8_t;\nusing u8\
    \ = std::uint8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    #line 4 \"math/static_modint_utility.cpp\"\n#include <cassert>\n#include <vector>\n\
    \ntemplate <class M> class StaticModintUtility {\n    static inline usize size\
    \ = 1;\n    static inline std::vector<M> fact = {1, 1};\n    static inline std::vector<M>\
    \ inv = {0, 1};\n    static inline std::vector<M> inv_fact = {1, 1};\n\n    static\
    \ void reserve(const usize size_) {\n        if (size < size_) {\n           \
    \ for (usize i = size + 1; i <= size_; ++i) {\n                fact[i] = fact[i\
    \ - 1] * M(i);\n                inv[i] = -M(M::mod() / i) * inv[i - 1];\n    \
    \            inv_fact[i] = inv_fact[i - 1] * inv[i];\n            }\n        \
    \    size = size_;\n        }\n    }\n\n  public:\n    static M get_fact(const\
    \ usize i) {\n        reserve(i + 1);\n        return fact[i];\n    }\n\n    static\
    \ M get_inv(const usize i) {\n        assert(i != 0);\n        reserve(i + 1);\n\
    \        return inv[i];\n    }\n\n    static M get_inv_fact(const usize i) {\n\
    \        reserve(i + 1);\n        return inv_fact[i];\n    }\n\n    static M comb(const\
    \ usize n, const usize k) {\n        assert(k <= n);\n        reserve(n + 1);\n\
    \        return fact[n] * inv_fact[n - k] * inv_fact[k];\n    }\n\n    static\
    \ M perm(const usize n, const usize k) {\n        assert(k <= n);\n        reserve(n\
    \ + 1);\n        return fact[n] * inv_fact[n - k];\n    }\n\n    static M homo(const\
    \ usize n, const usize k) {\n        if (n == 0 and k == 0) return 1;\n      \
    \  reserve(n + k);\n        return comb(n + k - 1, k);\n    }\n};\n"
  code: "#pragma once\n\n#include \"../utility/int_alias.cpp\"\n#include <cassert>\n\
    #include <vector>\n\ntemplate <class M> class StaticModintUtility {\n    static\
    \ inline usize size = 1;\n    static inline std::vector<M> fact = {1, 1};\n  \
    \  static inline std::vector<M> inv = {0, 1};\n    static inline std::vector<M>\
    \ inv_fact = {1, 1};\n\n    static void reserve(const usize size_) {\n       \
    \ if (size < size_) {\n            for (usize i = size + 1; i <= size_; ++i) {\n\
    \                fact[i] = fact[i - 1] * M(i);\n                inv[i] = -M(M::mod()\
    \ / i) * inv[i - 1];\n                inv_fact[i] = inv_fact[i - 1] * inv[i];\n\
    \            }\n            size = size_;\n        }\n    }\n\n  public:\n   \
    \ static M get_fact(const usize i) {\n        reserve(i + 1);\n        return\
    \ fact[i];\n    }\n\n    static M get_inv(const usize i) {\n        assert(i !=\
    \ 0);\n        reserve(i + 1);\n        return inv[i];\n    }\n\n    static M\
    \ get_inv_fact(const usize i) {\n        reserve(i + 1);\n        return inv_fact[i];\n\
    \    }\n\n    static M comb(const usize n, const usize k) {\n        assert(k\
    \ <= n);\n        reserve(n + 1);\n        return fact[n] * inv_fact[n - k] *\
    \ inv_fact[k];\n    }\n\n    static M perm(const usize n, const usize k) {\n \
    \       assert(k <= n);\n        reserve(n + 1);\n        return fact[n] * inv_fact[n\
    \ - k];\n    }\n\n    static M homo(const usize n, const usize k) {\n        if\
    \ (n == 0 and k == 0) return 1;\n        reserve(n + k);\n        return comb(n\
    \ + k - 1, k);\n    }\n};\n"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: math/static_modint_utility.cpp
  requiredBy: []
  timestamp: '2021-12-08 20:23:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/static_modint_utility.cpp
layout: document
redirect_from:
- /library/math/static_modint_utility.cpp
- /library/math/static_modint_utility.cpp.html
title: math/static_modint_utility.cpp
---
