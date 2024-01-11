#include "sort.h"

/**
 * bubble_sort - sorts an array of integers using bubble sort
 * @array: pointer to an int type array
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	int temp = 0, sizecpy = size;
	size_t i;

	if (!array)
		exit(EXIT_FAILURE);

	while (size != 1)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
		print_array(array, sizecpy);
		size--;
	}
}
