#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

int main (void) {
    int number;
    srand(time(NULL));

    void** array = malloc(n * sizeof(void* ));

    if (array == NULL) {
        printf("Can't allocate memory!\n");
        return ERROR;
    }
}


void mergeSort(int n ,void* array, int elementSize, int compare) {
    int length = sizeof(array) / sizeof(array[0]);
    if (length <= 1) {
        return array;
    }
    
    while(length > 2) {
        int mid = length / 2;
        void* left = array[]
    }
    
}


