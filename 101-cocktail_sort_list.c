#include "sort.h"

void swapme(listint_t *current, listint_t *current_old, listint_t **list)
{
	listint_t *temp1 = current->next;
	listint_t *temp2 = current_old->prev;

	if (temp1 != NULL)
		temp1->prev = current_old;
	if (temp2 != NULL)
		temp2->next = current;
	current->prev = temp2;
	current_old->next = temp1;
	current->next = current_old;
	current_old->prev = current;
	if (*list == current_old)
		*list = current;
	print_list(*list);
}

/**
 * cocktail_sort_list - sort list
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *check = *list;
	int flag;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		flag = 0;
		while (check->next != NULL)
		{
			if (check->n > check->next->n)
			{
				swapme(check->next, check, list);
				flag = 1;
			}
			else
			{
				check = check->next;
			}
		}
		check = check->prev;
		while (check->prev != NULL)
		{
			if (check->n < check->prev->n)
			{	swapme(check, check->prev, list);
				flag = 1;
			}
			else
			{
				check = check->prev;
			}
		}
		check = check->next;
	} while (flag == 1);
}
