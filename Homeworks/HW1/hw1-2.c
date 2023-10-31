/**
 * HW 1-2
 * 
 * [2] 2개의 분수를 (입력형식: 4/3 3/4 혹은 4/3+3/4) 입력 받아 
 * 합과 평균(소수 2째자리까지)을 출력하는 프로그램 작성.

<입력 예시>: __   은 입력 데이타
Input fraction: __4/3  3/4__

<출력 예시>
Sum: 25/12
Avg: 1.04
 * 
 */

#include <stdio.h>

int main()
{
    int a, b, c, d;
    // 정밀도 확보를 위해 float 대신 long double 사용
    long double var1, var2;
    printf("Input fraction: ");

    // '/' => 정확히 '/' 문자가 매칭되어야 함 (아닐 경우 fail)
    // %*1[ +] : ' ', '+' 중 한 문자를 읽고 버림
    // %*c도 가능하긴 하나 다른 문자가 와도 오류를 내지 않음.
    scanf("%d/%d%*1[ +]%d/%d", &a, &b, &c, &d);

    var1 = (long double)a / b;
    var2 = (long double)c / d;

    // 약분은 하지 않음
    printf("Sum: %d/%d\n", (a * d + b * c), (b * d));
    printf("Avg: %.2Lf", (var1 + var2) / 2);

    return 0;
}