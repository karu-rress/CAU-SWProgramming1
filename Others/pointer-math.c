/**
 * @file pointer-math.c
 * @author Karu
 * @date 2023-12-12
 * 
 */

#include <stdio.h>

int v, source = 100, *p = &source;
#define EVALUATE(expr)  v = 0; source = 100; p = &source;\
        (expr);\
        printf("Result of [" #expr "]:\t v = %d, p = %p, *p = %d\n", v, p, *p)

int main(void) {
    printf("Original value: v = %d, p = %p, *p = %d\n\n", v, p, *p);
    EVALUATE(v = *p++);
    EVALUATE(v = (*p)++);
    EVALUATE(v = *++p);
    EVALUATE(v = ++*p);

    return 0;
}