#include "mergeSort.h"

static void mergeSortRecursion(int* arr, int l, int r);
static void mergeSortedArrays(int* arr, int l, int m, int r);

void mergeSort(int* arr, int length) {
	mergeSortRecursion(arr, 0, length - 1);
}

static void mergeSortRecursion (int* arr, int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSortRecursion(arr, l, m);
		mergeSortRecursion(arr, m + 1, r);
		mergeSortedArrays(arr, l, m, r);
	}
}


static void mergeSortedArrays (int* arr, int l, int m, int r) {
	int leftLength = m - l + 1;
	int rightLength = r - m;

	int tempLeft[leftLength];
	int tempRight[rightLength];

	int i, j, k;

	for (i = 0; i < leftLength; i++) {
		tempLeft[i] = arr[l + i];
	}

	for (j = 0; j < rightLength; j++) {
		tempRight[j] = arr[m + 1 + j];
	}

	i = 0;
	j = 0;
	k = l;

	while (i < leftLength && j < rightLength)
	{
		if (tempLeft[i] <= tempRight[j])
		{
			arr[k] = tempLeft[i];
			i++;
		}
		else
		{
			arr[k] = tempRight[j];
			j++;
		}
		k++;
	}

	while (i < leftLength)
	{
		arr[k] = tempLeft[i];
		i++;
		k++;
	}


	while (j < rightLength)
	{
		arr[k] = tempRight[j];
		j++;
		k++;
	}
}


int compareInt (void* ptr_a, void* ptr_b) {
	
}

int compareFloat(void *ptr_a, void *ptr_b) {

}

int compareChar(void *ptr_a, void *ptr_b) {

}

int compareString(void *ptr_a, void *ptr_b) { 

}
