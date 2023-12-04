#include <stdio.h>

void test(int (*)[2]);
void test1(int [][2]);
// void test2(int [][]) // 에러
// void test2(int [4]); // 에러

int main(void) {
    int b[5] = {1, 2, 3, 4, 5};
    int (*pa)[5] = &b;

    for (int i = 0; i < 5; i++)
        printf("%5d", (*pa)[i]);                    //   1  2  3  4  5

    int a[2][2] = {10, 20, 30, 40};
    printf("\n%p    %p\n", a, &a);                  // same address
    printf("%p  %p  %d\n", a+1, *(a+1), **(a+1));   // addr, addr, value
    printf("===%p   %p  %d\n\n", a[0], &a[0], *a[0]); // addr, addr, value

    // a++ : l-avlue가 아니므로 에러. (배열 이름은 상수!)
    test(a);
    test1(a);
    return 0;
}

void test(int (*a)[2]) {
    // a: 넘겨받은 시작주소, &a: 포인터변수 파라미터 a의 주소
    printf("%p  %p\n", a, &a);

    // addr, addr, value, value, value
    printf("%p  %p  %d  %d  %d\n\n", a+1, *(a+1), **(a+1), (*(a+1))[0], (*(a+1))[1]);

    // a++ : 얘는 별개의 포인터 변수이므로 l-value임. 수정 가능.
}

void test1(int a[][2]) {
    // a: 넘겨받은 시작주소, &a: 포인터변수 파라미터 a의 주소
    printf("%p  %p\n", a, &a);

    // addr, addr, value, value, value
    printf("%p  %p  %d  %d  %d\n\n", a+1, *(a+1), **(a+1), (*(a+1))[0], (*(a+1))[1]);
}