#include "sort.h"
#include <stddef.h>
void swap_node(listint_t **list, listint_t *node1, listint_t *node2);
/**
 * insertion_sort_list - Sort a doubly linked list in ascending order.
 * @list: List of integers.
 *
 * Return: Void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			swap_node(list, current->prev, current);
			print_list(*list);
		}

		current = next;
	}
}
/**
 * swap_node - Switch two nodes
 * @list: Head of the doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 * Return: Void
 */
void swap_node(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1 == NULL || node2 == NULL)
	{
		return;
	}

	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
	}

	else
	{
		(*list) = node2;
	}

	if (node2->next != NULL)
	{
		node2->next->prev = node1;
	}

	node1->next = node2->next;
	node2->prev = node1->prev;

	node2->next = node1;
	node1->prev = node2;

}
