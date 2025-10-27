#include "sort.h"

/**
 * swap_ints - Swap two integers in an array
 * @a: Pointer to first int
 * @b: Pointer to second int
 */
static void swap_ints(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * partition_lomuto - Lomuto partition scheme for Quick sort
 * @array: The array being sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition (pivot index)
 * @size: Total size of the full array (for printing)
 *
 * Return: The final index of the pivot
 *
 * Description:
 * Chooses the last element as pivot, places all elements smaller than pivot
 * to the left of it, and all greater elements to the right.
 * Prints the array after each swap.
 */
static int partition_lomuto(int *array, int low, int high, size_t size)
{
    int pivot, i, j;

    pivot = array[high];
    i = low;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            if (i != j)
            {
                swap_ints(&array[i], &array[j]);
                print_array(array, size);
            }
            i++;
        }
    }

    if (i != high)
    {
        swap_ints(&array[i], &array[high]);
        print_array(array, size);
    }

    return (i);
}

/**
 * quick_sort_rec - Recursively sorts an array using Quick sort
 * @array: The array to sort
 * @low: Starting index of the sub-array
 * @high: Ending index of the sub-array
 * @size: Size of the full array
 *
 * Description:
 * Recursively applies partitioning, then sorts left and right parts.
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
 * quick_sort - Sorts an array of integers in ascending order using Quick sort
 * @array: Pointer to the array to sort
 * @size: Number of elements in the array
 *
 * Description:
 * Wrapper function that calls the recursive Quick sort.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_rec(array, 0, (int)size - 1, size);
}
