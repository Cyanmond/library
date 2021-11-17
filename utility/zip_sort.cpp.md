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
  bundledCode: "#line 2 \"utility/zip_sort.cpp\"\n\n#line 2 \"utility/int_alias.cpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nusing i8 = std::int8_t;\nusing u8\
    \ = std::uint8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    #line 4 \"utility/zip_sort.cpp\"\n#include <algorithm>\n#include <vector>\n\n\
    namespace helper {\ntemplate <class T, class... Tail>\nvoid zip_sort_renumber(const\
    \ std::vector<usize> &order, std::vector<T> &head, Tail &...tail) {\n    const\
    \ usize n = order.size();\n    std::vector<T> sorted_head(n);\n    for (usize\
    \ i = 0; i < n; ++i)\n        sorted_head[i] = head[order[i]];\n    head = std::move(sorted_head);\n\
    \    if constexpr (sizeof...(Tail) != 0) zip_sort_renumber(order, tail...);\n\
    }\n} // namespace helper\n\ntemplate <class Head, class... Tail>\nstd::vector<usize>\
    \ zip_sort(std::vector<Head> &head, std::vector<Tail> &...tail) {\n    const usize\
    \ n = head.size();\n\n    std::vector<std::tuple<Head, Tail..., usize>> res(n);\n\
    \    for (usize i = 0; i < n; ++i)\n        res[i] = std::make_tuple(head[i],\
    \ tail[i]..., i);\n    std::sort(res.begin(), res.end());\n\n    std::vector<usize>\
    \ order(n);\n    for (usize i = 0; i < n; ++i)\n        order[i] = std::get<std::tuple_size_v<std::tuple<Head,\
    \ Tail...>>>(res[i]);\n    helper::zip_sort_renumber(order, head, tail...);\n\
    \    return order;\n}\n"
  code: "#pragma once\n\n#include \"../utility/int_alias.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\nnamespace helper {\ntemplate <class T, class... Tail>\nvoid\
    \ zip_sort_renumber(const std::vector<usize> &order, std::vector<T> &head, Tail\
    \ &...tail) {\n    const usize n = order.size();\n    std::vector<T> sorted_head(n);\n\
    \    for (usize i = 0; i < n; ++i)\n        sorted_head[i] = head[order[i]];\n\
    \    head = std::move(sorted_head);\n    if constexpr (sizeof...(Tail) != 0) zip_sort_renumber(order,\
    \ tail...);\n}\n} // namespace helper\n\ntemplate <class Head, class... Tail>\n\
    std::vector<usize> zip_sort(std::vector<Head> &head, std::vector<Tail> &...tail)\
    \ {\n    const usize n = head.size();\n\n    std::vector<std::tuple<Head, Tail...,\
    \ usize>> res(n);\n    for (usize i = 0; i < n; ++i)\n        res[i] = std::make_tuple(head[i],\
    \ tail[i]..., i);\n    std::sort(res.begin(), res.end());\n\n    std::vector<usize>\
    \ order(n);\n    for (usize i = 0; i < n; ++i)\n        order[i] = std::get<std::tuple_size_v<std::tuple<Head,\
    \ Tail...>>>(res[i]);\n    helper::zip_sort_renumber(order, head, tail...);\n\
    \    return order;\n}"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: utility/zip_sort.cpp
  requiredBy: []
  timestamp: '2021-11-07 20:31:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/zip_sort.cpp
layout: document
redirect_from:
- /library/utility/zip_sort.cpp
- /library/utility/zip_sort.cpp.html
title: utility/zip_sort.cpp
---
