C - Sorting Algorithms & Big O - Holberton School Tasks
Task 0: Bubble Sort

Description:
Sorts an array of integers in ascending order using the Bubble sort algorithm.

Prototype:

void bubble_sort(int *array, size_t size);


Input:

array: Pointer to the array of integers.

size: Number of elements in the array.

Output:

None. (The function sorts the array in-place.)

Notes:

Prints the array after each time two elements are swapped.

Algorithm repeatedly compares adjacent elements and swaps them if they are in the wrong order.

The largest elements "bubble up" to the end with each pass.

Stops when no swaps are needed.

Big O:

Best case: O(n)

Average case: O(n²)

Worst case: O(n²)

Task 1: Insertion Sort (Doubly Linked List)

Description:
Sorts a doubly linked list of integers in ascending order using the Insertion sort algorithm.

Prototype:

void insertion_sort_list(listint_t **list);


Input:

list: Double pointer to the head of the linked list.

Output:

None. (The function rearranges the nodes directly.)

Notes:

You must swap the nodes, not the integer values.

Prints the list after each time two nodes are swapped.

Starts from the second node and moves it left until it’s in the correct position.

Works similarly to sorting playing cards in your hand.

Utilizes both prev and next pointers for efficient navigation.

Big O:

Best case: O(n²)

Average case: O(n²)

Worst case: O(n²)

Task 2: Selection Sort

Description:
Sorts an array of integers in ascending order using the Selection sort algorithm.

Prototype:

void selection_sort(int *array, size_t size);


Input:

array: Pointer to the array of integers.

size: Number of elements in the array.

Output:

None. (The function sorts the array in-place.)

Notes:

Prints the array after each swap.

The algorithm divides the array into a sorted and an unsorted section.

It repeatedly finds the smallest element in the unsorted section
and swaps it with the first unsorted element.

Inefficient for large arrays but simple to implement.

Big O:

Best case: O(n²)

Average case: O(n²)

Worst case: O(n²)

Task 3: Quick Sort

Description:
Sorts an array of integers in ascending order using the Quick sort algorithm.

Prototype:

void quick_sort(int *array, size_t size);


Input:

array: Pointer to the array of integers.

size: Number of elements in the array.

Output:

None. (The function sorts the array in-place.)

Notes:

Implements the Lomuto partition scheme.

The pivot is always the last element of the partition.

Prints the array after each time two elements are swapped.

Recursively applies the same logic to the left and right partitions.

Efficient for large data sets, but performance depends on pivot choice.

Big O:

Best case: O(n log n)

Average case: O(n log n)

Worst case: O(n²)

General Notes

All files follow Betty coding style.

All code is compiled using:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o sort


Header file sort.h includes all function prototypes and the doubly linked list structure:

typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

Big O Summary
Algorithm	Best	Average	Worst
Bubble Sort	O(n)	O(n²)	O(n²)
Insertion Sort	O(n²)	O(n²)	O(n²)
Selection Sort	O(n²)	O(n²)	O(n²)
Quick Sort	O(nlog(n))	O(nlog(n))	O(n²)
Author

Abdullah Mushabab Al-Salem
Seba Alshedokhi
