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
	unsigned int i = 0, j = 0;
	int p = array ? array[size - 1] : 0, n;

	if (!array || size <= 1)
		return;

	for (j = 0; j < size; j++)
		if ((array[j] <= p && array[i] != array[j]) || j == size - 1)
		{
			n = array[i];
			array[i] = array[j];
			array[j] = n;
			print_array(o_array, o_size);
			i++;
		}
	print_quick_sort(array, i - 1, o_array, o_size);
	print_quick_sort(array + i, size - i, o_array, o_size);
}

/**
 * quick_sort - This function sorts an array of integers
 * in ascending order
 * @array: List of numbers
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	print_quick_sort(array, size, array, size);
}
