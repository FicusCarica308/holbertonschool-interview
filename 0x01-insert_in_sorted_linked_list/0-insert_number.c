#include "lists.h"
#include <stdlib.h>
#include <stdio.h>
/**
* insert_node -  a function in C that inserts
* a number into a sorted singly linked list
* @head: head of the singly linked list
* @number: number(n) value for new node to be inserted
* Return: returns new node / null on failure
*/
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = NULL;
	listint_t *prev_node = NULL;
	listint_t *temp_head = *head;
	(void)number;

	if (*head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = number;
	new_node->next = NULL;

	while (temp_head != NULL)
	{
		if (temp_head->n > number)
		{
			if (temp_head == *head)
			{
				new_node->next = *head;
				*head = new_node;
				return (new_node);
			}
			break;
		}
		prev_node = temp_head;
		temp_head = temp_head->next;
	}
	prev_node->next = new_node;
	new_node->next = temp_head;
	return (new_node);
}
