#include "sort.h"

void print_quick_sort(int *array, size_t size, int *o_array, size_t o_size);

/**
 * print_quick_sort - This function sorts an array of integers
 * in ascending order and print for each swap
 * @array: List of numbers
 * @size: Size of array
 * @o_array: Original list of numbers
 * @o_size: Original size of array
 */
void print_quick_sort(int *array, size_t size, int *o_array, size_t o_size)
{
	int i = 0;
	int j = size - 1;
	int p, n;

	if (!array || size <= 1)
		return;

	p = array[size - 1];
	while (i < j)
	{
		while (array[i] < p)
			i++;

		while (array[j] > p)
			j--;

		if (i >= j)
			break;

		n = array[i];
		array[i] = array[j];
		array[j] = n;
		print_array(o_array, o_size);
		i++, j--;
	}
	if (i == j && array[i] < p)
		i++;
	print_quick_sort(array, i, o_array, o_size);
	print_quick_sort(array + i, size - i, o_array, o_size);
}
/**
 * quick_sort_hoare - This function sorts an array of integers
 * in ascending order
 * @array: List of numbers
 * @size: Size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	print_quick_sort(array, size, array, size);
}
