#pragma once

#include "int_alias.cpp"
#include <vector>

template <typename T> std::vector<T> make_vector(const usize n, const T &value) {
    return std::vector(n, value);
}

template <class... Args> auto make_vector(const usize n, Args... args) {
    return std::vector(n, make_vector(args...));
}