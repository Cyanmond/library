#pragma once

#include "../utility/int_alias.cpp"
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

class UnionFind {
  public:
    struct node_type {
        usize parent;
        usize size;
    };

  private:
    usize components;
    std::vector<node_type> data;

  public:
    explicit UnionFind(const usize n_) : components(n_), data(n_, {0, 1}) {
        for (usize i = 0; i < n_; ++i) {
            data[i].parent = i;
        }
    }

    usize size() const {
        return data.size();
    }

    usize count_components() const {
        return components;
    }

    usize leader(usize v) {
        assert(v < size());
        if (data[v].parent == v) return v;
        data[v].parent = leader(data[v].parent);
        return data[v].parent;
    }

    usize size(const usize v) {
        assert(v < size());
        return data[leader(v)].size;
    }

    std::pair<usize, usize> unite(usize x, usize y) {
        assert(x < size());
        assert(y < size());
        x = leader(x);
        y = leader(y);
        if (x != y) {
            if (data[x].size < data[y].size) std::swap(x, y);
            data[y].parent = x;
            data[x].size += data[y].size;
        }
        return {x, y};
    }

    std::vector<std::vector<usize>> decompose() {
        std::vector<std::vector<usize>> ret(size());
        for (usize i = 0; i < size(); ++i)
            ret[leader(i)].push_back(i);

        ret.erase(std::remove_if(ret.begin(), ret.end(),
                                 [&](const std::vector<usize> &v) { return v.empty(); }),
                  ret.end());
        return ret;
    }
};