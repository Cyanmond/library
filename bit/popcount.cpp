#pragma once

#include "../utility/int_alias.cpp"

usize popcount(u64 n) {
#ifdef __GNUC__
    return __builtin_popcountll(n);
#else
    n -= n >> 1 & 0x5555555555555555;
    n = (n & 0x3333333333333333) + (n >> 2 & 0x3333333333333333);
    n = n + (n >> 4) & 0x0F0F0F0F0F0F0F0F;
    return n * 0x0101010101010101 >> 56 & 0x7f;
#endif
}