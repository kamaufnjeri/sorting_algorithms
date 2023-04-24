#include "sort.h"

/*
 * File: 102-counting_sort.c
 * Auth: Brennan D Baraban
 */

#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
/**
 * get_k - gets max number in an array
 * @array: array
 * @size: size of array
 * Return: max number
 */
/**int get_k(int *array, size_t size)
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
*/
/**
 * counting_sort - sorts array
 * @array: array to sort
 * @size: size of array
 */
/**void counting_sort(int *array, size_t size)
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
	for (i = 0; i <= k; i++)
		count[i] = 0;
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
}*/
