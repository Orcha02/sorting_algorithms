#include "sort.h"

void merge(int *array_merged, int *a1, size_t l1, int *a2, size_t l2);
void merge_sort_array(int *sorted_array, int *array, size_t size);

/**
 * merge_sort - create a copy of the array before to sort
 * @array: array to be sorted
 * @size: size of the array
*/
void merge_sort(int *array, size_t size)
{
	int *cp_array;
	size_t i;

	if (!array || size < 1)
		return;

	cp_array = malloc(sizeof(int) * size);

	if (!cp_array)
		exit(1);

	for (i = 0; i < size; i++)
		cp_array[i] = array[i];
	merge_sort_array(array, cp_array, size);
	free(cp_array);
}

/**
 * merge_sort_array - This function sorts an array of integers
 * in ascending order and print for each swap
 * @sorted_array: sorted array
 * @array: array of numbers
 * @size: Size of array
 */
void merge_sort_array(int *sorted_array, int *array, size_t size)
{
	if (!array || size < 2)
		return;

	merge_sort_array(sorted_array, array, size / 2);
	merge_sort_array(sorted_array + size / 2, array + size / 2, size - size / 2);
	merge(sorted_array, array, size / 2, array + size / 2, size - size / 2);
}

/**
 * merge - compare two sorted arrays and merge
 * @array_merged: merge sort of a1 and a2
 * @a1: first array to merge
 * @l1: size of a1
 * @a2: second array to merge
 * @l2: size of a2
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
