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
  bundledCode: "#line 2 \"graph/union-find.cpp\"\n\n#line 2 \"utility/int_alias.cpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nusing i8 = std::int8_t;\nusing u8\
    \ = std::uint8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    #line 4 \"graph/union-find.cpp\"\n#include <algorithm>\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\n\nclass UnionFind {\n  public:\n    struct node_type\
    \ {\n        usize parent;\n        usize size;\n    };\n\n  private:\n    usize\
    \ components;\n    std::vector<node_type> data;\n\n  public:\n    explicit UnionFind(const\
    \ usize n_) : components(n_), data(n_, {0, 1}) {\n        for (usize i = 0; i\
    \ < n_; ++i) {\n            data[i].parent = i;\n        }\n    }\n\n    usize\
    \ size() const {\n        return data.size();\n    }\n\n    usize count_components()\
    \ const {\n        return components;\n    }\n\n    usize leader(usize v) {\n\
    \        assert(v < size());\n        if (data[v].parent == v) return v;\n   \
    \     data[v].parent = leader(data[v].parent);\n        return data[v].parent;\n\
    \    }\n\n    usize size(const usize v) {\n        assert(v < size());\n     \
    \   return data[leader(v)].size;\n    }\n\n    std::pair<usize, usize> unite(usize\
    \ x, usize y) {\n        assert(x < size());\n        assert(y < size());\n  \
    \      x = leader(x);\n        y = leader(y);\n        if (x != y) {\n       \
    \     if (data[x].size < data[y].size) std::swap(x, y);\n            data[y].parent\
    \ = x;\n            data[x].size += data[y].size;\n        }\n        return {x,\
    \ y};\n    }\n\n    std::vector<std::vector<usize>> decompose() {\n        std::vector<std::vector<usize>>\
    \ ret(size());\n        for (usize i = 0; i < size(); ++i)\n            ret[leader(i)].push_back(i);\n\
    \n        ret.erase(std::remove_if(ret.begin(), ret.end(),\n                 \
    \                [&](const std::vector<usize> &v) { return v.empty(); }),\n  \
    \                ret.end());\n        return ret;\n    }\n};\n"
  code: "#pragma once\n\n#include \"../utility/int_alias.cpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\nclass UnionFind {\n\
    \  public:\n    struct node_type {\n        usize parent;\n        usize size;\n\
    \    };\n\n  private:\n    usize components;\n    std::vector<node_type> data;\n\
    \n  public:\n    explicit UnionFind(const usize n_) : components(n_), data(n_,\
    \ {0, 1}) {\n        for (usize i = 0; i < n_; ++i) {\n            data[i].parent\
    \ = i;\n        }\n    }\n\n    usize size() const {\n        return data.size();\n\
    \    }\n\n    usize count_components() const {\n        return components;\n \
    \   }\n\n    usize leader(usize v) {\n        assert(v < size());\n        if\
    \ (data[v].parent == v) return v;\n        data[v].parent = leader(data[v].parent);\n\
    \        return data[v].parent;\n    }\n\n    usize size(const usize v) {\n  \
    \      assert(v < size());\n        return data[leader(v)].size;\n    }\n\n  \
    \  std::pair<usize, usize> unite(usize x, usize y) {\n        assert(x < size());\n\
    \        assert(y < size());\n        x = leader(x);\n        y = leader(y);\n\
    \        if (x != y) {\n            if (data[x].size < data[y].size) std::swap(x,\
    \ y);\n            data[y].parent = x;\n            data[x].size += data[y].size;\n\
    \        }\n        return {x, y};\n    }\n\n    std::vector<std::vector<usize>>\
    \ decompose() {\n        std::vector<std::vector<usize>> ret(size());\n      \
    \  for (usize i = 0; i < size(); ++i)\n            ret[leader(i)].push_back(i);\n\
    \n        ret.erase(std::remove_if(ret.begin(), ret.end(),\n                 \
    \                [&](const std::vector<usize> &v) { return v.empty(); }),\n  \
    \                ret.end());\n        return ret;\n    }\n};"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: graph/union-find.cpp
  requiredBy: []
  timestamp: '2021-12-08 20:23:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/union-find.cpp
layout: document
redirect_from:
- /library/graph/union-find.cpp
- /library/graph/union-find.cpp.html
title: graph/union-find.cpp
---
