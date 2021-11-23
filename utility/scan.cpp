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

template <typename T, class... Args> auto scan_vec(const usize n, Args... args) {
    std::vector<decltype(scan_vec(args...))> res(n);
    for (auto &vec : res)
        vec = scan_vec(args...);
    return res;
}

template <typename T, class F> std::vector<T> scan_vec_f(const usize n, const F &f) {
    std::vector<T> res;
    for (auto &e : res)
        e = f(scan<T>());
    return res;
}

template <typename T, class... Args> auto scan_vec_f(const usize n, Args... args) {
    std::vector<decltype(scan_vec_f(args...))> res(n);
    for (auto &vec : res)
        vec = scan_vec_f(args...);
    return res;
}