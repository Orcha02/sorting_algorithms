#include "sort.h"
/**
 * selection_sort - This function sorts an array of integers
 * in ascending order
 * @array: List of numbers
 * @size: Size of array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, j, m_idx, tmp;

	for (i = 0; i < size; i++)
	{
		m_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[m_idx])
				m_idx = j;
		}
		if (array[m_idx] < array[i])
		{
			tmp = array[i];
			array[i] = array[m_idx];
			array[m_idx] = tmp;
			print_array(array, size);
		}
	}
}
