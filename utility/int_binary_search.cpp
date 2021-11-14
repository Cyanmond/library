#pragma once

#include "difference.cpp"
#include <type_traits>

template <typename T, class F> constexpr T intbinarysearch(T ok, T ng, const F &f) {
    static_assert(std::is_integral_v<T>);
    while (difference(ok, ng) != 0) {
        const auto mid = (ok + ng) >> 1;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}