#include "sort.h"

/**
 * swap - swaps two elements
 * @a: integer to swap with b
 * @b: integer to swap with a
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - orders a subset of an array of integers
 * according to the lomuto partition scheme
 * (last element is the pivot)
 * @array: array to sort
 * @left: starting index of the subset
 * @right: ending index of the subset
 *
 * Return: the final partition index
 */

int lomuto_partition(int *array, int left, int right, size_t size)
{
	int i, j;
	int pivot = array[right];

	i = left - 1;

	for (j = left; j <= right - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[right]);
	print_array(array, size);

	return (i + 1);
}

/**
 * qs_operation - performs quick sort using
 * leftest index and rightest index
 * @array: unordered array to sort
 * @left: first index
 * @right: last index
 * @size: size of index
 */

void qs_operation(int *array, int left, int right, size_t size)
{
	int p;

	if (left >= right)
		return;

	p = lomuto_partition(array, left, right, size);
	qs_operation(array, left, p - 1, size);
	qs_operation(array, p + 1, right, size);
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: unordered array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (!array)
		return;

	qs_operation(array, 0, size - 1, size);
}
