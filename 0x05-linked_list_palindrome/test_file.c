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
	listint_t *temp_head1 = *head;
	listint_t *temp_head2 = *head;
	int *flipped_values = NULL;
	int list_lgt = 0;

	for (list_lgt = 0; temp_head1 != NULL; list_lgt++)
		temp_head1 = temp_head1->next;

	list_lgt = list_lgt / 2;

	flipped_values = malloc(sizeof(int) * list_lgt);

	while (temp_head2 != NULL)
	{
		if (list_lgt >= 0)
		{
			flipped_values[list_lgt] = temp_head2->n;
			list_lgt -= 1;
			temp_head2 = temp_head2->next;
		}
		else
		{
			if (temp_head2->n != flipped_values[list_lgt])
				return (0);
			temp_head2 = temp_head2->next;
		}
	}

	return 1;
}
