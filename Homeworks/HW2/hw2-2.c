/**
 * 
 * HW 2-2
 * 
 *
 * 5자리의 자연수(10000~99999)를 입력받아
 * 자리가 역순인 수로 변환한 후 출력하는 프로그램 작성.
 * ㈜ 5자리 자연수는 자릿수별이 아닌 하나의 자연수로 입출력 할 것
 * 예:  26753--> 35762,  12300-->321
 *
 * ---------------------------------------
 * 
 * Key: (int) / (int) => (int), remainder's discarded
 * 
 */

#include <stdio.h>

int main(void)
{
    int input, result;
    int c1, c2, c3, c4, c5;

    printf("5자리 자연수 입력 >> ");
    scanf("%d", &input);

    c1 = input / 10000;     // [1]2345
    input %= 10000;         // 2345

    c2 = input / 1000;      // [2]345
    input %= 1000;          // 345

    c3 = input / 100;       // [3]45
    input %= 100;           // 45

    c4 = input / 10;        // [4]5
    input %= 10;            // 5

    c5 = input;             // [5]

    result = c5*10000 + c4*1000 + c3*100 + c2*10 + c1*1;
    printf("%d\n", result);
    

    /*
    result = 0;
    int digit = 0;

    for (int i = 10000; i >= 1; i /= 10) {
        result += (input / i) * i;
        input %= i;
    }

    */


    return 0;
}