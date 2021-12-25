---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../utility/scan.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../data-structure/segmenttree.cpp\"\n#include \"../../utility/eoln.cpp\"\
    \n#include \"../../utility/int_alias.cpp\"\n#include \"../../utility/rep.cpp\"\
    \n#include \"../../utility/scan.cpp\"\n\nstruct monoid {\n    using value_type\
    \ = i64;\n    static value_type operation(const value_type a, const value_type\
    \ b) {\n        return a + b;\n    }\n    static value_type identity() {\n   \
    \     return 0;\n    }\n};\n\nint main(void) {\n    const usize N = scan<usize>();\n\
    \    const usize Q = scan<usize>();\n    std::vector<i64> A(N);\n    for (auto\
    \ &e : A)\n        e = scan<i64>();\n\n    SegmentTree<monoid> s(A);\n    for\
    \ ([[maybe_unused]] const auto i : rep(0, Q)) {\n        const int t = scan<int>();\n\
    \        if (t == 0) {\n            const usize p = scan<usize>();\n         \
    \   const i64 x = scan<i64>();\n            s.set(p, monoid::operation(s.get(p),\
    \ x));\n        } else {\n            const usize l = scan<usize>();\n       \
    \     const usize r = scan<usize>();\n            std::cout << s.product(l, r)\
    \ << eoln;\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/library-checker/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library-checker/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library-checker/point_add_range_sum.test.cpp
- /verify/verify/library-checker/point_add_range_sum.test.cpp.html
title: verify/library-checker/point_add_range_sum.test.cpp
---
