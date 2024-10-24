#include <stdio.h>
#include "mergeSort.h"


int compareInt(void *ptr_a, void *ptr_b);


int main() {
	int array[] = {9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
	int length = sizeof(array) / sizeof(array[0]);

	void* arr_ptr = (void*)array;
	void* ptr0 = (void*)((char*)arr_ptr + 0);
	void* ptr1 = (void*)((char*)arr_ptr + 4);

	printf("%d\n", compareInt(ptr0, ptr1));

}


int compareInt(void *ptr_a, void *ptr_b)
{
	if (*(int *)(ptr_a) >= *(int *)(ptr_b)) {
		return 1;
	}
	else return 0;
}