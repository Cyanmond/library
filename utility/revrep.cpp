#pragma once

#include "../utility/int_alias.cpp"

class revrep {
    struct revrep_iterator {
        usize itr;
        constexpr revrep_iterator(const usize pos) noexcept : itr(pos) {}
        constexpr void operator++() noexcept { --itr; }
        constexpr bool operator!=(const usize &other) const noexcept { return itr != other; }
        constexpr usize operator*() const noexcept { return itr; }
    };
    const revrep_iterator first;
    const usize last;

  public:
    constexpr revrep(const usize first_, const usize last_) noexcept
        : first(last_ - 1), last(first_ - 1) {}
    constexpr revrep_iterator begin() const noexcept { return first; }
    constexpr usize end() const noexcept { return last; }
};
