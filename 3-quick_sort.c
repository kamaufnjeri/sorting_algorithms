#include "sort.h"

/**
 * swap - swap two ints
 * @array: two elements in array to swap
 * @i: index of first element
 * @j: index of second element
 */
void swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
/**
 * partition - partition array
 * @array: array to sort
 * @lb: first element index
 * @ub: last element index
 * @size: array size
 * Return: index of pivot
 */
int partition(int *array, int lb, int ub, size_t size)
{
	int i = lb - 1, j;

	for (j = lb; j <= ub - 1; j++)
	{
		if (array[j] < array[ub])
		{
			i++;
			if (i < j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[ub])
	{
		swap(array, (i + 1), ub);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * sort - sort array recursion
 * @array: array
 * @lb: index of first element
 * @ub: index of last element
 * @size: size of array
 */
void sort(int *array, int lb, int ub, size_t size)
{
	int loc;

	if (lb < ub)
	{
		loc = partition(array, lb, ub, size);
		sort(array, lb, loc - 1, size);
		sort(array, loc + 1, ub, size);
	}
}

/**
 * quick_sort - sorts an array of integers using the Quick
 * sort algorithm in ascending order
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort(array, 0, size - 1, size);
}
