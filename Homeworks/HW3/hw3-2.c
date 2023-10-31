/**
 * 
 * HW 3-2
 * 
 *
 * 5명 학생이 각각 3번의 시험을 보았다. 각 학생별로 3개 점수(0~100)를 읽어 들여
 * 다음과 같이 3개의 점수를 학점으로(A,B,C,D,F) 계산한 후, 
 * 최상위학점과 최하위학점을(중복학점 존재) 제외한 학점으로 
 * 각 학생의 최종 학점을 정한다. 각 학생의 최종 학점으로 다음과 같이
 * 평점을 계산하여 전체 학생의 평균 평점을 출력하는 프로그램을 작성
 *	
 *	90이상: A, 	80이상: B,	 70이상: C,	60이상: D, 	60미만: F학점
 *	A(4.5), 	B(3.5)	 C(2.5)	D(1.5)	F(0) 
 */

#include <stdio.h>

int main() {
    int i, j, k;
    char grade[3], total_grade[5];
    double sum = .0;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &k);
            switch (k / 10) {
            case 10:
            case 9:
                grade[i] = 'A';
                break;
            case 8:
                grade[i] = 'B';
                break;
            case 7:
                grade[i] = 'C';
                break;
            case 6:
                grade[i] = 'D';
                break;
            default:
                grade[i] = 'F';
                break;
            }

            
        }

        // 0이 중간인 경우, 1이 중간인 경우, 2가 중간인 경우
        if (grade[0] <= grade[1] && grade[1] <= grade[2])
            total_grade[i] = grade[1];
        else if (grade[1] <= grade[2] && grade[2] <= grade[0])
            total_grade[i] = grade[2];
        else
            total_grade[i] = grade[0];

        switch (total_grade[i]) {
            case 'A':
                sum += 4.5;
                break;
            case 'B':
                sum += 3.5;
                break;
            case 'C':
                sum += 2.5;
                break;
            case 'D':
                sum += 1.5;
                break;
            default:
                break;
        }
    }

    printf("%.2lf", sum / 5);

    return 0;
}