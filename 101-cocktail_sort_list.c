#include "sort.h"

void swap(listint_t *n1, listint_t *n2);

/**
 * cocktail_sort_list - Sorts list of integers with cocktail sort algorithm
 * @list: reference to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *c, *start = *list, *end = 0;
	int swaped = 1;

	while (start != end && swaped)
	{
		swaped = 0;
		c = start;
		while (c && c->next)
		{
			if (c->n > c->next->n)
			{
				swap(c, c->next);
				swaped = 1;
				print_list(*list);
			}
			c = c->next;
		}
		return;
		end = c;
		c = c->prev;
		while (c && c->prev && c->prev != start)
		{
			if (c->n < c->prev->n)
			{
				swap(c, c->prev);
				swaped = 1;
				print_list(*list);
			}
			c = c->prev;
		}
		start = c->next;
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
