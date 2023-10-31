/**
 * 
 * HW 3-1
 * 
 *
 * 무작위로 생성된 20개의 자연수 (1~100)를 아래 조건에 맞게
 * 4개의 그룹명(A, B, C, D)으로 분류한 후 
 * 멤버수가 가장 많은 그룹과 적은 그룹의 그룹명과 멤버수를
 * 각각 출력하는 프로그램 작성 (동수 그룹이면 알파벳순 낮은 그룹 1개 출력)
 * 
 * 	A: 50미만의 홀수		B: 50이상의 홀수
 *	C: 50미만의 짝수		D: 50이상의 짝수
 * 
 * * 출력예시: 
 * Group A: 6  Group B: 8   Group C: 3   Group D: 3
 * Max_group: B(8)   Min_group: C(6)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, temp, a = 0, b = 0, c = 0, d = 0;

    srand((unsigned int)time(NULL));
    for (i = 0; i < 20; i++) {
        temp = rand() % 100 + 1; // % 100 -> 0~99, +1 -> 1~100
        if (temp < 50) {    // A or C
            (temp % 2 == 1) ? a++ : c++;
        }
        else {              // B or D
            (temp % 2 == 1) ? b++ : d++;
        }
    }

    printf("Group A: %d\tGroup B: %d\tGroup C: %d\tGroup D: %d\n", a, b, c, d);

    if (a >= b && a >= c && a >= d)
        printf("Max_group: A(%d)\t\t", a);
    else if (b >= c && b >= d && b >= a)
        printf("Max_group: B(%d)\t\t", b);
    else if (c >= d && c >= a && c >= b)
        printf("Max_group: C(%d)\t\t", c);
    else
        printf("Max_group: D(%d)\t\t", d);
    
    if (a <= b && a <= c && a <= d)
        printf("Min_group: A(%d)\n", a);
    else if (b <= c && b <= d && b <= a)
        printf("Min_group: B(%d)\n", b);
    else if (c <= d && c <= a && c <= b)
        printf("Min_group: C(%d)\n", c);
    else
        printf("Min_group: D(%d)\n", d);

    return 0;
}