#pragma once

#include "int_alias.cpp"
#include <iostream>
#include <vector>

template <typename T> inline T scan() {
    T x;
    std::cin >> x;
    return x;
}

template <typename T> std::vector<T> scan_vec(const usize n) {
    std::vector<T> res(n);
    for (auto &e : res)
        e = scan<T>();
    return res;
}

template <typename T> std::vector<std::vector<T>> scan_vec(const usize n, const usize m) {
    std::vector<std::vector<T>> res(n);
    for (auto &vec : res)
        vec = scan_vec<T>(m);
    return res;
}

template <typename T, class F> std::vector<T> scan_vec_f(const usize n, const F &f) {
    std::vector<T> res;
    for (auto &e : res)
        e = f(scan<T>());
    return res;
}

template <typename T, class F> auto scan_vec_f(const usize n, const usize m, const F &f) {
    std::vector<std::vector<T>> res(n);
    for (auto &vec : res)
        vec = scan_vec_f<T>(m, f);
    return res;
}