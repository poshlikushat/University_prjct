#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_NUMBER 100
#define ERROR -1

void insertion_sort(int* arr, int n);
int read_number(char* prompt, int* value);
void print_array(int n, int* arr);
int* generate_random_array(int n);


int main (void) {
    int number;
    srand(time(NULL));

    if (read_number("Input a number: ", &number)) {
        return ERROR;
    }

    int* array = generate_random_array(number);
    
    if (array == NULL) {
        printf("Can't allocate memory!\n");
        return ERROR;
    }

    printf("Random array: ");
    print_array(number, array);
    

    insertion_sort(array, number);

    printf("Sorted array: ");
    print_array(number, array);

    free(array);
    return 0;
}

void insertion_sort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int x = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}


int read_number(char* prompt, int* value) {
    printf("%s", prompt);

    if (!scanf("%d", value) || *value <= 0) {
        printf("Please, input a valid positive number!\n");
        return ERROR;
    }
    return 0;
}


void print_array(int n, int* arr) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* generate_random_array(int n) {
    int* array = malloc(n * sizeof(int));
    if (array == NULL)
        return NULL;
    for (int i = 0; i < n; i++) {
        array[i] = rand() % MAX_ARRAY_NUMBER;
    }
    return array;
}