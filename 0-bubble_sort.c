#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the bubble sort algorithm.
 * @array: Array that will be sorted.
 * @size: Size of the @array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, new_size;
	int temp;

	new_size = size - 1;
	if (!array || size < 2)
		return;
	while (new_size != 0)
	{
		i = 0;
		while (i < new_size)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
			i++;
		}
		new_size--;
	}
}
