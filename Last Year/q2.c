/**
 * 무작위로 서로 다른(중복 수 배제) 20개의 점수를 (1~100의 자연수) 생성한 후,
 * 올림차순으로 정렬하여 출력한다.
 * 출력 후에 임의의 점수를 사용자로부터 입력 받아 20개 점수가 정렬되어 있다는
 * 사실을 활용(반영/고려)하여 효율적으로 해당 입력 점수의 등수를 출력하는
 * (입력받은 점수가 무작위로 생성한 20개 점수에 없으면 "NOT FOUND" 출력)프로그램 작성.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 20

int main() {
    int arr[ARRAY_SIZE];
    int i, j, input, grade = 1, temp, has_value;

    srand((unsigned int)time(NULL));
    for (i = 0; i < ARRAY_SIZE; i++) {
        temp = rand() % 100 + 1; // [1, 101)

        for (j = 0; j < ARRAY_SIZE; j++)
            if (temp == arr[j]) {
                has_value = 1;
                break;
            }
            
        if (has_value == 1) {
            i--;
            has_value = 0;
            continue;
        }

        arr[i] = temp;
    }

    for (i = 0; i < ARRAY_SIZE; i++)
        for (j = i + 1; j < ARRAY_SIZE; j++)
            if (arr[i] >= arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

    printf("점수 목록: ");
    for (i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("점수 입력 >> ");
    scanf("%d", &input);

    for (i = 0; i < ARRAY_SIZE; i++)
        if (input == arr[i])
            break;
    if (i > 19)
        printf("NOT FOUND\n");
    else {
        printf("%d점은 %d등입니다.", input, 20 - i);
    }

    return 0;
}