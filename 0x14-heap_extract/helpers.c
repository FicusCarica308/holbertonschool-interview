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
/**
 * tree_size - finds the size of a binary tree
 * @root: the root node passed to the function
 * Return: returns the total amount of nodes in the binary tree
*/
int tree_size(heap_t *root)
{
	if (root == NULL)
		return (0);
	else
		return (tree_size(root->left) + 1 + tree_size(root->right));
}

/**
 *get_last_node_path - prints a decimal number as binary
 *@n: the decimal number given
 *@binary: A integer array that will store the path to the last node in order
 *@current_index: The current index of 'binary'
 */
void get_last_node_path(unsigned long int n, int *binary, int current_index)
{
	unsigned long int temp = n;

	if (temp == 1)
		return;
	if (temp > 1)
		get_last_node_path(temp >> 1, binary, current_index - 1);
	binary[current_index] = (temp & 1);
}
