#include"sort.h"
/**
* insertion_sort_list - sorts linked list using Insertion sort algorithm
* @list: list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *node;

	if (!list || !*list || !(*list)->next)
		return;
	tmp = (*list)->next;
	while (tmp)
	{
		node = tmp;
		tmp = tmp->next;
		while (node->prev && node->n < node->prev->n)
		{
			if (node->next)
				node->next->prev = node->prev;
			node->prev->next = node->next;
			node->next = node->prev;
			node->prev = node->next->prev;
			if (node->prev)
				node->prev->next = node;
			node->next->prev = node;
			if (!node->prev)
				*list = node;
			print_list(*list);
		}
	}
}
