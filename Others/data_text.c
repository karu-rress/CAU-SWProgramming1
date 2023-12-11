#include <stdio.h>

enum days { SUN, MON, TUE, WED, THU, FRI, SAT };
char *days_name[] = {
    "sunday", "monday", "tuesday", "wednesday",
    "thursday", "friday", "saturday"
};

int data_variable;

int main(void) {
    enum days d;
    d = WED;
    printf("%d번째 요일은 %s입니다.\n", d, days_name[d]);

    printf("ADDRESS OF data_variable: %p\n", &data_variable);
    printf("ADDRESS OF days_name[0]: %p\n", days_name[0]);

    return 0;
}



