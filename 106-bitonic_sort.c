#include <stdio.h>
#include "sort.h"

void bitonic_merge(int *arr, int lowindex, int count, int direction);

/**
 * biton_sort - sort
 * @arr: array
 * @lowindex: ...
 * @count: ...
 * @direction: ...
 * @size: ...
 */
void biton_sort(int *arr, int lowindex, int count, int direction, size_t size)
{
	int k;

	if (count > 1)
	{
		k = count / 2;
		printf("Merging [%d/%d] ", count, (int)size);
		if (direction == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(arr + lowindex, count);
		biton_sort(arr, lowindex, k, 1, size);
		biton_sort(arr, (lowindex + k), k, 0, size);
		bitonic_merge(arr, lowindex, count, direction);
		printf("Result [%d/16] ", count);
		if (direction == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(arr + lowindex, count);
	}
}
/**
 * bitonic_merge - sort
 * @arr: array
 * @lowindex: ...
 * @count: ...
 * @direction: ...
 */

void bitonic_merge(int *arr, int lowindex, int count, int direction)
{
	int k, temp, i;

	if (count > 1)
	{
		k = count / 2;
		for (i = lowindex; i < (lowindex + k); i++)
		{
			if (direction == (arr[i] > arr[i + k]))
			{
				temp = arr[i];
				arr[i]  = arr[i + k];
				arr[i + k] = temp;
			}
		}
		bitonic_merge(arr, lowindex, k, direction);
		bitonic_merge(arr, (lowindex + k), k, direction);
	}
}

/**
 * bitonic_sort - sort
 * @array: array
 * @size: ...
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	biton_sort(array, 0, (int)size, 1, size);
}
