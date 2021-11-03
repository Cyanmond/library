#pragma once

#include <limits>

template <class T, T Div = 2>
constexpr T infty = std::numeric_limits<T>::max() / Div;