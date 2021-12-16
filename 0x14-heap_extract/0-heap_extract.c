#include "binary_trees.h"

/**
 * free_last_node - frees the last node of a binary tree and returns its ->n
 *@root: the root node of the binary tree
 *Return: returns the ->n value of the deleted node
*/
int free_last_node(heap_t *root)
{
	int size = tree_size(root);
	heap_t *temp_head = root;
	int height = binary_tree_height(root);
	int *binary = malloc(sizeof(int) * height);
	int i;
	int hold_n1;

	/* Finds and removes the last item in the binary tree */
	get_last_node_path(size, binary, height - 1);

	printf("\n");
	for (i = 0; i < height; i++)
	{
		if (binary[i] == 1)
			temp_head = temp_head->right;
		else if (binary[i] == 0)
			temp_head = temp_head->left;
	}

	if (binary[i - 1] == 1)
		temp_head->parent->right = NULL;
	else if (binary[i - 1] == 0)
		temp_head->parent->left = NULL;
	hold_n1 = temp_head->n;
	free(temp_head);
	free(binary);
	return (hold_n1);
}

/**
* heap_extract - a function that extracts the root node of a Max Binary Heap
* @root: is a double pointer to the root node of the heap
* Return: returns 0 on failure or the ->n value of the node extracted
*/
int heap_extract(heap_t **root)
{
	heap_t *tmp_head = *root;
	int hold_n1, hold_n2;

	hold_n1 = free_last_node(*root);

	tmp_head = *root;

	while (1 != 0)
	{
		hold_n2 = tmp_head->n;
		if (tmp_head->right == NULL || tmp_head->left->n >= tmp_head->right->n)
		{
			tmp_head->n = tmp_head->left->n;
			tmp_head->left->n = hold_n2;
			tmp_head = tmp_head->left;
		}
		else if (tmp_head->left == NULL || tmp_head->right->n >= tmp_head->left->n)
		{
			tmp_head->n = tmp_head->right->n;
			tmp_head->right->n = hold_n2;
			tmp_head = tmp_head->right;
		}
		if (tmp_head->right == NULL && tmp_head->left == NULL)
		{
			tmp_head->n = hold_n1;
			return (hold_n2);
		}
	}

	return (0);
}
