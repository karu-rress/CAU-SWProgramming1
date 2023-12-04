/** 
 * 
 * HW 8-1
 * 
 * 입력받은 문자열(1~50자)에 있는 substring(1~50자의 문자열로 입력받음)의
 * 갯수를 출력한 후에 각각 문자열내의 몇 번째 위치(시작 번호)에서 발견되었는지를
 * 출력하는 프로그램을 작성 (없으면 “NOT FOUND” 출력)
 * ㈜ 입력 문자열은 blank, tab, 알파벳으로 구성되며 나타나는 순서와 빈도수는 제한 없음
 * 입력예시:  string:  abbababb aba  ab
             substring:ab
 * 출력예시: 5 ab found
          1:[2] 1, 2:[5] 3:[7] 4:[11] 5:[16]
 *
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    char str[51] = "", substr[51] = "", *tmp;
    int count = 0, i = 1;

    printf("string: ");
    gets_s(str, sizeof str);

    printf("substring: ");
    gets_s(substr, sizeof substr);


    // count total substrings
    for (tmp = str; (tmp = strstr(tmp, substr)); tmp++)
        count++;

    if (count == 0) {
        puts("\nNOT FOUND");
        return 0;
    }

    printf("\n%d %s found\n", count, substr);
    for (tmp = str; (tmp = strstr(tmp, substr)); tmp++) {
        printf("%d: [%d], ", i++, (int)(tmp - str));
    }
    puts("\b\b ");

    return 0;
}