#pragma once

template <typename T> constexpr bool is_prime(const T n) {
    if (n == 1) return false;
    for (T i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}