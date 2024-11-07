#include <stdio.h>
#include "mergeSort.h"
#include <string.h>

int compareInt(const void *ptr_a, const void *ptr_b);
int compareFloat(const void *ptr_a, const void *ptr_b);
int compareChar(const void *ptr_a, const void *ptr_b);
int compareDouble(const void *ptr_a, const void *ptr_b);
int compareStruct(const void *ptr_a, const void *ptr_b);

	int main()
{
	// double array[] = {5.3, 24.3, 1.00001, 1.00000};
	// int length = sizeof(array) / sizeof(array[0]);

	// mergeSort(array, length, sizeof(double), compareDouble);

	// for (int i = 0; i < length; i++) {
	// 	printf("%.50lf\n", array[i]);
	// }
	// printf("\n");

	INFO persons[] = {
		{"Kuimov", "Mikhail", 'M'},
		{"Pupkin", "Vasya", 'M'},
		{"White", "Walter", 'M'},
		{"Pinkman", "Jessy", 'M'},
		{"White", "Skyler", 'W'},
		{"Nosurname", "Noname", 'W'}};
	int length = sizeof(persons) / sizeof(persons[0]);

	mergeSort(persons, length, sizeof(INFO), compareStruct);

	for (int i = 0; i < length; i++)
	{
		printf("%s %s, %c\n", persons[i].last_name, persons[i].first_name, persons[i].sex);
	}

	return 0;
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

int compareDouble(const void *ptr_a, const void *ptr_b)
{
	return (*(double *)(ptr_a) >= *(double *)(ptr_b)) ? 1 : 0;
}

int compareStruct(const void *ptr_a, const void *ptr_b)
{
	INFO *a = (INFO *)ptr_a;
	INFO *b = (INFO *)ptr_b;

	return strcmp(a->first_name, b->first_name);
}