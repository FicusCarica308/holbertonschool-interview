#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * is_palindrome - checks if a given linked list is a palindrome
 * @head: a double pointer to the head of a given linked list
 * Return: returns 0 if not palindrome and 1 if is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *temp_head = *head;
	int *list_values = NULL;
	int list_lgt= 0;
	
	/*finds the length of the linked list*/
	for (list_lgt = 0; temp_head != NULL; list_lgt++)
		temp_head = temp_head->next;
	
	/*mallocs dynamic array of integers*/
	list_values = malloc(sizeof(int) * list_lgt + 1);
	if (list_values == NULL)
		return (0);

	/*resets temp_head back to head*/
	temp_head = *head;

	while (temp_head != NULL)
	{
		list_values[list_lgt - 1] = temp_head->n;
		temp_head = temp_head->next;
		list_lgt -= 1;
	}

	temp_head = *head;

	while (temp_head != NULL)
	{
		if (temp_head->n != list_values[list_lgt])
		{
			free(list_values);
			return (0);
		}
		temp_head = temp_head->next;
		list_lgt++;
	}
	free(list_values);
	return (1);
}
