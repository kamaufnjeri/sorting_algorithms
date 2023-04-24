#include <stdio.h>
#include <stdlib.h>

int get_k(int *array, int size)
{
	int k, i;

	k = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	printf("%d\n", k);
	return (k);
}
void count_sort(int *array, int size)
{
	int *count, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_k(array, size);
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
int main(void)
{
	int i, k;
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	int size = sizeof(array) / sizeof(array[0]);
	
	k = get_k(array, size);
	for (i = 0; i < size; i++)
        {
                printf("%d ", array[i]);
        }
	printf("\n%d\n", size);
        return (0);	
	count_sort(array, size);
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	return (0);
}
