#include <stdio.h>
#include <stdlib.h>


unsigned long long int *fibonacci_numbers (int n);
int input_check(const char *prompt, int* value);


int main (void) {
    int number;

    if (input_check("Input a number: ", &number)) {
        return 1;
    }

    if (number < 0) {
        printf("Please, input a positive number \n");
        return 1;
    }

    unsigned long long int *array = fibonacci_numbers(number);

    printf("An array of Fibonacci numbers before n: ");
    for (int i = 0; i < number; i++) {
        printf("%llu ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}


int input_check(const char *prompt, int* value) {
    printf("%s", prompt);

    char addition;

    if (!scanf("%d%1c", value, &addition) || addition != '\n') {
        printf("Please, input a valid number!\n");
        return 1;
        
    }
    return 0;
}


unsigned long long int *fibonacci_numbers (int n) {
    unsigned long long int *array = malloc(n * sizeof(unsigned long long int));
    
    array[0] = 0;
    array[1] = 1;

    for (int i = 2; i < n; i++) {
        array[i] = array[i - 1] + array[i - 2];
    }

    return array;
}