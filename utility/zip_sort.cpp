#pragma once

#include "../utility/int_alias.cpp"
#include <algorithm>
#include <vector>

template <class Head, class... Tail> std::vector<usize> zip_sort(std::vector<Head> &head, std::vector<Tail> &...tail) {
    const usize n = head.size();

    std::vector<std::tuple<Head, Tail..., usize>> res(n);
    for (usize i = 0; i < n; ++i)
        res[i] = std::make_tuple(head[i], tail[i]..., i);
    std::sort(res.begin(), res.end());

    std::vector<usize> order(n);
    for (usize i = 0; i < n; ++i)
        order[i] = std::get<std::tuple_size_v<std::tuple<Head, Tail...>>>(res[i]);
    helper::zip_sort_renumber(order, head, tail...);
    return order;
}