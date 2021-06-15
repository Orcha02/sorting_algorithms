#include "sort.h"

void merge(int *array_merged, int *a1, size_t l1, int *a2, size_t l2);
void merge_sort_array(int *sorted_array, int *array, size_t size);

/**


*/
void merge_sort(int *array, size_t size)
{
	int *cp_array = malloc(sizeof(int) * size);
	size_t i;

	if (array && size > 0 && cp_array)
	{
		for (i = 0; i < size; i++)
			cp_array[i] = array[i];
		merge_sort_array(array, cp_array, size);
		free(cp_array);
	}
}

/**
 * ort - This function sorts an array of integers
 * in ascending order and print for each swap
 * @array: List of numbers
 * @size: Size of array
 */
void merge_sort_array(int *sorted_array, int *array, size_t size)
{
	if (!array || size < 2)
		return;

	merge_sort_array(sorted_array, array, size/2);
	merge_sort_array(sorted_array + size/2, array + size/2, size - size/2);
	merge(sorted_array, array, size/2, array + size/2, size - size/2);
}

/**
*/
void merge(int *array_merged, int *a1, size_t l1, int *a2, size_t l2)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: "), print_array(a1, l1);
	printf("[right]: "), print_array(a2, l2);

	for (k = 0; i < l1 && j < l2; k++)
		array_merged[k] = a1[i] < a2[j] ? a1[i++] : a2[j++];

	while (i < l1)
		array_merged[k] = a1[i++], k++;
	while (j < l2)
		array_merged[k] = a2[j++], k++;

	printf("[Done]: "), print_array(array_merged, l1 + l2);

	for (i = 0; i < l1 + l2; i++)
		a1[i] = array_merged[i];
}
