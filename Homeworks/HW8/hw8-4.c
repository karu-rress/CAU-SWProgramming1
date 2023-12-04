/** 
 * 
 * HW 8-4
 * 
 * [4] 10명 학생이 소속한 임의의 학과명(20자 미만, 동일 소속 학과 존재)과
 * 이름(20자 미만, 동명이인 존재) 입력받아 다음을 올림차순으로 출력하는 프로그램을 작성
   ① 학과별로(이름순) 학과명을 먼저 출력한 후 소속학생 이름만(이름순)
   ② 학과별로(이름순) 학과명과 해당학과내 이름이 서로 다른 학생의 수
   ③ 전체학생(10명) 이름별로(이름순) 이름과 해당 이름의 수

 *
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STU_NO 10

void swap(char str1[static restrict 20], char str2[static restrict 20]);
int count(char array[static const STU_NO][20], const char *str);
void sort_by_dept(char[static STU_NO][20], char[static STU_NO][20]);
void print_name_by_dept(char[static const STU_NO][20], char[static const STU_NO][20]);
void print_count_by_dept(char[static const STU_NO][20], char[static const STU_NO][20]);
void print_count_name(char names[static STU_NO][20]);

int main(void) {
    char depts[STU_NO][20] = {""}, names[STU_NO][20] = {""};

    // 입력받기
    for (int i = 0; i < STU_NO; i++) {
        printf("[%2d] 학과명: ", i + 1);
        scanf("%s", depts[i]);
        printf("[%2d] 이름: ", i + 1);
        scanf("%s", names[i]);
    }
    sort_by_dept(depts, names);

    // 1번문제 (학과별: 학과명 -> 소속학생)
    print_name_by_dept(depts, names);

    // 2번문제 (학과별: 학과명 -> 서로 다른 이름 수)
    print_count_by_dept(depts, names);

    // 3번문제 (이름별: 이름명 -> 해당 이름의 수)
    print_count_name(names);

    return 0;
}

void swap(char str1[static restrict 20], char str2[static restrict 20]) {
    char buf[20];
    strcpy(buf, str1);
    strcpy(str1, str2);
    strcpy(str2, buf);
}

int count(char array[static const STU_NO][20], const char *str) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (!strcmp(array[i], str))
            count++;
    }
    return count;    
}

void sort_by_dept(char depts[static STU_NO][20],
                            char names[static STU_NO][20]) {
    int cmp, i, j;
    for (i = 0; i < STU_NO - 1; i++) {
        for (j = i + 1; j < STU_NO; j++) {
            if ((cmp = strcmp(depts[i], depts[j])) > 0) {
                swap(depts[i], depts[j]);
                swap(names[i], names[j]);
            }
            else if (cmp == 0 && strcmp(names[i], names[j]) < 0) 
                swap(names[i], names[j]);
        }
    }
}

void print_name_by_dept(char depts[static const STU_NO][20],
                            char names[static const STU_NO][20]) {
    int i, j;
    for (i = 0; i < STU_NO; i = j) {
        printf("\n%s 학과: ", depts[i]);
        for (j = i; !strcmp(depts[j], depts[i]); j++)
            printf("%s, ", names[j]);
    }
}

void print_count_by_dept(char depts[static const STU_NO][20],
                            char names[static const STU_NO][20]) {
    char name_set[STU_NO][20];
    int i, j, cnt;
    for (i = 0; i < STU_NO; i = j) {
        cnt = 0;
        memset(name_set, '\0', sizeof name_set);        
        for (j = i; !strcmp(depts[j], depts[i]) && count(name_set, names[j]) == 0; j++) {
            strcpy(name_set[j], names[j]);
            cnt++;
        }
        printf("\n%s 학과: %d명", depts[i], cnt);        
    }    
}

void print_count_name(char names[static STU_NO][20]) {
    int count;
    for (int i = 0; i < STU_NO - 1; i++) {
        for (int j = i + 1; j < STU_NO; j++) 
            if (strcmp(names[i], names[j]) > 0) 
                swap(names[i], names[j]);
    }

    for (int i = 0; i < STU_NO; i++) {
        count = 0;
        if (!strcmp(names[i], names[i + 1])) {
            count++;
            continue;
        }
        printf("%s : %d명\n", names[i], count + 1);
    }
}