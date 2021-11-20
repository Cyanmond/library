---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segmenttree.cpp
    title: data-structure/segmenttree.cpp
  - icon: ':heavy_check_mark:'
    path: utility/eoln.cpp
    title: utility/eoln.cpp
  - icon: ':heavy_check_mark:'
    path: utility/int_alias.cpp
    title: utility/int_alias.cpp
  - icon: ':heavy_check_mark:'
    path: utility/rep.cpp
    title: utility/rep.cpp
  - icon: ':heavy_check_mark:'
    path: utility/scan.cpp
    title: utility/scan.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/library-checker/point_add_range_sum.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#line\
    \ 2 \"data-structure/segmenttree.cpp\"\n\n#line 2 \"utility/int_alias.cpp\"\n\n\
    #include <cstddef>\n#include <cstdint>\n\nusing i8 = std::int8_t;\nusing u8 =\
    \ std::uint8_t;\nusing i16 = std::int16_t;\nusing i32 = std::int32_t;\nusing i64\
    \ = std::int64_t;\nusing u16 = std::uint16_t;\nusing u32 = std::uint32_t;\nusing\
    \ u64 = std::uint64_t;\n\nusing usize = std::size_t;\nusing isize = std::ptrdiff_t;\n\
    #line 4 \"data-structure/segmenttree.cpp\"\n#include <algorithm>\n#include <cassert>\n\
    #line 7 \"data-structure/segmenttree.cpp\"\n#include <vector>\n\ntemplate <class\
    \ M> class SegmentTree {\n  public:\n    using size_type = usize;\n    using value_type\
    \ = typename M::value_type;\n\n  private:\n    size_type m_n, m_size;\n    std::vector<value_type>\
    \ m_nodes;\n\n  public:\n    explicit SegmentTree(const size_type n) : m_n(n),\
    \ m_size(ceil_pow2(n)) {\n        m_nodes.assign(m_size << 1, M::identity());\n\
    \    }\n\n    SegmentTree(const usize n, const value_type v) {\n        *this\
    \ = SegmentTree(std::vector(n, v));\n    }\n\n    SegmentTree(const std::vector<value_type>\
    \ &s) : m_n(s.size()), m_size(ceil_pow2(s.size())) {\n        m_nodes.assign(m_size\
    \ << 1, M::identity());\n        std::copy(s.begin(), s.end(), m_nodes.begin()\
    \ + m_size);\n        for (size_type i = m_size - 1; i != 0; --i)\n          \
    \  internal_update(i);\n    }\n\n    void set(size_type i, const value_type &v)\
    \ {\n        assert(i < m_n);\n        i += m_size;\n        m_nodes[i] = v;\n\
    \        for (i >>= 1; i != 0; i >>= 1)\n            internal_update(i);\n   \
    \ }\n\n    value_type all_product() const {\n        return m_nodes[1];\n    }\n\
    \n    value_type product(size_type l, size_type r) const {\n        assert(l <=\
    \ r);\n        assert(r <= m_n);\n        value_type v_l = M::identity(), v_r\
    \ = M::identity();\n        for (l += m_size, r += m_size; l < r; l >>= 1, r >>=\
    \ 1) {\n            if (l & 1) v_l = M::operation(v_l, m_nodes[l++]);\n      \
    \      if (r & 1) v_r = M::operation(m_nodes[--r], v_r);\n        }\n        return\
    \ M::operation(v_l, v_r);\n    }\n\n    value_type get(const size_type i) const\
    \ {\n        assert(i < m_n);\n        return m_nodes[m_size + i];\n    }\n\n\
    \    template <class F> size_type max_right(size_type l, const F &f) const {\n\
    \        assert(l <= m_n);\n        assert(f(M::identity()));\n        if (l ==\
    \ m_n) return m_n;\n\n        l += m_size;\n        value_type sum = M::identity();\n\
    \        do {\n            while (not(l & 1))\n                l >>= 1;\n    \
    \        if (not f(M::operation(sum, m_nodes[l]))) {\n                while (l\
    \ < m_size) {\n                    l = l << 1;\n                    if (f(M::operation(sum,\
    \ m_nodes[l]))) sum = M::operation(sum, m_nodes[l++]);\n                }\n  \
    \              return l - m_size;\n            }\n            sum = M::operation(sum,\
    \ m_nodes[l++]);\n        } while ((l & (l - 1)) != 0);\n        return m_n;\n\
    \    }\n\n    template <class F> size_type min_left(size_type r, const F &f) const\
    \ {\n        assert(r <= m_n);\n        assert(f(M::identity()));\n        if\
    \ (r == 0) return 0;\n\n        r += m_size;\n        value_type sum = M::identity();\n\
    \        do {\n            --r;\n            while (r > 1 and (r & 1))\n     \
    \           r >>= 1;\n            if (not f(M::operation(m_nodes[r], sum))) {\n\
    \                while (r < m_size) {\n                    r = (r << 1) | 1;\n\
    \                    if (f(M::operation(m_nodes[r], sum))) sum = M::operation(m_nodes[r--],\
    \ sum);\n                }\n                return r + 1 - m_size;\n         \
    \   }\n            sum = M::operation(m_nodes[r], sum);\n        } while ((r &\
    \ (r - 1)) != 0);\n        return 0;\n    }\n\n  private:\n    static constexpr\
    \ size_type ceil_pow2(const size_type n_) noexcept {\n        size_type res =\
    \ 1;\n        while (res < n_)\n            res <<= 1;\n        return res;\n\
    \    }\n\n    void internal_update(const size_type i) {\n        m_nodes[i] =\
    \ M::operation(m_nodes[i << 1], m_nodes[i << 1 | 1]);\n    }\n};\n#line 2 \"utility/eoln.cpp\"\
    \n\nconstexpr char eoln = '\\n';\n#line 2 \"utility/rep.cpp\"\n\n#line 5 \"utility/rep.cpp\"\
    \n\nclass rep {\n    struct rep_iterator {\n        usize itr;\n        constexpr\
    \ rep_iterator(const usize pos) noexcept : itr(pos) {}\n        constexpr void\
    \ operator++() noexcept {\n            ++itr;\n        }\n        constexpr bool\
    \ operator!=(const usize &other) const noexcept {\n            return itr != other;\n\
    \        }\n        constexpr usize operator*() const noexcept {\n           \
    \ return itr;\n        }\n    };\n    const rep_iterator first;\n    const usize\
    \ last;\n\n  public:\n    constexpr rep(const usize first_, const usize last_)\
    \ noexcept\n        : first(first_), last(std::max(first_, last_)) {}\n    constexpr\
    \ rep_iterator begin() const noexcept {\n        return first;\n    }\n    constexpr\
    \ usize end() const noexcept {\n        return last;\n    }\n};\n#line 2 \"utility/scan.cpp\"\
    \n\n#include <iostream>\n\ntemplate <typename T> inline T scan() {\n    T x;\n\
    \    std::cin >> x;\n    return x;\n}\n#line 8 \"verify/library-checker/point_add_range_sum.test.cpp\"\
    \n\nstruct monoid {\n    using value_type = i64;\n    static value_type operation(const\
    \ value_type a, const value_type b) {\n        return a + b;\n    }\n    static\
    \ value_type identity() {\n        return 0;\n    }\n};\n\nint main(void) {\n\
    \    const usize N = scan<usize>();\n    const usize Q = scan<usize>();\n    std::vector<i64>\
    \ A(N);\n    for (auto &e : A)\n        e = scan<i64>();\n\n    SegmentTree<monoid>\
    \ s(A);\n    for ([[maybe_unused]] const auto i : rep(0, Q)) {\n        const\
    \ int t = scan<int>();\n        if (t == 0) {\n            const usize p = scan<usize>();\n\
    \            const i64 x = scan<i64>();\n            s.set(p, monoid::operation(s.get(p),\
    \ x));\n        } else {\n            const usize l = scan<usize>();\n       \
    \     const usize r = scan<usize>();\n            std::cout << s.product(l, r)\
    \ << eoln;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../data-structure/segmenttree.cpp\"\n#include \"../../utility/eoln.cpp\"\
    \n#include \"../../utility/int_alias.cpp\"\n#include \"../../utility/rep.cpp\"\
    \n#include \"../../utility/scan.cpp\"\n\nstruct monoid {\n    using value_type\
    \ = i64;\n    static value_type operation(const value_type a, const value_type\
    \ b) {\n        return a + b;\n    }\n    static value_type identity() {\n   \
    \     return 0;\n    }\n};\n\nint main(void) {\n    const usize N = scan<usize>();\n\
    \    const usize Q = scan<usize>();\n    std::vector<i64> A(N);\n    for (auto\
    \ &e : A)\n        e = scan<i64>();\n\n    SegmentTree<monoid> s(A);\n    for\
    \ ([[maybe_unused]] const auto i : rep(0, Q)) {\n        const int t = scan<int>();\n\
    \        if (t == 0) {\n            const usize p = scan<usize>();\n         \
    \   const i64 x = scan<i64>();\n            s.set(p, monoid::operation(s.get(p),\
    \ x));\n        } else {\n            const usize l = scan<usize>();\n       \
    \     const usize r = scan<usize>();\n            std::cout << s.product(l, r)\
    \ << eoln;\n        }\n    }\n}"
  dependsOn:
  - data-structure/segmenttree.cpp
  - utility/int_alias.cpp
  - utility/eoln.cpp
  - utility/rep.cpp
  - utility/scan.cpp
  isVerificationFile: true
  path: verify/library-checker/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-11-21 02:00:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library-checker/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library-checker/point_add_range_sum.test.cpp
- /verify/verify/library-checker/point_add_range_sum.test.cpp.html
title: verify/library-checker/point_add_range_sum.test.cpp
---
