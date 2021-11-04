#include "search.h"

/**
 * 
 *
 *
 */
void print_check(skiplist_t *temp_head, skiplist_t *prev_place, int type)
{
	if (temp_head == NULL)
		return;
	
	if (type == 0)
		printf("Value checked at index [%ld] = [%d]\n", temp_head->index, temp_head->n);
	else if (type == 1)
		printf("Value found between indexes [%ld] and [%ld]\n", prev_place->index, temp_head->index);
}

/**
 * 
 * 
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temp_head = NULL;
	skiplist_t *prev_place = NULL;


	if (list == NULL)
		return (NULL);
	temp_head = list;

	while (temp_head != NULL)
	{
		if (temp_head->n < value)
		{
			prev_place = temp_head;
			temp_head = temp_head->express;
			print_check(temp_head, prev_place, 0);
		}
		else
			break;
	}

	if (prev_place != NULL && prev_place->next == NULL)
		return (NULL);
	print_check(temp_head, prev_place, 1);
	temp_head = prev_place;
	while (temp_head != NULL)
	{
		print_check(temp_head, prev_place, 0);
		if (temp_head->n == value)
			return (temp_head);
		temp_head = temp_head->next;
	}

	return (NULL);
}
