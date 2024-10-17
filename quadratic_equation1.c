#include <stdio.h>
#include <math.h>

#define NO_REAL_NUMBERS -2
#define ERROR -1
#define INFINIT_SOLUTION 10 
#define NO_SOLUTIONS -10
#define ONE_ROOT 1
#define TWO_ROOTS 2

int readCoefficient(char *prompt, double *value);
double quadraticEquation(double a, double b, double c, double *root1_ptr, double *root2_ptr);

int main(void) {
    double a, b, c;
    double root1, root2;
    double* root1_ptr = &root1;
    double* root2_ptr = &root2;

    if (readCoefficient("Input a senior coefficient: ", &a)) {
        return ERROR;
    }
    if (readCoefficient("Input a middle coefficient: ", &b)) {
        return ERROR;
    }
    if (readCoefficient("Input a free member: ", &c)) {
        return ERROR;
    }

    double result = quadraticEquation(a, b, c, root1_ptr, root2_ptr);

    if (result == INFINIT_SOLUTION)
    {
        printf("The equation has infinitly many soultions!\n");
    }
    if (result == NO_SOLUTIONS)
    {
        printf("The equation has no avaliable soultions!\n");
    }
    if (result == NO_REAL_NUMBERS)
    {
        printf("The equation has no real roots!\n");
    }
    if (result == ONE_ROOT)
    {
        printf("%lf\n", root1);
    }
    if (result == TWO_ROOTS)
    {
        printf("%lf\n%lf\n", root1, root2);
    }
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

double quadraticEquation(double a, double b, double c, double *root1_ptr, double *root2_ptr) {
    double discriminant = b * b - 4 * a * c;

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                return INFINIT_SOLUTION;
            }
            else
            {
                return NO_SOLUTIONS;
            }
        }
        else
        {
            *root1_ptr = -c / b;
            return ONE_ROOT;
        }
    }

    if (discriminant > 0) {
        *root1_ptr = (-b + sqrt(discriminant)) / (2 * a);
        *root2_ptr = (-b - sqrt(discriminant)) / (2 * a);
        return TWO_ROOTS;
    } else if (discriminant == 0) {
        *root1_ptr = -b / (2 * a);
        return ONE_ROOT;
    } else {
        return NO_REAL_NUMBERS;
    }
}
