#include "lists.h"
#include <stdio.h>

/**
* check_cycle - a function in C that checks if a
* singly linked list has a cycle in it
* @list: head of list to be checked
* Return: returns 0 if no cycle is found, 1 if cycle is found
*/
int check_cycle(listint_t *list)
{
	listint_t *norm_node = list;
	listint_t *ahead_node = list;

	if (list == NULL || list->next == NULL)
		return (0);

	while (norm_node != NULL && ahead_node != NULL)
	{
		norm_node = norm_node->next;
		if (ahead_node->next == NULL)
			return (0);
		ahead_node = ahead_node->next->next;
		if (norm_node == ahead_node)
			return (1);
	}
	return (0);
}
