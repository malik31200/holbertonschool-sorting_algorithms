#include "sort.h"
int partition(int *array, int low, int high, size_t size);
void quick_sort_rec(int *array, int low, int high, size_t size);
/**
 * quick_sort - Sort an array in ascending.
 * @array: Array of integers.
 * @size: Size of an array.
 * Return: Void.
 */
void quick_sort(int *array, size_t size)
{

	if (array == NULL || size <= 1)
	{
		return;
	}
	quick_sort_rec(array, 0, size - 1, size);

}

/**
 * partition - Used to place the pivot.
 * @array: Array of integers.
 * @low: Start of partition.
 * @high: End of the partition.
 * @size: Size of partition.
 * Return: position of the pivot.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, temp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if ((i + 1) != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_rec - Appli quick sort.
 * @array: Array of integers.
 * @low: Start of partition.
 * @high: End of partition.
 * @size: Size of partition.
 */
void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pivot;

	if (array == NULL || size <= 1)
	{
		return;
	}

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_rec(array, low, pivot - 1, size);
		quick_sort_rec(array, pivot + 1, high, size);
	}
}
