#include <stdio.h>

int main(void)
{
   int n1, n2; //분모 분자 나눠 받기 
   int total1, total2 = 1;
   int i;
   int t1, t2;
   
   printf("원하는 분수를 3/4 형태로 무한대로 입력해 주세요 (이때, 분수 입력을 종료하고 싶다면 ctrl+z를 눌러주세요.) : ");
   while ((i = scanf("%d / %d", &n1, &n2)) != EOF)
   {
      printf("원하는 분수를 3/4 형태로 무한대로 입력해 주세요 (이때, 분수 입력을 종료하고 싶다면 ctrl+z를 눌러주세요.) : ");
      
        if (total1 == 1 && total2 == 1)
        {
            total1 = n1;
            total2 = n2;
        }
        else
        {
            if (n2 == total2)
            {
                total1 += n1;
            }
            else
            {
                total1 = (total1*n2) + (total2*n1); //만약 total2가 선행되면 total2 값이 저장된 상태로 연산되니, 이 조건 먼저 나오기 
                total2 *= n2;
            }
        }
   }
   
   if (total1/total2>0) // 이거를    [ total1 > total2 ]  로 바꾸고
   {
      if (total1%total2 == 0)
      {
         printf("%d / %d (%d)", total1, total2, total1/total2);
         // 얘는 그냥 여기서 return 0 써서 프로그램 끝내고
      }
      else
      {
        // 여기는 정수 부분만 따로 나누기.
         t1 = total1/(total1/total2);
         t2 = total2/(total1/total2);
         printf("%d / %d (%d + %d'/' %d)", total1, total2, total1/total2, (total1%total2)/t2);
      }
   }
   else // 여기서 기약분수 만드는 코드 돌리기
      printf("%d / %d", total1, total2);
   

   
   return 0;
   
}