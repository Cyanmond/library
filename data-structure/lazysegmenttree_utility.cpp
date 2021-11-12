#pragma once

#include "../../library/data-structure/lazysegmenttree.cpp"
#include "../../library/utility/int_alias.cpp"
#include "../../library/utility/int_infinity.cpp"

namespace cl_lazysegmenttree_utility {
template <class T> struct AddPartsLazySegmentTreeUtility {
    using value_type = T;
    static constexpr T operation(const T a, const T b) {
        return a + b;
    }

    static constexpr T identity() {
        return 0;
    }
};

template <class T> struct MaxPartsLazySegmentTreeUtility {
    using value_type = T;
    static constexpr T operation(const T a, const T b) {
        return (a > b ? a : b);
    }

    static constexpr T identity() {
        return -infty<T>;
    }
};

template <class T> struct MinPartsLazySegmentTreeUtility {
    using value_type = T;
    static constexpr T operation(const T a, const T b) {
        return (a < b ? a : b);
    }

    static constexpr T identity() {
        return infty<T>;
    }
};

template <class T> struct AssignPartsLazySegmentTreeUtility {
    using value_type = T;
    static constexpr T operation(const T a, const T b) {
        return b == identity() ? a : b;
    }

    static constexpr T identity() {
        return infty<T>;
    }
};

template <class T> struct RangeAddRangeSum {
    using Monoid = typename AddPartsLazySegmentTreeUtility<T>;
    using Effector = typename AddPartsLazySegmentTreeUtility<T>;

    static constexpr Monoid::value_type operation(const Effector::value_type a,
                                                  const Monoid::value_type b) {
        return a + b;
    }
};

template <class T> struct RangeChmaxRangeSum {
    using Monoid = typename AddPartsLazySegmentTreeUtility<T>;
    using Effector = typename MaxPartsLazySegmentTreeUtility<T>;

    static constexpr Monoid::value_type operation(const Effector::value_type a,
                                                  const Monoid::value_type b) {
        return (a > b ? a : b);
    }
};

template <class T> struct RangeChminRangeSum {
    using Monoid = typename AddPartsLazySegmentTreeUtility<T>;
    using Effector = typename MinPartsLazySegmentTreeUtility<T>;

    static constexpr Monoid::value_type operation(const Effector::value_type a,
                                                  const Monoid::value_type b) {
        return (a < b ? a : b);
    }
};

template <class T> struct RangeAssignRangeSum {
    using Monoid = typename AddPartsLazySegmentTreeUtility<T>;
    using Effector = typename MaxPartsLazySegmentTreeUtility<T>;

    static constexpr Monoid::value_type operation(const Effector::value_type a,
                                                  const Monoid::value_type b) {
        return (a == Effector::identity() ? b : a);
    }
};

template <class T> struct RangeAddRangeMax {
    using Monoid = typename MaxPartsLazySegmentTreeUtility<T>;
    using Effector = typename AddPartsLazySegmentTreeUtility<T>;

    static constexpr Monoid::value_type operation(const Effector::value_type a,
                                                  const Monoid::value_type b) {
        return a + b;
    }
};

template <class T> struct RangeChmaxRangeMax {
    using Monoid = typename MaxPartsLazySegmentTreeUtility<T>;
    using Effector = typename MaxPartsLazySegmentTreeUtility<T>;

    static constexpr Monoid::value_type operation(const Effector::value_type a,
                                                  const Monoid::value_type b) {
        return (a > b ? a : b);
    }
};

template <class T> struct RangeChminRangeMax {
    using Monoid = typename MaxPartsLazySegmentTreeUtility<T>;
    using Effector = typename MinPartsLazySegmentTreeUtility<T>;

    static constexpr Monoid::value_type operation(const Effector::value_type a,
                                                  const Monoid::value_type b) {
        return (a < b ? a : b);
    }
};

template <class T> struct RangeAssignRangeMax {
    using Monoid = typename MaxPartsLazySegmentTreeUtility<T>;
    using Effector = typename AssignPartsLazySegmentTreeUtility<T>;

    static constexpr Monoid::value_type operation(const Effector::value_type a,
                                                  const Monoid::value_type b) {
        return (a == Effector::identity() ? b : a);
    }
};

template <class T> struct RangeAddRangeMin {
    using Monoid = typename MinPartsLazySegmentTreeUtility<T>;
    using Effector = typename MinPartsLazySegmentTreeUtility<T>;

    static constexpr Monoid::value_type operation(const Effector::value_type a,
                                                  const Monoid::value_type b) {
        return a + b;
    }
};

template <class T> struct RangeChmaxRangeMin {
    using Monoid = typename MinPartsLazySegmentTreeUtility<T>;
    using Effector = typename MinPartsLazySegmentTreeUtility<T>;

    static constexpr Monoid::value_type operation(const Effector::value_type a,
                                                  const Monoid::value_type b) {
        return (a > b ? a : b);
    }
};

template <class T> struct RangeChminRangeMin {
    using Monoid = typename MinPartsLazySegmentTreeUtility<T>;
    using Effector = typename MinPartsLazySegmentTreeUtility<T>;

    static constexpr Monoid::value_type operation(const Effector::value_type a,
                                                  const Monoid::value_type b) {
        return (a < b ? a : b);
    }
};

template <class T> struct RangeAssignRangeMin {
    using Monoid = typename MinPartsLazySegmentTreeUtility<T>;
    using Effector = typename AssignPartsLazySegmentTreeUtility<T>;

    static constexpr Monoid::value_type operation(const Effector::value_type a,
                                                  const Monoid::value_type b) {
        return (a == Effector::identity() ? b : a);
    }
};
} // namespace cl_lazysegmenttree_utility

namespace segmenttrees {
template <class T = i64>
using RangeAddRangeSum = LazySegmentTree<cl_lazysegmenttree_utility::RangeAddRangeSum<T>>;

template <class T = i64>
using RangeChMaxRangeSum = LazySegmentTree<cl_lazysegmenttree_utility::RangeChmaxRangeSum<T>>;

template <class T = i64>
using RangeChminRangeSum = LazySegmentTree<cl_lazysegmenttree_utility::RangeChminRangeSum<T>>;

template <class T = i64>
using RangeAssignRangeSum = LazySegmentTree<cl_lazysegmenttree_utility::RangeAssignRangeSum<T>>;

template <class T = i64>
using RangeAddRangeMax = LazySegmentTree<cl_lazysegmenttree_utility::RangeAddRangeMax<T>>;

template <class T = i64>
using RangeChMaxRangeMax = LazySegmentTree<cl_lazysegmenttree_utility::RangeChmaxRangeMax<T>>;

template <class T = i64>
using RangeChminRangeMax = LazySegmentTree<cl_lazysegmenttree_utility::RangeChminRangeMax<T>>;

template <class T = i64>
using RangeAssignRangeMax = LazySegmentTree<cl_lazysegmenttree_utility::RangeAssignRangeMax<T>>;

template <class T = i64>
using RangeAddRangeMin = LazySegmentTree<cl_lazysegmenttree_utility::RangeAddRangeMin<T>>;

template <class T = i64>
using RangeChMaxRangeMin = LazySegmentTree<cl_lazysegmenttree_utility::RangeChmaxRangeMin<T>>;

template <class T = i64>
using RangeChminRangeMin = LazySegmentTree<cl_lazysegmenttree_utility::RangeChminRangeMin<T>>;

template <class T = i64>
using RangeAssignRangeMin = LazySegmentTree<cl_lazysegmenttree_utility::RangeAssignRangeMin<T>>;
} // namespace segmenttrees