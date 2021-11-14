#pragma once

#include "../utility/int_alias.cpp"
#include "barrett.cpp"
#include "normalize_mod.cpp"
#include <cassert>
#include <type_traits>

template <class T> u32 pow_mod(T x, u64 exp, const u32 mod) {
    assert(mod != 0);
    if (mod == 1) return 0;
    const Barrett bt(mod);
    u32 ret = 1, p = static_cast<u32>(normalize_mod<std::common_type_t<i64, T>>(x, mod));
    while (exp != 0) {
        if (exp & 1) ret = bt.product(ret, p);
        exp >>= 1;
        p = bt.product(p, p);
    }
    return ret;
}