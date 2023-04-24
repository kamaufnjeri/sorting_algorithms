#include "sort.h"

/**
 * merger_sort - merge sort
 * @array: to sort
 * @lb: lower bound
 * @ub: upper bound
 */
void merger_sort(int *array, int lb, int ub, size_t size)
{
	if (lb < ub)
	{
		mid = (int)size / 2;
		merger_sort(array, lb, mid - 1, (size_t)(mid - lb);
		merger_sort(array, mid, uub, (size_t)((ub - mid) + 1));
		merge(array, lb, mid, ub);
	}
}
void merge(int *array, int lb, int mid, int ub)
{

}
/**
 * merge_sort - sort through merge
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
}
