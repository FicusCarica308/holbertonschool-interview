#include "binary_trees.h"
#include <stdio.h>

/**
 */
int find_height(const binary_tree_t *node)
{
	if (node == NULL)
		return -1;
	else
	{
		int left_Depth = find_height(node->left);
		int right_Depth = find_height(node->right);

		if (left_Depth > right_Depth)
			return (left_Depth + 1);
		else
			return (right_Depth + 1);
	}
}

/* process_node */
void process_node(const binary_tree_t *node, int *bts_flag, int left_or_right, const binary_tree_t *head)
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

/*
* binary_is_bst - determines if a binary tree is a BST
* @tree: the root node of the given binary tree
*/
void binary_is_bst(const binary_tree_t *tree, int *bts_flag, int left_or_right, const binary_tree_t *head)
{
	if (tree == NULL)
		return;
	process_node(tree, &*bts_flag, left_or_right, head);
	binary_is_bst(tree->left, &*bts_flag, left_or_right, head);
	binary_is_bst(tree->right, &*bts_flag, left_or_right, head);
}

/*
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
	return(bts_flag);
}
