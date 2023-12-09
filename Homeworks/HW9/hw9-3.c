/**
 * 
 * HW 9-3
 * 
 * [3] 가상대학에 지원한 9명의 지원자의
 * - 이름(5자이하, 동명이인 가능),
 * - 지원전공명(임의 2자),
 * - 점수(동일 점수 없음)
 * 를 특정순서와 무관하게 입력받아 합격자(합격자는 60점 이상)를 선정하여
 * 학번(석차 + 전공명(2자리) + 이름(첫1자)로 구성)을 부여한 후
 *   ① 합격자의 학번, 이름, 지원전공명, 점수, 등수를 학번의 알파벳 올림차순으로 출력하고,
 *   ② 각 지원전공별로 2명 이상의 합격자수를 갖는 전공명과 합격자수를 출력하는 프로그램을 작성.
 *
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char name[6];
    char major[3];
    int score;
} Applier;

typedef struct {
    char name[6];
    char major[3];
    int score;
    char id[5];
} Qualifer;

void assign_id(Qualifer *qualifiers, int cnt);

int main(void) {
    Applier appliers[9];
    int cnt = 0;

    for (int i = 0; i < 9; i++) {
        printf("지원자 이름 >> ");
        scanf("%s", appliers[i].name);
        printf("지원전공 입력 (2자리) >> ");
        scanf("%s", appliers[i].major);
        printf("점수 >> ");
        scanf("%d", &appliers[i].score);
        if (appliers[i].score >= 60)
            cnt++;
    }

    Qualifer qualifiers[cnt], tmp; // VLA
    cnt = 0;
    // 합격자 추려내기
    for (int i = 0; i < 9; i++) 
        if (appliers[i].score >= 60) {
            strcpy(qualifiers[cnt].name, appliers[i].name);
            strcpy(qualifiers[cnt].major, appliers[i].major);
            qualifiers[cnt].score = appliers[i].score;
            cnt++;
        }
    
    assign_id(qualifiers, cnt);

    // 정렬 -> 근데 안 해도 되지 않나? 어차피 이미 정렬됐을텐데
    for (int i = 0; i < cnt - 1; i++)
        for (int j = i + 1; j < cnt; j++) 
            if (strcmp(qualifiers[i].id, qualifiers[j].id) > 0) {
                tmp = qualifiers[i];
                qualifiers[i] = qualifiers[j];
                qualifiers[j] = tmp;
            }

    for (int i = 0; i < cnt; i++)
        printf("%s %s (%s) 점수: %d, 등수: %c", qualifiers[i].id,
            qualifiers[i].name, qualifiers[i].major, qualifiers[i].score, qualifiers[i].id[0]);

    
    char *majors[cnt];
    int tmpi;
    for (int i = 0; i < cnt; i++) {
        tmpi = 0;
        memset(majors, NULL, sizeof majors);
        for (int j = i + 1; !strcmp(qualifiers[j].major, qualifiers[i].major) && count(majors, cnt, qualifiers[j].major) == 0; j++) {
            majors[j] = qualifiers[j].major;
            tmpi++;
        }
        if (tmpi >= 2)
            printf("%s 전공: %d명\n", majors[i], tmpi);
    }

    return 0;
}

void assign_id(Qualifer *qualifiers, int cnt) {
    Qualifer tmp;
    for (int i = 0; i < cnt - 1; i++)
        for (int j = i + 1; j < cnt; j++) 
            if (qualifiers[i].score < qualifiers[j].score) {
                tmp = qualifiers[i];
                qualifiers[i] = qualifiers[j];
                qualifiers[j] = tmp;
            }

    for (int i = 0; i < cnt; i++) {
        sprintf(qualifiers[i].id, "%d%s%c", i + 1, qualifiers[i].major, qualifiers[i].name[0]);
    }
}

int count(const Qualifer *qualifers, int cnt, const char *str) {
    int count = 0;
    for (int i = 0; i < cnt; i++) {
        if (!strcmp(qualifers[i].major, str))
            count++;
    }
    return count;    
}
