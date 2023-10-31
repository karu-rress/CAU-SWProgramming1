#include <stdio.h>

int main(void) {
    double score;
    while (scanf("%lf", &score) != EOF) {
        switch ((int)score / 10)
        {
        case 10:
        case 9:
            putchar('A');
            break;
        case 8:
            putchar('B');
            break;
        case 7:
            putchar('C');
            break;
        case 6:
            putchar('D');
            break;
        default:
            putchar('F');
            break;
        }
        putchar('\n');
    }
    return 0;
}