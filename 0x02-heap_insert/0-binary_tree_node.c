#include "binary_trees.h"
#include <stdlib.h>

/**
* binary_tree_node - Functions that adds a node to a binary tree
* @parent: the parent node that we will add to
* @value: the number value that will be added to new node
* Return: returns either new node or null on failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	/* sets all pointers to NULL to init values properly */
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	if (parent == NULL)
		return (new_node);
	new_node->parent = parent;
	return (new_node);
}
