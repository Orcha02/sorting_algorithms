#include "sort.h"
/**
 * shell_sort -Sort an array using shell_sort algorithm
 * @array: array to be sorted
 * @size: size of array
 **/
void shell_sort(int *array, size_t size)
{
	int current;
	size_t i, j, gap = 1;

	if (!array || size <= 1)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			current = array[i];
			j = i;
			while (j >= gap && array[i - j] > current)
			{
				array[j] = array[j - gap];
				j =  j - gap;
			}
			array[j] = current;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
