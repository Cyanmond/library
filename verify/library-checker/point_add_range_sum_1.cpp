#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../data-structure/segmenttree.cpp"
#include "../../math/static_modint.cpp"
#include "../../utility/eoln.cpp"
#include "../../utility/int_alias.cpp"
#include "../../utility/rep.cpp"
#include "../../utility/scan.cpp"

using Modint = Modint998244353;

struct monoid {
    using value_type = Modint;
    static value_type operation(const Modint a, const Modint b) {
        return a + b;
    }
    static value_type identity() {
        return Modint(0);
    }
};

int main(void) {
    const usize N = scan<usize>();
    const usize Q = scan<usize>();
    std::vector<i32> A(N);
    std::vector<Modint> inits(N);
    for (const auto i : rep(0, N)) {
        A[i] = scan<i32>();
        inits[i] = Modint::raw(A[i]);
    }
    
    SegmentTree<monoid> s(inits);
    for ([[maybe_unused]] const auto i : rep(0, Q)) {
        const int t = scan<int>();
        if (t == 0) {
            const usize p = scan<usize>();
            const i32 x = scan<i32>();
            s.set(p, monoid::operation(s.get(p), x));
        } else {
            const usize l = scan<usize>();
            const usize r = scan<usize>();
            std::cout << s.product(l, r).val() << eoln;
        }
    }
}