#include <stdio.h>
#include "sort.h"

/**
 * swap_int - sorts two by swap
 * @a: first int
 * @b: secon int
 */
void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
