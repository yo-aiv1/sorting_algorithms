#include "sort.h"

/**
 * lumoto_quick_sort- function that help to implement lumoto sort algorithm
 * @array: array that will be sorted.
 * @start: start index in sub @array
 * @end: end index in sub @array
 * @size: size of @array
 */

void lumoto_quick_sort(int *array, int start, int end, size_t size)
{
	int  i, item;
	int tmp, pivot;

	if (start >= end)
		return;
	pivot = array[end];
	item = start;

	for (i = start; i < end; i++)
		if (array[i] <= pivot)
		{
			if (item < i)
			{
				tmp = array[i];
				array[i] = array[item];
				array[item] = tmp;
				print_array(array, size);
			}

				item++;
		}
	if (array[item] > pivot)
	{
		tmp = pivot;
		array[end] = array[item];
		array[item] = tmp;
		print_array(array, size);
	}
	lumoto_quick_sort(array, start, item - 1, size);
	lumoto_quick_sort(array, item + 1, end, size);
}
/**
 * quick_sort - function that sorts an array of integers in ascending
 * order using the quick_sort sort algorithm
 * @array: array that will be sorted.
 * @size: size of the @array
 */


void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	lumoto_quick_sort(array, 0, size - 1, size);
}
