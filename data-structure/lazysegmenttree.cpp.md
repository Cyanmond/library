---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/lazysegmenttree_utility.cpp
    title: data-structure/lazysegmenttree_utility.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/lazysegmenttree.cpp\"\n\n#line 2 \"utility/int_alias.cpp\"\
    \n\n#include <cstddef>\n#include <cstdint>\n\nusing i8 = std::int8_t;\nusing u8\
    \ = std::uint8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing\
    \ i64 = std::int64_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\n\
    using u64 = std::uint64_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    #line 4 \"data-structure/lazysegmenttree.cpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#line 7 \"data-structure/lazysegmenttree.cpp\"\n#include <vector>\n\
    \ntemplate <class A> class LazySegmentTree {\n  public:\n    using size_type =\
    \ usize;\n    using M = typename A::Monoid;\n    using E = typename A::Effector;\n\
    \    using T = typename M::value_type;\n    using U = typename E::value_type;\n\
    \n    struct node_type {\n        T value;\n        U lazy;\n\n        node_type()\
    \ : value(M::identity()), lazy(E::identity()) {}\n        node_type(const T v,\
    \ const U l) : value(v), lazy(l) {}\n    };\n\n  private:\n    size_type m_n,\
    \ m_log, m_size;\n    std::vector<node_type> m_nodes;\n\n  public:\n    explicit\
    \ LazySegmentTree(const size_type n) : m_n(n), m_log(ceil_log2(n)) {\n       \
    \ m_size = static_cast<size_type>(1) << m_log;\n        m_nodes.assign(m_size\
    \ << 1, node_type());\n    }\n\n    LazySegmentTree(const size_type n, const T\
    \ &v) {\n        *this = LazySegmentTree(n, std::vector(n, v));\n    }\n\n   \
    \ LazySegmentTree(const size_type n, const std::vector<T> &s) : m_n(n), m_log(ceil_log2(n))\
    \ {\n        assert(s.size() <= m_n);\n        m_size = static_cast<size_type>(1)\
    \ << m_log;\n        m_nodes.assign(m_size << 1, node_type(M::identity(), E::identity()));\n\
    \n        std::vector<node_type> rs(s.size());\n        for (size_type i = 0;\
    \ i < s.size(); ++i)\n            rs[i].value = s[i];\n        std::copy(rs.begin(),\
    \ rs.end(), m_nodes.begin() + m_size);\n\n        for (size_type i = m_size -\
    \ 1; i != 0; --i)\n            internal_update(i);\n    }\n\n    void set(size_type\
    \ k, const T &v) {\n        assert(0 <= k && k < m_n);\n        k += m_size;\n\
    \        for (size_type i = m_log; i != 0; --i)\n            internal_propagate(k\
    \ >> i);\n        m_nodes[k].value = v;\n        for (size_type i = 1; i <= m_log;\
    \ ++i)\n            internal_update(k >> i);\n    }\n\n    void apply(size_type\
    \ k, const U &f) {\n        assert(k < m_n);\n        k += m_size;\n        for\
    \ (size_type i = m_log; i != 0; --i)\n            internal_propagate(k >> i);\n\
    \        m_nodes[k].value = A::operation(f, m_nodes[k].value);\n        for (size_type\
    \ i = 1; i <= m_log; ++i)\n            internal_update(k >> i);\n    }\n\n   \
    \ void apply(size_type l, size_type r, const U &f) {\n        assert(l <= r);\n\
    \        assert(r <= m_n);\n        if (l == r) return;\n        l += m_size;\n\
    \        r += m_size;\n\n        for (size_type i = m_log; i != 0; --i) {\n  \
    \          if (((l >> i) << i) != l) internal_propagate(l >> i);\n           \
    \ if (((r >> i) << i) != r) internal_propagate((r - 1) >> i);\n        }\n\n \
    \       for (size_type l2 = l, r2 = r; l2 < r2; l2 >>= 1, r2 >>= 1) {\n      \
    \      if (l2 & 1) internal_apply(l2++, f);\n            if (r2 & 1) internal_apply(--r2,\
    \ f);\n        }\n\n        for (size_type i = 1; i <= m_log; ++i) {\n       \
    \     if (((l >> i) << i) != l) internal_update(l >> i);\n            if (((r\
    \ >> i) << i) != r) internal_update((r - 1) >> i);\n        }\n    }\n\n    T\
    \ product(size_type l, size_type r) {\n        assert(l <= r);\n        assert(r\
    \ <= m_n);\n        if (l == r) return M::identity();\n\n        l += m_size;\n\
    \        r += m_size;\n\n        for (size_type i = m_log; i != 0; --i) {\n  \
    \          if (((l >> i) << i) != l) internal_propagate(l >> i);\n           \
    \ if (((r >> i) << i) != r) internal_propagate((r - 1) >> i);\n        }\n\n \
    \       T v_l = M::identity(), v_r = M::identity();\n        while (l < r) {\n\
    \            if (l & 1) v_l = M::operation(v_l, m_nodes[l++].value);\n       \
    \     if (r & 1) v_r = M::operation(m_nodes[--r].value, v_r);\n            l >>=\
    \ 1;\n            r >>= 1;\n        }\n\n        return M::operation(v_l, v_r);\n\
    \    }\n\n    T all_product() const {\n        return m_nodes[1].value;\n    }\n\
    \n    T get(size_type k) {\n        assert(k < m_n);\n        k += m_size;\n \
    \       for (size_type i = m_log; i != 0; --i)\n            internal_propagate(k\
    \ >> i);\n        return m_nodes[k].value;\n    }\n\n    template <class F> size_type\
    \ max_right(size_type l, const F &f) {\n        assert(l <= m_n);\n        assert(f(M::identity()));\n\
    \        if (l == m_n) return m_n;\n        l += m_size;\n        for (size_type\
    \ i = m_log; i != 0; --i)\n            internal_propagate(l >> i);\n        T\
    \ sum = M::identity();\n\n        do {\n            while (not(l & 1))\n     \
    \           l >>= 1;\n            if (!f(M::operation(sum, m_nodes[l].value)))\
    \ {\n                while (l < m_size) {\n                    internal_propagate(l);\n\
    \                    l <<= 1;\n                    if (f(M::operation(sum, m_nodes[l].value)))\n\
    \                        sum = M::operation(sum, m_nodes[l++].value);\n      \
    \          }\n                return l - m_size;\n            }\n            sum\
    \ = M::operation(sum, m_nodes[l++].value);\n        } while ((l & (l - 1)) !=\
    \ 0);\n        return m_n;\n    }\n\n    template <class F> size_type min_left(size_type\
    \ r, const F &f) {\n        assert(r <= m_n);\n        assert(f(M::identity()));\n\
    \        if (r == 0) return 0;\n        r += m_size;\n        for (size_type i\
    \ = m_log; i != 0; --i)\n            internal_propagate((r - 1) >> i);\n     \
    \   T sum = M::identity();\n\n        do {\n            --r;\n            while\
    \ (r != 1 && (r & 2))\n                r >>= 1;\n            if (!f(M::operation(m_nodes[r].value,\
    \ sum))) {\n                while (r < m_size) {\n                    internal_propagate(r);\n\
    \                    r = r << 1 | 1;\n                    if (f(M::operation(m_nodes[r].value,\
    \ sum)))\n                        sum = M::operation(m_nodes[r--].value, sum);\n\
    \                }\n                return r + 1 - m_size;\n            }\n  \
    \          sum = M::operation(m_nodes[r].value, sum);\n        } while ((r & (r\
    \ - 1)) != 0);\n        return 0;\n    }\n\n  private:\n    static constexpr size_type\
    \ ceil_log2(const size_type n) {\n        size_type res = 0;\n        while ((static_cast<size_type>(1)\
    \ << res) < n)\n            ++res;\n        return res;\n    }\n\n    void internal_update(const\
    \ size_type i) {\n        m_nodes[i].value = M::operation(m_nodes[i << 1].value,\
    \ m_nodes[i << 1 | 1].value);\n    }\n\n    void internal_apply(const size_type\
    \ k, const U f) {\n        m_nodes[k].value = A::operation(f, m_nodes[k].value);\n\
    \        if (k < m_size) m_nodes[k].lazy = E::operation(f, m_nodes[k].lazy);\n\
    \    }\n\n    void internal_propagate(const size_type k) {\n        internal_apply(k\
    \ << 1, m_nodes[k].lazy);\n        internal_apply(k << 1 | 1, m_nodes[k].lazy);\n\
    \        m_nodes[k].lazy = E::identity();\n    }\n};\n"
  code: "#pragma once\n\n#include \"../../library/utility/int_alias.cpp\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <cstddef>\n#include <vector>\n\ntemplate\
    \ <class A> class LazySegmentTree {\n  public:\n    using size_type = usize;\n\
    \    using M = typename A::Monoid;\n    using E = typename A::Effector;\n    using\
    \ T = typename M::value_type;\n    using U = typename E::value_type;\n\n    struct\
    \ node_type {\n        T value;\n        U lazy;\n\n        node_type() : value(M::identity()),\
    \ lazy(E::identity()) {}\n        node_type(const T v, const U l) : value(v),\
    \ lazy(l) {}\n    };\n\n  private:\n    size_type m_n, m_log, m_size;\n    std::vector<node_type>\
    \ m_nodes;\n\n  public:\n    explicit LazySegmentTree(const size_type n) : m_n(n),\
    \ m_log(ceil_log2(n)) {\n        m_size = static_cast<size_type>(1) << m_log;\n\
    \        m_nodes.assign(m_size << 1, node_type());\n    }\n\n    LazySegmentTree(const\
    \ size_type n, const T &v) {\n        *this = LazySegmentTree(n, std::vector(n,\
    \ v));\n    }\n\n    LazySegmentTree(const size_type n, const std::vector<T> &s)\
    \ : m_n(n), m_log(ceil_log2(n)) {\n        assert(s.size() <= m_n);\n        m_size\
    \ = static_cast<size_type>(1) << m_log;\n        m_nodes.assign(m_size << 1, node_type(M::identity(),\
    \ E::identity()));\n\n        std::vector<node_type> rs(s.size());\n        for\
    \ (size_type i = 0; i < s.size(); ++i)\n            rs[i].value = s[i];\n    \
    \    std::copy(rs.begin(), rs.end(), m_nodes.begin() + m_size);\n\n        for\
    \ (size_type i = m_size - 1; i != 0; --i)\n            internal_update(i);\n \
    \   }\n\n    void set(size_type k, const T &v) {\n        assert(0 <= k && k <\
    \ m_n);\n        k += m_size;\n        for (size_type i = m_log; i != 0; --i)\n\
    \            internal_propagate(k >> i);\n        m_nodes[k].value = v;\n    \
    \    for (size_type i = 1; i <= m_log; ++i)\n            internal_update(k >>\
    \ i);\n    }\n\n    void apply(size_type k, const U &f) {\n        assert(k <\
    \ m_n);\n        k += m_size;\n        for (size_type i = m_log; i != 0; --i)\n\
    \            internal_propagate(k >> i);\n        m_nodes[k].value = A::operation(f,\
    \ m_nodes[k].value);\n        for (size_type i = 1; i <= m_log; ++i)\n       \
    \     internal_update(k >> i);\n    }\n\n    void apply(size_type l, size_type\
    \ r, const U &f) {\n        assert(l <= r);\n        assert(r <= m_n);\n     \
    \   if (l == r) return;\n        l += m_size;\n        r += m_size;\n\n      \
    \  for (size_type i = m_log; i != 0; --i) {\n            if (((l >> i) << i) !=\
    \ l) internal_propagate(l >> i);\n            if (((r >> i) << i) != r) internal_propagate((r\
    \ - 1) >> i);\n        }\n\n        for (size_type l2 = l, r2 = r; l2 < r2; l2\
    \ >>= 1, r2 >>= 1) {\n            if (l2 & 1) internal_apply(l2++, f);\n     \
    \       if (r2 & 1) internal_apply(--r2, f);\n        }\n\n        for (size_type\
    \ i = 1; i <= m_log; ++i) {\n            if (((l >> i) << i) != l) internal_update(l\
    \ >> i);\n            if (((r >> i) << i) != r) internal_update((r - 1) >> i);\n\
    \        }\n    }\n\n    T product(size_type l, size_type r) {\n        assert(l\
    \ <= r);\n        assert(r <= m_n);\n        if (l == r) return M::identity();\n\
    \n        l += m_size;\n        r += m_size;\n\n        for (size_type i = m_log;\
    \ i != 0; --i) {\n            if (((l >> i) << i) != l) internal_propagate(l >>\
    \ i);\n            if (((r >> i) << i) != r) internal_propagate((r - 1) >> i);\n\
    \        }\n\n        T v_l = M::identity(), v_r = M::identity();\n        while\
    \ (l < r) {\n            if (l & 1) v_l = M::operation(v_l, m_nodes[l++].value);\n\
    \            if (r & 1) v_r = M::operation(m_nodes[--r].value, v_r);\n       \
    \     l >>= 1;\n            r >>= 1;\n        }\n\n        return M::operation(v_l,\
    \ v_r);\n    }\n\n    T all_product() const {\n        return m_nodes[1].value;\n\
    \    }\n\n    T get(size_type k) {\n        assert(k < m_n);\n        k += m_size;\n\
    \        for (size_type i = m_log; i != 0; --i)\n            internal_propagate(k\
    \ >> i);\n        return m_nodes[k].value;\n    }\n\n    template <class F> size_type\
    \ max_right(size_type l, const F &f) {\n        assert(l <= m_n);\n        assert(f(M::identity()));\n\
    \        if (l == m_n) return m_n;\n        l += m_size;\n        for (size_type\
    \ i = m_log; i != 0; --i)\n            internal_propagate(l >> i);\n        T\
    \ sum = M::identity();\n\n        do {\n            while (not(l & 1))\n     \
    \           l >>= 1;\n            if (!f(M::operation(sum, m_nodes[l].value)))\
    \ {\n                while (l < m_size) {\n                    internal_propagate(l);\n\
    \                    l <<= 1;\n                    if (f(M::operation(sum, m_nodes[l].value)))\n\
    \                        sum = M::operation(sum, m_nodes[l++].value);\n      \
    \          }\n                return l - m_size;\n            }\n            sum\
    \ = M::operation(sum, m_nodes[l++].value);\n        } while ((l & (l - 1)) !=\
    \ 0);\n        return m_n;\n    }\n\n    template <class F> size_type min_left(size_type\
    \ r, const F &f) {\n        assert(r <= m_n);\n        assert(f(M::identity()));\n\
    \        if (r == 0) return 0;\n        r += m_size;\n        for (size_type i\
    \ = m_log; i != 0; --i)\n            internal_propagate((r - 1) >> i);\n     \
    \   T sum = M::identity();\n\n        do {\n            --r;\n            while\
    \ (r != 1 && (r & 2))\n                r >>= 1;\n            if (!f(M::operation(m_nodes[r].value,\
    \ sum))) {\n                while (r < m_size) {\n                    internal_propagate(r);\n\
    \                    r = r << 1 | 1;\n                    if (f(M::operation(m_nodes[r].value,\
    \ sum)))\n                        sum = M::operation(m_nodes[r--].value, sum);\n\
    \                }\n                return r + 1 - m_size;\n            }\n  \
    \          sum = M::operation(m_nodes[r].value, sum);\n        } while ((r & (r\
    \ - 1)) != 0);\n        return 0;\n    }\n\n  private:\n    static constexpr size_type\
    \ ceil_log2(const size_type n) {\n        size_type res = 0;\n        while ((static_cast<size_type>(1)\
    \ << res) < n)\n            ++res;\n        return res;\n    }\n\n    void internal_update(const\
    \ size_type i) {\n        m_nodes[i].value = M::operation(m_nodes[i << 1].value,\
    \ m_nodes[i << 1 | 1].value);\n    }\n\n    void internal_apply(const size_type\
    \ k, const U f) {\n        m_nodes[k].value = A::operation(f, m_nodes[k].value);\n\
    \        if (k < m_size) m_nodes[k].lazy = E::operation(f, m_nodes[k].lazy);\n\
    \    }\n\n    void internal_propagate(const size_type k) {\n        internal_apply(k\
    \ << 1, m_nodes[k].lazy);\n        internal_apply(k << 1 | 1, m_nodes[k].lazy);\n\
    \        m_nodes[k].lazy = E::identity();\n    }\n};"
  dependsOn:
  - utility/int_alias.cpp
  isVerificationFile: false
  path: data-structure/lazysegmenttree.cpp
  requiredBy:
  - data-structure/lazysegmenttree_utility.cpp
  timestamp: '2021-12-08 20:23:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/lazysegmenttree.cpp
layout: document
redirect_from:
- /library/data-structure/lazysegmenttree.cpp
- /library/data-structure/lazysegmenttree.cpp.html
title: data-structure/lazysegmenttree.cpp
---
