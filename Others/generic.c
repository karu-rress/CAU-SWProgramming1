#include <stdio.h>

enum TYPE { INT, DOUBLE, CHAR, OTHER };
#define type_name(expr) _Generic((expr), \
        char: CHAR, int: INT, double: DOUBLE, default: OTHER)

int main(void) {
    int c = 10;
    // char c = 10;
    _Static_assert(type_name(c) == INT, "type mismatch");

    return 0;
}