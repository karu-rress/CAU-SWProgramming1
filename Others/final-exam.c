// 문제에서 주어진 조건에 따라 func1, func2, func3를 각각 만들고
// 전체 코드를 작성하는 문제.
// 모든 입출력은 main()에서 진행함.
// 전역변수 사용 금지.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char name[3];
    char team[3];
    int money;
    int group;
} Player;

void func1(const char* id, int money, int *group, char *name, char *team);
void func2(const char* name, const char* team, int money, int group, Player *player);
void sort_by_group(Player plyaers[]);
void func3(Player players[], int total_team[]);

int main(void) {
    Player players[20];
    int money, group, total_team[10] = {0,}, total_count[10] = {0,}, total_money[10] = {0,};
    char buf[5], name[3], team[3];
    bool printed = false;

    for (int i = 0; i < 20; i++) {
        printf("식별코드와 연봉을 입력하세요: ");
        scanf("%s%d", buf, &money);
        func1(buf, money, &group, name, team);
        func2(name, team, money, group, &players[i]);
    }

    sort_by_group(players);
    func3(players, total_team);

    for (int i = 0; i < 20; i++) {
        total_count[players[i].group]++;
        total_money[players[i].group] += players[i].money;
    }

    for (int i = 0; i < 20; i++) {
        if (printed == false) {
            printed = true;
            group = players[i].group;
            printf("그룹 %d\n", group);
            printf("  %d players,\n", total_count[group]);
            printf("  %d 연봉, \n", total_money[group]);
            printf("  %d teams, \n", total_team[group]);
            printf("  플레이어: ");
        }
        printf("%s, ", players[i].name);

        if (players[i].group != players[i + 1].group) {
            puts("\n");
            printed = false;
        }
    }

    return 0;
}

// 식별자와 연봉을 받아 그룹, 이름, 팀을 구함
void func1(const char* id, int money, int *group, char *name, char *team) {
    *group = money / 100;
    sprintf(name, "%2s", id);
    sprintf(team, "%s", &id[2]);
}

// 값을 저장
void func2(const char* name, const char* team, int money, int group, Player *player) {
    strcpy(player->name, name);
    strcpy(player->team, team);
    player->money = money;
    player->group = group;
}

void sort_by_group(Player players[]) {
    Player tmp;
    for (int i = 0; i < 19; i++) {
        for (int j = i + 1; j < 20; j++) {
            if (players[i].group > players[j].group) {
                tmp = players[i];
                players[i] = players[j];
                players[j] = tmp;
            }
        }
    }
}

// 각 그룹 별 서로 다른 팀 개수 구함
void func3(Player players[], int total_team[]) {
    bool team[] = {false, false, false, false, false};

    for (int i = 0; i < 20; i++) {
        if (strcmp(players[i].team, "AA") == 0)
            team[0] = true;
        else if (strcmp(players[i].team, "BB") == 0)
            team[1] = true;
        else if (strcmp(players[i].team, "CC") == 0)
            team[2] = true;
        else if (strcmp(players[i].team, "DD") == 0)
            team[3] = true;
        else
            team[4] = true;


        if (players[i].group != players[i + 1].group) {
            total_team[players[i].group] = 
                (int)team[0] + (int)team[1] + (int)team[2] + (int)team[3] + (int)team[4];

            memset(team, false, sizeof team);
        }
    }
}