#include <stdio.h>
#include <math.h>
#include <complex.h>


int input_coefficient(const char *prompt, double *value);
double _Complex quadratoc_equation_real(double a, double b, double c, double root, double _Complex root1, double _Complex root2);

int main(void) {
    double senior_coefficient, middle_coefficient, free_member, root;
    double _Complex root1, root2; 
    
    if (input_coefficient("Input a senior coefficient: ", &senior_coefficient)) {
        return 1;
    }
    if (input_coefficient("Input a middle coefficient: ", &middle_coefficient)) {
        return 1;
    }
    if (input_coefficient("Input a free member: ", &free_member)) {
        return 1;
    }

    return quadratoc_equation_real(senior_coefficient, middle_coefficient, free_member, root, root1, root2);
    

}

int input_coefficient(const char *prompt, double *value) {
    printf("%s", prompt);

    char addition;

    if (!scanf("%lf%1c", value, &addition) || addition != '\n') {
        printf("Please enter a valid number!\n");
        return 1;
    }
    return 0;
}

double _Complex quadratoc_equation_real(double a, double b, double c, double root, double _Complex root1, double _Complex root2) { 
    double discriminant = b * b - 4 * a * c;

    if (a == 0 && b == 0 && c != 0) {
        printf("No avaliable solutions for the equation!\n");
        return 0;
    }
    
    else if (a == 0 && b == 0 && c == 0) {
        printf("The equation has infinitely many solutions!");
        return 0;
    }

    else if (a == 0) {
        root = -c / b;
        printf("The solution is: %.2lf\n", root);
        return 0;
    }
    
    root1 = (-b + csqrt(discriminant)) / (2 * a);
    root2 = (-b - csqrt(discriminant)) / (2 * a);

    printf("Root 1: %.2f %.2fi\n", creal(root1), cimag(root1));
    printf("Root 2: %.2f %.2fi\n", creal(root2), cimag(root2));

    return 0;
}