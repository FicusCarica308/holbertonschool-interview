#include "binary_trees.h"
#include <stdio.h>

/* process_node */
void process_node(const binary_tree_t *node, int *bts_flag)
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
    *bts_flag = 1;
}

/*
* binary_is_bst - determines if a binary tree is a BST
* @tree: the root node of the given binary tree
*/
void binary_is_bst(const binary_tree_t *tree, int *bts_flag)
{
    if (tree == NULL)
        return;
    process_node(tree, &*bts_flag);
    binary_is_bst(tree->left, &*bts_flag);
    binary_is_bst(tree->right, &*bts_flag);
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
    binary_is_bst(tree, &bts_flag);
    return(bts_flag);
}
