/** 
 * 
 * HW 7-2
 * 
 * 5명 학생의 이름(1자), 학과명(1자), 학번(3자리 자연수),
 * 국어, 영어, 수학 성적(0~100)을 한 명을 한줄에 입력 받아
 * 각 과목별로 과목명(Korean, English, Math)을 출력한 후,
 * 해당 과목의 각 학생의 과목 석차와 이름, 학번, 학과명, 해당 점수를
 * 석차순으로 출력하는 프로그램을 작성(총점이 같으면 동일 등수로 출력: 1,2,2,2,5)
 * 
 * 입력 예시
 * H P 777 92 90 88
 * 출력 예시:
 * Korean:
 * 1 S 123 M 96
 * 2 H 777 P 92
 * ....
 * Math:
 * 1 H 777 P 90
 * 1 K 342 G 90
 * ......
 *
*/

#include <stdio.h>

int main(void) {
    char names[5], depts[5];
    int id[5], scores[5][3];

    for (int i = 0; i < 5; i++) {
        scanf("%c %c %d %d %d %d", &names[i], &depts[i], &id[i], &scores[i][0], &scores[i][1], &scores[i][2]);
    }

    puts("Korean:");

    puts("English:");

    puts("Math:");
    return 0;
}