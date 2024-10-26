#include "mergeSort.h"
#include <string.h>
#include <stdlib.h>

static void mergeSortRecursion(void *arr, int l, int r, int typeSize, int (*cmp)(const void *, const void *));
static void mergeSortedArrays(void *arr, int l, int m, int r, int typeSize, int (*cmp)(const void *, const void *));

void mergeSort(void *arr, int length, int typeSize, int (*cmp)(const void *, const void *))
{
	mergeSortRecursion(arr, 0, length - 1, typeSize, cmp);
}

static void mergeSortRecursion(void *arr, int l, int r, int typeSize, int (*cmp)(const void *, const void *))
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSortRecursion(arr, l, m, typeSize, cmp);
		mergeSortRecursion(arr, m + 1, r, typeSize, cmp);
		mergeSortedArrays(arr, l, m, r, typeSize, cmp);
	}
}

static void mergeSortedArrays(void *arr, int l, int m, int r, int typeSize, int (*cmp)(const void *, const void *))
{
	int leftLength = m - l + 1;
	int rightLength = r - m;

	void *tempLeft = malloc(leftLength * typeSize);
	void *tempRight = malloc(rightLength * typeSize);

	memcpy(tempLeft, (char*)arr + l * typeSize, leftLength * typeSize);
	memcpy(tempRight, (char*)arr + (m + 1) * typeSize, rightLength * typeSize);


	int i, j, k;

	i = 0;
	j = 0;
	k = l;

	while (i < leftLength && j < rightLength)
	{
		if (cmp((char*)tempLeft + i * typeSize, (char*)tempRight + j * typeSize) <= 0)
		{
			// arr[k] = tempLeft[i];
			memcpy((char*)arr + k * typeSize, (char* )tempLeft + i * typeSize, typeSize);
			i++;
		}
		else
		{
			memcpy((char *)arr + k * typeSize, (char *)tempRight + j * typeSize, typeSize);
			j++;
		}
		k++;
	}

	while (i < leftLength)
	{
		memcpy((char *)arr + k * typeSize, (char *)tempLeft + i * typeSize, typeSize);
		i++;
		k++;
	}

	while (j < rightLength)
	{
		memcpy((char *)arr + k * typeSize, (char *)tempRight + j * typeSize, typeSize);
		j++;
		k++;
	}
}
