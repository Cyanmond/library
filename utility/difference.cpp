#pragma once

template <typename T> constexpr T difference(const T a, const T b) {
    return (a > b) ? (a - b) : (b - a);
}
