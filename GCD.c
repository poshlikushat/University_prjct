#include "stdio.h"

int greatest_common_divisor(int a, int b);
int input_coefficient(const char *prompt, int *value);
int validate_input(int a, int b);

int main (void) {
    int a, b;
    if (input_coefficient("Please, input the first value: ", &a)) {
        return 1;
    }

    if (input_coefficient("Please, input the second value: ", &b)) {
        return 2;
    }

    if (validate_input(a, b)) {
        printf("Numbers must be positive!");
        return 3;
    }   

    printf("The greatest_common_divisor: %d\n", greatest_common_divisor(a, b));
    return 0;
}


int greatest_common_divisor (int a, int b) {
    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    return (b == 0) ? a : greatest_common_divisor(b, a % b);
}


int input_coefficient(const char *prompt, int *value) {
    printf("%s", prompt);
    char addition;
    if (!scanf("%d%1c", value, &addition) || addition != '\n') {
        printf("Please enter a valid number!\n");
        return 1;
    }
    return 0;
}


int validate_input(int a, int b) {
    return (a <= 0 || b <= 0) ? 1 : 0;
}


// result = (condition) ? val1 : val2;