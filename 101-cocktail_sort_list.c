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
	listint_t *check = *list;
	int flag;

	if (!list)
		return;
	if (!(*list))
		return;
	if (!(*list)->next)
		return;
	do {
		flag = 0;
		while (check->next)
		{
			if (check->n > check->next->n)
			{
				check = swapper(check->next, list);
				print_list(* list);
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
			{
				check = swapper(check, list);
				print_list(* list);
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

