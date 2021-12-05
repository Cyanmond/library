#pragma once

#include "../utility/int_alias.cpp"
#include <algorithm>

class rep {
    struct rep_iterator {
        usize itr;
        constexpr rep_iterator(const usize pos) noexcept : itr(pos) {}
        constexpr void operator++() noexcept {
            ++itr;
        }
        constexpr bool operator!=(const usize &other) const noexcept {
            return itr != other;
        }
        constexpr usize operator*() const noexcept {
            return itr;
        }
    };
    
    const rep_iterator first;
    const usize last;

  public:
    constexpr rep(const usize first_, const usize last_) noexcept
        : first(first_), last(std::max(first_, last_)) {}
    constexpr rep_iterator begin() const noexcept {
        return first;
    }
    constexpr usize end() const noexcept {
        return last;
    }
};
