/** 
 * 
 * HW 7-1
 * 
 * [1] 10명의 학생이 3번의 시험을 보았다. 
 * 각 학생별로 이름(1자)을 입력 받고(이름 한자 입력후 리턴return key)
 * 3번의 시험 점수(90~100)는 무작위수로 생성하여 중간점수를
 * 해당 학생의 최종 점수로 한다(mid_cal() 함수는 한 학생의 중간점수를 구함).
 * 
 * 10명 학생의 3번 점수와 최종 점수를 출력한 후, 10명 학생의 전체평균을
 * 구하여(avg_cal() 함수는 전체평균을 구함) 석차순으로
 * (rank() 함수는 정렬하여 석차를 구함, (동일 석차 존재))
 * 10명 각 학생의 석차, 이름, 최종점수와 전체 학생의 평균을 출력하는 프로그램을 작성 
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mid_cal(int score[static const 3]);
double avg_cal(int score[static const 10]);
void rank(int score[static 10], char name[static 10], int ranks[static 10]);

int main(void) {
    char names[10] = {'\0',};
    int scores[10][3] = {0,}, fscore[10] = {0,}, ranks[10] = {0,};

    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++) {
        scanf(" %c", &names[i]);
        for (int j = 0; j < 3; j++) 
            scores[i][j] = rand() % 11 + 90;
        fscore[i] = mid_cal(scores[i]);
    }

    for (int i = 0; i < 10; i++)
        printf("학생 %c: [%d, %d, %d] => %d\n",
            names[i], scores[i][0], scores[i][1], scores[i][2], fscore[i]);
    puts("");

    rank(fscore, names, ranks);

    for (int i = 0; i < 10; i++) 
        printf("[%2d위] 이름: %c, 최종점수: %d\n", ranks[i], names[i], fscore[i]);
    printf("\n>> 전체 학생의 평균: %.2f\n\n", avg_cal(fscore));

    return 0;
}

int mid_cal(int score[static const 3]) {
    // 선택정렬을 이용할 수 있지만, 여기선 개수가 작으므로
    // 다중 if문을 사용하여 비교함.
    if (score[0] <= score[1] && score[1] <= score[2])
        return score[1];
    if (score[1] <= score[2] && score[2] <= score[0])
        return score[2];
    return score[0];
}

double avg_cal(int score[static const 10]) {
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum += score[i];
    return sum / 10.;
}

void rank(int score[static 10], char name[static 10], int ranks[static 10]) {
    // 1. Sort
    for (int i = 0; i < 9; i++)
        for (int j = i + 1; j < 10; j++) 
            if (score[i] < score[j]) {
                score[i] ^= score[j];
                score[j] ^= score[i];
                score[i] ^= score[j];

                name[i] ^= name[j];
                name[j] ^= name[i];
                name[i] ^= name[j];
            }
            
    // 2. Assign Rank
    int current = INT_MAX;
    
    for (int i = 0; i < 10; i++) {
        if (current == score[i]) 
            ranks[i] = ranks[i - 1];
        else {
            ranks[i] = i + 1;
            current = score[i];
        }
    }
}