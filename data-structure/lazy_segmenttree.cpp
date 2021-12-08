#pragma once

#include "../../library/utility/int_alias.cpp"
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <vector>

template <class A> class LazySegmentTree {
  public:
    using size_type = usize;
    using M = typename A::Monoid;
    using E = typename A::Effector;
    using T = typename M::value_type;
    using U = typename E::value_type;

    struct node_type {
        T value;
        U lazy;

        node_type() : value(M::identity()), lazy(E::identity()) {}
        node_type(const T v, const U l) : value(v), lazy(l) {}
    };

  private:
    size_type m_n, m_log, m_size;
    std::vector<node_type> m_nodes;

  public:
    explicit LazySegmentTree(const size_type n) : m_n(n), m_log(ceil_log2(n)) {
        m_size = static_cast<size_type>(1) << m_log;
        m_nodes.assign(m_size << 1, node_type());
    }

    LazySegmentTree(const size_type n, const T &v) {
        *this = LazySegmentTree(n, std::vector(n, v));
    }

    LazySegmentTree(const size_type n, const std::vector<T> &s) : m_n(n), m_log(ceil_log2(n)) {
        assert(s.size() <= m_n);
        m_size = static_cast<size_type>(1) << m_log;
        m_nodes.assign(m_size << 1, node_type(M::identity(), E::identity()));

        std::vector<node_type> rs(s.size());
        for (size_type i = 0; i < s.size(); ++i)
            rs[i].value = s[i];
        std::copy(rs.begin(), rs.end(), m_nodes.begin() + m_size);

        for (size_type i = m_size - 1; i != 0; --i)
            internal_update(i);
    }

    void set(size_type k, const T &v) {
        assert(0 <= k && k < m_n);
        k += m_size;
        for (size_type i = m_log; i != 0; --i)
            internal_propagate(k >> i);
        m_nodes[k].value = v;
        for (size_type i = 1; i <= m_log; ++i)
            internal_update(k >> i);
    }

    void apply(size_type k, const U &f) {
        assert(k < m_n);
        k += m_size;
        for (size_type i = m_log; i != 0; --i)
            internal_propagate(k >> i);
        m_nodes[k].value = A::operation(f, m_nodes[k].value);
        for (size_type i = 1; i <= m_log; ++i)
            internal_update(k >> i);
    }

    void apply(size_type l, size_type r, const U &f) {
        assert(l <= r);
        assert(r <= m_n);
        if (l == r) return;
        l += m_size;
        r += m_size;

        for (size_type i = m_log; i != 0; --i) {
            if (((l >> i) << i) != l) internal_propagate(l >> i);
            if (((r >> i) << i) != r) internal_propagate((r - 1) >> i);
        }

        for (size_type l2 = l, r2 = r; l2 < r2; l2 >>= 1, r2 >>= 1) {
            if (l2 & 1) internal_apply(l2++, f);
            if (r2 & 1) internal_apply(--r2, f);
        }

        for (size_type i = 1; i <= m_log; ++i) {
            if (((l >> i) << i) != l) internal_update(l >> i);
            if (((r >> i) << i) != r) internal_update((r - 1) >> i);
        }
    }

    T product(size_type l, size_type r) {
        assert(l <= r);
        assert(r <= m_n);
        if (l == r) return M::identity();

        l += m_size;
        r += m_size;

        for (size_type i = m_log; i != 0; --i) {
            if (((l >> i) << i) != l) internal_propagate(l >> i);
            if (((r >> i) << i) != r) internal_propagate((r - 1) >> i);
        }

        T v_l = M::identity(), v_r = M::identity();
        while (l < r) {
            if (l & 1) v_l = M::operation(v_l, m_nodes[l++].value);
            if (r & 1) v_r = M::operation(m_nodes[--r].value, v_r);
            l >>= 1;
            r >>= 1;
        }

        return M::operation(v_l, v_r);
    }

    T all_product() const {
        return m_nodes[1].value;
    }

    T get(size_type k) {
        assert(k < m_n);
        k += m_size;
        for (size_type i = m_log; i != 0; --i)
            internal_propagate(k >> i);
        return m_nodes[k].value;
    }

    template <class F> size_type max_right(size_type l, const F &f) {
        assert(l <= m_n);
        assert(f(M::identity()));
        if (l == m_n) return m_n;
        l += m_size;
        for (size_type i = m_log; i != 0; --i)
            internal_propagate(l >> i);
        T sum = M::identity();

        do {
            while (not(l & 1))
                l >>= 1;
            if (!f(M::operation(sum, m_nodes[l].value))) {
                while (l < m_size) {
                    internal_propagate(l);
                    l <<= 1;
                    if (f(M::operation(sum, m_nodes[l].value)))
                        sum = M::operation(sum, m_nodes[l++].value);
                }
                return l - m_size;
            }
            sum = M::operation(sum, m_nodes[l++].value);
        } while ((l & (l - 1)) != 0);
        return m_n;
    }

    template <class F> size_type min_left(size_type r, const F &f) {
        assert(r <= m_n);
        assert(f(M::identity()));
        if (r == 0) return 0;
        r += m_size;
        for (size_type i = m_log; i != 0; --i)
            internal_propagate((r - 1) >> i);
        T sum = M::identity();

        do {
            --r;
            while (r != 1 && (r & 2))
                r >>= 1;
            if (!f(M::operation(m_nodes[r].value, sum))) {
                while (r < m_size) {
                    internal_propagate(r);
                    r = r << 1 | 1;
                    if (f(M::operation(m_nodes[r].value, sum)))
                        sum = M::operation(m_nodes[r--].value, sum);
                }
                return r + 1 - m_size;
            }
            sum = M::operation(m_nodes[r].value, sum);
        } while ((r & (r - 1)) != 0);
        return 0;
    }

  private:
    static constexpr size_type ceil_log2(const size_type n) {
        size_type res = 0;
        while ((static_cast<size_type>(1) << res) < n)
            ++res;
        return res;
    }

    void internal_update(const size_type i) {
        m_nodes[i].value = M::operation(m_nodes[i << 1].value, m_nodes[i << 1 | 1].value);
    }

    void internal_apply(const size_type k, const U f) {
        m_nodes[k].value = A::operation(f, m_nodes[k].value);
        if (k < m_size) m_nodes[k].lazy = E::operation(f, m_nodes[k].lazy);
    }

    void internal_propagate(const size_type k) {
        internal_apply(k << 1, m_nodes[k].lazy);
        internal_apply(k << 1 | 1, m_nodes[k].lazy);
        m_nodes[k].lazy = E::identity();
    }
};
