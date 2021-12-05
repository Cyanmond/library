#pragma once

#include "../utility/int_alias.cpp"

class repstep {
    struct repstep_iterator {
        usize itr, stepsize;
        constexpr repstep_iterator(const usize pos, const usize stp) noexcept
            : itr(pos), stepsize(stp) {}
        constexpr void operator++() noexcept {
            itr += stepsize;
        }
        constexpr bool operator!=(const usize &other) const noexcept {
            return itr < other;
        }
        constexpr usize operator*() const noexcept {
            return itr;
        }
    };

    const repstep_iterator first;
    const usize last;

  public:
    constexpr repstep(const usize first_, const usize last_, const usize stp_)
        : first(first_, stp_), last(last_) {}
    constexpr repstep_iterator begin() const noexcept {
        return first;
    }
    constexpr usize end() const noexcept {
        return last;
    }
};