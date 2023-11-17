#include "sort.h"

/**
 * insertion_sort_list - using the algorithm insertion sort, it will sort
 * doubly linked list of integers.
 * @list: list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tier1, *tier2;

	if (!list || !(*list) || !((*list)->next))
		return;
	tier1 = *list;
	while (tier1)
	{
		tier2 = tier1;
		while (tier2)
		{
			if (tier2->prev == NULL)
				break;
			if (tier2->n < tier2->prev->n)
			{
				tier2->prev->next = tier2->next;
				if (tier2->next)
					tier2->next->prev = tier2->prev;
				tier2->next = tier2->prev;
				tier2->prev = tier2->next->prev;
				tier2->next->prev = tier2;
				if (tier2->prev)
					tier2->prev->next = tier2;
				else
				{
					*list = tier2;
					tier2 = NULL;
				}
				print_list(*list);
			}
			else
				break;
		}
		tier1 = tier1->next;
	}
}
