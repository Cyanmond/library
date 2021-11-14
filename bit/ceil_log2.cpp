#pragma once

template <typename T> constexpr int ceil_log2(const T v) {
    int res = 0;
    while ((T(1) << res) < v)
        ++res;
    return res;
}