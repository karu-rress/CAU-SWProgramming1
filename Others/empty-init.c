#include <stdio.h>

int main() {
    int arr[10] = {}; // empty-init.c:4:19: warning: ISO C forbids empty initializer braces before C2X [-Wpedantic]
    printf("%d\n", arr[0]); // 0 출력

    return 0;
}