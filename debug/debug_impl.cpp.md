---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':warning:'
    path: utility/int_infinity.cpp
    title: utility/int_infinity.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"debug/debug_impl.cpp\"\n\n#line 2 \"utility/int_infinity.cpp\"\
    \n\n#line 2 \"utility/int_alias.cpp\"\n\n#include <cstddef>\n#include <cstdint>\n\
    \nusing i8 = std::int8_t;\nusing u8 = std::uint8_t;\nusing i16 = std::int16_t;\n\
    using i32 = std::int32_t;\nusing i64 = std::int64_t;\nusing u16 = std::uint16_t;\n\
    using u32 = std::uint32_t;\nusing u64 = std::uint64_t;\n\nusing usize = std::size_t;\n\
    using isize = std::ptrdiff_t;\n#line 4 \"utility/int_infinity.cpp\"\n#include\
    \ <limits>\n\ntemplate <class T, T Div = 2> constexpr T infty = std::numeric_limits<T>::max()\
    \ / Div;\n\nconstexpr i32 infi32 = infty<i32, 2>;\nconstexpr i64 infi64 = infty<i64,\
    \ 4>;\n\nconstexpr u32 infu32 = infty<u32, 4>;\nconstexpr u64 infu64 = infty<u32,\
    \ 4>;\n\nconstexpr isize infisz = infty<isize, 2>;\nconstexpr usize infusz = infty<usize,\
    \ 4>;\n#line 4 \"debug/debug_impl.cpp\"\n#include <array>\n#line 6 \"debug/debug_impl.cpp\"\
    \n#include <iostream>\n#include <map>\n#include <optional>\n#include <set>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace debug_impl {\ntemplate <class T> inline\
    \ void dump(const T &v);\nvoid dump(const std::int32_t &v);\nvoid dump(const std::int64_t\
    \ &v);\nvoid dump(const usize &v);\ntemplate <class T, class U> void dump(const\
    \ std::pair<T, U> &v);\ntemplate <class... T> void dump(const std::tuple<T...>\
    \ &v);\ntemplate <class T> void dump(const std::vector<T> &v);\ntemplate <class\
    \ T, size_t s> void dump(const std::array<T, s> &v);\ntemplate <class T> void\
    \ dump(const std::set<T> &v);\ntemplate <class T, class U> void dump(const std::map<T,\
    \ U> &v);\ntemplate <class T> void dump(const std::optional<T> &v);\n\ntemplate\
    \ <class T> inline void dump(const T &v) { std::cout << v; }\n\nvoid dump(const\
    \ std::int32_t &v) {\n    if (v == infi32)\n        std::cout << \"inf\";\n  \
    \  else if (v == -infi32)\n        std::cout << \"-inf\";\n    else\n        std::cout\
    \ << v;\n}\n\nvoid dump(const std::int64_t &v) {\n    if (v == infi32 or v ==\
    \ infi64)\n        std::cout << \"inf\";\n    else if (v == -infi32 or v == -infi64)\n\
    \        std::cout << \"-inf\";\n    else\n        std::cout << v;\n}\n\nvoid\
    \ dump(const usize &v) {\n    if (v == infusz)\n        std::cout << \"inf\";\n\
    \    else\n        std::cout << v;\n}\n\ntemplate <class T> void dump(const std::optional<T>\
    \ &v) {\n    if (v)\n        dump(v.value());\n    else\n        dump(\"nullopt\"\
    );\n}\n\ntemplate <class T, class U> void dump(const std::pair<T, U> &v) {\n \
    \   std::cout << \"( \";\n    dump(v.first);\n    std::cout << \", \";\n    dump(v.second);\n\
    \    std::cout << \" )\";\n}\n\ntemplate <class T> void dump(const std::vector<T>\
    \ &v) {\n    std::cout << \"[ \";\n    for (usize i = 0; i < v.size(); ++i) {\n\
    \        dump(v[i]);\n        if (i != v.size() - 1) std::cout << \", \";\n  \
    \  }\n    std::cout << \" ]\";\n}\ntemplate <class T, size_t S> void dump(const\
    \ std::array<T, S> &v) {\n    std::cout << \"[ \";\n    for (usize i = 0; i <\
    \ S; ++i) {\n        dump(v[i]);\n        if (i != v.size() - 1) std::cout <<\
    \ \", \";\n    }\n    std::cout << \" ]\";\n}\n\ntemplate <class T> void dump(const\
    \ std::set<T> &v) {\n    std::vector<T> r;\n    for (const auto &x : v)\n    \
    \    r.push_back(x);\n    dump(r);\n}\ntemplate <class T, class U> void dump(const\
    \ std::map<T, U> &v) {\n    std::vector<std::pair<T, U>> r;\n    for (const auto\
    \ &p : v)\n        r.push_back(p);\n    dump(r);\n}\nvoid tuple_dump_impl() {\
    \ std::cout << \" )\"; }\ntemplate <class Head, class... Tail> void tuple_dump_impl(const\
    \ Head &h, const Tail &...t) {\n    std::cout << h;\n    if constexpr (sizeof...(Tail)\
    \ != 0) std::cout << \", \";\n    tuple_dump_impl(t...);\n}\n\ntemplate <class...\
    \ T> void dump(const std::tuple<T...> &v) {\n    std::cout << \"( \";\n    std::apply(tuple_dump_impl<T...>,\
    \ v);\n}\n\nvoid converter() { std::cout << '\\n'; }\ntemplate <class Head, class...\
    \ Tail> void converter(Head &&h, Tail &&...t) {\n    dump(h);\n    if constexpr\
    \ (sizeof...(Tail) != 0) std::cout << \", \";\n    converter(std::forward<Tail>(t)...);\n\
    }\n} // namespace debug_impl\n"
  code: "#pragma once\n\n#include \"../utility/int_infinity.cpp\"\n#include <array>\n\
    #include <cstddef>\n#include <iostream>\n#include <map>\n#include <optional>\n\
    #include <set>\n#include <utility>\n#include <vector>\n\nnamespace debug_impl\
    \ {\ntemplate <class T> inline void dump(const T &v);\nvoid dump(const std::int32_t\
    \ &v);\nvoid dump(const std::int64_t &v);\nvoid dump(const usize &v);\ntemplate\
    \ <class T, class U> void dump(const std::pair<T, U> &v);\ntemplate <class...\
    \ T> void dump(const std::tuple<T...> &v);\ntemplate <class T> void dump(const\
    \ std::vector<T> &v);\ntemplate <class T, size_t s> void dump(const std::array<T,\
    \ s> &v);\ntemplate <class T> void dump(const std::set<T> &v);\ntemplate <class\
    \ T, class U> void dump(const std::map<T, U> &v);\ntemplate <class T> void dump(const\
    \ std::optional<T> &v);\n\ntemplate <class T> inline void dump(const T &v) { std::cout\
    \ << v; }\n\nvoid dump(const std::int32_t &v) {\n    if (v == infi32)\n      \
    \  std::cout << \"inf\";\n    else if (v == -infi32)\n        std::cout << \"\
    -inf\";\n    else\n        std::cout << v;\n}\n\nvoid dump(const std::int64_t\
    \ &v) {\n    if (v == infi32 or v == infi64)\n        std::cout << \"inf\";\n\
    \    else if (v == -infi32 or v == -infi64)\n        std::cout << \"-inf\";\n\
    \    else\n        std::cout << v;\n}\n\nvoid dump(const usize &v) {\n    if (v\
    \ == infusz)\n        std::cout << \"inf\";\n    else\n        std::cout << v;\n\
    }\n\ntemplate <class T> void dump(const std::optional<T> &v) {\n    if (v)\n \
    \       dump(v.value());\n    else\n        dump(\"nullopt\");\n}\n\ntemplate\
    \ <class T, class U> void dump(const std::pair<T, U> &v) {\n    std::cout << \"\
    ( \";\n    dump(v.first);\n    std::cout << \", \";\n    dump(v.second);\n   \
    \ std::cout << \" )\";\n}\n\ntemplate <class T> void dump(const std::vector<T>\
    \ &v) {\n    std::cout << \"[ \";\n    for (usize i = 0; i < v.size(); ++i) {\n\
    \        dump(v[i]);\n        if (i != v.size() - 1) std::cout << \", \";\n  \
    \  }\n    std::cout << \" ]\";\n}\ntemplate <class T, size_t S> void dump(const\
    \ std::array<T, S> &v) {\n    std::cout << \"[ \";\n    for (usize i = 0; i <\
    \ S; ++i) {\n        dump(v[i]);\n        if (i != v.size() - 1) std::cout <<\
    \ \", \";\n    }\n    std::cout << \" ]\";\n}\n\ntemplate <class T> void dump(const\
    \ std::set<T> &v) {\n    std::vector<T> r;\n    for (const auto &x : v)\n    \
    \    r.push_back(x);\n    dump(r);\n}\ntemplate <class T, class U> void dump(const\
    \ std::map<T, U> &v) {\n    std::vector<std::pair<T, U>> r;\n    for (const auto\
    \ &p : v)\n        r.push_back(p);\n    dump(r);\n}\nvoid tuple_dump_impl() {\
    \ std::cout << \" )\"; }\ntemplate <class Head, class... Tail> void tuple_dump_impl(const\
    \ Head &h, const Tail &...t) {\n    std::cout << h;\n    if constexpr (sizeof...(Tail)\
    \ != 0) std::cout << \", \";\n    tuple_dump_impl(t...);\n}\n\ntemplate <class...\
    \ T> void dump(const std::tuple<T...> &v) {\n    std::cout << \"( \";\n    std::apply(tuple_dump_impl<T...>,\
    \ v);\n}\n\nvoid converter() { std::cout << '\\n'; }\ntemplate <class Head, class...\
    \ Tail> void converter(Head &&h, Tail &&...t) {\n    dump(h);\n    if constexpr\
    \ (sizeof...(Tail) != 0) std::cout << \", \";\n    converter(std::forward<Tail>(t)...);\n\
    }\n} // namespace debug_impl"
  dependsOn:
  - utility/int_infinity.cpp
  - utility/int_alias.cpp
  isVerificationFile: false
  path: debug/debug_impl.cpp
  requiredBy: []
  timestamp: '2021-12-08 20:23:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: debug/debug_impl.cpp
layout: document
redirect_from:
- /library/debug/debug_impl.cpp
- /library/debug/debug_impl.cpp.html
title: debug/debug_impl.cpp
---
