#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int a, b, c, d, e;

    srand((unsigned int)time(NULL));

    a = rand() % 91 + 10; // 10~109
    b = rand() % 91 + 10;
    c = rand() % 91 + 10;
    d = rand() % 91 + 10;
    e = rand() % 91 + 10;

    if (a < b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
    if (a < c) {
        a = a ^ c;
        c = a ^ c;
        a = a ^ c;
    }
    if (a < d) {
        a = a ^ d;
        d = a ^ d;
        a = a ^ d;
    }

    if (b < c) {
        b = b ^ c;
        c = b ^ c;
        b = b ^ c;
    }
    if (b < d) {
        b = b ^ d;
        d = b ^ d;
        b = b ^ d;
    }

    if (c < d) {
        c = c ^ d;
        d = c ^ d;
        c = c ^ d;
    }

    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
    return 0;
}