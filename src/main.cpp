#include <iostream>

// Workaround
#include "lua5.3/lua.hpp"

// Sol
#include <sol/sol.hpp>

int main() {
    sol::state lua;
    int x = 0;
    lua.set_function("beep", [&x]{ ++x; });
    lua.script("beep()");

    if (x != 1) {
        std::cerr << "hmm... wtf..." << std::endl;
    }

    sol::function beep = lua["beep"];
    beep();
    if (x != 2) {
        std::cerr << "uh what?" << std::endl;
    }

    return 0;
}
