#include "sort.h"

void swap(listint_t *n1, listint_t *n2);

/**
 * insertion_sort_list - Sorts an array of integers with insertion sort
 * @list: list of numbers that's going to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (list && *list && (curr = curr->next))
	{
		while (curr->prev && curr->n < curr->prev->n)
		{
			swap(curr->prev, curr);
			if (!curr->prev)
				*list = curr;
			print_list(*list);
		}
	}
}
/**
 * swap - Swaps nodes with previous ones
 * @n1: previous node to swap
 * @n2: current node to swap
 */
void swap(listint_t *n1, listint_t *n2)
{
	n1->next = n2->next;
	if (n2->next)
		n2->next->prev = n1;
	n2->next = n1;
	n2->prev = n1->prev;
	if (n2->prev)
		n2->prev->next = n2;
	n1->prev = n2;
}
