/**
 * 
 * HW 9-1
 * 
 * [1] 6개의 축구팀들이 다음 규칙에 따라 결정된 3 경기를 한다. 
 * 6개 축구팀 이름(10자 미만), 예선전 승무패수(예선전 경기수는 모두 동일하며 임의로 함),
 * 홈구장명(10자 미만)을 입력 받아
 *    ① 팀의 순위, 팀이름, 총득점수를 출력한 후
 *    ② 각 경기의 대진 팀들의 이름 및 총점수와 경기구장 이름을 출력하는 프로그램을 작성.
 * 
	a. 승: 2점, 무: 1점, 패: 0점
	b. 승/무/패 수 모두가 동일한 팀은 없으며 총득점수가 높은 팀이 상위이며, 
	   동점인 경우 승수, 무승부수 순으로 수가 많은 팀이 상위이다.
	c 1/6, 2/5, 3/4위 팀이 3경기를 하며 경기구장은 상위 팀의 홈구장이다.
 *
*/

#include <stdio.h>

// 전체 게임 수를 임의로 10으로 결정
#define TOTAL_GAMES 10

typedef struct {
    char name[10];
    int wins;
    int loses;
    char home[10];
} team;

int get_score(const team* t);
int scorecmp(const team* t1, const team* t2);
void swap(team* t1, team* t2);
void sort_teams(team teams[static 6]);

int main(void) {
    team teams[6];

    for (int i = 0; i < 6; i++) {
        printf("축구팀 이름 >> ");
        scanf("%s", teams[i].name);
        printf("예선전 승무패수 (공백 구분) >> ");
        scanf("%d%d", &teams[i].wins, &teams[i].loses);
        printf("홈구장명 >> ");
        printf("%s", teams[i].home);
    }

    sort_teams(teams);

    for (int i = 0; i < 6; i++) 
        printf("[%d위] %s: %d점\n", i + 1, teams[i].name, get_score(&teams[i]));
    puts("");


    puts("제 1 경기 ======");
    printf("%s (%d점) vs %s (%d점) => 경기구장: %s",
        teams[0].name, get_score(&teams[0]), teams[5].name, get_score(&teams[5]), teams[0].home);

    puts("제 2 경기 ======");
    printf("%s (%d점) vs %s (%d점) => 경기구장: %s",
        teams[1].name, get_score(&teams[1]), teams[4].name, get_score(&teams[4]), teams[1].home);

    puts("제 3 경기 ======");
    printf("%s (%d점) vs %s (%d점) => 경기구장: %s",
        teams[2].name, get_score(&teams[2]), teams[3].name, get_score(&teams[3]), teams[2].home);

    return 0;
}

int get_score(const team* t) {
    int tie = TOTAL_GAMES - t->wins - t->loses;
    return 2*t->wins + tie;
}

/// @brief compare two teams' score
/// @return -1 if t1 < t2, 0 if t1 == t2, otherwise 1
int scorecmp(const team* t1, const team* t2) {
    int score1 = get_score(t1), score2 = get_score(t2);
    if (score1 < score2)
        return -1;
    else if (score1 == score2)
        return 0;
    else
        return 1;
}

void swap(team* t1, team* t2) {
    team tmp;
    tmp = *t1;
    *t1 = *t2;
    *t2 = tmp;
}

void sort_teams(team teams[static 6]) {
    int cmp;
    for (int i = 0; i < 5; i++)
        for (int j = i + 1; j < 6; j++) {
            cmp = scorecmp(&teams[i], &teams[j]);
            if (cmp < 0 ||
                (cmp == 0 && teams[i].wins < teams[j].wins) ||
                (cmp == 0 && teams[i].wins == teams[j].wins && teams[i].loses > teams[j].loses))
                swap(&teams[i], &teams[j]);
        }

}