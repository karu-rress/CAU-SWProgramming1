/**
 * 
 * HW5-4.c
 *
 * 
 * [4]  무작위로 20개의 자연수(0~99)를 생성하여 다음과 같이
 * 10개의 그룹으로(A~J) 분류하여 그룹명과 멤버수를 출력한 후,
 * 멤버수가 최대인 그룹(들)과 최소 그룹(들)의 그룹명과 멤버수를
 * 각각 출력하는 프로그램 작성 (최대나 최소 멤버수가 동일한
 * 그룹들은 그룹명의 알파벳 올림차순으로 모두 출력)
 *
 *    0~9: A   10~19: B   20~29: C  .....   90~99: J
 *
 * 출력 예시:
 * ....
 * Max: B 3     D 3       
 * Min: A 1   E 1   J 1
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_max_min(int array[static 10]);

int main(void) {
    int groups[10] = {0,};

    srand((unsigned int)time(NULL));

    for (int i = 0; i < 20; i++) {
        int tmp = rand() % 100;
        groups[tmp / 10]++;
    }

    for (int i = 0; i < 10; i++) {
        printf("Group %c: %d items\n", 65 + i, groups[i]);
    }

    print_max_min(groups);

    return 0;
}

void print_max_min(int array[static 10]) {
    int max = 0, min = 20;
    for (int i = 0; i < 10; i++) {
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];
    }

    printf("Max: ");
    for (int i = 0; i < 10; i++)
        if (array[i] == max)
            printf("%c %d\t", 65 + i, array[i]);
    
    printf("\nMin: ");
    for (int i = 0; i < 10; i++)
        if (array[i] == min)
            printf("%c %d\t", 65 + i, array[i]);
}