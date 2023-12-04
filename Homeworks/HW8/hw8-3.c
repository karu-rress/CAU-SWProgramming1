/** 
 * 
 * HW 8-3
 * 
 * [3] 학생 10명의 학과명(2~9자, 모두 동일/상이 가능)과 학생이름(2~9자,
 * 동일학과에는 동명이인 없음)을 입력 받아 학생이름 올림차순에 따라 학번을
 * 부여한다. 학번은 2개 부분(학과 코드(학과명 처음 2자, 다른 학과에
 * 동명이인이 존재하는 경우만 포함))+학생이름순번(동명이인은 같은 순번 부여,
 * 예 KS02 MS02)으로 구성되며 최소 2자리(예:01)이며 최대 4자리(예:IS10)이다
 * (동명이인은 학과코드를 추가하여 4자리로 구분함). 
 * 학번, 학생이름과 학과명을 학번순으로 출력하는 프로그램을 작성
* 출력 예시:
01
03
IS02
KS02
.....
 *
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STU_NO 10

void swap(char str1[static restrict 10], char str2[static restrict 10]);
int count(char array[static const STU_NO][10], const char *str);

int main(void) {
    char depts[STU_NO][10] = {""}, names[STU_NO][10] = {""}, id[STU_NO][5] = {""};
    int idx = 1;
    bool is_duplicate = false;

    // 입력받기
    for (int i = 0; i < STU_NO; i++) {
        printf("[%2d] 학과명: ", i + 1);
        scanf("%s", depts[i]);
        printf("[%2d] 이름: ", i + 1);
        scanf("%s", names[i]);
    }

    // 정렬
    for (int i = 0; i < STU_NO - 1; i++) {
        for (int j = i + 1; j < STU_NO; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                swap(names[i], names[j]);
                swap(depts[i], depts[j]);
            } // 학생 이름이 같고 학과가 다른 경우엔 순서를 매기지 않음.
        }
    }
    puts("");
    
    // 학번 생성 및 출력
    for (int i = 0; i < STU_NO; i++) {
        if (count(names, names[i]) > 1) {
            if (!is_duplicate)
                is_duplicate = true;
            strncpy(&id[i][0], depts[i], 2);    // 첫 두 문자만 복사
            sprintf(&id[i][2], "%02d", idx);    // 뒤는 숫자로 채움
        }
        else {
            if (is_duplicate) {
                is_duplicate = false;
                idx++;
            }
            sprintf(id[i], "%02d", idx++);      // itoa()는 비표준 함수
        }
        printf("[%4s] 이름: %s\t\t학과: %s\n", id[i], names[i], depts[i]);
    }
    return 0;
}

void swap(char str1[static restrict 10], char str2[static restrict 10]) {
    char buf[10];
    strcpy(buf, str1);
    strcpy(str1, str2);
    strcpy(str2, buf);
}

int count(char array[static const STU_NO][10], const char *str) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (!strcmp(array[i], str))
            count++;
    }
    return count;    
}
