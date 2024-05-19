/** 
 * 
 * HW 6-2-1
 * 
 * ㈜ 전역 변수 사용하지 말 것.
 *
 * [2] 대문자로 입력되는 한 단어의 끝은 임의의 소문자(예:HONGKILDONGa,
 * 단어길이: 11자)로 구분한다. main()에서 한 단어(1자이상 20자 이하)를
 * 한 문자씩 입력 받은 한 문자를(소문자 포함) avg_ascii() 함수(단어의
 * ASCII 코드값의 평균값과 단어길이를 계산하는 함수)에게 전달한다.
 * 
 * main()에서 단어, 단어길이, ASCII 코드 평균값을(소수 2째자리)
 * 출력하는 프로그램을 다음과 같이 각각 프로그램 작성
 *
 *	가. static 변수 미사용
 *	나. static 변수 사용
*/

#include <stdio.h>

void avg_ascii(char *restrict str, double *restrict avg, size_t *restrict len);

int main(void) {
    char str[21] = "", ch;
    size_t idx = 0, len;
    double avg;

    do {
        str[idx] = getchar();
    } while (str[idx] >= 'A' && str[idx++] <= 'Z'); // while 대문자

    avg_ascii(str, &avg, &len);

    printf("Word: %s\n", str);
    printf("Length: %zu\n", len);
    printf("Average ASCII: %.2f\n", avg);

    return 0;
}

void avg_ascii(char *restrict str, double *restrict avg, size_t *restrict len) {
    size_t sum = 0, word_len = 0;
    for (size_t i = 0; str[i] >= 'A' && str[i] <= 'Z'; i++) {
        sum += str[i];
        word_len++;
    }

    *avg = sum / word_len;
    *len = word_len;
    str[*len] = '\0'; // 마지막 문자는 삭제!
}