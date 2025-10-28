#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: Pointer to first integer
 * @b: Pointer to second integer
 */
static void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition_lomuto - Partitions a sub-array using Lomuto scheme
 * @array: The full array
 * @low: Starting index of the sub-array to partition
 * @high: Ending index of the sub-array to partition (pivot index)
 * @size: Total size of the full array (for printing)
 *
 * Return: The final index of the pivot after partition
 *
 * Description:
 * Uses the last element as pivot. All values smaller than the pivot
 * are moved before it. The pivot is then placed in its final position.
 * The array is printed after each meaningful swap (array actually changes).
 */
static int partition_lomuto(int *array, int low, int high, size_t size)
{
	int pivot;
	int i, j;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				/* only swap/print if values differ */
				if (array[i] != array[j])
				{
					swap_ints(&array[i], &array[j]);
					print_array(array, size);
				}
			}
			i++;
		}
	}

	if (i != high)
	{
		/* only swap/print if pivot actually moves to a different value */
		if (array[i] != array[high])
		{
			swap_ints(&array[i], &array[high]);
			print_array(array, size);
		}
	}

	return (i);
}

/**
 * quick_sort_rec - Recursively applies Quick sort on a sub-array
 * @array: The full array
 * @low: Starting index of the sub-array
 * @high: Ending index of the sub-array
 * @size: Total size of the full array (for printing)
 */
static void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int p_index;

	if (low < high)
	{
		p_index = partition_lomuto(array, low, high, size);
		quick_sort_rec(array, low, p_index - 1, size);
		quick_sort_rec(array, p_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: Pointer to array of integers
 * @size: Number of elements in the array
 *
 * Description:
 * Wrapper function that calls the recursive Quick sort.
 * Uses Lomuto partition scheme. The pivot is always the last element
 * of the current partition. The array is printed after each swap
 * that actually changes the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, (int)size - 1, size);
}
