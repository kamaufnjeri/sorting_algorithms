#include "sort.h"

/**
 * swap - swaps to elements in an array
 * @a: to swap with b
 * @b: swap with a
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}
/**
 * maxheapify - creates max heap
 * @array: to sort
 * @end: end of unsorted max heap
 * @size: size of array
 * @index: index of first node in binary tree
 */
void maxheapify(int *array, int end, size_t size, int index)
{
	int largest, left, right;

	largest = index;
	left = (2 * index) + 1;
	right = (2 * index) + 2;
	if (left < end && array[left] > array[largest])
		largest = left;
	if (right < end && array[right] > array[largest])
		largest = right;
	if (largest != index)
	{
		swap(&array[largest], &array[index]);
		print_array(array, size);
		maxheapify(array, end, size, largest);
	}
}

/**
 * heap_sort - sorts array
 * @array: to sort
 * @size: of array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	for (i = (size / 2) - 1; i >= 0; i--)
		maxheapify(array, size, size, i);
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i != 0)
			print_array(array, size);
		maxheapify(array, i, size, 0);
	}
}
