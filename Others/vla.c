// vla.c
// compiled with gcc 13
// gcc -fdiagnostics-color=always -fno-stack-protector -Wall -Wextra -std=c99 -g3 vla.c

#include <stdio.h>
#include <stdlib.h>

void test_same_scope();
void test_different_scope();

int main() {
    test_same_scope();
    test_different_scope();
    return 0;
}

void test_same_scope() {
    int stack_array[3] = {1, 2, 3};
    int stack_variable;

    printf("####### 1. 동일 scope에서 stack, vla, heap array 비교 #######\n\n");
    for (int i = 0; i < 3; i++) {
        printf("Address of stack_array[%d]: %p\n", i, &stack_array[i]);
        printf("Value of stack_array[%d]: %d\n", i, stack_array[i]);
    }

    stack_variable = 3;
    printf("\nAddress of stack_variable: %p\n\n", &stack_variable);

    int vla_array[stack_variable]; // = { } 형식의 초기화 불가
    for (int i = 0; i < 3; i++) {
        vla_array[i] = i + 1;
        printf("Address of vla_array[%d]: %p\n", i, &vla_array[i]);
        printf("Value of vla_array[%d]: %d\n", i, vla_array[i]);
    }

    int stack_variable2 = 0;
    printf("\nAddress of stack_variable2: %p\n\n", &stack_variable2);

    int *heap_array = (int*)calloc(3, sizeof(int));
    for (int i = 0; i < 3; i++) {
        heap_array[i] = i + 1;
        printf("Address of heap_array[%d]: %p\n", i, &heap_array[i]);
        printf("Value of heap_array[%d]: %d\n\n", i, heap_array[i]);
    }
    free(heap_array);
    heap_array = NULL;
    system("pause");
}

void test_different_scope() {
    system("cls");
    printf("####### 2. Scope를 벗어난 후 stack, vla, heap array 비교 #######\n\n");
    int *ptr; 
    goto FIRST_STACK;
    {
SECOND_STACK:
        printf("[GOTO] stack_array: %p\n", ptr);
        printf("[GOTO] stack_array[0]: %d\n", *ptr); // 정상 작동 (메모리 해제 전)
    goto EXIT_STACK;
FIRST_STACK:
        int stack_array[3] = {1, 2, 3};
        ptr = stack_array;
        goto SECOND_STACK;
    } // block scope를 벗어나면서 자동 해제
EXIT_STACK:
    printf("Address of stack_array: %p\n", ptr);
    printf("Value of stack_array[0]: %d\n\n", *ptr); // 메모리가 해제되었으나, 우연히 정상작동

    int size = 3;
    goto FIRST_VLA;
    {
SECOND_VLA: // goto 문을 이용해 선언 위로 올라오기만 해도 메모리 해제
        printf("[GOTO] vla_array: %p\n", ptr);
        printf("[GOTO] vla_array[0]: %d\n", *ptr); // ptr is dangling pointer
        goto EXIT_VLA;
FIRST_VLA:
        int vla_array[size];
        for (int i = 0; i < 3; i++) vla_array[i] = i+1;
        ptr = vla_array;
        goto SECOND_VLA;
    } // 마찬가지로 auto 변수이기에, scope를 벗어나면서 자동 해제
EXIT_VLA:
    printf("Address of vla_array: %p\n", ptr);
    printf("Value of vla_array[0]: %d\n\n", *ptr);

    {
        int *heap_array = (int *)calloc(3, sizeof(int));
        for (int i = 0; i < 3; i++) heap_array[i] = i+1;
        ptr = heap_array;
    }
    printf("Address of heap_array: %p\n", ptr);
    printf("Value of heap_array[0]: %d\n\n", *ptr);
    free(ptr);

    system("pause");
}