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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segmenttree.cpp\"\n\n#line 2 \"utility/int_alias.cpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nusing i8 = std::int8_t;\nusing u8\
    \ = std::uint8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    #line 4 \"data-structure/segmenttree.cpp\"\n#include <algorithm>\n#include <cassert>\n\
    #line 7 \"data-structure/segmenttree.cpp\"\n#include <vector>\n\ntemplate <class\
    \ M> class SegmentTree {\n  public:\n    using size_type = usize;\n    using value_type\
    \ = typename M::value_type;\n\n  private:\n    size_type m_n, m_size;\n    std::vector<value_type>\
    \ m_nodes;\n\n  public:\n    explicit SegmentTree(const size_type n) : m_n(n),\
    \ m_size(ceil_pow2(n)) {\n        m_nodes.assign(m_size << 1, M::identity());\n\
    \    }\n\n    SegmentTree(const size_type n, const value_type v) {\n        *this\
    \ = SegmentTree(n, std::vector(n, v));\n    }\n\n    SegmentTree(const size_type\
    \ n, const std::vector<value_type> &s)\n        : m_n(n), m_size(ceil_pow2(n))\
    \ {\n        m_nodes.assign(m_size << 1, M::identity());\n        std::copy(s.begin(),\
    \ s.end(), m_nodes.begin() + m_size);\n        for (size_type i = m_size - 1;\
    \ i != 0; --i)\n            internal_update(i);\n    }\n\n    void set(size_type\
    \ i, const value_type &v) {\n        assert(i < m_n);\n        i += m_size;\n\
    \        m_nodes[i] = v;\n        for (i >>= 1; i != 0; i >>= 1)\n           \
    \ internal_update(i);\n    }\n\n    value_type all_product() const {\n       \
    \ return m_nodes[1];\n    }\n\n    value_type product(size_type l, size_type r)\
    \ const {\n        assert(l <= r);\n        assert(r <= m_n);\n        value_type\
    \ v_l = M::identity(), v_r = M::identity();\n        for (l += m_size, r += m_size;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (l & 1) v_l = M::operation(v_l, m_nodes[l++]);\n\
    \            if (r & 1) v_r = M::operation(m_nodes[--r], v_r);\n        }\n  \
    \      return M::operation(v_l, v_r);\n    }\n\n    value_type get(const size_type\
    \ i) const {\n        assert(i < m_n);\n        return m_nodes[m_size + i];\n\
    \    }\n\n    template <class F> size_type max_right(size_type l, const F &f)\
    \ const {\n        assert(l <= m_n);\n        assert(f(M::identity()));\n    \
    \    if (l == m_n) return m_n;\n\n        l += m_size;\n        value_type sum\
    \ = M::identity();\n        do {\n            while (not(l & 1))\n           \
    \     l >>= 1;\n            if (not f(M::operation(sum, m_nodes[l]))) {\n    \
    \            while (l < m_size) {\n                    l = l << 1;\n         \
    \           if (f(M::operation(sum, m_nodes[l]))) sum = M::operation(sum, m_nodes[l++]);\n\
    \                }\n                return l - m_size;\n            }\n      \
    \      sum = M::operation(sum, m_nodes[l++]);\n        } while ((l & (l - 1))\
    \ != 0);\n        return m_n;\n    }\n\n    template <class F> size_type min_left(size_type\
    \ r, const F &f) const {\n        assert(r <= m_n);\n        assert(f(M::identity()));\n\
    \        if (r == 0) return 0;\n\n        r += m_size;\n        value_type sum\
    \ = M::identity();\n        do {\n            --r;\n            while (r > 1 and\
    \ (r & 1))\n                r >>= 1;\n            if (not f(M::operation(m_nodes[r],\
    \ sum))) {\n                while (r < m_size) {\n                    r = (r <<\
    \ 1) | 1;\n                    if (f(M::operation(m_nodes[r], sum))) sum = M::operation(m_nodes[r--],\
    \ sum);\n                }\n                return r + 1 - m_size;\n         \
    \   }\n            sum = M::operation(m_nodes[r], sum);\n        } while ((r &\
    \ (r - 1)) != 0);\n        return 0;\n    }\n\n  private:\n    static constexpr\
    \ size_type ceil_pow2(const size_type n_) noexcept {\n        size_type res =\
    \ 1;\n        while (res < n_)\n            res <<= 1;\n        return res;\n\
    \    }\n\n    void internal_update(const size_type i) {\n        m_nodes[i] =\
    \ M::operation(m_nodes[i << 1], m_nodes[i << 1 | 1]);\n    }\n};\n"
  code: "#pragma once\n\n#include \"../../library/utility/int_alias.cpp\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <cstddef>\n#include <vector>\n\ntemplate\
    \ <class M> class SegmentTree {\n  public:\n    using size_type = usize;\n   \
    \ using value_type = typename M::value_type;\n\n  private:\n    size_type m_n,\
    \ m_size;\n    std::vector<value_type> m_nodes;\n\n  public:\n    explicit SegmentTree(const\
    \ size_type n) : m_n(n), m_size(ceil_pow2(n)) {\n        m_nodes.assign(m_size\
    \ << 1, M::identity());\n    }\n\n    SegmentTree(const size_type n, const value_type\
    \ v) {\n        *this = SegmentTree(n, std::vector(n, v));\n    }\n\n    SegmentTree(const\
    \ size_type n, const std::vector<value_type> &s)\n        : m_n(n), m_size(ceil_pow2(n))\
    \ {\n        m_nodes.assign(m_size << 1, M::identity());\n        std::copy(s.begin(),\
    \ s.end(), m_nodes.begin() + m_size);\n        for (size_type i = m_size - 1;\
    \ i != 0; --i)\n            internal_update(i);\n    }\n\n    void set(size_type\
    \ i, const value_type &v) {\n        assert(i < m_n);\n        i += m_size;\n\
    \        m_nodes[i] = v;\n        for (i >>= 1; i != 0; i >>= 1)\n           \
    \ internal_update(i);\n    }\n\n    value_type all_product() const {\n       \
    \ return m_nodes[1];\n    }\n\n    value_type product(size_type l, size_type r)\
    \ const {\n        assert(l <= r);\n        assert(r <= m_n);\n        value_type\
    \ v_l = M::identity(), v_r = M::identity();\n        for (l += m_size, r += m_size;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (l & 1) v_l = M::operation(v_l, m_nodes[l++]);\n\
    \            if (r & 1) v_r = M::operation(m_nodes[--r], v_r);\n        }\n  \
    \      return M::operation(v_l, v_r);\n    }\n\n    value_type get(const size_type\
    \ i) const {\n        assert(i < m_n);\n        return m_nodes[m_size + i];\n\
    \    }\n\n    template <class F> size_type max_right(size_type l, const F &f)\
    \ const {\n        assert(l <= m_n);\n        assert(f(M::identity()));\n    \
    \    if (l == m_n) return m_n;\n\n        l += m_size;\n        value_type sum\
    \ = M::identity();\n        do {\n            while (not(l & 1))\n           \
    \     l >>= 1;\n            if (not f(M::operation(sum, m_nodes[l]))) {\n    \
    \            while (l < m_size) {\n                    l = l << 1;\n         \
    \           if (f(M::operation(sum, m_nodes[l]))) sum = M::operation(sum, m_nodes[l++]);\n\
    \                }\n                return l - m_size;\n            }\n      \
    \      sum = M::operation(sum, m_nodes[l++]);\n        } while ((l & (l - 1))\
    \ != 0);\n        return m_n;\n    }\n\n    template <class F> size_type min_left(size_type\
    \ r, const F &f) const {\n        assert(r <= m_n);\n        assert(f(M::identity()));\n\
    \        if (r == 0) return 0;\n\n        r += m_size;\n        value_type sum\
    \ = M::identity();\n        do {\n            --r;\n            while (r > 1 and\
    \ (r & 1))\n                r >>= 1;\n            if (not f(M::operation(m_nodes[r],\
    \ sum))) {\n                while (r < m_size) {\n                    r = (r <<\
    \ 1) | 1;\n                    if (f(M::operation(m_nodes[r], sum))) sum = M::operation(m_nodes[r--],\
    \ sum);\n                }\n                return r + 1 - m_size;\n         \
    \   }\n            sum = M::operation(m_nodes[r], sum);\n        } while ((r &\
    \ (r - 1)) != 0);\n        return 0;\n    }\n\n  private:\n    static constexpr\
    \ size_type ceil_pow2(const size_type n_) noexcept {\n        size_type res =\
    \ 1;\n        while (res < n_)\n            res <<= 1;\n        return res;\n\
    \    }\n\n    void internal_update(const size_type i) {\n        m_nodes[i] =\
    \ M::operation(m_nodes[i << 1], m_nodes[i << 1 | 1]);\n    }\n};"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: data-structure/segmenttree.cpp
  requiredBy:
  - verify/library-checker/point_add_range_sum_1.cpp
  timestamp: '2021-11-12 23:02:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/segmenttree.cpp
layout: document
redirect_from:
- /library/data-structure/segmenttree.cpp
- /library/data-structure/segmenttree.cpp.html
title: data-structure/segmenttree.cpp
---
