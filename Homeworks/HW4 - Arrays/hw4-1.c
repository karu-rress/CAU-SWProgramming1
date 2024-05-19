/**
 * 
 * HW 4-1
 * 
 *
 * 피보나치(Fibonacci) 수열은 다음과 같이 정의된다.
 * 
 * 	f(n) = 1  (n<=2)
 *	f(n) = f(n-2) + f(n-1)   (n>2)
 *
 *
 * 임의의 자연수 n (10~20)을 생성하여
 * f(1)부터 f(n)까지의 수열을 출력하는 프로그램을 작성.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fib(int n);

int main() {
    int i, n;

    srand((unsigned int)time(NULL));
    n = rand() % 11 + 10;

    for (i = 1; i <= n; i++)
        printf("%d, ", fib(i));
    
    puts("\b\b ");
    return 0;
}

int fib(int n) {
    if (n <= 2)
        return 1;
    return fib(n - 2) + fib(n - 1);
}