/**
 * 
 * HW 4-2
 * 
 *
 * 5명 학생의 이름(알파벳 1자)과 각 학생의 5번의 학점(A, B, C, D, F)을
 *  한 학생씩 읽어 최대학점과 최소학점(중복학점 존재) 2개로만
 * (예: A, A, B, B, F: A와 F 가 해당) 
 * 다음과 같이 평점을 계산하여 석차순으로(동일 석차 존재가능: 예:1 1 3등)
 * 각 학생의 석차, 이름 및 평균 평점과 전체학생의 평균 평점을
 * 출력하는 프로그램을 작성
 * 
 * A(4.5), 	B(3.5)	 C(2.5)	D(1.5)	F(0)
 * 
 * **출력 예시
 * 1:S 4.00    1:K 4.00     3: H 3.58   4: M 3.33   5: L 3.01
 * 
 */

#include <stdio.h>

void sort(char array[static 5]);
void sort_by(char array[static 5], char other[static 5]);
double grade_to_score(char grade);

int main() {
    char names[5];
    char grades[5][5];
    double score[5], prev;
    int i, j;

    for (i = 0; i < 5; i++) {
        printf("이름 입력 >> ");
        scanf(" %c", &names[i]);

        printf("성적 입력 >> ");
        for (j = 0; j < 5; j++)
            scanf(" %c", &grades[i][j]);

        sort(grades[i]);
        
        score[i] = (grade_to_score(grades[i][0]) + grade_to_score(grades[i][4])) / 2;
    }
    
    sort_by(score, names);
    for (i = j = 1, prev = score[0]; i <= 5; i++) {
        if (prev == score[i - 1]) {
            prev = score[i - 1];
            printf("%d:%c %.2lf\t", j, names[i - 1], score[i - 1]);
        }
        else {
            j = i;
            printf("%d:%c %.2lf\t", j, names[i - 1], score[i - 1]);
        }
    }
}

void sort(char array[static 5]) {
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = i + 1; j < 5; j++)
            if (array[i] > array[j]) {
                array[i] = array[i] ^ array[j];
                array[j] = array[i] ^ array[j];
                array[i] = array[i] ^ array[j];
            }
}

void sort_by(char array[static 5], char other[static 5]) {
    int i, j;
    for (i = 0; i < 4; i++)
        for (j = i + 1; j < 5; j++)
            if (array[i] < array[j]) {
                array[i] = array[i] ^ array[j];
                array[j] = array[i] ^ array[j];
                array[i] = array[i] ^ array[j];

                other[i] = other[i] ^ other[j];
                other[j] = other[i] ^ other[j];
                other[i] = other[i] ^ other[j];
            }
}

double grade_to_score(char grade) {
    switch (grade) {
        case 'A': return 4.5;
        case 'B': return 3.5;
        case 'C': return 2.5;
        case 'D': return 1.5;
        default: return 0.;
    }
}