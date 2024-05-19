/** 
 * 
 * HW 6-1-1
 * 
 * ㈜ 전역 변수 사용하지 말 것.
 *
 * [1] n개의 노드를 갖는 서로 다른 이진 트리의 개수는 2nCn 개가 된다.
 * 노드의 개수 n(1~10)을 입력 받아 n개의 노드를 갖는 서로 다른 이진
 * 트리의 개수를 구하되 factorial 구하는 방식을 다음과 같이 각각 프로그램 작성.
 *	
 *	가. 반복 방식
 *	나. 순환 방식
*/

#include <stdio.h>

unsigned long long fact(unsigned long long n);

int main(void) {
    unsigned long long n, trees;
    scanf("%llu", &n);

    // ₂nCn = 2n! / (2n-n)! n!
    trees = fact(2*n) / fact(2*n - n) * fact(n);
    printf("trees: %llu\n", trees);
}

unsigned long long fact(unsigned long long n) {
    unsigned long long result = 1;
    for (unsigned long long i = 1; i <= n; i++)
        result *= i;
    return result;
}