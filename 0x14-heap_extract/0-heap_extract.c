#include "binary_trees.h"
/**
* heap_extract - a function that extracts the root node of a Max Binary Heap
* @root: is a double pointer to the root node of the heap
* Return: returns 0 on failure or the ->n value of the node extracted
*/
int heap_extract(heap_t **root)
{
	heap_t *tmp_head = NULL;
	int hold_n, right_or_left;

	if (root == NULL)
		return (0);
	tmp_head = *root;
	if (tmp_head->right == NULL && tmp_head->left == NULL)
	{
		hold_n = tmp_head->n;
		*root = NULL;
		free(tmp_head);
		return (hold_n);
	}
	while (1 != 0)
	{
		hold_n = temp_head->n;
		if (tmp_head->right == NULL || tmp_head->left->n >= tmp_head->right->n)
		{
			tmp_head->n = tmp_head->left->n;
			tmp_head->left->n = hold_n;
			tmp_head = tmp_head->left;
			right_or_left = 0;
		} else if (tmp_head->left == NULL || tmp_head->right->n >= tmp_head->left->n)
		{
			tmp_head->n = tmp_head->right->n;
			tmp_head->right->n = hold_n;
			tmp_head = tmp_head->right;
			right_or_left = 1;
		}
		if (tmp_head->right == NULL && tmp_head->left == NULL)
		{
			if (right_or_left == 0)
				tmp_head->parent->left = NULL;
			else if (right_or_left == 1)
				tmp_head->parent->right = NULL;
			free(tmp_head);
			return (hold_n);
		}
	}
	return (0);
}
