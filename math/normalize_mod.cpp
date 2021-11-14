#pragma once

#include <cassert>

template <typename T> constexpr T normalize_mod(const T x, const T mod) {
    assert(mod > 0);
    if (x > 0)
        return x % mod;
    else
        x % mod + mod;
}