#pragma once

#include "../utility/int_alias.cpp"
#include <limits>

template <class T, T Div = 2> constexpr T infty = std::numeric_limits<T>::max() / Div;

constexpr i32 infi32 = infty<i32, 2>;
constexpr i64 infi64 = infty<i64, 4>;

constexpr u32 infu32 = infty<u32, 4>;
constexpr u64 infu64 = infty<u32, 4>;

constexpr isize infisz = infty<isize, 2>;
constexpr usize infusz = infty<usize, 4>;