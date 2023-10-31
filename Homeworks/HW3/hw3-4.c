/**
 * 
 * HW 3-4
 * 
 *
 * 입력 갯수를 알수 없는(가변 갯수의)) 양수 분수(5/3 형식으로 입력 받을 것)들을
 * 입력 받아 합을 계산후 약분하여 출력예시 형식으로 출력하는 프로그램 작성.
 *
 * 출력 예시: 9/4(2+1/4),  10/4(2+1/2),   8/4(2) (정수 형태로)
 */

#include <stdio.h>

int main() {
    int sum_a = 0, sum_b = 0, a, b, quot = 0, i;
    for (;;) {
        scanf("%d/%d", &a, &b);
        if (b == 0)
            break;

        if (sum_a == 0) {
            sum_a = a;
            sum_b = b;
        }
        else {
            sum_a = sum_a*b + sum_b*a;
            sum_b *= b;
        }
    }
    
    a = sum_a;
    b = sum_b;
    quot = a / b;
    a %= b;

    for (i = a; i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            a /= i;
            b /= i;
            break;
        }
    }

    if (a == 0)
        printf("%d", quot);
    else
        printf("%d+%d/%d", quot, a, b);

    return 0;
}