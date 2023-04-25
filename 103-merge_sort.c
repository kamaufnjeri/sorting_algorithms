#include "sort.h"

/**
 * merge - divides, sorts and merges arrays
 * @array: to be sorted
 * @b: array to store sorted array temporarily
 * @size: size  of array
 */
void merge(int *array, int *b, size_t size)
{
	size_t mid, i, j, k;

	if (size < 2)
		return;

	mid = size / 2;
	j = i = k = 0;
	merge(array, b, mid);
	merge(array + mid, b + mid, size - mid);
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);
	for (k = 0; k < size; k++)
	{
		if (j >= size - mid || (i < mid && (array[i] < (array + mid)[j])))
		{
			b[k] = array[i];
			i++;
		}
		else
		{
			b[k] = (array + mid)[j];
			j++;
		}
	}
	for (k = 0; k < size; k++)
		array[k] = b[k];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - sorts array
 * @array: to sort
 * @size: of array
 */
void merge_sort(int *array, size_t size)
{
	int *b;

	if (!array || size < 2)
		return;
	b = malloc(sizeof(int) * size);
	if (b == NULL)
		return;
	merge(array, b, size);
	free(b);
}
