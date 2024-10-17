#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void) {
    float side1, side2, side3;

    printf("Input the 1st side: ");
    if (scanf("%f", &side1) != 1) {
        printf("Please enter a valid number!\n");
        return 1;
    }
    printf("Input the 2nd side: ");
    if (scanf("%f", &side2) != 1) {
        printf("Please enter a valid number!\n");
        return 1;
    }

    printf("Input the 3rd side: ");
    if (scanf("%f", &side3) != 1) {
        printf("Please enter a valid number!\n");
        return 1;
    }
    
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        printf("Write a positive number\n");
        return 1;
    }

    bool is_ok = false;
    if ((side1 + side2 > side3) && (side2 + side3 > side1) && (side1 + side3 > side2)) {
        is_ok = true;
    }

    if (is_ok == false) {
        printf("This triangle can't exist!\n");
        return 1;
    }

    if (is_ok) {
        double sp = (side1 + side2 + side3) / 2.0; // semiperimeter
        double square = sqrt(sp * (sp - side1) * (sp - side2) * (sp - side3));

        if (side1 == side2 && side2 == side3) {
            printf("Triangle is equilateral\n");
        }
        else if (side1 == side2 || side2 == side3 || side1 == side3) {
            printf("Triangle is isosceles\n");
        }
        else {
            printf("Triangle is versatile\n");
        }

        printf("Perimeter: %.2f\n", sp * 2.0);
        printf("Square = %.2f\n", square);
        return 0;
    }
}
