#include "sort.h"

/**
 * insertion_sort_list - Sorts an array of integers with insertion sort
 * @array: Array of numbers that's going to be sorted
 * @size: Size of array
 * Return: Nothing, will sort and print when swap
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *curr = *list, *prev = curr->prev, *previous, *current;
	int p_n;

	while (curr->next)
	{
		current = curr;
		previous = prev;
		while (previous && current->n < previous->n)
		{
			p_n = previous->n;
			previous->n = current->n;
			current->n = p_n;

			current = current->prev;
			previous = current->prev;
		}
		curr = curr->next;
		prev = curr->prev;
	}
}
/**
 * swap - Swaps nodes with previous ones
 * @current: current node
 */
void swap(listint_t **current)
{
	listint_t *previous = current->prev;

	while (previous && current->n < previous->n)
	{
		current->prev->next = current->next;
		curr->next = curr->previous;
		
	}
}
