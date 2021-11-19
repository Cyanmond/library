---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: utility/eoln.cpp
    title: utility/eoln.cpp
  - icon: ':question:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':question:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  - icon: ':question:'
    path: utility/scan.cpp
    title: utility/scan.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/many_aplusb
    links:
    - https://judge.yosupo.jp/problem/many_aplusb
  bundledCode: "#line 1 \"verify/library-checker/many_aplusb.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/many_aplusb\"\n\n#include <iostream>\n#include\
    \ <vector>\n\n#line 2 \"utility/eoln.cpp\"\n\nconstexpr char eoln = '\\n';\n#line\
    \ 2 \"utility/int_alias.cpp\"\n\n#include <cstddef>\n#include <cstdint>\n\nusing\
    \ i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\nusing\
    \ i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing u16 = std::uint16_t;\n\
    using u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    using isize = std::ptrdiff_t;\n#line 2 \"utility/rep.cpp\"\n\n#line 4 \"utility/rep.cpp\"\
    \n\nclass rep {\n    struct rep_iterator {\n        usize itr;\n        constexpr\
    \ rep_iterator(const usize pos) noexcept : itr(pos) {}\n        constexpr void\
    \ operator++() noexcept { ++itr; }\n        constexpr bool operator!=(const usize\
    \ &other) const noexcept { return itr != other; }\n        constexpr usize operator*()\
    \ const noexcept { return itr; }\n    };\n    const rep_iterator first;\n    const\
    \ usize last;\n\n  public:\n    constexpr rep(const usize first_, const usize\
    \ last_) noexcept : first(first_), last(last_) {}\n    constexpr rep_iterator\
    \ begin() const noexcept { return first; }\n    constexpr usize end() const noexcept\
    \ { return last; }\n};\n#line 2 \"utility/scan.cpp\"\n\n#line 4 \"utility/scan.cpp\"\
    \n\ntemplate <typename T> inline T scan() {\n    T x;\n    std::cin >> x;\n  \
    \  return x;\n}\n#line 10 \"verify/library-checker/many_aplusb.test.cpp\"\n\n\
    int main(void) {\n    const usize T = scan<usize>();\n    std::vector<i64> A(T),\
    \ B(T);\n    for (const auto i : rep(0, T)) {\n        A[i] = scan<i64>();\n \
    \       B[i] = scan<i64>();\n        std::cout << A[i] + B[i] << eoln;\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../../utility/eoln.cpp\"\n#include\
    \ \"../../utility/int_alias.cpp\"\n#include \"../../utility/rep.cpp\"\n#include\
    \ \"../../utility/scan.cpp\"\n\nint main(void) {\n    const usize T = scan<usize>();\n\
    \    std::vector<i64> A(T), B(T);\n    for (const auto i : rep(0, T)) {\n    \
    \    A[i] = scan<i64>();\n        B[i] = scan<i64>();\n        std::cout << A[i]\
    \ + B[i] << eoln;\n    }\n}"
  dependsOn:
  - utility/eoln.cpp
  - utility/int_alias.cpp
  - utility/rep.cpp
  - utility/scan.cpp
  isVerificationFile: true
  path: verify/library-checker/many_aplusb.test.cpp
  requiredBy: []
  timestamp: '2021-11-19 22:47:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library-checker/many_aplusb.test.cpp
layout: document
redirect_from:
- /verify/verify/library-checker/many_aplusb.test.cpp
- /verify/verify/library-checker/many_aplusb.test.cpp.html
title: verify/library-checker/many_aplusb.test.cpp
---
