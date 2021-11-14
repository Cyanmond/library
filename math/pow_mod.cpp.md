---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nomarlize_mod.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n\n#include \"../utility/int_alias.cpp\"\n#include \"barrett.cpp\"\
    \n#include \"nomarlize_mod.cpp\"\n#include <cassert>\n#include <type_traits>\n\
    \ntemplate <class T> u32 pow_mod(T x, u64 exp, const u32 mod) {\n    assert(mod\
    \ != 0);\n    if (mod == 1) return 0;\n    const Barrett bt(mod);\n    u32 ret\
    \ = 1, p = normalize_mod<std::common_type<T, i64>>(x, mod);\n    while (exp !=\
    \ 0) {\n        if (exp & 1) ret = bt.product(ret, p);\n        exp >>= 1;\n \
    \       p = bt.product(ret, p);\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/pow_mod.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/pow_mod.cpp
layout: document
redirect_from:
- /library/math/pow_mod.cpp
- /library/math/pow_mod.cpp.html
title: math/pow_mod.cpp
---
