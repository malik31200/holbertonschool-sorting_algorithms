#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a linked list.
 * @list: Pointer to the head.
 * @node1: Firt node.
 * @node2: Second node.
 *
 * Return: Void.
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (!node1 || !node2 || node1->next != node2)
		return;

	node1->next = node2->next;
	if (node2->next)
		node2->next->prev = node1;

	node2->prev = node1->prev;
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	node2->next = node1;
	node1->prev = node2;
}

/**
 * cocktail_sort_list - Sort a list with double linked list.
 * @list: Pointer to the head.
 *
 * Return: Void.
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start, *end, *current;

	if (!list || !*list || !(*list)->next)
		return;

	start = *list;
	end = NULL;

	while (swapped)
	{
		swapped = 0;

		current = start;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}
		end = current;

		if (!swapped)
			break;

		swapped = 0;

		while (current->prev != start->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
		start = current->next;
	}
}
