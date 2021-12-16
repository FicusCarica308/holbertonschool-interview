#include "binary_trees.h"

#include "binary_trees.h"
/**
 * left_and_right - loops through tree recursively left and right
 * @tree: given tree
 * Return: returns total height of tree
 */
size_t left_and_right(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
		return (0);
	left_height = left_and_right(tree->left) + 1;
	right_height = left_and_right(tree->right) + 1;
	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}
/**
 * binary_tree_height - finds height from node
 * @tree: given tree
 * Return: height;
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (left_and_right(tree) - 1);
}

int tree_size(heap_t *root)
{
	if (root == NULL)
		return (0);
	else
		return (tree_size(root->left) + 1 + tree_size(root->right));
}

/**
 *print_binary - prints a decimal number as binary
 *@n: the decimal number given
 */
void print_binary(unsigned long int n, int *binary, int current_index)
{
	unsigned long int temp = n;
	if (temp == 1)
		return;
	if (temp > 1)
		print_binary(temp >> 1, binary, current_index - 1);
	binary[current_index] = (temp & 1);
}

int heap_extract(heap_t **root)
{
	int size = tree_size(*root);
	heap_t *temp_head = *root;
	int height = binary_tree_height(*root);
	int *binary = malloc(sizeof(int) * height);
	int i;
	int hold_n1, hold_n2;

		/* Finds and removes the last item in the binary tree */
	print_binary(size, binary, height - 1);

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

	/* ======= */

	temp_head = *root;

	while (1 != 0)
	{
		hold_n2 = temp_head->n;
		if (temp_head->right == NULL || temp_head->left->n >= temp_head->right->n)
		{
			temp_head->n = temp_head->left->n;
			temp_head->left->n = hold_n2;
			temp_head = temp_head->left;
		} 
		else if (temp_head->left == NULL || temp_head->right->n >= temp_head->left->n)
		{
			temp_head->n = temp_head->right->n;
			temp_head->right->n = hold_n2;
			temp_head = temp_head->right;
		}
		if (temp_head->right == NULL && temp_head->left == NULL)
		{
			temp_head->n = hold_n1;
			return (hold_n2);
		}
	}
	return (0);
}