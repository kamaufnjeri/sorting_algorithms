#include "sort.h"

/**
 * swapme - swap the nodes themselves.
 * @current: pointer.
 * @current_old: pointer.
 * @list: doubly linked list
 */
listint_t *swapper(listint_t *holder, listint_t **list)
{
	listint_t *node_holder;

	if (holder->prev->prev != NULL)
		holder->prev->prev->next = holder;
	holder->prev->next = holder->next;
	node_holder = holder->prev->prev;
	holder->prev->prev = holder;
	if (holder->next != NULL)
		holder->next->prev = holder->prev;
	holder->next = holder->prev;
	holder->prev = node_holder;
	if (holder->prev == NULL)
		*list = holder;
	return (holder);
}
/**
 * cocktail_sort_list - cocktail_sort_list
 *
 * @list: doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *check = *list, *first = NULL, *last = NULL;

	if (!list)
		return;
	if (!(*list))
		return;
	if (!(*list)->next)
		return;
	do {
		while (check->next)
		{
			if (check->n > check->next->n)
				check = swapper(check->next, list);
			else
				check = check->next;
		}
		last = check;
		while (check->prev != first)
		{
			if (check->n < check->prev->n)
				check = swapper(check, list);
			else
				check = check->prev;
		}
		first = check;
	} while (first != last);
}

