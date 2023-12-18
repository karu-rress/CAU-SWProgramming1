#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i = 30;
    char arr[20];

    itoa(i, arr, 10);

    printf("%s", arr);
}