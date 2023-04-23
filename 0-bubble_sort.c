#include "sort.h"

/**
 * bubble_sort - sorts array
 * @array: to be sorted
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	int k;
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
				swap_int(&array[j], &array[j + 1]);
				print_array(array, size);
				k = 1;
			}
		}
		if (k == 0)
			return;
	}
}
