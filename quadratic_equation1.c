#include <stdio.h>
#include <math.h>

#define ERROR 1

int readCoefficient(char *prompt, double *value);
double quadraticEquation(double a, double b, double c);

int main(void) {
    double a, b, c;

    if (readCoefficient("Input a senior coefficient: ", &a)) {
        return ERROR;
    }
    if (readCoefficient("Input a middle coefficient: ", &b)) {
        return ERROR;
    }
    if (readCoefficient("Input a free member: ", &c)) {
        return ERROR;
    }

    return quadraticEquation(a, b, c);
}


int readCoefficient(char *prompt, double *value) {
    printf("%s", prompt);

    char addition;
    if (!scanf("%lf%1c", value, &addition) || addition != '\n') {
        printf("Please enter a valid number!\n");
        return 1;
    }
    return 0;
}


double quadraticEquation(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("The equation has infinitely many solutions!\n");
            } else {
                printf("No available solutions for the equation!\n");
            }
        } else {
            printf("The solution is: %.2lf\n", -c / b);
        }
        return 0;
    }

    if (discriminant > 0) {
        printf("Root 1: %.2lf\n", (-b + sqrt(discriminant)) / (2 * a));
        printf("Root 2: %.2lf\n", (-b - sqrt(discriminant)) / (2 * a));
    } else if (discriminant == 0) {
        printf("The equation has a real root: %.2lf\n", -b / (2 * a));
    } else {
        double real_part = -b / (2 * a);
        double imaginary_part = sqrt(fabs(discriminant)) / (2 * a);
        printf("Root 1: %.2lf - %.2lfi\n", real_part, imaginary_part);
        printf("Root 2: %.2lf + %.2lfi\n", real_part, imaginary_part);
    }

    return 0;
}
