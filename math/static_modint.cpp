#pragma once

#include <cstddef>
#include <cstdint>
#include <type_traits>

template <std::uint32_t MOD> class StaticModint {
    using this_type = StaticModint;
    std::uint32_t value;

  public:
    static constexpr std::uint32_t mod() noexcept { return MOD; }
    template <class T> static constexpr T mod() noexcept { return static_cast<T>(MOD); }

    template <class T, std::enable_if_t<std::is_unsigned_v<T>> * = nullptr>
    static constexpr std::uint32_t normalize(const T v) noexcept {
        return static_cast<std::uint32_t>(v % mod<T>());
    }
    template <class T, std::enable_if_t<std::is_signed_v<T>> * = nullptr>
    static constexpr std::uint32_t normalize(const T v) noexcept {
        if(v < 0)
            return static_cast<std::uint32_t>(v % mod<T>() + mod<T>());
        else
            return static_cast<std::uint32_t>(v % mod<T>());
    }

    constexpr StaticModint() noexcept : value(0) {}
    template <class T> constexpr StaticModint(const T v) noexcept : value(normalize(v)) {}

    template <class T> static constexpr this_type raw(const T v) noexcept {
        this_type ret;
        ret.value = static_cast<std::uint32_t>(v);
        return ret;
    }

    constexpr const std::uint32_t &val() const noexcept { return value; }
    constexpr this_type operator-() const noexcept { return value == 0 ? 0 : mod() - value; }

    constexpr bool operator==(const this_type &rhs) const noexcept { return value == rhs.value; }
    constexpr bool operator!=(const this_type &rhs) const noexcept { return value != rhs.value; }
    constexpr bool operator<(const this_type &rhs) const noexcept { return value < rhs.value; }
    constexpr bool operator<=(const this_type &rhs) const noexcept { return value <= rhs.value; }
    constexpr bool operator>(const this_type &rhs) const noexcept { return value > rhs.value; }
    constexpr bool operator>=(const this_type &rhs) const noexcept { return value >= rhs.value; }
    constexpr this_type &operator++() noexcept {
        ++value;
        if(value == mod())
            value = 0;
        return *this;
    }
    constexpr this_type &operator--() noexcept {
        if(value == 0)
            value = mod();
        --value;
        return *this;
    }
    constexpr this_type operator++(int) noexcept {
        this_type ret(*this);
        ++*this;
        return ret;
    }
    constexpr this_type operator--(int) noexcept {
        this_type ret(*this);
        --*this;
        return ret;
    }

    constexpr this_type operator+(const this_type &rhs) const noexcept {
        return this_type(*this) += rhs;
    }
    constexpr this_type operator-(const this_type &rhs) const noexcept {
        return this_type(*this) -= rhs;
    }
    constexpr this_type operator*(const this_type &rhs) const noexcept {
        return this_type(*this) *= rhs;
    }
    constexpr this_type operator/(const this_type &rhs) const noexcept {
        return this_type(*this) /= rhs;
    }

    constexpr this_type &operator+=(const this_type &rhs) noexcept {
        if((value += rhs.value) >= mod())
            value -= mod();
        return *this;
    }
    constexpr this_type &operator-=(const this_type &rhs) noexcept {
        if(value < rhs.value)
            value += mod();
        value -= rhs.value;
        return *this;
    }
    constexpr this_type &operator*=(const this_type &rhs) noexcept {
        value = static_cast<std::uint32_t>(static_cast<std::uint64_t>(value) *
                                           static_cast<std::uint64_t>(rhs.value) %
                                           mod<std::uint64_t>());
        return *this;
    }
    constexpr this_type &operator/=(const this_type &rhs) noexcept { return *this *= rhs.inv(); }

    template <class T> constexpr this_type pow(T n) {
        this_type ret(1), x(*this);
        while(n != 0) {
            if(n & 1)
                ret *= x;
            x *= x;
            n >>= 1;
        }
        return ret;
    }
    constexpr this_type inv() const {
        std::int64_t s = mod<std::int64_t>(), t = static_cast<std::int64_t>(value), a = 0, b = 1;
        while(t != 0) {
            const std::int64_t u = s / t;
            s -= t * u;
            a -= b * u;
            auto k = s;
            s = t;
            t = k;
            k = a;
            a = b;
            b = k;
        }
        if(a < 0)
            a += mod<std::int64_t>();
        return this_type::raw(a);
    }
};

using Modint1000000007 = StaticModint<1000000007>;
using Modint998244353 = StaticModint<998244353>;