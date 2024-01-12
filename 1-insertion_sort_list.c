#include "sort.h"

/**
 * insertion_sort_list - sorts a double linked list of ints in ascending order
 * using insertion sort algorithm
 * @list: list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node, *next_node;

	if (!list || !*list)
		return;

	current = (*list)->next;
	while (current)
	{
		while (current->prev && current->prev->n > current->n)
		{
			prev_node = current->prev;
			next_node = current->next;

			if (prev_node->prev)
				prev_node->prev->next = current;
			else
				*list = current;

			current->prev = prev_node->prev;
			current->next = prev_node;

			prev_node->prev = current;
			prev_node->next = next_node;

			if (next_node)
				next_node->prev = prev_node;

			print_list(*list);
		}
		current = current->next;
	}
}
