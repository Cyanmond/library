#pragma once

template <typename T>
bool is_pow2(const T n) {
    return (n & (n - 1)) == 0;
}