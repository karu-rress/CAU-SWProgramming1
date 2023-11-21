/** 
 * 
 * HW 6-3
 * 
 * ㈜ 전역 변수 사용하지 말 것.
 *
 * [3] 21개의 자연수(61~100)를 무작위로 생성한 후(중복 수 배제)
 * 이진탐색(binary search)을 사용하여 사용자로부터 입력받은 하나의
 * 임의 자연수(61~100)가 21개 수에 존재하는지를 결정한다. 21개 수에서
 * 입력 받은 수의 위치와 위치결정(match)까지의 비교횟수를 구하는
 * 함수 binary_search()를 정의하여 main()에서 출력하는 프로그램을
 * 다음과 같이 각각 작성 (없으면(match 되지 않으면) “NOT FOUND와 비교횟수” 출력)
 *
 *	가. 반복 방식
 * 	나, 순환 방식 (binary_search() 에서 static 변수를 사용할 것
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void selection_sort(int array[static 21]);
int binary_search(int array[static const restrict 21], const int *low, const int *high, int value, int *restrict pos);

int main(void) {
    int rands[21], tmp, cmp_cnt, value, pos;
    bool contains = false;

    srand((unsigned int)time(NULL));
    for (int i = 0; i < 21; i++) {
        tmp = rand() % 40 + 61;

        for (int j = 0; j < i; j++) 
            if (rands[j] == tmp) {
                contains = true;
                break;
            }
        if (contains) {
            contains =! contains; // 함정?
            i--;
            continue;
        }

        rands[i] = tmp;
    }

    selection_sort(rands);

    printf("하나의 자연수 입력 (61 ~ 100) >> ");
    scanf("%d", &value);
    cmp_cnt = binary_search(rands, &rands[0], &rands[20], value, &pos);

    if (pos == -1) {
        printf("NOT FOUND\n");
        printf("Compared %d time(s).\n", cmp_cnt);
    }
    else {
        printf("Found %d in position %d in %d time(s).",
            value, pos, cmp_cnt);
    }

    printf("\n\nArray: \n[");
    for (int i = 0; i < 21; i++)
        printf("%d, ", rands[i]);
    puts("\b\b]\n");

    return 0;
}

void selection_sort(int array[static 21]) {
    for (int i = 0; i < 20; i++)
        for (int j = i; j < 21; j++)
            if (array[j] < array[i]) {
            array[i] ^= array[j];
            array[j] ^= array[i];
            array[i] ^= array[j];
        }
}

/**
 * @brief 이진탐색 함수 (재귀형)
 * 
 * @param array 비교할 배열. 정렬되어 있어야 함.
 * @param low 배열의 시작 주소
 * @param high 배열의 끝 주소
 * @param value 찾을 값.
 * @param pos 성공한 경우, value의 인덱스. 실패한 경우 -1
 * @return 총 비교횟수
 */
int binary_search(int array[static const restrict 21], const int *low, const int *high, int value, int *restrict pos) {
    static const int *mid = NULL;
    static int cnt = 0;
    if (low <= high) {
        cnt++;
        mid = low + (high - low) / 2;
        if (value == *mid) {
            *pos = (int)(mid - array);
            return cnt;
        }
        return (value > *mid)
            ? binary_search(array, mid + 1, high, value, pos)
            : binary_search(array, low, mid - 1, value, pos); 
    }

    *pos = -1;
    return cnt;
}
