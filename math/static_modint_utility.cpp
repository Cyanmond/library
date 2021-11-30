#pragma once

#include "../utility/int_alias.cpp"
#include <cassert>
#include <vector>

template <class M> class StaticModintUtility {
    static inline usize size = 1;
    static inline std::vector<M> fact = {1, 1};
    static inline std::vector<M> inv = {0, 1};
    static inline std::vector<M> inv_fact = {1, 1};

    static void reserve(const usize size_) {
        if (size < size_) {
            for (usize i = size + 1; i <= size_; ++i) {
                fact[i] = fact[i - 1] * M(i);
                inv[i] = -M(M::mod() / i) * inv[i - 1];
                inv_fact[i] = inv_fact[i - 1] * inv[i];
            }
            size = size_;
        }
    }

  public:
    static M get_fact(const usize i) {
        reserve(i + 1);
        return fact[i];
    }

    static M get_inv(const usize i) {
        assert(i != 0);
        reserve(i + 1);
        return inv[i];
    }

    static M get_inv_fact(const usize i) {
        reserve(i + 1);
        return inv_fact[i];
    }

    static M comb(const usize n, const usize k) {
        assert(k <= n);
        reserve(n + 1);
        return fact[n] * inv_fact[n - k] * inv_fact[k];
    }

    static M perm(const usize n, const usize k) {
        assert(k <= n);
        reserve(n + 1);
        return fact[n] * inv_fact[n - k];
    }

    static M homo(const usize n, const usize k) {
        if (n == 0 and k == 0) return 1;
        reserve(n + k);
        return comb(n + k - 1, k);
    }
};
