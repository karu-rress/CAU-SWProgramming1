#include <stdio.h>
#include <stdlib.h>

#define str_to_num(var, str) _Generic((var), \
    int: ((var) = atoi((str))), \
    long: ((var) = atol((str))), \
    double: ((var) = atof((str))), \
    float: ((var) = atof((str))), \
    long long: ((var) = atoll(str)))

int main() {
    int iNum;
    long lNum;
    long long llNum;
    double Real;

    str_to_num(iNum, "300"); // iNum은 int이므로 atoi 호출
    printf("converted '300' to int, %d\n", iNum);

    str_to_num(lNum, "-30000"); // lNum은 long이므로 atol 호출
    printf("converted '-30000' to long long, %ld\n", lNum);

    str_to_num(llNum, "9223372036854775807"); // atoll 호출
    printf("converted '9223372036854775807' to long long: %lld\n", llNum);

    str_to_num(Real, "3.14159265"); // atof 호출
    printf("converted '3.14159265' to double, %.8f\n", Real);
    
    return 0;
}