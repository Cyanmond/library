#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#include <iostream>
#include <vector>

#include "../../utility/eoln.cpp"
#include "../../utility/int_alias.cpp"
#include "../../utility/rep.cpp"
#include "../../utility/scan.cpp"

int main(void) {
    const usize T = scan<usize>();
    std::vector<i64> A(T), B(T);
    for (const auto i : rep(0, T)) {
        A[i] = scan<i64>();
        B[i] = scan<i64>();
        std::cout << A[i] + B[i] << eoln;
    }
}