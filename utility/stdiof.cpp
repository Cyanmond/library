#pragma once

#include <fstream>
#include <iostream>

struct stdiocustom_struct_ {
    stdiocustom_struct_() {
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    }
} stdiocustom_var_;