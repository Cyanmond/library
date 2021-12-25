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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/many_aplusb\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../../utility/eoln.cpp\"\n#include\
    \ \"../../utility/int_alias.cpp\"\n#include \"../../utility/rep.cpp\"\n#include\
    \ \"../../utility/scan.cpp\"\n\nint main(void) {\n    const usize T = scan<usize>();\n\
    \    std::vector<i64> A(T), B(T);\n    for (const auto i : rep(0, T)) {\n    \
    \    A[i] = scan<i64>();\n        B[i] = scan<i64>();\n        std::cout << A[i]\
    \ + B[i] << eoln;\n    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/library-checker/many_aplusb.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library-checker/many_aplusb.test.cpp
layout: document
redirect_from:
- /verify/verify/library-checker/many_aplusb.test.cpp
- /verify/verify/library-checker/many_aplusb.test.cpp.html
title: verify/library-checker/many_aplusb.test.cpp
---
