#include "sort.h"

/**
 * get_k - gets max number in an array
 * @array: array
 * @size: size of array
 * Return: max number
 */
int get_k(int *array, size_t size)
{
	int k, i;

	k = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	return (k);
}

/**
 * counting_sort - sorts array
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *copy, *count, i, k;

	k = get_k(array, size);
	copy = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * (k + 1));
	if (array == NULL || size < 2 || copy == NULL)
		return;
	if (count == NULL)
	{
		free(copy);
		return;
	}

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;
	for (i = 1; i <= k; i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, (k + 1));
	for (i = ((int)size - 1); i >= 0; i--)
	{
		copy[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = copy[i];
	free(copy);
	free(count);
}
