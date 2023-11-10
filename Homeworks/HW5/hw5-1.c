/**
 * 
 * HW5-1.c
 * 
 * 
 * [1] 2개의 정수 m과 n을 입력받아 함수 add_sub()를 호출하여 
 * 합(m+n)과 차(m-n)를 구한 후, 함수 swap()을 호출하여 m과 n을
 * 교환한 합과 차를 구하여 main()에서 교환전후 합과 차의 값을
 * 각각 출력하는 프로그램을 작성
 *
 */

#include <stdio.h>

void add_sub(int a, int b, int *sum, int *sub);
void swap(int *a, int *b);

int main(void) {
    int m, n, sum, sub;
    printf("정수 2개 입력: ");
    scanf("%d%d", &m, &n);

    printf("Before swap\n");
    add_sub(m, n, &sum, &sub);
    printf("Sum: %d, Sub: %d\n", sum, sub);

    swap(&m, &n);

    printf("After swap\n");
    add_sub(m, n, &sum, &sub);
    printf("Sum: %d, Sub: %d\n", sum, sub);
    
    return 0;
}

void add_sub(int a, int b, int *sum, int *sub) {
    *sum = a + b;
    *sub = a - b;
}

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}