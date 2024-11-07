#pragma once

void mergeSort(void *arr, int length, int typeSize, int (*cmp)(const void *, const void *));
typedef struct personInfo
{
	char last_name[25];
	char first_name[25];
	char sex;
} INFO;