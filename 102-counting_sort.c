#include "sort.h"
/**
 * counting_sort - Sorts an array of integers in ascending order
 * @array: the array of ints we want to sort
 * @size: the size of the array we want to sort
 * Return: Nothing
 **/
void counting_sort(int *array, size_t size)
{
	unsigned int i, max = 0;
	int *count, *output;

	if (!array || size < 2)
		return;
	for (i = 0; i < size; i++)
		if (array[i] > (int)max)
			max = array[i];
	count = malloc((max) * sizeof(int));
	if (count == NULL)
		return;
	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;
	for (i = 0; i < (max); i++)
		count[i] = 0;
	for (i = 0; i <= (size - 1); i++)
		count[array[i]] = count[array[i]] + 1; /*Counts instances*/
	for (i = 1; i <= max; i++)
		count[i] = count[i] + count[i - 1];/*sumCount*/
	print_array(count, max + 1);
	/*Sort array*/
	for (i = 0; i < size; i++)
	{/*Places object at correct position and decreases the count by one*/
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	/*Copy output array so it now contains the sorted characters*/
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
