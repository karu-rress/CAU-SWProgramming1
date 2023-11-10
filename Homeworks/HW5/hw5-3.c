/**
 * 
 * HW5-3.c
 *
 * 
 * [3] 서로 다른 10개의 자연수(1~50)를 무작위로 생성한 후
 * (random_gen() 함수를 정의하여 생성) 아래와 같이 작동하는
 * sorting() 함수(전달 받은 10개의 수를 올림차순으로 정렬하는 함수)를
 * 재귀적으로 호출하여(recursive call) 출력하는 프로그램을 작성
 *
 * 1) 가장 큰 수를 찾아 마지막 위치에 놓는다.
 * 2) 나머지 수에서 가장 큰 수를 찾아 마지막 위치에 놓는다.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_gen(int array[static 10]);
void sorting(int array[static 10], int size);

int main(void) {
    int random[10];

    random_gen(random);
    sorting(random, 10);

    for (int i = 0; i < 10; i++)
        printf("%d, ", random[i]);

    printf("\b\b \n");
    return 0;
}

void random_gen(int array[static 10]) {
    srand((unsigned int)time(NULL));

    for (int i = 0; i < 10; i++)
        array[i] = rand() % 50 + 1;
}

void sorting(int array[static 10], int size) {
    int max = 0, max_index = -1;

    if (size <= 1)
        return;

    for (int i = 0; i < size; i++) 
        if (array[i] > max) {
            max = array[i];
            max_index = i;
        }
    
    // swap
    array[max_index] = array[size - 1];
    array[size - 1] = max;

    sorting(array, size - 1);
}