#include "sort.h"

/**
 * swap_node - swap two nodes
 * @temp: to swap
 * @list: pointer to first node
 * Return: pointer new pointer after the exchange
 */
listint_t *swap_node(listint_t **list, listint_t *temp)
{
	listint_t *temp2;

	temp2 = temp->prev;
	if (temp2->prev != NULL)
		temp2->prev->next = temp;
	temp2->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = temp2;
	temp->next = temp->prev;
	temp->prev = temp2->prev;
	temp2->prev = temp;
	if (temp->prev == NULL)
		*list = temp;
	return (temp);
}

/**
 * cocktail_sort_list - sort linked list using cocktail sort method
 * @list: input linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp = *list;
	int flag = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (flag != 0)
	{
		flag = 0;
		while (temp->next != NULL)
		{

			if (temp->n > temp->next->n)
			{
				temp = swap_node(list, temp->next);
				print_list(*list);
				flag = 1;
			}
			temp = temp->next;
		}
		temp = temp->prev;
		while (temp->prev != NULL)
		{

			if (temp->n < temp->prev->n)
			{
				temp = swap_node(list, temp);
				print_list(*list);
				flag = 1;
			}
			else
				temp = temp->prev;
		}
	       temp = temp->next;
	}
}
