#pragma once

#include "int_alias.cpp"
#include <iostream>
#include <vector>

template <typename T> inline std::vector<T> scan_vec(const usize n) {
    std::vector<T> res(n);
    for (usize i = 0; i < n; ++i) {
        res[i] = scan<T>();
    }
    return res;
}

template <typename T, class F> inline std::vector<T> scan_vec(const usize n, const F f) {
    std::vector<T> res(n);
    for (usize i = 0; i < n; ++i) {
        res[i] = f(scan<T>());
    }
    return res;
}