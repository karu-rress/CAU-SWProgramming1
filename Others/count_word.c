#include <stdio.h>
#include <ctype.h>

int count(const char *s, int*);

int main(void) {
    int arr[5] = {0,};
    printf("%d\n", count("This is a sample string.", arr));
    
    for (int i = 0; i < 5; i++)
        printf("%d\t", arr[i]);
    return 0;
}

int count(const char *s, int *arr) {
    int i, wc = 0, waiting = 1;

    for (i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) { 
            if (waiting) {
                wc++;
                waiting = 0;
            } 
            arr[wc - 1]++; // 단어 길이 재기
        }
        else
            waiting = 1;
    }
    return wc;
}