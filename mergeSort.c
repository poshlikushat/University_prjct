#include "mergeSort.h"
#include <string.h>
#include <stdlib.h>

static void mergeSortedArrays(void *arr, int l, int m, int r, int typeSize, int (*cmp)(const void *, const void *));

void mergeSort(void *arr, int length, int typeSize, int (*cmp)(const void *, const void *))
{
	for (int step = 1; step < length; step *= 2)
	{
		for (int i = 0; i < length; i += 2 * step)
		{
			int l = i;
			int m = (i + step - 1 < length) ? i + step - 1 : length - 1;
			int r = (i + 2 * step - 1 < length) ? i + 2 * step - 1 : length - 1;

			if (m < r)
			{
				mergeSortedArrays(arr, l, m, r, typeSize, cmp);
			}
		}
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
