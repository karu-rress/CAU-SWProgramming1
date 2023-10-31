/**
 * 
 * HW 3-3
 * 
 *
 * 한줄의 문자열을 입력받아 문자열내의 단어 갯수와 평균 단어길이를
 * (소수 2째자리) 구하는 프로그램 작성
 * ㈜ 입력 문자는 blank, tab, 알파벳, CR(Carriage Return)로
 * 구성되며 이들 간에 나타나는 순서와 빈도수는 제한 없음
 *
 * 다양한 형태의 입력 데이터로 test 할 것
 * 입력예시: 
 * abc     bc  g    mm        ‘\n’
 *    jksj j k lo   jj     kk’\n’
 */

#include <stdio.h>

int main() {
    int ch;
    int words = 0, word_len = 0, total_len = 0, i = 0;
    _Bool state;
    const _Bool WORD = 0, WHITESPACE = 1;

    do {
        ch = getchar();
        if (i++ == 0)
            state = (ch == ' ' || ch == '\t'); // isspace(buf[i])

        // state가 달라졌다면
        if (state != (ch == ' ' || ch == '\t' || ch == '\n')) {
            state = !state;
            if (state == WHITESPACE) {            // word -> white
                words++;
                total_len += word_len;
                word_len = 0;
            }
        }
        if (state == WORD)
            word_len++;
    } while (ch != '\n');
    printf("Word count: %d, Average word length: %.2lf\n", words, (double)total_len / words);
    
    return 0;
}