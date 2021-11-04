#include "search.h"

/**
 * print_check - print function that prints out what index are checked
 * or what index range a value is found between
 *@temp_head: temp_head is passed from the parent function linear_skip.
 * This value is the highest index in the skip list express lane found in
 * this first loop of linear_skip.
 * @prev_place: This is the skiplist_t express lane node right behind
 * temp_head...
 *@type: this is the type of print we want to make
 * Type 0: This prints the index/value checked
 * Type 1: This prints what index range the value is found index
 * Type 1 + temp_head == NULL: This runs when the value is found outside of
 * the express lane. Same function as Type 1 just with the last value of
 * the express lane and the last value of the skip list
 */
void print_check(skiplist_t *temp_head, skiplist_t *prev_place, int type)
{
	skiplist_t *node = NULL;

	if (type == 1 && temp_head == NULL)
	{
		for (node = prev_place; node->next != NULL; node = node->next)
		;
		printf("Value found between indexes [%ld] and [%ld]\n",
			prev_place->index, node->index);
	}

	if (temp_head == NULL)
		return;

	if (type == 0)
		printf("Value checked at index [%ld] = [%d]\n",
		temp_head->index, temp_head->n);
	else if (type == 1)
		printf("Value found between indexes [%ld] and [%ld]\n",
		prev_place->index, temp_head->index);
}

/**
 * linear_skip - a function that searches for a value in a sorted skip
 * list of integers.
 *@list: is a pointer to the head of the skip list to search in.
 *@value: is the value to search for.
 *Return: a pointer on the first node where value is located / NULL if value
 *is not present or head is NULL
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
