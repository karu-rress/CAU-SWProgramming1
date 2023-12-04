/** 
 * 
 * HW 7-3
 * 
 * 4개 학과(I, C, M, E) 학생 10명의 학과명과 학생이름(1자)을
 * 학과명 순서와 상관없이 입력받아 각각 1차원 배열에 저장한 후,
 * 학생들을 학과명의 올림차순으로(동일학과내는 학생이름순으로) 정렬하여
 * ⓵학과별로 학과명을 출력한 후 해당학과 학생이름들을 출력한다.
 * 다음에 학과별로 학생이름이 정렬된 사실을 이용하여 (학과끼리 학생이름순으로
 * merge 방식 적용하여) 
 * ⓶ 4개 학과 전체 학생이름순으로 학생이름과 소속학과명을 출력하는 프로그램을 작성
 * #출력 예시
 * ⓵
 * dept: C
 * A J W
 * dept: I
 * K X
 * ......
 * ⓶
 * A C
 * J  C
 * K  I
 * .....
*/

#include <stdio.h>

void sort(char depts[static 10], char names[static 10]);
void swap(char *restrict c1, char *restrict c2);

int main(void) {
    char depts[10], names[10];

    for (int i = 0; i < 10; i++) {
        scanf(" %c %c", &depts[i], &names[i]);
    }

    sort(depts, names);

    return 0;
}

void sort(char depts[static 10], char names[static 10]) {
    for (int i = 0; i < 9; i++)
        for (int j = i + 1; j < 10; j++)
            if (depts[i] > depts[j]) {
                swap(&depts[i], &depts[j]);
                swap(&names[i], &names[j]);
            }
            else if (depts[i] == depts[j] && names[i] > names[j]) {
                swap(&names[i], &names[j]);
            }
}

void swap(char *restrict c1, char *restrict c2) {
    *c1 ^= *c2;
    *c2 ^= *c1;
    *c1 ^= *c2;
}