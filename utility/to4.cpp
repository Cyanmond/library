#pragma once

#include "../utility/int_alias.cpp"
#include <array>

class to4 {
    using value_type = usize;
    static_assert(std::is_unsigned_v<value_type>);
    static constexpr value_type minus1 = std::numeric_limits<value_type>::max();
    static constexpr std::array<value_type, 5> dx = {minus1, 0, 1, 0, 0}, dy = {0, minus1, 0, 1, 0};

    struct to4_iterator {
        int d;
        const value_type h, w, maxh, maxw;
        constexpr to4_iterator(const value_type h_, const value_type w_, const value_type maxh_, const value_type maxw_) noexcept
            : d(0), h(h_), w(w_), maxh(maxh_), maxw(maxw_) {}
        constexpr void operator++() noexcept {
            do {
                ++d;
            } while(d != 4 and (h + dx[d] == minus1 or h + dx[d] == maxh or w + dy[d] == minus1 or w + dy[d] == maxw));
        }
        constexpr bool operator!=(const int other) const noexcept { return d != other; }
        constexpr std::pair<value_type, value_type> operator*() const noexcept { return {h + dx[d], w + dy[d]}; }
    };

    const to4_iterator i;

  public:
    constexpr to4(const value_type h, const value_type w, const value_type maxh, const value_type maxw) noexcept : i(h, w, maxh, maxw) {}
    constexpr to4_iterator begin() const noexcept { return i; }
    constexpr int end() const noexcept { return 4; }
};