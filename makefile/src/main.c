// src/main.c
#include <stdio.h>
#include "../include/sum.h"


int main() {
	// printf("main main\n");
    int a = 5;
    int b = 10;
    printf("Sum of %d and %d is %d\n", a, b, sum(a, b));
    return 0;
}
