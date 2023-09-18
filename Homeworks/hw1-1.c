/**
 * HW 1-1
 * 
 * 학생 2명의 영어 및 국어 점수(0~100점의 자연수)와 
 * 이름(알파벳 3자 이하)을 각각 입력받아 
 * 각 학생의 이름, 영어, 국어 점수를 출력하는
 * 프로그램 작성
 * 
 */

#include <stdio.h>

int main()
{
    char name1[4], name2[4];
    unsigned int eng1, kor1, eng2, kor2;

    printf("첫 번째 학생의 이름을 입력하세요. (알파벳 3자 이하) >> ");
    scanf("%3s", name1); // 3글자만 입력받고, 나머지는 버림

    printf("├────영어 점수를 입력하세요. (0~100) >> ");
    scanf("%u", &eng1);

    printf("└────국어 점수를 입력하세요. (0~100) >> ");
    scanf("%u", &kor1);


    printf("두 번째 학생의 이름을 입력하세요. (알파벳 3자 이하) >> ");
    scanf("%3s%*c", name2);

    printf("├────영어 점수를 입력하세요. (0~100) >> ");
    scanf("%u", &eng2);

    printf("└────국어 점수를 입력하세요. (0~100) >> ");
    scanf("%u", &kor2);

    printf("\n\n<%s 학생의 점수>\n"
        "영어 %u점\t국어 %u점\n\n"
        "<%s 학생의 점수>\n"
        "영어 %u점\t국어 %u점\n",
        name1, eng1, kor1, name2, eng2, kor1
    );
    
    return 0;
}