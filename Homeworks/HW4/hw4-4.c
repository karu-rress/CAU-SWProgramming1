/**
 * 
 * HW 4-4
 * 
 *
 * 무작위로 생성된 30개의 자연수 (1~100)를 
 * 아래 조건에 맞게 4개의 그룹명(A, B, C, D)으로 분류한 후
 *  각 그룹을 올림차순으로 정렬하여 출력한다. 각 그룹이 
 * 정렬되어 있다는 사실을 고려하여(merge 적용, 즉 정렬된 
 * 그룹들을 통합하여 재정렬하지 말 것) 홀수 그룹들과 
 * 짝수그룹들을 각 그룹(홀수/짝수)끼리 통합하여 올림차순으로 
 * 출력한다. 마지막으로, 각기 통합된 홀수그룹과 짝수그룹을 
 * 역시 정렬되어 있다는 사실을 고려하여 50개의 전체수를 
 * 올림차순으로 출력하는 프로그램 작성.
 *
 *	A: 50미만의 홀수		B: 50이상의 홀수
 *	C: 50미만의 짝수		D: 50이상의 짝수
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 30

void selection_sort(int array[static const ARRAY_SIZE]);
void merge_array(int a[static const ARRAY_SIZE], int b[static const ARRAY_SIZE], int merged[static ARRAY_SIZE]);

int main() {
    int rnd, i;
    int a[ARRAY_SIZE] = {0}, b[ARRAY_SIZE] = {0}, c[ARRAY_SIZE] = {0}, d[ARRAY_SIZE] = {0};
    int odd[ARRAY_SIZE] = {0}, even[ARRAY_SIZE] = {0}, all[ARRAY_SIZE] = {0};

    srand((unsigned int)time(NULL));

    for (i = 0; i < ARRAY_SIZE; i++) {
        rnd = rand() % 100 + 1;

        if (rnd < 50) {
            if (rnd % 2 == 1)
                a[i] = rnd;
            else
                c[i] = rnd;
        }
        else {
            if (rnd % 2 == 1)
                b[i] = rnd;
            else 
                d[i] = rnd;
        }
    }

    selection_sort(a);
    selection_sort(b);
    selection_sort(c);
    selection_sort(d);

    printf("ODD: ");
    merge_array(a, b, odd);
    puts("\b\b ");

    printf("EVEN: ");
    merge_array(c, d, even);
    puts("\b\b ");

    printf("TOTAL: ");
    merge_array(odd, even, all);
    puts("\b\b ");

    return 0;
}

// [static N]: N보다 같거나 큰 크기의 배열이 들어옴. (C99)
void selection_sort(int array[static ARRAY_SIZE]) {
    int i, j;
    for (i = 0; i < ARRAY_SIZE - 1; i++)
        for (j = i + 1; j < ARRAY_SIZE; j++)
            if (array[i] > array[j]) {
                array[i] = array[i] ^ array[j];
                array[j] = array[i] ^ array[j];
                array[i] = array[i] ^ array[j];
            }
}

void merge_array(int a[static const ARRAY_SIZE], int b[static const ARRAY_SIZE], int merged[static ARRAY_SIZE]) {
    int i, j, k;
    for (i = j = k = 0; i < ARRAY_SIZE || j < ARRAY_SIZE;) {
        if (a[i] == 0) 
            i++;
        else if (b[j] == 0) 
            j++;
        else if (i >= ARRAY_SIZE || (j < ARRAY_SIZE && a[i] > b[j]))
            printf("%d, ", (merged[k++] = b[j++]));
        else
            printf("%d, ", (merged[k++] = a[i++]));
    }
}