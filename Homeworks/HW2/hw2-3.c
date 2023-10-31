/**
 * 
 * HW 2-3
 * 
 *
 * 시간의 초(예: 100000)를 읽어 들여
 * 몇 시간 몇 분 몇 초인지를 출력하는 프로그램 작성
 */

#include <stdio.h>

int main(void)
{
    unsigned int seconds;
    unsigned int hours, mins, secs;

    printf("초 입력 >> ");
    scanf("%u", &seconds);
    
    secs = seconds;

    hours = secs / 3600U;
    secs %= 3600U;

    mins = secs / 60U;
    secs %= 60U;

    printf("%u초는 %u시간 %u분 %u초입니다.\n", seconds, hours, mins, secs);
    
    return 0;
}