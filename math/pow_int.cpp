#pragma once

template <typename T>
constexpr T pow_int(T n,T k) {
    auto m = n;
    while (k != 0) {
        if (k & 1) m *= n;
        n *= n;
        k >>= 1;
    }
    return m;
}