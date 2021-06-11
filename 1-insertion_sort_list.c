#include "sort.h"

/**
 * insertion_sort_list - Sorts an array of integers with insertion sort
 * @array: Array of numbers that's going to be sorted
 * @size: Size of array
 * Return: Nothing, will sort and print when swap
 */

void insertion_sort_list(listint_t **list):
{
	unsigned int i, j, swap = 0;
	int n;
	listint_t *curr = *list

	for (i = 0; curr->next; i++)
	{
		for (j = ; ; j++)
		{
			n = array[j];

			if (n > array[j + 1])
			{
				array[j] = array[j + 1];
				array[j + 1] = n;
				swap = 1;
				print_array(array, size);
			}
		}
		if (!swap)
			break;
	}
}
