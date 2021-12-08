#pragma once

#include <utility>

template <class F> class rec_lambda {
    F f;

  public:
    explicit constexpr rec_lambda(F &&f_) : f(std::forward<F>(f_)) {}
    template <class... Args> constexpr auto operator()(Args &&...args) const {
        return f(*this, std::forward<Args>(args)...);
    }
};
