#include "sort.h"

void swap(listint_t *n1, listint_t *n2);

/**
 * insertion_sort_list - Sorts an array of integers with insertion sort
 * @array: Array of numbers that's going to be sorted
 * @size: Size of array
 * Return: Nothing, will sort and print when swap
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr = *list;

	while ((curr = curr->next))
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
