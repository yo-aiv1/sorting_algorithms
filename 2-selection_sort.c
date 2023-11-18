#include "sort.h"
#include <stddef.h>

/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: Array that will be sorted.
 * @size: Size of the @array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min, item;

	if (!array || size <= 1)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;

		if (min != i)
		{
			item = array[i];
			array[i] = array[min];
			array[min] = item;
			print_array(array, size);
		}
	}
}
