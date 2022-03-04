#include "binary_trees.h"
#include <stdio.h>

/**
 * find_height - A recrusive function that finds the height of a binary tree
 * @node: the root/processable node passed to the function
 * Return: returns the total height of the given binary tree
 */
int find_height(const binary_tree_t *node)
{
	if (node == NULL)
		return (-1);
	int left_Depth = find_height(node->left);
	int right_Depth = find_height(node->right);

		if (left_Depth > right_Depth)
			return (left_Depth + 1);
		return (right_Depth + 1);
}

/**
* process_node - a helper function used with binary_is_bst() to determine if
* the passed node meets the requirments of a BST at its current
* know position (left or right). The function can also be told
* if the node being checked is apart of a left or right side of
* a root tree...
*
* @node: the current node binary_is_bst() has passed
*
* @bts_flag: A int pointer that will be changed based on the outcome.
* (0 if node is not valid and 1 if it IS valid)
*
* @left_or_right: Whether or not the passed node is apart of a left or right
* root subtree. (1 for right tree or -1 for left tree.)
* (pass 0 if checking a binary tree from it root)
*
* @head: the current root node of the passed binary tree
* (only used if left_or_right is (-1 or 1))
*/
void process_node(const binary_tree_t *node,
				  int *bts_flag,
				  int left_or_right,
				  const binary_tree_t *head)
{
	if (*bts_flag == 0)
	{
		*bts_flag = 0;
		return;
	}
	if (node->right != NULL)
	{
		if (node->right->n < node->n)
			*bts_flag = 0;
		return;
	}
	if (node->left != NULL)
	{
		if (node->left->n > node->n)
			*bts_flag = 0;
		return;
	}
	if (left_or_right == 1)
	{
		if (node->n <= head->n)
			*bts_flag = 0;
		return;
	}
	if (left_or_right == -1)
	{
		if (node->n >= head->n)
			*bts_flag = 0;
		return;
	}
	*bts_flag = 1;
}

/**
* binary_is_bst - checks if a given binary tree is a BST
*
* @node: The root/processable node passed to the function
*
* @bts_flag: A int pointer that will be changed based on the outcome
* of the process_node() function (0 NOT valid / 1 IS valid)
*
*@left_or_right: Whether or not the passed node is apart of a left or right
* root subtree. (1 for right tree or -1 for left tree.)
* (pass 0 if checking a binary tree from it root)
*
* @head: the current root node of the passed binary tree
* (only used if left_or_right is (-1 or 1))
*/
void binary_is_bst(const binary_tree_t *node,
				   int *bts_flag,
				   int left_or_right,
				   const binary_tree_t *head)
{
	if (node == NULL)
		return;
	process_node(node, &*bts_flag, left_or_right, head);
	binary_is_bst(node->left, &*bts_flag, left_or_right, head);
	binary_is_bst(node->right, &*bts_flag, left_or_right, head);
}

/**
* binary_tree_is_avl - determines if a tree is an AVL tree
* @tree: the root node of the given binary tree
* Return: returns 0 if tree is NOT an AVL and 1 if it IS an AVL tree
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int bts_flag = -1;

	if (tree == NULL)
		return (0);
	binary_is_bst(tree, &bts_flag, 0, tree);
	binary_is_bst(tree->right, &bts_flag, 1, tree);
	binary_is_bst(tree->left, &bts_flag, -1, tree);
	if (find_height(tree->left) != find_height(tree->right))
		return (0);
	return (bts_flag);
}
