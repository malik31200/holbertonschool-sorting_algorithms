#include "sort.h"

/**
  * selection_sort - Sort with the selection algorithm.
  * @array: Array to sort.
  * @size: Number of elements in the array.
  *
  * Return: Void.
  */

void selection_sort(int *array, size_t size)
{
	unsigned int long i, j, i_min, temp;

	for (i = 0; i < size - 1; i++)
	{
		i_min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i_min])
				i_min = j;
		}
		if (i_min != i)
		{
			temp = array[i];
			array[i] = array[i_min];
			array[i_min] = temp;
			print_array(array, size);
		}
	}
}
