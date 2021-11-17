#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../data-structure/segmenttree.cpp"
#include "../../utility/eoln.cpp"
#include "../../utility/int_alias.cpp"
#include "../../utility/rep.cpp"
#include "../../utility/scan.cpp"

struct monoid {
    using value_type = i64;
    static value_type operation(const value_type a, const value_type b) {
        return a + b;
    }
    static value_type identity() {
        return 0;
    }
};

int main(void) {
    const usize N = scan<usize>();
    const usize Q = scan<usize>();
    std::vector<i64> A(N);
    for (auto &e : A)
        e = scan<i64>();

    SegmentTree<monoid> s(A);
    for ([[maybe_unused]] const auto i : rep(0, Q)) {
        const int t = scan<int>();
        if (t == 0) {
            const usize p = scan<usize>();
            const i64 x = scan<i64>();
            s.set(p, monoid::operation(s.get(p), x));
        } else {
            const usize l = scan<usize>();
            const usize r = scan<usize>();
            std::cout << s.product(l, r) << eoln;
        }
    }
}