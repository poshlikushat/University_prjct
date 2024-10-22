#include <stdio.h>
#include "mergeSort.h"

int main() {
	int array[] = {9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
	int length = sizeof(array) / sizeof(array[0]);

	mergeSort(array, length);

	for (int i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;

}
