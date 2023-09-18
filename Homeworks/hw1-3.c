/**
 
 [3] 학생의 영어 및 국어 점수(0~100점의 자연수)와 이름(알파벳 1자)을
 아래와 같이 한줄에 하나씩 입력받아 다음과 같은 형태로 출력하는 프로그램 작성. (평균은 소숫점 2자리까지)

<입력 예시>:   _ 은 입력 데이타
Eng: _87
Kor: _92
Name: _S

<출력>
NAME	  ENGLISH	KOREAN	TOTAL		AVERAGE
	  SCORE	SCORE		SCORE		SCORE
S         87 		92         	179		89.50
 * 
 */

#include <stdio.h>

int main()
{
    char name;
    unsigned int eng, kor;

    printf("Eng: ");
    scanf("%u", &eng);

    printf("Kor: ");
    scanf("%u", &kor);

    // Kor 입력 후 개행문자 '\n'이 버퍼에 남아
    // %c만 사용할 경우 의도하지 않은 동작을 일으킴.
    // 입력버퍼에 남아있는 '\n'을 비워줘야 정상적으로 입력 가능
    // 1. getchar() 사용
    // 2. %*c%c 포맷 스트링 사용
    printf("Name: ");
    scanf("%*c%c", &name);

    printf("NAME\tENGLISH\tKOREAN\tTOTAL\tAVERAGE\n");
    printf("\tSCORE\tSCORE\tSCORE\tSCORE\n");
    printf("%c\t%u\t%u\t%u\t%.2Lf\n", name, eng, kor, eng+kor, (eng+kor)/2.L);

    return 0;
}