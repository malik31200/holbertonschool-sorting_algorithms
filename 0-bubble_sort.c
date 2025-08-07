#include "sort.h"

/**
 * bubble_sort - Sort an array with bubble sort algorithm.
 * @array: Array to sort.
 * @size: Number of elements in the array.
 *
 * Return: Void.
 */

void bubble_sort(int *array, size_t size)
{
	int temp = 0; 
	size_t i, j;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
}
