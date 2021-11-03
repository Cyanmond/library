#pragma once

template <typename T> bool setmax(T &lhs, const T &rhs) {
    if(rhs > lhs) {
        lhs = rhs;
        return true;
    }
    return false;
}