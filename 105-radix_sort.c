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
 * count_sort - sorts array
 * @array: array to sort
 * @pos: LSD of element
 * @size: size of array
 */
void count_sort(int *array, size_t size, int pos)
{
	int i, *copy, *count;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	count = malloc(sizeof(int) * 10);
	if (count == NULL)
	{
		free(copy);
		return;
	}
	for (i = 0; i < 10; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[((array[i] / pos) % 10)]++;
	for (i = 1; i < 10; i++)
		count[i] = count[i] + count[i - 1];
	for (i = ((int)size - 1); i >= 0; i--)
	{
		copy[count[((array[i] / pos) % 10)] - 1] = array[i];
		count[((array[i] / pos) % 10)]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = copy[i];
	free(copy);
	free(count);
}
/**
 * radix_sort - sort using radix LSD
 * @array: to sort
 * @size: of array
 */
void radix_sort(int *array, size_t size)
{
	int pos, max;

	if (array == NULL || size < 2)
		return;
	max = get_k(array, size);
	for (pos = 1; max / pos > 0; pos *= 10)
	{
		count_sort(array, size, pos);
		print_array(array, size);
	}

}
