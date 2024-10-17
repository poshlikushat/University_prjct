#include <stdio.h>


int sum(int number);
int product (int number);


int main(void)
{
    int number;

    printf("Write down a positive number: ");
    if (!scanf("%d", &number)) {
        printf("Please enter a valid number!\n");
        return 1;
    }
    if (number <= 0)
    {
        printf("Write down a POSITIVE number: ");
        return 1;
    }
    printf("Sum: %d\n", sum(number));
    printf("Product: %d\n", product(number));
}


int sum(int number) {
    int suma = 0;
    while (number > 0)
    {
        int digit = number % 10;
        suma += digit;
        number /= 10;
    }  
    return suma;  
}


int product (int number) {
    int producta = 1;
    while (number > 0) {
        int digit = number % 10;
        producta *= digit;
        number /= 10;
    }
    return producta;
}