#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * malloc_new_node
 * @new_str: The new string to copy into the new node
 * Return: pointer to new node, NULL on malloc failure or if new_str == NULL
*/
List *malloc_new_node(char *new_str)
{
	List *new_node = NULL;

	if (new_str == NULL)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);

	new_node->str = strdup(new_str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = new_node;
	new_node->prev = new_node;
	return (new_node);
}

/**
 * add_node_end - adds a new node to the end of a double circular linked list.
 * @list: The list to modify
 * @str: The string to copy into the new node
 * Return: Returns new node
*/
List *add_node_end(List **list, char *str)
{
	List *new_node = NULL;

	new_node = malloc_new_node(str);
	if (new_node == NULL)
		return (NULL);

	if (*list == NULL)
		*list = new_node;
	else
	{
		new_node->prev = (*list)->prev;
		new_node->next = *list;
		(*list)->prev = new_node;
		new_node->prev->next = new_node;
	}
	return (new_node);
}

/**
 * add_node_begin - Adds a new node to the beginning of a double circular
 *					linked list
 * @list: The list to modify
 * @str: The string to copy into the new node
 * Return: Returns new node
*/
List *add_node_begin(List **list, char *str)
{
	List *new_node = NULL;

	new_node = malloc_new_node(str);
	if (new_node == NULL)
		return (NULL);
	if (*list == NULL)
		*list = new_node;
	else
	{
		new_node->next = *list;
		new_node->prev = (*list)->prev;
		(*list)->prev = new_node;
		new_node->prev->next = new_node;
		*list = new_node;
	}
	return (new_node);
}
