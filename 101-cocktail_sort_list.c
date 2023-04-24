#include "sort.h"

/**
 *  swap_nod_1 - swap infront of node
 * @list: points to first element
 * @temp: points to element to swap
 * @temp_prev: element to swap with
 */
void swap_nod_1(listint_t **list, listint_t *temp, listint_t *temp_prev)
{
	listint_t *temp1 = current->next;
	listint_t *temp2 = current_old->prev;

	if (temp->next != NULL)
		temp->next->prev = temp_prev;
	if (temp_prev->prev != NULL)
		temmp_prev->prev->next = temp;
	temp->prev = temp_prev->prev;
	temp_prev->next = temp->next;
	temp->next = temp_prev;
	temp_prev->prev = temp;
	if (*list == temp_prev)
		*list = temp;
	print_list(*list);
}
/**
 * cocktail_sort_list - sort a list
 * @list: list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp, *head, *tail;

	if (list == NULL || list == NULL || (*list)->next == NULL)
		return;
	head = tail = NULL;
	temp = *list;
	do {
		while (temp->next)
		{
			if (temp->next->n < temp->n)
				swap_nod_1(list, temp->next, temp);
			else
				temp = temp->next;
		}
		tail = temp;
		while (temp->prev != head)
		{
			if (temp->n < temp->prev->n)
				swap_nod_1(list, temp, temp->prev);
			else
				temp = temp->prev;
		}
		head = temp;
	} while (head != tail);
}
