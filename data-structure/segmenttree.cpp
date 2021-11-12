#pragma once

#include "../../library/utility/int_alias.cpp"
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <vector>

template <class M> class SegmentTree {
  public:
    using size_type = usize;
    using value_type = typename M::value_type;

  private:
    size_type m_n, m_size;
    std::vector<value_type> m_nodes;

  public:
    explicit SegmentTree(const size_type n) : m_n(n), m_size(ceil_pow2(n)) {
        m_nodes.assign(m_size << 1, M::identity());
    }

    SegmentTree(const size_type n, const value_type v) {
        *this = SegmentTree(n, std::vector(n, v));
    }

    SegmentTree(const size_type n, const std::vector<value_type> &s)
        : m_n(n), m_size(ceil_pow2(n)) {
        m_nodes.assign(m_size << 1, M::identity());
        std::copy(s.begin(), s.end(), m_nodes.begin() + m_size);
        for (size_type i = m_size - 1; i != 0; --i)
            internal_update(i);
    }

    void set(size_type i, const value_type &v) {
        assert(i < m_n);
        i += m_size;
        m_nodes[i] = v;
        for (i >>= 1; i != 0; i >>= 1)
            internal_update(i);
    }

    value_type all_product() const {
        return m_nodes[1];
    }

    value_type product(size_type l, size_type r) const {
        assert(l <= r);
        assert(r <= m_n);
        value_type v_l = M::identity(), v_r = M::identity();
        for (l += m_size, r += m_size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) v_l = M::operation(v_l, m_nodes[l++]);
            if (r & 1) v_r = M::operation(m_nodes[--r], v_r);
        }
        return M::operation(v_l, v_r);
    }

    value_type get(const size_type i) const {
        assert(i < m_n);
        return m_nodes[m_size + i];
    }

    template <class F> size_type max_right(size_type l, const F &f) const {
        assert(l <= m_n);
        assert(f(M::identity()));
        if (l == m_n) return m_n;

        l += m_size;
        value_type sum = M::identity();
        do {
            while (not(l & 1))
                l >>= 1;
            if (not f(M::operation(sum, m_nodes[l]))) {
                while (l < m_size) {
                    l = l << 1;
                    if (f(M::operation(sum, m_nodes[l]))) sum = M::operation(sum, m_nodes[l++]);
                }
                return l - m_size;
            }
            sum = M::operation(sum, m_nodes[l++]);
        } while ((l & (l - 1)) != 0);
        return m_n;
    }

    template <class F> size_type min_left(size_type r, const F &f) const {
        assert(r <= m_n);
        assert(f(M::identity()));
        if (r == 0) return 0;

        r += m_size;
        value_type sum = M::identity();
        do {
            --r;
            while (r > 1 and (r & 1))
                r >>= 1;
            if (not f(M::operation(m_nodes[r], sum))) {
                while (r < m_size) {
                    r = (r << 1) | 1;
                    if (f(M::operation(m_nodes[r], sum))) sum = M::operation(m_nodes[r--], sum);
                }
                return r + 1 - m_size;
            }
            sum = M::operation(m_nodes[r], sum);
        } while ((r & (r - 1)) != 0);
        return 0;
    }

  private:
    static constexpr size_type ceil_pow2(const size_type n_) noexcept {
        size_type res = 1;
        while (res < n_)
            res <<= 1;
        return res;
    }

    void internal_update(const size_type i) {
        m_nodes[i] = M::operation(m_nodes[i << 1], m_nodes[i << 1 | 1]);
    }
};