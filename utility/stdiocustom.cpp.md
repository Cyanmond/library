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
  bundledCode: "#line 2 \"utility/stdiocustom.cpp\"\n\n#include <fstream>\n#include\
    \ <iostream>\n\nstruct stdiocustom_struct_ {\n    stdiocustom_struct_() {\n  \
    \      freopen(\"in.txt\", \"r\", stdin);\n        freopen(\"out.txt\", \"w\"\
    , stdout);\n    }\n} stdiocustom_var_;\n"
  code: "#pragma once\n\n#include <fstream>\n#include <iostream>\n\nstruct stdiocustom_struct_\
    \ {\n    stdiocustom_struct_() {\n        freopen(\"in.txt\", \"r\", stdin);\n\
    \        freopen(\"out.txt\", \"w\", stdout);\n    }\n} stdiocustom_var_;"
  dependsOn: []
  isVerificationFile: false
  path: utility/stdiocustom.cpp
  requiredBy: []
  timestamp: '2021-11-05 14:34:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utility/stdiocustom.cpp
layout: document
redirect_from:
- /library/utility/stdiocustom.cpp
- /library/utility/stdiocustom.cpp.html
title: utility/stdiocustom.cpp
---
