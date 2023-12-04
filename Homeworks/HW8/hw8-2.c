/** 
 * 
 * HW 8-2
 * 
 * [2] 학생 5명의 학과명(10자 미만, 모두 동일/상이 가능)과 학생이름(10자 미만, 모두 상이)을
 * 학과명 순서와 상관없이 입력받아 학과명 올림차순으로 모든 학생들의 학과명과 학생이름을
 * 출력한 후(동일 학과내에서는 학생이름 순으로), 학과명 올림차순으로 학과명과
 * 해당학과 학생수를 출력하는 프로그램을 작성
 *
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STU_NO 5

void swap(char str1[static restrict 10], char str2[static restrict 10]);
int count(char array[static const STU_NO][10], const char *str);
bool contains(char array[static const STU_NO][10], char string[10]);
inline bool is_empty(char array[static 10]) { return array == NULL || *array == '\0'; }

int main(void) {
    char depts[STU_NO][10] = {""}, names[STU_NO][10] = {""}, depts_set[STU_NO][10] = {"","","","",""};
    int cmp;

    for (int i = 0; i < STU_NO; i++) {
        printf("[%d] 학과명: ", i + 1);
        scanf("%s", depts[i]);
        printf("[%d] 이름: ", i + 1);
        scanf("%s", names[i]);
    }

    for (int i = 0; i < STU_NO - 1; i++) {
        for (int j = i + 1; j < STU_NO; j++) {
            if ((cmp = strcmp(depts[i], depts[j])) > 0) {
                swap(depts[i], depts[j]);
                swap(names[i], names[j]);
            }
            else if (cmp == 0 && strcmp(names[i], names[j]) < 0) 
                swap(names[i], names[j]);
        }
    }
    puts("");

    for (int i = 0; i < STU_NO; i++) {
        printf("학과: %s\t\t이름: %s\n", depts[i], names[i]);
        if (!contains(depts_set, depts[i]))
            strcpy(depts_set[i], depts[i]);
    }
    puts("");

    for (int i = 0; i < STU_NO; i++) {
        if (!is_empty(depts_set[i])) {
            printf("%s 학과의 학생 수: %d명\n", depts_set[i], count(depts, depts_set[i]));
        }
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

bool contains(char array[static const STU_NO][10], char string[10]) {
    for (int i = 0; i < 5; i++) 
        if (strcmp(array[i], string) == 0)
            return true;
    return false;
}