#pragma once

#include "../utility/int128_alias.cpp"
#include "../utility/int_alias.cpp"

class Barrett {
    u32 mod;
    u64 near_inv;

  public:
    explicit constexpr Barrett(const u32 mod_) noexcept
        : mod(mod_), near_inv((u64)(-1) / mod_ + 1) {}

    constexpr u32 product(const u32 a, const u32 b) const noexcept {
        const u64 z = static_cast<u64>(a) * static_cast<u64>(b);
        const u64 x = static_cast<u64>((static_cast<u128>(z) * static_cast<u128>(near_inv)) >> 64);
        const u32 v = static_cast<u32>(z - x * mod);
        return v < mod ? v : v + mod;
    }
};