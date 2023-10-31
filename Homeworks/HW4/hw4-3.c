/**
 * 
 * HW 4-3
 * 
 *
 * A, B, C, D, F 로 평가하는 국어와 수학 과목에서 
 * 5명 학생들이 각 과목에서 5번의 시험을 보았다. 
 * 각 과목의 최종 평가 등급은 5번 시험의 등급에서 
 * 제일 많이 받은 등급으로 결정되며 등급갯수가 같으면 
 * 상위등급 (ABBCC=>B)으로 결정한다. 각 등급을 
 * 아래와 같이 점수로 환산할 때 과목별로 각 학생들의 
 * 이름(1자)과 5번의 성적을 입력받아 각 학생의 학생이름, 
 * 2과목 전체석차와 평균점수를 소수 둘째 자리까지 
 * 석차순으로 출력하는 프로그램을 작성(동일 성적은 없음)
 * 
 *			A:95	B:85   C:75 	D:65	 F:0
 *
 */

#include <stdio.h>

#define KOR 0
#define MATH 1

void sort(char array[static 5]);
void sort_by(double array[static 5], char other[static 5]);
int grade_to_score(char grade);
char most_frequent(char array[static 5]);

int main() {
    char names[5];
    char grades[5][2][5];
    int score[2][5];
    double avg_score[5];
    int i, j;

    for (i = 0; i < 5; i++) {
        printf("이름 입력 >> ");
        scanf(" %c", &names[i]);

        printf("국어 성적 입력 >> ");
        for (j = 0; j < 5; j++)
            scanf(" %c", &grades[i][KOR][j]);

        printf("수학 성적 입력 >> ");
        for (j = 0; j < 5; j++)
            scanf(" %c", &grades[i][MATH][j]);

        score[KOR][i] = grade_to_score(most_frequent(grades[i][KOR]));
        score[MATH][i] = grade_to_score(most_frequent(grades[i][MATH]));
        avg_score[i] = (score[KOR][i] + score[MATH][i]) / 2;
    }
    
    sort_by(avg_score, names);
    for (i = 1; i <= 5; i++)
        printf("%d:%c %.2lf\t", i, names[i - 1], avg_score[i - 1]);
    return 0;
}

void sort(char array[static 5]) {
    for (int i = 0, j; i < 4; i++)
        for (j = i + 1; j < 5; j++)
            if (array[i] > array[j]) {
                array[i] = array[i] ^ array[j];
                array[j] = array[i] ^ array[j];
                array[i] = array[i] ^ array[j];
            }
}

void sort_by(double array[static 5], char other[static 5]) {
    int i, j;
    double temp;
    for (i = 0; i < 4; i++)
        for (j = i + 1; j < 5; j++)
            if (array[i] < array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;

                other[i] = other[i] ^ other[j];
                other[j] = other[i] ^ other[j];
                other[i] = other[i] ^ other[j];
            }
}

int grade_to_score(char grade) {
    switch (grade) {
        case 'A': return 95;
        case 'B': return 85;
        case 'C': return 75;
        case 'D': return 65;
        default: return 0;
    }
}

char most_frequent(char array[static 5]) {
    int a = 0, b = 0, c = 0, d = 0, f = 0, i, max;
    for (i = 0; i < 5; i++) {
        switch (array[i]) {
            case 'A': a++; break;
            case 'B': b++; break;
            case 'C': c++; break;
            case 'D': d++; break;
            case 'F': f++; break;
        }
    }

    max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    if (f > max) max = f;

    if (max == a) return 'A';
    if (max == b) return 'B';
    if (max == c) return 'C';
    if (max == d) return 'D';
    else return 'F';
}