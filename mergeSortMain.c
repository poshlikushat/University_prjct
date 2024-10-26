#include <stdio.h>
#include "mergeSort.h"

int compareInt(const void *ptr_a, const void *ptr_b);
int compareFloat(const void *ptr_a, const void *ptr_b);
int compareChar(const void *ptr_a, const void *ptr_b);

	int main()
{
	const char *array[] = { "apple", "orange", "banana", "grape", "pear" };
	int length = sizeof(array) / sizeof(array[0]);

	mergeSort(array, length, sizeof(char* * 25), compareChar);

	for (int i = 0; i < length; i++) {
		printf("%s\n", array[i]);
	}
	printf("\n");
}

int compareInt(const void *ptr_a, const void *ptr_b) 
{
	return (*(int *)(ptr_a) >= *(int *)(ptr_b)) ? 1 : 0;
}

int compareFloat(const void *ptr_a, const void *ptr_b)
{
	return (*(float *)(ptr_a) >= *(float *)(ptr_b)) ? 1 : 0;
}

int compareChar(const void *ptr_a, const void *ptr_b)
{
	return (*(char *)(ptr_a) >= *(char *)(ptr_b)) ? 1 : 0;
}