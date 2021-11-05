#pragma once

#include "../utility/int_infinity.cpp"
#include <array>
#include <cstddef>
#include <iostream>
#include <map>
#include <optional>
#include <set>
#include <utility>
#include <vector>

namespace debug_impl {
template <class T> inline void dump(const T &v);
void dump(const std::int32_t &v);
void dump(const std::int64_t &v);
void dump(const usize &v);
template <class T, class U> void dump(const std::pair<T, U> &v);
template <class... T> void dump(const std::tuple<T...> &v);
template <class T> void dump(const std::vector<T> &v);
template <class T, size_t s> void dump(const std::array<T, s> &v);
template <class T> void dump(const std::set<T> &v);
template <class T, class U> void dump(const std::map<T, U> &v);
template <class T> void dump(const std::optional<T> &v);

template <class T> inline void dump(const T &v) { std::cout << v; }

void dump(const std::int32_t &v) {
    if (v == infi32)
        std::cout << "inf";
    else if (v == -infi32)
        std::cout << "-inf";
    else
        std::cout << v;
}

void dump(const std::int64_t &v) {
    if (v == infi32 or v == infi64)
        std::cout << "inf";
    else if (v == -infi32 or v == -infi64)
        std::cout << "-inf";
    else
        std::cout << v;
}

void dump(const usize &v) {
    if (v == infusz)
        std::cout << "inf";
    else
        std::cout << v;
}

template <class T> void dump(const std::optional<T> &v) {
    if (v)
        dump(v.value());
    else
        dump("nullopt");
}

template <class T, class U> void dump(const std::pair<T, U> &v) {
    std::cout << "( ";
    dump(v.first);
    std::cout << ", ";
    dump(v.second);
    std::cout << " )";
}

template <class T> void dump(const std::vector<T> &v) {
    std::cout << "[ ";
    for (usize i = 0; i < v.size(); ++i) {
        dump(v[i]);
        if (i != v.size() - 1) std::cout << ", ";
    }
    std::cout << " ]";
}
template <class T, size_t S> void dump(const std::array<T, S> &v) {
    std::cout << "[ ";
    for (usize i = 0; i < S; ++i) {
        dump(v[i]);
        if (i != v.size() - 1) std::cout << ", ";
    }
    std::cout << " ]";
}

template <class T> void dump(const std::set<T> &v) {
    std::vector<T> r;
    for (const auto &x : v)
        r.push_back(x);
    dump(r);
}
template <class T, class U> void dump(const std::map<T, U> &v) {
    std::vector<std::pair<T, U>> r;
    for (const auto &p : v)
        r.push_back(p);
    dump(r);
}
void tuple_dump_impl() { std::cout << " )"; }
template <class Head, class... Tail> void tuple_dump_impl(const Head &h, const Tail &...t) {
    std::cout << h;
    if constexpr (sizeof...(Tail) != 0) std::cout << ", ";
    tuple_dump_impl(t...);
}

template <class... T> void dump(const std::tuple<T...> &v) {
    std::cout << "( ";
    std::apply(tuple_dump_impl<T...>, v);
}

void converter() { std::cout << '\n'; }
template <class Head, class... Tail> void converter(Head &&h, Tail &&...t) {
    dump(h);
    if constexpr (sizeof...(Tail) != 0) std::cout << ", ";
    converter(std::forward<Tail>(t)...);
}
} // namespace debug_impl