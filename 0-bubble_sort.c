#include "sort.h"

/**
 * bubble_sort - sorts array
 * @array: to be sorted
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	int k, temp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < (size - 1); i++)
	{
		k = 0;
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				k = 1;
			}
		}
		if (k == 0)
			return;
	}
}
