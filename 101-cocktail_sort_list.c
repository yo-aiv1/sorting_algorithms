#include "sort.h"
#include <stddef.h>
#include <stdio.h>

/**
 * swping_next-func that swap tow item of linked list
 * @lst: list
 * @lst1: item1
 * @lst2: item2
 */
void swping_next(listint_t **lst, listint_t *lst1, listint_t *lst2)
{
	listint_t *tmp;

	tmp = lst2;
	lst1->next = tmp->next;
	tmp->prev = lst1->prev;

	if (tmp->next)
		tmp->next->prev = lst1;
	if (tmp->prev)
		tmp->prev->next = tmp;
	else
		*lst = tmp;

	tmp->next = lst1;
	lst1->prev = tmp;
}

/**
 * cocktail_sort_list- sorts an array of integers in ascending order
 * using the cocktail_sort_list sort algorithm.
 * @list: list of values
 */


void cocktail_sort_list(listint_t **list)
{
	int swp = 1;
	listint_t *tier1;

	if (!list || !(*list) || !((*list)->next))
		return;
	while (swp)
	{
		tier1 = *list;
		swp = 0;
		while (tier1 && tier1->next)
		{
			if (tier1->n > tier1->next->n)
			{
				swping_next(list, tier1, tier1->next);
				swp = 1;
				print_list(*list);
			}
			else
				tier1 = tier1->next;
		}
		if (!swp)
			break;
		while (tier1->prev)
		{
			if (tier1->n < tier1->prev->n)
			{

				swping_next(list, tier1->prev, tier1);
				swp = 1;
				print_list(*list);
			}
			else
				tier1 = tier1->prev;
		}
	}
}
