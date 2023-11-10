/**
 * 
 * HW5-2.c
 *
 * 
 * [2] 5줄의 텍스트에 대하여 처리한다. line_scan() 함수
 * (한 줄을 읽어 단어 갯수와 평균 단어길이를 (소수 2째자리) 구하는 함수)를
 * 호출한 후 단어 갯수의 내림차순으로(sorting() 함수를 호출하여 정렬)
 * 각 줄의 줄번호, 단어 갯수, 평균 단어길이를 출력하고(갯수가 같으면 평균단어
 * 길이, 길이가 같으면 큰 줄번호 내림차순으로 출력), 전체 단어 개수 및
 * 평균 길이를 출력하는 프로그램을 작성
 * ㈜ 한 줄의 입력 문자는 blank, tab, 알파벳으로 구성되며 이들 간에
 * 나타나는 순서와 빈도수는 제한 없음
 * 
 */

#include <stdio.h>

#define INT 0
#define DOUBLE 1
#define BUFF_SIZE 256

void line_scan(int *restrict word_cnt, double *restrict avg_len);
void sorting(int word_counts[static restrict 5], double average_length[static restrict 5], int line_number[static restrict 5]);
void swap(void *restrict v1, void *restrict v2, int TYPE);
int sum_word(int word_counts[static 5]);
double total_avg_len(int word_counts[static restrict 5], double average_length[static restrict 5]);

int main(void) {
    int word_counts[5], line_number[5];
    double average_length[5];

    for (int i = 0; i < 5; i++) {
        line_scan(&word_counts[i], &average_length[i]);
        line_number[i] = i + 1;
    }

    sorting(word_counts, average_length, line_number);
 
    for (int i = 0; i < 5; i++) {
        printf("Line %d: %d word(s), avg len %.2f\n", line_number[i], word_counts[i], average_length[i]);
    }

    printf("\nTotal: %d words, avg len %.2f\n", sum_word(word_counts), total_avg_len(word_counts, average_length));

}

void line_scan(int *restrict word_cnt, double *restrict avg_len) {
    char buffer[BUFF_SIZE];
    int ch;
    int word_len = 0, total_len = 0, i = 0;
    _Bool state;
    const _Bool WORD = 0, WHITESPACE = 1;
    
    fgets(buffer, BUFF_SIZE, stdin);
    for (const char *p = buffer; p != '\0'; p++) {

    }


    do {
        ch = getchar();
        if (i++ == 0)
            state = (ch == ' ' || ch == '\t'); // isspace(buf[i])

        // state가 달라졌다면
        if (state != (ch == ' ' || ch == '\t' || ch == '\n')) {
            state = !state;
            if (state == WHITESPACE) {            // word -> white
                word_cnt++;
                total_len += word_len;
                word_len = 0;
            }
        }
        if (state == WORD)
            word_len++;
    } while (ch != '\n');


    *avg_len = (double)total_len / *word_cnt;

    // 소수점 2자리 미만 제거
    *avg_len = (double)( (int)(*avg_len * 100) ) / 100;
}

void sorting(int word_counts[static restrict 5], double average_length[static restrict 5], int line_number[static restrict 5]) {
    int tmp;
    double tmpf;

    for (int i = 0; i < 4; i++)
        for (int j = i; j < 5; j++) {
            if (word_counts[j] > word_counts[i]) {
                swap(&word_counts[i], &word_counts[j], INT);
                swap(&average_length[i], &average_length[j], DOUBLE);
                swap(&line_number[i], &line_number[j], INT);
            }
            else if (word_counts[i] == word_counts[j] && average_length[j] > average_length[i]) {
                swap(&word_counts[i], &word_counts[j], INT);
                swap(&average_length[i], &average_length[j], DOUBLE);
                swap(&line_number[i], &line_number[j], INT);
            }
            else if (average_length[j] == average_length[i] && line_number[j] > line_number[i]) {
                swap(&word_counts[i], &word_counts[j], INT);
                swap(&average_length[i], &average_length[j], DOUBLE);
                swap(&line_number[i], &line_number[j], INT);
            }
        }
    // 개수, 길이, 번호
}

void swap(void *restrict v1, void *restrict v2, int TYPE) {
    if (v1 == v2)
        return;

    if (TYPE == INT) {
        int tmp;
        tmp = *(int *)v1;
        *(int *)v1 = *(int *)v2;
        *(int *)v2 = tmp;
    }
    else if (TYPE == DOUBLE) {
        double tmp;
        tmp = *(double *)v1;
        *(double *)v1 = *(double *)v2;
        *(double *)v2 = tmp;
    }
}

int sum_word(int word_counts[static 5]) {
    int sum = 0;
    for (int i = 0; i < 5; i++)
        sum += word_counts[i];

    return sum;
}

double total_avg_len(int word_counts[static restrict 5], double average_length[static restrict 5]) {
    int total_length = 0;
    for (int i = 0; i < 5; i++) {
        total_length += word_counts[i] * average_length[i];
    }

    return (double)total_length / sum_word(word_counts);
}