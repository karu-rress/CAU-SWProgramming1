/**
 * 
 * HW 9-2
 * 
 * [2] 5명 학생의 이름(5자미만)과 3번의 시험점수(0~100)를 입력받아
 * 처리하기 위해 각 학생별로 함수 read_data()와 (데이터를 입력만 받는 함수)
 * 함수 calculate()를(평균과 총점을 계산하고 합격여부만 결정, 평균 60이상 합격)
 * 정의하여 호출한다. 다음에 합격생 전체에 대해 함수 ranking()을
 * (석차만 계산/동일석차 없음) 정의하여 호출한 후 합격생의 석차, 이름, 총점, 평균을
 * 석차순으로 출력하는 프로그램을 작성.
*/

#include <stdio.h>
#include <limits.h>

typedef struct {
    char name[5];
    int score[3];
    int sum;
    double average;
    _Bool qualified;
    int rank;
} Student;

void read_data(Student* students);
void calculate(Student* students);

int main(void) {
    Student students[5], tmp;
    int qualifieds = 0;

    read_data(students);
    calculate(students);
    ranking(students);

    for (int i = 0; i < 4; i++) 
        for (int j = i + 1; j < 5; j++) 
            if (students[i].rank > students[j].rank) {
                tmp = students[i];
                students[i] = students[j];
                students[j] = tmp;
            }
    
    for (int i = 0; i < 5; i++) {
        if (students[i].average < 60.0)
            break;
        printf("%d위: %s (총점: %d, 평균: %.2f)\n",
            students[i].rank, students[i].name, students[i].sum, students[i].average);
    }

    return 0;
}

void read_data(Student* students) {
    for (int i = 0; i < 5; i++) {
        printf("학생 이름 입력 >> ");
        scanf("%s", students[i].name);
        printf("3번의 시험 점수 입력 (공백으로 구분) >> ");
        scanf("%d%d%d", &students[i].score[0], &students[i].score[1], &students[i].score[2]);
    }
}

void calculate(Student* students) {
    for (int i = 0; i < 5; i++) {
        students[i].sum = students[i].score[0] + students[i].score[1] + students[i].score[2];
        students[i].average = students[i].sum / 3.0;
        students[i].qualified = students[i].average >= 60.0;
    }
}

void ranking(Student* students) {
    double scores[5], tmp;

    for (int i = 0; i < 5; i++)
        scores[i] = students[i].average;

    for (int i = 0; i < 4; i++) 
        for (int j = i + 1; j < 5; j++) 
            if (scores[i] < scores[j]) {
                tmp = scores[i];
                scores[i] = scores[j];
                scores[j] = tmp;
            }
    
    for (int i = 0; i < 5; i++) {
        double tmp = students[i].average;
        for (int j = 0; j < 5; j++)
            if (tmp == scores[j])
                students[i].rank = j + 1;
    }
}
