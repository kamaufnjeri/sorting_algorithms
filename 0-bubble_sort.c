#include "sort.h"

/**
 * swap - swap two integers
 * @a: first int
 * @b: second int
 */
void swap(int a, int b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}
/**
 * bubble_sort - sorts an arrray
 * @array: array to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int flag;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		flag = 0;
		for (j = 0; j < (size -i - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + i]);
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
		return;
	}
}
