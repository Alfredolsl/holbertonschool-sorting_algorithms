#include "sort.h"

/**
 * partition - lomuto's partition scheme
 * this works by assuming the pivot element
 * with the last element
 *
 * @array: array to use
 * @low: first index
 * @high: last index
 * @size: size of array
 *
 * Return: pivot element
 */

int partition(int *array, int low, int high, size_t size)
{
	int i, pivot, j, temp;

	i = low;
	pivot = array[high];

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			print_array(array, size);
		}
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;

	print_array(array, size);
	return (i);
}

/**
 * quick_sort_operation - performs quick sort using
 * lowest index and highest index
 * @array: unordered array to sort
 * @low: first index
 * @high: last index
 */

void quick_sort_operation(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = partition(array, low, high, size);
		quick_sort_operation(array, low, partition_index - 1, size);
		quick_sort_operation(array, partition_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the quick sort algorithm
 * @array: unordered array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_operation(array, 0, size - 1, size);
}
