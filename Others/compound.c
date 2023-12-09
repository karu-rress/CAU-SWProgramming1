#include <stdio.h>

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d, ", arr[i]);
    puts("\n");
}

int main() {
    print_arr((int[]){1, 2, 3, 4, 5}, 5);

    // 마찬가지로 이 문법이 없다면 아래와 같이 써야 했을 겁니다.
    int array[] = {1, 2, 3};
    print_arr(array, 3);
}