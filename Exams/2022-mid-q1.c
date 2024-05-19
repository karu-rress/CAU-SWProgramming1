/**
 * 무작위로 서로 다른(중복 수 배제) 20개의 수를 하나씩 생성(1~50의 자연수)하면서,
 * 홀수 그룹과 짝수 그룹으로 분류한 후 각 그룹을 올림차순으로 정렬한 결과를 출력한다.
 * 출력 후 각 그룹이 정렬되어 있다는 사실을 활용(반영/고려)하여 20개 수 전체를 올림차순으로 정렬하여
 * (20개수 모두를 다시 정렬하지 말 것) 출력하는 프로그램 작성
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 20

int main() {
    int odd[ARRAY_SIZE] = {0,}, even[ARRAY_SIZE] = {0,};
    int i, j, temp, has_value = 0;

    // 난수 시드값 초기화
    srand((unsigned int)time(NULL));

    for (i = 0; i < ARRAY_SIZE; i++) {
        temp = rand() % 50 + 1; // [1, 51)

        for (j = 0; j < ARRAY_SIZE; j++)
            if (temp == odd[j]) {
                has_value = 1;
                break;
            }
        for (j = 0; j < ARRAY_SIZE; j++)
            if (temp == even[j]) {
                has_value = 1;
                break;
            }

        if (has_value == 1) {
            i--;
            has_value = 0;
            continue;
        }

        if (temp % 2 == 0) 
            even[i] = temp;
        else 
            odd[i] = temp;
    }

    for (i = 0; i < ARRAY_SIZE; i++) 
        for (j = i + 1; j < ARRAY_SIZE; j++) 
            if (odd[i] >= odd[j]) {
                temp = odd[i];
                odd[i] = odd[j];
                odd[j] = temp;
            }
    
    printf("홀수 그룹: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        if (odd[i] == 0)
            continue;
        printf("%d ", odd[i]);
    }
    printf("\n");
        
    for (i = 0; i < ARRAY_SIZE; i++) 
        for (j = i + 1; j < ARRAY_SIZE; j++) 
            if (even[i] >= even[j]) {
                temp = even[i];
                even[i] = even[j];
                even[j] = temp;
            }

    printf("짝수 그룹: ");
    for (i = 0; i < ARRAY_SIZE; i++) {
        if (even[i] == 0)
            continue;
        printf("%d ", even[i]);
    }
    printf("\n");

    printf("전체 그룹: ");
    for (i = 0; odd[i] == 0; i++);
    for (j = 0; even[j] == 0; j++);
    while (i < ARRAY_SIZE || j < ARRAY_SIZE) {
        if (i >= ARRAY_SIZE) 
            printf("%d ", even[j++]);
        
        else if (j >= ARRAY_SIZE) 
            printf("%d ", odd[i++]);
        
        else if (odd[i] < even[j]) 
            printf("%d ", odd[i++]);
        
        else 
            printf("%d ", even[j++]);
        
    }
    printf("\n");

    return 0;
}